#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <iostream>

class Vector3
{
    public:
        float x, y, z;

        // Default Constructor
        Vector3(); // x.set(0); y.set(0); z.set0); }
		Vector3(int x, int y, int z);
        Vector3(float x, float y, float z);
        
        void reset();

        float Magnitude();
        Vector3 Normalized();
        Vector3 Cross(Vector3 b);
        float Dot(Vector3 b);

        Vector3 operator + (Vector3 v2);
        Vector3 operator - (Vector3 v2);
        Vector3 operator * (Vector3 v2);
        Vector3 operator / (Vector3 v2);

        Vector3 operator += (Vector3 v2);
        Vector3 operator -= (Vector3 v2);
        Vector3 operator *= (Vector3 v2);
        Vector3 operator /= (Vector3 v2);
                
        float operator [] (int i);

        bool operator == (Vector3 v2);

        bool operator != (Vector3 v2);

        void print();
};
//double Distance(Vector3 v1, Vector3 v2);


class Vector2
{
	public:
		float x;
		float y;
		
		Vector2();
		
		Vector2(int x, int y);
		Vector2(float x, float y);

        void reset();
		
		float Magnitude();
		Vector2 Normalized();
		float Dot(Vector2 b);
		
		Vector2 operator + (Vector2 v2);
        Vector2 operator - (Vector2 v2);
        Vector2 operator * (Vector2 v2);
        Vector2 operator / (Vector2 v2);

		Vector2 operator += (Vector2 v2);
		Vector2 operator -= (Vector2 v2);
		Vector2 operator *= (Vector2 v2);
		Vector2 operator /= (Vector2 v2);
		
		float operator [] (int i);
		
		bool operator == (Vector2 v2);
		
		bool operator != (Vector2 v2);
		
		void print();
			
};
//double Distance(Vector2 v1, Vector2 v2);


#endif