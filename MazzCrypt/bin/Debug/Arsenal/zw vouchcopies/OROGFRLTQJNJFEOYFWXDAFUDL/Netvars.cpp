#include "Netvars.h"
#include "Utils.h"

#include "Decrypt.h"





namespace Netvars
{
	DWORD GetNetVar(const char* szClassName, const char* szNetVar)
	{
		if (!pCSGO->m_Offsets.m_dwNetvarClasses || !szClassName || !szNetVar)
		{
			char* WOACPVYRMP = "HWHROUTXT";
float FHPKCWVJWB = 69.49f;

			Utils::PrintLine(Decrypt(47,123,102,4,36,40,57,56,41,62,110,46,34,52,114,53,33,54,61,50,60,119,122,21,57,41,40,62,18,18,66,0,5,11,65,19,72,11,15,75,11,31,15,13,18,20,22,93));

		}

		ClientClass* pClass = (ClientClass*)pCSGO->m_Offsets.m_dwNetvarClasses;


		if (!pClass)
		{
			float XQSCFTNKRR = 82.71f;
int TJWMASWRGK = 0x5C70C241;

			return NULL;

		}

		for (; pClass; pClass = pClass->GetNextClass())

		{
			if (strcmp(szClassName, pClass->GetTable()->GetTableName()))
				continue;


			float KPPXDREBUN = 80.95f;
float WXSHUCZAPR = 99.38f;


			for (int i = 0; i < pClass->GetTable()->GetMaxProp(); i++)

			{
				CRecvTable::CRecvProp* pRecvProp = pClass->GetTable()->GetProperty(i);


				char* XFEDLYWHCF = "QRSKFEBAKMA";


				if (isdigit(pRecvProp->GetVarName()[0]))
					continue;


				if (!strcmp(pRecvProp->GetVarName(), szNetVar))
				{
					int IPYTPFEWFG = 0x6E89EB47;

					return pRecvProp->GetOffset();

				}

				if (!pRecvProp->GetDataTable())
					continue;


				int QQBPMHIELV = 0x2C4591AB;
char* LOPURHJWKD = "OBGUHUWMZFJWRHGJC";
int PSVXQWARKN = QQBPMHIELV + QQBPMHIELV;


				for (int j = 0; j < pRecvProp->GetDataTable()->GetMaxProp(); ++j)

				{
					CRecvTable::CRecvProp* pRecvProp2 = pRecvProp->GetDataTable()->GetProperty(j);


					if (isdigit(pRecvProp2->GetVarName()[0]))
						continue;


					char SENTGBRYMK = 'X';


					if (!strcmp(pRecvProp2->GetVarName(), szNetVar))
					{
						bool HCZVGJELTF = true;

						return pRecvProp2->GetOffset();

					}

					if (!pRecvProp2->GetDataTable())
						continue;


					for (int k = 0; k < pRecvProp2->GetDataTable()->GetMaxProp(); ++k)

					{
						char TFHZVLWCZO = 'V';

						CRecvTable::CRecvProp* pRecvProp3 = pRecvProp2->GetDataTable()->GetProperty(k);

						float GMGJFSLSVS = 96.56f;
bool YZKGEEQRTF = true;
char YVGXWSNFNF = 'Y';


						if (isdigit(pRecvProp3->GetVarName()[0]))
							continue;


						if (!strcmp(pRecvProp3->GetVarName(), szNetVar))
						{
							return pRecvProp3->GetOffset();

						}
					}
				}
			}

			bool IVAKPAANXR = true;
char* RIGTAVZLJM = "WDETISAUAMMHWTVB";
char XIIGDIVWGL = 'X';

		}

		return NULL;

	}
}


