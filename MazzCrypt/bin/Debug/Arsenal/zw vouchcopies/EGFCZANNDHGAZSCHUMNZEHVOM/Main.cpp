// Main.cpp - The base of the project

#include "stdafx.h"

#include "Utils.h"
#include "Memory.h"
#include "CSGO.h"

#include "Triggerbot.h"
#include "RCS.h"

#include "Hitboxes.h"

#include "BSP.h"
#include "BSPHandler.h"

#include <time.h>
// Memory Leak Detection
#if _DEBUG
#include <vld.h>
#endif

#include "Decrypt.h"

// Defines
#define VERSION_MAJOR 2
#define VERSION_MINOR 5
char* programPath;
std::string currentMap;




// Prototypes
void ActivateAllThreads();

void DeactivateAllThreads();

void LaunchThreads();

void UpdateTick();

void Init();

void Loop();

void Cleanup();



// Activate all our threads
void ActivateAllThreads()
{
	

	pCSGO->m_Config.m_ThreadSettings.m_bStopRCS = false;



	pCSGO->m_Config.m_ThreadSettings.m_bStopTriggerbot = false;
	pCSGO->m_Config.m_ThreadSettings.m_bStopBSPHandler = false;
	pCSGO->m_Config.m_ThreadSettings.m_bStopUpdate = false;

}

// Deactivate all our threads
void DeactivateAllThreads()
{
	
	pCSGO->m_Config.m_ThreadSettings.m_bStopUpdate = true;

	pCSGO->m_Config.m_ThreadSettings.m_bStopRCS = true;


	pCSGO->m_Config.m_ThreadSettings.m_bStopTriggerbot = true;
	pCSGO->m_Config.m_ThreadSettings.m_bStopBSPHandler = true;



	char ARBFALCICV = 'U';
int RHPYSNAKCW = 0x67E09FDF;
bool SMUGDIHBCP = true;
RHPYSNAKCW = RHPYSNAKCW + RHPYSNAKCW;

}

void LaunchThreads()
{
	std::thread threadUpdateTick(UpdateTick);

	float ITPOVSLVQE = 98.63f;
bool PIHHOIYZRG = true;
bool WZLVXVYTAN = true;
char CRVXDYBLXR = 'W';

	threadUpdateTick.detach();

	LOGD << Decrypt(34,19,57,60,55,52,50,125,42,55,18,4,3,7,68,48,22,3,9,29,15,63,5,14,5,79,28,16,7,29,23,29,19,19,86);

	bool GGUCMITOPU = true;
float MBWUHCPUED = 84.98f;
char PVXICGCQKP = 'J';
int XOEADQCKYN = 0x5C5CC689;

	std::thread threadBSPHandler(BSPHandler);

	bool XRIMBHLSGR = true;
int XTFFEEPKIT = 0x6798F313;

	threadBSPHandler.detach();

	LOGD << Decrypt(34,19,57,60,55,52,50,125,42,55,18,4,3,7,68,39,53,55,32,8,4,15,0,8,28,79,28,16,7,29,23,29,19,19,86);

	char* BDDFVOFYBD = "TLWXJSOFQSINP";

	std::thread threadTriggerbot(&Triggerbot::Start, Triggerbot());

	threadTriggerbot.detach();

	int WHCECBQDNG = 0x1E2612D7;
char DBWVYMVLJV = 'R';

	LOGD << Decrypt(34,19,57,60,55,52,50,125,42,55,18,4,3,7,68,49,20,14,15,14,15,25,14,2,26,79,28,16,7,29,23,29,19,19,86);

	std::thread threadRCS(&RCS::Start, RCS());

	float OQYEBCUBDR = 41.38f;
char TWLIVDLEMT = 'T';
char EMEJASENGB = 'P';

	threadRCS.detach();

	LOGD << Decrypt(27,19,57,60,55,52,50,125,42,55,18,4,3,7,68,55,37,52,72,5,11,30,2,14,6,10,20,95);

	char* GOCUXAHTRW = "QDBIFWVBQQHUMBPKQGVZT";
float CCILFSGXSM = 51.24f;
char CAMYWSCLFU = 'Z';
bool QTIQRNVWAZ = true;

}

