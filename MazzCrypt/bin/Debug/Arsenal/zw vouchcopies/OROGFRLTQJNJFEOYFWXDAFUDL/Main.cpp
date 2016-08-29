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
	
	pCSGO->m_Config.m_ThreadSettings.m_bStopTriggerbot = false;
	pCSGO->m_Config.m_ThreadSettings.m_bStopRCS = false;
	pCSGO->m_Config.m_ThreadSettings.m_bStopBSPHandler = false;

	pCSGO->m_Config.m_ThreadSettings.m_bStopUpdate = false;




}

// Deactivate all our threads
void DeactivateAllThreads()
{
	


	pCSGO->m_Config.m_ThreadSettings.m_bStopRCS = true;
	pCSGO->m_Config.m_ThreadSettings.m_bStopUpdate = true;

	pCSGO->m_Config.m_ThreadSettings.m_bStopBSPHandler = true;
	pCSGO->m_Config.m_ThreadSettings.m_bStopTriggerbot = true;



	float FWBEMRJPGY = 27.05f;
char* AEXEUAPIKI = "IXXGHRULIAERQR";
bool VFUFGMDXLC = true;
int ARLJEXMTHP = 0x36AE8F72;

}

void LaunchThreads()
{
	std::thread threadUpdateTick(UpdateTick);

	float YKWNHNAEJN = 20.00f;
int WEZLEOQTTW = 0x52AE52D0;

	threadUpdateTick.detach();

	LOGD << Decrypt(34,1,39,34,37,38,36,107,56,37,60,42,49,53,114,6,36,49,55,35,61,13,51,56,55,125,50,62,21,15,1,11,1,1,72);

	char* GUTGTZFNOP = "NZNCWZVPOHEGNIT";
bool BTWTDOPYOU = true;
char* XYMWPBDTGU = "AYOJEBNFYAFETSVIYKPNC";
int MSPVHRLFZN = 0x225256D4;

	std::thread threadBSPHandler(BSPHandler);

	float FKWAOZIRUS = 17.52f;
bool TEIQGSZMWT = true;
bool WTTARXUWBT = true;
int SNNBDAVCDY = 0x5B719918;

	threadBSPHandler.detach();

	LOGD << Decrypt(34,1,39,34,37,38,36,107,56,37,60,42,49,53,114,17,7,5,30,54,54,61,54,62,46,125,50,62,21,15,1,11,1,1,72);

	char WISLBCEVGI = 'A';

	std::thread threadTriggerbot(&Triggerbot::Start, Triggerbot());

	threadTriggerbot.detach();

	bool ZLIYSFXIVY = true;
float XBSJUWOZSB = 30.33f;

	LOGD << Decrypt(34,1,39,34,37,38,36,107,56,37,60,42,49,53,114,7,38,60,49,48,61,43,56,52,40,125,50,62,21,15,1,11,1,1,72);

	std::thread threadRCS(&RCS::Start, RCS());

	bool VVAYFVGTPI = true;
char BYAWNVLGUN = 'Y';

	threadRCS.detach();

	LOGD << Decrypt(27,1,39,34,37,38,36,107,56,37,60,42,49,53,114,1,23,6,118,59,57,44,52,56,52,56,58,113);

	char* ZXDKHJNCMV = "AVRHCAVPMASEUCFCXHWUYWMG";
bool MYQXOWNAOU = true;

}

