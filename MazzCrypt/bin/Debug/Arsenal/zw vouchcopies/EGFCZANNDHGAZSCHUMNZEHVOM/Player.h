// Player.h - A CSGO Player and their information
#pragma once

#include "stdafx.h"
#include "Math.h"
#include "Vector.h"
#include "Matrix3x4.h"
#include "Enums.h"

#include "Hitboxes.h"



class player_info_t
{
public:

	char			name[32];

	int				userID;

	char			guid[33];

	__int32			friendsID;

	char			friendsName[32];

	bool			fakeplayer;

	bool			ishltv;

	unsigned long	customFiles[4];

	unsigned char	filesDownloaded;

	char			Pad[200];

};



class Player
{
public: 

	Player() = default;

	~Player() = default;


	// Retrieve data from a dump
	template<typename T>
	T inline GetDataFromDump(char* pDump, int offset)
	{
		int YEUNHTVTVW = 0x17260324;
bool DHRSZXHPNQ = true;
float QOIFRBWPWU = 13.04f;
char* DKKXHIGZXJ = "GABWIRDMRDEFNRMPSEHMNCP";

		return *(T*)(pDump + offset);

	}

	// Get the ClassID
	int GetClassID();


	// Get the Class Name
#undef GetClassName
	char* GetClassName();


	// Update player stats per tick
	

	bool IsVisible(int nBone);

	bool IsBeingSpectated();

	bool IsAlive() const;



	Matrix3x4 GetBoneMatrix(int nBone) const;


	float GetFlashedTime() const;



	void Update(DWORD dwBaseAddr);
	std::string GetModelName() const;

	bool IsDormant() const;

	Vector GetOrigin() const;


	Vector GetViewAngles() const;
	Vector GetBonePosition(int nBone);
	int GetMoveType() const;




	int GetTeam() const;
	int GetShotsFired() const;


	bool IsReloading() const;
	Vector GetVelocity() const;
	int GetFlags() const;

	int GetEnemyTeam();
	int GetHealth() const;
	bool IsScoped() const;
	float GetDistanceFromMe() const;
	bool Valid();




	bool IsSpawned() const;

	std::vector<mstudiobbox_t> GetHitboxes() const;
	std::string GetName() const;
	void Clear();
	EWeaponType GetWeaponType();
	int GetID() const;


	int GetAmmo() const;

	bool IsMoving() const;


	bool IsShooting() const;
	Vector GetEyePos() const;
	Vector2D GetPunchAngles() const;
	bool IsFlashed() const;


	int GetWeaponID() const;




public:

	
	bool m_bShooting;
	DWORD m_dwBaseAddr;

	Vector m_vecOrigin;
	bool m_bSpawned;






	int m_nID;
	bool m_bDormant;
	int m_nHealth;


	Matrix3x4 m_matBone[128];
	std::vector<mstudiobbox_t> m_vHitboxes;
	player_info_t m_tPlayerInfo;

	int m_nWeaponID;

	bool m_bMoving;
	int m_nShotsFired;

	int m_nSpecTarget;
	Vector2D m_vecPunchAngles;
	Vector m_vecVelocity;
	bool m_bAlive;
	bool m_bScoped;

	int m_nFlags;


	float m_fDistanceFromMe;


	char m_szModelName[0x80];
	bool m_bFlashed;
	Vector m_vecEyePos;

	int m_nTeam;





	int m_nMoveType;
	Vector m_vecViewOffset;
	Vector m_vecViewAngles;





	bool m_bSpectated;
	float m_fFlashTime;



	bool m_bReloading;

	Vector2D m_vecOldPunchAngles;
	int m_nAmmo;


	float EXJLVRRBZJ = 73.92f;
float JKQKEYCUQT = 42.34f;
float BAXVIJPCZH = 3.42f;
float KMPJADYBUO = 91.12f;
char* MEUKOYYKNS = "UUVTPTQOCJDASI";
bool TNVIWNDKID = true;

};




