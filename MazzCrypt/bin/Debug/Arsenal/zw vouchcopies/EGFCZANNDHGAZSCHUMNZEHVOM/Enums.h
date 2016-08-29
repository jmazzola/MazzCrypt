// Enums.h - All of the enumerations to have from CSGO
#pragma once

#define	FL_ONGROUND				(1<<0)	// At rest / on the ground
#define FL_DUCKING				(1<<1)	// Player flag -- Player is fully crouched
#define	FL_WATERJUMP			(1<<3)	// player jumping out of water
#define FL_ONTRAIN				(1<<4) // Player is _controlling_ a train, so movement commands should be ignored on client during prediction.
#define FL_INRAIN				(1<<5)	// Indicates the entity is standing in rain
#define FL_FROZEN				(1<<6) // Player is frozen for 3rd person camera
#define FL_ATCONTROLS			(1<<7) // Player can't move, but keeps key inputs for controlling another entity
#define	FL_CLIENT				(1<<8)	// Is a player
#define FL_FAKECLIENT			(1<<9)	// Fake client, simulated server side; don't send network messages to them
#define	FL_INWATER				(1<<10)	// In water

enum ETeams : int
{
	Team_NoTeam = 0,
	Team_Spectator = 1,
	Team_Terrorists = 2,
	Team_CounterTerrorists = 3,
};

enum ESignOnState : int
{
	SOS_None = 0,
	SOS_Challenge = 1,
	SOS_Connected = 2,
	SOS_New = 3,
	SOS_Prespawn = 4,
	SOS_Spawn = 5,
	SOS_Full = 6,
	SOS_ChangeLevel = 7,
};

enum EWeaponType : int
{
	WeapType_Pistol = 0,
	WeapType_Rifle = 1,
	WeapType_SMG = 2,
	WeapType_Sniper = 3,
	WeapType_KnifeType = 4,
	WeapType_Grenade = 5,
	WeapType_LMG = 6,
	WeapType_Shotgun = 7,
	WeapType_ZeusGun = 8,
	WeapType_C4Explosive = 9,
};

enum ETargetType : int
{
	TargetType_Enemies = 0,
	TargetType_Teammates = 1,
	TargetType_Everyone = 2,
};

enum EWeaponIDs : int
{
	WID_None = 0,
	WID_Deagle = 1,
	WID_Dual_Berettas = 2,
	WID_Five_Seven = 3,
	WID_Glock = 4,
	WID_AK47 = 7,
	WID_AUG = 8,
	WID_AWP = 9,
	WID_FAMAS = 10,
	WID_G3SG1_Auto = 11,
	WID_Galil = 13,
	WID_M249 = 14,
	WID_M4A4 = 16,
	WID_MAC10 = 17,
	WID_P90 = 19,
	WID_UMP45 = 24,
	WID_XM1014 = 25,
	WID_PPBizon = 26,
	WID_MAG7 = 27,
	WID_Negev = 28,
	WID_SawedOff = 29,
	WID_Tec9 = 30,
	WID_Zeus = 31,
	WID_P2000 = 32,
	WID_MP7 = 33,
	WID_MP9 = 34,
	WID_Nova = 35,
	WID_P250 = 36,
	WID_SCAR_Auto = 38,
	WID_SG553 = 39,
	WID_Scout = 40,
	WID_Knife = 42,
	WID_Flashbang = 43,
	WID_HEFrag = 44,
	WID_Smoke = 45,
	WID_Molly = 46,
	WID_Decoy = 47,
	WID_Firebomb = 48,
	WID_C4 = 49,
	WID_MusicKit = 58,
	WID_Default_Knife = 59,
	WID_M4A1S = 60,
	WID_USP = 61,
	WID_TradeUpContract = 62,
	WID_CZ75 = 63,
	WID_Revolver = 64,
	WID_BayonetKnife = 500,
	WID_FlipKnife = 505,
	WID_GutKnife = 506,
	WID_KarambitKnife = 507,
	WID_M9BayonetKnife = 508,
	WID_HuntsmanKnife = 509,
	WID_FalchionKnife = 512,
	WID_BowieKnife = 514,
	WID_ButterflyKnife = 515,
	WID_ShadowDaggerKnife = 516,
};

enum EBones : int
{
	Bone_Pelvis = 0,
	Bone_Spine0 = 1,
	Bone_Spine1 = 2,
	Bone_Spine2 = 3,
	Bone_Spine3 = 4,
	Bone_Neck = 5,
	Bone_Head = 6,
	Bone_LeftClavicle = 7,
	Bone_LeftUpperarm = 8,
	Bone_LeftLowerarm = 9,
	Bone_LeftHand = 10,
	Bone_RightClavicle = 35,
	Bone_RightUpperarm = 36,
	Bone_RightLowerarm = 37,
	Bone_RightHand = 38,
	Bone_LeftUpperleg = 63,
	Bone_LeftLowerleg = 64,
	Bone_LeftAnkle = 65,
	Bone_RightUpperleg = 69,
	Bone_RightLowerleg = 70,
	Bone_RightAnkle = 71,
	Bone_MAX = 81,
};


enum EMoveType : int
{
	MOVETYPE_NONE = 0,			// never moves
	MOVETYPE_ISOMETRIC,			// For players -- in TF2 commander view, etc.
	MOVETYPE_WALK,				// Player only - moving on the ground
	MOVETYPE_STEP,				// gravity, special edge handling -- monsters use this
	MOVETYPE_FLY,				// No gravity, but still collides with stuff
	MOVETYPE_FLYGRAVITY,		// flies through the air + is affected by gravity
	MOVETYPE_VPHYSICS,			// uses VPHYSICS for simulation
	MOVETYPE_PUSH,				// no clip to world, push and crush
	MOVETYPE_NOCLIP,			// No gravity, no collisions, still do velocity/avelocity
	MOVETYPE_LADDER,			// Used by players only when going onto a ladder
	MOVETYPE_OBSERVER,			// Observer movement, depends on player's observer mode
	MOVETYPE_CUSTOM,			// Allows the entity to describe its own physics
};

enum ETriggerTypes : int
{
	Trigger_InCross = 0,
	Trigger_Hitbox = 1,
};

