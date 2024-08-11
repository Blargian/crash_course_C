# Member Initializer Lists

We'll start out our example with this base code:

```c++
#include <iostream>

class Vector3f
{
    public:
        Vector3f()
        {
            x = 1.0f;
            y = 2.0f;
            z = 3.0f;
        }

    float x, y, z;
    
};

std::ostream& operator<<(std::ostream& os, const Vector3f& obj)
{
    os << obj.x << ", " << obj.y << ", " << obj.z;
    return os;
};

int main()
{
    Vector3f myVector1;
    std::cout << myVector1 << std::endl;
    return 0;
};
```

What happens when `myVector1` gets constructed?
- we allocate some space for `x`, `y`, `z`. (construction)
- we assign values for each of those variables. (assignment)

Wouldn't it be nice if we could do both of those things at once? We can! We can use the **member initializer list**

```c++
 /* Vector3f()
{
  x = 1.0f;
  y = 2.0f;
  z = 3.0f;
}
 */

/// member initializer list
Vector3f(): x(1.0f), y(2.0f), z(3.0f);
```

> This is probably not a huge performance boost for primitive types but it could be for non-primitive objects. See: [should my constructors use initialization lists or assignment]()

> the order of initialization in the list should have the same order as the order of the member variables.

`vector3f.hpp`:
```c++
#ifndef VECTOR3F_HPP
#define VECTOR3F_HPP

class Vector3f
{
    public:
    Vector3f(); ///.hpp file is our interface so we want implementation in the .cpp file
    float x, y, z;
};

#endif
```

`vector3f.cpp`:
```c++
#include <iostream>
#include "vector3f.hpp"

Vector3f::Vector3f(): x(0.0f), y(0.0f), z(0.0f){};

std::ostream& operator<<(std::ostream& os, const Vector3f& obj)
{
    os << obj.x << ", " << obj.y << ", " << obj.z;
    return os;
};

int main()
{
    Vector3f myVector1;
    std::cout << myVector1 << std::endl;
    return 0;
};
```
