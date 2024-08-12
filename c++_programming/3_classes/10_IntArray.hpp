#ifndef INTARRAY_HPP
#define INTARRAY_HPP
#include <string>

class IntArray
{
public:
    /// The Big 3 
    /// (1) Constructor
    IntArray(std::string name);
    /// (2) Destructor
    ~IntArray();
    /// (3) Copy constructor operator
    IntArray(const IntArray& rhs);
    /// Copy assignment poolicy
    IntArray& operator=(const IntArray& rhs);
	/// Move constructor
	IntArray(IntArray&& rhs);
	/// Move assignment operator
	IntArray& operator=(IntArray&& source);
private:
    std::string m_name;
    int* m_data;
};
#endif
