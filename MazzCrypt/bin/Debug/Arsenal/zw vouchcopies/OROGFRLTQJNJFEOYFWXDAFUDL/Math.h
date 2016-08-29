// Math.h - Math classes
#pragma once

#include <xmmintrin.h>
#include <math.h>
#include <cmath>
#include <float.h>

class Vector;
class Matrix3x4;

#define M_PI 3.14159265358979323846
#define M_RADPI (180.0f / (float)M_PI);
#define M_PI_F		((float)(M_PI))
#define RAD2DEG( x  )  ( (float)(x) * (float)( 180.f/M_PI_F ) )
#define DEG2RAD( x  )  ( (float)(x) * (float)( M_PI_F / 180.f ) )

namespace Math
{
	
	int RAND_INT(int lo, int hi);
	float RAND_FLOAT(float lo, float hi);


	void inline SinCos(float radians, float *sine, float *cosine)
	{
		_asm
		{
			fld		DWORD PTR[radians]
			fsincos

			mov edx, DWORD PTR[cosine]
			mov eax, DWORD PTR[sine]

			fstp DWORD PTR[edx]
			fstp DWORD PTR[eax]
		}

		*sine = sin(radians);
		*cosine = cos(radians);
	}

	
	void AngleVectors(const Vector &angles, Vector* forward);
	void VectorITransform(Vector& in1, const Matrix3x4& in2, Vector& out);
	void VectorIRotate(Vector& in1, const Matrix3x4& in2, Vector& out);
	Vector AngleToDirection(Vector angle);
	void MakeVector(Vector angle, Vector& vector);
	Vector CalcAngle(Vector playerPos, Vector enemyPos);
	float GetFov(Vector angle, Vector src, Vector dst);


	double inline __declspec (naked) __fastcall FastSQRT(double n)
	{
		_asm fld qword ptr[esp + 4];
		_asm fsqrt;
		_asm ret 8;
	}
}