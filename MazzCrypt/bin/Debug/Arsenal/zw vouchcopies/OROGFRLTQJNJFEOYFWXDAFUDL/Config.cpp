#include "Config.h"
#include "Utils.h"
#include "Enums.h"
#include <Wincrypt.h>
#include <cctype>
#include <algorithm>
#include <sstream>

#include "Decrypt.h"




#define SECTION_TRIGGERBOT Decrypt(10,49,52,46,47,46,47,57,46,34,58)

// Set the config file
void Config::Init(std::string szConfigName)
{
	m_szConfigFile = szConfigName;


	



	m_TriggerSettings.m_bAntiJump = false;




	m_TriggerSettings.m_bAntiSpectate = true;

	m_TriggerSettings.m_nKey = VK_XBUTTON1;

	m_TriggerSettings.m_bKnifebot = true;



	m_TriggerSettings.m_nMethod = Trigger_Hitbox;

	m_TriggerSettings.m_bSniperMode = true;


	m_TriggerSettings.m_bInvertMouse = false;
	m_TriggerSettings.m_nToggleKey = VK_NUMPAD5;
	m_TriggerSettings.m_fMinFlash = 55.0f;
	m_TriggerSettings.m_bKeyHeld = true;
	m_TriggerSettings.m_bActive = true;
	m_TriggerSettings.m_bSprayUntilDeadMode = true;

	m_TriggerSettings.m_bDeathmatch = true;
	m_TriggerSettings.m_bMoveCheck = true;
	m_TriggerSettings.m_bRecoilControl = true;

	m_TriggerSettings.m_nTargetType = TargetType_Enemies;
	m_TriggerSettings.m_fMinSpeed = 25.0f;

}



// Get hash of the file
std::string Config::GetHash()
{
	HANDLE hFile = CreateFile(m_szConfigFile.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);


	HCRYPTPROV hProv;

	char* YCFDKUBPXD = "AUBPFKDUN";

	HCRYPTHASH hHash;


	DWORD cbHash = 16;

	BYTE rgbHash[16];

	CHAR rgbDigits[] = "0123456789abcdef";





	if (hFile == INVALID_HANDLE_VALUE)
	{
		int dwStatus = GetLastError();

		Utils::PrintLine(std::string(Decrypt(21,0,52,53,39,59,106,57,41,44,42,38,62,54,114,58,58,117,120,62,54,48)));

		int VADFHHNPNT = 0xD89E1C1;
VADFHHNPNT = VADFHHNPNT * VADFHHNPNT;
int ATXZXSNOAS = 0x5195124E;

		CloseHandle(hFile);

		return std::string(Decrypt(5,0,20,21,7,27));

	}

	if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
	{
		int dwStatus = GetLastError();

		char* XACTHJBKZT = "TGMOHLAHUKJFZJSTH";
bool ZBCHZCESJT = true;

		Utils::PrintLine(std::string(Decrypt(35,0,52,53,39,59,106,42,47,60,59,38,34,56,60,52,116,22,36,46,40,45,27,56,45,40,55,45,5,34,13,13,16,0,30,19)));

		CloseHandle(hFile);

		return std::string(Decrypt(5,0,20,21,7,27));

	}

	if (!CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash))
	{
		int dwStatus = GetLastError();

		Utils::PrintLine(std::string(Decrypt(19,0,52,53,39,59,106,40,62,40,47,59,57,63,53,115,60,52,37,63)));

		CloseHandle(hFile);

		char BTULHRYOUD = 'K';
float QURARLLHJK = 54.86f;
int HXZVMGBOYN = 0x1D5F861D;
HXZVMGBOYN = HXZVMGBOYN + HXZVMGBOYN;

		CryptReleaseContext(hProv, 0);

		return std::string(Decrypt(5,0,20,21,7,27));

	}

	BOOL bResult = FALSE;

	DWORD cbRead;

	BYTE rgbFile[1024];


	while (bResult = ReadFile(hFile, rgbFile, 1024, &cbRead, NULL))
	{
		if (!cbRead)
		{
			int BOCWQCOTVB = 0x51FCF008;

			break;

		}

		if (!CryptHashData(hHash, rgbFile, cbRead, 0))
		{
			int dwStatus = GetLastError();

			Utils::PrintLine(std::string(Decrypt(24,0,52,53,39,59,106,60,37,57,38,111,19,35,43,35,32,29,55,36,48,29,59,47,61)));

			CryptReleaseContext(hProv, 0);

			int DYXPZOELQP = 0x5C3A5017;

			CryptDestroyHash(hHash);

			CloseHandle(hFile);

			return std::string(Decrypt(5,0,20,21,7,27));

		}
	}

	if (!bResult)
	{
		int dwStatus = GetLastError();

		Utils::PrintLine(std::string(Decrypt(15,23,35,38,44,15,35,39,41,109,40,46,57,61,55,55)));

		float BNRMEBGVOG = 10.48f;
float HNAHTFMONR = 18.12f;
char* ZAIOFWJHGK = "QLMTNTSQF";
float ALZMDERAGA = 38.46f;

		CryptReleaseContext(hProv, 0);

		CryptDestroyHash(hHash);

		CloseHandle(hFile);

		return std::string(Decrypt(5,0,20,21,7,27));

	}

	std::string hashOutput;


	if (CryptGetHashParam(hHash, HP_HASHVAL, rgbHash, &cbHash, 0))
	{
		for (DWORD i = 0; i < cbHash; i++)

		{
			hashOutput += std::to_string(rgbDigits[rgbHash[i] >> 4]);

			char HZPUBCYISR = 'O';
float CHXEBKFIKG = 54.96f;
float KQNZFNIMSC = 55.37f;

			hashOutput += std::to_string(rgbDigits[rgbHash[i] & 0xf]);

		}
	}

	CryptReleaseContext(hProv, 0);

	CryptDestroyHash(hHash);

	bool DQFHAUYUUM = true;
float EKWBLAJLPY = 13.92f;
char JCWZTPHWPO = 'E';
bool AHOQRSFSHS = true;

	CloseHandle(hFile);


	return hashOutput;

}

