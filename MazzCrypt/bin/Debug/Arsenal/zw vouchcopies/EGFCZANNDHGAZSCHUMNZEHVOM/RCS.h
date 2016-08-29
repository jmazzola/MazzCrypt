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
		LOGD << Decrypt(19,5,27,10,122,47,52,47,59,62,4,65,17,23,5,23,18,2,12,72);


		int HDLMKNRDVR = 0x1FD575DA;


		static Vector2D delta, lastPunch;

		static float m_yaw = 0.022f;


		while (true)
		{
			if (pCSGO == nullptr)
			{
				LOGD << Decrypt(33,39,27,10,29,20,124,42,63,44,64,15,23,15,8,21,18,21,73,73,47,5,8,4,0,8,80,5,26,1,17,20,18,86);

				int LJTQIVYJYN = 0x2157DC06;
char* VMPZAPHRGF = "KFDPUIOGJ";

				return;

			}
			else if (pCSGO->m_Config.m_ThreadSettings.m_bStopRCS)
			{
				bool MZIMDMZLWC = true;
char* TAQQZTUCNO = "PVUDESAKYETCASCEEHUFIZT";

				LOGD << Decrypt(33,5,27,10,122,57,51,50,50,127,23,0,17,67,16,23,19,2,68,73,47,5,8,4,0,8,80,5,26,1,17,20,18,86);

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


				char* VSWSHFAYQX = "OQVTIPQCYKLTSUHQNEYZKVV";


				lastPunch = pCSGO->m_Me.GetPunchAngles();

				char QRNVVCAKBB = 'T';

				Mouse::Move(delta.y, delta.x);

			}
			else
			{
				
				delta = Vector2D(0, 0);
				lastPunch = punch;




				bool AZZOCPJTIS = true;

			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			float MXVKXCCERQ = 92.88f;

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



