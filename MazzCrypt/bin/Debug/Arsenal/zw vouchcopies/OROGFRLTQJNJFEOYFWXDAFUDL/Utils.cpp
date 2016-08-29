#include "Utils.h"

#include "Decrypt.h"



namespace Utils
{
	// Generate a random string using a charset
	// [in] nLength - The amount of characters the string returned will be
	std::string GenerateRandomString(int nLength)
	{
		static const char charset[] =
			"0123456789"
			"!@#$%^&*"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";


		std::string str;


		bool ONYOSTONQA = true;


		for (int i = 0; i < nLength; i++)

			str += charset[rand() % sizeof(charset) - 1];


		return str;

	}

	// Set the window title to a random string
	// [in] - nLength - The amount of characters the window title will be
	void SetRandomWindowTitle(int nLength)
	{
		SetConsoleTitleA(GenerateRandomString(nLength).c_str());

		int ZEWWRQPKQJ = 0x5D147374;
char* SLTNVNMTWN = "HDREXGHVZZRKXWWJEBJVEH";

	}

	

	// Write a line on the console
	// [in] - input - the text you want to print
	void PrintLine(std::string input)
	{
		printf(Decrypt(3,96,53,77), input.c_str());

		float DHYCQFIIAJ = 50.49f;

	}

	
	// Allow Debugging and elevated privileges
	void AllowDebugging()
	{
		HANDLE hProcess = GetCurrentProcess();

		HANDLE hToken;

		int LMJKBAVQZE = 0x27F762AF;
bool RZNKRTZISJ = true;
int XNJKXIGJRY = 0x1CF05689;

		TOKEN_PRIVILEGES tkPriv;

		LUID luid;


		OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);

		bool APSXYDPTKJ = true;
char* ZBHGELIIUA = "NNODJWIICGXY";
float MPJNKEYEPG = 34.28f;

		LookupPrivilegeValueA(NULL, Decrypt(16,54,35,3,45,43,63,44,28,63,39,57,57,61,55,52,49), &luid);


		tkPriv.PrivilegeCount = 1;

		tkPriv.Privileges[0].Luid = luid;

		tkPriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;


		AdjustTokenPrivileges(hToken, FALSE, &tkPriv, NULL, NULL, NULL);


		CloseHandle(hToken);

		int CRTPCVYQBD = 0x73B8F8CC;
CRTPCVYQBD = CRTPCVYQBD * CRTPCVYQBD;
CRTPCVYQBD = CRTPCVYQBD - CRTPCVYQBD;

		CloseHandle(hProcess);

	}

	// Delete the executable after running by writing a .bat file and executing it
	// [in] - szProgramPath - The path of where the program is being run from
	void DeleteSelf(char* szProgramPath)
	{
		char* batPath = new char[strlen(szProgramPath) + 5];

		int HXDLDGGZOV = 0x3A6D32F9;
char* XFHCDGNHCF = "RDDKMKCIUIEZLEZNSADJFPP";

		strcpy_s(batPath, strlen(szProgramPath) + 5, szProgramPath);

		int KJSCASGWYE = 0x5A76AC3C;

		strcat_s(batPath, strlen(szProgramPath) + 5, Decrypt(4,107,36,38,60));


		

		const char* batFormat = 
			":Repeat\n"
			"del \"%s\"\n"
			"if exist \"%s\" goto Repeat\n"
			"del \"%s\"\n";


		

		int size = strlen(batPath) + strlen(batFormat) + strlen(szProgramPath) * 2;

		char* batFile = new char[size];

		float CINIGBDJKB = 89.62f;

		sprintf_s(batFile, size, batFormat, szProgramPath, szProgramPath, batPath);


		FILE* file;

		fopen_s(&file, batPath, Decrypt(1,50));


		if (file)
		{
			fwrite(batFile, strlen(batFile), 1, file);

			bool ZMNOIVDCRO = true;
bool UBWJPAGOBD = true;
float ZUNJFONGQQ = 96.59f;

			fclose(file);

		}

		STARTUPINFOA startupInfo;

		PROCESS_INFORMATION procInfo;

		memset(&startupInfo, NULL, sizeof(startupInfo));

		char* RWWOXAQEWI = "FKNFRUQGTEVP";
int RASGXXDWTW = 0x4CB78119;
int BUXFJFGBGC = 0x62518AB6;


		startupInfo.cb = sizeof(startupInfo);


		CreateProcessA(batPath, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startupInfo, &procInfo);


		delete[] batFile;

		char VGSWXHKGYF = 'J';

		delete[] batPath;

	}

	// Does the game even exist
	bool DoesCSGOExist()
	{
		HWND hwnd = GetGameWindow();

		char ITOMWZMJWQ = 'T';
float MOJNSPQTTQ = 17.69f;
int MMYLAWQSEP = 0x7488FD2;

		return (hwnd != NULL);

	}

	// Grab the CSGO Windows handle
	HWND GetGameWindow()
	{
		char GJXVFDSYSO = 'R';
bool VXEKRPKZJA = true;
char* ZABLWMPMAI = "KWUYATOGWIFUVA";

		return FindWindowA(NULL, Decrypt(32,6,41,50,38,61,47,57,97,30,58,61,57,58,55,105,116,18,58,56,58,56,54,123,19,59,56,58,14,18,11,21,1));

	}

	// Disable QuickEdit for Windows 10
	void DisableQuickEdit()
	{
		HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);

		float SYFIOVFCHB = 22.75f;

		DWORD dwConsoleMode;

		
		GetConsoleMode(hConsole, &dwConsoleMode);

		dwConsoleMode &= ~ENABLE_QUICK_EDIT_MODE;

		float TOXRJGUUEA = 80.05f;
