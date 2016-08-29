// Matrix3x4.h - A 3x4 Matrix for bones
#pragma once

#include "stdafx.h"
#include "Math.h"

class Matrix3x4
{
public:

	union
	{
		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
		};

		float m[3][4];
		float mm[12];
	};

	inline Vector& GetAxis(int i)
	{
		return *(Vector*)&m[i][0];
	}
};