// Load the config
bool Config::LoadConfig()
{
	m_szHash = GetHash();


	char IAQFCAELST = 'W';
bool KXRUOTGTKB = true;
char* AHAJQSSRAN = "RRCDMSLCPFKBCFDJFULUHUEF";
bool AUVABETXYA = true;


	

	m_TriggerSettings.m_tRevolver.m_hitboxes = GetCommaSeperatedInts(Decrypt(16,49,52,46,47,46,47,57,19,63,43,57,63,61,36,54,38), Decrypt(8,45,47,51,42,38,50,46,63));

	m_TriggerSettings.m_tFiveSeven.m_fRCSScale = GetFloat(Decrypt(17,49,52,46,47,46,47,57,19,43,39,57,53,34,55,37,49,59), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));

	m_TriggerSettings.m_tMag7.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,32,47,40,103), Decrypt(8,45,47,51,42,38,50,46,63));


	m_TriggerSettings.m_tM4A4.m_nDelayBefore = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,122,46,100), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_tM4A4.m_fRCSScale = GetFloat(Decrypt(12,49,52,46,47,46,47,57,19,32,122,46,100), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));

	m_TriggerSettings.m_tGlock.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,42,34,32,51,58), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tM249.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,32,124,123,105), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tMag7.m_nDelayAfter = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,47,40,103), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tM4A1S.m_nDelayBefore = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,32,122,46,97,34), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_fMinFlash = GetFloat(SECTION_TRIGGERBOT, Decrypt(16,35,42,38,59,33,21,59,41,63,45,42,62,37,51,52,49));
	m_TriggerSettings.m_tDuelies.m_nDelayBefore = GetInt(Decrypt(20,49,52,46,47,46,47,57,19,41,59,46,60,51,55,33,49,33,34,54,43), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_bSprayUntilDeadMode = GetBool(SECTION_TRIGGERBOT, Decrypt(21,54,54,53,41,48,21,62,34,57,39,35,15,53,55,50,48,10,59,56,60,60));
	m_TriggerSettings.m_tP250.m_nDelayAfter = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,61,124,122,96), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tP2K.m_nDelayBefore = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,61,124,127,96,97), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_tCZ75.m_nDelayBefore = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,46,52,120,101), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));


	m_TriggerSettings.m_tFiveSeven.m_hitboxes = GetCommaSeperatedInts(Decrypt(17,49,52,46,47,46,47,57,19,43,39,57,53,34,55,37,49,59), Decrypt(8,45,47,51,42,38,50,46,63));


	m_TriggerSettings.m_tAWP.m_nDelayAfter = GetInt(Decrypt(11,49,52,46,47,46,47,57,19,44,57,63), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tTec9.m_nDelayBefore = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,57,43,44,105), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));

	m_TriggerSettings.m_tMAC10.m_nDelayBefore = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,32,47,44,97,97), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_tMAC10.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,32,47,44,97,97), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tSCAR20.m_hitboxes = GetCommaSeperatedInts(Decrypt(14,49,52,46,47,46,47,57,19,62,45,46,34,99,98), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tXM1014.m_nDelayBefore = GetInt(Decrypt(14,49,52,46,47,46,47,57,19,53,35,126,96,96,102), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_tSCAR20.m_fRCSScale = GetFloat(Decrypt(14,49,52,46,47,46,47,57,19,62,45,46,34,99,98), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));

	m_TriggerSettings.m_bRevolverMode = GetBool(SECTION_TRIGGERBOT, Decrypt(13,55,35,49,39,37,60,46,62,18,35,32,52,52));
	m_TriggerSettings.m_tGalil.m_nDelayAfter = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,47,35,57,61), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tNova.m_fRCSScale = GetFloat(Decrypt(12,49,52,46,47,46,47,57,19,35,33,57,49), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));




	m_TriggerSettings.m_tAUG.m_fRCSScale = GetFloat(Decrypt(11,49,52,46,47,46,47,57,19,44,59,40), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tXM1014.m_fRCSScale = GetFloat(Decrypt(14,49,52,46,47,46,47,57,19,53,35,126,96,96,102), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));

	m_TriggerSettings.m_tP2K.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,61,124,127,96,97), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tMag7.m_nDelayBefore = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,47,40,103), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_tNova.m_nDelayBefore = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,35,33,57,49), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));


	m_TriggerSettings.m_tMP7.m_hitboxes = GetCommaSeperatedInts(Decrypt(11,49,52,46,47,46,47,57,19,32,62,120), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_nMethod = GetInt(SECTION_TRIGGERBOT, Decrypt(12,49,52,46,47,46,47,57,19,57,55,63,53));

	m_TriggerSettings.m_tDeagle.m_nDelayBefore = GetInt(Decrypt(14,49,52,46,47,46,47,57,19,41,43,46,55,61,55), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_bKeyHeld = GetBool(SECTION_TRIGGERBOT, Decrypt(7,45,41,43,44,34,47,50));
	m_TriggerSettings.m_tUSP.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,56,61,63,35), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tG3SG1.m_nDelayAfter = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,125,60,55,96), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tUMP45.m_fRCSScale = GetFloat(Decrypt(13,49,52,46,47,46,47,57,19,56,35,63,100,100), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));

	m_TriggerSettings.m_tNegev.m_nDelayAfter = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,35,43,40,53,39), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tUSP.m_fRCSScale = GetFloat(Decrypt(12,49,52,46,47,46,47,57,19,56,61,63,35), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));

	m_TriggerSettings.m_tM4A1S.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,32,122,46,97,34), Decrypt(8,45,47,51,42,38,50,46,63));


	m_TriggerSettings.m_tDeagle.m_nDelayAfter = GetInt(Decrypt(14,49,52,46,47,46,47,57,19,41,43,46,55,61,55), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));




	m_TriggerSettings.m_tNegev.m_fRCSScale = GetFloat(Decrypt(13,49,52,46,47,46,47,57,19,35,43,40,53,39), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tP90.m_nDelayAfter = GetInt(Decrypt(11,49,52,46,47,46,47,57,19,61,119,127), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tScout.m_nDelayAfter = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,62,45,32,37,37), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tMP7.m_fRCSScale = GetFloat(Decrypt(11,49,52,46,47,46,47,57,19,32,62,120), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));


	m_TriggerSettings.m_tGalil.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,42,47,35,57,61), Decrypt(8,45,47,51,42,38,50,46,63));

	m_TriggerSettings.m_tFAMAS.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,43,47,34,49,34), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tP250.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,61,124,122,96), Decrypt(8,45,47,51,42,38,50,46,63));


	m_TriggerSettings.m_nTargetType = GetInt(SECTION_TRIGGERBOT, Decrypt(11,49,39,53,47,44,62,20,56,52,62,42));
	m_TriggerSettings.m_tP2K.m_fRCSScale = GetFloat(Decrypt(13,49,52,46,47,46,47,57,19,61,124,127,96,97), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tMP9.m_nDelayAfter = GetInt(Decrypt(11,49,52,46,47,46,47,57,19,32,62,118), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));


	m_TriggerSettings.m_bMoveCheck = GetBool(SECTION_TRIGGERBOT, Decrypt(9,40,41,49,45,42,34,46,47,38));


	m_TriggerSettings.m_tSG553.m_nDelayBefore = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,62,41,122,101,98), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_tXM1014.m_hitboxes = GetCommaSeperatedInts(Decrypt(14,49,52,46,47,46,47,57,19,53,35,126,96,96,102), Decrypt(8,45,47,51,42,38,50,46,63));

	m_TriggerSettings.m_tSawedOff.m_fRCSScale = GetFloat(Decrypt(16,49,52,46,47,46,47,57,19,62,47,56,53,53,61,53,50), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));


	m_TriggerSettings.m_tMP9.m_nDelayBefore = GetInt(Decrypt(11,49,52,46,47,46,47,57,19,32,62,118), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_tFAMAS.m_nDelayBefore = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,43,47,34,49,34), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));





	m_TriggerSettings.m_tM249.m_nDelayBefore = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,124,123,105), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));


	m_TriggerSettings.m_tAUG.m_nDelayAfter = GetInt(Decrypt(11,49,52,46,47,46,47,57,19,44,59,40), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));

	m_TriggerSettings.m_tAWP.m_fRCSScale = GetFloat(Decrypt(11,49,52,46,47,46,47,57,19,44,57,63), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));

	m_TriggerSettings.m_tCZ75.m_nDelayAfter = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,46,52,120,101), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tMAC10.m_fRCSScale = GetFloat(Decrypt(13,49,52,46,47,46,47,57,19,32,47,44,97,97), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tAK47.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,44,37,123,103), Decrypt(8,45,47,51,42,38,50,46,63));

	m_TriggerSettings.m_tAUG.m_nDelayBefore = GetInt(Decrypt(11,49,52,46,47,46,47,57,19,44,59,40), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));


	m_TriggerSettings.m_tG3SG1.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,42,125,60,55,96), Decrypt(8,45,47,51,42,38,50,46,63));


	m_TriggerSettings.m_tUMP45.m_nDelayBefore = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,56,35,63,100,100), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));

	m_TriggerSettings.m_tScout.m_nDelayBefore = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,62,45,32,37,37), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_tG3SG1.m_nDelayBefore = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,125,60,55,96), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));

	m_TriggerSettings.m_tFAMAS.m_fRCSScale = GetFloat(Decrypt(13,49,52,46,47,46,47,57,19,43,47,34,49,34), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tMP7.m_nDelayAfter = GetInt(Decrypt(11,49,52,46,47,46,47,57,19,32,62,120), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tNova.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,35,33,57,49), Decrypt(8,45,47,51,42,38,50,46,63));

	m_TriggerSettings.m_tM4A1S.m_fRCSScale = GetFloat(Decrypt(13,49,52,46,47,46,47,57,19,32,122,46,97,34), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));





	m_TriggerSettings.m_tAK47.m_fRCSScale = GetFloat(Decrypt(12,49,52,46,47,46,47,57,19,44,37,123,103), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tFiveSeven.m_nDelayAfter = GetInt(Decrypt(17,49,52,46,47,46,47,57,19,43,39,57,53,34,55,37,49,59), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tXM1014.m_nDelayAfter = GetInt(Decrypt(14,49,52,46,47,46,47,57,19,53,35,126,96,96,102), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));


	m_TriggerSettings.m_tMP9.m_fRCSScale = GetFloat(Decrypt(11,49,52,46,47,46,47,57,19,32,62,118), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tTec9.m_fRCSScale = GetFloat(Decrypt(12,49,52,46,47,46,47,57,19,57,43,44,105), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));

	m_TriggerSettings.m_tAK47.m_nDelayBefore = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,44,37,123,103), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_tBizon.m_nDelayAfter = GetInt(Decrypt(15,49,52,46,47,46,47,57,19,61,62,45,57,43,61,61), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));

	m_TriggerSettings.m_tFAMAS.m_nDelayAfter = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,43,47,34,49,34), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));









	m_TriggerSettings.m_tDeagle.m_hitboxes = GetCommaSeperatedInts(Decrypt(14,49,52,46,47,46,47,57,19,41,43,46,55,61,55), Decrypt(8,45,47,51,42,38,50,46,63));

	m_TriggerSettings.m_tUSP.m_nDelayAfter = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,56,61,63,35), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));

	m_TriggerSettings.m_bDeathmatch = GetBool(SECTION_TRIGGERBOT, Decrypt(15,33,35,38,60,33,39,42,56,46,38,16,61,62,54,54));
	m_TriggerSettings.m_tBizon.m_nDelayBefore = GetInt(Decrypt(15,49,52,46,47,46,47,57,19,61,62,45,57,43,61,61), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));



	m_TriggerSettings.m_tM4A4.m_nDelayAfter = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,122,46,100), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tUMP45.m_nDelayAfter = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,56,35,63,100,100), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tTec9.m_nDelayAfter = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,57,43,44,105), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tDuelies.m_fRCSScale = GetFloat(Decrypt(20,49,52,46,47,46,47,57,19,41,59,46,60,51,55,33,49,33,34,54,43), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tGalil.m_fRCSScale = GetFloat(Decrypt(13,49,52,46,47,46,47,57,19,42,47,35,57,61), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tM249.m_nDelayAfter = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,124,123,105), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tGlock.m_nDelayAfter = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,34,32,51,58), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tSCAR20.m_nDelayAfter = GetInt(Decrypt(14,49,52,46,47,46,47,57,19,62,45,46,34,99,98), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));

	m_TriggerSettings.m_tRevolver.m_nDelayAfter = GetInt(Decrypt(16,49,52,46,47,46,47,57,19,63,43,57,63,61,36,54,38), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));

	m_TriggerSettings.m_bAntiJump = GetBool(SECTION_TRIGGERBOT, Decrypt(12,36,40,51,33,22,32,62,33,61,39,33,55));


	m_TriggerSettings.m_tM249.m_fRCSScale = GetFloat(Decrypt(12,49,52,46,47,46,47,57,19,32,124,123,105), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));



	m_TriggerSettings.m_tP90.m_hitboxes = GetCommaSeperatedInts(Decrypt(11,49,52,46,47,46,47,57,19,61,119,127), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tMP7.m_nDelayBefore = GetInt(Decrypt(11,49,52,46,47,46,47,57,19,32,62,120), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));

	m_TriggerSettings.m_tAWP.m_hitboxes = GetCommaSeperatedInts(Decrypt(11,49,52,46,47,46,47,57,19,44,57,63), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tSG553.m_nDelayAfter = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,62,41,122,101,98), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));

	m_TriggerSettings.m_tSawedOff.m_nDelayBefore = GetInt(Decrypt(16,49,52,46,47,46,47,57,19,62,47,56,53,53,61,53,50), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));




	m_TriggerSettings.m_tTec9.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,57,43,44,105), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tCZ75.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,46,52,120,101), Decrypt(8,45,47,51,42,38,50,46,63));




	m_TriggerSettings.m_tCZ75.m_fRCSScale = GetFloat(Decrypt(12,49,52,46,47,46,47,57,19,46,52,120,101), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));




	m_TriggerSettings.m_tDeagle.m_fRCSScale = GetFloat(Decrypt(14,49,52,46,47,46,47,57,19,41,43,46,55,61,55), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));

	m_TriggerSettings.m_tMAC10.m_nDelayAfter = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,32,47,44,97,97), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tGlock.m_fRCSScale = GetFloat(Decrypt(13,49,52,46,47,46,47,57,19,42,34,32,51,58), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tUSP.m_nDelayBefore = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,56,61,63,35), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));

	m_TriggerSettings.m_tAK47.m_nDelayAfter = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,44,37,123,103), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tM4A4.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,32,122,46,100), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tAWP.m_nDelayBefore = GetInt(Decrypt(11,49,52,46,47,46,47,57,19,44,57,63), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));


	m_TriggerSettings.m_tDuelies.m_nDelayAfter = GetInt(Decrypt(20,49,52,46,47,46,47,57,19,41,59,46,60,51,55,33,49,33,34,54,43), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tAUG.m_hitboxes = GetCommaSeperatedInts(Decrypt(11,49,52,46,47,46,47,57,19,44,59,40), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tP2K.m_nDelayAfter = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,61,124,127,96,97), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));
	m_TriggerSettings.m_tRevolver.m_fRCSScale = GetFloat(Decrypt(16,49,52,46,47,46,47,57,19,63,43,57,63,61,36,54,38), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tMag7.m_fRCSScale = GetFloat(Decrypt(12,49,52,46,47,46,47,57,19,32,47,40,103), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));


	m_TriggerSettings.m_tGlock.m_nDelayBefore = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,34,32,51,58), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));

	m_TriggerSettings.m_fMinSpeed = GetFloat(SECTION_TRIGGERBOT, Decrypt(8,40,47,41,59,57,47,46,40));


	m_TriggerSettings.m_nKey = GetKey(SECTION_TRIGGERBOT, Decrypt(3,46,35,62));
	m_TriggerSettings.m_tDuelies.m_hitboxes = GetCommaSeperatedInts(Decrypt(20,49,52,46,47,46,47,57,19,41,59,46,60,51,55,33,49,33,34,54,43), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tBizon.m_hitboxes = GetCommaSeperatedInts(Decrypt(15,49,52,46,47,46,47,57,19,61,62,45,57,43,61,61), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tGalil.m_nDelayBefore = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,47,35,57,61), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_nToggleKey = GetKey(SECTION_TRIGGERBOT, Decrypt(9,49,41,32,47,37,47,32,41,52));
	m_TriggerSettings.m_tP250.m_fRCSScale = GetFloat(Decrypt(12,49,52,46,47,46,47,57,19,61,124,122,96), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));




	m_TriggerSettings.m_tSG553.m_fRCSScale = GetFloat(Decrypt(13,49,52,46,47,46,47,57,19,62,41,122,101,98), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tP250.m_nDelayBefore = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,61,124,122,96), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));

	m_TriggerSettings.m_bInvertMouse = GetBool(SECTION_TRIGGERBOT, Decrypt(13,44,40,49,45,59,62,46,40,32,33,58,35,52));

	m_TriggerSettings.m_bRecoilControl = GetBool(SECTION_TRIGGERBOT, Decrypt(14,55,35,36,39,32,38,20,47,34,32,59,34,62,62));


	m_TriggerSettings.m_tP90.m_nDelayBefore = GetInt(Decrypt(11,49,52,46,47,46,47,57,19,61,119,127), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));






	m_TriggerSettings.m_tRevolver.m_nDelayBefore = GetInt(Decrypt(16,49,52,46,47,46,47,57,19,63,43,57,63,61,36,54,38), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));

	m_TriggerSettings.m_tFiveSeven.m_nDelayBefore = GetInt(Decrypt(17,49,52,46,47,46,47,57,19,43,39,57,53,34,55,37,49,59), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));
	m_TriggerSettings.m_tScout.m_fRCSScale = GetFloat(Decrypt(13,49,52,46,47,46,47,57,19,62,45,32,37,37), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));


	m_TriggerSettings.m_tSawedOff.m_nDelayAfter = GetInt(Decrypt(16,49,52,46,47,46,47,57,19,62,47,56,53,53,61,53,50), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));



	m_TriggerSettings.m_tNova.m_nDelayAfter = GetInt(Decrypt(12,49,52,46,47,46,47,57,19,35,33,57,49), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));


	m_TriggerSettings.m_tNegev.m_nDelayBefore = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,35,43,40,53,39), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));


	m_TriggerSettings.m_bSniperMode = GetBool(SECTION_TRIGGERBOT, Decrypt(11,54,40,46,56,44,56,20,33,34,42,42));

	m_TriggerSettings.m_tSawedOff.m_hitboxes = GetCommaSeperatedInts(Decrypt(16,49,52,46,47,46,47,57,19,62,47,56,53,53,61,53,50), Decrypt(8,45,47,51,42,38,50,46,63));

	m_TriggerSettings.m_tP90.m_fRCSScale = GetFloat(Decrypt(11,49,52,46,47,46,47,57,19,61,119,127), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));


	m_TriggerSettings.m_tMP9.m_hitboxes = GetCommaSeperatedInts(Decrypt(11,49,52,46,47,46,47,57,19,32,62,118), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_bAntiSpectate = GetBool(SECTION_TRIGGERBOT, Decrypt(13,36,40,51,33,22,57,59,41,46,58,46,36,52));




	m_TriggerSettings.m_tUMP45.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,56,35,63,100,100), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tScout.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,62,45,32,37,37), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tSG553.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,62,41,122,101,98), Decrypt(8,45,47,51,42,38,50,46,63));
	m_TriggerSettings.m_tNegev.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,35,43,40,53,39), Decrypt(8,45,47,51,42,38,50,46,63));




	m_TriggerSettings.m_bActive = GetBool(SECTION_TRIGGERBOT, Decrypt(9,36,37,51,33,63,43,63,41,41));
	m_TriggerSettings.m_tSCAR20.m_nDelayBefore = GetInt(Decrypt(14,49,52,46,47,46,47,57,19,62,45,46,34,99,98), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53));

	m_TriggerSettings.m_tM4A1S.m_nDelayAfter = GetInt(Decrypt(13,49,52,46,47,46,47,57,19,32,122,46,97,34), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61));

	m_TriggerSettings.m_tG3SG1.m_fRCSScale = GetFloat(Decrypt(13,49,52,46,47,46,47,57,19,42,125,60,55,96), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));
	m_TriggerSettings.m_tBizon.m_fRCSScale = GetFloat(Decrypt(15,49,52,46,47,46,47,57,19,61,62,45,57,43,61,61), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53));



	return true;

}

