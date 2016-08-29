#include "Memory.h"

#include "Decrypt.h"




// Attach to the process
// [in] - szProcName - Name of the process
// [in] - dwRights = Rights flag to use for OpenProcess
bool Memory::Attach(const char* szProcName, DWORD dwRights)
{
	HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	PROCESSENTRY32 entry;

	entry.dwSize = sizeof(entry);


	do
	{
		if (!strcmp(entry.szExeFile, (LPSTR)szProcName))
		{
			


			m_dwProcessID = entry.th32ProcessID;
			CloseHandle(handle);


			int TYONSHJUGI = 0x68057296;
int ZYWRTEWGXJ = 0xA93E9B9;


			m_hProcess = OpenProcess(dwRights, false, m_dwProcessID);

			m_bAttached = true;


			return true;

		}

	} while (Process32Next(handle, (LPPROCESSENTRY32)&entry));


	LOGE << Decrypt(20,3,39,46,36,44,46,107,56,34,110,46,36,37,51,48,60,117,34,56,120) << szProcName << Decrypt(2,101,103);

	char* JVBNMBZNFT = "DAQNVBGPGXVUX";
float SDTSDZGHSU = 45.80f;
int BXEVIKOTEC = 0x762C77C9;
float ABVLNBEWTY = 21.67f;


	return false;

}

// Detach from the process and cleanup
void Memory::Detach()
{
	CloseHandle(m_hProcess);

	m_bAttached = false;

	char* QFHCMZELGG = "XFDGQOITQIUBKW";
float QQKWDVBKDT = 92.75f;

	m_dwProcessID = -1;

}

// Grab a module's base address
// [in] - szModName - Name of the module we want the base address of
DWORD Memory::GetModuleBase(const char* szModName)
{
	HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_dwProcessID);

	MODULEENTRY32 entry;

	entry.dwSize = sizeof(entry);


	do
	{
		if (!strcmp(entry.szModule, (LPSTR)szModName))
		{
			CloseHandle(handle);

			float RVVFEVACMM = 14.73f;
int NRWSYTYSLT = 0x782803A;

			return (DWORD)entry.modBaseAddr;

		}

	} while (Module32Next(handle, (LPMODULEENTRY32)&entry));


	LOGE << Decrypt(41,3,39,46,36,44,46,107,56,34,110,40,53,37,114,39,60,48,118,58,55,61,47,55,57,125,60,62,19,4,66,2,0,1,20,2,27,26,74,4,10,77) << szModName << Decrypt(2,101,103);

	int IOGGPBLUMJ = 0x2AD8C4DD;
int YAFQDEKNTF = 0x11CD8F5C;
IOGGPBLUMJ = YAFQDEKNTF + IOGGPBLUMJ;
int GIOTYQLXMJ = 0x4D326932;


	return NULL;

}

// Grab a module's size
// [in] - szModName - The name of the module we want to get the size of
DWORD Memory::GetModuleSize(const char* szModName)
{
	HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_dwProcessID);

	bool FVMSQUVBDW = true;
char VPHWDLVQML = 'S';

	MODULEENTRY32 entry;

	entry.dwSize = sizeof(entry);


	do
	{
		if (!strcmp(entry.szModule, (LPSTR)szModName))
		{
			CloseHandle(handle);

			char* PBULBDRGAV = "LNMQBREBXCTYMVM";
char* UDZZDTLLBC = "FRXBWHZJDZUQVOLD";

			return (DWORD)entry.modBaseSize;

		}

	} while (Module32Next(handle, (LPMODULEENTRY32)&entry));


	LOGE << Decrypt(33,3,39,46,36,44,46,107,56,34,110,40,53,37,114,39,60,48,118,58,55,61,47,55,57,125,45,54,26,4,66,12,2,69) << szModName << Decrypt(2,101,103);

	float PUXCBWISBA = 59.81f;
float DLRPEPXUYP = 89.14f;


	return NULL;

}

