// RCS.h - RCS (Recoil Control System) cheat thread
#pragma once

#include "stdafx.h"
#include "CSGO.h"
#include "Vector.h"
#include "Mouse.h"

#include "Decrypt.h"





class RCS
{
public:

	RCS() = default;

	~RCS() = default;


	// Thread routine
	void Start()
	{
		LOGD << Decrypt(19,23,5,20,104,61,34,57,41,44,42,111,35,37,51,33,32,48,50,118);


		bool AKJFESZEHU = true;
float AOMAKHGVNF = 80.79f;


		static Vector2D delta, lastPunch;

		static float m_yaw = 0.022f;


		while (true)
		{
			if (pCSGO == nullptr)
			{
				LOGD << Decrypt(33,53,5,20,15,6,106,60,45,62,110,33,37,61,62,35,32,39,119,119,29,55,62,50,50,58,126,43,8,19,7,2,0,68);

				char* JZZJXHNDVV = "FBHVPXTBRBALGHLEBJRJG";

				return;

			}
			else if (pCSGO->m_Config.m_ThreadSettings.m_bStopRCS)
			{
				int FVCOVMUIAU = 0x3A8070AA;

				LOGD << Decrypt(33,23,5,20,104,43,37,36,32,109,57,46,35,113,38,33,33,48,122,119,29,55,62,50,50,58,126,43,8,19,7,2,0,68);

				return;

			}

			if (GetAsyncKeyState(VK_END))
				pCSGO->m_Config.m_ThreadSettings.m_bStopRCS = true;


			if (!m_bActive || !pCSGO->m_Config.m_TriggerSettings.m_bRecoilControl)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				continue;

			}

			Vector2D punch = pCSGO->m_Me.GetPunchAngles();


			if (pCSGO->m_Me.IsShooting())
			{
				float sens = pCSGO->m_Mem.Read<float>(pCSGO->m_dwClientBase + pCSGO->m_Offsets.m_dwIngameSensitivity);


				
				delta.y = ((pCSGO->m_Me.GetPunchAngles().y - lastPunch.y) * m_fRCSScale) / (m_yaw * sens);

				delta.x = ((pCSGO->m_Me.GetPunchAngles().x - lastPunch.x) * m_fRCSScale) / (m_yaw * sens) * (pCSGO->m_Config.m_TriggerSettings.m_bInvertMouse ? 1.0f : -1.0f);



				char* TDLNDTDPTV = "FEHRLLVJQJV";


				lastPunch = pCSGO->m_Me.GetPunchAngles();

				char OXTSCACTAA = 'F';

				Mouse::Move(delta.y, delta.x);

			}
			else
			{
				
				lastPunch = punch;
				delta = Vector2D(0, 0);




				int UIDSCHFCLD = 0x75F494E1;
char OVJWQUBLEG = 'M';

			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			float AFGBPAMFUB = 61.55f;

		}
	}

	// What is the scale we're using to compensate recoil?
	static float m_fRCSScale;


	// Are we using RCS?
	static bool m_bActive;

};


// extern
extern RCS* pRCS = new RCS();


// Statics
float RCS::m_fRCSScale = 0.0f;

bool RCS::m_bActive = true;



