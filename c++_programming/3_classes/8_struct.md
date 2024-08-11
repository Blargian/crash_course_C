# Struct

Classes and Structs are user-defined types. They are almost identifcal except for one detail, which is the default access.

- `class` = default private.
- `struct` = default public.

 `vector3f.hpp`:
 ```c++
#ifndef VECTOR3F_HPP
#define VECTOR3F_HPP

struct Vector3f
{
  Vector3f();
  float x, y, z;
};

#endif
```

`vector3f.cpp`:
```c++
#include <iostream>
#include "vector3f.hpp"

Vector3f::Vector3f(): x(1.0f), y(2.0f), z(3.0f){};

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

## Why do both even exist? 

- C language already had the keyword `struct` so it had to be kept in.

For example:
```c
struct Vector3f
{
  float x, y, z;
}
```
