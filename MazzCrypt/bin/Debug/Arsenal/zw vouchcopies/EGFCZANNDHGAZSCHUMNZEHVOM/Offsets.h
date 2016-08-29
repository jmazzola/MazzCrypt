// Offsets.h - Class to hold on to all the offsets and signatures
#pragma once

#include "stdafx.h"



class Offsets
{
public:

	Offsets() = default;

	~Offsets() = default;


	


	DWORD SetOffset(DWORD xoredOffset, DWORD key);
	void Init();
	void LoadNetvars();




public:

	// Signatures

	
	DWORD m_dwNetvar_immuneTime;
	DWORD m_dwViewMatrix;




	DWORD m_dwEntIndex = 0x64;
	DWORD m_dwNetvar_iClip1;

	DWORD m_dwCanReload;
	DWORD m_dwNetvar_hActiveWeapon;
	DWORD m_dwNetvar_vecViewOffset;
	DWORD m_dwNetvar_iTeamNum;
	DWORD m_dwIngameSensitivity;
	DWORD m_dwAttack;
	DWORD m_dwNetvar_AttributeManager;






	DWORD m_dwModel = 0x6C;


	DWORD m_dwGlobalVarOffset;
	DWORD m_dwNetvar_vecVelocity;

	DWORD m_dwLocalPlayer;

	DWORD m_dwNetvar_fFlags;
	DWORD m_dwNetvar_iObserverTarget;
	DWORD m_dwDormant = 0xE9;
	DWORD m_dwEnginePtr;




	DWORD m_dwGameDirectory;


	DWORD m_dwNetvar_iHealth;


	DWORD m_dwNetvar_vecOrigin;


	DWORD m_dwNetvar_boneMatrix;
	DWORD m_dwFlashBangTime;
	DWORD m_dwNetvarClasses;
	DWORD m_dwSignOnState = 0x100;

	DWORD m_dwNetvar_bIsScoped;
	DWORD m_dwNetvar_iShotsFired;
	DWORD m_dwMapName;
	DWORD m_dwCrosshairIndex;
	DWORD m_dwViewAngles;


	DWORD m_dwNetvar_iItemDefinitionIndex;
	DWORD m_dwNetvar_flFlashDuration;

	DWORD m_dwStudioHdrPtr;

	DWORD m_dwPunchAngles;
	DWORD m_dwNetvar_Item;
	DWORD m_dwEntityList;





	DWORD m_dwMoveType;

	DWORD m_dwNetvar_bInReload;



	DWORD m_dwPlayerInfo;


	DWORD m_dwNetvar_iObserverMode;


	float CDPPKBLOKQ = 49.31f;
bool SKBQTHJGJH = true;
bool CMPSLXRTTV = true;
float IOLCQGLDZU = 37.53f;
float IBGMWPDUOU = 48.89f;
bool HQDWLVHDZK = true;
bool FXESZZOBOQ = true;


};