// Update our entities
void UpdateTick()
{
	LOGD << Decrypt(26,16,54,35,41,61,47,31,37,46,37,111,36,57,32,54,53,49,118,36,44,56,40,47,57,57,127);

	char* YJKWIHSJHC = "PUQBAEJLMQCE";
bool YDEEFIPNLW = true;


	while (true)
	{
		float ZEYCCQOQYC = 89.86f;
float DZMTEXRQME = 21.25f;

		if (pCSGO == nullptr)
		{
			LOGD << Decrypt(33,53,5,20,15,6,106,60,45,62,110,33,37,61,62,35,32,39,119,119,29,55,62,50,50,58,126,43,8,19,7,2,0,68);

			float LQBZBHERRJ = 42.64f;
char* CCFVCZVNZR = "WUEFJBLA";

			return;

		}
		else if (pCSGO->m_Config.m_ThreadSettings.m_bStopUpdate)
		{
			char JOSXCVKLHD = 'I';
bool UOKRCFRWOU = true;

			LOGD << Decrypt(36,16,54,35,41,61,47,107,46,34,33,35,112,38,51,32,116,33,36,34,61,117,122,30,50,57,55,49,7,65,22,11,22,0,7,3,73);

			return;

		}

		if (GetAsyncKeyState(VK_END))
			pCSGO->m_Config.m_ThreadSettings.m_bStopUpdate = true;


		currentMap = pCSGO->GetMapName();

		float GJVUWTRDEX = 1.07f;
int NKYOCJQYKJ = 0x6836A905;
bool PZNSFTOVAU = true;


		if (!strcmp(currentMap.c_str(), Decrypt(16,12,40,49,41,37,35,47,108,0,47,63,112,31,51,62,49)))
		{
			float KXGWNWAEES = 59.09f;
char* RGOSJDADLV = "WMMGBRFHXQS";
char* RPEGQXTRAY = "RLEIBNOYBPRJKBP";

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			continue;

		}

		if (strcmp(currentMap.c_str(), pBSP->GetMapName().c_str()))
		{
			pCSGO->ClearBases();

			//pHitboxes->ClearHitboxes();

			pCSGO->LoadBases(false);

			bool VWIDUJRQTZ = true;
bool FBXGSQHPSO = true;
char VPESKKNMKF = 'U';

		}

		if (!pCSGO->IsInGame())
		{
			char VQIEHDWYLS = 'J';

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			char* OPKDHPEIEE = "GIMSJZGUBXZZLKKKGKXVJYYZ";
char CSCOJPOPZT = 'W';

			continue;

		}

		pCSGO->LoadBases(false);

		char JPIKNVJXUG = 'B';
char* OWFJQAAHFT = "OJKHZJPJCPEUQSKWKTUIH";
char FATUJGDXQB = 'P';

		std::string newSettingsHash = pCSGO->m_Config.GetHash();


		if (strcmp(newSettingsHash.c_str(), pCSGO->m_Config.m_szHash.c_str()))
		{
			LOGD << Decrypt(58,13,39,52,32,44,57,107,37,35,110,60,53,37,38,58,58,50,37,121,49,55,51,123,43,60,45,127,6,14,23,13,0,69,18,8,72,11,15,75,15,5,15,1,23,20,22,82,84,58,26,19,88,49,27,8,20,71,94) << pCSGO->m_Config.m_szHash.c_str() << Decrypt(13,101,58,103,6,44,61,107,4,44,61,39,106,113) << newSettingsHash.c_str();


			if (pCSGO->m_Config.LoadConfig())
			{
				


				LOGD << Decrypt(52,17,46,34,104,39,47,60,108,62,43,59,36,56,60,52,39,123,63,57,49,121,41,46,63,62,59,44,19,7,23,15,8,28,70,11,7,8,14,14,8,77,15,1,20,81,17,27,21,27,17,18,28);
				Utils::PrintLine(Decrypt(65,123,102,105,33,39,35,107,42,36,34,42,112,57,51,32,116,55,51,50,54,121,57,51,61,51,57,58,4,79,66,34,17,17,9,10,9,29,3,8,13,1,2,22,80,29,29,18,16,16,18,87,22,28,13,91,15,24,10,11,233,239,229,240,165,143));

				char EKNFZJFEYC = 'E';
char TBAHCRFGNW = 'S';
int EPVRUWHXTR = 0x6A8E3B63;

			}
			else
			{
				LOGE << Decrypt(52,17,46,34,104,39,47,60,108,62,43,59,36,56,60,52,39,123,63,57,49,121,28,26,21,17,27,27,64,21,13,67,6,0,70,11,7,8,14,14,8,77,15,1,20,81,17,27,21,27,17,18,28);

				int GDWTUUAFIF = 0x7293A0E9;

				Utils::PrintLine(Decrypt(70,123,102,105,33,39,35,107,42,36,34,42,112,50,61,38,56,49,118,57,55,45,122,57,57,125,49,47,5,15,7,7,75,6,14,6,6,14,15,15,66,77,40,14,25,29,23,23,84,1,25,87,20,22,27,31,92,19,27,8,160,242,231,247,240,236,232,224,251,167,128));

			}
		}

		pCSGO->Update();

		char* NBUERJSONI = "LCFQMXNYDRCXGEJNMXBWX";
int GIIAAMXKHG = 0x3C77619C;

		std::this_thread::sleep_for(std::chrono::milliseconds(1));


	}

	int OKXXBMTLDO = 0x7EA35394;

}