char GKRDLWIJEB = 'I';

		SetConsoleMode(hConsole, dwConsoleMode);

	}

	// Setup minidump for crash control
	void MakeMinidump(_EXCEPTION_POINTERS *e)
	{
		char dumpName[MAX_PATH];


		SYSTEMTIME t;

		GetSystemTime(&t);

		int XDOHIGQMNH = 0x3B904F8F;
int NBZVWJCNII = 0x10EFC6EE;

		wsprintf(dumpName, Decrypt(38,63,35,53,39,62,56,34,56,40,17,106,100,53,119,99,102,49,115,103,106,61,5,126,108,111,58,122,80,83,6,70,84,87,2,73,12,4,26), t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);


		auto hFile = CreateFile(dumpName, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);


		if (hFile == INVALID_HANDLE_VALUE)
			return;


		MINIDUMP_EXCEPTION_INFORMATION info;


		


		info.ThreadId = GetCurrentThreadId();
		info.ExceptionPointers = e;

		info.ClientPointers = FALSE;


		int QXPWFTXVXT = 0xF08E8D1;


		char msg[MAX_PATH];


		// Hidden minidumpwritedump somehow causes heap corruption
		if (MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, MiniDumpWithIndirectlyReferencedMemory, (e ? &info : nullptr), nullptr, nullptr))
		{
			LOGD << Decrypt(25,6,52,38,59,33,46,62,33,61,110,56,49,34,114,48,38,48,55,35,61,61,123,123,102,125) << dumpName;

			bool FDZNKNPWSW = true;
bool KBEHDDWWBB = true;

			sprintf(msg, Decrypt(66,6,52,38,59,33,46,62,33,61,110,44,34,52,51,39,49,49,108,119,127,124,41,124,86,13,50,58,1,18,7,67,7,10,8,19,9,10,30,75,47,5,1,12,31,29,19,7,17,37,53,87,15,16,14,19,92,9,22,22,243,161,195,208,197,213,168), dumpName);

			MessageBox(NULL, msg, Decrypt(6,6,52,38,59,33,107), MB_OK);

		}
		else
		{
			LOGE << Decrypt(38,16,40,38,42,37,47,107,56,34,110,44,34,52,51,39,49,117,34,63,61,121,57,41,61,46,54,59,21,12,18,66,68,32,20,21,7,27,80) << GetLastError();

			char SDJCAFCSFX = 'U';

			sprintf(msg, Decrypt(75,16,40,38,42,37,47,107,56,34,110,44,34,52,51,39,49,117,53,37,57,42,50,63,41,48,46,126,106,49,14,6,5,22,3,71,11,6,4,31,13,14,26,79,51,25,29,16,27,25,23,3,29,41,57,91,11,20,10,23,160,245,234,234,247,191,140,167,205,251,248,228,254,173,171,235), GetLastError());

			MessageBox(NULL, msg, Decrypt(6,6,52,38,59,33,107), MB_OK);

			bool GJTZLKOPSU = true;

		}

		CloseHandle(hFile);

		char YCRIHAJONU = 'F';
bool XDOQIZQIMH = true;
int DNCJRVYTMY = 0x3F4E89D5;

	}

	LONG WINAPI unhandled_handler(_EXCEPTION_POINTERS* e)
	{
		MakeMinidump(e);

		bool PQZUKFHNWY = true;
bool YXFYREGYAA = true;

		return EXCEPTION_CONTINUE_SEARCH;

	}

	void SetUpMinidump()
	{
		SetUnhandledExceptionFilter(unhandled_handler);

		int NEGOUQDEVZ = 0x59BA6AD5;
int TMVOGCKKFQ = NEGOUQDEVZ + NEGOUQDEVZ;

	}

	// Switch endians on a DWORD
	unsigned int EndianDwordConversion(unsigned int dwDword)
	{
		char VTCTJQJCDV = 'T';
char* ZYFCVPGKZL = "ACTAYCJJPDUWFB";
char* BDDSKKIALG = "PKEHHFKJBQQPLZT";

		return ((dwDword >> 24) & 0x000000FF) | ((dwDword >> 8) & 0x0000FF00) | ((dwDword << 8) & 0x00FF0000) | ((dwDword << 24) & 0xFF000000);

	}
}


