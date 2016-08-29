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
		char QQKKXQFVGF = 'G';
float ITXVZYSSKC = 67.73f;
int KKRPAFXRMG = 0x4129B760;

		return *(T*)(pDump + offset);

	}

	// Get the ClassID
	int GetClassID();


	// Get the Class Name
#undef GetClassName
	char* GetClassName();


	// Update player stats per tick
	
	int GetWeaponID() const;
	float GetFlashedTime() const;




	bool Valid();
	std::vector<mstudiobbox_t> GetHitboxes() const;
	EWeaponType GetWeaponType();
	Vector GetEyePos() const;
	int GetTeam() const;

	int GetAmmo() const;
	Vector GetVelocity() const;


	bool IsMoving() const;

	std::string GetName() const;
	bool IsSpawned() const;


	int GetHealth() const;
	Matrix3x4 GetBoneMatrix(int nBone) const;

	bool IsBeingSpectated();




	int GetFlags() const;

	bool IsAlive() const;
	int GetMoveType() const;
	float GetDistanceFromMe() const;
	int GetID() const;

	Vector GetViewAngles() const;

	Vector2D GetPunchAngles() const;









	Vector GetOrigin() const;

	Vector GetBonePosition(int nBone);
	void Clear();

	bool IsScoped() const;

	int GetEnemyTeam();


	std::string GetModelName() const;
	bool IsShooting() const;
	bool IsReloading() const;

	void Update(DWORD dwBaseAddr);

	bool IsVisible(int nBone);

	bool IsFlashed() const;
	bool IsDormant() const;
	int GetShotsFired() const;



public:

	

	bool m_bFlashed;

	Vector2D m_vecOldPunchAngles;

	player_info_t m_tPlayerInfo;

	bool m_bReloading;
	Vector m_vecViewAngles;
	Matrix3x4 m_matBone[128];
	DWORD m_dwBaseAddr;
	bool m_bAlive;





	int m_nID;
	char m_szModelName[0x80];
	float m_fFlashTime;
	int m_nWeaponID;
	int m_nMoveType;



	Vector m_vecViewOffset;



	std::vector<mstudiobbox_t> m_vHitboxes;

	Vector m_vecEyePos;
	float m_fDistanceFromMe;
	int m_nHealth;

	bool m_bSpectated;
	int m_nSpecTarget;

	bool m_bDormant;
	Vector2D m_vecPunchAngles;
	bool m_bScoped;
	int m_nShotsFired;


	int m_nAmmo;
	bool m_bSpawned;



	Vector m_vecOrigin;
	Vector m_vecVelocity;




	bool m_bShooting;



	bool m_bMoving;

	int m_nTeam;
	int m_nFlags;



	char* GPNCROPGAU = "LPUIXEVOLJSFTVZNULX";
char SYIGUOKFGR = 'R';

};