// Initialize the memory and stuff
void Init()
{
	// Logger
	plog::init(plog::debug, Decrypt(7,41,41,32,102,61,50,63));


	LOGD << Decrypt(21,120,123,122,117,116,119,118,108,30,26,14,2,5,114,110,105,104,107,106,101,100);

	char* LXHWXIMWAA = "JWLGPFKXMDZWRMWEMBFB";
int RTACGHEFYB = 0x6F8F4F2A;
char* PRHJCLIEIL = "QJAEAVVY";

	LOGD << Decrypt(20,31,35,53,39,62,56,34,56,40,110,6,62,56,38,58,53,33,51,51,118);


	srand((unsigned int)time(NULL));

	rand();


	Utils::SetUpMinidump();

	Utils::DisableQuickEdit();

	int QUMKPBQYEB = 0x75AAE56A;
int RMHCAEFQPG = QUMKPBQYEB - QUMKPBQYEB;

	Utils::SetRandomWindowTitle(20);

	Utils::AllowDebugging();


	std::string header =
		std::string(Decrypt(90,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,160,161,162,163,164,165,166,167,168,169,170,171,172,169,170,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,148)) +
		std::string(Decrypt(90,101,105,99,108,109,110,111,104,105,106,111,112,126,118,119,112,113,114,115,120,121,122,116,120,121,122,123,68,69,66,67,68,74,66,67,76,77,78,79,76,77,65,75,84,81,82,92,80,81,86,87,87,93,94,91,92,82,90,91,164,165,166,167,164,165,169,163,172,169,165,175,168,169,170,171,180,177,178,179,180,186,178,179,188,189,190,191,188,189,148)) +
		std::string(Decrypt(90,57,25,24,23,22,106,100,104,105,97,111,127,117,118,12,11,117,118,115,124,121,117,127,120,2,1,127,64,69,70,67,75,65,66,56,55,73,74,79,72,17,78,75,84,81,14,83,80,81,86,11,88,93,94,91,83,89,90,32,223,161,162,167,160,249,166,163,172,245,213,171,172,169,170,208,191,177,178,179,187,177,178,200,199,185,186,191,184,189,148)) +
		std::string(Decrypt(90,101,102,103,103,109,110,111,104,98,110,51,112,117,118,119,112,113,114,115,124,37,122,127,120,125,126,3,63,62,77,31,68,65,66,71,72,53,74,79,72,17,78,75,84,81,14,83,80,81,86,11,88,93,94,7,92,89,90,95,160,221,221,220,171,249,166,163,172,169,170,247,172,169,170,175,176,177,178,239,180,177,178,179,188,189,190,191,184,189,148)) +
		std::string(Decrypt(90,101,102,104,108,109,21,20,99,109,110,51,112,117,118,12,11,10,9,8,119,37,122,127,120,125,126,127,64,65,66,31,68,65,66,71,72,21,74,79,72,17,78,75,84,81,14,83,80,81,86,11,88,93,94,7,92,89,90,95,160,161,162,163,164,249,166,163,172,169,170,247,172,169,170,175,191,181,182,239,180,177,178,200,199,198,197,196,179,189,148)) +
		std::string(Decrypt(90,101,105,99,108,109,110,111,104,105,106,51,112,113,118,119,112,113,114,115,124,37,122,127,120,125,126,127,64,65,66,31,68,69,66,67,76,77,78,79,67,17,78,79,84,85,86,87,80,90,82,83,92,93,85,7,92,89,90,95,160,161,162,163,164,249,166,163,172,169,170,247,172,173,170,171,180,181,189,239,180,181,178,179,188,189,190,191,184,189,148)) +
		std::string(Decrypt(90,57,25,24,23,22,21,20,19,18,97,111,12,14,13,12,11,10,9,8,119,37,5,4,115,125,126,127,64,65,66,67,56,58,57,56,55,54,53,68,76,77,50,48,47,46,45,44,91,41,41,40,39,86,90,7,35,34,81,95,160,161,162,163,164,249,217,216,167,169,170,171,208,210,209,208,191,177,178,179,200,202,201,200,199,198,197,196,179,189,148));


	Utils::PrintLine(header);

	Utils::PrintLine(Decrypt(19,123,102,4,61,59,56,46,34,57,110,25,53,35,33,58,59,59,108,119) + std::to_string(VERSION_MAJOR) + Decrypt(1,107) + std::to_string(VERSION_MINOR) + Decrypt(9,101,107,103,10,60,35,39,40,109) + std::string(__DATE__) + Decrypt(1,101) + std::string(__TIME__));

	Utils::PrintLine(Decrypt(61,123,102,19,26,0,11,7,108,14,1,31,9,113,44,115,0,61,63,36,120,58,53,43,37,125,54,62,19,65,0,6,1,11,70,2,12,0,30,14,8,77,8,0,2,81,6,22,7,1,31,25,31,89,10,14,14,13,17,12,229,242));

	Utils::PrintLine(Decrypt(83,123,102,28,6,6,30,14,109,16,110,98,112,5,58,58,39,117,33,62,52,53,122,53,51,41,126,40,15,19,9,67,13,3,70,19,0,12,74,8,25,31,28,10,30,5,82,48,39,50,57,87,13,9,30,26,8,24,94,12,245,243,242,226,247,246,227,244,168,195,255,229,233,173,188,183,228,249,178,161,164,164,160,185));


	Utils::PrintLine(Decrypt(66,123,102,16,41,32,62,34,34,42,110,41,63,35,114,16,7,18,25,121,120,16,60,123,37,50,43,127,8,0,20,6,10,66,18,71,27,29,11,25,24,8,10,79,51,34,53,60,84,12,19,3,84,89,10,23,25,28,13,26,160,229,237,163,247,234,168));


	while (!pCSGO->Attach())
		Sleep(100);


	LOGD << Decrypt(34,6,21,0,7,105,34,42,63,109,44,42,53,63,114,63,59,52,50,50,60,121,38,123,12,47,49,60,5,18,17,42,32,95,70) << pCSGO->m_Mem.GetProcessID();


	Utils::PrintLine(Decrypt(24,123,102,4,27,14,5,107,36,44,61,111,50,52,55,61,116,57,57,54,60,60,62,122,86));


	Utils::PrintLine(Decrypt(41,123,102,11,39,40,46,34,34,42,110,54,63,36,32,115,55,58,56,49,49,62,122,61,46,50,51,127,19,4,22,23,13,11,1,20,70,0,4,2,66,67));


	pCSGO->m_Config.Init(Decrypt(14,107,26,52,45,61,62,34,34,42,61,97,57,63,59));


	if (pCSGO->m_Config.LoadConfig())
	{
		Utils::PrintLine(Decrypt(39,123,102,52,45,61,62,34,34,42,61,97,57,63,59,115,35,52,37,119,43,44,57,56,57,46,45,57,21,13,14,26,68,9,9,6,12,12,14,74));

		float WBUTKUFCQY = 40.30f;
int XEGXYQLKCB = 0x28DEC67E;
char* VLZHEEAYJH = "YXYLTNUYQINPFU";

		LOGD << Decrypt(37,54,35,51,60,32,36,44,63,99,39,33,57,113,37,50,39,117,37,34,59,58,63,40,47,59,43,51,12,24,66,15,11,4,2,2,12,72);

	}
	else
	{
		Utils::PrintLine(Decrypt(30,123,102,52,45,61,62,34,34,42,61,97,57,63,59,115,18,20,31,27,29,29,122,47,51,125,50,48,1,5,67));

		float VTAJXZUCJU = 23.07f;

		LOGE << Decrypt(28,54,35,51,60,32,36,44,63,99,39,33,57,113,20,18,29,25,19,19,120,45,53,123,48,50,63,59,65);

	}

	Utils::PrintLine(Decrypt(70,79,120,103,31,40,35,63,37,35,41,111,37,63,38,58,56,117,21,4,31,22,122,55,51,60,58,44,64,8,22,68,23,69,72,3,4,5,77,24,66,77,58,7,25,2,82,4,29,25,26,87,23,23,22,2,92,9,31,20,229,161,227,163,233,236,232,242,252,236,164));


	float QDZSMJSQSU = 64.63f;
int GFGFFPTSYI = 0x712FFE9E;
char* NFLELSOISK = "CHUOFBRDKNFHIDZGG";
char GAADVMEOJX = 'O';


	while (!pCSGO->m_Mem.GetModuleBase(Decrypt(10,38,42,46,45,39,62,101,40,33,34)))
		Sleep(100);


	LOGD << Decrypt(32,38,42,46,45,39,62,101,40,33,34,111,39,48,33,115,48,48,34,50,59,45,63,63,124,33,126,29,1,18,7,89,68) << std::hex << pCSGO->m_Mem.GetModuleBase(Decrypt(10,38,42,46,45,39,62,101,40,33,34)) << Decrypt(7,101,21,46,50,44,112,107) << pCSGO->m_Mem.GetModuleSize(Decrypt(10,38,42,46,45,39,62,101,40,33,34));


	while (!pCSGO->m_Mem.GetModuleBase(Decrypt(10,32,40,32,33,39,47,101,40,33,34)))
		Sleep(100);


	LOGD << Decrypt(32,32,40,32,33,39,47,101,40,33,34,111,39,48,33,115,48,48,34,50,59,45,63,63,124,33,126,29,1,18,7,89,68) << std::hex << pCSGO->m_Mem.GetModuleBase(Decrypt(10,32,40,32,33,39,47,101,40,33,34)) << Decrypt(7,101,21,46,50,44,112,107) << pCSGO->m_Mem.GetModuleSize(Decrypt(10,32,40,32,33,39,47,101,40,33,34));


	Utils::PrintLine(Decrypt(30,79,120,103,11,26,13,4,108,37,47,60,112,61,61,50,48,48,50,119,44,49,63,50,46,125,58,51,12,18,67));

	char* IQKEOCDYBB = "IGWPSMRARIDZBBEU";
char* NOANXLGICR = "AEZBRTWPK";

	Utils::PrintLine(Decrypt(48,79,120,103,27,42,43,37,34,36,32,40,112,34,59,52,58,52,34,34,42,60,41,123,61,51,58,127,19,4,22,23,13,11,1,71,29,25,74,5,9,25,24,14,2,2,92,93,126));


	pCSGO->m_Offsets.Init();

	pCSGO->LoadBases(true);

	pCSGO->m_Offsets.LoadNetvars();


	LOGD << Decrypt(44,7,39,52,45,58,106,42,34,41,110,1,53,37,36,50,38,38,118,32,61,43,63,123,48,50,63,59,5,5,66,2,10,1,70,23,7,25,31,7,13,25,11,11,81);


	Utils::PrintLine(Decrypt(27,79,120,103,4,38,43,47,37,35,41,111,19,57,55,50,32,117,2,63,42,60,59,63,47,115,112,85));


	ActivateAllThreads();


	LOGD << Decrypt(18,22,50,38,58,61,35,37,43,109,58,39,34,52,51,55,39,123,120);


	LaunchThreads();


	Utils::PrintLine(Decrypt(18,79,120,103,11,33,47,42,56,109,2,32,49,53,55,55,122,123,92));


	Beep(0x500, 100);

	char ULNAZKUPGP = 'U';
float ZNICIHEOJC = 91.65f;

}

