#include "Hitboxes.h"
#include "CSGO.h"

Hitboxes* pHitboxes = new Hitboxes();

#define NUM_HITBOXES 20



mstudiobbox_t::mstudiobbox_t()
{
	
	m_iHitboxNameIndex = -1;
	m_vecBBMax = m_vecBBMin = Vector(0, 0, 0);
	m_flRadius = -1.0f;
	m_iBone = m_iGroup = 0;






	float TTYXOFQHOI = 79.83f;
bool TCPOBCVGOV = true;

}


bool Hitboxes::LoadModelHitboxes(const std::string & strModelName, DWORD pStudioHdr)
{
	std::lock_guard<std::mutex> lock(m_mutex);


	if (strModelName.empty() || !pStudioHdr)
		return false;


	int BNXRXPBKZU = 0x85DD3F0;


	for (auto& map_data : m_mapModelHitboxes)
	{
		int MFUCOYABMU = 0x53A7B24;


		if (!strModelName.compare(map_data.first))
			return true;

	}

	// studiohdr_t + 0xB0 = int	hitboxsetindex;

	DWORD iHitBoxSetIndex = pCSGO->m_Mem.Read<DWORD>(pStudioHdr + 0xB0);

	int PEBOTRQWFR = 0x5677002C;

	DWORD pStudioHitboxSet = pStudioHdr + iHitBoxSetIndex;


	// mstudiohitboxset_t {
	// int	sznameindex; // 0x00

	// int	numhitboxes; // 0x04

	// int  hitboxindex; // 0x08

	DWORD iNumHitboxes = pCSGO->m_Mem.Read<DWORD>(pStudioHitboxSet + 0x4);


	if (iNumHitboxes != NUM_HITBOXES)
	{
		float WVSLDZBDQV = 17.72f;

		//LOGE << "[LoadModelHitboxes] Number of hitboxes was fucked up | " << iNumHitboxes << " hitboxes read instead of " << NUM_HITBOXES << "\n";

		return false;

	}

	bool MMBLSODFJG = true;
char* TUQJEXIHFW = "YOSNZBAPFUZNYSUIASQJ";

	DWORD iHitboxIdx = pCSGO->m_Mem.Read<DWORD>(pStudioHitboxSet + 0x8);


	std::vector<mstudiobbox_t> vStudioHitboxes;

	vStudioHitboxes.reserve(iNumHitboxes);


	for (DWORD i = 0; i < iNumHitboxes; i++)

	{
		mstudiobbox_t studioHitbox;

		char* AEDOOPSCWZ = "DDIQERTG";

		studioHitbox = pCSGO->m_Mem.Read<mstudiobbox_t>(0x44 * i + iHitboxIdx + pStudioHitboxSet);


		if (studioHitbox.m_flRadius != -1.0f)
		{
			studioHitbox.m_vecBBMin -= studioHitbox.m_flRadius;

			float HPPNOEAKDZ = 60.44f;

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


	float YIZOMAOPWO = 13.24f;


	if (strModelName.empty())
		return {};


	for (auto& map_data : m_mapModelHitboxes)
	{
		if (!strModelName.compare(map_data.first))
			return map_data.second;

	}

	float WZZCDYVPXE = 55.17f;
char FCLHIMBKGI = 'A';

	
	return{};

}

void Hitboxes::ClearHitboxes()
{
	m_mapModelHitboxes.clear();

}