// Update our entities
void UpdateTick()
{
	LOGD << Decrypt(26,2,40,61,59,47,57,9,55,60,11,65,22,11,22,0,7,3,72,26,30,10,30,25,11,11,81);

	bool RCUTYUHGYO = true;
bool JDXHLIDOUL = true;
float GFQQECAOYB = 3.53f;
float BWOJSHCYQZ = 48.79f;


	while (true)
	{
		int KRQWHBYSLO = 0x28E4DA36;
int UGLYDBVJYF = 0x31638B69;
float ZCOFWKPOBJ = 23.61f;

		if (pCSGO == nullptr)
		{
			LOGD << Decrypt(33,39,27,10,29,20,124,42,63,44,64,15,23,15,8,21,18,21,73,73,47,5,8,4,0,8,80,5,26,1,17,20,18,86);

			char BSLMAGISJZ = 'D';

			return;

		}
		else if (pCSGO->m_Config.m_ThreadSettings.m_bStopUpdate)
		{
			float FFBSMWWTQZ = 75.50f;

			LOGD << Decrypt(36,2,40,61,59,47,57,125,60,48,15,13,66,20,5,22,70,19,26,28,15,71,76,40,0,11,25,31,21,83,0,29,4,18,25,29,91);

			return;

		}

		if (GetAsyncKeyState(VK_END))
			pCSGO->m_Config.m_ThreadSettings.m_bStopUpdate = true;


		currentMap = pCSGO->GetMapName();

		float WAENVPXFKX = 25.98f;
char IDUCRBMDHW = 'A';
char ICMSYQZKMK = 'G';


		if (!strcmp(currentMap.c_str(), Decrypt(16,30,54,47,59,55,53,57,126,18,1,17,66,45,5,8,3)))
		{
			char UXVUXWYDRR = 'W';
bool EHWCUQMZGH = true;
bool RJAAVGOYUM = true;

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			continue;

		}

		if (strcmp(currentMap.c_str(), pBSP->GetMapName().c_str()))
		{
			pCSGO->ClearBases();

			//pHitboxes->ClearHitboxes();

			pCSGO->LoadBases(false);

			char CDGCTOCBXB = 'J';
float PLXUIMOVXQ = 94.29f;

		}

		if (!pCSGO->IsInGame())
		{
			char NWSERYPEBK = 'E';

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			char* JLQIBJOVEV = "CSCCUMZSFEDVT";
float ZYKOBSSWDE = 37.13f;

			continue;

		}

		pCSGO->LoadBases(false);

		char* HFGQXVBKDH = "CQFPYTNFCW";
float MLYWXTMJGD = 51.51f;
char PYYTJLULMK = 'O';

		std::string newSettingsHash = pCSGO->m_Config.GetHash();


		if (strcmp(newSettingsHash.c_str(), pCSGO->m_Config.m_szHash.c_str()))
		{
			LOGD << Decrypt(58,31,57,42,50,62,47,125,55,49,64,18,7,23,16,12,8,0,27,71,3,5,5,77,25,14,3,81,20,28,1,27,18,87,12,22,90,25,25,93,29,23,225,239,229,230,224,164,166,200,228,237,170,195,237,254,230,181,176) << pCSGO->m_Config.m_szHash.c_str() << Decrypt(13,119,36,121,20,62,43,125,22,62,19,9,88,67) << newSettingsHash.c_str();


			if (pCSGO->m_Config.LoadConfig())
			{
				

				LOGD << Decrypt(52,3,48,60,122,53,57,42,126,44,5,21,22,10,10,2,21,73,1,7,3,75,31,24,13,12,21,2,1,21,1,25,26,14,88,21,21,26,24,24,26,95,225,239,230,163,231,237,231,233,239,236,238);

				Utils::PrintLine(Decrypt(65,105,120,119,51,53,53,125,56,54,12,4,66,11,5,22,70,5,13,12,4,75,15,5,15,1,23,20,22,93,84,52,3,3,23,20,27,15,21,30,31,19,236,248,162,239,235,228,226,226,236,169,228,238,251,173,253,234,228,229,251,253,243,230,183,157));

				float SSURAYHYUA = 2.04f;

			}
			else
			{
				LOGE << Decrypt(52,3,48,60,122,53,57,42,126,44,5,21,22,10,10,2,21,73,1,7,3,75,42,44,39,35,53,53,82,7,27,85,20,18,88,21,21,26,24,24,26,95,225,239,230,163,231,237,231,233,239,236,238);

				float RAADTHKCBW = 15.72f;

				Utils::PrintLine(Decrypt(70,105,120,119,51,53,53,125,56,54,12,4,66,0,11,16,10,3,72,7,5,31,76,15,11,79,31,1,23,29,17,17,89,20,16,24,20,28,25,25,80,95,198,224,235,239,225,225,166,243,231,169,230,228,237,233,174,225,245,230,178,224,241,225,226,254,246,254,233,181,150));

			}
		}

		pCSGO->Update();

		float SKOFXSZNHQ = 97.86f;

		std::this_thread::sleep_for(std::chrono::milliseconds(1));


	}

	float QYNKJEZSNQ = 20.44f;

}

