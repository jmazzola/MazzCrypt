#include "Player.h"
#include "CSGO.h"
#include "Utils.h"
#include "Math.h"

#include "BSP.h"

#include "Hitboxes.h"

#include <future>



// Get the ClassID
int Player::GetClassID()
{
	float JNOUFENXHY = 83.99f;

	int vt = pCSGO->m_Mem.Read<int>(m_dwBaseAddr + 0x8);

	int fn = pCSGO->m_Mem.Read<int>(vt + 2 * 0x4);

	int cls = pCSGO->m_Mem.Read<int>(fn + 0x1);

	bool ZQSBSEPXBA = true;

	int clsn = pCSGO->m_Mem.Read<int>(cls + 8);

	return pCSGO->m_Mem.Read<int>(cls + 20);

}

// Get the Classname
char* Player::GetClassName()
{
	int vt = pCSGO->m_Mem.Read<int>(m_dwBaseAddr + 0x8);

	int fn = pCSGO->m_Mem.Read<int>(vt + 2 * 0x4);

	float HNYSIZZPQB = 97.60f;

	int cls = pCSGO->m_Mem.Read<int>(fn + 0x1);

	float AVDFZLCYFY = 67.41f;
bool EOWMPLNPCP = true;
int RRTMCCQYHM = 0x488420B8;

	int clsn = pCSGO->m_Mem.Read<int>(cls + 8);


	char* nameData = new char[32];

	char* ELLPAOISQW = "ISMSAAFDY";
float BTGGCCWITY = 63.39f;

	pCSGO->m_Mem.Read(clsn, &nameData[0], 32);


	return nameData;

}

void Player::Clear()
{
	

	ZeroMemory(&m_vecViewOffset, sizeof(Vector));

	ZeroMemory(&m_vecOldPunchAngles, sizeof(Vector2D));



	ZeroMemory(&m_vecVelocity, sizeof(Vector));


	m_bScoped = false;
	m_bReloading = false;
	m_bAlive = false;

	m_dwBaseAddr = 0;


	ZeroMemory(&m_tPlayerInfo, sizeof(player_info_t));


	ZeroMemory(&m_szModelName, sizeof(m_szModelName));
	m_fDistanceFromMe = 0.0f;
	m_bSpawned = false;

	m_bSpectated = false;



	m_nHealth = 0;
	m_nSpecTarget = 0;
	m_nAmmo = 0;



	m_nTeam = 0;

	m_bShooting = false;


	m_bMoving = false;


	ZeroMemory(&m_vecEyePos, sizeof(Vector));
	ZeroMemory(&m_vecViewAngles, sizeof(Vector));
	m_nWeaponID = 0;

	m_nMoveType = 0;
	ZeroMemory(&m_vecPunchAngles, sizeof(Vector2D));
	m_vHitboxes.clear();
	m_nFlags = 0;

	m_bDormant = false;
	m_bFlashed = false;
	m_nID = 0;
	ZeroMemory(&m_matBone, sizeof(Matrix3x4));


	m_fFlashTime = 0.0f;
	ZeroMemory(&m_vecOrigin, sizeof(Vector));



	m_nShotsFired = 0;


}

// Update player stats per tick
// [in] - dwBaseAddr - Base address for this entity
void Player::Update(DWORD dwBaseAddr)
{
	if (!dwBaseAddr)
		return;


	m_dwBaseAddr = dwBaseAddr;

	char BPGLMBADTO = 'C';
char YUXBXVFMGU = 'N';
float ZHZAQGUTLY = 96.40f;
float RAZHDTINWV = 47.85f;
char* TOXZHNGHVU = "HVTIMULUZVGJXWXJNMZV";
int UPGCJVLYSR = 0x689094BF;
int JLVTKANNME = UPGCJVLYSR - UPGCJVLYSR;

	char pData[0x10000];

	char* MREMABQGKD = "BUXKSCUZWZYRE";
char WFTUKEGJAS = 'I';
char XCGHMNZAHE = 'W';
bool JJEZADXBMM = true;
int MZCPNTLYOC = 0x1397BC59;
int YWZOXBQEAU = MZCPNTLYOC + MZCPNTLYOC;
char WRWODVLZTQ = 'B';
char* ANXIXWKDZP = "WVBVSESLC";

	pCSGO->m_Mem.Read(dwBaseAddr, pData, sizeof(pData));


	

	m_nFlags = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_fFlags);

	m_bShooting = ((pCSGO->m_Mem.Read<int>(pCSGO->m_dwClientBase + pCSGO->m_Offsets.m_dwAttack) == 5)) ? true : false;

	m_nMoveType = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwMoveType);
	m_nShotsFired = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_iShotsFired);

	m_nTeam = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_iTeamNum);
	m_nSpecTarget = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_iObserverTarget);
	m_nHealth = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_iHealth);


	m_nID = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwEntIndex);




	m_bAlive = (m_nHealth > 0);

	bool QGOXQKQSKT = true;
