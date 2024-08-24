# explicit constructor

Given some starting code:

```c++
#include <iostream>
#include <string>

class udt
{
public:
    udt(int);
private:
    int m_variable;
};

udt::udt(int i)
{
    m_variable = i;

    std::cout << "m_variable: "
              << m_variable
              << std::endl;
}

int main()
{
    udt ul(500);
    return 0;
}
```

What if we created our `ul` object as `udt ul(500.123f)`? (As a float rather than as the expected int).
Well, it works still! Why? 

> implicit conversion

This is where the `explicit` keyword comes in. In general you want to make your constructors explicit.

```
udt ul1 = 500.0f; // this won't work when the constructor is explicit
udt ul2{500.0f}; // list initialization protects against narrowing conversion
```

