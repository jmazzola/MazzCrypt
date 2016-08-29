// CSGO.h - An object to hold all the shit we're doing with the game. Players, offsets all that shiz
#pragma once

#include "stdafx.h"
#include "Memory.h"
#include "Offsets.h"
#include "Player.h"
#include "Config.h"
#include "Enums.h"

#define m_Me m_Players[0]

struct Hitbox
{
	int m_nBone;
	Vector m_vMin;
	Vector m_vMax;

	void Setup(int b, Vector min, Vector max)
	{
		m_nBone = b;
		m_vMin = min;
		m_vMax = max;
	}
};

class CSGO
{
public:

	CSGO() = default;
	~CSGO() = default;

	// Attach to CSGO
	bool Attach();

	// Detach from CSGO
	void Detach();

	void GrabStudioHdrPtr();

	void ClearBases();
	
	// Load the base offsets
	bool LoadBases(bool bGetDLLs);

	// Update Tick
	void Update();

	// Are we in game?
	bool IsInGame();

	bool IsChangingLevel();

	bool IsPrespawned();

	// What map are we currently on?
	std::string GetMapName();

	// Get our game directory path
	std::string GetGameDirectory();

public:

	// Our memory module
	Memory m_Mem;

	// Our config
	Config m_Config;

	// Player Pool
	Player m_Players[64];
	
	// Viewmatrix
	float m_flViewMatrix[16];

	// Bases
	DWORD m_dwClientBase;
	DWORD m_dwEngineBase;
	DWORD m_dwLocalBase;
	DWORD m_dwEntityBase;
	DWORD m_dwBoneMatrix;
	DWORD m_dwAnglePointer;
	DWORD m_dwStudioHdrPointer;
	DWORD m_dwGlobalVarsBase;

	// Offsets
	Offsets m_Offsets;

	// Window Dimensions
	int m_iWindowWidth;
	int m_iWindowHeight;
};

extern CSGO* pCSGO;
