#include <iostream>
#include <string>

/// A vector3 data type, storing floats.
class Vector3f
{
	public:

		Vector3f()
	    {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		Vector3f operator+(const Vector3f& rhs) const
		{
			Vector3f result;
			result.x = x + rhs.x;
			result.y = y + rhs.y;
			result.z = z + rhs.z;
			return result;	
		}
		
		/// pre-increment
		Vector3f& operator++()
		{
			x = x + 1;
			y = y + 1;
			z = z + 1;
			return *this; 
		}
		 
		float x, y, z;
};

bool operator==(const Vector3f& lhs, const Vector3f& rhs)
{
	if (lhs.x == rhs.x &&
		lhs.y == rhs.y &&
		lhs.z == rhs.z)
	{
		return true;
	}
	return false; 
};

std::ostream& operator<<(std::ostream& os, const Vector3f& obj)
{
	std::string spacer = ", ";
	os << obj.x << spacer << obj.y << spacer << obj.z;
	return os;
};

int main()
{
	Vector3f myVector, myVector2;
	myVector.x = 1.f;
	myVector.y = 2.f;
	myVector.z = 3.f;

	myVector2.x = 3.f;
	myVector2.y = 2.f;
	myVector2.z = 1.f;
	
	if (myVector == myVector2)
	{
		std::cout << "vectors are equal" << std::endl;
	}
	else
	{
		std::cout << "vectors are not equal" << std::endl;
	}

	myVector = myVector + myVector2;
	std::cout << myVector << std::endl;

	++myVector;
	std::cout << myVector << std::endl;
}
