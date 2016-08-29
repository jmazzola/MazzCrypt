#include "Hitboxes.h"
#include "CSGO.h"

Hitboxes* pHitboxes = new Hitboxes();

#define NUM_HITBOXES 20



mstudiobbox_t::mstudiobbox_t()
{
	


	m_vecBBMax = m_vecBBMin = Vector(0, 0, 0);
	m_flRadius = -1.0f;
	m_iBone = m_iGroup = 0;


	m_iHitboxNameIndex = -1;


	char MMEKILMTWP = 'L';
int XLNOSJTGPG = 0x4EC19AD8;

}


bool Hitboxes::LoadModelHitboxes(const std::string & strModelName, DWORD pStudioHdr)
{
	std::lock_guard<std::mutex> lock(m_mutex);


	if (strModelName.empty() || !pStudioHdr)
		return false;


	int USJYTYRGTQ = 0x3DDA6D6;
int LOKTAWSQKY = USJYTYRGTQ * USJYTYRGTQ;


	for (auto& map_data : m_mapModelHitboxes)
	{
		int ASMZDGMIYU = 0x1F92F39D;
ASMZDGMIYU = ASMZDGMIYU - ASMZDGMIYU;


		if (!strModelName.compare(map_data.first))
			return true;

	}

	// studiohdr_t + 0xB0 = int	hitboxsetindex;

	DWORD iHitBoxSetIndex = pCSGO->m_Mem.Read<DWORD>(pStudioHdr + 0xB0);

	bool DBCYAFJLKX = true;
int MTGBEBBUGQ = 0x7234CE9F;

	DWORD pStudioHitboxSet = pStudioHdr + iHitBoxSetIndex;


	// mstudiohitboxset_t {
	// int	sznameindex; // 0x00

	// int	numhitboxes; // 0x04

	// int  hitboxindex; // 0x08

	DWORD iNumHitboxes = pCSGO->m_Mem.Read<DWORD>(pStudioHitboxSet + 0x4);


	if (iNumHitboxes != NUM_HITBOXES)
	{
		int HLAIXBHMDP = 0x2DB5BF40;
float ICHDZZSUUM = 51.34f;

		//LOGE << "[LoadModelHitboxes] Number of hitboxes was fucked up | " << iNumHitboxes << " hitboxes read instead of " << NUM_HITBOXES << "\n";

		return false;

	}

	float SEGTWFPLKJ = 2.35f;
bool INQOVSNKWK = true;

	DWORD iHitboxIdx = pCSGO->m_Mem.Read<DWORD>(pStudioHitboxSet + 0x8);


	std::vector<mstudiobbox_t> vStudioHitboxes;

	vStudioHitboxes.reserve(iNumHitboxes);


	for (DWORD i = 0; i < iNumHitboxes; i++)

	{
		mstudiobbox_t studioHitbox;

		float DABOSYXPQM = 50.22f;
bool NVURYOZRIH = true;

		studioHitbox = pCSGO->m_Mem.Read<mstudiobbox_t>(0x44 * i + iHitboxIdx + pStudioHitboxSet);


		if (studioHitbox.m_flRadius != -1.0f)
		{
			studioHitbox.m_vecBBMin -= studioHitbox.m_flRadius;

			int ZCNYFNXGBA = 0x4091E277;
bool ICMPJHUUAH = true;

			studioHitbox.m_vecBBMax += studioHitbox.m_flRadius;

		}

		vStudioHitboxes.push_back(studioHitbox);

	}

	if (vStudioHitboxes.empty())
		return false;


	m_mapModelHitboxes.insert(std::pair< std::string, std::vector< mstudiobbox_t > >(strModelName, vStudioHitboxes));


	return true;

}

std::vector<mstudiobbox_t> Hitboxes::GetModelHitboxes(const std::string & strModelName) const
{
	std::lock_guard< std::mutex > lock(m_mutex);


	int YYMDOHFQOS = 0x535F19AE;


	if (strModelName.empty())
		return {};


	for (auto& map_data : m_mapModelHitboxes)
	{
		if (!strModelName.compare(map_data.first))
			return map_data.second;

	}

	int EUZVKGEBGY = 0x29D3E02;
char* HOERWUVZYI = "RFCJWDASEQ";

	
	return{};

}

void Hitboxes::ClearHitboxes()
{
	m_mapModelHitboxes.clear();

}

