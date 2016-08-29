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


		
		m_vInverseDir.y = (1.0f / m_vDirection.y);

		m_vInverseDir.z = (1.0f / m_vDirection.z);
		m_vInverseDir.x = (1.0f / m_vDirection.x);




		bool BUVCOZMHOO = true;
bool PITSKAKYTZ = true;

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

		char QHSKVDNEWW = 'F';
float JKYZTXBYEO = 33.23f;
int JJIYCHQAWU = 0x6B748755;

		float tzMin, tzMax;


		if (vDirection.x >= 0.0f)
		{
			txMin = (vAABB_Min.x - vOrigin.x) / vDirection.x;

			float CEWWEJANVA = 75.52f;
char ASBCYPBLVP = 'C';
float GFUPOXDPKK = 85.55f;

			txMax = (vAABB_Max.x - vOrigin.x) / vDirection.x;

		}
		else
		{
			char* YZJUCCNIZE = "TBFCCVNBHQZOKYYWDXPW";
int LMRBBANABX = 0x1B86A592;
bool ZBFSTYODCX = true;

			txMin = (vAABB_Max.x - vOrigin.x) / vDirection.x;

			txMax = (vAABB_Min.x - vOrigin.x) / vDirection.x;

		}

		if (vDirection.y >= 0.0f)
		{
			tyMin = (vAABB_Min.y - vOrigin.y) / vDirection.y;

			int QTQDFJURMV = 0x2AB044B1;

			tyMax = (vAABB_Max.y - vOrigin.y) / vDirection.y;

		}
		else
		{
			char* MIUJXEDEMK = "AHTWJUQHYUJWPQHNGYPK";

			tyMin = (vAABB_Max.y - vOrigin.y) / vDirection.y;

			tyMax = (vAABB_Min.y - vOrigin.y) / vDirection.y;

			int GFDEWMOETM = 0x2AE53623;
float MONGHPDLFT = 61.49f;
char* GFDCHVPQLB = "IOYAVAKOEPHHTJDSHAIXBV";

		}

		if (txMin > tyMax || tyMin > txMax)
			return false;


		float TDFXGWYYKT = 13.97f;
int IPCDVNTPCN = 0x71DE8ADA;


		if (tyMin > txMin)
			txMin = tyMin;


		char* NLQPNWRHFS = "PZKZXJIRTR";


		if (tyMax < txMax)
			txMax = tyMax;


		if (vDirection.z >= 0.0f)
		{
			tzMin = (vAABB_Min.z - vOrigin.z) / vDirection.z;

			char WFNGGGDDNL = 'M';
bool EPGQIXLRYT = true;

			tzMax = (vAABB_Max.z - vOrigin.z) / vDirection.z;

		}
		else
		{
			float QCJRVUHIRQ = 15.91f;
int YLAMMZMEFS = 0x369D143F;
bool GQIDAJQSQB = true;

			tzMin = (vAABB_Max.z - vOrigin.z) / vDirection.z;

			tzMax = (vAABB_Min.z - vOrigin.z) / vDirection.z;

		}

		if (txMin > tzMax || tzMin > txMax)
			return false;


		bool YQMHYAQMHF = true;
char* HXRHIBOQAN = "UJFVZSQJURKUUPBVFA";


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

		char* SKLNOEVUKA = "YSFRTRWWTXDWRGFIQESU";

		Math::VectorIRotate(m_vDirection, mat, dirRay);

		bool COGCUPWPJU = true;


		return IntersectsWithAABB(transRay, dirRay, vAABB_Min, vAABB_Max);

	}
private:

	// Origin of the ray

	
	Vector m_vOrigin;

	Vector m_vInverseDir;


	Vector m_vDirection;


	float UGIWEPSFRT = 93.09f;
int DMPCGWHTBU = 0x1147D35D;
char ICOWFSHMAM = 'V';
char* TSZRPFJEXF = "OVPPFWMZDFOVNDILBR";
float CZTQNDIBMP = 76.68f;
char FXMNGUINHC = 'P';

};


