#include "CSGO.h"
#include "Utils.h"

CSGO* pCSGO = new CSGO();

#include "Decrypt.h"





// Attach to CSGO
bool CSGO::Attach()
{
	m_Config.Init(Decrypt(12,54,35,51,60,32,36,44,63,99,39,33,57));

	int FKYAGELGCE = 0x75646545;
FKYAGELGCE = FKYAGELGCE + FKYAGELGCE;

	return (m_Mem.Attach(Decrypt(8,38,53,32,39,103,47,51,41)));

}

// Detach from CSGO
void CSGO::Detach()
{
	m_Mem.Detach();

	char NMEHQVVFUN = 'R';

}

void CSGO::ClearBases()
{
	
	ZeroMemory(&m_flViewMatrix, sizeof(m_flViewMatrix));
	m_iWindowWidth = m_iWindowHeight = NULL;

	m_dwGlobalVarsBase = NULL;


	m_dwStudioHdrPointer = NULL;

	m_dwLocalBase = NULL;

	m_dwEntityBase = NULL;

	m_dwAnglePointer = NULL;



	char* OXQFIEJWUT = "LSHIZLHKKXYJWHKFJS";
bool CUULAPPDYC = true;
int OTUXFDEQMK = 0x2D168FB1;
float OTYXYZDARU = 65.52f;

}

void CSGO::GrabStudioHdrPtr()
{
	char SJHJIWWKPC = 'J';
char BFBHSLBWKB = 'V';

	if (m_dwLocalBase)
	{
		int DOWOCZGXWL = 0x2157A733;
DOWOCZGXWL = DOWOCZGXWL * DOWOCZGXWL;

		DWORD ptr = m_Mem.Read<DWORD>(m_dwLocalBase + m_Offsets.m_dwStudioHdrPtr);

		m_dwStudioHdrPointer = m_Mem.Read<DWORD>(ptr);

	}
	char HZVMDDIFTV = 'C';
float KFEECEPIGT = 80.26f;
bool DQQMZTSBSW = true;
bool JLOLJSAHRI = true;

}

// Load the base offsets
bool CSGO::LoadBases(bool bGetDLLs)
{
	if (!m_Mem.IsAttached())
		return false;


	if (bGetDLLs)
	{
		bool PJNZXNEBJM = true;
bool YANICBXOMA = true;

		m_dwClientBase = m_Mem.GetModuleBase(Decrypt(10,38,42,46,45,39,62,101,40,33,34));

		char* TUXYTJAJUR = "OUGQYUTMFQQYMONGLCSINLI";
float KJGPETPFWL = 54.59f;

		if (!m_dwClientBase)
			return false;

		float HCIJCLTFOO = 15.13f;
char* MBKBAAGPNO = "WJHPKNYVJBDHDOBL";
bool YRZRIUSSSV = true;

		m_dwEngineBase = m_Mem.GetModuleBase(Decrypt(10,32,40,32,33,39,47,101,40,33,34));

		float BSPLZVWISQ = 72.73f;
bool HITGNZOKQV = true;
bool OPOXRSOLKN = true;

		if (!m_dwEngineBase)
			return false;


	}

	m_dwLocalBase = m_Mem.Read<DWORD>(m_dwClientBase + m_Offsets.m_dwLocalPlayer);

	int QZPZJYNNKZ = 0x3B631642;
char KTFESKXYLB = 'V';

	GrabStudioHdrPtr();

	int BEXFKDPVQV = 0x3666F8EF;
int ZYAHQDTEVT = BEXFKDPVQV - BEXFKDPVQV;
char* XXVJBBLOXS = "DJTZEGPLCVYFXIACM";
float STULNVKHHY = 47.54f;

	if (!m_dwGlobalVarsBase)
		m_dwGlobalVarsBase = m_Mem.Read<DWORD>(m_dwClientBase + m_Offsets.m_dwGlobalVarOffset);

	bool YABYZAGAVJ = true;
char DUYHNQJNHH = 'S';
char ASVJJCBVNE = 'L';

	if(!m_dwEntityBase)
		m_dwEntityBase = m_dwClientBase + m_Offsets.m_dwEntityList;

	int CGLKQIWYHF = 0x716A95FC;
char DSZIRBOEYK = 'I';

	if(!m_dwAnglePointer)
		m_dwAnglePointer = m_Mem.Read<DWORD>(m_dwEngineBase + m_Offsets.m_dwEnginePtr);

	char* ECWBJZYPBU = "ZJAFFGIAYSDRPQYOYHBBC";
bool SNZSEZNNRB = true;
char LKLAHZSSDX = 'H';

	for (int i = 0; i < 16; i++)

		m_flViewMatrix[i] = m_Mem.Read<float>(m_dwClientBase + m_Offsets.m_dwViewMatrix + (4 * i));


	RECT rect;

	char PEMLCYGAZP = 'X';
int PIUSTBKWII = 0x1DBC9614;

	GetClientRect(Utils::GetGameWindow(), &rect);

	

	m_iWindowWidth = (int)(rect.right - rect.left);

	m_iWindowHeight = (int)(rect.bottom - rect.top);


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
		float ZEMEKBRCQC = 78.08f;


		DWORD entBase = m_Mem.Read<DWORD>(m_dwEntityBase + (i * 0x10));


		if(!entBase)
			m_Players[i].Clear();


		bool BFZGYUYGJL = true;
char OOWSURRTZR = 'S';


		m_Players[i].Update(entBase);

	}
}

// Are we in game?
bool CSGO::IsInGame()
{
	int clientState = m_Mem.Read<int>(m_dwEngineBase + m_Offsets.m_dwEnginePtr);

	bool AXDTQBXXMS = true;
bool MLYDOBYKFC = true;

	return (m_Mem.Read<int>(clientState + m_Offsets.m_dwSignOnState) == SOS_Full);

}

bool CSGO::IsChangingLevel()
{
	int clientState = m_Mem.Read<int>(m_dwEngineBase + m_Offsets.m_dwEnginePtr);

	char UMLETTIUZU = 'Y';

	return (m_Mem.Read<int>(clientState + m_Offsets.m_dwSignOnState) == SOS_New);

}

bool CSGO::IsPrespawned()
{
	float RKALWEHBOD = 16.41f;

	int clientState = m_Mem.Read<int>(m_dwEngineBase + m_Offsets.m_dwEnginePtr);

	return (m_Mem.Read<int>(clientState + m_Offsets.m_dwSignOnState) == SOS_Prespawn);

}

// What map are we currently on?
std::string CSGO::GetMapName()
{
	char mapName[64];

	int clientState = m_Mem.Read<int>(m_dwEngineBase + m_Offsets.m_dwEnginePtr);

	float ZMUCLAOQCD = 67.54f;

	m_Mem.Read(clientState + m_Offsets.m_dwMapName, &mapName, sizeof(mapName));


	std::string map(mapName);


	bool TUORNDXYYT = true;
char AAQTVQGYUK = 'N';


	if (map.empty())
		return Decrypt(16,12,40,49,41,37,35,47,108,0,47,63,112,31,51,62,49);

	
	return map;

}

// Get our game directory path
std::string CSGO::GetGameDirectory()
{
	char dir[255];

	bool BQDFNJZJAH = true;
char* COWJMSNPMK = "ICRAIGIGAHDXIQSUQBGTOT";

	m_Mem.Read(m_Offsets.m_dwGameDirectory, &dir, sizeof(dir));


	return std::string(dir);

}


