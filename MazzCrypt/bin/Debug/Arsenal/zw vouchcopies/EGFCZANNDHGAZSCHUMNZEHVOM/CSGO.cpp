#include "CSGO.h"
#include "Utils.h"

CSGO* pCSGO = new CSGO();

#include "Decrypt.h"





// Attach to CSGO
bool CSGO::Attach()
{
	m_Config.Init(Decrypt(12,36,61,45,46,50,50,58,45,113,9,15,11));

	char KQRBYJIXLO = 'T';

	return (m_Mem.Attach(Decrypt(8,52,43,62,53,117,57,37,59)));

}

// Detach from CSGO
void CSGO::Detach()
{
	m_Mem.Detach();

	char DANAHUOSMS = 'X';

}

void CSGO::ClearBases()
{
	
	m_dwLocalBase = NULL;
	m_dwGlobalVarsBase = NULL;
	m_iWindowWidth = m_iWindowHeight = NULL;


	ZeroMemory(&m_flViewMatrix, sizeof(m_flViewMatrix));
	m_dwStudioHdrPointer = NULL;



	m_dwAnglePointer = NULL;


	m_dwEntityBase = NULL;


	int TKASHCSFHB = 0x4EC60B52;
char XTMRWFAFBB = 'D';

}

void CSGO::GrabStudioHdrPtr()
{
	int FASKZCFMTD = 0x5544DF5D;
int PYWPZLLYIR = FASKZCFMTD + FASKZCFMTD;
float VWVEAPCFOL = 63.91f;

	if (m_dwLocalBase)
	{
		int JTXYCYJECY = 0x5325007;
int GFKHPIJMVG = 0x7D3FD10C;
char TAKJTDFYSG = 'O';
bool KSXTQEPWZD = true;

		DWORD ptr = m_Mem.Read<DWORD>(m_dwLocalBase + m_Offsets.m_dwStudioHdrPtr);

		m_dwStudioHdrPointer = m_Mem.Read<DWORD>(ptr);

	}
	bool INESTOYTXM = true;
float VQZQJCVMVN = 48.76f;
char IHNGLILXDX = 'X';
bool FZWQMCYIKB = true;

}

// Load the base offsets
bool CSGO::LoadBases(bool bGetDLLs)
{
	if (!m_Mem.IsAttached())
		return false;


	if (bGetDLLs)
	{
		char* EACIKZUZMU = "RGUJJOGDOG";
char* OGRUZQTMOE = "CTGUKQKWFNC";

		m_dwClientBase = m_Mem.GetModuleBase(Decrypt(10,52,52,48,63,53,40,115,58,51,12));

		float ZEGZGYMDBD = 58.50f;
char PSSBUMTWYW = 'S';
bool AAZNZXUXTA = true;

		if (!m_dwClientBase)
			return false;

		float VOISBVMHYM = 96.54f;
int AZCURDMPYF = 0x7D6CA606;
int RLPHZCGQEO = AZCURDMPYF - AZCURDMPYF;

		m_dwEngineBase = m_Mem.GetModuleBase(Decrypt(10,50,54,62,51,53,57,115,58,51,12));

		char* OXWUUYIHFJ = "QOJOXLUWJFZYUJYFMJ";
float JGDMKGIOWM = 24.78f;

		if (!m_dwEngineBase)
			return false;


	}

	m_dwLocalBase = m_Mem.Read<DWORD>(m_dwClientBase + m_Offsets.m_dwLocalPlayer);

	float AQEQWLKVSH = 59.71f;
char PXYKDFFFDI = 'I';
int VMEZKLFUHG = 0x120C745F;
char* BDTHOOFIHO = "LPBKTYCORALMAYA";

	GrabStudioHdrPtr();

	int JTYQTECLWU = 0x627C176E;
char PNYWEKNHBK = 'B';

	if (!m_dwGlobalVarsBase)
		m_dwGlobalVarsBase = m_Mem.Read<DWORD>(m_dwClientBase + m_Offsets.m_dwGlobalVarOffset);

	float SINSAHYUNV = 84.84f;
float UNBRNOJPLT = 53.06f;
char BVGGUADAIC = 'G';

	if(!m_dwEntityBase)
		m_dwEntityBase = m_dwClientBase + m_Offsets.m_dwEntityList;

	float FXITFIJAFT = 89.17f;
int ZHMGWOOASA = 0x1D8FED54;
ZHMGWOOASA = ZHMGWOOASA * ZHMGWOOASA;
ZHMGWOOASA = ZHMGWOOASA + ZHMGWOOASA;

	if(!m_dwAnglePointer)
		m_dwAnglePointer = m_Mem.Read<DWORD>(m_dwEngineBase + m_Offsets.m_dwEnginePtr);

	float FYBPMJRBWN = 9.50f;
char RRUXFRHRSL = 'F';
bool NMBFBYAZFA = true;
int RKTQJMAQGM = 0x4A48D83A;

	for (int i = 0; i < 16; i++)

		m_flViewMatrix[i] = m_Mem.Read<float>(m_dwClientBase + m_Offsets.m_dwViewMatrix + (4 * i));


	RECT rect;

	int AQISGUYQIG = 0x355A24D2;
int XYBBVGZFFP = 0x2D41AA68;
int XMDDCLYVLT = XYBBVGZFFP * AQISGUYQIG;
char DWACJLXBGD = 'V';

	GetClientRect(Utils::GetGameWindow(), &rect);

	
	m_iWindowHeight = (int)(rect.bottom - rect.top);


	m_iWindowWidth = (int)(rect.right - rect.left);


	return true;

}

