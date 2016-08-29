#include "Config.h"
#include "Utils.h"
#include "Enums.h"
#include <Wincrypt.h>
#include <cctype>
#include <algorithm>
#include <sstream>

#include "Decrypt.h"




#define SECTION_TRIGGERBOT Decrypt(10,35,42,48,61,60,57,47,60,48,20)

// Set the config file
void Config::Init(std::string szConfigName)
{
	m_szConfigFile = szConfigName;


	

	m_TriggerSettings.m_bSniperMode = true;
	m_TriggerSettings.m_fMinSpeed = 25.0f;
	m_TriggerSettings.m_nTargetType = TargetType_Enemies;


	m_TriggerSettings.m_bInvertMouse = false;


	m_TriggerSettings.m_bAntiSpectate = true;
	m_TriggerSettings.m_bSprayUntilDeadMode = true;
	m_TriggerSettings.m_bRecoilControl = true;



	m_TriggerSettings.m_bMoveCheck = true;


	m_TriggerSettings.m_nKey = VK_XBUTTON1;


	m_TriggerSettings.m_fMinFlash = 55.0f;

	m_TriggerSettings.m_bDeathmatch = true;
	m_TriggerSettings.m_nToggleKey = VK_NUMPAD5;


	m_TriggerSettings.m_nMethod = Trigger_Hitbox;
	m_TriggerSettings.m_bKeyHeld = true;

	m_TriggerSettings.m_bAntiJump = false;

	m_TriggerSettings.m_bActive = true;
	m_TriggerSettings.m_bKnifebot = true;

}



// Get hash of the file
std::string Config::GetHash()
{
	HANDLE hFile = CreateFile(m_szConfigFile.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);


	HCRYPTPROV hProv;

	float OMOUEDPLTI = 27.11f;
float RKXIONNICQ = 9.99f;
int LNWLUCXFWE = 0x74043FC3;
int CDRVZMGKML = LNWLUCXFWE * LNWLUCXFWE;

	HCRYPTHASH hHash;


	DWORD cbHash = 16;

	BYTE rgbHash[16];

	CHAR rgbDigits[] = "0123456789abcdef";





	if (hFile == INVALID_HANDLE_VALUE)
	{
		int dwStatus = GetLastError();

		Utils::PrintLine(std::string(Decrypt(21,18,42,43,53,41,124,47,59,62,4,8,12,4,68,12,8,71,70,0,4,2)));

		char HYPYYUNMIA = 'W';
char LEKVCNFDJZ = 'H';

		CloseHandle(hFile);

		return std::string(Decrypt(5,18,10,11,21,9));

	}

	if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
	{
		int dwStatus = GetLastError();

		char IQGCWTVTFA = 'O';

		Utils::PrintLine(std::string(Decrypt(35,18,42,43,53,41,124,60,61,46,21,8,16,10,10,2,70,36,26,16,26,31,45,14,31,26,25,3,23,48,27,27,2,18,0,13)));

		CloseHandle(hFile);

		return std::string(Decrypt(5,18,10,11,21,9));

	}

	if (!CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash))
	{
		int dwStatus = GetLastError();

		Utils::PrintLine(std::string(Decrypt(19,18,42,43,53,41,124,62,44,58,1,21,11,13,3,69,14,6,27,1)));

		CloseHandle(hFile);

		char* LNTVOKIYHR = "DNOHERTUIRJQPC";
bool SNVNCUXAXP = true;
char* TGPRBWDSOQ = "PLWGFMSOPW";
int CUWVOUFZWP = 0x439E4CFB;

		CryptReleaseContext(hProv, 0);

		return std::string(Decrypt(5,18,10,11,21,9));

	}

	BOOL bResult = FALSE;

	DWORD cbRead;

	BYTE rgbFile[1024];


	while (bResult = ReadFile(hFile, rgbFile, 1024, &cbRead, NULL))
	{
		if (!cbRead)
		{
			char* CDBKFCFORN = "BFORDVVGIIN";
float UNBAVIWCZS = 19.99f;
bool XAJQTIGNLR = true;
char WJTNOMOBPO = 'H';

			break;

		}

		if (!CryptHashData(hHash, rgbFile, cbRead, 0))
		{
			int dwStatus = GetLastError();

			Utils::PrintLine(std::string(Decrypt(24,18,42,43,53,41,124,42,55,43,8,65,33,17,29,21,18,47,9,26,2,47,13,25,15)));

			CryptReleaseContext(hProv, 0);

			bool KFIAVTDLEN = true;

			CryptDestroyHash(hHash);

			CloseHandle(hFile);

			return std::string(Decrypt(5,18,10,11,21,9));

		}
	}

	if (!bResult)
	{
		int dwStatus = GetLastError();

		Utils::PrintLine(std::string(Decrypt(15,5,61,56,62,29,53,49,59,127,6,0,11,15,1,1)));

		int LOIONEDEJT = 0x3C88200D;
float ZPKDZKYYQN = 86.24f;
char XRKJZRWBBH = 'C';
bool MDVXGDOPDO = true;

		CryptReleaseContext(hProv, 0);

		CryptDestroyHash(hHash);

		CloseHandle(hFile);

		return std::string(Decrypt(5,18,10,11,21,9));

	}

	std::string hashOutput;


	if (CryptGetHashParam(hHash, HP_HASHVAL, rgbHash, &cbHash, 0))
	{
		for (DWORD i = 0; i < cbHash; i++)

		{
			hashOutput += std::to_string(rgbDigits[rgbHash[i] >> 4]);

			bool BJJFHDTCNY = true;

			hashOutput += std::to_string(rgbDigits[rgbHash[i] & 0xf]);

		}
	}

	CryptReleaseContext(hProv, 0);

	CryptDestroyHash(hHash);

	bool CSGSDPUDMU = true;
float DBQDYWRDTQ = 64.15f;
int KLCFGPCGFY = 0x71AAEDD8;
char* QLOGTNRFYL = "EJQPTAMCEIRNP";

	CloseHandle(hFile);


	return hashOutput;

}

