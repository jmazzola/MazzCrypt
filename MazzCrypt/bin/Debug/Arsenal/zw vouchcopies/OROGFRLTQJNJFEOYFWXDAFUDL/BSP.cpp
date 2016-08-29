#include "BSP.h"
#include "CSGO.h"
#include "Math.h"

#include "Decrypt.h"




BSP* pBSP = new BSP();


BSP::~BSP()
{
	char MHMOXEPMBH = 'G';
char* HYNGHUGEPV = "FETPPQCFUZHQEO";
float YOMDQFUEEL = 93.01f;

	Unload();

}

bool BSP::Load(std::string& szPathName, std::string& szMapName)
{
	
	m_szPathName = szPathName;

	m_szMapName = szMapName;



	char KDOAWYCLKZ = 'I';
char* RRWSRLEDKA = "DQHYUCDRZGGFUZMHR";
int ITECOQMOYD = 0x17B8F083;


	std::string fPath(m_szPathName);

	fPath += char(0x5C);

	fPath += Decrypt(4,38,53,32,39);

	fPath += char(0x5C);

	fPath += Decrypt(4,40,39,55,59);

	fPath += char(0x5C);

	fPath += m_szMapName + Decrypt(4,107,36,52,56);


	HANDLE hFile = CreateFile(fPath.c_str(), GENERIC_READ, NULL, NULL, OPEN_ALWAYS, NULL, NULL);


	if (hFile == NULL)
		return false;


	while (GetFileSize(hFile, NULL) == INVALID_FILE_SIZE)
		std::this_thread::sleep_for(std::chrono::milliseconds(1));


	DWORD dwSize = GetFileSize(hFile, NULL);


	if (!dwSize)
	{
		CloseHandle(hFile);

		int KLCSEEMABG = 0x2EEE3889;
int GEAMMLJVEO = KLCSEEMABG * KLCSEEMABG;

		return false;

	}

	m_pbData = new BYTE[dwSize];

	bool LFAMGYAAUV = true;
char KGWNBEGVXR = 'B';
float XEBKUEBTMH = 64.53f;


	DWORD dwRead = NULL;

	if (!ReadFile(hFile, m_pbData, dwSize, &dwRead, NULL))
	{
		CloseHandle(hFile);


		delete[] m_pbData;

		int LMROSYDWWE = 0x62C33DEC;
LMROSYDWWE = LMROSYDWWE + LMROSYDWWE;
int XQFPTJTCQK = 0x50EE92D;

		m_pbData = nullptr;


		return false;

	}

	CloseHandle(hFile);


	m_pHeader = (dheader_t*)m_pbData;


	m_pNode = (dnode_t*)(m_pbData + m_pHeader->lumps[LUMP_NODES].fileofs);

	int FVDVGBUIFB = 0x1F18263F;
FVDVGBUIFB = FVDVGBUIFB + FVDVGBUIFB;

	m_pPlane = (dplane_t*)(m_pbData + m_pHeader->lumps[LUMP_PLANES].fileofs);

	char* QBTCPFNVHR = "CZCLCNEZSOSZYBMYTNUA";
int QOPUKTQVHN = 0x77C588AB;

	m_pLeaf = (dleaf_t*)(m_pbData + m_pHeader->lumps[LUMP_LEAVES].fileofs);


	return true;

}

void BSP::Unload()
{
	if (m_pPlane)
	{
		char* CYDHTYYXCU = "CHUINRPL";

		m_pPlane = nullptr;

	}

	float RUNDLBUPLR = 33.01f;
float QOQSJSQRRP = 72.34f;


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

	char* SWYUWLGIUQ = "XCMJJUTDTWYGSTVZ";


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


	char TPEGJTVJLN = 'U';
float GABLEHUAOA = 74.13f;


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


	float ZMNAGVVSFT = 55.68f;
char* VDYMNQUDAE = "QSVOLSNTLAYUDSAVQJOO";


	return false;

}

void BSP::DisplayInfo()
{
	if (!pCSGO->IsInGame())
		return;


	printf(Decrypt(30,8,39,55,104,31,47,57,63,36,33,33,106,113,119,55,116,41,118,5,61,47,51,40,53,50,48,127,69,5,104), m_pHeader->version, m_pHeader->mapRevision);

	char* WFSLDHPVUW = "KGJASZCKXIUTN";
bool DULPLPCYCP = true;
bool IHSJYJWSLK = true;

	printf(Decrypt(13,8,39,55,104,7,43,38,41,119,110,106,35,91), m_szMapName.c_str());

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

		char* FQANDGIGGL = "UNYRUSNJLW";

		pPlane = &m_pPlane[pNode->planenum];


		dist = point.DotProduct(pPlane->normal) - pPlane->dist;


		(dist > 0.0f) ?	nodenum = pNode->children[0] : 	nodenum = pNode->children[1];

	}

	char SBPMZFFBXP = 'D';
float MUQPKGGTGN = 14.96f;
float JNGGMKZMNH = 68.76f;


	return &m_pLeaf[-nodenum - 1];

}

bool BSP::IsVisible(Vector& vStart, Vector& vEnd)
{
	if (IsNull())
	{
		LOGE << Decrypt(50,17,46,34,104,11,25,27,108,32,47,63,112,56,60,53,59,39,59,54,44,48,53,53,124,42,63,44,14,70,22,67,8,10,7,3,13,13,74,4,30,77,25,14,3,81,60,38,56,57,87);

		char* NPVVPOJKDX = "DLBLZEXACLZZPMQ";
float ZFCGHBWTEK = 69.53f;

		return false;

	}

	Vector dir = vEnd - vStart;

	int CJAHNLCHNM = 0x22DBD751;
float PGIYXKFBQE = 6.76f;
char HPMIZCJXPO = 'F';

	Vector point = vStart;


	int steps = (int)Math::FastSQRT(pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2));


	// fuck with this too
	if (steps > 4000)
		return false;


	dir /= (float)steps;

	bool AVZFODJQDP = true;
int SWFZDUSADH = 0x12466F60;

	dleaf_t* pLeaf = nullptr;


	while (steps)
	{
		point += dir;

		pLeaf = GetLeafFromPoint(point);

		bool SNHMWDGPCT = true;


		// fuck with this for stuff
		if (pLeaf->contents & CONTENTS_SOLID)
			return false;


		--steps;

	}

	char* LWXSADBCFO = "TRKOOLGUKCPOWSZJAB";
char XLKQCUCZCR = 'Q';
char* CXGKOFOEAW = "LKWHBZATAAZREIBHTLLDDUS";


	return true;

}

std::string BSP::GetMapName() const
{
	float ILEMWFANYG = 25.80f;
char* BABXPJDGCB = "XUTOSURSJQLQPPOE";

	return m_szMapName;

}


