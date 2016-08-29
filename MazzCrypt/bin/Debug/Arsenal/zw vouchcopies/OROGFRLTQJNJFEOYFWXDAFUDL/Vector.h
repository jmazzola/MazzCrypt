// Vector.h - Linear Algebra I. 
#pragma once

#include "stdafx.h"
#include "Math.h"

#include "Decrypt.h"

class Vector
{

public:

	// Data members
	float x, y, z;

	// Ctors
	inline Vector() : x(0.0f), y(0.0f), z(0.0f)
	{
	}

	inline Vector(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
	{
	}

	inline Vector(const Vector& v) : x(v.x), y(v.y), z(v.z)
	{
	}

	inline Vector(float num[3]) : x(num[0]), y(num[1]), z(num[2])
	{
	}

	inline void PrintInfo()
	{
		

		printf_s(Decrypt(12,96,32,103,52,105,111,45,108,49,110,106,54), x, y, z);

		

	}

	inline void ZeroOut()
	{
		x = y = z = 0.0f;
	}

	inline float Length()
	{
		return (float)Math::FastSQRT(x*x + y*y + z*z);
	}

	inline float DotProduct(Vector v)
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	inline void Normalize()
	{
		float l = 1.0f / Length();
		x *= l;
		y *= l;
		z *= l;
	}

	inline float ToDegree(Vector to)
	{
		return (180.0f / 3.141f) * asinf(DotProduct(to));
	}

	inline float operator[] (int i)
	{
		return *(&x + i);
	}

	inline Vector operator+(const Vector& v)
	{
		return Vector(x + v.x, y + v.y, z + v.z);
	}

	inline void operator+= (const Vector& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	inline Vector operator+= (const float f)
	{
		return Vector(x += f, y += f, z += f);
	}


	inline Vector operator-(const Vector& v)
	{
		return Vector(x - v.x, y - v.y, z - v.z);
	}

	inline void operator-=(const Vector& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	inline Vector operator-=(const float f)
	{
		return Vector(x -= f, y -= f, z -= f);
	}

	inline Vector operator*(const float f)
	{
		return Vector(x * f, y * f, z * f);
	}

	inline void operator*=(const float f)
	{
		x *= f;
		y *= f;
		z *= f;
	}

	inline Vector operator/(const float f)
	{
		return Vector(x / f, y / f, z / f);
	}

	inline void operator/=(const float f)
	{
		x /= f;
		y /= f;
		z /= f;
	}

	inline void operator=(const float* f)
	{
		x = f[0];
		y = f[1];
		z = f[2];
	}

	inline void operator=(const float& f)
	{
		x = y = z = f;
	}

	inline bool operator==(const Vector& v)
	{
		return (x == v.x && y == v.y && z == v.z);
	}

	inline bool operator!=(const Vector& v)
	{
		return (x != v.x && y != v.y && z != v.z);
	}

	inline bool operator<=(const Vector& v)
	{
		return (x <= v.x && y <= v.y && z <= v.z);
	}

	inline bool operator>=(const Vector& v)
	{
		return (x >= v.x && y >= v.y && z >= v.z);
	}

	inline bool operator>(const Vector& v)
	{
		return (x > v.x && y > v.y && z > v.z);
	}

	inline bool operator<(const Vector& v)
	{
		return (x < v.x && y < v.y && z < v.z);
	}
};

class Vector2D
{

public:

	// Data members
	float x, y;

	// Ctors
	inline Vector2D() : x(0.0f), y(0.0f)
	{
	}

	inline Vector2D(float fX, float fY) : x(fX), y(fY)
	{
	}

	inline Vector2D(const Vector2D& v) : x(v.x), y(v.y)
	{
	}

	inline Vector2D(float num[2]) : x(num[0]), y(num[1])
	{
	}

	inline void PrintInfo()
	{
		

		printf_s(Decrypt(7,96,32,103,52,105,111,45), x, y);

		

	}

	inline void ZeroOut()
	{
		x = y = 0.0f;
	}

	inline float Length()
	{
		return (float)Math::FastSQRT(x*x + y*y);
	}

	inline float DotProduct(Vector2D v)
	{
		return (x * v.x + y * v.y);
	}

	inline void Normalize()
	{
		float l = 1.0f / Length();
		x *= l;
		y *= l;
	}

	inline float ToDegree(Vector2D to)
	{
		return (180.0f / 3.141f) * asinf(DotProduct(to));
	}

	inline float operator[] (int i)
	{
		return *(&x + i);
	}

	inline Vector2D operator+(const Vector2D& v)
	{
		return Vector2D(x + v.x, y + v.y);
	}

	inline void operator+= (const Vector2D& v)
	{
		x += v.x;
		y += v.y;
	}

	inline Vector2D operator-(const Vector2D& v)
	{
		return Vector2D(x - v.x, y - v.y);
	}

	inline void operator-=(const Vector2D& v)
	{
		x -= v.x;
		y -= v.y;
	}

	inline Vector2D operator*(const float f)
	{
		return Vector2D(x * f, y * f);
	}

	inline void operator*=(const float f)
	{
		x *= f;
		y *= f;
	}

	inline Vector2D operator/(const float f)
	{
		return Vector2D(x / f, y / f);
	}

	inline void operator/=(const float f)
	{
		x /= f;
		y /= f;
	}

	inline void operator=(const float* f)
	{
		x = f[0];
		y = f[1];
	}

	inline void operator=(const float& f)
	{
		x = y = f;
	}

	inline bool operator==(const Vector2D& v)
	{
		return (x == v.x && y == v.y);
	}

	inline bool operator!=(const Vector2D& v)
	{
		return (x != v.x && y != v.y);
	}

	inline bool operator<=(const Vector2D& v)
	{
		return (x <= v.x && y <= v.y);
	}

	inline bool operator>=(const Vector2D& v)
	{
		return (x >= v.x && y >= v.y);
	}

	inline bool operator>(const Vector2D& v)
	{
		return (x > v.x && y > v.y);
	}

	inline bool operator<(const Vector2D& v)
	{
		return (x < v.x && y < v.y);
	}
};