char* KRBHWDPUXC = "SSTYERBM";
float ZVKYHJKQJI = 19.96f;


	
	m_fFlashTime = GetDataFromDump<float>(pData, pCSGO->m_Offsets.m_dwFlashBangTime) - pCSGO->m_Mem.Read<float>(pCSGO->m_dwGlobalVarsBase + 0x10);

	m_bFlashed = (GetDataFromDump<float>(pData, pCSGO->m_Offsets.m_dwFlashBangTime) >= pCSGO->m_Mem.Read<float>(pCSGO->m_dwGlobalVarsBase + 0x10)) ? true : false;
	m_bDormant = (GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwDormant)) ? true : false;



	m_bSpawned = (GetDataFromDump<float>(pData, pCSGO->m_Offsets.m_dwNetvar_immuneTime) <= 0.0001f);
	m_bSpectated = IsBeingSpectated();

	m_bReloading = (GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_bInReload)) ? true : false;

	m_bScoped = (GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_bIsScoped)) ? true : false;



	float JOHDZMTYLO = 88.86f;
float VSBWDXIUHV = 98.47f;
char* GOBUPXQLCG = "DUXUGYJSHBBXPOEIULM";


	
	m_vecViewOffset = GetDataFromDump<Vector>(pData, pCSGO->m_Offsets.m_dwNetvar_vecViewOffset);

	m_vecPunchAngles = GetDataFromDump<Vector2D>(pData, pCSGO->m_Offsets.m_dwPunchAngles);


	m_vecOrigin = GetDataFromDump<Vector>(pData, pCSGO->m_Offsets.m_dwNetvar_vecOrigin);
	m_vecVelocity = GetDataFromDump<Vector>(pData, pCSGO->m_Offsets.m_dwNetvar_vecVelocity);



	

	m_vecViewAngles = pCSGO->m_Mem.Read<Vector>(pCSGO->m_dwAnglePointer + pCSGO->m_Offsets.m_dwViewAngles);

	m_vecEyePos = m_vecOrigin + m_vecViewOffset;

	m_bMoving = (abs(m_vecVelocity.z != 0) && abs(m_vecVelocity.y) > pCSGO->m_Config.m_TriggerSettings.m_fMinSpeed || abs(m_vecVelocity.x) > pCSGO->m_Config.m_TriggerSettings.m_fMinSpeed);


	int SJERLFLOVA = 0x4E2E9051;
SJERLFLOVA = SJERLFLOVA * SJERLFLOVA;
int EJQNIOPBCR = 0x2C26DCB9;
char* WMSTATYZCL = "QXKDFTHWXYITRIWQJLERZMT";
char* HPUGCFHEPS = "FYXYBTOLNTAKDDPNYUY";
SJERLFLOVA = EJQNIOPBCR - EJQNIOPBCR;
float VSBPBQEKLO = 24.30f;
char YIESHFQDMS = 'I';
float PONFZUNDSS = 46.11f;


	int clientState = pCSGO->m_Mem.Read<int>(pCSGO->m_dwEngineBase + pCSGO->m_Offsets.m_dwEnginePtr);

	bool ZSEYRESEVN = true;
float YWNIASFLBP = 89.32f;
char PLCCGPSOIL = 'R';
char* IUQFXKTZGJ = "QPKSSYNSJVYJGCQYGUKIN";
char DZFBZNQWXY = 'F';
float LNVWZPUSHP = 39.14f;
char* KDHMNFVAHK = "LMQZABNYADPQCCJV";
bool OUYOPVRWFE = true;
bool CFIABKJIQT = true;

	int ecx = pCSGO->m_Mem.Read<int>(clientState + pCSGO->m_Offsets.m_dwPlayerInfo);

	int edx = pCSGO->m_Mem.Read<int>(ecx + 0x3C);

	char VMEJDJAMMM = 'Y';