// Save the config
bool Config::SaveConfig()
{
	



	SetFloat(Decrypt(11,49,52,46,47,46,47,57,19,32,62,118), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tMP9.m_fRCSScale);
	SetInt(Decrypt(14,49,52,46,47,46,47,57,19,41,43,46,55,61,55), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tDeagle.m_nDelayAfter);
	SetFloat(Decrypt(11,49,52,46,47,46,47,57,19,44,57,63), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tAWP.m_fRCSScale);
	SetFloat(Decrypt(12,49,52,46,47,46,47,57,19,32,47,40,103), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tMag7.m_fRCSScale);


	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,43,47,34,49,34), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tFAMAS.m_nDelayAfter);


	SetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,62,45,32,37,37), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tScout.m_hitboxes);
	SetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,56,61,63,35), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tUSP.m_hitboxes);
	SetInt(Decrypt(16,49,52,46,47,46,47,57,19,63,43,57,63,61,36,54,38), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tRevolver.m_nDelayBefore);


	SetInt(Decrypt(11,49,52,46,47,46,47,57,19,44,57,63), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tAWP.m_nDelayBefore);
	SetFloat(Decrypt(12,49,52,46,47,46,47,57,19,44,37,123,103), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tAK47.m_fRCSScale);


	SetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,32,122,46,100), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tM4A4.m_hitboxes);
	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,122,46,100), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tM4A4.m_nDelayBefore);


	SetBool(SECTION_TRIGGERBOT, Decrypt(13,55,35,49,39,37,60,46,62,18,35,32,52,52), m_TriggerSettings.m_bRevolverMode);
	SetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,44,37,123,103), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tAK47.m_hitboxes);

	SetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,61,124,122,96), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tP250.m_hitboxes);
	SetInt(Decrypt(11,49,52,46,47,46,47,57,19,44,59,40), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tAUG.m_nDelayAfter);
	SetInt(Decrypt(11,49,52,46,47,46,47,57,19,32,62,118), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tMP9.m_nDelayAfter);
	SetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,32,124,123,105), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tM249.m_hitboxes);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,56,35,63,100,100), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tUMP45.m_nDelayBefore);

	SetCommaSeperatedInts(Decrypt(20,49,52,46,47,46,47,57,19,41,59,46,60,51,55,33,49,33,34,54,43), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tDuelies.m_hitboxes);
	SetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,56,35,63,100,100), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tUMP45.m_hitboxes);

	SetFloat(Decrypt(11,49,52,46,47,46,47,57,19,32,62,120), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tMP7.m_fRCSScale);


	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,124,123,105), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tM249.m_nDelayBefore);
	SetBool(SECTION_TRIGGERBOT, Decrypt(7,45,41,43,44,34,47,50), m_TriggerSettings.m_bKeyHeld);



	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,46,52,120,101), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tCZ75.m_nDelayAfter);





	SetInt(Decrypt(14,49,52,46,47,46,47,57,19,41,43,46,55,61,55), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tDeagle.m_nDelayBefore);
	SetInt(Decrypt(16,49,52,46,47,46,47,57,19,62,47,56,53,53,61,53,50), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tSawedOff.m_nDelayBefore);
	SetInt(Decrypt(15,49,52,46,47,46,47,57,19,61,62,45,57,43,61,61), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tBizon.m_nDelayAfter);



	SetInt(Decrypt(14,49,52,46,47,46,47,57,19,62,45,46,34,99,98), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tSCAR20.m_nDelayAfter);


	SetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,42,125,60,55,96), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tG3SG1.m_hitboxes);

	SetFloat(Decrypt(12,49,52,46,47,46,47,57,19,61,124,122,96), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tP250.m_fRCSScale);
	SetBool(SECTION_TRIGGERBOT, Decrypt(13,36,40,51,33,22,57,59,41,46,58,46,36,52), m_TriggerSettings.m_bAntiSpectate);
	SetBool(SECTION_TRIGGERBOT, Decrypt(13,44,40,49,45,59,62,46,40,32,33,58,35,52), m_TriggerSettings.m_bInvertMouse);



	SetFloat(Decrypt(13,49,52,46,47,46,47,57,19,32,122,46,97,34), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tM4A1S.m_fRCSScale);



	SetInt(Decrypt(11,49,52,46,47,46,47,57,19,32,62,120), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tMP7.m_nDelayBefore);
	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,61,124,122,96), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tP250.m_nDelayAfter);

	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,32,122,46,97,34), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tM4A1S.m_nDelayBefore);
	SetCommaSeperatedInts(Decrypt(16,49,52,46,47,46,47,57,19,62,47,56,53,53,61,53,50), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tSawedOff.m_hitboxes);
	SetFloat(Decrypt(13,49,52,46,47,46,47,57,19,42,47,35,57,61), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tGalil.m_fRCSScale);


	SetInt(Decrypt(17,49,52,46,47,46,47,57,19,43,39,57,53,34,55,37,49,59), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tFiveSeven.m_nDelayBefore);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,62,45,32,37,37), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tScout.m_nDelayAfter);


	SetFloat(Decrypt(13,49,52,46,47,46,47,57,19,61,124,127,96,97), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tP2K.m_fRCSScale);

	SetCommaSeperatedInts(Decrypt(11,49,52,46,47,46,47,57,19,44,57,63), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tAWP.m_hitboxes);

	SetInt(Decrypt(11,49,52,46,47,46,47,57,19,44,59,40), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tAUG.m_nDelayBefore);
	SetBool(SECTION_TRIGGERBOT, Decrypt(15,33,35,38,60,33,39,42,56,46,38,16,61,62,54,54), m_TriggerSettings.m_bDeathmatch);
	SetFloat(Decrypt(11,49,52,46,47,46,47,57,19,61,119,127), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tP90.m_fRCSScale);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,34,32,51,58), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tGlock.m_nDelayAfter);
	SetFloat(Decrypt(16,49,52,46,47,46,47,57,19,63,43,57,63,61,36,54,38), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tRevolver.m_fRCSScale);



	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,62,41,122,101,98), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tSG553.m_nDelayAfter);
	SetFloat(Decrypt(15,49,52,46,47,46,47,57,19,61,62,45,57,43,61,61), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tBizon.m_fRCSScale);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,47,35,57,61), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tGalil.m_nDelayBefore);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,56,35,63,100,100), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tUMP45.m_nDelayAfter);



	SetInt(Decrypt(11,49,52,46,47,46,47,57,19,61,119,127), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tP90.m_nDelayBefore);


	SetKey(SECTION_TRIGGERBOT, Decrypt(3,46,35,62), m_TriggerSettings.m_nKey);
	SetFloat(Decrypt(13,49,52,46,47,46,47,57,19,56,35,63,100,100), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tUMP45.m_fRCSScale);


	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,62,41,122,101,98), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tSG553.m_nDelayBefore);
	SetFloat(SECTION_TRIGGERBOT, Decrypt(8,40,47,41,59,57,47,46,40), m_TriggerSettings.m_fMinSpeed);

	SetCommaSeperatedInts(Decrypt(17,49,52,46,47,46,47,57,19,43,39,57,53,34,55,37,49,59), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tFiveSeven.m_hitboxes);

	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,35,33,57,49), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tNova.m_nDelayAfter);


	SetCommaSeperatedInts(Decrypt(14,49,52,46,47,46,47,57,19,41,43,46,55,61,55), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tDeagle.m_hitboxes);

	SetBool(SECTION_TRIGGERBOT, Decrypt(9,40,41,49,45,42,34,46,47,38), m_TriggerSettings.m_bMoveCheck);


	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,61,124,127,96,97), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tP2K.m_nDelayAfter);

	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,124,123,105), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tM249.m_nDelayAfter);




	SetInt(Decrypt(11,49,52,46,47,46,47,57,19,32,62,118), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tMP9.m_nDelayBefore);

	SetCommaSeperatedInts(Decrypt(16,49,52,46,47,46,47,57,19,63,43,57,63,61,36,54,38), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tRevolver.m_hitboxes);
	SetInt(Decrypt(14,49,52,46,47,46,47,57,19,53,35,126,96,96,102), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tXM1014.m_nDelayBefore);

	SetCommaSeperatedInts(Decrypt(15,49,52,46,47,46,47,57,19,61,62,45,57,43,61,61), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tBizon.m_hitboxes);
	SetBool(SECTION_TRIGGERBOT, Decrypt(21,54,54,53,41,48,21,62,34,57,39,35,15,53,55,50,48,10,59,56,60,60), m_TriggerSettings.m_bSprayUntilDeadMode);


	SetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,46,52,120,101), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tCZ75.m_hitboxes);


	SetInt(Decrypt(11,49,52,46,47,46,47,57,19,61,119,127), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tP90.m_nDelayAfter);


	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,32,47,44,97,97), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tMAC10.m_nDelayAfter);


	SetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,35,33,57,49), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tNova.m_hitboxes);
	SetInt(SECTION_TRIGGERBOT, Decrypt(12,49,52,46,47,46,47,57,19,57,55,63,53), m_TriggerSettings.m_nMethod);

	SetInt(Decrypt(15,49,52,46,47,46,47,57,19,61,62,45,57,43,61,61), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tBizon.m_nDelayBefore);

	SetFloat(Decrypt(12,49,52,46,47,46,47,57,19,32,122,46,100), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tM4A4.m_fRCSScale);
	SetCommaSeperatedInts(Decrypt(14,49,52,46,47,46,47,57,19,62,45,46,34,99,98), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tSCAR20.m_hitboxes);
	SetInt(SECTION_TRIGGERBOT, Decrypt(11,49,39,53,47,44,62,20,56,52,62,42), m_TriggerSettings.m_nTargetType);
	SetBool(SECTION_TRIGGERBOT, Decrypt(11,54,40,46,56,44,56,20,33,34,42,42), m_TriggerSettings.m_bSniperMode);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,32,47,44,97,97), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tMAC10.m_nDelayBefore);

	SetInt(Decrypt(14,49,52,46,47,46,47,57,19,53,35,126,96,96,102), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tXM1014.m_nDelayAfter);
	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,56,61,63,35), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tUSP.m_nDelayBefore);
	SetInt(Decrypt(16,49,52,46,47,46,47,57,19,62,47,56,53,53,61,53,50), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tSawedOff.m_nDelayAfter);

	SetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,43,47,34,49,34), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tFAMAS.m_hitboxes);
	SetFloat(Decrypt(12,49,52,46,47,46,47,57,19,57,43,44,105), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tTec9.m_fRCSScale);



	SetCommaSeperatedInts(Decrypt(14,49,52,46,47,46,47,57,19,53,35,126,96,96,102), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tXM1014.m_hitboxes);
	SetFloat(Decrypt(13,49,52,46,47,46,47,57,19,43,47,34,49,34), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tFAMAS.m_fRCSScale);

	SetInt(Decrypt(11,49,52,46,47,46,47,57,19,32,62,120), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tMP7.m_nDelayAfter);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,34,32,51,58), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tGlock.m_nDelayBefore);

	SetFloat(Decrypt(13,49,52,46,47,46,47,57,19,42,34,32,51,58), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tGlock.m_fRCSScale);
	SetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,62,41,122,101,98), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tSG553.m_hitboxes);
	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,47,40,103), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tMag7.m_nDelayBefore);
	SetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,42,34,32,51,58), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tGlock.m_hitboxes);
	SetFloat(Decrypt(14,49,52,46,47,46,47,57,19,41,43,46,55,61,55), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tDeagle.m_fRCSScale);
	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,56,61,63,35), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tUSP.m_nDelayAfter);


	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,44,37,123,103), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tAK47.m_nDelayAfter);
	SetFloat(Decrypt(14,49,52,46,47,46,47,57,19,62,45,46,34,99,98), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tSCAR20.m_fRCSScale);


	SetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,32,47,40,103), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tMag7.m_hitboxes);
	SetFloat(Decrypt(12,49,52,46,47,46,47,57,19,32,124,123,105), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tM249.m_fRCSScale);
	SetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,61,124,127,96,97), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tP2K.m_hitboxes);
	SetCommaSeperatedInts(Decrypt(12,49,52,46,47,46,47,57,19,57,43,44,105), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tTec9.m_hitboxes);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,47,35,57,61), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tGalil.m_nDelayAfter);
	SetInt(Decrypt(17,49,52,46,47,46,47,57,19,43,39,57,53,34,55,37,49,59), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tFiveSeven.m_nDelayAfter);


	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,62,45,32,37,37), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tScout.m_nDelayBefore);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,61,124,127,96,97), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tP2K.m_nDelayBefore);
	SetFloat(Decrypt(13,49,52,46,47,46,47,57,19,62,45,32,37,37), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tScout.m_fRCSScale);


	SetInt(Decrypt(16,49,52,46,47,46,47,57,19,63,43,57,63,61,36,54,38), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tRevolver.m_nDelayAfter);

	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,32,122,46,97,34), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tM4A1S.m_nDelayAfter);
	SetCommaSeperatedInts(Decrypt(11,49,52,46,47,46,47,57,19,61,119,127), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tP90.m_hitboxes);




	SetFloat(Decrypt(13,49,52,46,47,46,47,57,19,62,41,122,101,98), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tSG553.m_fRCSScale);
	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,122,46,100), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tM4A4.m_nDelayAfter);
	SetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,35,43,40,53,39), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tNegev.m_hitboxes);
	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,57,43,44,105), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tTec9.m_nDelayBefore);
	SetBool(SECTION_TRIGGERBOT, Decrypt(9,36,37,51,33,63,43,63,41,41), m_TriggerSettings.m_bActive);
	SetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,32,122,46,97,34), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tM4A1S.m_hitboxes);

	SetFloat(Decrypt(16,49,52,46,47,46,47,57,19,62,47,56,53,53,61,53,50), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tSawedOff.m_fRCSScale);

	SetFloat(Decrypt(12,49,52,46,47,46,47,57,19,46,52,120,101), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tCZ75.m_fRCSScale);

	SetBool(SECTION_TRIGGERBOT, Decrypt(14,55,35,36,39,32,38,20,47,34,32,59,34,62,62), m_TriggerSettings.m_bRecoilControl);




	SetInt(Decrypt(11,49,52,46,47,46,47,57,19,44,57,63), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tAWP.m_nDelayAfter);



	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,35,43,40,53,39), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tNegev.m_nDelayBefore);
	SetInt(Decrypt(20,49,52,46,47,46,47,57,19,41,59,46,60,51,55,33,49,33,34,54,43), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tDuelies.m_nDelayBefore);

	SetFloat(Decrypt(11,49,52,46,47,46,47,57,19,44,59,40), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tAUG.m_fRCSScale);
	SetCommaSeperatedInts(Decrypt(11,49,52,46,47,46,47,57,19,32,62,118), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tMP9.m_hitboxes);

	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,61,124,122,96), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tP250.m_nDelayBefore);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,125,60,55,96), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tG3SG1.m_nDelayBefore);



	SetCommaSeperatedInts(Decrypt(11,49,52,46,47,46,47,57,19,44,59,40), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tAUG.m_hitboxes);





	SetFloat(SECTION_TRIGGERBOT, Decrypt(16,35,42,38,59,33,21,59,41,63,45,42,62,37,51,52,49), m_TriggerSettings.m_fMinFlash);
	SetCommaSeperatedInts(Decrypt(11,49,52,46,47,46,47,57,19,32,62,120), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tMP7.m_hitboxes);


	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,44,37,123,103), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tAK47.m_nDelayBefore);






	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,57,43,44,105), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tTec9.m_nDelayAfter);


	SetInt(Decrypt(14,49,52,46,47,46,47,57,19,62,45,46,34,99,98), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tSCAR20.m_nDelayBefore);
	SetBool(SECTION_TRIGGERBOT, Decrypt(12,36,40,51,33,22,32,62,33,61,39,33,55), m_TriggerSettings.m_bAntiJump);

	SetFloat(Decrypt(17,49,52,46,47,46,47,57,19,43,39,57,53,34,55,37,49,59), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tFiveSeven.m_fRCSScale);
	SetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,32,47,44,97,97), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tMAC10.m_hitboxes);

	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,46,52,120,101), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tCZ75.m_nDelayBefore);


	SetKey(SECTION_TRIGGERBOT, Decrypt(9,49,41,32,47,37,47,32,41,52), m_TriggerSettings.m_nToggleKey);


	SetFloat(Decrypt(13,49,52,46,47,46,47,57,19,35,43,40,53,39), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tNegev.m_fRCSScale);


	SetFloat(Decrypt(13,49,52,46,47,46,47,57,19,42,125,60,55,96), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tG3SG1.m_fRCSScale);


	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,42,125,60,55,96), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tG3SG1.m_nDelayAfter);
	SetCommaSeperatedInts(Decrypt(13,49,52,46,47,46,47,57,19,42,47,35,57,61), Decrypt(8,45,47,51,42,38,50,46,63), m_TriggerSettings.m_tGalil.m_hitboxes);


	SetInt(Decrypt(20,49,52,46,47,46,47,57,19,41,59,46,60,51,55,33,49,33,34,54,43), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tDuelies.m_nDelayAfter);
	SetFloat(Decrypt(20,49,52,46,47,46,47,57,19,41,59,46,60,51,55,33,49,33,34,54,43), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tDuelies.m_fRCSScale);

	SetFloat(Decrypt(12,49,52,46,47,46,47,57,19,35,33,57,49), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tNova.m_fRCSScale);
	SetFloat(Decrypt(14,49,52,46,47,46,47,57,19,53,35,126,96,96,102), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tXM1014.m_fRCSScale);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,35,43,40,53,39), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tNegev.m_nDelayAfter);




	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,32,47,40,103), Decrypt(11,33,35,43,41,48,21,42,42,57,43,61), m_TriggerSettings.m_tMag7.m_nDelayAfter);

	SetInt(Decrypt(12,49,52,46,47,46,47,57,19,35,33,57,49), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tNova.m_nDelayBefore);
	SetInt(Decrypt(13,49,52,46,47,46,47,57,19,43,47,34,49,34), Decrypt(12,33,35,43,41,48,21,41,41,43,33,61,53), m_TriggerSettings.m_tFAMAS.m_nDelayBefore);
	SetFloat(Decrypt(12,49,52,46,47,46,47,57,19,56,61,63,35), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tUSP.m_fRCSScale);

	SetFloat(Decrypt(13,49,52,46,47,46,47,57,19,32,47,44,97,97), Decrypt(12,55,35,36,39,32,38,20,63,46,47,35,53), m_TriggerSettings.m_tMAC10.m_fRCSScale);



	char* QKCRYDWEMP = "QGBYBVAMW";