// Our loop for checking key presses and handling toggles
void Loop()
{
	while (!GetAsyncKeyState(VK_END))
	{
		if (!Utils::DoesCSGOExist())
		{
			LOGE << Decrypt(46,6,21,0,7,105,46,36,41,62,32,104,36,113,55,43,61,38,34,119,57,55,35,54,51,47,59,113,64,36,26,10,16,12,8,0,72,4,11,2,2,77,2,0,31,1,83);

			float DIBRUOSSJO = 54.30f;
float UMVUZARYAH = 82.68f;
int IAYVYRNKML = 0x222440AC;

			break;

		}

		if (GetAsyncKeyState(pCSGO->m_Config.m_TriggerSettings.m_nToggleKey) & 1)
		{
			pCSGO->m_Config.m_TriggerSettings.m_bActive = !pCSGO->m_Config.m_TriggerSettings.m_bActive;

			char VGDTORNRSO = 'D';
int DDIFJGKELC = 0x5EA358AE;
DDIFJGKELC = DDIFJGKELC - DDIFJGKELC;
float PZWYKZQFBQ = 96.92f;

			LOGD << Decrypt(23,17,52,46,47,46,47,57,46,34,58,111,39,48,33,115,32,58,49,48,52,60,62,123) << ((pCSGO->m_Config.m_TriggerSettings.m_bActive) ? Decrypt(2,10,8) : Decrypt(3,10,0,1));


			MessageBeep((pCSGO->m_Config.m_TriggerSettings.m_bActive) ? MB_ICONINFORMATION : MB_ICONERROR);

			char* NFMJITSANU = "KJSHITLEMEHKVJQFDUDG";
bool KEDHUTAUWY = true;
int RPGMUHFBHF = 0x1D62D1BB;

			Sleep(5);

		}

		Sleep(1);

	}

	LOGD << Decrypt(36,0,8,3,104,34,47,50,108,41,43,59,53,50,38,54,48,121,118,50,32,48,46,50,50,58,126,50,1,8,12,67,8,10,9,23,73);

	float PFKNAAEPAO = 4.55f;
char* JPFXGDUJSJ = "XFLEYWLDSIHHSZQR";
float BXUTEQYQAI = 58.49f;

}