// Load the config
bool Config::LoadConfig()
{
	m_szHash = GetHash();


	char FEYFMGFONX = 'D';


	
	m_TriggerSettings.m_tUSP.m_fRCSScale = GetFloat(Decrypt(12,35,42,48,61,60,57,47,1,42,19,17,17), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tSawedOff.m_nDelayBefore = GetInt(Decrypt(16,35,42,48,61,60,57,47,1,44,1,22,7,7,11,3,0), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tFAMAS.m_fRCSScale = GetFloat(Decrypt(13,35,42,48,61,60,57,47,1,57,1,12,3,16), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));

	m_TriggerSettings.m_tM249.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,50,82,85,91), Decrypt(8,63,49,45,56,52,36,56,45));


	m_TriggerSettings.m_tFiveSeven.m_fRCSScale = GetFloat(Decrypt(17,35,42,48,61,60,57,47,1,57,9,23,7,16,1,19,3,9), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tSG553.m_nDelayBefore = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,44,7,84,87,80), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));


	m_TriggerSettings.m_tMP7.m_hitboxes = GetCommaSeperatedInts(Decrypt(11,35,42,48,61,60,57,47,1,50,16,86), Decrypt(8,63,49,45,56,52,36,56,45));


	m_TriggerSettings.m_tM249.m_nDelayBefore = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,82,85,91), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tDeagle.m_nDelayAfter = GetInt(Decrypt(14,35,42,48,61,60,57,47,1,59,5,0,5,15,1), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));


	m_TriggerSettings.m_tXM1014.m_nDelayBefore = GetInt(Decrypt(14,35,42,48,61,60,57,47,1,39,13,80,82,82,80), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tMP7.m_fRCSScale = GetFloat(Decrypt(11,35,42,48,61,60,57,47,1,50,16,86), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));



	m_TriggerSettings.m_tUMP45.m_nDelayAfter = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,42,13,17,86,86), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tMag7.m_nDelayAfter = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,1,6,85), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tM249.m_fRCSScale = GetFloat(Decrypt(12,35,42,48,61,60,57,47,1,50,82,85,91), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));

	m_TriggerSettings.m_bRecoilControl = GetBool(SECTION_TRIGGERBOT, Decrypt(14,37,61,58,53,50,48,2,61,48,14,21,16,12,8));

	m_TriggerSettings.m_tFiveSeven.m_nDelayBefore = GetInt(Decrypt(17,35,42,48,61,60,57,47,1,57,9,23,7,16,1,19,3,9), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));






	m_TriggerSettings.m_tSG553.m_fRCSScale = GetFloat(Decrypt(13,35,42,48,61,60,57,47,1,44,7,84,87,80), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));



	m_TriggerSettings.m_tMP7.m_nDelayBefore = GetInt(Decrypt(11,35,42,48,61,60,57,47,1,50,16,86), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tP2K.m_nDelayAfter = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,47,82,81,82,83), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));


	m_TriggerSettings.m_tG3SG1.m_nDelayBefore = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,83,18,5,82), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));


	m_TriggerSettings.m_tNova.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,49,15,23,3), Decrypt(8,63,49,45,56,52,36,56,45));


	m_TriggerSettings.m_tTec9.m_nDelayAfter = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,43,5,2,91), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tMAC10.m_nDelayBefore = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,50,1,2,83,83), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_bRevolverMode = GetBool(SECTION_TRIGGERBOT, Decrypt(13,37,61,47,53,55,42,56,44,0,13,14,6,6));
	m_TriggerSettings.m_bKeyHeld = GetBool(SECTION_TRIGGERBOT, Decrypt(7,63,55,53,62,48,57,36));
	m_TriggerSettings.m_tXM1014.m_hitboxes = GetCommaSeperatedInts(Decrypt(14,35,42,48,61,60,57,47,1,39,13,80,82,82,80), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tAK47.m_nDelayBefore = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,62,11,85,85), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tNegev.m_nDelayAfter = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,49,5,6,7,21), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));




	m_TriggerSettings.m_tM4A1S.m_fRCSScale = GetFloat(Decrypt(13,35,42,48,61,60,57,47,1,50,84,0,83,16), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_fMinFlash = GetFloat(SECTION_TRIGGERBOT, Decrypt(16,49,52,56,41,51,3,45,59,45,3,4,12,23,5,2,3));
	m_TriggerSettings.m_tCZ75.m_fRCSScale = GetFloat(Decrypt(12,35,42,48,61,60,57,47,1,60,26,86,87), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_bActive = GetBool(SECTION_TRIGGERBOT, Decrypt(9,54,59,45,51,45,61,41,59,59));





	m_TriggerSettings.m_bAntiSpectate = GetBool(SECTION_TRIGGERBOT, Decrypt(13,54,54,45,51,4,47,45,59,60,20,0,22,6));




	m_TriggerSettings.m_bMoveCheck = GetBool(SECTION_TRIGGERBOT, Decrypt(9,58,55,47,63,56,52,56,61,52));

	m_TriggerSettings.m_tScout.m_nDelayAfter = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,44,3,14,23,23), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tM4A1S.m_nDelayAfter = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,50,84,0,83,16), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tDeagle.m_hitboxes = GetCommaSeperatedInts(Decrypt(14,35,42,48,61,60,57,47,1,59,5,0,5,15,1), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tBizon.m_nDelayBefore = GetInt(Decrypt(15,35,42,48,61,60,57,47,1,47,16,3,11,25,11,11), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tSawedOff.m_nDelayAfter = GetInt(Decrypt(16,35,42,48,61,60,57,47,1,44,1,22,7,7,11,3,0), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tNova.m_fRCSScale = GetFloat(Decrypt(12,35,42,48,61,60,57,47,1,49,15,23,3), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_bInvertMouse = GetBool(SECTION_TRIGGERBOT, Decrypt(13,62,54,47,63,41,40,56,58,50,15,20,17,6));
	m_TriggerSettings.m_tAWP.m_nDelayBefore = GetInt(Decrypt(11,35,42,48,61,60,57,47,1,62,23,17), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));


	m_TriggerSettings.m_tRevolver.m_nDelayBefore = GetInt(Decrypt(16,35,42,48,61,60,57,47,1,45,5,23,13,15,18,0,20), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));

	m_TriggerSettings.m_tG3SG1.m_fRCSScale = GetFloat(Decrypt(13,35,42,48,61,60,57,47,1,56,83,18,5,82), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));



	m_TriggerSettings.m_tAWP.m_hitboxes = GetCommaSeperatedInts(Decrypt(11,35,42,48,61,60,57,47,1,62,23,17), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tMP9.m_hitboxes = GetCommaSeperatedInts(Decrypt(11,35,42,48,61,60,57,47,1,50,16,88), Decrypt(8,63,49,45,56,52,36,56,45));

	m_TriggerSettings.m_tScout.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,44,3,14,23,23), Decrypt(8,63,49,45,56,52,36,56,45));

	m_TriggerSettings.m_tGalil.m_nDelayBefore = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,1,13,11,15), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));

	m_TriggerSettings.m_tDeagle.m_fRCSScale = GetFloat(Decrypt(14,35,42,48,61,60,57,47,1,59,5,0,5,15,1), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));


	m_TriggerSettings.m_nKey = GetKey(SECTION_TRIGGERBOT, Decrypt(3,60,61,32));




	m_TriggerSettings.m_tGalil.m_fRCSScale = GetFloat(Decrypt(13,35,42,48,61,60,57,47,1,56,1,13,11,15), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tScout.m_nDelayBefore = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,44,3,14,23,23), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tP2K.m_nDelayBefore = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,47,82,81,82,83), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));

	m_TriggerSettings.m_tUSP.m_nDelayBefore = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,42,19,17,17), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));





	m_TriggerSettings.m_tFAMAS.m_nDelayBefore = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,57,1,12,3,16), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));

	m_TriggerSettings.m_tGlock.m_nDelayBefore = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,12,14,1,8), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tAK47.m_nDelayAfter = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,62,11,85,85), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tUMP45.m_fRCSScale = GetFloat(Decrypt(13,35,42,48,61,60,57,47,1,42,13,17,86,86), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tG3SG1.m_nDelayAfter = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,83,18,5,82), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tSG553.m_nDelayAfter = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,44,7,84,87,80), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tMP7.m_nDelayAfter = GetInt(Decrypt(11,35,42,48,61,60,57,47,1,50,16,86), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tDeagle.m_nDelayBefore = GetInt(Decrypt(14,35,42,48,61,60,57,47,1,59,5,0,5,15,1), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));

	m_TriggerSettings.m_tScout.m_fRCSScale = GetFloat(Decrypt(13,35,42,48,61,60,57,47,1,44,3,14,23,23), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));

	m_TriggerSettings.m_tTec9.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,43,5,2,91), Decrypt(8,63,49,45,56,52,36,56,45));

	m_TriggerSettings.m_tRevolver.m_nDelayAfter = GetInt(Decrypt(16,35,42,48,61,60,57,47,1,45,5,23,13,15,18,0,20), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tMAC10.m_nDelayAfter = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,50,1,2,83,83), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tSawedOff.m_fRCSScale = GetFloat(Decrypt(16,35,42,48,61,60,57,47,1,44,1,22,7,7,11,3,0), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));





	m_TriggerSettings.m_tSawedOff.m_hitboxes = GetCommaSeperatedInts(Decrypt(16,35,42,48,61,60,57,47,1,44,1,22,7,7,11,3,0), Decrypt(8,63,49,45,56,52,36,56,45));

	m_TriggerSettings.m_tMAC10.m_fRCSScale = GetFloat(Decrypt(13,35,42,48,61,60,57,47,1,50,1,2,83,83), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tNova.m_nDelayBefore = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,49,15,23,3), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tCZ75.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,60,26,86,87), Decrypt(8,63,49,45,56,52,36,56,45));

	m_TriggerSettings.m_tSG553.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,44,7,84,87,80), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tMag7.m_fRCSScale = GetFloat(Decrypt(12,35,42,48,61,60,57,47,1,50,1,6,85), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tM4A4.m_fRCSScale = GetFloat(Decrypt(12,35,42,48,61,60,57,47,1,50,84,0,86), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tAK47.m_fRCSScale = GetFloat(Decrypt(12,35,42,48,61,60,57,47,1,62,11,85,85), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));


	m_TriggerSettings.m_tAWP.m_nDelayAfter = GetInt(Decrypt(11,35,42,48,61,60,57,47,1,62,23,17), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tSCAR20.m_nDelayAfter = GetInt(Decrypt(14,35,42,48,61,60,57,47,1,44,3,0,16,81,84), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tMP9.m_nDelayAfter = GetInt(Decrypt(11,35,42,48,61,60,57,47,1,50,16,88), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tP250.m_nDelayBefore = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,47,82,84,82), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));


	m_TriggerSettings.m_fMinSpeed = GetFloat(SECTION_TRIGGERBOT, Decrypt(8,58,49,55,41,43,57,56,58));


	m_TriggerSettings.m_tAUG.m_nDelayBefore = GetInt(Decrypt(11,35,42,48,61,60,57,47,1,62,21,6), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));




	m_TriggerSettings.m_tNegev.m_fRCSScale = GetFloat(Decrypt(13,35,42,48,61,60,57,47,1,49,5,6,7,21), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));

	m_TriggerSettings.m_tUSP.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,42,19,17,17), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_nMethod = GetInt(SECTION_TRIGGERBOT, Decrypt(12,35,42,48,61,60,57,47,1,43,25,17,7));

	m_TriggerSettings.m_tCZ75.m_nDelayBefore = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,60,26,86,87), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));



	m_TriggerSettings.m_tP250.m_fRCSScale = GetFloat(Decrypt(12,35,42,48,61,60,57,47,1,47,82,84,82), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));

	m_TriggerSettings.m_tNegev.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,49,5,6,7,21), Decrypt(8,63,49,45,56,52,36,56,45));




	m_TriggerSettings.m_tBizon.m_nDelayAfter = GetInt(Decrypt(15,35,42,48,61,60,57,47,1,47,16,3,11,25,11,11), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tGalil.m_nDelayAfter = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,1,13,11,15), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_bSniperMode = GetBool(SECTION_TRIGGERBOT, Decrypt(11,36,54,48,42,62,46,2,51,48,4,4));
	m_TriggerSettings.m_tDuelies.m_hitboxes = GetCommaSeperatedInts(Decrypt(20,35,42,48,61,60,57,47,1,59,21,0,14,1,1,23,3,19,28,8,25), Decrypt(8,63,49,45,56,52,36,56,45));

	m_TriggerSettings.m_tP90.m_hitboxes = GetCommaSeperatedInts(Decrypt(11,35,42,48,61,60,57,47,1,47,89,81), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tUSP.m_nDelayAfter = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,42,19,17,17), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tM4A1S.m_nDelayBefore = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,50,84,0,83,16), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tSCAR20.m_nDelayBefore = GetInt(Decrypt(14,35,42,48,61,60,57,47,1,44,3,0,16,81,84), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tGlock.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,56,12,14,1,8), Decrypt(8,63,49,45,56,52,36,56,45));

	m_TriggerSettings.m_tNegev.m_nDelayBefore = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,49,5,6,7,21), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));





	m_TriggerSettings.m_tDuelies.m_fRCSScale = GetFloat(Decrypt(20,35,42,48,61,60,57,47,1,59,21,0,14,1,1,23,3,19,28,8,25), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tGlock.m_nDelayAfter = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,12,14,1,8), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tAWP.m_fRCSScale = GetFloat(Decrypt(11,35,42,48,61,60,57,47,1,62,23,17), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));


	m_TriggerSettings.m_tRevolver.m_fRCSScale = GetFloat(Decrypt(16,35,42,48,61,60,57,47,1,45,5,23,13,15,18,0,20), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tTec9.m_nDelayBefore = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,43,5,2,91), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_tP90.m_nDelayBefore = GetInt(Decrypt(11,35,42,48,61,60,57,47,1,47,89,81), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));



	m_TriggerSettings.m_tG3SG1.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,56,83,18,5,82), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tP250.m_nDelayAfter = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,47,82,84,82), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tBizon.m_hitboxes = GetCommaSeperatedInts(Decrypt(15,35,42,48,61,60,57,47,1,47,16,3,11,25,11,11), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tAK47.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,62,11,85,85), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tFiveSeven.m_nDelayAfter = GetInt(Decrypt(17,35,42,48,61,60,57,47,1,57,9,23,7,16,1,19,3,9), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tM4A4.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,50,84,0,86), Decrypt(8,63,49,45,56,52,36,56,45));







	m_TriggerSettings.m_tUMP45.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,42,13,17,86,86), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tFiveSeven.m_hitboxes = GetCommaSeperatedInts(Decrypt(17,35,42,48,61,60,57,47,1,57,9,23,7,16,1,19,3,9), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_bSprayUntilDeadMode = GetBool(SECTION_TRIGGERBOT, Decrypt(21,36,40,43,59,34,3,40,48,43,9,13,61,7,1,4,2,56,5,6,14,14));
	m_TriggerSettings.m_tFAMAS.m_nDelayAfter = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,57,1,12,3,16), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tM4A4.m_nDelayAfter = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,84,0,86), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tP90.m_fRCSScale = GetFloat(Decrypt(11,35,42,48,61,60,57,47,1,47,89,81), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tMP9.m_nDelayBefore = GetInt(Decrypt(11,35,42,48,61,60,57,47,1,50,16,88), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));


	m_TriggerSettings.m_tDuelies.m_nDelayAfter = GetInt(Decrypt(20,35,42,48,61,60,57,47,1,59,21,0,14,1,1,23,3,19,28,8,25), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_bDeathmatch = GetBool(SECTION_TRIGGERBOT, Decrypt(15,51,61,56,46,51,49,60,42,60,8,62,15,12,0,0));

	m_TriggerSettings.m_tNova.m_nDelayAfter = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,49,15,23,3), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_nTargetType = GetInt(SECTION_TRIGGERBOT, Decrypt(11,35,57,43,61,62,40,2,42,38,16,4));
	m_TriggerSettings.m_tMag7.m_nDelayBefore = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,1,6,85), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));

	m_TriggerSettings.m_tRevolver.m_hitboxes = GetCommaSeperatedInts(Decrypt(16,35,42,48,61,60,57,47,1,45,5,23,13,15,18,0,20), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tAUG.m_fRCSScale = GetFloat(Decrypt(11,35,42,48,61,60,57,47,1,62,21,6), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));

	m_TriggerSettings.m_tMag7.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,50,1,6,85), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tAUG.m_hitboxes = GetCommaSeperatedInts(Decrypt(11,35,42,48,61,60,57,47,1,62,21,6), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_bAntiJump = GetBool(SECTION_TRIGGERBOT, Decrypt(12,54,54,45,51,4,54,40,51,47,9,15,5));
	m_TriggerSettings.m_tUMP45.m_nDelayBefore = GetInt(Decrypt(13,35,42,48,61,60,57,47,1,42,13,17,86,86), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));

	m_TriggerSettings.m_tAUG.m_nDelayAfter = GetInt(Decrypt(11,35,42,48,61,60,57,47,1,62,21,6), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tMP9.m_fRCSScale = GetFloat(Decrypt(11,35,42,48,61,60,57,47,1,50,16,88), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tGalil.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,56,1,13,11,15), Decrypt(8,63,49,45,56,52,36,56,45));



	m_TriggerSettings.m_tDuelies.m_nDelayBefore = GetInt(Decrypt(20,35,42,48,61,60,57,47,1,59,21,0,14,1,1,23,3,19,28,8,25), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));

	m_TriggerSettings.m_tSCAR20.m_hitboxes = GetCommaSeperatedInts(Decrypt(14,35,42,48,61,60,57,47,1,44,3,0,16,81,84), Decrypt(8,63,49,45,56,52,36,56,45));

	m_TriggerSettings.m_tXM1014.m_nDelayAfter = GetInt(Decrypt(14,35,42,48,61,60,57,47,1,39,13,80,82,82,80), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tMAC10.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,50,1,2,83,83), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tP2K.m_fRCSScale = GetFloat(Decrypt(13,35,42,48,61,60,57,47,1,47,82,81,82,83), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));

	m_TriggerSettings.m_tCZ75.m_nDelayAfter = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,60,26,86,87), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));



	m_TriggerSettings.m_tP250.m_hitboxes = GetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,47,82,84,82), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tP90.m_nDelayAfter = GetInt(Decrypt(11,35,42,48,61,60,57,47,1,47,89,81), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));

	m_TriggerSettings.m_tM4A1S.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,50,84,0,83,16), Decrypt(8,63,49,45,56,52,36,56,45));



	m_TriggerSettings.m_tM249.m_nDelayAfter = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,82,85,91), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19));
	m_TriggerSettings.m_tTec9.m_fRCSScale = GetFloat(Decrypt(12,35,42,48,61,60,57,47,1,43,5,2,91), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tM4A4.m_nDelayBefore = GetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,84,0,86), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7));
	m_TriggerSettings.m_nToggleKey = GetKey(SECTION_TRIGGERBOT, Decrypt(9,35,55,62,61,55,57,54,59,38));


	m_TriggerSettings.m_tBizon.m_fRCSScale = GetFloat(Decrypt(15,35,42,48,61,60,57,47,1,47,16,3,11,25,11,11), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tXM1014.m_fRCSScale = GetFloat(Decrypt(14,35,42,48,61,60,57,47,1,39,13,80,82,82,80), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tFAMAS.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,57,1,12,3,16), Decrypt(8,63,49,45,56,52,36,56,45));
	m_TriggerSettings.m_tGlock.m_fRCSScale = GetFloat(Decrypt(13,35,42,48,61,60,57,47,1,56,12,14,1,8), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));
	m_TriggerSettings.m_tSCAR20.m_fRCSScale = GetFloat(Decrypt(14,35,42,48,61,60,57,47,1,44,3,0,16,81,84), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7));


	m_TriggerSettings.m_tP2K.m_hitboxes = GetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,47,82,81,82,83), Decrypt(8,63,49,45,56,52,36,56,45));


	return true;

}

