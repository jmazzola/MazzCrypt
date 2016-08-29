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
			

			CloseHandle(handle);

			m_dwProcessID = entry.th32ProcessID;


			char* MSJLIETVUB = "OVSFJAKP";
char BRAIOPXSVR = 'A';


			m_hProcess = OpenProcess(dwRights, false, m_dwProcessID);

			m_bAttached = true;


			return true;

		}

	} while (Process32Next(handle, (LPPROCESSENTRY32)&entry));


	LOGE << Decrypt(20,17,57,48,54,62,56,125,42,48,64,0,22,23,5,6,14,71,28,6,74) << szProcName << Decrypt(2,119,121);

	char BLJRCRUVKL = 'V';
char* EYBTHUSBXS = "BADBOAZAMDSI";


	return false;

}

// Detach from the process and cleanup
void Memory::Detach()
{
	CloseHandle(m_hProcess);

	m_bAttached = false;

	char* NTFMWMMCKU = "XAEKJEHRZQFUKKJEM";
float XUWFJNEMUE = 51.28f;
float ZEGKDLZHZZ = 67.63f;

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

			int NHAMNZSRQQ = 0x219554E1;
int EIRBNAGXFE = 0x4F82C604;
NHAMNZSRQQ = EIRBNAGXFE - NHAMNZSRQQ;
bool RFQMQGSLVI = true;

			return (DWORD)entry.modBaseAddr;

		}

	} while (Module32Next(handle, (LPMODULEENTRY32)&entry));


	LOGE << Decrypt(41,17,57,48,54,62,56,125,42,48,64,6,7,23,68,17,14,2,72,4,5,15,25,1,11,79,18,16,1,22,84,20,18,19,10,28,9,8,92,18,24,95) << szModName << Decrypt(2,119,121);

	char AGKUVPCVWQ = 'X';
float BYLBFRLYSE = 42.07f;
char HVBXENHNNJ = 'R';


	return NULL;

}

// Grab a module's size
// [in] - szModName - The name of the module we want to get the size of
DWORD Memory::GetModuleSize(const char* szModName)
{
	HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_dwProcessID);

	char* JBRHMHIVJV = "OKYELFAFQJKXVVDRJWNXDHR";
char IOIFLSZZEV = 'M';
char* QYYVXTHSYC = "QPNBGPCEOSMBIFSRPSAX";
bool SPYRSJBRXQ = true;

	MODULEENTRY32 entry;

	entry.dwSize = sizeof(entry);


	do
	{
		if (!strcmp(entry.szModule, (LPSTR)szModName))
		{
			CloseHandle(handle);

			int SAXFWNNLKC = 0x551D7BE2;
SAXFWNNLKC = SAXFWNNLKC + SAXFWNNLKC;

			return (DWORD)entry.modBaseSize;

		}

	} while (Module32Next(handle, (LPMODULEENTRY32)&entry));


	LOGE << Decrypt(33,17,57,48,54,62,56,125,42,48,64,6,7,23,68,17,14,2,72,4,5,15,25,1,11,79,3,24,8,22,84,26,16,87) << szModName << Decrypt(2,119,121);

	bool JAYECMHPRW = true;
char* RYBDDCIUBF = "RHBOQQJNLGGWVO";
char AGQJZZVWTZ = 'S';
char* EPNNQDQHWB = "QZIIYBKBFPVCCESGJVLHOYGE";


	return NULL;

}

// Return our handle we're using
HANDLE Memory::GetHandle() const
{
	if (!m_bAttached)
		return NULL;


	float TEHLYHAJQR = 89.62f;
bool JXMUJNLJYW = true;
char* LTJRTEKAIU = "BHKDUEIPSYQYR";
char* MVKMKRWXWZ = "YIQMGWMOOKM";


	return m_hProcess;

}

// Return if we're attached to the process
bool Memory::IsAttached() const
{
	float FPHONUVSFG = 33.32f;
char* BEKCBAWAVF = "OIJEKFDJE";
char JOLCGBOLUJ = 'W';

	return m_bAttached;

}

// Return our process ID
DWORD Memory::GetProcessID() const
{
	char* QLPDGMZSSB = "VCFOQSIXESQYAVYHOAVEJFX";
float ZQZDSHRVJE = 40.74f;

	return m_dwProcessID;

}

// Signature scanning - Compare bytes to a mask
// [in] - pbData - Data we're comparing
// [in] - pbMask - Mask we're comparing
// [in] - szMask - String pattern with '?' to help the comparing process
bool Memory::DataCompare(const BYTE* pbData, const BYTE* pbMask, const char* szMask)
{
	char* RWWOQEQPAS = "FWBUPVLZXQW";
char QBGEONBSWN = 'W';
bool FWUWIGUVRF = true;


	for (; *szMask; ++szMask, ++pbData, ++pbMask)

	{
		if (*szMask == 'z' && *pbData != *pbMask)
			return false;

	}

	int ZAJRABWDER = 0x15953EED;
int IZELIQGVNH = ZAJRABWDER - ZAJRABWDER;


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

		char* XMGOULSEVK = "XPWAIJOAMJJPBUZXRQJFPBW";
char* RCFWVMSDAE = "TWPWTNLQBOXETUNAOLEI";

		return NULL;

	}

	for (DWORD i = 0; i < dwSize; i++)

	{
		if (DataCompare((const BYTE*)(data + i), szSig, szMask))
		{
			delete[] data;

			char ESFAQFPXAF = 'B';
int TQSDKUUTXL = 0x5FF2814;
char SVVXAIFQPU = 'G';

			data = nullptr;

			return dwStart + i;

		}
	}

	delete[] data;

	char SPMYVVMELY = 'S';
float ISRXOLMUCD = 18.20f;

	data = nullptr;

	return NULL;

}

// Signature scanning - Return the address of a signature
DWORD Memory::FindPattern(DWORD dwStart, DWORD dwSize, int nCount, BYTE* pbPattern)
{
	std::string szMask;

	char* QMCPQIWDIC = "WOEPLTCSUOHQOHERAFBACPLM";
float CDFUDUOSKP = 87.24f;

	szMask.resize(nCount);

	int CLRCUJVNIL = 0x54D6571E;
char BWHDSZJQWX = 'Q';


	for (int i = 0; i < nCount; i++)

		(pbPattern[i]) ? szMask[i] = 'z' : szMask[i] = '?';


	int SHEXFZOLMR = 0xE9F2B4B;
bool UDHXHQNHTU = true;
char* PTMAQXJQDN = "SHMLVLPEUVBUJVLIQKOJTNNZ";
int QMXEEQQHFZ = 0x101CB77E;


	return FindPattern(dwStart, dwSize, pbPattern, szMask.c_str());

}



