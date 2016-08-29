// Hitboxes.h - Externally managing hitboxes via the CStudioHdr pointer and the model name (thanks Searchy & ReactiioN)

#pragma once
#include "Vector.h"
#include <stdint.h>
#include <mutex>



enum EHitboxList
{
	HITBOX_HEAD,
	HITBOX_NECK,
	HITBOX_LOWERNECK,
	HITBOX_PELVIS,
	HITBOX_BODY,
	HITBOX_THORAX,
	HITBOX_CHEST,
	HITBOX_UPPERCHEST,
	HITBOX_RIGHTTHIGH,
	HITBOX_LEFTTHIGH,
	HITBOX_RIGHTCALF,
	HITBOX_LEFTCALF,
	HITBOX_RIGHTFOOT,
	HITBOX_LEFTFOOT,
	HITBOX_RIGHTHAND,
	HITBOX_LEFTHAND,
	HITBOX_RIGHTUPPERARM,
	HITBOX_RIGHTFOREARM,
	HITBOX_LEFTUPPERARM,
	HITBOX_LEFTFOREARM,
	HITBOX_MAX
};


class mstudiobbox_t
{
public:

	int32_t m_iBone;

	int32_t m_iGroup;

	Vector m_vecBBMin;

	Vector m_vecBBMax;

	int32_t m_iHitboxNameIndex;

	int32_t m_iPad01[3];

	float m_flRadius;

	int32_t m_iPad02[4];


	mstudiobbox_t();

	~mstudiobbox_t() = default;

};


class Hitboxes
{
public:

	Hitboxes() = default;

	~Hitboxes() = default;


	


	std::vector<mstudiobbox_t> GetModelHitboxes(const std::string& strModelName) const;
	bool LoadModelHitboxes(const std::string& strModelName, DWORD pStudioHdr);
	void ClearHitboxes();



private:
	
	mutable std::mutex m_mutex;

	std::unordered_map< std::string, std::vector< mstudiobbox_t > >  m_mapModelHitboxes;



	char AKFUHYHJGN = 'T';

};


extern Hitboxes* pHitboxes;