int AYTFEKMYIG = 0x67C251E5;
bool HXBXNUKQMJ = true;


	return true;

}

// Return an integer
int Config::GetInt(char* section, char* option)
{
	char* GDJGXTELIJ = "MXUKWWCGRFAHJHZCFBJZL";
char PBLSQFEOVP = 'R';
int AXPFPMJOBE = 0x1C7D5CC5;

	return GetPrivateProfileIntA(section, option, NULL, m_szConfigFile.c_str());

}

// Return a float
float Config::GetFloat(char* section, char* option)
{
	char val[255];

	GetPrivateProfileStringA(section, option, NULL, val, sizeof(val), m_szConfigFile.c_str());

	int JLPHGCMZLX = 0x503DCE43;
JLPHGCMZLX = JLPHGCMZLX * JLPHGCMZLX;
JLPHGCMZLX = JLPHGCMZLX - JLPHGCMZLX;

	return (float)atof(val);

}

// Return a string
std::string Config::GetString(char* section, char* option)
{
	char val[255];

	char YXBTMAVXJK = 'O';
float ONXUHPLMPT = 1.85f;
bool DKGQAJAZMI = true;

	GetPrivateProfileStringA(section, option, NULL, val, sizeof(val), m_szConfigFile.c_str());

	return std::string(val);

}

