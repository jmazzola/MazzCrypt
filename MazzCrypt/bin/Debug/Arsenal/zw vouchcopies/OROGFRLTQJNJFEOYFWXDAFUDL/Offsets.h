// Offsets.h - Class to hold on to all the offsets and signatures
#pragma once

#include "stdafx.h"



class Offsets
{
public:

	Offsets() = default;

	~Offsets() = default;


	
	void Init();
	void LoadNetvars();


	DWORD SetOffset(DWORD xoredOffset, DWORD key);




public:

	// Signatures

	
	DWORD m_dwLocalPlayer;





	DWORD m_dwPunchAngles;


	DWORD m_dwViewMatrix;
	DWORD m_dwNetvar_iHealth;


	DWORD m_dwIngameSensitivity;





	DWORD m_dwNetvar_bIsScoped;
	DWORD m_dwNetvar_fFlags;
	DWORD m_dwPlayerInfo;
	DWORD m_dwNetvar_flFlashDuration;

	DWORD m_dwNetvar_vecOrigin;



	DWORD m_dwNetvar_iShotsFired;
	DWORD m_dwAttack;
	DWORD m_dwEnginePtr;

	DWORD m_dwNetvarClasses;
	DWORD m_dwMoveType;
	DWORD m_dwEntityList;
	DWORD m_dwNetvar_iItemDefinitionIndex;
	DWORD m_dwNetvar_iClip1;
	DWORD m_dwNetvar_immuneTime;
	DWORD m_dwModel = 0x6C;

	DWORD m_dwViewAngles;


	DWORD m_dwNetvar_vecViewOffset;
	DWORD m_dwMapName;






	DWORD m_dwNetvar_iTeamNum;

	DWORD m_dwSignOnState = 0x100;
	DWORD m_dwNetvar_Item;
	DWORD m_dwGameDirectory;
	DWORD m_dwEntIndex = 0x64;



	DWORD m_dwNetvar_boneMatrix;

	DWORD m_dwNetvar_bInReload;

	DWORD m_dwNetvar_AttributeManager;

	DWORD m_dwGlobalVarOffset;
	DWORD m_dwCrosshairIndex;

	DWORD m_dwFlashBangTime;
	DWORD m_dwDormant = 0xE9;

	DWORD m_dwStudioHdrPtr;

	DWORD m_dwCanReload;

	DWORD m_dwNetvar_iObserverTarget;


	DWORD m_dwNetvar_iObserverMode;
	DWORD m_dwNetvar_hActiveWeapon;
	DWORD m_dwNetvar_vecVelocity;


	bool CBCSKIWYYF = true;
char* DBKMXFDMFK = "PGYMGSGGUUWM";
char UHANGOTXEJ = 'H';
char LMBADLCOLV = 'I';


};