// Save the config
bool Config::SaveConfig()
{
	


	SetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,60,26,86,87), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tCZ75.m_hitboxes);

	SetFloat(Decrypt(13,35,42,48,61,60,57,47,1,47,82,81,82,83), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tP2K.m_fRCSScale);

	SetFloat(SECTION_TRIGGERBOT, Decrypt(8,58,49,55,41,43,57,56,58), m_TriggerSettings.m_fMinSpeed);


	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,44,3,14,23,23), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tScout.m_nDelayBefore);



	SetFloat(Decrypt(13,35,42,48,61,60,57,47,1,50,84,0,83,16), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tM4A1S.m_fRCSScale);

	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,49,5,6,7,21), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tNegev.m_nDelayBefore);

	SetInt(Decrypt(16,35,42,48,61,60,57,47,1,45,5,23,13,15,18,0,20), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tRevolver.m_nDelayAfter);
	SetBool(SECTION_TRIGGERBOT, Decrypt(21,36,40,43,59,34,3,40,48,43,9,13,61,7,1,4,2,56,5,6,14,14), m_TriggerSettings.m_bSprayUntilDeadMode);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,44,7,84,87,80), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tSG553.m_nDelayBefore);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,42,13,17,86,86), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tUMP45.m_nDelayAfter);

	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,62,11,85,85), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tAK47.m_nDelayAfter);



	SetFloat(Decrypt(12,35,42,48,61,60,57,47,1,50,1,6,85), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tMag7.m_fRCSScale);

	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,47,82,81,82,83), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tP2K.m_nDelayAfter);
	SetCommaSeperatedInts(Decrypt(11,35,42,48,61,60,57,47,1,47,89,81), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tP90.m_hitboxes);
	SetFloat(Decrypt(20,35,42,48,61,60,57,47,1,59,21,0,14,1,1,23,3,19,28,8,25), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tDuelies.m_fRCSScale);


	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,49,5,6,7,21), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tNegev.m_nDelayAfter);
	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,60,26,86,87), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tCZ75.m_nDelayAfter);


	SetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,56,12,14,1,8), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tGlock.m_hitboxes);

	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,1,13,11,15), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tGalil.m_nDelayBefore);
	SetFloat(SECTION_TRIGGERBOT, Decrypt(16,49,52,56,41,51,3,45,59,45,3,4,12,23,5,2,3), m_TriggerSettings.m_fMinFlash);
	SetBool(SECTION_TRIGGERBOT, Decrypt(13,62,54,47,63,41,40,56,58,50,15,20,17,6), m_TriggerSettings.m_bInvertMouse);

	SetFloat(Decrypt(13,35,42,48,61,60,57,47,1,56,12,14,1,8), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tGlock.m_fRCSScale);

	SetFloat(Decrypt(13,35,42,48,61,60,57,47,1,56,1,13,11,15), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tGalil.m_fRCSScale);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,12,14,1,8), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tGlock.m_nDelayAfter);
	SetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,50,1,6,85), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tMag7.m_hitboxes);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,57,1,12,3,16), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tFAMAS.m_nDelayAfter);
	SetFloat(Decrypt(12,35,42,48,61,60,57,47,1,50,82,85,91), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tM249.m_fRCSScale);
	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,47,82,84,82), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tP250.m_nDelayBefore);
	SetBool(SECTION_TRIGGERBOT, Decrypt(13,37,61,47,53,55,42,56,44,0,13,14,6,6), m_TriggerSettings.m_bRevolverMode);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,47,82,81,82,83), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tP2K.m_nDelayBefore);

	SetInt(Decrypt(14,35,42,48,61,60,57,47,1,59,5,0,5,15,1), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tDeagle.m_nDelayAfter);

	SetKey(SECTION_TRIGGERBOT, Decrypt(3,60,61,32), m_TriggerSettings.m_nKey);


	SetInt(Decrypt(11,35,42,48,61,60,57,47,1,47,89,81), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tP90.m_nDelayBefore);

	SetFloat(Decrypt(12,35,42,48,61,60,57,47,1,49,15,23,3), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tNova.m_fRCSScale);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,1,13,11,15), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tGalil.m_nDelayAfter);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,44,7,84,87,80), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tSG553.m_nDelayAfter);

	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,47,82,84,82), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tP250.m_nDelayAfter);
	SetFloat(Decrypt(12,35,42,48,61,60,57,47,1,42,19,17,17), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tUSP.m_fRCSScale);


	SetInt(Decrypt(15,35,42,48,61,60,57,47,1,47,16,3,11,25,11,11), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tBizon.m_nDelayAfter);
	SetFloat(Decrypt(15,35,42,48,61,60,57,47,1,47,16,3,11,25,11,11), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tBizon.m_fRCSScale);
	SetFloat(Decrypt(12,35,42,48,61,60,57,47,1,47,82,84,82), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tP250.m_fRCSScale);



	SetFloat(Decrypt(12,35,42,48,61,60,57,47,1,60,26,86,87), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tCZ75.m_fRCSScale);
	SetFloat(Decrypt(14,35,42,48,61,60,57,47,1,44,3,0,16,81,84), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tSCAR20.m_fRCSScale);


	SetFloat(Decrypt(16,35,42,48,61,60,57,47,1,44,1,22,7,7,11,3,0), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tSawedOff.m_fRCSScale);

	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,43,5,2,91), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tTec9.m_nDelayAfter);
	SetInt(Decrypt(11,35,42,48,61,60,57,47,1,62,23,17), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tAWP.m_nDelayBefore);

	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,50,84,0,83,16), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tM4A1S.m_nDelayBefore);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,50,1,2,83,83), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tMAC10.m_nDelayBefore);





	SetCommaSeperatedInts(Decrypt(11,35,42,48,61,60,57,47,1,62,21,6), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tAUG.m_hitboxes);

	SetCommaSeperatedInts(Decrypt(15,35,42,48,61,60,57,47,1,47,16,3,11,25,11,11), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tBizon.m_hitboxes);

	SetInt(Decrypt(11,35,42,48,61,60,57,47,1,62,21,6), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tAUG.m_nDelayBefore);
	SetFloat(Decrypt(14,35,42,48,61,60,57,47,1,59,5,0,5,15,1), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tDeagle.m_fRCSScale);
	SetFloat(Decrypt(14,35,42,48,61,60,57,47,1,39,13,80,82,82,80), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tXM1014.m_fRCSScale);
	SetFloat(Decrypt(11,35,42,48,61,60,57,47,1,50,16,88), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tMP9.m_fRCSScale);


	SetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,43,5,2,91), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tTec9.m_hitboxes);

	SetBool(SECTION_TRIGGERBOT, Decrypt(12,54,54,45,51,4,54,40,51,47,9,15,5), m_TriggerSettings.m_bAntiJump);
	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,84,0,86), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tM4A4.m_nDelayBefore);
	SetInt(SECTION_TRIGGERBOT, Decrypt(11,35,57,43,61,62,40,2,42,38,16,4), m_TriggerSettings.m_nTargetType);
	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,1,6,85), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tMag7.m_nDelayBefore);

	SetFloat(Decrypt(11,35,42,48,61,60,57,47,1,50,16,86), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tMP7.m_fRCSScale);

	SetCommaSeperatedInts(Decrypt(16,35,42,48,61,60,57,47,1,45,5,23,13,15,18,0,20), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tRevolver.m_hitboxes);
	SetInt(Decrypt(14,35,42,48,61,60,57,47,1,39,13,80,82,82,80), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tXM1014.m_nDelayBefore);
	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,43,5,2,91), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tTec9.m_nDelayBefore);




	SetInt(Decrypt(11,35,42,48,61,60,57,47,1,62,23,17), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tAWP.m_nDelayAfter);
	SetInt(Decrypt(15,35,42,48,61,60,57,47,1,47,16,3,11,25,11,11), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tBizon.m_nDelayBefore);
	SetFloat(Decrypt(12,35,42,48,61,60,57,47,1,62,11,85,85), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tAK47.m_fRCSScale);



	SetBool(SECTION_TRIGGERBOT, Decrypt(11,36,54,48,42,62,46,2,51,48,4,4), m_TriggerSettings.m_bSniperMode);
	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,42,19,17,17), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tUSP.m_nDelayAfter);
	SetCommaSeperatedInts(Decrypt(14,35,42,48,61,60,57,47,1,59,5,0,5,15,1), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tDeagle.m_hitboxes);
	SetBool(SECTION_TRIGGERBOT, Decrypt(7,63,55,53,62,48,57,36), m_TriggerSettings.m_bKeyHeld);


	SetBool(SECTION_TRIGGERBOT, Decrypt(13,54,54,45,51,4,47,45,59,60,20,0,22,6), m_TriggerSettings.m_bAntiSpectate);
	SetFloat(Decrypt(13,35,42,48,61,60,57,47,1,49,5,6,7,21), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tNegev.m_fRCSScale);


	SetBool(SECTION_TRIGGERBOT, Decrypt(9,54,59,45,51,45,61,41,59,59), m_TriggerSettings.m_bActive);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,83,18,5,82), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tG3SG1.m_nDelayAfter);


	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,50,84,0,83,16), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tM4A1S.m_nDelayAfter);
	SetFloat(Decrypt(12,35,42,48,61,60,57,47,1,43,5,2,91), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tTec9.m_fRCSScale);



	SetInt(Decrypt(11,35,42,48,61,60,57,47,1,50,16,86), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tMP7.m_nDelayBefore);

	SetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,50,84,0,83,16), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tM4A1S.m_hitboxes);
	SetInt(Decrypt(14,35,42,48,61,60,57,47,1,39,13,80,82,82,80), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tXM1014.m_nDelayAfter);


	SetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,42,13,17,86,86), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tUMP45.m_hitboxes);





	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,84,0,86), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tM4A4.m_nDelayAfter);


	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,1,6,85), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tMag7.m_nDelayAfter);
	SetFloat(Decrypt(13,35,42,48,61,60,57,47,1,50,1,2,83,83), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tMAC10.m_fRCSScale);
	SetCommaSeperatedInts(Decrypt(14,35,42,48,61,60,57,47,1,44,3,0,16,81,84), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tSCAR20.m_hitboxes);


	SetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,56,1,13,11,15), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tGalil.m_hitboxes);


	SetCommaSeperatedInts(Decrypt(17,35,42,48,61,60,57,47,1,57,9,23,7,16,1,19,3,9), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tFiveSeven.m_hitboxes);
	SetFloat(Decrypt(17,35,42,48,61,60,57,47,1,57,9,23,7,16,1,19,3,9), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tFiveSeven.m_fRCSScale);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,57,1,12,3,16), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tFAMAS.m_nDelayBefore);
	SetBool(SECTION_TRIGGERBOT, Decrypt(15,51,61,56,46,51,49,60,42,60,8,62,15,12,0,0), m_TriggerSettings.m_bDeathmatch);

	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,42,13,17,86,86), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tUMP45.m_nDelayBefore);
	SetInt(Decrypt(11,35,42,48,61,60,57,47,1,47,89,81), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tP90.m_nDelayAfter);

	SetFloat(Decrypt(12,35,42,48,61,60,57,47,1,50,84,0,86), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tM4A4.m_fRCSScale);

	SetInt(Decrypt(11,35,42,48,61,60,57,47,1,50,16,88), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tMP9.m_nDelayBefore);


	SetBool(SECTION_TRIGGERBOT, Decrypt(9,58,55,47,63,56,52,56,61,52), m_TriggerSettings.m_bMoveCheck);




	SetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,44,7,84,87,80), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tSG553.m_hitboxes);
	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,49,15,23,3), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tNova.m_nDelayAfter);

	SetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,49,5,6,7,21), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tNegev.m_hitboxes);



	SetFloat(Decrypt(11,35,42,48,61,60,57,47,1,62,23,17), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tAWP.m_fRCSScale);
	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,42,19,17,17), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tUSP.m_nDelayBefore);
	SetInt(Decrypt(17,35,42,48,61,60,57,47,1,57,9,23,7,16,1,19,3,9), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tFiveSeven.m_nDelayBefore);
	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,82,85,91), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tM249.m_nDelayBefore);
	SetKey(SECTION_TRIGGERBOT, Decrypt(9,35,55,62,61,55,57,54,59,38), m_TriggerSettings.m_nToggleKey);

	SetFloat(Decrypt(13,35,42,48,61,60,57,47,1,44,7,84,87,80), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tSG553.m_fRCSScale);
	SetCommaSeperatedInts(Decrypt(16,35,42,48,61,60,57,47,1,44,1,22,7,7,11,3,0), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tSawedOff.m_hitboxes);





	SetFloat(Decrypt(11,35,42,48,61,60,57,47,1,47,89,81), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tP90.m_fRCSScale);
	SetCommaSeperatedInts(Decrypt(11,35,42,48,61,60,57,47,1,50,16,88), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tMP9.m_hitboxes);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,50,1,2,83,83), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tMAC10.m_nDelayAfter);
	SetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,47,82,81,82,83), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tP2K.m_hitboxes);
	SetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,50,84,0,86), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tM4A4.m_hitboxes);

	SetFloat(Decrypt(13,35,42,48,61,60,57,47,1,57,1,12,3,16), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tFAMAS.m_fRCSScale);
	SetInt(Decrypt(16,35,42,48,61,60,57,47,1,45,5,23,13,15,18,0,20), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tRevolver.m_nDelayBefore);

	SetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,50,82,85,91), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tM249.m_hitboxes);



	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,83,18,5,82), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tG3SG1.m_nDelayBefore);

	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,56,12,14,1,8), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tGlock.m_nDelayBefore);

	SetInt(Decrypt(11,35,42,48,61,60,57,47,1,50,16,88), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tMP9.m_nDelayAfter);


	SetInt(Decrypt(14,35,42,48,61,60,57,47,1,44,3,0,16,81,84), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tSCAR20.m_nDelayBefore);
	SetCommaSeperatedInts(Decrypt(14,35,42,48,61,60,57,47,1,39,13,80,82,82,80), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tXM1014.m_hitboxes);

	SetInt(Decrypt(16,35,42,48,61,60,57,47,1,44,1,22,7,7,11,3,0), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tSawedOff.m_nDelayBefore);


	SetInt(SECTION_TRIGGERBOT, Decrypt(12,35,42,48,61,60,57,47,1,43,25,17,7), m_TriggerSettings.m_nMethod);


	SetFloat(Decrypt(13,35,42,48,61,60,57,47,1,56,83,18,5,82), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tG3SG1.m_fRCSScale);

	SetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,49,15,23,3), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tNova.m_hitboxes);
	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,50,82,85,91), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tM249.m_nDelayAfter);
	SetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,56,83,18,5,82), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tG3SG1.m_hitboxes);

	SetInt(Decrypt(14,35,42,48,61,60,57,47,1,44,3,0,16,81,84), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tSCAR20.m_nDelayAfter);


	SetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,57,1,12,3,16), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tFAMAS.m_hitboxes);
	SetInt(Decrypt(13,35,42,48,61,60,57,47,1,44,3,14,23,23), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tScout.m_nDelayAfter);

	SetCommaSeperatedInts(Decrypt(20,35,42,48,61,60,57,47,1,59,21,0,14,1,1,23,3,19,28,8,25), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tDuelies.m_hitboxes);
	SetInt(Decrypt(16,35,42,48,61,60,57,47,1,44,1,22,7,7,11,3,0), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tSawedOff.m_nDelayAfter);




	SetFloat(Decrypt(16,35,42,48,61,60,57,47,1,45,5,23,13,15,18,0,20), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tRevolver.m_fRCSScale);
	SetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,42,19,17,17), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tUSP.m_hitboxes);
	SetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,47,82,84,82), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tP250.m_hitboxes);

	SetFloat(Decrypt(13,35,42,48,61,60,57,47,1,42,13,17,86,86), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tUMP45.m_fRCSScale);


	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,49,15,23,3), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tNova.m_nDelayBefore);
	SetInt(Decrypt(14,35,42,48,61,60,57,47,1,59,5,0,5,15,1), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tDeagle.m_nDelayBefore);
	SetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,50,1,2,83,83), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tMAC10.m_hitboxes);

	SetInt(Decrypt(11,35,42,48,61,60,57,47,1,50,16,86), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tMP7.m_nDelayAfter);


	SetInt(Decrypt(20,35,42,48,61,60,57,47,1,59,21,0,14,1,1,23,3,19,28,8,25), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tDuelies.m_nDelayBefore);
	SetInt(Decrypt(20,35,42,48,61,60,57,47,1,59,21,0,14,1,1,23,3,19,28,8,25), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tDuelies.m_nDelayAfter);
	SetFloat(Decrypt(11,35,42,48,61,60,57,47,1,62,21,6), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tAUG.m_fRCSScale);


	SetCommaSeperatedInts(Decrypt(11,35,42,48,61,60,57,47,1,50,16,86), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tMP7.m_hitboxes);

	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,60,26,86,87), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tCZ75.m_nDelayBefore);

	SetBool(SECTION_TRIGGERBOT, Decrypt(14,37,61,58,53,50,48,2,61,48,14,21,16,12,8), m_TriggerSettings.m_bRecoilControl);



	SetInt(Decrypt(11,35,42,48,61,60,57,47,1,62,21,6), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tAUG.m_nDelayAfter);

	SetCommaSeperatedInts(Decrypt(12,35,42,48,61,60,57,47,1,62,11,85,85), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tAK47.m_hitboxes);

	SetCommaSeperatedInts(Decrypt(11,35,42,48,61,60,57,47,1,62,23,17), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tAWP.m_hitboxes);
	SetFloat(Decrypt(13,35,42,48,61,60,57,47,1,44,3,14,23,23), Decrypt(12,37,61,58,53,50,48,2,45,60,1,13,7), m_TriggerSettings.m_tScout.m_fRCSScale);



	SetCommaSeperatedInts(Decrypt(13,35,42,48,61,60,57,47,1,44,3,14,23,23), Decrypt(8,63,49,45,56,52,36,56,45), m_TriggerSettings.m_tScout.m_hitboxes);


	SetInt(Decrypt(17,35,42,48,61,60,57,47,1,57,9,23,7,16,1,19,3,9), Decrypt(11,51,61,53,59,34,3,60,56,43,5,19), m_TriggerSettings.m_tFiveSeven.m_nDelayAfter);
	SetInt(Decrypt(12,35,42,48,61,60,57,47,1,62,11,85,85), Decrypt(12,51,61,53,59,34,3,63,59,57,15,19,7), m_TriggerSettings.m_tAK47.m_nDelayBefore);









	char* MGKADFJWVO = "PHXAMQOUHNZIBGA";
