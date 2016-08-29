// Triggerbot.h - Triggerbot cheat thread
#pragma once

#include "stdafx.h"
#include "CSGO.h"
#include "Player.h"
#include "Utils.h"
#include "Enums.h"
#include "Mouse.h"
#include "Math.h"
#include "Ray.h"
#include "Config.h"

#include "RCS.h"

#include "Hitboxes.h"

#include "Decrypt.h"





class Triggerbot
{
public:

	Triggerbot() = default;

	~Triggerbot() = default;


	// Load Weapon Settings from Config
	void GetWeaponSettings(TriggerWeaponSettings& tWeap)
	{
		switch (pCSGO->m_Me.GetWeaponID())
		{
			case WID_Glock:
			{
				



				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tGlock.m_hitboxes;

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tGlock.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tGlock.m_nDelayBefore;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tGlock.m_fRCSScale;


				break;

			}

			case WID_P2000:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tP2K.m_fRCSScale;


				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tP2K.m_nDelayBefore;

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tP2K.m_nDelayAfter;

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tP2K.m_hitboxes;

				break;

			}

			case WID_USP:
			{
				

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tUSP.m_nDelayAfter;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tUSP.m_nDelayBefore;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tUSP.m_hitboxes;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tUSP.m_fRCSScale;



				break;

			}

			case WID_P250:
			{
				

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tP250.m_hitboxes;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tP250.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tP250.m_nDelayBefore;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tP250.m_fRCSScale;

				break;

			}

			case WID_Five_Seven:
			{
				

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tFiveSeven.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tFiveSeven.m_hitboxes;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tFiveSeven.m_nDelayBefore;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tFiveSeven.m_fRCSScale;


				break;

			}

			case WID_Deagle:
			{
				
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tDeagle.m_nDelayBefore;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tDeagle.m_fRCSScale;




				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tDeagle.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tDeagle.m_hitboxes;

				break;

			}

			case WID_Dual_Berettas:
			{
				
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tDuelies.m_nDelayBefore;



				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tDuelies.m_fRCSScale;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tDuelies.m_nDelayAfter;

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tDuelies.m_hitboxes;

				break;

			}

			case WID_Tec9:
			{
				

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tTec9.m_nDelayAfter;



				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tTec9.m_fRCSScale;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tTec9.m_nDelayBefore;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tTec9.m_hitboxes;

				break;

			}

			case WID_CZ75:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tCZ75.m_fRCSScale;



				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tCZ75.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tCZ75.m_hitboxes;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tCZ75.m_nDelayBefore;


				break;

			}

			case WID_Revolver:
			{
				
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tRevolver.m_nDelayBefore;



				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tRevolver.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tRevolver.m_hitboxes;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tRevolver.m_fRCSScale;


				break;

			}

			case WID_Galil:
			{
				

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tGalil.m_fRCSScale;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tGalil.m_nDelayBefore;

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tGalil.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tGalil.m_nDelayAfter;


				break;

			}

			case WID_AK47:
			{
				


				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tAK47.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tAK47.m_nDelayAfter;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tAK47.m_fRCSScale;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tAK47.m_nDelayBefore;



				break;

			}

			case WID_M4A4:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tM4A4.m_fRCSScale;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tM4A4.m_nDelayBefore;


				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tM4A4.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tM4A4.m_nDelayAfter;



