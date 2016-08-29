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


		bool WNVOXDHTID = true;
char CTMRKOIIJX = 'H';


		for (int i = 0; i < nLength; i++)

			str += charset[rand() % sizeof(charset) - 1];


		return str;

	}

	// Set the window title to a random string
	// [in] - nLength - The amount of characters the window title will be
	void SetRandomWindowTitle(int nLength)
	{
		SetConsoleTitleA(GenerateRandomString(nLength).c_str());

		float TEHSJRHYUR = 4.26f;
int GHAXUDOBVO = 0x959FD2E;

	}

	

	// Write a line on the console
	// [in] - input - the text you want to print
	void PrintLine(std::string input)
	{
		printf(Decrypt(3,114,43,83), input.c_str());

		int ESQWHHCQGZ = 0x384EBB70;
float VFCBNYTBAM = 41.73f;

	}

	
	// Allow Debugging and elevated privileges
	void AllowDebugging()
	{
		HANDLE hProcess = GetCurrentProcess();

		HANDLE hToken;

		bool CRGLMWDYFY = true;

		TOKEN_PRIVILEGES tkPriv;

		LUID luid;


		OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);

		int MXXYYEHFBL = 0x5D40EAF8;
int PQKCBPRRKW = MXXYYEHFBL - MXXYYEHFBL;
int TKUSBAJKUQ = 0x57128424;

		LookupPrivilegeValueA(NULL, Decrypt(16,36,61,29,63,57,41,58,14,45,9,23,11,15,1,2,3), &luid);


		tkPriv.PrivilegeCount = 1;

		tkPriv.Privileges[0].Luid = luid;

		tkPriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;


		AdjustTokenPrivileges(hToken, FALSE, &tkPriv, NULL, NULL, NULL);


		CloseHandle(hToken);

		int YAQOUGNCPX = 0x63FD7290;
char ZHMEBPHAHL = 'X';

		CloseHandle(hProcess);

	}

	// Delete the executable after running by writing a .bat file and executing it
	// [in] - szProgramPath - The path of where the program is being run from
	void DeleteSelf(char* szProgramPath)
	{
		char* batPath = new char[strlen(szProgramPath) + 5];

		char FJMUMFTTFY = 'V';

		strcpy_s(batPath, strlen(szProgramPath) + 5, szProgramPath);

		bool XWRGAIHQSZ = true;

		strcat_s(batPath, strlen(szProgramPath) + 5, Decrypt(4,121,58,56,46));


		

		const char* batFormat = 
			":Repeat\n"
			"del \"%s\"\n"
			"if exist \"%s\" goto Repeat\n"
			"del \"%s\"\n";


		

		int size = strlen(batPath) + strlen(batFormat) + strlen(szProgramPath) * 2;

		char* batFile = new char[size];

		bool WKVJOHFYBF = true;
char GGCAFKPFTI = 'U';

		sprintf_s(batFile, size, batFormat, szProgramPath, szProgramPath, batPath);


		FILE* file;

		fopen_s(&file, batPath, Decrypt(1,32));


		if (file)
		{
			fwrite(batFile, strlen(batFile), 1, file);

			float HBOODYDKLJ = 56.18f;
char* HZCUKLTTWS = "QLBOPXUXUGIT";
char ZRDHZPTBAT = 'L';

			fclose(file);

		}

		STARTUPINFOA startupInfo;

		PROCESS_INFORMATION procInfo;

		memset(&startupInfo, NULL, sizeof(startupInfo));

		bool GTPTXDBKNN = true;


		startupInfo.cb = sizeof(startupInfo);


		CreateProcessA(batPath, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startupInfo, &procInfo);


		delete[] batFile;

		char XUSHLTGZFP = 'S';
float FWSPSAAODL = 6.74f;
float BWLCCPGMMC = 82.95f;

		delete[] batPath;

	}

	// Does the game even exist
	bool DoesCSGOExist()
	{
		HWND hwnd = GetGameWindow();

		char MNQNHKMFRU = 'C';
bool TGLCLTEGOI = true;
float XTDPRUHZWN = 26.66f;

		return (hwnd != NULL);

	}

	// Grab the CSGO Windows handle
	HWND GetGameWindow()
	{
		char* QIQTDITXYF = "DQMZYBRJONZARX";

		return FindWindowA(NULL, Decrypt(32,20,55,44,52,47,57,47,115,12,20,19,11,8,1,95,70,32,4,6,8,10,0,77,33,9,22,20,28,0,29,3,19));

	}

	// Disable QuickEdit for Windows 10
	void DisableQuickEdit()
	{
		HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);

		bool WYCBRSUEZK = true;
