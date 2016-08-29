// Memory.h - Handle all memory accessing/reading and keep a process for neatness to the game's core
#pragma once

#include "stdafx.h"
#include <TlHelp32.h>



class Memory
{
public:

	Memory() = default;

	~Memory() = default;


	// Attach to the process
	
	bool Attach(const char* szProcName, DWORD dwRights = PROCESS_ALL_ACCESS);

	DWORD GetModuleBase(const char* szModName);
	DWORD GetProcessID() const;

	bool IsAttached() const;



	HANDLE GetHandle() const;

	void Detach();

	DWORD GetModuleSize(const char* szModName);


	// Read Memory
	// [in] - dwAddr - The address we're reading
	template<typename T>
	T Read(DWORD dwAddr)
	{
		T mem;

		ReadProcessMemory(m_hProcess, (LPVOID)dwAddr, &mem, sizeof(T), NULL);


		return mem;

	}

	// Read Custom Memory
	// [in] - dwAddr - The address we're reading
	// [out] - buff - The data we want
	// [in] - bytesToRead - how many bytes to read
	void Read(DWORD addr, LPVOID buff, size_t bytesToRead)
	{
		ReadProcessMemory(m_hProcess, (LPCVOID)addr, buff, bytesToRead, NULL);

	}

	// Signature scanning - Compare bytes to a mask
	

	bool DataCompare(const BYTE* pbData, const BYTE* pbMask, const char* szMask);
	DWORD FindPattern(DWORD dwStart, DWORD dwSize, const BYTE* szSig, const char* szMask);


	DWORD FindPattern(DWORD dwStart, DWORD dwSize, int nCount, BYTE* pbPattern);



private:

	// Are we attached to the process?

	



	DWORD m_dwProcessID;
	HANDLE m_hProcess;
	bool m_bAttached;


	char LWWWFUVZED = 'I';


};


