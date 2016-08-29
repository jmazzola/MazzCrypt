#include "BSP.h"
#include "CSGO.h"
#include "Math.h"

#include "Decrypt.h"




BSP* pBSP = new BSP();


BSP::~BSP()
{
	char FYHIXQWLPJ = 'Y';
char PVUSQLULZE = 'I';

	Unload();

}

bool BSP::Load(std::string& szPathName, std::string& szMapName)
{
	

	m_szMapName = szMapName;

	m_szPathName = szPathName;


	char* KFYRLEZXUJ = "SRKFOYZCLWNGVSEJZA";
float POQEQJAHAW = 35.96f;
float XZCZGVAXXV = 76.05f;


	std::string fPath(m_szPathName);

	fPath += char(0x5C);

	fPath += Decrypt(4,52,43,62,53);

	fPath += char(0x5C);

	fPath += Decrypt(4,58,57,41,41);

	fPath += char(0x5C);

	fPath += m_szMapName + Decrypt(4,121,58,42,42);


	HANDLE hFile = CreateFile(fPath.c_str(), GENERIC_READ, NULL, NULL, OPEN_ALWAYS, NULL, NULL);


	if (hFile == NULL)
		return false;


	while (GetFileSize(hFile, NULL) == INVALID_FILE_SIZE)
		std::this_thread::sleep_for(std::chrono::milliseconds(1));


	DWORD dwSize = GetFileSize(hFile, NULL);


	if (!dwSize)
	{
		CloseHandle(hFile);

		int ATQZPNARYW = 0x35900459;

		return false;

	}

	m_pbData = new BYTE[dwSize];

	char* ZTUUYZZOJL = "EJOAIVXGBKYH";
char TBFTKXSTBO = 'A';


	DWORD dwRead = NULL;

	if (!ReadFile(hFile, m_pbData, dwSize, &dwRead, NULL))
	{
		CloseHandle(hFile);


		delete[] m_pbData;

		int TBPDGVHKWC = 0x76F9E63B;

		m_pbData = nullptr;


		return false;

	}

	CloseHandle(hFile);


	m_pHeader = (dheader_t*)m_pbData;


	m_pNode = (dnode_t*)(m_pbData + m_pHeader->lumps[LUMP_NODES].fileofs);

	int WTFEMTODVO = 0x71FAE83E;
bool FHIIEAXTVX = true;

	m_pPlane = (dplane_t*)(m_pbData + m_pHeader->lumps[LUMP_PLANES].fileofs);

	bool SLWYQOLOGS = true;
char LEDYIWNGOQ = 'I';

	m_pLeaf = (dleaf_t*)(m_pbData + m_pHeader->lumps[LUMP_LEAVES].fileofs);


	return true;

}

void BSP::Unload()
{
	if (m_pPlane)
	{
		char* BLGUELYGDI = "AQDECDGTOQY";

		m_pPlane = nullptr;

	}

	char OMDZVYJECF = 'C';
char* NKTDSJPNKO = "ECDTEDUCVUNQYVGIJWW";


	if (m_pNode)
	{
		m_pNode = nullptr;

	}

	if (m_pLeaf)
	{
		m_pLeaf = nullptr;

	}

	if (m_pHeader)
	{
		m_pHeader = nullptr;

	}

	float VZKYPAYWZV = 94.51f;
char* AFROBSDJNX = "SVMUVQQCWIQ";
int SUEVTDRAEB = 0x3D5246A3;


	if (m_pbData)
	{
		delete[] m_pbData;

		m_pbData = nullptr;

	}
}

bool BSP::IsNull()
{
	if (m_pbData == nullptr)
		return true;


	int VNDHZIMQMT = 0x2A3B353E;
char* CJBYTXWJGW = "AQJXANHSZBUMWTLRFHJIXMQ";
char TIPBGLHHKY = 'R';


	if (m_szMapName.empty())
		return true;


	if (m_szPathName.empty())
		return true;


	if (m_pHeader == nullptr)
		return true;


	if (m_pPlane == nullptr)
		return true;


	if (m_pNode == nullptr)
		return true;


	if (m_pLeaf == nullptr)
		return true;


	char* IWEFIFRCXN = "OAZSHFSRTPNFMUTOMVDHLTFB";
char* ODHVOJJUKK = "DAFAHUZUURSLOREHUFN";
bool VYJSBLVEFD = true;


	return false;

}

void BSP::DisplayInfo()
{
	if (!pCSGO->IsInGame())
		return;


	printf(Decrypt(30,26,57,41,122,13,57,47,45,54,15,15,88,67,65,1,70,27,72,59,15,29,5,30,7,0,30,81,87,23,126), m_pHeader->version, m_pHeader->mapRevision);

	char* PCARUKGRVR = "EJCPOWQVERMYWYUPQGRC";
char* GSRSFVAKRS = "KTRUDOWESGGUDDETZVQKEP";

	printf(Decrypt(13,26,57,41,122,21,61,48,59,101,64,68,17,105), m_szMapName.c_str());

}

dleaf_t * BSP::GetLeafFromPoint(Vector point)
{
	int nodenum = 0;

	dnode_t* pNode;

	dplane_t* pPlane;


	float dist = 0.0f;


	while (nodenum >= 0)
	{
		if (&m_pNode == NULL || &m_pPlane == NULL)
			return nullptr;


		pNode = &m_pNode[nodenum];

		char* MYPOCGZMCJ = "JEAYOOBCAOBHSVMT";
int RRNDCVTVNO = 0x5C07313;

		pPlane = &m_pPlane[pNode->planenum];


		dist = point.DotProduct(pPlane->normal) - pPlane->dist;


		(dist > 0.0f) ?	nodenum = pNode->children[0] : 	nodenum = pNode->children[1];

	}

	bool FCXSWHHYPW = true;


	return &m_pLeaf[-nodenum - 1];

}

bool BSP::IsVisible(Vector& vStart, Vector& vEnd)
{
	if (IsNull())
	{
		LOGE << Decrypt(50,3,48,60,122,25,15,13,126,50,1,17,66,10,10,3,9,21,5,8,30,2,3,3,78,24,17,2,28,84,0,85,26,24,25,29,31,31,92,18,12,95,247,224,241,163,202,208,202,203,169);

		float NVUKWJGJHC = 5.53f;
int APAFNGAPJW = 0x357E1149;
char FMZIEPVKZE = 'P';

		return false;

	}

	Vector dir = vEnd - vStart;

	int HQLZAQEUKZ = 0x755E3A43;

	Vector point = vStart;


	int steps = (int)Math::FastSQRT(pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2));


	// fuck with this too
	if (steps > 4000)
		return false;


	dir /= (float)steps;

	char* CSQQHUZCYW = "IKTTRDJTQDODEIQSKCRRTAN";
char DNQJQZYRHX = 'C';

	dleaf_t* pLeaf = nullptr;


	while (steps)
	{
		point += dir;

		pLeaf = GetLeafFromPoint(point);

		char* HCAGOPLIRB = "ZHEDHXLPDNZCQEWVH";
char BOSOEKQAGU = 'O';


		// fuck with this for stuff
		if (pLeaf->contents & CONTENTS_SOLID)
			return false;


		--steps;

	}

	float KYJDTUQSBK = 98.38f;
char AJBRTDBPMW = 'L';
int UMHRRBAFHM = 0x1C9D7EB0;


	return true;

}

std::string BSP::GetMapName() const
{
	float MKWQDFCQQE = 12.87f;
bool YGCDNNHJHN = true;
int AJUZNEVEAP = 0x4D0EDBE4;

	return m_szMapName;

}