// Return a boolean
bool Config::GetBool(char* section, char* option)
{
	char val[255];

	GetPrivateProfileStringA(section, option, NULL, val, sizeof(val), m_szConfigFile.c_str());

	bool ZWBRXXLXZZ = true;
char JPFXJPCUFW = 'A';
char* PCGXJFRJRR = "WZAFNVTBJXSCSLQFZD";
int PCWRBVQOOU = 0x23E232B5;

	return (!_stricmp(val, Decrypt(2,42,40)));

}

// Return a vector of ints from csvs
std::vector<int> Config::GetCommaSeperatedInts(char * section, char * option)
{
	char val[255];

	GetPrivateProfileStringA(section, option, NULL, val, sizeof(val), m_szConfigFile.c_str());


	std::string str(val);


	std::vector<int> vec;

	char* PYMVQMWZOM = "ZSFQCMAHYKWHFGCDDLSC";
bool VPOBCHFEFV = true;

	std::stringstream ss(str);

	int i;


	while (ss >> i)
	{
		vec.push_back(i);


		float YOMHQLZSRH = 58.33f;
float ISOVJBEDRP = 99.81f;
char VCSOUFJMNQ = 'F';


		if (ss.peek() == ',' || ss.peek() == ' ')
			ss.ignore();

	}

	return vec;

}