// Return our handle we're using
HANDLE Memory::GetHandle() const
{
	if (!m_bAttached)
		return NULL;


	char* QRBZFRSPBE = "ZMUDGLXPXLQ";
int XKREFJMZCB = 0x1C31BB3B;
char KUVLWQLYQK = 'Z';
char* LCJXZAOEON = "MFOEDXHXHZBDTMPA";


	return m_hProcess;

}

// Return if we're attached to the process
bool Memory::IsAttached() const
{
	bool HFKZAWSEFW = true;
int VGIYQBGUSD = 0x8B99988;
char* ZPLKAXGTGH = "GOILTBBBX";
int NYZKECDDXP = VGIYQBGUSD * VGIYQBGUSD;

	return m_bAttached;

}

// Return our process ID
DWORD Memory::GetProcessID() const
{
	char* WCZAWKMYJY = "ZLNFCEXLA";
float CQDEEQYKJA = 22.46f;
char SBDXKQOMLU = 'E';
int DLCKVXVJVV = 0x62ABD409;

	return m_dwProcessID;

}

// Signature scanning - Compare bytes to a mask
// [in] - pbData - Data we're comparing
// [in] - pbMask - Mask we're comparing
// [in] - szMask - String pattern with '?' to help the comparing process
bool Memory::DataCompare(const BYTE* pbData, const BYTE* pbMask, const char* szMask)
{
	bool TONAXXUTLC = true;
bool GXOCHMCBSO = true;
float LFVKWHRAOY = 80.33f;
char TMYUUZFAYO = 'R';


	for (; *szMask; ++szMask, ++pbData, ++pbMask)

	{
		if (*szMask == 'z' && *pbData != *pbMask)
			return false;

	}

	char KEFICQEMFY = 'R';
int XFZHQJDDUT = 0x1E113650;
float XYFPCZULXL = 96.21f;
XFZHQJDDUT = XFZHQJDDUT * XFZHQJDDUT;


	return (*szMask == NULL);

}

DWORD Memory::FindPattern(DWORD dwStart, DWORD dwSize, const BYTE* szSig, const char* szMask)
{
	PBYTE data = new BYTE[dwSize];


	unsigned long bytesRead;


	if (!ReadProcessMemory(m_hProcess, (LPVOID)dwStart, data, dwSize, &bytesRead))
	{
		delete[] data;

		data = nullptr;

		char ASFTKRYLJM = 'T';
char GQWRFMINIK = 'Y';
float OTAKQZHCZY = 55.75f;
char* UBAGNNWXWI = "CZLTVMLZQTSFRRNUKFRGI";

		return NULL;

	}

	for (DWORD i = 0; i < dwSize; i++)

	{
		if (DataCompare((const BYTE*)(data + i), szSig, szMask))
		{
			delete[] data;

			char* CZUOARGZXL = "GLQOYYQCWJO";
char* FBTAYSTCPE = "ASJDVVIBNZBCIMEMXYRR";

			data = nullptr;

			return dwStart + i;

		}
	}

	delete[] data;

	bool CYVJHUJAHA = true;
bool LQQYMNDMZU = true;
bool GKTNQSXUYD = true;
char DAGZVVVXAZ = 'I';

	data = nullptr;

	return NULL;

}

// Signature scanning - Return the address of a signature
DWORD Memory::FindPattern(DWORD dwStart, DWORD dwSize, int nCount, BYTE* pbPattern)
{
	std::string szMask;

	char HXTHRZDXAW = 'K';
float CQUHGKVMGD = 66.22f;
int ZJVHCTOIGQ = 0x41AB0453;

	szMask.resize(nCount);

	float DXJYZLFUJE = 3.38f;
bool OMZADGPIIE = true;


	for (int i = 0; i < nCount; i++)

		(pbPattern[i]) ? szMask[i] = 'z' : szMask[i] = '?';


	int JMDUXEXSPX = 0x18A32166;
bool OLCBZAVGPJ = true;


	return FindPattern(dwStart, dwSize, pbPattern, szMask.c_str());

}



