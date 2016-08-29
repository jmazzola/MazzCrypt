// BSPHandler.h - Handle the BSP check in the tick
#pragma once

#include "stdafx.h"
#include "CSGO.h"

#include "Decrypt.h"




void BSPHandler()
{
	LOGD << Decrypt(26,21,11,9,18,58,50,57,50,58,18,65,22,11,22,0,7,3,72,26,30,10,30,25,11,11,81);


	char BQJMUFXAXI = 'O';


	while (true)
	{
		if (pCSGO == nullptr)
		{
			char QSPJNPGKKM = 'E';

			LOGD << Decrypt(33,39,27,10,29,20,124,42,63,44,64,15,23,15,8,21,18,21,73,73,47,5,8,4,0,8,80,5,26,1,17,20,18,86);

			return;

		}
		else if (pCSGO->m_Config.m_ThreadSettings.m_bStopBSPHandler)
		{
			LOGD << Decrypt(37,31,57,55,62,55,57,47,126,61,15,14,14,67,19,4,21,71,28,27,31,14,64,77,43,1,20,24,28,20,84,1,30,5,29,24,30,90);

			int IUEJJDSWEG = 0x1630833E;
char* AYLMPFKNUZ = "LOQKTPPCHHU";

			return;

		}

		if (GetAsyncKeyState(VK_END))
			pCSGO->m_Config.m_ThreadSettings.m_bStopBSPHandler = true;


		if (!pCSGO->IsInGame())
		{
			char* ZSFHLZMYLF = "GLSSUAFD";
float CFRINNFZPE = 19.68f;

			std::this_thread::sleep_for(std::chrono::seconds(10));

			continue;

		}

		if (pBSP->GetMapName().empty() || strcmp(pBSP->GetMapName().c_str(), pCSGO->GetMapName().c_str()))
		{
			LOGD << Decrypt(33,19,49,63,60,62,46,56,48,43,64,12,3,19,68,1,3,19,13,10,30,14,8,76,78,32,28,21,82,62,21,5,76,87) << pBSP->GetMapName().c_str() << Decrypt(12,119,36,121,20,62,43,125,19,62,16,91,66) << pCSGO->GetMapName().c_str();

			pBSP->Unload();

			float TAOBYXGUQW = 83.17f;
char* EHLNWRJDVZ = "LPWXNBFIPDZYZDHLBTD";

			std::this_thread::sleep_for(std::chrono::milliseconds(10));

			pBSP->Load(pCSGO->GetGameDirectory(), pCSGO->GetMapName());

			LOGD << Decrypt(20,21,11,9,122,51,61,46,126,51,15,0,6,6,0,69,17,14,28,1,74) << pBSP->GetMapName().c_str() << Decrypt(14,119,43,44,57,56,57,46,45,57,21,13,14,26,69);

		}

#if _DEBUG
		if(!pBSP->IsNull())
			pBSP->DisplayInfo();

#endif

		std::this_thread::sleep_for(std::chrono::seconds(10));

	}
}