int Config::GetKey(char * section, char * option)
{
	int KPVKVSRWMH = 0x20727B15;
float LWIOHMNSLY = 47.28f;
int ASNRPOATNV = 0x1A3F0180;
int GGGNMQVCTW = 0x266400BC;


	char val[255];

	bool DXXYPREYPQ = true;
bool WYADKTIHMF = true;

	GetPrivateProfileStringA(section, option, NULL, val, sizeof(val), m_szConfigFile.c_str());


	std::string str(val);


	char data = str.c_str()[0];


	int HRWJXZETSX = 0x1AD06B74;
HRWJXZETSX = HRWJXZETSX * HRWJXZETSX;
int HFAXFTOCWF = HRWJXZETSX - HRWJXZETSX;
float PJITFYNLFI = 91.65f;


	if ((data >= '0' && data <= '9') || (data >= 'A' && data <= 'Z'))
		return (int)data;


	char* MQUVALWMSF = "QWRKFZZKYJJZYAISPR";
float DEPCVAAIYA = 50.47f;


	if (str == Decrypt(6,40,41,50,59,44,123)) return VK_LBUTTON;

	else if (str == Decrypt(6,40,41,50,59,44,120)) return VK_RBUTTON;

	else if (str == Decrypt(6,40,41,50,59,44,121)) return VK_MBUTTON;

	else if (str == Decrypt(6,40,41,50,59,44,126)) return VK_XBUTTON1;

	else if (str == Decrypt(6,40,41,50,59,44,127)) return VK_XBUTTON2;

	else if (str == Decrypt(9,39,39,36,35,58,58,42,47,40)) return VK_BACK;

	else if (str == Decrypt(3,49,39,37)) return VK_TAB;

	else if (str == Decrypt(5,32,40,51,45,59)) return VK_RETURN;

	else if (str == Decrypt(5,54,46,46,46,61)) return VK_SHIFT;

	else if (str == Decrypt(4,38,50,53,36)) return VK_CONTROL;

	else if (str == Decrypt(3,36,42,51)) return VK_MENU;

	else if (str == Decrypt(8,38,39,55,59,37,37,40,39)) return VK_CAPITAL;

	else if (str == Decrypt(6,32,53,36,41,57,47)) return VK_ESCAPE;

	else if (str == Decrypt(5,54,54,38,43,44)) return VK_SPACE;

	else if (str == Decrypt(4,53,33,50,56)) return VK_PRIOR;

	else if (str == Decrypt(4,53,33,35,38)) return VK_NEXT;

	else if (str == Decrypt(3,32,40,35)) return VK_END;

	else if (str == Decrypt(4,45,41,42,45)) return VK_HOME;

	else if (str == Decrypt(9,41,35,33,60,40,56,57,35,58)) return VK_LEFT;

	else if (str == Decrypt(10,55,47,32,32,61,43,57,62,34,57)) return VK_RIGHT;

	else if (str == Decrypt(7,48,54,38,58,59,37,60)) return VK_UP;

	else if (str == Decrypt(9,33,41,48,38,40,56,57,35,58)) return VK_DOWN;

	else if (str == Decrypt(3,44,40,52)) return VK_INSERT;

	else if (str == Decrypt(3,33,35,43)) return VK_DELETE;

	else if (str == Decrypt(8,43,51,42,56,40,46,20,124)) return VK_NUMPAD0;

	else if (str == Decrypt(8,43,51,42,56,40,46,20,125)) return VK_NUMPAD1;

	else if (str == Decrypt(8,43,51,42,56,40,46,20,126)) return VK_NUMPAD2;

	else if (str == Decrypt(8,43,51,42,56,40,46,20,127)) return VK_NUMPAD3;

	else if (str == Decrypt(8,43,51,42,56,40,46,20,120)) return VK_NUMPAD4;

	else if (str == Decrypt(8,43,51,42,56,40,46,20,121)) return VK_NUMPAD5;

	else if (str == Decrypt(8,43,51,42,56,40,46,20,122)) return VK_NUMPAD6;

	else if (str == Decrypt(8,43,51,42,56,40,46,20,123)) return VK_NUMPAD7;

	else if (str == Decrypt(8,43,51,42,56,40,46,20,116)) return VK_NUMPAD8;

	else if (str == Decrypt(8,43,51,42,56,40,46,20,117)) return VK_NUMPAD9;

	else if (str == Decrypt(11,46,54,24,37,60,38,63,37,61,34,54)) return VK_MULTIPLY;

	else if (str == Decrypt(7,46,54,24,56,37,63,56)) return VK_ADD;

	else if (str == Decrypt(8,46,54,24,37,32,36,62,63)) return VK_SUBTRACT;

	else if (str == Decrypt(8,46,54,24,59,37,43,56,36)) return VK_DIVIDE;

	else if (str == Decrypt(2,35,119)) return VK_F1;

	else if (str == Decrypt(2,35,116)) return VK_F2;

	else if (str == Decrypt(2,35,117)) return VK_F3;

	else if (str == Decrypt(2,35,114)) return VK_F4;

	else if (str == Decrypt(2,35,115)) return VK_F5;

	else if (str == Decrypt(2,35,112)) return VK_F6;

	else if (str == Decrypt(2,35,113)) return VK_F7;

	else if (str == Decrypt(2,35,126)) return VK_F8;

	else if (str == Decrypt(2,35,127)) return VK_F9;

	else if (str == Decrypt(3,35,119,119)) return VK_F10;

	else if (str == Decrypt(3,35,119,118)) return VK_F11;

	else if (str == Decrypt(3,35,119,117)) return VK_F12;

	else if (str == Decrypt(1,126)) return VK_OEM_1;

	else if (str == Decrypt(1,110)) return VK_OEM_PLUS;

	else if (str == Decrypt(1,104)) return VK_OEM_MINUS;

	else if (str == Decrypt(1,105)) return VK_OEM_COMMA;

	else if (str == Decrypt(1,107)) return VK_OEM_PERIOD;

	else if (str == Decrypt(1,106)) return VK_OEM_2;

	else if (str == Decrypt(1,59)) return VK_OEM_3;

	else if (str == Decrypt(1,30)) return VK_OEM_4;

	else if (str == std::to_string(char(0x5C))) return VK_OEM_5;

	else if (str == Decrypt(1,24)) return VK_OEM_6;

	else if (str == std::to_string(char(0x22))) return VK_OEM_7;


	bool EHLKUUKSZB = true;
char* XUCSFEAMRD = "IGVYMDWRWSKVQSWOA";
bool AJMRAWAHZT = true;
char MEUHTXZMOP = 'Y';


	return -1;

}