bool MDHURTEPRS = true;


	return true;

}

// Return an integer
int Config::GetInt(char* section, char* option)
{
	int CFWWVJAKEE = 0x6DC2D20D;
int HJTMFBEKTL = 0x19DD1A86;
bool BZCYMDICTJ = true;

	return GetPrivateProfileIntA(section, option, NULL, m_szConfigFile.c_str());

}

// Return a float
float Config::GetFloat(char* section, char* option)
{
	char val[255];

	GetPrivateProfileStringA(section, option, NULL, val, sizeof(val), m_szConfigFile.c_str());

	bool CCZHSBKSRC = true;
char* TMEJMTWTLV = "SUFQKCZVZACI";

	return (float)atof(val);

}

// Return a string
std::string Config::GetString(char* section, char* option)
{
	char val[255];

	char* IQFHUGNNKA = "RHLKQDBXDUWFBOYAW";
bool JECGJQKWBH = true;

	GetPrivateProfileStringA(section, option, NULL, val, sizeof(val), m_szConfigFile.c_str());

	return std::string(val);

}

// Return a boolean
bool Config::GetBool(char* section, char* option)
{
	char val[255];

	GetPrivateProfileStringA(section, option, NULL, val, sizeof(val), m_szConfigFile.c_str());

	float CGNSDECPSM = 43.58f;
int SWGQSBVMKX = 0x659DBA51;
int TTHIGQGZVT = 0x2ED8F60B;
SWGQSBVMKX = TTHIGQGZVT - TTHIGQGZVT;

	return (!_stricmp(val, Decrypt(2,56,54)));

}

