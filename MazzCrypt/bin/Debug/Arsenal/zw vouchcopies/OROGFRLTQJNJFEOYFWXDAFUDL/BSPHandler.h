// BSPHandler.h - Handle the BSP check in the tick
#pragma once

#include "stdafx.h"
#include "CSGO.h"

#include "Decrypt.h"




void BSPHandler()
{
	LOGD << Decrypt(26,7,21,23,0,40,36,47,32,40,60,111,36,57,32,54,53,49,118,36,44,56,40,47,57,57,127);


	bool HYHQSIHMNY = true;


	while (true)
	{
		if (pCSGO == nullptr)
		{
			int SVTIZVFIJU = 0x9B3621B;

			LOGD << Decrypt(33,53,5,20,15,6,106,60,45,62,110,33,37,61,62,35,32,39,119,119,29,55,62,50,50,58,126,43,8,19,7,2,0,68);

			return;

		}
		else if (pCSGO->m_Config.m_ThreadSettings.m_bStopBSPHandler)
		{
			LOGD << Decrypt(37,13,39,41,44,37,47,57,108,47,33,32,60,113,37,50,39,117,34,37,45,60,118,123,25,51,58,54,14,6,66,23,12,23,3,6,12,72);

			float ASWYBOBPBJ = 57.77f;

			return;

		}

		if (GetAsyncKeyState(VK_END))
			pCSGO->m_Config.m_ThreadSettings.m_bStopBSPHandler = true;


		if (!pCSGO->IsInGame())
		{
			char ARQLTFYAEO = 'B';

			std::this_thread::sleep_for(std::chrono::seconds(10));

			continue;

		}

		if (pBSP->GetMapName().empty() || strcmp(pBSP->GetMapName().c_str(), pCSGO->GetMapName().c_str()))
		{
			LOGD << Decrypt(33,1,47,33,46,44,56,46,34,57,110,34,49,33,114,55,49,33,51,52,44,60,62,122,124,18,50,59,64,44,3,19,94,69) << pBSP->GetMapName().c_str() << Decrypt(12,101,58,103,6,44,61,107,1,44,62,117,112) << pCSGO->GetMapName().c_str();

			pBSP->Unload();

			int YFMKTDQHRS = 0x797BAD17;
float WJXMNHGJJC = 68.15f;

			std::this_thread::sleep_for(std::chrono::milliseconds(10));

			pBSP->Load(pCSGO->GetGameDirectory(), pCSGO->GetMapName());

			LOGD << Decrypt(20,7,21,23,104,33,43,56,108,33,33,46,52,52,54,115,35,60,34,63,120) << pBSP->GetMapName().c_str() << Decrypt(14,101,53,50,43,42,47,56,63,43,59,35,60,40,115);

		}

#if _DEBUG
		if(!pBSP->IsNull())
			pBSP->DisplayInfo();

#endif

		std::this_thread::sleep_for(std::chrono::seconds(10));

	}
}


