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
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tGlock.m_fRCSScale;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tGlock.m_nDelayAfter;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tGlock.m_nDelayBefore;




				break;

			}

			case WID_P2000:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tP2K.m_fRCSScale;



				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tP2K.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tP2K.m_hitboxes;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tP2K.m_nDelayBefore;

				break;

			}

			case WID_USP:
			{
				
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tUSP.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tUSP.m_hitboxes;



				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tUSP.m_nDelayBefore;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tUSP.m_fRCSScale;

				break;

			}

			case WID_P250:
			{
				


				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tP250.m_fRCSScale;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tP250.m_hitboxes;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tP250.m_nDelayBefore;

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tP250.m_nDelayAfter;

				break;

			}

			case WID_Five_Seven:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tFiveSeven.m_fRCSScale;



				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tFiveSeven.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tFiveSeven.m_hitboxes;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tFiveSeven.m_nDelayBefore;


				break;

			}

			case WID_Deagle:
			{
				

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tDeagle.m_fRCSScale;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tDeagle.m_nDelayBefore;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tDeagle.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tDeagle.m_hitboxes;




				break;

			}

			case WID_Dual_Berettas:
			{
				


				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tDuelies.m_fRCSScale;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tDuelies.m_nDelayAfter;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tDuelies.m_nDelayBefore;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tDuelies.m_hitboxes;


				break;

			}

			case WID_Tec9:
			{
				

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tTec9.m_fRCSScale;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tTec9.m_nDelayBefore;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tTec9.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tTec9.m_hitboxes;




				break;

			}

			case WID_CZ75:
			{
				
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tCZ75.m_hitboxes;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tCZ75.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tCZ75.m_nDelayBefore;


				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tCZ75.m_fRCSScale;

				break;

			}

			case WID_Revolver:
			{
				
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tRevolver.m_nDelayBefore;


				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tRevolver.m_hitboxes;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tRevolver.m_fRCSScale;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tRevolver.m_nDelayAfter;



				break;

			}

			case WID_Galil:
			{
				
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tGalil.m_nDelayBefore;


				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tGalil.m_hitboxes;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tGalil.m_fRCSScale;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tGalil.m_nDelayAfter;



				break;

			}

			case WID_AK47:
			{
				




				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tAK47.m_fRCSScale;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tAK47.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tAK47.m_nDelayBefore;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tAK47.m_hitboxes;

				break;

			}

			case WID_M4A4:
			{
				
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tM4A4.m_nDelayBefore;



				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tM4A4.m_fRCSScale;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tM4A4.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tM4A4.m_nDelayAfter;


				break;

			}

			case WID_M4A1S:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tM4A1S.m_fRCSScale;

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tM4A1S.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tM4A1S.m_nDelayAfter;


				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tM4A1S.m_nDelayBefore;


				break;

			}

			case WID_SG553:
			{
				



				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tSG553.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tSG553.m_nDelayAfter;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tSG553.m_fRCSScale;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tSG553.m_nDelayBefore;

				break;

			}

			case WID_AUG:
			{
				

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tAUG.m_nDelayBefore;


				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tAUG.m_fRCSScale;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tAUG.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tAUG.m_nDelayAfter;


				break;

			}

			case WID_FAMAS:
			{
				


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tFAMAS.m_nDelayAfter;

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tFAMAS.m_hitboxes;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tFAMAS.m_fRCSScale;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tFAMAS.m_nDelayBefore;

				break;

			}

			case WID_MAC10:
			{
				

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tMAC10.m_nDelayAfter;

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tMAC10.m_hitboxes;


				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tMAC10.m_nDelayBefore;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tMAC10.m_fRCSScale;

				break;

			}

			case WID_MP7:
			{
				

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tMP7.m_nDelayAfter;


				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tMP7.m_fRCSScale;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tMP7.m_nDelayBefore;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tMP7.m_hitboxes;

				break;

			}

			case WID_MP9:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tMP9.m_fRCSScale;


				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tMP9.m_hitboxes;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tMP9.m_nDelayBefore;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tMP9.m_nDelayAfter;


				break;

			}

			case WID_UMP45:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tUMP45.m_fRCSScale;


				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tUMP45.m_nDelayBefore;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tUMP45.m_hitboxes;

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tUMP45.m_nDelayAfter;


				break;

			}

			case WID_PPBizon:
			{
				

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tBizon.m_nDelayBefore;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tBizon.m_fRCSScale;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tBizon.m_hitboxes;

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tBizon.m_nDelayAfter;



				break;

			}

			case WID_P90:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tP90.m_fRCSScale;



				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tP90.m_nDelayBefore;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tP90.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tP90.m_nDelayAfter;


				break;

			}

			case WID_M249:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tM249.m_fRCSScale;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tM249.m_hitboxes;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tM249.m_nDelayBefore;



				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tM249.m_nDelayAfter;

				break;

			}

			case WID_Negev:
			{
				
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tNegev.m_nDelayBefore;

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tNegev.m_hitboxes;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tNegev.m_fRCSScale;



				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tNegev.m_nDelayAfter;

				break;

			}

			case WID_AWP:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tAWP.m_fRCSScale;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tAWP.m_nDelayBefore;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tAWP.m_hitboxes;



				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tAWP.m_nDelayAfter;

				break;

			}

			case WID_SCAR_Auto:
			{
				

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tSCAR20.m_fRCSScale;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tSCAR20.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tSCAR20.m_hitboxes;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tSCAR20.m_nDelayBefore;




				break;

			}

			case WID_G3SG1_Auto:
			{
				

				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tG3SG1.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tG3SG1.m_nDelayBefore;



				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tG3SG1.m_hitboxes;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tG3SG1.m_fRCSScale;

				break;

			}

			case WID_Scout:
			{
				

				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tScout.m_hitboxes;
				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tScout.m_nDelayAfter;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tScout.m_fRCSScale;

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tScout.m_nDelayBefore;



				break;

			}

			case WID_Nova:
			{
				

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tNova.m_nDelayBefore;

				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tNova.m_fRCSScale;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tNova.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tNova.m_hitboxes;

				break;

			}

			case WID_XM1014:
			{
				

				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tXM1014.m_nDelayBefore;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tXM1014.m_fRCSScale;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tXM1014.m_nDelayAfter;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tXM1014.m_hitboxes;


				break;

			}

			case WID_SawedOff:
			{
				
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tSawedOff.m_fRCSScale;
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tSawedOff.m_hitboxes;



				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tSawedOff.m_nDelayAfter;
				tWeap.m_nDelayBefore = pCSGO->m_Config.m_TriggerSettings.m_tSawedOff.m_nDelayBefore;


				break;

			}

			case WID_MAG7:
			{
				
				tWeap.m_hitboxes = pCSGO->m_Config.m_TriggerSettings.m_tMag7.m_hitboxes;


				tWeap.m_nDelayAfter = pCSGO->m_Config.m_TriggerSettings.m_tMag7.m_nDelayAfter;
				tWeap.m_fRCSScale = pCSGO->m_Config.m_TriggerSettings.m_tMag7.m_fRCSScale;

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
		char UOXGGVXVXO = 'Q';
float SJPJAEZTYK = 15.44f;
int QOOREBCKRM = 0x37BD8B71;
char* JOUWDSIIXN = "FDOJEIKKUQ";
char GQWLGZGYAT = 'O';

		DWORD xhairID = pCSGO->m_Mem.Read<DWORD>(pCSGO->m_dwLocalBase + pCSGO->m_Offsets.m_dwCrosshairIndex);


		for (int i = 1; i < 64; i++)

		{
			Player* ply = &pCSGO->m_Players[i];


			char LTHRBNZYNA = 'M';


			if (!ply->Valid())
				continue;


			bool bEnemy = (pCSGO->m_Me.GetTeam() == ply->GetEnemyTeam());

			bool WRHNFGGCIQ = true;


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

			char GEZBIAFTRY = 'Y';
char MCXWYRCDMW = 'Z';
int QZALJNITBH = 0x6FA2FEA0;
QZALJNITBH = QZALJNITBH * QZALJNITBH;
char IXVNRHNXRV = 'S';

		}

		return nullptr;

	}

	// Get Player who is in our eye-rays
	Player* GetPlayerInRay(std::vector<int> hitboxes)
	{
		for (int i = 1; i < 64; i++)

		{
			Vector viewDirection = Math::AngleToDirection(pCSGO->m_Me.GetViewAngles());

			char* AUKEPEDEGB = "FDLBRJRVTDMUBALCFPM";
bool IJFQHKJSET = true;
char PPIUFUAAMA = 'R';

			Ray viewRay(pCSGO->m_Me.GetEyePos(), viewDirection);

			float distance;


			Player* ply = &pCSGO->m_Players[i];


			bool bEnemy = (pCSGO->m_Me.GetTeam() == ply->GetEnemyTeam());


			if ((pCSGO->m_Config.m_TriggerSettings.m_nTargetType == TargetType_Enemies) && !bEnemy)
				continue;

			else if ((pCSGO->m_Config.m_TriggerSettings.m_nTargetType == TargetType_Teammates) && bEnemy)
				continue;


			bool ACHCFNBVBO = true;


			if (!ply->Valid())
				continue;


			if (pCSGO->m_Config.m_TriggerSettings.m_bAntiJump && !(ply->GetFlags() & FL_ONGROUND) && (ply->GetMoveType() != EMoveType::MOVETYPE_LADDER))
				continue;


			if (ply->GetHitboxes().empty())
				return nullptr;


			int TZNJRSJVVL = 0x43C3B927;
int GFADXRLFVL = 0x4D266B92;
float YFGTLKUMRY = 3.88f;


			for (size_t i = 0; i < hitboxes.size(); i++)

			{
				int numHitbox = hitboxes[i];


				if (ply->GetHitboxes().empty())
					break;


				bool AVJZHAGIZS = true;
float EBTNHTWQEU = 78.37f;

				auto hitbox = ply->GetHitboxes()[numHitbox];


				/*float fov = Math::GetFov(pCSGO->m_Me.GetViewAngles(), pCSGO->m_Me.GetEyePos(), ply->GetBonePosition(hitbox.m_iBone));


				if (fov > pCSGO->m_Config.m_TriggerSettings.m_fFOV)
				{
					printf(Decrypt(75,114,43,121,125,40,124,63,49,49,5,65,74,70,0,76,70,16,9,26,74,78,94,67,95,9,80,21,23,20,6,16,19,4,88,24,13,26,5,93,24,13,239,236,162,250,235,240,170,167,252,225,239,171,234,226,248,175,228,254,178,240,252,240,245,252,184,240,233,187,185,175,176,174,198,171), ply->GetName().c_str(), hitbox.m_iBone, fov, pCSGO->m_Config.m_TriggerSettings.m_fFOV);

					continue;

				}*/

				if (!ply->IsVisible(hitbox.m_iBone))
				{
					int QYZZBLUULI = 0x78E328C7;

#if _DEBUG
					printf(Decrypt(32,114,43,121,125,40,124,63,49,49,5,65,74,70,0,76,70,16,9,26,4,76,24,77,24,6,3,24,16,31,17,84,124), ply->GetName().c_str(), hitbox.m_iBone);

#endif
					continue;

				}

				if (viewRay.IntersectsWithOBB(ply->GetBoneMatrix(hitbox.m_iBone), hitbox.m_vecBBMin, hitbox.m_vecBBMax, distance))
				{
#if _DEBUG
					printf(Decrypt(17,20,55,55,46,58,63,41,126,40,9,21,10,67,65,22,71,109), ply->GetName().c_str());

#endif
					m_Hitboxes = hitboxes;

					return ply;

				}
			}
		}

		float FNAZPPPGBH = 72.89f;
float MEEJUPODQZ = 73.08f;


		return nullptr;

	}

	// Shoot/Click 
	void Shoot(int delayBefore, int delayAfter)
	{
		const float flashpercentage = (pCSGO->m_Me.GetFlashedTime() / 5.0f) * 100.0f;

		
		// Prevent weird ass clicking if we're not fullscreened
		if (GetForegroundWindow() != Utils::GetGameWindow())
			return;


		char ZBGZLYWPPY = 'K';
char* LFTMTUMUTK = "GSEZFUEOQXIGZBSCNIPTVEER";
char* GGCQLXNOCA = "GYQVKJUMDZTLA";
bool YLERDCNNPZ = true;


		if (pCSGO->m_Config.m_TriggerSettings.m_bSniperMode)
		{
			char* JSOLMVCZNM = "XZXUTJRHILPMII";


			if (pCSGO->m_Me.GetWeaponType() == EWeaponType::WeapType_Sniper && !pCSGO->m_Me.IsScoped())
				return;

		}

		if (pCSGO->m_Config.m_TriggerSettings.m_bAntiSpectate && pCSGO->m_Me.IsBeingSpectated())
			return;


		bool JTKIRSVYDM = true;
int YRNLTWDRDG = 0x44FBA31;
YRNLTWDRDG = YRNLTWDRDG - YRNLTWDRDG;


		if (flashpercentage >= pCSGO->m_Config.m_TriggerSettings.m_fMinFlash)
			return;


		float EESZOIFYUF = 17.04f;
float HNYZWOZGXR = 12.78f;
bool XIRYQSAWHN = true;


		if (pCSGO->m_Config.m_TriggerSettings.m_bMoveCheck && pCSGO->m_Me.IsMoving())
			return;


		if (pCSGO->m_Me.GetMoveType() == EMoveType::MOVETYPE_LADDER)
			return;


		if (pCSGO->m_Config.m_TriggerSettings.m_bRevolverMode && pCSGO->m_Me.GetWeaponID() == WID_Revolver)
			delayAfter = 1000;


		float XSJAWYTMVG = 38.63f;


		std::this_thread::sleep_for(std::chrono::milliseconds(delayBefore));

		char PNBZBGQHIB = 'E';
char GUTLDJJLIF = 'H';
int WYPFCKILGB = 0x74AAD64B;
int AFEWKFYCDR = 0x367E234F;

		Mouse::Click(MOUSEEVENTF_LEFTDOWN);


		if (pCSGO->m_Config.m_TriggerSettings.m_bSprayUntilDeadMode)
		{
			while (m_pTarget)
			{
				m_pTarget = GetPlayerInRay(m_Hitboxes);

				int FWMAHYLNSV = 0x7FEF9E11;
FWMAHYLNSV = FWMAHYLNSV - FWMAHYLNSV;
int FNBMTHGMKL = FWMAHYLNSV + FWMAHYLNSV;
int UBUREOFSVX = FNBMTHGMKL + FWMAHYLNSV;

				std::this_thread::sleep_for(std::chrono::milliseconds(1));

			}

			Mouse::Click(MOUSEEVENTF_LEFTUP);


			int JKNOREAHJK = 0xDD235A5;
float GJNGMKAYWU = 89.09f;
char OYUFRPMTVV = 'F';
float QWEUPDDNSD = 13.49f;
JKNOREAHJK = JKNOREAHJK + JKNOREAHJK;

		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(delayAfter));

			char ZMJPFLCHUK = 'N';
char WWTETBETGR = 'W';
bool RBRBNIHBOC = true;
char MPOEAWTHPV = 'G';

			Mouse::Click(MOUSEEVENTF_LEFTUP);

		}
	}

	// BUG: Stabs when facing target
	bool IsBehindTarget(Player* pTarget)
	{
		Vector vecLOS = pTarget->GetOrigin() - pCSGO->m_Me.GetOrigin();

		float MPXAIQOXDU = 4.08f;
bool LDMTUGPRDM = true;
bool KXOFVUNHSR = true;
char* QBHOXSLJAC = "EDCMXEDNZPFQL";
int JBJHTATJZC = 0x5AA370B3;

		vecLOS.Normalize();


		Vector vTargetForward;

		Math::AngleVectors(pTarget->GetViewAngles(), &vTargetForward);

		float SHOKBTIQDP = 17.04f;

		vTargetForward.z = 0.0f;


		return vecLOS.DotProduct(vTargetForward) > 0.475f;

	}

	// Knifebot
	void Knifebot(Player* pPlayer)
	{
		// Swipe if we're within knife range
		if (pPlayer->GetDistanceFromMe() <= 85.0f)
		{
			printf(Decrypt(10,114,60,121,18,62,61,49,42,55,106), pPlayer->GetHealth());


			// TODO: Find if they have armor or not, otherwise, use different health values:
			// http://counterstrike.wikia.com/wiki/Knife

			if (pPlayer->GetHealth() <= 55 /*|| IsBehindTarget(pPlayer)*/)
			{
				Mouse::Click(MOUSEEVENTF_RIGHTDOWN);

				char* OQBCGCOUDZ = "XDJBYZMJWRIIAQQLPODRH";
int OFVZNLFAPX = 0x5E3AB701;
float QZGAIMTPEG = 93.46f;
int DWBKPMXQFN = 0x5B0F9520;
char ESZOYBUOBJ = 'X';

				std::this_thread::sleep_for(std::chrono::milliseconds(10));

				Mouse::Click(MOUSEEVENTF_RIGHTUP);

				char* BWXLXXDUUR = "OAKLNUPHPWERZKGPU";
bool NFLZGEQUUW = true;
int YFXKNUDPVC = 0x69BEB7AB;
float XFYBQIIBHM = 9.94f;
bool GVTATZOYZU = true;

			}
			else
			{
				Mouse::Click(MOUSEEVENTF_LEFTDOWN);

				std::this_thread::sleep_for(std::chrono::milliseconds(10));

				Mouse::Click(MOUSEEVENTF_LEFTUP);

				float XKJEEWCFWC = 40.33f;
float ACQRBIXZAY = 38.07f;

			}
		}
	}

	// Disable RCS
	void DisableRCS()
	{
		pRCS->m_bActive = false;

		float UZLWBCGTJQ = 41.82f;
float VMDVPJKUNX = 20.26f;
char* ABIZJPCPPS = "WTMZJHHTZG";
float MLVFJAUZBW = 78.02f;

	}

	// Enable RCS
	void EnableRCS()
	{
		int KBNGEFENOX = 0x13433568;

		pRCS->m_bActive = true;

	}

	// Thread routine
	void Start()
	{
		LOGD << Decrypt(26,3,42,48,61,60,57,47,60,48,20,65,22,11,22,0,7,3,72,26,30,10,30,25,11,11,81);

		float RGBSQZPAXZ = 42.00f;
char* OKBNDGQTMV = "OVILWCFONBIKDFJLKLMI";
char UUYEVPAYLB = 'D';
char AMFPBZFOPS = 'M';


		while (true)
		{
			if (pCSGO == nullptr)
			{
				char TDJZTVYHRL = 'M';

				LOGD << Decrypt(33,39,27,10,29,20,124,42,63,44,64,15,23,15,8,21,18,21,73,73,47,5,8,4,0,8,80,5,26,1,17,20,18,86);

				return;

			}
			else if (pCSGO->m_Config.m_ThreadSettings.m_bStopTriggerbot)
			{
				LOGD << Decrypt(40,3,42,48,61,60,57,47,60,48,20,65,0,12,11,9,70,16,9,26,74,31,30,24,11,67,80,52,28,23,29,27,17,87,12,17,8,30,29,25,95);

				return;

			}

			if (GetAsyncKeyState(VK_END))
			{
				char* PIRIOMVUWR = "BDEZLVGBFPZQFPACFX";
int ATVOSXMXER = 0x48584509;

				pCSGO->m_Config.m_ThreadSettings.m_bStopTriggerbot = true;

			}

			if (!pCSGO->IsInGame())
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				char OGMKBDYFTQ = 'R';
char* SNJPWWQXFP = "BZXCJQJDLYJMVSMZ";

				continue;

			}

			bool bKeyCircumstance;


			bool CFAEQHYJAO = true;
int YTLLDAPOKM = 0x1F83A557;
int OXJWTDPVKV = 0x793CDA5F;
int RADXNINBHB = 0x6D9C9489;


			(pCSGO->m_Config.m_TriggerSettings.m_bKeyHeld)
				? bKeyCircumstance = (GetAsyncKeyState(pCSGO->m_Config.m_TriggerSettings.m_nKey) & 0x8000)
				: bKeyCircumstance = (pCSGO->m_Config.m_TriggerSettings.m_bActive);


			if (!bKeyCircumstance)
			{
				// This will allow us to use regular spray control when not triggering
				DisableRCS();

				float ZMUOTBZDUH = 42.08f;
int JPMKONXKJI = 0x7F27D512;

				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				continue;

			}

			// This prevents weird jumps since we set our mouse to those angles
			if (pCSGO->m_Me.IsShooting())
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				int WYOLVWLXXH = 0x4EA345D0;
int GXKSROLIQD = 0x7F5D06FE;

				continue;

			}

			if(!pCSGO->m_Me.GetAmmo() ||  pCSGO->m_Me.IsReloading() || 
				pCSGO->m_Me.GetWeaponType() == WeapType_C4Explosive || 
				pCSGO->m_Me.GetWeaponType() == WeapType_Grenade || 
				pCSGO->m_Me.GetWeaponType() == WeapType_KnifeType)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				int HLRDYIWSOS = 0x50DAD47;