bool RZCVXEFXXG = true;
int SZMEUEEWFN = 0x6A412763;
int ICTVOCOSIN = SZMEUEEWFN + SZMEUEEWFN;

	int eax = pCSGO->m_Mem.Read<int>(edx + 0xC);

	int info = pCSGO->m_Mem.Read<int>(eax + 0x20 + (m_nID - 1) * 0x34);

	bool UCZXVEKCZD = true;
int QWKOLTDGOX = 0xFB89603;
char BNGBYNEVDQ = 'Q';
float EEUDNWTFVX = 73.88f;
char TZVSUYXCYC = 'T';
float DRAFPMLCNG = 67.23f;

	pCSGO->m_Mem.Read(info + 0x10, m_tPlayerInfo.name, sizeof(m_tPlayerInfo.name));

	m_tPlayerInfo.userID = Utils::EndianDwordConversion(pCSGO->m_Mem.Read<int>(info + 0x90));

	pCSGO->m_Mem.Read(info + 0x94, m_tPlayerInfo.guid, sizeof(m_tPlayerInfo.guid));


	DWORD m_pModel = GetDataFromDump<DWORD>(pData, pCSGO->m_Offsets.m_dwModel);

	int GYGJDUKDDU = 0x578813AB;

	pCSGO->m_Mem.Read(m_pModel + 0x4, (LPVOID)&m_szModelName[0], sizeof(m_szModelName));



	DWORD baseCombatHandle = pCSGO->m_Mem.Read<DWORD>(dwBaseAddr + pCSGO->m_Offsets.m_dwNetvar_hActiveWeapon);

	int KUVOYIJLCG = 0x5A3923C5;
int HWAXWVNGAW = 0x5163BDB3;
bool UHLMHDGWFN = true;
float UGXCGRZMVT = 14.99f;

	baseCombatHandle &= 0xFFF;


	DWORD weapBase = pCSGO->m_Mem.Read<DWORD>(pCSGO->m_dwEntityBase + (baseCombatHandle * 0x10) - 0x10);

	int UYYWWQRVUG = 0x6F9EED3C;
char* RNVYGTACUK = "MGYNINSNCBGPGCY";
int WJICBEGIAH = UYYWWQRVUG - UYYWWQRVUG;
char* JKSHMSEVVJ = "YOWIQOZYACKEUH";
float KQYJBBVSOJ = 15.89f;
int FMHRTITEZG = 0x4A843B1D;

	m_nWeaponID = pCSGO->m_Mem.Read<int>(weapBase + pCSGO->m_Offsets.m_dwNetvar_AttributeManager + pCSGO->m_Offsets.m_dwNetvar_Item + pCSGO->m_Offsets.m_dwNetvar_iItemDefinitionIndex);

	m_nAmmo = pCSGO->m_Mem.Read<int>(weapBase + pCSGO->m_Offsets.m_dwNetvar_iClip1);

	int UGKIUUQDMB = 0x7B10124F;
char* JJRVNMTILD = "YLGKSLLAAFZ";
int TSVTWBGWIV = UGKIUUQDMB + UGKIUUQDMB;


	DWORD boneMat = GetDataFromDump<DWORD>(pData, pCSGO->m_Offsets.m_dwNetvar_boneMatrix);

	char* UHDWIJTUQN = "IFKFHJUUYOP";
int YCDLXJYBUR = 0x5FA872ED;
char PKICYGNBND = 'L';
int PLLXFEFUFY = YCDLXJYBUR + YCDLXJYBUR;


	if (boneMat)
		pCSGO->m_Mem.Read(boneMat, m_matBone, sizeof(m_matBone));


	m_fDistanceFromMe = (float)abs((m_vecOrigin - pCSGO->m_Me.m_vecOrigin).Length());/* * 0.01905f*/

	char HAUKLVPJPX = 'O';
char KGOOAPWRGA = 'B';
char FZPHWOIFGY = 'H';
int WACLPFPYAF = 0x51F190F;
WACLPFPYAF = WACLPFPYAF - WACLPFPYAF;


	if (GetHitboxes().empty() && !GetModelName().empty())
	{
		float HMGIQODETO = 92.73f;
char* YMRZNLBBLC = "ZYZGBZAOYFTUK";
bool TUABLFLHOR = true;

		if (!pHitboxes->LoadModelHitboxes(GetModelName(), pCSGO->m_dwStudioHdrPointer))
		{
			pCSGO->GrabStudioHdrPtr();

			bool FGRCEEGKQI = true;
int SAZHFSHFTR = 0x40D2DBB;
SAZHFSHFTR = SAZHFSHFTR - SAZHFSHFTR;

		}

		m_vHitboxes = pHitboxes->GetModelHitboxes(GetModelName());

		char* GISNQPFNJD = "ZGMLHHLWWIAOFSCHHOA";
char RETLRHUPCB = 'S';
char* NIATKLKCXU = "BGTMUNIYY";
char* VBVNBTANVU = "QQBWSJXWEXLWCREXUZCUD";

	}

	int SHEFJSJPBA = 0x2288A6EB;