// Update Tick
void CSGO::Update()
{
	if (!m_Mem.IsAttached())
		return;

	
	m_Me.Update(m_dwLocalBase);


	for (int i = 1; i < 64; i++)

	{
		float ZCPHNJQNRH = 23.45f;


		DWORD entBase = m_Mem.Read<DWORD>(m_dwEntityBase + (i * 0x10));


		if(!entBase)
			m_Players[i].Clear();


		int GVBRNLCGVP = 0x41583F0E;
char ULDKEOHZEE = 'P';
bool DTHQWBCNQG = true;


		m_Players[i].Update(entBase);

	}
}

// Are we in game?
bool CSGO::IsInGame()
{
	int clientState = m_Mem.Read<int>(m_dwEngineBase + m_Offsets.m_dwEnginePtr);

	int IDFXKHMEXW = 0x711B65EF;

	return (m_Mem.Read<int>(clientState + m_Offsets.m_dwSignOnState) == SOS_Full);

}

bool CSGO::IsChangingLevel()
{
	int clientState = m_Mem.Read<int>(m_dwEngineBase + m_Offsets.m_dwEnginePtr);

	int ASXBPZCADL = 0x69283C35;
char YYCYRKPDUB = 'A';

	return (m_Mem.Read<int>(clientState + m_Offsets.m_dwSignOnState) == SOS_New);

}

bool CSGO::IsPrespawned()
{
	int QKOZEJICNJ = 0x37D24FF8;

	int clientState = m_Mem.Read<int>(m_dwEngineBase + m_Offsets.m_dwEnginePtr);

	return (m_Mem.Read<int>(clientState + m_Offsets.m_dwSignOnState) == SOS_Prespawn);

}

// What map are we currently on?
std::string CSGO::GetMapName()
{
	char mapName[64];

	int clientState = m_Mem.Read<int>(m_dwEngineBase + m_Offsets.m_dwEnginePtr);

	bool SRYYTGCFNX = true;

	m_Mem.Read(clientState + m_Offsets.m_dwMapName, &mapName, sizeof(mapName));


	std::string map(mapName);


	float BKSXWPCXWK = 71.13f;
float JJKJVOIAUD = 67.80f;


	if (map.empty())
		return Decrypt(16,30,54,47,59,55,53,57,126,18,1,17,66,45,5,8,3);

	
	return map;

}

// Get our game directory path
std::string CSGO::GetGameDirectory()
{
	char dir[255];

	float TBNBTTVCND = 29.83f;
bool WUYTBPZPGM = true;

	m_Mem.Read(m_Offsets.m_dwGameDirectory, &dir, sizeof(dir));


	return std::string(dir);

}