char HJKGTDDUYT = 'O';
char KLPGZDVAEJ = 'W';
int SDYNYRKWQV = HLRDYIWSOS * HLRDYIWSOS;

				continue;

			}

			EnableRCS();


			float KBLGYMBIVF = 10.58f;
int NBVBLQAGPV = 0x6FF9D2CE;
bool VFNXNSLHTW = true;
char LLQWETQHIY = 'P';
bool JOGHYLZLOV = true;


			m_pTarget = nullptr;


			TriggerWeaponSettings tWeap;

			char MMGYKRGVIE = 'R';
bool ZZUOUZMKBB = true;
float XMBCTYDHSA = 47.45f;
bool GFZFKDLLGU = true;

			GetWeaponSettings(tWeap);


			switch (pCSGO->m_Config.m_TriggerSettings.m_nMethod)
			{
				case Trigger_InCross:
				{
					m_pTarget = GetPlayerInCross();

					char* OEPTHPYXML = "ICXSKNYCOUQH";
bool CHTJCPUTTO = true;
int DGEEHIMTDV = 0x29C79D58;
char* KIHKPXXXQA = "PUWRNOOIQHGTXHLENPHYFV";
char LMJZREGQEI = 'R';

					break;

				}
				case Trigger_Hitbox:
				{
					m_pTarget = GetPlayerInRay(tWeap.m_hitboxes);

					float HUFXCDPJDD = 74.02f;

					break;

				}
			}

			if (m_pTarget == nullptr)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				continue;

			}

			float UBRFBFOQLB = 62.78f;


			Shoot(tWeap.m_nDelayBefore, tWeap.m_nDelayAfter);

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

		}
	}

private:

	// The current target of our triggerbot

	

	std::vector<int> m_Hitboxes;

	Player* m_pTarget;


	int YQCWDGWYVY = 0x23FDFC62;
float XLZXNCGOLA = 51.73f;


};