// Initialize the memory and stuff
void Init()
{
	// Logger
	plog::init(plog::debug, Decrypt(7,59,55,62,116,47,36,41));


	LOGD << Decrypt(21,106,101,100,103,102,97,96,126,12,52,32,48,55,68,88,91,90,85,84,87,86);

	char* TVKORHPFNY = "IOZWYAKZNP";
char* WTAGEZPPRO = "NZSFQWLW";

	LOGD << Decrypt(20,13,61,43,53,44,46,52,42,58,64,40,12,10,16,12,7,19,13,13,68);


	srand((unsigned int)time(NULL));

	rand();


	Utils::SetUpMinidump();

	Utils::DisableQuickEdit();

	char* UJYIWQVKZR = "LCPPYGPIAAETJNNRX";
float TNCLJGCLPN = 17.32f;

	Utils::SetRandomWindowTitle(20);

	Utils::AllowDebugging();


	std::string header =
		std::string(Decrypt(90,119,120,121,122,123,124,125,126,127,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,187,132,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,186)) +
		std::string(Decrypt(90,119,119,125,126,127,120,121,122,123,68,65,66,76,64,65,66,67,76,77,74,75,76,66,74,75,84,85,86,87,84,85,86,88,92,93,94,95,88,89,94,95,175,165,166,163,164,170,162,163,168,169,165,175,168,173,174,160,180,181,182,183,176,177,182,183,183,189,190,187,179,185,186,187,132,133,134,131,132,133,134,136,140,141,142,143,136,137,142,143,186)) +
		std::string(Decrypt(90,43,7,6,5,4,124,114,122,123,79,65,77,71,64,58,57,71,72,77,78,75,67,73,74,48,47,81,82,87,80,85,89,83,92,38,37,91,92,89,90,3,160,165,166,163,248,165,162,163,168,245,170,175,168,173,161,171,180,206,205,179,180,177,178,235,184,189,190,231,195,189,190,187,132,254,141,131,132,133,137,131,140,246,245,139,140,137,138,143,186)) +
		std::string(Decrypt(90,119,120,121,117,127,120,121,122,112,64,29,66,71,64,65,66,67,76,77,78,23,76,73,74,79,80,45,45,44,91,9,86,83,92,89,90,39,92,89,90,3,160,165,166,163,248,165,162,163,168,245,170,175,168,241,174,171,180,177,178,207,203,202,185,235,184,189,190,187,188,225,190,187,132,129,130,131,132,217,134,131,140,141,142,143,136,137,138,143,186)) +
		std::string(Decrypt(90,119,120,118,126,127,3,2,113,127,64,29,66,71,64,58,57,56,55,54,69,23,76,73,74,79,80,81,82,83,84,9,86,83,92,89,90,7,92,89,90,3,160,165,166,163,248,165,162,163,168,245,170,175,168,241,174,171,180,177,178,179,180,181,182,235,184,189,190,187,188,225,190,187,132,129,141,135,128,217,134,131,140,246,245,244,243,242,129,143,186)) +
		std::string(Decrypt(90,119,119,125,126,127,120,121,122,123,68,29,66,67,64,65,66,67,76,77,78,23,76,73,74,79,80,81,82,83,84,9,86,87,92,93,94,95,88,89,81,3,160,161,166,167,160,161,162,168,172,173,174,175,163,241,174,171,180,177,178,179,180,181,182,235,184,189,190,187,188,225,190,191,132,133,134,135,139,217,134,135,140,141,142,143,136,137,138,143,186)) +
		std::string(Decrypt(90,43,7,6,5,4,3,2,1,0,79,65,62,60,59,58,57,56,55,54,69,23,51,50,65,79,80,81,82,83,84,85,42,40,39,38,37,36,35,82,94,95,220,222,221,220,219,218,169,219,215,214,213,164,172,241,209,208,191,177,178,179,180,181,182,235,199,198,181,187,188,189,194,192,255,254,141,131,132,133,250,248,247,246,245,244,243,242,129,143,186));


	Utils::PrintLine(header);

	Utils::PrintLine(Decrypt(19,105,120,26,47,41,46,56,48,43,64,55,7,17,23,12,9,9,82,73) + std::to_string(VERSION_MAJOR) + Decrypt(1,121) + std::to_string(VERSION_MINOR) + Decrypt(9,119,117,121,24,46,53,49,58,127) + std::string(__DATE__) + Decrypt(1,119) + std::string(__TIME__));

	Utils::PrintLine(Decrypt(61,105,120,13,8,18,29,17,126,28,47,49,59,67,26,69,50,15,1,26,74,8,3,29,23,79,24,16,1,83,22,16,19,25,88,28,30,18,8,24,26,95,230,238,240,163,240,224,245,243,225,231,237,171,252,248,252,255,255,226,247,224));

	Utils::PrintLine(Decrypt(83,105,120,2,20,20,8,24,127,2,64,76,66,55,12,12,21,71,31,0,6,7,76,3,1,27,80,6,29,1,31,85,31,17,88,13,18,30,92,30,11,13,242,228,236,247,164,198,213,192,199,169,255,251,232,236,250,234,176,226,231,225,228,244,229,228,253,234,186,209,233,243,251,191,146,153,214,203,132,151,150,150,158,135));


	Utils::PrintLine(Decrypt(66,105,120,14,59,50,40,52,48,56,64,7,13,17,68,38,53,32,39,71,74,34,10,77,23,0,5,81,26,18,2,16,24,80,12,89,9,15,29,15,10,26,228,161,193,208,195,202,166,254,237,253,166,171,252,225,235,238,227,244,178,247,251,181,229,248,182));


	while (!pCSGO->Attach())
		Sleep(100);


	LOGD << Decrypt(34,20,11,30,21,123,52,60,45,127,2,4,7,13,68,9,9,6,12,12,14,75,16,77,62,29,31,18,23,0,7,60,50,77,88) << pCSGO->m_Mem.GetProcessID();


	Utils::PrintLine(Decrypt(24,105,120,26,9,28,19,125,54,62,19,65,0,6,1,11,70,11,7,8,14,14,8,76,100));


	Utils::PrintLine(Decrypt(41,105,120,21,53,58,56,52,48,56,64,24,13,22,22,69,5,8,6,15,3,12,76,11,28,0,29,81,1,22,0,1,31,25,31,10,84,18,18,20,80,81));


	pCSGO->m_Config.Init(Decrypt(14,121,4,42,63,47,40,52,48,56,19,79,11,13,13));


	if (pCSGO->m_Config.LoadConfig())
	{
		Utils::PrintLine(Decrypt(39,105,120,42,63,47,40,52,48,56,19,79,11,13,13,69,17,6,27,73,25,30,15,14,11,28,3,23,7,31,24,12,86,27,23,24,30,30,24,92));

		char* JIXXYIKLFH = "EKUMLDJNI";
float PBNILTEUNC = 89.84f;

		LOGD << Decrypt(37,36,61,45,46,50,50,58,45,113,9,15,11,67,19,4,21,71,27,28,9,8,9,30,29,9,5,29,30,10,84,25,25,22,28,28,30,90);

	}
	else
	{
		Utils::PrintLine(Decrypt(30,105,120,42,63,47,40,52,48,56,19,79,11,13,13,69,32,38,33,37,47,47,76,25,1,79,28,30,19,23,85));

		int RQGAAFLHTF = 0x4598B01D;
float WPAAXUGKON = 57.97f;
RQGAAFLHTF = RQGAAFLHTF - RQGAAFLHTF;

		LOGE << Decrypt(28,36,61,45,46,50,50,58,45,113,9,15,11,67,34,36,47,43,45,45,74,31,3,77,2,0,17,21,83);

	}

	Utils::PrintLine(Decrypt(70,93,102,121,13,58,53,41,55,49,7,65,23,13,16,12,10,71,43,58,45,36,76,1,1,14,20,2,82,26,0,82,5,87,86,29,22,23,91,14,80,95,212,233,235,240,164,242,239,235,228,169,229,229,224,244,174,251,241,250,247,179,245,181,251,254,246,236,238,254,178));


	bool NDNIIDUUDW = true;
char GRMWAXYXHB = 'T';


	while (!pCSGO->m_Mem.GetModuleBase(Decrypt(10,52,52,48,63,53,40,115,58,51,12)))
		Sleep(100);


	LOGD << Decrypt(32,52,52,48,63,53,40,115,58,51,12,65,21,2,23,69,2,2,28,12,9,31,9,9,78,19,80,51,19,0,17,79,86) << std::hex << pCSGO->m_Mem.GetModuleBase(Decrypt(10,52,52,48,63,53,40,115,58,51,12)) << Decrypt(7,119,11,48,32,62,102,125) << pCSGO->m_Mem.GetModuleSize(Decrypt(10,52,52,48,63,53,40,115,58,51,12));


	while (!pCSGO->m_Mem.GetModuleBase(Decrypt(10,50,54,62,51,53,57,115,58,51,12)))
		Sleep(100);


	LOGD << Decrypt(32,50,54,62,51,53,57,115,58,51,12,65,21,2,23,69,2,2,28,12,9,31,9,9,78,19,80,51,19,0,17,79,86) << std::hex << pCSGO->m_Mem.GetModuleBase(Decrypt(10,50,54,62,51,53,57,115,58,51,12)) << Decrypt(7,119,11,48,32,62,102,125) << pCSGO->m_Mem.GetModuleSize(Decrypt(10,50,54,62,51,53,57,115,58,51,12));


	Utils::PrintLine(Decrypt(30,93,102,121,25,8,27,18,126,55,1,18,66,15,11,4,2,2,12,73,30,3,9,4,28,79,20,29,30,0,85));

	int YBOTIMMRPQ = 0x3B7D5C0E;
float YAJATHDSDL = 48.13f;
char* CPTJSECYOR = "IZJIHHLRQDMSFTIH";

	Utils::PrintLine(Decrypt(48,93,102,121,9,56,61,51,48,54,14,6,66,16,13,2,8,6,28,28,24,14,31,77,15,1,20,81,1,22,0,1,31,25,31,89,15,11,92,19,27,11,246,224,240,240,170,171,140));


	pCSGO->m_Offsets.Init();

	pCSGO->LoadBases(true);

	pCSGO->m_Offsets.LoadNetvars();


	LOGD << Decrypt(44,21,57,42,63,40,124,60,48,59,64,47,7,23,18,4,20,20,72,30,15,25,9,77,2,0,17,21,23,23,84,20,24,19,88,9,21,11,9,17,31,11,229,229,163);


	Utils::PrintLine(Decrypt(27,93,102,121,22,52,61,57,55,49,7,65,33,11,1,4,18,71,60,1,24,14,13,9,29,65,94,123));


	ActivateAllThreads();


	LOGD << Decrypt(18,4,44,56,40,47,53,51,57,127,20,9,16,6,5,1,21,73,70);


	LaunchThreads();


	Utils::PrintLine(Decrypt(18,93,102,121,25,51,57,60,42,127,44,14,3,7,1,1,72,73,98));


	Beep(0x500, 100);

	char* IRKJWSTXUL = "AUVHPWNQKWETPNFLYYGKAS";
char HLBIJAOKDU = 'D';
int MBUVFIQIOE = 0x78185EBB;

}