void Config::SetInt(char* section, char* option, int nValue)
{
	char val[255];

	sprintf_s(val, Decrypt(3,101,99,35), nValue);

	float HKLJTHJCVY = 40.54f;
char HVNAEBRAOJ = 'L';
bool IIMHXDBKAM = true;

	WritePrivateProfileStringA(section, option, val, m_szConfigFile.c_str());

}

void Config::SetFloat(char* section, char* option, float fValue)
{
	char val[255];

	char CUADOWYEDM = 'N';
char* HRRMDNQRJT = "NYLHTTODFWTO";
char LRNITRWUHY = 'Z';

	sprintf_s(val, Decrypt(6,101,99,117,102,120,44), fValue );

	WritePrivateProfileStringA(section, option, val, m_szConfigFile.c_str());

}

void Config::SetString(char* section, char* option, std::string szValue)
{
	WritePrivateProfileStringA(section, option, szValue.c_str(),  m_szConfigFile.c_str());

	char HPNDKBMAHX = 'R';
char UYMKSOGHLA = 'I';
char* XIPCVULEMZ = "FQJFIPAECQYQ";

}

void Config::SetBool(char* section, char* option, bool bValue)
{
	char val[255];

	sprintf_s(val, Decrypt(2,96,53), bValue ? Decrypt(3,101,41,41) : Decrypt(4,101,41,33,46));

	float JLPBFQAIRN = 90.14f;
char* HBSSVQHUJI = "SKVGUZRLCGFBSXXCPPBOURP";
char* KGIZBVFCZZ = "XORFIUDAVYFWUWZJLZBEA";

	WritePrivateProfileStringA(section, option, val, m_szConfigFile.c_str());

}

