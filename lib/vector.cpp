#include <math.h>

#include <string>
#include <iostream>

#include "vector.h"

/****************************************

				Vector3

****************************************/

	// Default Constructor
	Vector3::Vector3() { x=0; y=0; z=0; } // x.set(0); y.set(0); z.set0); }

	// Parameter Constructor x,y,z
	Vector3::Vector3(int a, int b, int c) { x=a; y=b; z=c; }
	Vector3::Vector3(float a, float b, float c) { x=a; y=b; z=c; }
	
	//Vector3::Vector3(Vector3 v) { this->x = v.x; this->y = v.y; this->z = v.z; }

	void Vector3::reset() { x=0;y=0;z=0; }
	
	float Vector3::Magnitude() { return sqrtf((x*x) + (y*y) + (z*z)); }

	Vector3 Vector3::Normalized() { float m=Magnitude(); return Vector3(x/m,y/m,z/m); }

	Vector3 Vector3::Cross(Vector3 b) { return Vector3(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x); }

	float Vector3::Dot(Vector3 b) { return x*b.x + y*b.y + z*b.z; }

	Vector3 Vector3::operator + (Vector3 v2) { return Vector3(x+v2.x,y+v2.y,z+v2.z); }
	Vector3 Vector3::operator - (Vector3 v2) { return Vector3(x-v2.x,y-v2.y,z-v2.z); }
	Vector3 Vector3::operator * (Vector3 v2) { return Vector3(x*v2.x,y*v2.y,z*v2.z); }
	Vector3 Vector3::operator / (Vector3 v2) { return Vector3(x/v2.x,y/v2.y,z/v2.z); }
	
	Vector3 Vector3::operator += (Vector3 v2) { return Vector3(x+v2.x,y+v2.y,z+v2.z); }
	Vector3 Vector3::operator -= (Vector3 v2) { return Vector3(x-v2.x,y-v2.y,z-v2.z); }
	Vector3 Vector3::operator *= (Vector3 v2) { return Vector3(x*v2.x,y*v2.y,z*v2.z); }
	Vector3 Vector3::operator /= (Vector3 v2) { return Vector3(x/v2.x,y/v2.y,z/v2.z); }
			
	float Vector3::operator [] (int i) { if (i==0) return x; else if (i==1) return y; else if (i==2) return z; throw "Index out of bounds exception";}

	bool Vector3::operator == (Vector3 v2) { if (x==v2.x && y==v2.y && z==v2.z) return true; return false; }

	bool Vector3::operator != (Vector3 v2) { if (x!=v2.x || y!=v2.y || z!=v2.z) return true; return false; }

	void Vector3::print() { printf("(%f, %f, %f)\n", x, y, z); }



/****************************************

				Vector2

****************************************/

	// Default Constructor
	Vector2::Vector2() { }

	// Parameter Constructor
	Vector2::Vector2(int a, int b) { x=a; y=b; }
	Vector2::Vector2(float a, float b) { x=a; y=b; }

	void Vector2::reset() { x=0; y=0; }

	// Member methods
	float Vector2::Magnitude() { return sqrtf((x*x) + (y*y)); }

	Vector2 Vector2::Normalized() { float m = Magnitude(); return Vector2(x/m,y/m); }

	float Vector2::Dot(Vector2 b) { return x*b.x + y*b.y; }

	Vector2 Vector2::operator + (Vector2 v2) { return Vector2(x+v2.x,y+v2.y); }
	Vector2 Vector2::operator - (Vector2 v2) { return Vector2(x-v2.x,y-v2.y); }
	Vector2 Vector2::operator * (Vector2 v2) { return Vector2(x*v2.x,y*v2.y); }
	Vector2 Vector2::operator / (Vector2 v2) { return Vector2(x/v2.x,y/v2.y); }
	
	Vector2 Vector2::operator += (Vector2 v2) { return Vector2(x+v2.x,y+v2.y); }
	Vector2 Vector2::operator -= (Vector2 v2) { return Vector2(x-v2.x,y-v2.y); }
	Vector2 Vector2::operator *= (Vector2 v2) { return Vector2(x*v2.x,y*v2.y); }
	Vector2 Vector2::operator /= (Vector2 v2) { return Vector2(x/v2.x,y/v2.y); }
			
	float Vector2::operator [] (int i) { if (i==0) return x; else if (i==1) return y; throw "Index out of bounds exception";}

	bool Vector2::operator == (Vector2 v2) { if (x==v2.x && y==v2.y) return true; return false; }

	bool Vector2::operator != (Vector2 v2) { if (x!=v2.x || y!=v2.y) return true; return false; }

	void Vector2::print() { printf("(%f, %.f)\n", x, y); }


// Static Methods
//Fix Distance(Vector2 v1, Vector2 v2) { return sqrt( ((v1.x-v2.x)*(v1.x-v2.x)) + ((v1.y-v2.y)*(v1.y-v2.y)) ); }