bool QCELCTMJET = true;
bool FNTZRVPJPN = true;
int UHKWVFOFEX = 0x759FB2CE;
SHEFJSJPBA = SHEFJSJPBA + SHEFJSJPBA;
float WECHAPPBIA = 56.73f;
UHKWVFOFEX = UHKWVFOFEX * SHEFJSJPBA;
UHKWVFOFEX = SHEFJSJPBA - UHKWVFOFEX;

}

// Get Bone Position
// [in] - Bone to return
Vector Player::GetBonePosition(int nBone)
{
	int VFPNWDIXLD = 0x7989E64;
VFPNWDIXLD = VFPNWDIXLD - VFPNWDIXLD;


	if (nBone < 0 || nBone >= Bone_MAX)
		return Vector(0, 0, 0);


	char* JZUAHOMGXQ = "YXNSBUTXIYENT";
float SROCUANTQL = 25.55f;


	return Vector(m_matBone[nBone].m[0][3], m_matBone[nBone].m[1][3], m_matBone[nBone].m[2][3]);

}

EWeaponType Player::GetWeaponType()
{
	switch (m_nWeaponID)
	{
		case WID_C4:
		return EWeaponType::WeapType_C4Explosive;


		case WID_Zeus:
		return EWeaponType::WeapType_ZeusGun;


		case WID_Negev:
		case WID_M249:
		return EWeaponType::WeapType_LMG;


		case WID_AWP:
		case WID_G3SG1_Auto:
		case WID_SCAR_Auto:
		case WID_Scout:
		return EWeaponType::WeapType_Sniper;


		case WID_XM1014:
		case WID_MAG7:
		case WID_Nova:
		case WID_SawedOff:
		return EWeaponType::WeapType_Shotgun;


		case WID_Flashbang:
		case WID_Smoke:
		case WID_Firebomb:
		case WID_HEFrag:
		case WID_Molly:
		return EWeaponType::WeapType_Grenade;


		case WID_MAC10:
		case WID_P90:
		case WID_UMP45:
		case WID_PPBizon:
		case WID_MP7:
		case WID_MP9:
		return EWeaponType::WeapType_SMG;


		case WID_Deagle:
		case WID_Dual_Berettas:
		case WID_Five_Seven:
		case WID_USP:
		case WID_Glock:
		case WID_Tec9:
		case WID_P2000:
		case WID_P250:
		case WID_CZ75:
		case WID_Revolver:
		return EWeaponType::WeapType_Pistol;


		case WID_AK47:
		case WID_AUG:
		case WID_FAMAS:
		case WID_M4A4:
		case WID_M4A1S:
		case WID_Galil:
		case WID_SG553:
		return EWeaponType::WeapType_Rifle;


		case WID_Default_Knife:
		case WID_ButterflyKnife:
		case WID_FlipKnife:
		case WID_HuntsmanKnife:
		case WID_M9BayonetKnife:
		case WID_KarambitKnife:
		case WID_FalchionKnife:
		case WID_ShadowDaggerKnife:
		case WID_BayonetKnife:
		case WID_GutKnife:
		case WID_BowieKnife:
		return EWeaponType::WeapType_KnifeType;


		default:
		return (EWeaponType)-1;

	}
}

// Get Enemy Team
int Player::GetEnemyTeam()
{
	if (m_nTeam == Team_Terrorists)
		return Team_CounterTerrorists;

	else if (m_nTeam == Team_CounterTerrorists)
		return Team_Terrorists;


	float GDNFMAJPWX = 16.21f;
int QVEGBLGHEH = 0x3B078D4A;


	return Team_NoTeam;

}

// Are we being spectated?
bool Player::IsBeingSpectated()
{
	for (int i = 0; i < 64; i++)

	{
		if (i == m_nID)
			continue;


		char KTMJNHQDGU = 'T';


		int specTarget = m_nSpecTarget & 0xFFF;


		if (specTarget == m_nID)
			return true;

	}

	bool FOLAEGMDRS = true;
float ODVRMDEONU = 17.36f;
char DYEEKCFEIZ = 'X';


	return false;

}

