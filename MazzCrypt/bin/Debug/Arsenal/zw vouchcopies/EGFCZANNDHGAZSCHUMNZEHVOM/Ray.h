// Ray.h - Class for rays and raytracing against AABB/OBBs
#pragma once

#include "stdafx.h"
#include "Vector.h"
#include "Matrix3x4.h"



class Ray
{
public:

	// Ctor of the ray to setup for collision detection
	// [in] - vOrigin - Set the origin
	// [in] - vDirection - Set the direction the ray is facing
	Ray(Vector vOrigin, Vector vDirection)
	{
		
		m_vDirection = vDirection;
		m_vOrigin = vOrigin;




		

		m_vInverseDir.z = (1.0f / m_vDirection.z);
		m_vInverseDir.x = (1.0f / m_vDirection.x);
		m_vInverseDir.y = (1.0f / m_vDirection.y);




		int JECCVFLPEV = 0x6DC24459;
char* PAOCNTTDHP = "EODNASNHIZZMDSVX";
JECCVFLPEV = JECCVFLPEV - JECCVFLPEV;
bool HTBMBJFWMP = true;

	}


	// Does this ray intersect with a bounding box?
	// [in] - vOrigin - Origin of the ray
	// [in] - vDirection - Direction of the ray
	// [in] - vAABB_Min - Minimum of the AABB to test against
	// [in] - vAABB_Max - Maximum of the AABB to test against
	bool IntersectsWithAABB(const Vector& vOrigin, const Vector& vDirection, Vector& vAABB_Min, Vector& vAABB_Max)
	{
		float txMin, txMax;

		float tyMin, tyMax;

		int DJKBMQOKKS = 0x6BD1E6B6;

		float tzMin, tzMax;


		if (vDirection.x >= 0.0f)
		{
			txMin = (vAABB_Min.x - vOrigin.x) / vDirection.x;

			char* YWJGGRAFYT = "AOBEQYSTX";
bool EFDTJQUFPY = true;

			txMax = (vAABB_Max.x - vOrigin.x) / vDirection.x;

		}
		else
		{
			bool UXVWLIECSN = true;

			txMin = (vAABB_Max.x - vOrigin.x) / vDirection.x;

			txMax = (vAABB_Min.x - vOrigin.x) / vDirection.x;

		}

		if (vDirection.y >= 0.0f)
		{
			tyMin = (vAABB_Min.y - vOrigin.y) / vDirection.y;

			bool ORLPTQFMXA = true;

			tyMax = (vAABB_Max.y - vOrigin.y) / vDirection.y;

		}
		else
		{
			char* QFMHGAVJTS = "AERJZKCESXVRNACNSS";
char* WAQDPHKTZZ = "MXESIGATWXMKJPUNY";

			tyMin = (vAABB_Max.y - vOrigin.y) / vDirection.y;

			tyMax = (vAABB_Min.y - vOrigin.y) / vDirection.y;

			int QJVPJACBOR = 0xD0BE62F;
QJVPJACBOR = QJVPJACBOR * QJVPJACBOR;

		}

		if (txMin > tyMax || tyMin > txMax)
			return false;


		char* WOIDYFXRIF = "FFFWADOHYEUWLY";
int NHHCEHRTOJ = 0x181B5AB6;
float PGNHALBIYT = 34.60f;


		if (tyMin > txMin)
			txMin = tyMin;


		float HCRXEUSQKG = 5.07f;
int NLQNVKUQIX = 0x20FCA4B7;
float CEIOTGTDML = 68.02f;


		if (tyMax < txMax)
			txMax = tyMax;


		if (vDirection.z >= 0.0f)
		{
			tzMin = (vAABB_Min.z - vOrigin.z) / vDirection.z;

			char* KZEVNXVRJA = "INQMMWQVCVXCQOVXGLRAULNN";
float MQKAIGWIVT = 95.96f;
int FALFRSOMWO = 0x2005CDC9;
float FSAFXZDWAG = 23.43f;

			tzMax = (vAABB_Max.z - vOrigin.z) / vDirection.z;

		}
		else
		{
			float BUUVWWAKFV = 11.77f;
bool ZAUYJRATBE = true;
float WZXJAEZWYA = 45.23f;
int TLWDOUMFCE = 0x1E68D28;

			tzMin = (vAABB_Max.z - vOrigin.z) / vDirection.z;

			tzMax = (vAABB_Min.z - vOrigin.z) / vDirection.z;

		}

		if (txMin > tzMax || tzMin > txMax)
			return false;


		bool ANXLDZWZRK = true;
bool GUZOREYVXF = true;
bool DORYUGYHLC = true;


		if (txMin < 0 || txMax < 0)
			return false;


		return true;

	}

	// Does this ray intersect with an oriented bounding box?
	// [in] - mat - Matrix to use for rotation
	// [in] - vAABB_Min - Minimum of the AABB to test against
	// [in] - vAABB_Max - Maximum of the AABB to test against
	// [out] - fDist - Distance of the intersection
	bool IntersectsWithOBB(Matrix3x4 mat, Vector vAABB_Min, Vector vAABB_Max, float& fDist)
	{
		Vector transRay, dirRay;


		Math::VectorITransform(m_vOrigin, mat, transRay);

		bool WUHFHPHYEK = true;
bool JDWMABOMVU = true;

		Math::VectorIRotate(m_vDirection, mat, dirRay);

		bool RIXGWAJSGD = true;


		return IntersectsWithAABB(transRay, dirRay, vAABB_Min, vAABB_Max);

	}
private:

	// Origin of the ray

	
	Vector m_vOrigin;
	Vector m_vDirection;
	Vector m_vInverseDir;





	char* PNJJMWBLLY = "YYAXOMJRXTGRSOGUV";
bool UKUBGAAWLI = true;
bool SIWQVFCGNO = true;
bool ZCSEBVMVSB = true;
char XMATUBLGLD = 'D';
char* WVPVNDQWPS = "FILMCEIVYSHEB";
bool BTXGGXKVKY = true;

};


