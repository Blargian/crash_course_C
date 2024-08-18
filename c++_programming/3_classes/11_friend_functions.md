# Friend functions

Take for example the following code which will not compile due to trying to access a **private** member variable:

```c++
#include <iostream>

class UserDefinedType
{
    public:

    private:
        int m_privateMemberVariable;
}

int main() 
{
    UserDefinedType instance;
    instance.m_privateMemberVariable = 42;

    return 0;
}
```

However we can use the `friend` keyword to give a function access to the private member variables:

```c++
#include <iostream>

class UserDefinedType
{
    public:
        friend void PrintPrivateMemberVariablesOfUDT(UserDefinedType u); <--- declare it friend here
    private:
        int m_privateMemberVariable;
};

void PrintPrivateMemberVariablesOfUDT(UserDefinedType u)
{
    std::cout << "m_privateMemberVariable: " << u.m_privateMemberVariable << std::endl;
};

int main() 
{
    UserDefinedType instance;
    PrintPrivateMemberVariablesOfUDT(instance); <--- now we are able to access the private member variable
}
```

> General rule: avoid them! Unless there is a very good reason to use one (for instance operator overloading)
> In gerneral friend functions are a sign of poor API design.