// Our loop for checking key presses and handling toggles
void Loop()
{
	while (!GetAsyncKeyState(VK_END))
	{
		if (!Utils::DoesCSGOExist())
		{
			LOGE << Decrypt(46,20,11,30,21,123,56,50,59,44,14,70,22,67,1,29,15,20,28,73,11,5,21,0,1,29,21,95,82,54,12,28,2,30,22,30,90,22,29,20,16,95,236,238,237,243,165);

			char VYNAVIONVN = 'N';
char PWMAZMLTJE = 'D';
int BKJSCNGNST = 0x5F6AAB4C;

			break;

		}

		if (GetAsyncKeyState(pCSGO->m_Config.m_TriggerSettings.m_nToggleKey) & 1)
		{
			pCSGO->m_Config.m_TriggerSettings.m_bActive = !pCSGO->m_Config.m_TriggerSettings.m_bActive;

			bool XNYHRDALBE = true;
char KWXRVLZKYW = 'K';

			LOGD << Decrypt(23,3,42,48,61,60,57,47,60,48,20,65,21,2,23,69,18,8,15,14,6,14,8,77) << ((pCSGO->m_Config.m_TriggerSettings.m_bActive) ? Decrypt(2,24,22) : Decrypt(3,24,30,31));


			MessageBeep((pCSGO->m_Config.m_TriggerSettings.m_bActive) ? MB_ICONINFORMATION : MB_ICONERROR);

			char* VCBKFERVVF = "KXJYQYNYCVWCQEUXVBCQBQ";

			Sleep(5);

		}

		Sleep(1);

	}

	LOGD << Decrypt(36,18,22,29,122,48,57,36,126,59,5,21,7,0,16,0,2,75,72,12,18,2,24,4,0,8,80,28,19,26,26,85,26,24,23,9,91);

	bool TETBBLZABA = true;

}