				break;

			}

			case WID_M4A1S:
			{
				
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tM4A1S.m_hitboxes;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tM4A1S.m_fRCSScale;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tM4A1S.m_nDelayBefore;

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tM4A1S.m_nDelayAfter;



				break;

			}

			case WID_SG553:
			{
				

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tSG553.m_nDelayAfter;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tSG553.m_fRCSScale;


				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tSG553.m_hitboxes;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tSG553.m_nDelayBefore;

				break;

			}

			case WID_AUG:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tAUG.m_fRCSScale;


				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tAUG.m_hitboxes;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tAUG.m_nDelayBefore;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tAUG.m_nDelayAfter;

				break;

			}

			case WID_FAMAS:
			{
				


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tFAMAS.m_nDelayAfter;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tFAMAS.m_fRCSScale;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tFAMAS.m_nDelayBefore;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tFAMAS.m_hitboxes;


				break;

			}

			case WID_MAC10:
			{
				

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tMAC10.m_fRCSScale;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tMAC10.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tMAC10.m_nDelayBefore;

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tMAC10.m_hitboxes;

				break;

			}

			case WID_MP7:
			{
				

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tMP7.m_fRCSScale;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tMP7.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tMP7.m_nDelayBefore;

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tMP7.m_hitboxes;

				break;

			}

			case WID_MP9:
			{
				

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tMP9.m_hitboxes;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tMP9.m_fRCSScale;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tMP9.m_nDelayBefore;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tMP9.m_nDelayAfter;

				break;

			}

			case WID_UMP45:
			{
				
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tUMP45.m_nDelayBefore;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tUMP45.m_fRCSScale;



				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tUMP45.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tUMP45.m_nDelayAfter;

				break;

			}

			case WID_PPBizon:
			{
				

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tBizon.m_hitboxes;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tBizon.m_nDelayAfter;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tBizon.m_fRCSScale;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tBizon.m_nDelayBefore;

				break;

			}

			case WID_P90:
			{
				

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tP90.m_hitboxes;


				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tP90.m_fRCSScale;

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tP90.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tP90.m_nDelayBefore;

				break;

			}

			case WID_M249:
			{
				

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tM249.m_nDelayBefore;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tM249.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tM249.m_nDelayAfter;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tM249.m_fRCSScale;



				break;

			}

			case WID_Negev:
			{
				
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tNegev.m_nDelayAfter;


				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tNegev.m_fRCSScale;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tNegev.m_nDelayBefore;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tNegev.m_hitboxes;



				break;

			}

			case WID_AWP:
			{
				
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tAWP.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tAWP.m_nDelayBefore;


				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tAWP.m_hitboxes;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tAWP.m_fRCSScale;


				break;

			}

			case WID_SCAR_Auto:
			{
				
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tSCAR20.m_hitboxes;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tSCAR20.m_nDelayBefore;


				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tSCAR20.m_fRCSScale;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tSCAR20.m_nDelayAfter;


				break;

			}

			case WID_G3SG1_Auto:
			{
				

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tG3SG1.m_hitboxes;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tG3SG1.m_fRCSScale;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tG3SG1.m_nDelayAfter;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tG3SG1.m_nDelayBefore;


				break;

			}

			case WID_Scout:
			{
				


				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tScout.m_nDelayBefore;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tScout.m_fRCSScale;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tScout.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tScout.m_hitboxes;

				break;

			}

			case WID_Nova:
			{
				
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tNova.m_nDelayBefore;

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tNova.m_hitboxes;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tNova.m_fRCSScale;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tNova.m_nDelayAfter;


				break;

			}

			case WID_XM1014:
			{
				

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tXM1014.m_nDelayAfter;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tXM1014.m_fRCSScale;

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tXM1014.m_hitboxes;


				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tXM1014.m_nDelayBefore;

				break;

			}

			case WID_SawedOff:
			{
				
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tSawedOff.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tSawedOff.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tSawedOff.m_nDelayBefore;



				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tSawedOff.m_fRCSScale;


				break;

			}

			case WID_MAG7:
			{
				


				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tMag7.m_fRCSScale;


				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tMag7.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tMag7.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tMag7.m_nDelayBefore;

				break;

			}

			default:
			break;

		}

		pRCS->m_fRCSScale = tWeap.m_fRCSScale;

	}

	// Get Player with In-cross method
	Player* GetPlayerInCross()
	{
		int WFWPARTCAX = 0x27AB0FD9;
int OYIYQFXUTJ = 0x6EFCA58A;
int JPMAJQLRQU = OYIYQFXUTJ + WFWPARTCAX;
char* XWDRLQCJND = "MMSZKYVQH";

		DWORD xhairID = pCSGO->m_Mem.Read<DWORD>(pCSGO->m_dwLocalBase + pCSGO->m_Offsets.m_dwCrosshairIndex);


		for (int i = 1; i < 64; i++)

		{
			Player* ply = &pCSGO->m_Players[i];


			int HRDAMRECXZ = 0x11655C3A;
HRDAMRECXZ = HRDAMRECXZ + HRDAMRECXZ;


			if (!ply->Valid())
				continue;


			bool bEnemy = (pCSGO->m_Me.GetTeam() == ply->GetEnemyTeam());

			char XUEUKYJRTL = 'T';
float EYYIBMXJPT = 85.30f;
char VZXURQFWEC = 'T';
char* VSGGTFFRJP = "UOULTRPOEYWZLBOACGX";
char* CFQNJFQQKN = "YFICGWFMEO";


			if ((pCSGO->m_Config.m_TriggerSettings.m_nTargetType == TargetType_Enemies) && !bEnemy)
				continue;

			else if ((pCSGO->m_Config.m_TriggerSettings.m_nTargetType == TargetType_Teammates) && bEnemy)
				continue;


			if (ply->GetID() == xhairID)
			{
				if (pCSGO->m_Config.m_TriggerSettings.m_bAntiJump && !(ply->GetFlags() & FL_ONGROUND) && (ply->GetMoveType() != EMoveType::MOVETYPE_LADDER))
					return nullptr;


				return ply;

			}

			bool EEEDLMFOPY = true;
int NAZEQUYTDY = 0x292C9370;
bool SUOPFOQLML = true;
bool MZTNIPDZEP = true;

		}

		return nullptr;

	}

	// Get Player who is in our eye-rays
	Player* GetPlayerInRay(std::vector<int> hitboxes)
	{
		for (int i = 1; i < 64; i++)

		{
			Vector viewDirection = Math::AngleToDirection(pCSGO->m_Me.GetViewAngles());

			bool GVBGRUKAAS = true;
char* CNNYGBLTKK = "OTUNEFPPORTGPEEASPTNPWSX";
float CKTOOEHVVM = 50.98f;
int TERXKRAXWC = 0x63512F95;
int MKTSRDLJXD = TERXKRAXWC + TERXKRAXWC;

			Ray viewRay(pCSGO->m_Me.GetEyePos(), viewDirection);

			float distance;


			Player* ply = &pCSGO->m_Players[i];


			bool bEnemy = (pCSGO->m_Me.GetTeam() == ply->GetEnemyTeam());


			if ((pCSGO->m_Config.m_TriggerSettings.m_nTargetType == TargetType_Enemies) && !bEnemy)
				continue;

			else if ((pCSGO->m_Config.m_TriggerSettings.m_nTargetType == TargetType_Teammates) && bEnemy)
				continue;


			float YLUMZJDANB = 15.92f;


			if (!ply->Valid())
				continue;


			if (pCSGO->m_Config.m_TriggerSettings.m_bAntiJump && !(ply->GetFlags() & FL_ONGROUND) && (ply->GetMoveType() != EMoveType::MOVETYPE_LADDER))
				continue;


			if (ply->GetHitboxes().empty())
				return nullptr;


			int KXIVTTWZCI = 0x45AD8D50;


			for (size_t i = 0; i < hitboxes.size(); i++)

			{
				int numHitbox = hitboxes[i];


				if (ply->GetHitboxes().empty())
					break;


				char* WMIXEDCFXP = "ORSLCPGQMEWEOVJ";
float VHXIOYUYKV = 15.66f;

				auto hitbox = ply->GetHitboxes()[numHitbox];


				/*float fov = Math::GetFov(pCSGO->m_Me.GetViewAngles(), pCSGO->m_Me.GetEyePos(), ply->GetBonePosition(hitbox.m_iBone));


				if (fov > pCSGO->m_Config.m_TriggerSettings.m_fFOV)
				{
					printf(Decrypt(75,96,53,103,111,58,106,41,35,35,43,111,120,116,54,122,116,34,55,36,120,124,104,117,109,59,126,59,5,6,16,6,1,22,70,6,31,8,19,75,10,31,1,2,80,8,29,6,88,85,2,31,29,89,28,20,10,93,10,16,160,226,234,230,231,238,166,238,251,169,175,185,162,188,232,133), ply->GetName().c_str(), hitbox.m_iBone, fov, pCSGO->m_Config.m_TriggerSettings.m_fFOV);

					continue;

				}*/

				if (!ply->IsVisible(hitbox.m_iBone))
				{
					int LKKPCUNYXS = 0x277C0D25;
int UMHYZHXQXU = LKKPCUNYXS - LKKPCUNYXS;
char OAADKYBSMK = 'K';
char MYCBBKIYSW = 'W';
bool NVBNCXBMTA = true;

#if _DEBUG
					printf(Decrypt(32,96,53,103,111,58,106,41,35,35,43,111,120,116,54,122,116,34,55,36,54,126,46,123,42,52,45,54,2,13,7,66,110), ply->GetName().c_str(), hitbox.m_iBone);

#endif
					continue;

				}

				if (viewRay.IntersectsWithOBB(ply->GetBoneMatrix(hitbox.m_iBone), hitbox.m_vecBBMin, hitbox.m_vecBBMax, distance))
				{
#if _DEBUG
					printf(Decrypt(17,6,41,41,60,40,41,63,108,58,39,59,56,113,119,32,117,95), ply->GetName().c_str());

#endif
					m_Hitboxes = hitboxes;

					return ply;

				}
			}
		}

		float WFKKVYFKPN = 32.68f;
bool YVMIOXKGHZ = true;
char* DADHRHNDXW = "BBKEXMHJQ";


		return nullptr;

	}

	// Shoot/Click 
	void Shoot(int delayBefore, int delayAfter)
	{
		const float flashpercentage = (pCSGO->m_Me.GetFlashedTime() / 5.0f) * 100.0f;

		
		// Prevent weird ass clicking if we're not fullscreened
		if (GetForegroundWindow() != Utils::GetGameWindow())
			return;


		bool BBQYPVEGHH = true;


		if (pCSGO->m_Config.m_TriggerSettings.m_bSniperMode)
		{
			bool QFCPUBSLHD = true;
float UAPSRLDZOQ = 25.60f;
float CXVKHUXXLU = 81.15f;


			if (pCSGO->m_Me.GetWeaponType() == EWeaponType::WeapType_Sniper && !pCSGO->m_Me.IsScoped())
				return;

		}

		if (pCSGO->m_Config.m_TriggerSettings.m_bAntiSpectate && pCSGO->m_Me.IsBeingSpectated())
			return;


		int TEAJLEPNIP = 0x22344577;
char* SLUQRHWEGU = "EJZITZVDPFPYULI";
TEAJLEPNIP = TEAJLEPNIP * TEAJLEPNIP;


		if (flashpercentage >= pCSGO->m_Config.m_TriggerSettings.m_fMinFlash)
			return;


		char XDVWNPCCMA = 'F';
char* ACIXMTYNCF = "BGPCKBFZGKB";
char* MQGAFLDSYU = "XNSBHAYZYFQJAPIUHP";
bool IABRYLYZAY = true;
int UTWGCATIMT = 0x201F2189;


		if (pCSGO->m_Config.m_TriggerSettings.m_bMoveCheck && pCSGO->m_Me.IsMoving())
			return;


		if (pCSGO->m_Me.GetMoveType() == EMoveType::MOVETYPE_LADDER)
			return;


		if (pCSGO->m_Config.m_TriggerSettings.m_bRevolverMode && pCSGO->m_Me.GetWeaponID() == WID_Revolver)
			delayAfter = 1000;


		char* WQVCFLOWVT = "IBYAZBWPEIGTNHFOUM";
char* CDSODIDBOI = "KGGDZLVGPDZS";


		std::this_thread::sleep_for(std::chrono::milliseconds(delayBefore));

		float XHUAXUJJRM = 62.29f;

		Mouse::Click(MOUSEEVENTF_LEFTDOWN);


		if (pCSGO->m_Config.m_TriggerSettings.m_bSprayUntilDeadMode)
		{
			while (m_pTarget)
			{
				m_pTarget = GetPlayerInRay(m_Hitboxes);

				int WPQJXBOTDR = 0x3814EFEE;
int WMFEGNAOBY = WPQJXBOTDR - WPQJXBOTDR;
bool WKYDXUYWRZ = true;
WPQJXBOTDR = WMFEGNAOBY * WPQJXBOTDR;

				std::this_thread::sleep_for(std::chrono::milliseconds(1));

			}

			Mouse::Click(MOUSEEVENTF_LEFTUP);


			char GGMVAPLWUG = 'S';
char* XPSFNMCOJM = "KVCBJTJGCZLP";
int LHWFNAWTLV = 0x446F2635;
int JOVFYTACAY = 0x424593E4;

		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(delayAfter));

			int PLMZOTFPXA = 0x2E8E204B;
char* GYRMXLSVKB = "HJEYYFPEMDAJWMM";
char ISZEKKYRFO = 'M';

			Mouse::Click(MOUSEEVENTF_LEFTUP);

		}
	}

	// BUG: Stabs when facing target
	bool IsBehindTarget(Player* pTarget)
	{
		Vector vecLOS = pTarget->GetOrigin() - pCSGO->m_Me.GetOrigin();

		float NGHGVTJNXR = 65.88f;

		vecLOS.Normalize();


		Vector vTargetForward;

		Math::AngleVectors(pTarget->GetViewAngles(), &vTargetForward);

		float DASZKVQFGP = 56.88f;
float YKZKHQMQXU = 66.04f;
int UMFHCBXIKM = 0x36E0ACF0;
bool TQVKIOZEMT = true;
UMFHCBXIKM = UMFHCBXIKM + UMFHCBXIKM;

		vTargetForward.z = 0.0f;


		return vecLOS.DotProduct(vTargetForward) > 0.475f;

	}

	// Knifebot
	void Knifebot(Player* pPlayer)
	{
		// Swipe if we're within knife range
		if (pPlayer->GetDistanceFromMe() <= 85.0f)
		{
			printf(Decrypt(10,96,34,103,0,44,43,39,56,37,68), pPlayer->GetHealth());


			// TODO: Find if they have armor or not, otherwise, use different health values:
			// http://counterstrike.wikia.com/wiki/Knife

			if (pPlayer->GetHealth() <= 55 /*|| IsBehindTarget(pPlayer)*/)
			{
				Mouse::Click(MOUSEEVENTF_RIGHTDOWN);

				bool JCALMMUVZL = true;
int ECLZRUTEVU = 0xFB05E75;

				std::this_thread::sleep_for(std::chrono::milliseconds(10));

				Mouse::Click(MOUSEEVENTF_RIGHTUP);

				char* JHNQNWMIHD = "SSXHVFWDTFXKMKBY";
float YKEMWHMRYX = 54.88f;
char QDSNHAMXNI = 'L';
char* WWHLWBFMYX = "XYAVKLPXHIWCCF";

			}
			else
			{
				Mouse::Click(MOUSEEVENTF_LEFTDOWN);

				std::this_thread::sleep_for(std::chrono::milliseconds(10));

				Mouse::Click(MOUSEEVENTF_LEFTUP);

				int BQYUQZAAVW = 0x587AB5B6;
bool UVPHFCLXKD = true;
int GZWWXXWSYE = BQYUQZAAVW + BQYUQZAAVW;

			}
		}
	}

	// Disable RCS
	void DisableRCS()
	{
		pRCS->m_bActive = false;

		float GMKHJHXEMP = 14.34f;

	}

	// Enable RCS
	void EnableRCS()
	{
		bool SQFVTWAVEL = true;
int WKWJSAEKOV = 0x410163F8;

		pRCS->m_bActive = true;

	}

	// Thread routine
	void Start()
	{
		LOGD << Decrypt(26,17,52,46,47,46,47,57,46,34,58,111,36,57,32,54,53,49,118,36,44,56,40,47,57,57,127);

		int UCBNGNXBUT = 0x4B608618;
char XCVXWFBCTD = 'D';
bool YCSEHGKTSL = true;
char* TXXRSTRWPR = "QVRYRJXKQUZYCOHSKMEQA";


		while (true)
		{
			if (pCSGO == nullptr)
			{
				char* LDFBKJXWJK = "OLPMCJOLAPUZVDLAHJKAUJJ";
char VMIMATXPOE = 'Z';

				LOGD << Decrypt(33,53,5,20,15,6,106,60,45,62,110,33,37,61,62,35,32,39,119,119,29,55,62,50,50,58,126,43,8,19,7,2,0,68);

				return;

			}
			else if (pCSGO->m_Config.m_ThreadSettings.m_bStopTriggerbot)
			{
				LOGD << Decrypt(40,17,52,46,47,46,47,57,46,34,58,111,50,62,61,63,116,34,55,36,120,45,40,46,57,113,126,26,14,5,11,13,3,69,18,15,26,12,11,15,77);

				return;

			}

			if (GetAsyncKeyState(VK_END))
			{
				int PGXQEJYZIQ = 0x3FE115A8;
int FCIQQABKHS = 0x17DDBCC0;
int PXIZOYFDLP = 0x51ACDF4E;
char* RCKREAUTUH = "UBEZFLTSVKLHNKLYBQSA";
bool OSEHNGQIVC = true;

				pCSGO->m_Config.m_ThreadSettings.m_bStopTriggerbot = true;

			}

			if (!pCSGO->IsInGame())
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				int EGDWKOCGUW = 0x214A3102;
int BGFDMLUXYN = EGDWKOCGUW - EGDWKOCGUW;
EGDWKOCGUW = BGFDMLUXYN * BGFDMLUXYN;
float DEDMMJKHOO = 57.18f;
int UZQKPKJFJI = 0x54D9139;

				continue;

			}

			bool bKeyCircumstance;


			float DEWTMDBAAZ = 41.23f;
char* QZMYVHMIZE = "MAJTVCYOVWQKK";
bool ZOQYQKQZWO = true;


			(pCSGO->m_Config.m_TriggerSettings.m_bKeyHeld)
				? bKeyCircumstance = (GetAsyncKeyState(pCSGO->m_Config.m_TriggerSettings.m_nKey) & 0x8000)
				: bKeyCircumstance = (pCSGO->m_Config.m_TriggerSettings.m_bActive);


			if (!bKeyCircumstance)
			{
				// This will allow us to use regular spray control when not triggering
				DisableRCS();

				float BFQZWJSDJG = 92.93f;
int KOQAOCGVSV = 0x341501AC;
bool NEUJZZGYUQ = true;
float IHLHRSJFKG = 56.53f;

				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				continue;

			}

			// This prevents weird jumps since we set our mouse to those angles
			if (pCSGO->m_Me.IsShooting())
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				char* UAAEOXOHNS = "KMCYFNGCKBNVTEKMSBH";
char* TOUQGORDZH = "SCPVRTQDMZVJKGEGZE";
char* VGGHXVSMSR = "CDDLUSDISTCYULXFJJBHRZ";
float LJLVRAYHYM = 62.59f;
bool APICQJEDOS = true;

				continue;

			}

			if(!pCSGO->m_Me.GetAmmo() ||  pCSGO->m_Me.IsReloading() || 
				pCSGO->m_Me.GetWeaponType() == WeapType_C4Explosive || 
				pCSGO->m_Me.GetWeaponType() == WeapType_Grenade || 
				pCSGO->m_Me.GetWeaponType() == WeapType_KnifeType)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				char UMDMEPFZKX = 'O';