// Return a vector of ints from csvs
std::vector<int> Config::GetCommaSeperatedInts(char * section, char * option)
{
	char val[255];

	GetPrivateProfileStringA(section, option, NULL, val, sizeof(val), m_szConfigFile.c_str());


	std::string str(val);


	std::vector<int> vec;

	bool NSIEEMNZBK = true;

	std::stringstream ss(str);

	int i;


	while (ss >> i)
	{
		vec.push_back(i);


		int SIUBNTYXUR = 0x2424ED11;
SIUBNTYXUR = SIUBNTYXUR - SIUBNTYXUR;
char UQKMYERXUL = 'X';
char* YICOGWMVZY = "FKLRFXJZSVGCYI";


		if (ss.peek() == ',' || ss.peek() == ' ')
			ss.ignore();

	}

	return vec;

}

int Config::GetKey(char * section, char * option)
{
	int DITLKFVNBD = 0x35DD401B;


	char val[255];

	float AGOSZRXCXC = 63.75f;
bool GEGDMKTWQP = true;
int GWRWFOHMKL = 0x746D05F6;
float CJGGVJTNPI = 81.04f;

	GetPrivateProfileStringA(section, option, NULL, val, sizeof(val), m_szConfigFile.c_str());


	std::string str(val);


	char data = str.c_str()[0];


	char VGEOWHKQJT = 'K';
char THIBEQGWMJ = 'N';
float AEZJFJMOPG = 76.45f;


	if ((data >= '0' && data <= '9') || (data >= 'A' && data <= 'Z'))
		return (int)data;


	char* BSFIRQDHTW = "ZSSOHULTQORIBLAHVQM";
float GKSONRESWK = 69.75f;
char* DRGQTZILII = "WKKDXQJH";


	if (str == Decrypt(6,58,55,44,41,62,109)) return VK_LBUTTON;

	else if (str == Decrypt(6,58,55,44,41,62,110)) return VK_RBUTTON;

	else if (str == Decrypt(6,58,55,44,41,62,111)) return VK_MBUTTON;

	else if (str == Decrypt(6,58,55,44,41,62,104)) return VK_XBUTTON1;

	else if (str == Decrypt(6,58,55,44,41,62,105)) return VK_XBUTTON2;

	else if (str == Decrypt(9,53,57,58,49,40,44,60,61,58)) return VK_BACK;

	else if (str == Decrypt(3,35,57,59)) return VK_TAB;

	else if (str == Decrypt(5,50,54,45,63,41)) return VK_RETURN;

	else if (str == Decrypt(5,36,48,48,60,47)) return VK_SHIFT;

	else if (str == Decrypt(4,52,44,43,54)) return VK_CONTROL;

	else if (str == Decrypt(3,54,52,45)) return VK_MENU;

	else if (str == Decrypt(8,52,57,41,41,55,51,62,53)) return VK_CAPITAL;

	else if (str == Decrypt(6,50,43,58,59,43,57)) return VK_ESCAPE;

	else if (str == Decrypt(5,36,40,56,57,62)) return VK_SPACE;

	else if (str == Decrypt(4,39,63,44,42)) return VK_PRIOR;

	else if (str == Decrypt(4,39,63,61,52)) return VK_NEXT;

	else if (str == Decrypt(3,50,54,61)) return VK_END;

	else if (str == Decrypt(4,63,55,52,63)) return VK_HOME;

	else if (str == Decrypt(9,59,61,63,46,58,46,47,49,40)) return VK_LEFT;

	else if (str == Decrypt(10,37,49,62,50,47,61,47,44,48,23)) return VK_RIGHT;

	else if (str == Decrypt(7,34,40,56,40,41,51,42)) return VK_UP;

	else if (str == Decrypt(9,51,55,46,52,58,46,47,49,40)) return VK_DOWN;

	else if (str == Decrypt(3,62,54,42)) return VK_INSERT;

	else if (str == Decrypt(3,51,61,53)) return VK_DELETE;

	else if (str == Decrypt(8,57,45,52,42,58,56,2,110)) return VK_NUMPAD0;

	else if (str == Decrypt(8,57,45,52,42,58,56,2,111)) return VK_NUMPAD1;

	else if (str == Decrypt(8,57,45,52,42,58,56,2,108)) return VK_NUMPAD2;

	else if (str == Decrypt(8,57,45,52,42,58,56,2,109)) return VK_NUMPAD3;

	else if (str == Decrypt(8,57,45,52,42,58,56,2,106)) return VK_NUMPAD4;

	else if (str == Decrypt(8,57,45,52,42,58,56,2,107)) return VK_NUMPAD5;

	else if (str == Decrypt(8,57,45,52,42,58,56,2,104)) return VK_NUMPAD6;

	else if (str == Decrypt(8,57,45,52,42,58,56,2,105)) return VK_NUMPAD7;

	else if (str == Decrypt(8,57,45,52,42,58,56,2,102)) return VK_NUMPAD8;

	else if (str == Decrypt(8,57,45,52,42,58,56,2,103)) return VK_NUMPAD9;

	else if (str == Decrypt(11,60,40,6,55,46,48,41,55,47,12,24)) return VK_MULTIPLY;

	else if (str == Decrypt(7,60,40,6,42,55,41,46)) return VK_ADD;

	else if (str == Decrypt(8,60,40,6,55,50,50,40,45)) return VK_SUBTRACT;

	else if (str == Decrypt(8,60,40,6,41,55,61,46,54)) return VK_DIVIDE;

	else if (str == Decrypt(2,49,105)) return VK_F1;

	else if (str == Decrypt(2,49,106)) return VK_F2;

	else if (str == Decrypt(2,49,107)) return VK_F3;

	else if (str == Decrypt(2,49,108)) return VK_F4;

	else if (str == Decrypt(2,49,109)) return VK_F5;

	else if (str == Decrypt(2,49,110)) return VK_F6;

	else if (str == Decrypt(2,49,111)) return VK_F7;

	else if (str == Decrypt(2,49,96)) return VK_F8;

	else if (str == Decrypt(2,49,97)) return VK_F9;

	else if (str == Decrypt(3,49,105,105)) return VK_F10;

	else if (str == Decrypt(3,49,105,104)) return VK_F11;

	else if (str == Decrypt(3,49,105,107)) return VK_F12;

	else if (str == Decrypt(1,108)) return VK_OEM_1;

	else if (str == Decrypt(1,124)) return VK_OEM_PLUS;

	else if (str == Decrypt(1,122)) return VK_OEM_MINUS;

	else if (str == Decrypt(1,123)) return VK_OEM_COMMA;

	else if (str == Decrypt(1,121)) return VK_OEM_PERIOD;

	else if (str == Decrypt(1,120)) return VK_OEM_2;

	else if (str == Decrypt(1,41)) return VK_OEM_3;

	else if (str == Decrypt(1,12)) return VK_OEM_4;

	else if (str == std::to_string(char(0x5C))) return VK_OEM_5;

	else if (str == Decrypt(1,10)) return VK_OEM_6;

	else if (str == std::to_string(char(0x22))) return VK_OEM_7;


	float SYQUNMQCPM = 94.00f;
int SECTSFNYPR = 0x5B372BA;
float IYXJTWSLDC = 78.77f;
int GTASQMWRYF = SECTSFNYPR * SECTSFNYPR;


	return -1;

}

