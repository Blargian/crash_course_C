# Rule of Five

Recalling the big 3:
- constructor
- destructor
- copy constructor (and copy assignment operator)

`intArray.hpp`:
```c++
#include <iostream>
#include <string>
#include "IntArray.hpp"

/// Constructor Implementation
IntArray::IntArray(std::string name) : m_name(name), m_data(new int[10])
{
    std::cout << m_name << " was constructed" << std::endl;
}

/// Destructor
IntArray::~IntArray()
{
    std::cout << m_name << " was destructed" << std::endl;
    delete[] m_data;
}

/// Copy constructor
IntArray::IntArray(const IntArray& rhs)
{
    m_name = rhs.m_name + " copy";
    std::cout << "was copy constructed from" << rhs.m_name << std::endl;
    m_data = new int[10];
    for (int i=0; i < 10; i++)
    {
        m_data[i] = rhs.m_data[i];        
    }
}

/// Copy assignment operator
IntArray& IntArray::operator=(const IntArray& rhs)
{
  if (this != &rhs)
  {
    delete[] m_data;
    m_name = rhs.m_name + " copy";
    std::cout << "was copy assigned from" << rhs.m_name << std::endl;
    m_data = new int[10];
    for (int i=0; i < 10; i++)
    {
      m_data[i] = rhs.m_data[i];
    }
  }
  return *this;
}

int main()
{
  IntArray array1("array1");
	IntArray array2("array2");
	array2 = array1;
  return 0;
}
}
```

The output of this will be:

```response
array1 was constructed
array2 was constructed
array2 was copy assigned from array1
array1 copy was destructed
array1 was destructed
```
> Notice that the order of destruction is reversed from the order of creation. I.e First in, last out. 

## Move constructor and move assignment operator

We can avoid calling the copy constructor if we have a move constructor (to steal or transfer resources)

Interface:
```c++
IntArray(IntArray&& source);
IntArray& operator=(IntArray&& source);
```

Implementation:
```c++
/// Move constructor
IntArray::IntArray(IntArray&& source)
{
  m_name = source.m_name;
  source.m_name = "";
  m_data = source.m_data;
  source.m_data = nullptr;
  std::cout << m_name << " was move constructed" << std::endl;
}

/// Move assignment operator
IntArray& IntArray::operator=(IntArray&& source)
{
  if (this!=&source)
  {
    m_name = source.m_name;
    source.m_name = "";
    m_data = source.m_data;
    source.m_data = nullptr;
    std::cout << m_name << " used move assignment" << std::endl;
  }
  return *this;
}
```

Example usage:

```c++
#include <vector>
int main()
{
  std::vector<IntArray> myArrays;
  for (int i=0; i<3; i++)
  {
    IntArray temp(std::to_string(i));
    myArrays.push_back(temp);
  }
}
```

In this case we see this a lot of copies being made when we call `push_back`:

```response
0 was constructed
was copy constructed from0
0 was destructed
1 was constructed
was copy constructed from1
was copy constructed from0 copy
0 copy was destructed
1 was destructed
2 was constructed
was copy constructed from2
was copy constructed from0 copy copy
was copy constructed from1 copy
0 copy copy was destructed
1 copy was destructed
2 was destructed
0 copy copy copy was destructed
1 copy copy was destructed
2 copy was destructed
```

> If we run this program using valgrind we might see, for example, that there are x amount of allocations.

If we replace the above example with:

```c++
#include <vector>
int main()
{
  std::vector<IntArray> myArrays;
  for (int i=0; i<3; i++)
  {
    IntArray temp(std::to_string(i));
    myArrays.push_back(std::move(temp));
  }
}
```
Now the response is:

```response
0 was constructed
0 was move constructed
 was destructed
1 was constructed
1 was move constructed
was copy constructed from0
0 was destructed
 was destructed
2 was constructed
2 was move constructed
was copy constructed from0 copy
was copy constructed from1
0 copy was destructed
1 was destructed
 was destructed
0 copy copy was destructed
1 copy was destructed
2 was destructed
```

> We now have less copies. If you run valgrind again you'll see that there were less allocations made. 36 vs 52 in the example run on Mike's PC.
