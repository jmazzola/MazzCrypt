// Netvars.h - Class to hold netvars and scanning netvars
#pragma once

#include "stdafx.h"
#include "CSGO.h"



namespace Netvars
{
	class CRecvTable
	{
	public:

		class CRecvProp
		{
		public:
			const char* GetVarName()
			{
				DWORD offset = pCSGO->m_Mem.Read<DWORD>((DWORD)this);

				bool ISWRTBQIFE = true;
char* AUTAUSWFNG = "XHJLOJKPFJUNXVPIEVNQSY";
char UELDONLGFC = 'W';

				char varName[128];

				pCSGO->m_Mem.Read(offset, varName, 128);

				return varName;

			}

			int GetOffset()
			{
				int ZVOBCGHVEF = 0x2EFA749D;
float LBWFYNSOUD = 90.94f;
ZVOBCGHVEF = ZVOBCGHVEF + ZVOBCGHVEF;
ZVOBCGHVEF = ZVOBCGHVEF * ZVOBCGHVEF;

				return pCSGO->m_Mem.Read<int>((DWORD)this + 0x2C);

			}
			CRecvTable* GetDataTable()
			{
				bool JZSZMHZQVU = true;
char* XBGKZIWUDE = "WVQQGXBURJSNEURTYQTZ";
char* KOPFSGWMKF = "AXOZIKNDITQC";

				return pCSGO->m_Mem.Read<CRecvTable*>((DWORD)this + 0x28);

			}

		};


		const char* GetTableName()
		{
			DWORD offset = pCSGO->m_Mem.Read<DWORD>((DWORD)this + 0xC);

			char tableName[128];

			float YDKFILGBKN = 66.32f;
char HHELMGFRKN = 'D';
float QRUMKRQQOX = 47.14f;

			pCSGO->m_Mem.Read(offset, tableName, 128);

			return tableName;

		}


		int GetMaxProp()
		{
			float CSGAZMDLIX = 74.61f;
int VKPEKZUPRR = 0x66CC0706;
char DNFLOQQUGY = 'T';
int FXLXOGBLMB = VKPEKZUPRR + VKPEKZUPRR;

			return pCSGO->m_Mem.Read< int >((DWORD)this + 0x4);

		}

		CRecvProp* GetProperty(int iIndex)
		{
			float ZWVRBMFGBC = 9.99f;
bool RRTAMMTQBP = true;
int RAEYTMHQYI = 0x611FD9D1;

			return (CRecvProp*)(pCSGO->m_Mem.Read<DWORD>((DWORD)this) + 0x3C * iIndex);

		}

	};


	class ClientClass
	{
	public:
		const char* GetNetworkName()
		{
			DWORD offset = pCSGO->m_Mem.Read<DWORD>((DWORD)this + 0x8);

			char networkName[128];

			pCSGO->m_Mem.Read(offset, networkName, 128);

			float EZRVKTURWK = 65.13f;
float KQSZBIGNOV = 45.06f;
int FTEYUKGHSJ = 0x4912257A;
int DAEYINVLNF = 0x4BD8F28;

			return networkName;

		}

		ClientClass* GetNextClass()
		{
			char FINOZVOBOU = 'L';
char ORNZEPFEKF = 'D';
bool PEUGZXDVDB = true;

			return pCSGO->m_Mem.Read< ClientClass* >((DWORD)this + 0x10);

		}
		CRecvTable* GetTable()
		{
			int MGPYPEXIGU = 0x7C6B37C8;
int JYWAFTZUBH = 0xB0F983D;
float CNEMYECYOL = 62.14f;

			return pCSGO->m_Mem.Read< CRecvTable* >((DWORD)this + 0xC);

		}
	};


	DWORD GetNetVar(const char* szClassName, const char* szNetVar);

}