void Config::SetInt(char* section, char* option, int nValue)
{
	char val[255];

	sprintf_s(val, Decrypt(3,119,125,61), nValue);

	bool YEREGSBHHA = true;

	WritePrivateProfileStringA(section, option, val, m_szConfigFile.c_str());

}

void Config::SetFloat(char* section, char* option, float fValue)
{
	char val[255];

	char RVRJXNSQAS = 'I';
char* PZJDFSNACP = "UZPEORYGQCZBFJOEG";

	sprintf_s(val, Decrypt(6,119,125,107,116,106,58), fValue );

	WritePrivateProfileStringA(section, option, val, m_szConfigFile.c_str());

}

void Config::SetString(char* section, char* option, std::string szValue)
{
	WritePrivateProfileStringA(section, option, szValue.c_str(),  m_szConfigFile.c_str());

	bool QNHUOYBWQD = true;
float TDAUVUYYME = 84.20f;

}

void Config::SetBool(char* section, char* option, bool bValue)
{
	char val[255];

	sprintf_s(val, Decrypt(2,114,43), bValue ? Decrypt(3,119,55,55) : Decrypt(4,119,55,63,60));

	float BEAVJUDETO = 45.42f;
float EFATFNNFZL = 94.45f;
char* VZEHMRKTZK = "RQHMWQZG";

	WritePrivateProfileStringA(section, option, val, m_szConfigFile.c_str());

}