Matrix3x4 Player::GetBoneMatrix(int nBone) const
{
	bool YSGUUTTJSA = true;
bool WZDJEKKGWG = true;

	return m_matBone[nBone];

}

Vector Player::GetEyePos() const
{
	float MYFPFDISFM = 33.87f;
bool AKLTGETSFG = true;
int CUHJDURALK = 0x7D640F1B;

	return m_vecEyePos;

}

// Get ID
int Player::GetID() const
{
	char* YJDIHTSRJA = "ZXYIBMCHHVQUPVENVODRI";
bool OGKPNYBUEB = true;
float MCGWCFJMEJ = 69.42f;

	return m_nID;

}

// Get Origin
Vector Player::GetOrigin() const
{
	int KOQBXVBAWV = 0x73A732D8;
char NZJZWWBCNR = 'V';

	return m_vecOrigin;

}

// Get Velocity
Vector Player::GetVelocity() const
{
	return m_vecVelocity;

}

// Get ViewAngles
Vector Player::GetViewAngles() const
{
	int IBYFDJDFFK = 0x74F76D5;
char* PKAFTLDUCC = "AOVENNRMYPW";
int QTGSCANLZN = 0x4083F9C4;

	return m_vecViewAngles;

}

// Get PunchAngles
Vector2D Player::GetPunchAngles() const
{
	return m_vecPunchAngles;

}

// Get Name
std::string Player::GetName() const
{
	return std::string(m_tPlayerInfo.name);

}

// Get Model Name
std::string Player::GetModelName() const
{
	return std::string(m_szModelName);

}

std::vector<mstudiobbox_t> Player::GetHitboxes() const
{
	float YVZDUIARWJ = 70.04f;
bool TSUXOAFLSC = true;
bool ABIYLVGOZB = true;

	return m_vHitboxes;

}

float Player::GetDistanceFromMe() const
{
	return m_fDistanceFromMe;

}

float Player::GetFlashedTime() const
{
	return m_fFlashTime;

}

// Get Flags
int Player::GetFlags() const
{
	bool NWVGFCTZCG = true;
int EURUATCCGT = 0x24224B92;
int WHOMGSWUMF = 0xDF520F7;

	return m_nFlags;

}

// Get Team
int Player::GetTeam() const
{
	return m_nTeam;

}

// Get Health 
int Player::GetHealth() const
{
	float TOVVEGLLPA = 33.36f;

	return m_nHealth;

}

// Get WeaponID
int Player::GetWeaponID() const
{
	return m_nWeaponID;

}

// Get Ammo
int Player::GetAmmo() const
{
	return m_nAmmo;

}

// Get Shots Fired
int Player::GetShotsFired() const
{
	return m_nShotsFired;

}

// Get MoveType
int Player::GetMoveType() const
{
	return m_nMoveType;

}

// Get Alive
bool Player::IsAlive() const
{
	return m_bAlive;

}

// Get Dormancy
bool Player::IsDormant() const
{
	return m_bDormant;

}

// Are we reloading?
bool Player::IsReloading() const
{
	return m_bReloading;

}

// Are we shooting?
bool Player::IsShooting() const
{
	return m_bShooting;

}

// Are we scoped?
bool Player::IsScoped() const
{
	return m_bScoped;

}

// Are we spawned in?
bool Player::IsSpawned() const
{
	return m_bSpawned;

}

bool Player::IsFlashed() const
{
	return m_bFlashed;

}

bool Player::IsMoving() const
{
	return m_bMoving;

}

bool Player::Valid()
{
	char* MGNAUROHSQ = "TUDTNZDTUFBP";
char* ZQJKGPLYKS = "FXOGQRCPVKSANETEZEPGK";


	if (m_dwBaseAddr == NULL || m_bDormant || !m_bAlive)
		return false;


	int EIEBDFIICJ = 0x4544AA4B;


	if (pCSGO->m_Config.m_TriggerSettings.m_bDeathmatch && !m_bSpawned)
		return false;


	return true;

}

// Is this player visible?
// [in] - nBone - Bone to check is visible
bool Player::IsVisible(int nBone)
{
	//std::future<bool> ret = std::async(std::launch::async, &BSP::IsVisible, pBSP, pCSGO->m_Me.GetEyePos(), GetBonePosition(nBone));

	//return ret.get();

	
	char* UYGPVFMKLU = "LJOSNCIMAMPCKYEQCUCBM";

	return pBSP->IsVisible(pCSGO->m_Me.GetEyePos(), GetBonePosition(nBone));

}