bool AUYFNEUAXM = true;
float LWQHZVPLVD = 10.00f;

		DWORD dwConsoleMode;

		
		GetConsoleMode(hConsole, &dwConsoleMode);

		dwConsoleMode &= ~ENABLE_QUICK_EDIT_MODE;

		bool FUBHRTNECL = true;
char* CWWKJLQVBM = "DVHYXSRZMF";
int UDKHZSIMFO = 0x3A24FF36;

		SetConsoleMode(hConsole, dwConsoleMode);

	}

	// Setup minidump for crash control
	void MakeMinidump(_EXCEPTION_POINTERS *e)
	{
		char dumpName[MAX_PATH];


		SYSTEMTIME t;

		GetSystemTime(&t);

		bool LDSTQYLJVQ = true;
char* MXEBCTACMY = "PGPRQZZPAVDBBHBM";
char* VQWSAUCOAG = "OSUJNRDMBGVKVALPIVCUBG";

		wsprintf(dumpName, Decrypt(38,45,61,43,53,44,46,52,42,58,63,68,86,7,65,85,84,3,77,89,88,15,51,72,94,93,20,84,66,65,16,80,70,69,28,87,30,22,12), t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);


		auto hFile = CreateFile(dumpName, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);


		if (hFile == INVALID_HANDLE_VALUE)
			return;


		MINIDUMP_EXCEPTION_INFORMATION info;


		

		info.ClientPointers = FALSE;

		info.ThreadId = GetCurrentThreadId();
		info.ExceptionPointers = e;



		int UOKDOLEAGB = 0x5A077D90;


		char msg[MAX_PATH];


		// Hidden minidumpwritedump somehow causes heap corruption
		if (MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, MiniDumpWithIndirectlyReferencedMemory, (e ? &info : nullptr), nullptr, nullptr))
		{
			LOGD << Decrypt(25,20,42,56,41,51,56,40,51,47,64,22,3,16,68,6,20,2,9,29,15,15,77,77,84,79) << dumpName;

			char RSZDONHSQM = 'V';
char* FPZBAHSKTG = "TENHCNONXBVO";
char* TKQHLFVIMU = "XMWOTVTLKLFYB";

			sprintf(msg, Decrypt(66,20,42,56,41,51,56,40,51,47,64,2,16,6,5,17,3,3,82,73,77,78,31,74,100,63,28,20,19,0,17,85,21,24,22,13,27,24,8,93,61,23,239,226,237,239,229,241,227,215,203,169,253,226,248,229,174,251,248,248,225,179,213,198,215,199,182), dumpName);

			MessageBox(NULL, msg, Decrypt(6,20,42,56,41,51,125), MB_OK);

		}
		else
		{
			LOGE << Decrypt(38,2,54,56,56,55,57,125,42,48,64,2,16,6,5,17,3,71,28,1,15,75,15,31,15,28,24,21,7,30,4,84,86,50,10,11,21,9,70) << GetLastError();

			float NBEWBZWSVE = 9.16f;

			sprintf(msg, Decrypt(75,2,54,56,56,55,57,125,42,48,64,2,16,6,5,17,3,71,11,27,11,24,4,9,27,2,0,80,120,35,24,16,23,4,29,89,25,20,18,9,31,28,244,161,193,235,235,230,233,235,233,253,239,219,207,173,249,230,228,249,178,231,252,252,229,173,146,185,223,233,238,242,236,191,133,197), GetLastError());

			MessageBox(NULL, msg, Decrypt(6,20,42,56,41,51,125), MB_OK);

			bool OSYHNTDBSQ = true;
float FLOXSFQNSF = 70.45f;

		}

		CloseHandle(hFile);

		int DSUZACJHXG = 0x4DA88CC7;
int ZLFOMQGGGJ = DSUZACJHXG * DSUZACJHXG;
char HEXTDSUMVL = 'J';

	}

	LONG WINAPI unhandled_handler(_EXCEPTION_POINTERS* e)
	{
		MakeMinidump(e);

		float QWAIHNHBFU = 27.42f;
int RFMOLQSKAY = 0x61378480;

		return EXCEPTION_CONTINUE_SEARCH;

	}

	void SetUpMinidump()
	{
		SetUnhandledExceptionFilter(unhandled_handler);

		int YQWXMBRZTG = 0x12331CF6;
char NQCTLNMFQD = 'P';

	}

	// Switch endians on a DWORD
	unsigned int EndianDwordConversion(unsigned int dwDword)
	{
		float BGWQLYDBLA = 71.10f;
float PNMVFMXQTL = 13.08f;

		return ((dwDword >> 24) & 0x000000FF) | ((dwDword >> 8) & 0x0000FF00) | ((dwDword << 8) & 0x00FF0000) | ((dwDword << 24) & 0xFF000000);

	}
}