void Config::SetCommaSeperatedInts(char * section, char * option, std::vector<int> vValue)
{
	std::string input = Decrypt(1,119);


	for (size_t i = 0; i < vValue.size(); i++)

	{
		bool MLQKOIOQGO = true;
char* PWSBESQTEI = "XAQPAETBQ";
char KUABZFQVKL = 'C';
char CGTHFASNBP = 'E';

		
		if (i == vValue.size() - 1)
			input += std::to_string(i);

		else
			input += std::to_string(i) + Decrypt(1,123);

	}

	WritePrivateProfileStringA(section, option, input.c_str(), m_szConfigFile.c_str());

}

void Config::SetKey(char * section, char * option, int nKey)
{
	char c[2] = { 0 };

	float MNMJFFBRZF = 50.11f;
int DVQSIPIXGX = 0x78887620;
char* MXVNUCHCKL = "RPECRWYLTAJDDSXEOZAJLGDV";


	if ((nKey >= '0' && nKey <= '9') || (nKey >= 'A' && nKey <= 'Z'))
	{
		char* KEMQUQGROG = "MMYJWILD";
bool SVWYSCJBNK = true;
char* CGMTYDGSXL = "RECNCZOXSS";
char SPHOXRGEDD = 'U';

		c[0] = (char)nKey;

		std::string sweg(c);

		char* PYFFKWGQFU = "PHCYMTRWNXMJFOLSIA";

		std::transform(sweg.begin(), sweg.end(), sweg.begin(), ::tolower);

		bool HRKQSMHJLY = true;
bool GCZCFQAANS = true;

		WritePrivateProfileStringA(section, option, sweg.c_str(), m_szConfigFile.c_str());

		return;

	}

	std::string retStr = Decrypt(1,119);

	char* NCZKPZLMPD = "WMEODHCTVJEMIT";
char* HUJLXWUQAP = "SZAFMPVGMUUTNKFAL";
bool MAWARVIRSZ = true;


	switch (nKey)
	{
		case VK_LBUTTON: retStr += Decrypt(6,58,55,44,41,62,109); break;

		case VK_RBUTTON: retStr += Decrypt(6,58,55,44,41,62,110); break;

		case VK_MBUTTON: retStr += Decrypt(6,58,55,44,41,62,111); break;

		case VK_XBUTTON1: retStr += Decrypt(6,58,55,44,41,62,104); break;

		case VK_XBUTTON2: retStr += Decrypt(6,58,55,44,41,62,105); break;

		case VK_BACK: retStr += Decrypt(9,53,57,58,49,40,44,60,61,58); break;

		case VK_TAB: retStr += Decrypt(3,35,57,59); break;

		case VK_RETURN: retStr += Decrypt(5,50,54,45,63,41); break;

		case VK_SHIFT: retStr += Decrypt(5,36,48,48,60,47); break;

		case VK_CONTROL: retStr += Decrypt(4,52,44,43,54); break;

		case VK_MENU: retStr += Decrypt(3,54,52,45); break;

		case VK_CAPITAL: retStr += Decrypt(8,52,57,41,41,55,51,62,53); break;

		case VK_ESCAPE: retStr += Decrypt(6,50,43,58,59,43,57); break;

		case VK_SPACE: retStr += Decrypt(5,36,40,56,57,62); break;

		case VK_PRIOR: retStr += Decrypt(4,39,63,44,42); break;

		case VK_NEXT: retStr += Decrypt(4,39,63,61,52); break;

		case VK_END: retStr += Decrypt(3,50,54,61); break;

		case VK_HOME: retStr += Decrypt(4,63,55,52,63); break;

		case VK_LEFT: retStr += Decrypt(9,59,61,63,46,58,46,47,49,40); break;

		case VK_UP: retStr += Decrypt(7,34,40,56,40,41,51,42); break;

		case VK_DOWN: retStr += Decrypt(9,51,55,46,52,58,46,47,49,40); break;

		case VK_RIGHT: retStr += Decrypt(10,37,49,62,50,47,61,47,44,48,23); break;

		case VK_INSERT: retStr += Decrypt(3,62,54,42); break;

		case VK_DELETE: retStr += Decrypt(3,51,61,53); break;

		case VK_NUMPAD0: retStr += Decrypt(8,57,45,52,42,58,56,2,110); break;

		case VK_NUMPAD1: retStr += Decrypt(8,57,45,52,42,58,56,2,111); break;

		case VK_NUMPAD2: retStr += Decrypt(8,57,45,52,42,58,56,2,108); break;

		case VK_NUMPAD3: retStr += Decrypt(8,57,45,52,42,58,56,2,109); break;

		case VK_NUMPAD4: retStr += Decrypt(8,57,45,52,42,58,56,2,106); break;

		case VK_NUMPAD5: retStr += Decrypt(8,57,45,52,42,58,56,2,107); break;

		case VK_NUMPAD6: retStr += Decrypt(8,57,45,52,42,58,56,2,104); break;

		case VK_NUMPAD7: retStr += Decrypt(8,57,45,52,42,58,56,2,105); break;

		case VK_NUMPAD8: retStr += Decrypt(8,57,45,52,42,58,56,2,102); break;

		case VK_NUMPAD9: retStr += Decrypt(8,57,45,52,42,58,56,2,103); break;

		case VK_MULTIPLY: retStr += Decrypt(11,60,40,6,55,46,48,41,55,47,12,24); break;

		case VK_ADD: retStr += Decrypt(7,60,40,6,42,55,41,46); break;

		case VK_SUBTRACT: retStr += Decrypt(8,60,40,6,55,50,50,40,45); break;

		case VK_DIVIDE: retStr += Decrypt(8,60,40,6,41,55,61,46,54); break;

		case VK_F1: retStr += Decrypt(2,49,105); break;

		case VK_F2: retStr += Decrypt(2,49,106); break;

		case VK_F3: retStr += Decrypt(2,49,107); break;

		case VK_F4: retStr += Decrypt(2,49,108); break;

		case VK_F5: retStr += Decrypt(2,49,109); break;

		case VK_F6: retStr += Decrypt(2,49,110); break;

		case VK_F7: retStr += Decrypt(2,49,111); break;

		case VK_F8: retStr += Decrypt(2,49,96); break;

		case VK_F9: retStr += Decrypt(2,49,97); break;

		case VK_F10: retStr += Decrypt(3,49,105,105); break;

		case VK_F11: retStr += Decrypt(3,49,105,104); break;

		case VK_F12: retStr += Decrypt(3,49,105,107); break;

		case VK_OEM_1: retStr += Decrypt(1,108); break;

		case VK_OEM_PLUS: retStr += Decrypt(1,124); break;

		case VK_OEM_MINUS: retStr += Decrypt(1,122); break;

		case VK_OEM_COMMA: retStr += Decrypt(1,123); break;

		case VK_OEM_PERIOD: retStr += Decrypt(1,121); break;

		case VK_OEM_2: retStr += Decrypt(1,120); break;

		case VK_OEM_3: retStr += Decrypt(1,41); break;

		case VK_OEM_4: retStr += Decrypt(1,12); break;

		case VK_OEM_5: retStr += std::to_string(char(0x5C)); break;

		case VK_OEM_6: retStr += Decrypt(1,10); break;

		case VK_OEM_7: retStr += std::to_string(char(0x22)); break;

		default: retStr += Decrypt(11,34,54,50,52,52,43,51,126,52,5,24); break;

	}

	float UGVGJWWVOO = 97.05f;


	if (!retStr.empty())
		WritePrivateProfileStringA(section, option, retStr.c_str(), m_szConfigFile.c_str());

	else
		WritePrivateProfileStringA(section, option, Decrypt(6,119,61,43,40,52,46), m_szConfigFile.c_str());


	char* KJYZCHQMZK = "TGCMXYGHYOKRWSRQZKA";
int JVVNSICZJE = 0x649B9F16;
float DQSCQAADSU = 1.32f;

}