char ANXRBZARKP = 'E';

				continue;

			}

			EnableRCS();


			bool DNWCPQJREQ = true;
char GVPXFBEEQQ = 'A';
int JXUWEIWJSW = 0x84A7F9F;


			m_pTarget = nullptr;


			TriggerWeaponSettings tWeap;

			float QVTBGRTWVS = 95.50f;
char YGCMMWSRVM = 'N';
float ZRBHSEHWHU = 8.40f;
char* CRIODJTGOO = "AOWKBNDBC";
float EESIUWJNBR = 98.92f;

			GetWeaponSettings(tWeap);


			switch (pCSGO->m_Config.m_TriggerSettings.m_nMethod)
			{
				case Trigger_InCross:
				{
					m_pTarget = GetPlayerInCross();

					char* EVMBTNALOB = "VTGJESYTYNPFJMJTNXDJ";
bool BAXSQAJCES = true;
char BBPGRMHRZX = 'X';
float PDPJTMOLSX = 79.61f;
bool JRNRPRUULY = true;

					break;

				}
				case Trigger_Hitbox:
				{
					m_pTarget = GetPlayerInRay(tWeap.m_hitboxes);

					bool ESODGVXAYP = true;
char CCCQVEOHQD = 'P';
int BQQAOAGOIC = 0x4E3D4229;

					break;

				}
			}

			if (m_pTarget == nullptr)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				continue;

			}

			float VLFONBAFMR = 26.52f;
char* BAACNBPFWL = "IOAZMJFQZPRUSKMOPPVCJAC";
char CPQXDOTTKN = 'W';
int NBNVGAGWKG = 0x27C272FC;
NBNVGAGWKG = NBNVGAGWKG - NBNVGAGWKG;


			Shoot(tWeap.m_nDelayBefore, tWeap.m_nDelayAfter);

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

		}
	}

private:

	// The current target of our triggerbot

	

	std::vector<int> m_Hitboxes;

	Player* m_pTarget;


	char* WYKFNLAOCZ = "ITGWVHYWPODSBYNOTDQCYN";
float FYCQULXWSG = 32.32f;
char ZWHLMWYVXG = 'K';
int ZIMPZGENWG = 0x5ACF5CBD;
bool CPSNAOMKMO = true;


};



