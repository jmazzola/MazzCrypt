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

				float QZZJVPFQRY = 46.98f;
bool DFHXTTJOHW = true;
char* IYVQYKTOQT = "EJBKPXPN";
float DWESXTCOCJ = 36.85f;

				char varName[128];

				pCSGO->m_Mem.Read(offset, varName, 128);

				return varName;

			}

			int GetOffset()
			{
				char* TRRJZHLTCT = "IFMHJGTUZM";
bool IXGJGUTMUF = true;
char ISRKMHPDRV = 'N';

				return pCSGO->m_Mem.Read<int>((DWORD)this + 0x2C);

			}
			CRecvTable* GetDataTable()
			{
				char* UAZJTTWYIU = "PARZQYYYA";
int OSWGMJIDNJ = 0x29B77127;
int TNLMRHKJXH = 0x70806D67;

				return pCSGO->m_Mem.Read<CRecvTable*>((DWORD)this + 0x28);

			}

		};


		const char* GetTableName()
		{
			DWORD offset = pCSGO->m_Mem.Read<DWORD>((DWORD)this + 0xC);

			char tableName[128];

			int ZGFICCGJNV = 0x68E2247E;
char EQGDNMGTTF = 'U';
char* FKEBQVIJPU = "KJFHTOONNQCHXYJ";
int NANNSBYJTE = ZGFICCGJNV + ZGFICCGJNV;

			pCSGO->m_Mem.Read(offset, tableName, 128);

			return tableName;

		}


		int GetMaxProp()
		{
			int HZZEQHBTCC = 0x23FF6D74;
HZZEQHBTCC = HZZEQHBTCC * HZZEQHBTCC;
char FUTHJJGLZY = 'V';
HZZEQHBTCC = HZZEQHBTCC * HZZEQHBTCC;

			return pCSGO->m_Mem.Read< int >((DWORD)this + 0x4);

		}

		CRecvProp* GetProperty(int iIndex)
		{
			char XCZUVSKQMQ = 'F';
float JFMCEZAKDL = 66.90f;
float DSADXKZJEW = 68.82f;

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

			char HXXCFDTFWA = 'O';
char CMKIRDSHSB = 'R';
bool ANXJROZVYU = true;
char* OLUCJPFFBU = "PCZUXJMGIQPQQVXANRAJ";

			return networkName;

		}

		ClientClass* GetNextClass()
		{
			char SQHCKGXORG = 'U';
char HSTBLMNWTZ = 'U';
int HMOSNBKAGU = 0x215F5CFB;

			return pCSGO->m_Mem.Read< ClientClass* >((DWORD)this + 0x10);

		}
		CRecvTable* GetTable()
		{
			int ALCXKVNPIT = 0x4F480F76;
char MOTWDUXSFA = 'P';
bool BMLQLEKNLR = true;

			return pCSGO->m_Mem.Read< CRecvTable* >((DWORD)this + 0xC);

		}
	};


	DWORD GetNetVar(const char* szClassName, const char* szNetVar);

}