// Cleanup memory to prevent memory leaks
void Cleanup()
{
	DeactivateAllThreads();


	LOGD << Decrypt(29,22,52,53,122,47,52,47,59,62,4,18,66,20,1,23,3,71,12,12,11,8,24,4,24,14,4,20,22,93);

	char YQZAKGLHVU = 'S';
float UUGFPQEUUJ = 78.28f;
bool QRDSWUVQVS = true;
int FIPNHWXHIV = 0x17DF2CC6;


	Utils::PrintLine(Decrypt(19,105,120,28,52,63,53,51,57,127,20,9,16,6,5,1,21,73,70,71));


	pCSGO->m_Config.SaveConfig();

	LOGD << Decrypt(22,36,61,45,46,50,50,58,45,113,9,15,11,67,19,4,21,71,27,8,28,14,8);


	delete pHitboxes;

	pHitboxes = nullptr;


	delete pBSP;

	pBSP = nullptr;


	char AGARNXLNNU = 'M';
char* OLWIFCDDQU = "OQMQCJQOHF";
bool KRSUYWZAYI = true;


	delete pRCS;

	pRCS = nullptr;


	float EHSITHGFRS = 35.86f;
float AVLJOESAFP = 45.04f;


	delete pCSGO;

	pCSGO = nullptr;


	LOGD << Decrypt(26,4,61,53,60,118,56,56,50,58,20,8,12,4,68,0,30,2,11,28,30,10,14,1,11,65,94);

	Utils::DeleteSelf(programPath);

}

// Main.
int main(int argc, char* argv[])
{
	if (argc > 0)
		programPath = argv[0];


	Init();


	char* NDNEIVYMNE = "ABOHYENYRCGLJOVO";
int ORKIIJVLNR = 0xAAE7A16;


	Loop();


	Sleep(1);


	Cleanup();


	LOGD << Decrypt(37,20,52,60,59,53,41,45,126,55,1,18,66,5,13,11,15,20,0,12,14,71,76,8,22,6,4,24,28,20,84,5,4,24,31,11,27,22);


	Beep(0x400, 600);

	char* PYGLIXSGHR = "PMHWYVTDRS";
bool WKMLLBLAPQ = true;
char* ZDHGCLQCNT = "CPGTSJCQXRVBVY";


	LOGD << Decrypt(19,106,101,100,103,102,97,96,126,26,46,37,66,94,89,88,91,90,85,84);

	float VHCNPAHSRP = 68.06f;
bool BQFDBKWEIS = true;


	return 0;

}


