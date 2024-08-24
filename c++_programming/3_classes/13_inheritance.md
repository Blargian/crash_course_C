# Inheritance

In object oriented programming, the derived class _is a_ base class. (_is a_ relation)

> Based class "parent" -> derived class "child".

A really basic example:

```c++
#include <iostream>

/// Base Class
class Dog 
{
    public: 
        Dog()
        {
            
        }
        
        void Bark()
        {
            std::cout << "bark!" << std::endl;
        }
        
        void Walk()
        {
            x+=1;
            y+=1;
        }
        
    float x, y;     
};

/// Derived class
class Golden : public Dog
{
    public:
    
        Golden()
        {
            m_sticksRetrieved = 0;    
        }
        
        void Retrieve()
        {
            std::cout << "retrieving a stick" << std::endl;
            m_sticksRetrieved++;
        }
        
        int m_sticksRetrieved;
};

/// Another derived class
class Husky : public Dog
{
    
};

int main()
{
    Dog dog;
    dog.Bark();
    
    Golden dog2;
    dog2.Retrieve();
    
    return 0;
}
```

# public, private, protected access modifiers