void Config::SetCommaSeperatedInts(char * section, char * option, std::vector<int> vValue)
{
	std::string input = Decrypt(1,101);


	for (size_t i = 0; i < vValue.size(); i++)

	{
		bool OSWKUBYKXX = true;
float XGKWVKFKOC = 9.15f;

		
		if (i == vValue.size() - 1)
			input += std::to_string(i);

		else
			input += std::to_string(i) + Decrypt(1,105);

	}

	WritePrivateProfileStringA(section, option, input.c_str(), m_szConfigFile.c_str());

}

void Config::SetKey(char * section, char * option, int nKey)
{
	char c[2] = { 0 };

	bool RVNWPFKDLD = true;
bool HAZTKHBMEE = true;
int XADARGNNYL = 0x612DEC64;
bool LAUUSZUDUU = true;


	if ((nKey >= '0' && nKey <= '9') || (nKey >= 'A' && nKey <= 'Z'))
	{
		int AYMZHQHSSY = 0xE9B286E;
int UVGFAPVARJ = AYMZHQHSSY * AYMZHQHSSY;

		c[0] = (char)nKey;

		std::string sweg(c);

		char FMPLLLDKCS = 'B';

		std::transform(sweg.begin(), sweg.end(), sweg.begin(), ::tolower);

		bool JUJYNPJLEX = true;
float WOZYNPXRVD = 43.43f;
char KVBQNDYAMU = 'R';
float KGWQWTHRRV = 61.20f;

		WritePrivateProfileStringA(section, option, sweg.c_str(), m_szConfigFile.c_str());

		return;

	}

	std::string retStr = Decrypt(1,101);

	char* UFWGJBOSNT = "BYUDBXKNGSHUBVTQOFMEJXM";


	switch (nKey)
	{
		case VK_LBUTTON: retStr += Decrypt(6,40,41,50,59,44,123); break;

		case VK_RBUTTON: retStr += Decrypt(6,40,41,50,59,44,120); break;

		case VK_MBUTTON: retStr += Decrypt(6,40,41,50,59,44,121); break;

		case VK_XBUTTON1: retStr += Decrypt(6,40,41,50,59,44,126); break;

		case VK_XBUTTON2: retStr += Decrypt(6,40,41,50,59,44,127); break;

		case VK_BACK: retStr += Decrypt(9,39,39,36,35,58,58,42,47,40); break;

		case VK_TAB: retStr += Decrypt(3,49,39,37); break;

		case VK_RETURN: retStr += Decrypt(5,32,40,51,45,59); break;

		case VK_SHIFT: retStr += Decrypt(5,54,46,46,46,61); break;

		case VK_CONTROL: retStr += Decrypt(4,38,50,53,36); break;

		case VK_MENU: retStr += Decrypt(3,36,42,51); break;

		case VK_CAPITAL: retStr += Decrypt(8,38,39,55,59,37,37,40,39); break;

		case VK_ESCAPE: retStr += Decrypt(6,32,53,36,41,57,47); break;

		case VK_SPACE: retStr += Decrypt(5,54,54,38,43,44); break;

		case VK_PRIOR: retStr += Decrypt(4,53,33,50,56); break;

		case VK_NEXT: retStr += Decrypt(4,53,33,35,38); break;

		case VK_END: retStr += Decrypt(3,32,40,35); break;

		case VK_HOME: retStr += Decrypt(4,45,41,42,45); break;

		case VK_LEFT: retStr += Decrypt(9,41,35,33,60,40,56,57,35,58); break;

		case VK_UP: retStr += Decrypt(7,48,54,38,58,59,37,60); break;

		case VK_DOWN: retStr += Decrypt(9,33,41,48,38,40,56,57,35,58); break;

		case VK_RIGHT: retStr += Decrypt(10,55,47,32,32,61,43,57,62,34,57); break;

		case VK_INSERT: retStr += Decrypt(3,44,40,52); break;

		case VK_DELETE: retStr += Decrypt(3,33,35,43); break;

		case VK_NUMPAD0: retStr += Decrypt(8,43,51,42,56,40,46,20,124); break;

		case VK_NUMPAD1: retStr += Decrypt(8,43,51,42,56,40,46,20,125); break;

		case VK_NUMPAD2: retStr += Decrypt(8,43,51,42,56,40,46,20,126); break;

		case VK_NUMPAD3: retStr += Decrypt(8,43,51,42,56,40,46,20,127); break;

		case VK_NUMPAD4: retStr += Decrypt(8,43,51,42,56,40,46,20,120); break;

		case VK_NUMPAD5: retStr += Decrypt(8,43,51,42,56,40,46,20,121); break;

		case VK_NUMPAD6: retStr += Decrypt(8,43,51,42,56,40,46,20,122); break;

		case VK_NUMPAD7: retStr += Decrypt(8,43,51,42,56,40,46,20,123); break;

		case VK_NUMPAD8: retStr += Decrypt(8,43,51,42,56,40,46,20,116); break;

		case VK_NUMPAD9: retStr += Decrypt(8,43,51,42,56,40,46,20,117); break;

		case VK_MULTIPLY: retStr += Decrypt(11,46,54,24,37,60,38,63,37,61,34,54); break;

		case VK_ADD: retStr += Decrypt(7,46,54,24,56,37,63,56); break;

		case VK_SUBTRACT: retStr += Decrypt(8,46,54,24,37,32,36,62,63); break;

		case VK_DIVIDE: retStr += Decrypt(8,46,54,24,59,37,43,56,36); break;

		case VK_F1: retStr += Decrypt(2,35,119); break;

		case VK_F2: retStr += Decrypt(2,35,116); break;

		case VK_F3: retStr += Decrypt(2,35,117); break;

		case VK_F4: retStr += Decrypt(2,35,114); break;

		case VK_F5: retStr += Decrypt(2,35,115); break;

		case VK_F6: retStr += Decrypt(2,35,112); break;

		case VK_F7: retStr += Decrypt(2,35,113); break;

		case VK_F8: retStr += Decrypt(2,35,126); break;

		case VK_F9: retStr += Decrypt(2,35,127); break;

		case VK_F10: retStr += Decrypt(3,35,119,119); break;

		case VK_F11: retStr += Decrypt(3,35,119,118); break;

		case VK_F12: retStr += Decrypt(3,35,119,117); break;

		case VK_OEM_1: retStr += Decrypt(1,126); break;

		case VK_OEM_PLUS: retStr += Decrypt(1,110); break;

		case VK_OEM_MINUS: retStr += Decrypt(1,104); break;

		case VK_OEM_COMMA: retStr += Decrypt(1,105); break;

		case VK_OEM_PERIOD: retStr += Decrypt(1,107); break;

		case VK_OEM_2: retStr += Decrypt(1,106); break;

		case VK_OEM_3: retStr += Decrypt(1,59); break;

		case VK_OEM_4: retStr += Decrypt(1,30); break;

		case VK_OEM_5: retStr += std::to_string(char(0x5C)); break;

		case VK_OEM_6: retStr += Decrypt(1,24); break;

		case VK_OEM_7: retStr += std::to_string(char(0x22)); break;

		default: retStr += Decrypt(11,48,40,44,38,38,61,37,108,38,43,54); break;

	}

	int OHBFIVKFUM = 0x36CA9DC3;
OHBFIVKFUM = OHBFIVKFUM + OHBFIVKFUM;
int KVGUVAZLPD = OHBFIVKFUM - OHBFIVKFUM;


	if (!retStr.empty())
		WritePrivateProfileStringA(section, option, retStr.c_str(), m_szConfigFile.c_str());

	else
		WritePrivateProfileStringA(section, option, Decrypt(6,101,35,53,58,38,56), m_szConfigFile.c_str());


	char* AGPJGMMKCO = "AJOVUEMVLNVK";
bool EIOIFRQFTE = true;
float RAOTIKYKFO = 79.46f;
char BIYLTJXFVU = 'F';

}


