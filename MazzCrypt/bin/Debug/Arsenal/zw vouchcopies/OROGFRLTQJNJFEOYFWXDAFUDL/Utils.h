// Utils.h - Misc utilities needed
#pragma once

#include "stdafx.h"

#define clamp(val, a, b) { if(val < a) val = a; if(val > b) val = b; }

namespace Utils
{
	// Generate a random string using a charset
	std::string GenerateRandomString(int nLength = 15);
	
	// Set the window title to a random string
	void SetRandomWindowTitle(int nLength = 15);

	// Write a line on the console
	void PrintLine(std::string input);

	// Write a line on the console formatted
	void PrintLineFormatted(std::string input, ...);

	// Allow Debugging and elevated privileges
	void AllowDebugging();

	// Delete the executable after running
	void DeleteSelf(char* szProgramPath);

	// Does the game even exist
	bool DoesCSGOExist();

	// Grab the CSGO Windows handle
	HWND GetGameWindow();

	// Disable QuickEdit for Windows 10
	void DisableQuickEdit();

	// Setup minidump for crash control
	void SetUpMinidump();

	// Switch endians on a DWORD
	unsigned int EndianDwordConversion(unsigned int dwDword);
}