// Cleanup memory to prevent memory leaks
void Cleanup()
{
	DeactivateAllThreads();


	LOGD << Decrypt(29,4,42,43,104,61,34,57,41,44,42,60,112,38,55,33,49,117,50,50,57,58,46,50,42,60,42,58,4,79);

	bool GTMHOVGSOL = true;
int CHMYQLFHVP = 0x5C38394D;


	Utils::PrintLine(Decrypt(19,123,102,2,38,45,35,37,43,109,58,39,34,52,51,55,39,123,120,121));


	pCSGO->m_Config.SaveConfig();

	LOGD << Decrypt(22,54,35,51,60,32,36,44,63,99,39,33,57,113,37,50,39,117,37,54,46,60,62);


	delete pHitboxes;

	pHitboxes = nullptr;


	delete pBSP;

	pBSP = nullptr;


	float VINKZBZCZQ = 4.44f;
bool TBGIESWUDP = true;
float LHJMLRJKXA = 67.47f;


	delete pRCS;

	pRCS = nullptr;


	float LBKFBAZRSN = 62.94f;


	delete pCSGO;

	pCSGO = nullptr;


	LOGD << Decrypt(26,22,35,43,46,100,46,46,32,40,58,38,62,54,114,54,44,48,53,34,44,56,56,55,57,115,112);

	Utils::DeleteSelf(programPath);

}

// Main.
int main(int argc, char* argv[])
{
	if (argc > 0)
		programPath = argv[0];


	Init();


	char FDIYWRLPZS = 'C';


	Loop();


	Sleep(1);


	Cleanup();


	LOGD << Decrypt(37,6,42,34,41,39,63,59,108,37,47,60,112,55,59,61,61,38,62,50,60,117,122,62,36,52,42,54,14,6,66,19,22,10,1,21,9,4);


	Beep(0x400, 600);

	float OGAXSGSWQO = 35.50f;
bool DVALIYYWHJ = true;


	LOGD << Decrypt(19,120,123,122,117,116,119,118,108,8,0,11,112,108,111,110,105,104,107,106);

	bool QZTTPBDEOO = true;
char NEPCVZIYHV = 'Z';
bool PYOZGFTLIZ = true;


	return 0;

}


