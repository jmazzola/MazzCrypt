#include "Netvars.h"
#include "Utils.h"

#include "Decrypt.h"





namespace Netvars
{
	DWORD GetNetVar(const char* szClassName, const char* szNetVar)
	{
		if (!pCSGO->m_Offsets.m_dwNetvarClasses || !szClassName || !szNetVar)
		{
			char* TBZOAGDARA = "NEYYYTGHC";
int FETDLLJHWJ = 0x5388392B;
int KWWTWOSHKV = FETDLLJHWJ + FETDLLJHWJ;

			Utils::PrintLine(Decrypt(47,105,120,26,54,58,47,46,59,44,64,0,16,6,68,3,19,4,3,12,14,69,76,35,11,27,6,16,0,0,84,22,23,25,95,13,90,25,25,93,25,13,225,227,224,230,224,171));

		}

		ClientClass* pClass = (ClientClass*)pCSGO->m_Offsets.m_dwNetvarClasses;


		if (!pClass)
		{
			float BTTEQUWSRE = 38.92f;

			return NULL;

		}

		for (; pClass; pClass = pClass->GetNextClass())

		{
			if (strcmp(szClassName, pClass->GetTable()->GetTableName()))
				continue;


			char CXAACOMXJH = 'B';
float OTZGJADAKF = 21.81f;
int XDXOXMRZDQ = 0x3383B272;


			for (int i = 0; i < pClass->GetTable()->GetMaxProp(); i++)

			{
				CRecvTable::CRecvProp* pRecvProp = pClass->GetTable()->GetProperty(i);


				char* GVVJTFDXFD = "DHRUWRZCYRYAWPBNY";
char* ZEDNRTOKVI = "ZAJUYNSMVNICDOVIVYTR";


				if (isdigit(pRecvProp->GetVarName()[0]))
					continue;


				if (!strcmp(pRecvProp->GetVarName(), szNetVar))
				{
					float FZKQQXGMWR = 39.78f;

					return pRecvProp->GetOffset();

				}

				if (!pRecvProp->GetDataTable())
					continue;


				char YCJBDVRBZZ = 'V';
char* SMCQAUMDUN = "COPBLLTPESPZRHQBROXLRUM";


				for (int j = 0; j < pRecvProp->GetDataTable()->GetMaxProp(); ++j)

				{
					CRecvTable::CRecvProp* pRecvProp2 = pRecvProp->GetDataTable()->GetProperty(j);


					if (isdigit(pRecvProp2->GetVarName()[0]))
						continue;


					char* EELLLEHMOU = "QGKRSCMKJJT";


					if (!strcmp(pRecvProp2->GetVarName(), szNetVar))
					{
						float WCGHCBBRKJ = 42.70f;
int TKNJRZLKWO = 0x2C1B3F74;
int TNGWZSLYXX = TKNJRZLKWO * TKNJRZLKWO;

						return pRecvProp2->GetOffset();

					}

					if (!pRecvProp2->GetDataTable())
						continue;


					for (int k = 0; k < pRecvProp2->GetDataTable()->GetMaxProp(); ++k)

					{
						char JQNISKZOLP = 'F';
float ZTAEVBIHKH = 47.43f;
float MIUFNPZLZV = 5.38f;

						CRecvTable::CRecvProp* pRecvProp3 = pRecvProp2->GetDataTable()->GetProperty(k);

						char NMZDAISJJL = 'F';


						if (isdigit(pRecvProp3->GetVarName()[0]))
							continue;


						if (!strcmp(pRecvProp3->GetVarName(), szNetVar))
						{
							return pRecvProp3->GetOffset();

						}
					}
				}
			}

			float STBEXWJQUA = 82.56f;
float TPDSDXQNWH = 28.35f;

		}

		return NULL;

	}
}


