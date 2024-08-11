# Resource Acquisition Is Initialization (RAII)

This is a C++ programming technique which binds resource management to scope or lifecycle of objects.

Reference: [RAII](https://en.cppreference.com/w/cpp/language/raii)

An example of some bad code in which we will have a memory leak (run it through valgrind to check):

```c++
int main()
{
    int* Collection = new int[10];
    Collection[0] = 7;
    return 0;
}
```

So how can we save ourselves here? We can tie our resource to the life cycle of a class:

```c++
#include <cstdio>

class Collection
{
    public:
        Collection()
        {
            data = new int[10];
        }

        ~Collection()
        {
            delete[] data;
        }

        int& operator[](std::size_t idx)
        {
            return data[idx];
        }

        const int& operator[](std::size_t idx) const
        {
            return data[idx];
        }

    private:
        int* data;
};

int main()
{
    Collection myCollection;
    myCollection[0] = 7;
    myCollection[1] = 7;
    myCollection[2] = 7;
    return 0;
}
```
