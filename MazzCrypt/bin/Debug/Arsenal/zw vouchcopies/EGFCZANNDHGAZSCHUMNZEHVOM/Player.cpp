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
	float SDVKJIXECJ = 48.94f;

	int vt = pCSGO->m_Mem.Read<int>(m_dwBaseAddr + 0x8);

	int fn = pCSGO->m_Mem.Read<int>(vt + 2 * 0x4);

	int cls = pCSGO->m_Mem.Read<int>(fn + 0x1);

	bool NZWCXQQEDS = true;

	int clsn = pCSGO->m_Mem.Read<int>(cls + 8);

	return pCSGO->m_Mem.Read<int>(cls + 20);

}

// Get the Classname
char* Player::GetClassName()
{
	int vt = pCSGO->m_Mem.Read<int>(m_dwBaseAddr + 0x8);

	int fn = pCSGO->m_Mem.Read<int>(vt + 2 * 0x4);

	char GIMQOEWHEW = 'H';

	int cls = pCSGO->m_Mem.Read<int>(fn + 0x1);

	char* AZGNYGYRBN = "HRKGTHYGDBCQBZVAVS";
bool IEGHYSDIMZ = true;
float GZZGNLBKPJ = 78.15f;

	int clsn = pCSGO->m_Mem.Read<int>(cls + 8);


	char* nameData = new char[32];

	char* FNCFCYHEMA = "MNQZLGWMVQCSIO";
bool IEZJNYZIYU = true;
bool EQYVNGDZNU = true;

	pCSGO->m_Mem.Read(clsn, &nameData[0], 32);


	return nameData;

}

void Player::Clear()
{
	
	ZeroMemory(&m_szModelName, sizeof(m_szModelName));
	m_vHitboxes.clear();

	m_bAlive = false;

	m_dwBaseAddr = 0;
	m_nTeam = 0;
	m_bSpectated = false;


	m_nFlags = 0;

	m_bScoped = false;


	m_nHealth = 0;
	m_bReloading = false;







	ZeroMemory(&m_vecOldPunchAngles, sizeof(Vector2D));
	m_nSpecTarget = 0;
	m_nMoveType = 0;

	ZeroMemory(&m_vecEyePos, sizeof(Vector));

	ZeroMemory(&m_tPlayerInfo, sizeof(player_info_t));




	m_bShooting = false;



	m_bMoving = false;


	m_nAmmo = 0;

	m_fDistanceFromMe = 0.0f;
	ZeroMemory(&m_vecViewAngles, sizeof(Vector));
	m_bFlashed = false;
	ZeroMemory(&m_vecPunchAngles, sizeof(Vector2D));



	ZeroMemory(&m_vecOrigin, sizeof(Vector));
	m_fFlashTime = 0.0f;
	ZeroMemory(&m_vecViewOffset, sizeof(Vector));
	m_nWeaponID = 0;
	m_nShotsFired = 0;
	m_bSpawned = false;

	ZeroMemory(&m_matBone, sizeof(Matrix3x4));
	ZeroMemory(&m_vecVelocity, sizeof(Vector));

	m_nID = 0;

	m_bDormant = false;

}

// Update player stats per tick
// [in] - dwBaseAddr - Base address for this entity
void Player::Update(DWORD dwBaseAddr)
{
	if (!dwBaseAddr)
		return;


	m_dwBaseAddr = dwBaseAddr;

	char MEXHXTGFNP = 'J';
char GTKQZAAPMZ = 'K';
char* IAXOQFKZWU = "ZVGEGEXQGDXJXXZDZVJ";
bool MUOZXVROHE = true;
char MBKUTWULPJ = 'D';
char LRZRRCKDMA = 'F';
char GGGKNIICTO = 'X';
char* XGAALWTDFN = "HCOVBNXSAONLCINSLAHQ";
float MDHQURQUOU = 42.36f;

	char pData[0x10000];

	bool YDICXWVSLO = true;
char PACAWPDEXZ = 'O';
int QWNRUSSTVT = 0x50509540;
QWNRUSSTVT = QWNRUSSTVT * QWNRUSSTVT;
bool MXIWTSOZTU = true;
int FVOYARTCKV = QWNRUSSTVT * QWNRUSSTVT;
char* VALWRTORXB = "TZAUQHQTXE";
int TZJDZFLDOX = 0x21074431;
int JMRPCUBRXH = QWNRUSSTVT * FVOYARTCKV;

	pCSGO->m_Mem.Read(dwBaseAddr, pData, sizeof(pData));


	
	m_nMoveType = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwMoveType);
	m_nHealth = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_iHealth);
	m_nID = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwEntIndex);
	m_nShotsFired = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_iShotsFired);




	m_nTeam = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_iTeamNum);
	m_nFlags = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_fFlags);
	m_bShooting = ((pCSGO->m_Mem.Read<int>(pCSGO->m_dwClientBase + pCSGO->m_Offsets.m_dwAttack) == 5)) ? true : false;
	m_nSpecTarget = GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_iObserverTarget);






	m_bAlive = (m_nHealth > 0);

	char MWJXBGEYZC = 'S';
char* ZAYPLPYAZL = "MQUHJRUW";
int ZDWRTGLPWU = 0x3FD48C51;
char PPBSBRHSIB = 'U';
char HYUGEGONVD = 'G';
char DJEEYYAKFR = 'H';
bool EVHUUWWZEQ = true;


	


	m_bSpawned = (GetDataFromDump<float>(pData, pCSGO->m_Offsets.m_dwNetvar_immuneTime) <= 0.0001f);
	m_bSpectated = IsBeingSpectated();



	m_bReloading = (GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_bInReload)) ? true : false;

	m_fFlashTime = GetDataFromDump<float>(pData, pCSGO->m_Offsets.m_dwFlashBangTime) - pCSGO->m_Mem.Read<float>(pCSGO->m_dwGlobalVarsBase + 0x10);
	m_bFlashed = (GetDataFromDump<float>(pData, pCSGO->m_Offsets.m_dwFlashBangTime) >= pCSGO->m_Mem.Read<float>(pCSGO->m_dwGlobalVarsBase + 0x10)) ? true : false;

	m_bDormant = (GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwDormant)) ? true : false;
	m_bScoped = (GetDataFromDump<int>(pData, pCSGO->m_Offsets.m_dwNetvar_bIsScoped)) ? true : false;


	char* BSGAJJZFZS = "QPBCTLFMB";
float VTDPBZGPKV = 50.25f;
char* RJZBWILLTF = "HSCBEECQGDEFGZNIQZGLJYI";


	
	m_vecPunchAngles = GetDataFromDump<Vector2D>(pData, pCSGO->m_Offsets.m_dwPunchAngles);


	m_vecOrigin = GetDataFromDump<Vector>(pData, pCSGO->m_Offsets.m_dwNetvar_vecOrigin);
	m_vecViewOffset = GetDataFromDump<Vector>(pData, pCSGO->m_Offsets.m_dwNetvar_vecViewOffset);
	m_vecVelocity = GetDataFromDump<Vector>(pData, pCSGO->m_Offsets.m_dwNetvar_vecVelocity);




	
	m_bMoving = (abs(m_vecVelocity.z != 0) && abs(m_vecVelocity.y) > pCSGO->m_Config.m_TriggerSettings.m_fMinSpeed || abs(m_vecVelocity.x) > pCSGO->m_Config.m_TriggerSettings.m_fMinSpeed);

	m_vecViewAngles = pCSGO->m_Mem.Read<Vector>(pCSGO->m_dwAnglePointer + pCSGO->m_Offsets.m_dwViewAngles);

	m_vecEyePos = m_vecOrigin + m_vecViewOffset;



	int TCJAULMUNI = 0x326C3420;
TCJAULMUNI = TCJAULMUNI - TCJAULMUNI;
TCJAULMUNI = TCJAULMUNI + TCJAULMUNI;
bool XVDFSBZXDN = true;
char QHVINMHXUX = 'W';


	int clientState = pCSGO->m_Mem.Read<int>(pCSGO->m_dwEngineBase + pCSGO->m_Offsets.m_dwEnginePtr);

	char BOIYTQBORQ = 'I';

	int ecx = pCSGO->m_Mem.Read<int>(clientState + pCSGO->m_Offsets.m_dwPlayerInfo);

	int edx = pCSGO->m_Mem.Read<int>(ecx + 0x3C);

	int DADVZKDUCQ = 0x134AF257;
int XGTRVXIUPO = 0x213BC050;
int ZXDPVRXTQB = XGTRVXIUPO - XGTRVXIUPO;
XGTRVXIUPO = DADVZKDUCQ * XGTRVXIUPO;
float YNTTIKOOUH = 55.12f;
int TAMALANCQY = 0x284E844;
char YSZQVUKYQV = 'B';

	int eax = pCSGO->m_Mem.Read<int>(edx + 0xC);

	int info = pCSGO->m_Mem.Read<int>(eax + 0x20 + (m_nID - 1) * 0x34);

	int GOJEDNPCEA = 0x5FE59B36;
char OTFTBQWVRS = 'V';

	pCSGO->m_Mem.Read(info + 0x10, m_tPlayerInfo.name, sizeof(m_tPlayerInfo.name));

	m_tPlayerInfo.userID = Utils::EndianDwordConversion(pCSGO->m_Mem.Read<int>(info + 0x90));

	pCSGO->m_Mem.Read(info + 0x94, m_tPlayerInfo.guid, sizeof(m_tPlayerInfo.guid));


	DWORD m_pModel = GetDataFromDump<DWORD>(pData, pCSGO->m_Offsets.m_dwModel);

	int NIAKKRKKUJ = 0x4F0D8388;
int XXRBCWPLOF = 0x37856FA9;
char LSFLFYGOLX = 'E';
int HGGABQYUDI = NIAKKRKKUJ - XXRBCWPLOF;
bool YNABZBDEPR = true;
char* TWABGEHZKU = "KQPXXCLD";
float YRBTJFDBLK = 76.39f;
char* JLNBGYMVOS = "RJMFHNGSPVVFYHWYEXZKGVHF";
char* AEFHUKZCCA = "XUXDBZNOGPTKZIYOHSWB";

	pCSGO->m_Mem.Read(m_pModel + 0x4, (LPVOID)&m_szModelName[0], sizeof(m_szModelName));



	DWORD baseCombatHandle = pCSGO->m_Mem.Read<DWORD>(dwBaseAddr + pCSGO->m_Offsets.m_dwNetvar_hActiveWeapon);

	float CMIALFWFWF = 28.44f;
int BGFVURGUGU = 0x1F5DB934;
bool RJGYMDVKBO = true;
int ASONTAUMBM = 0x165AC42;
float EGIGJDPONZ = 93.88f;
int HQFREGOGBS = 0x20DB8769;
int IQWFQXQRET = 0x27173DDD;
char* MFOOZXNWWV = "AZHCOBTLBHXQTHVMPMLJXX";
IQWFQXQRET = BGFVURGUGU + HQFREGOGBS;

	baseCombatHandle &= 0xFFF;


	DWORD weapBase = pCSGO->m_Mem.Read<DWORD>(pCSGO->m_dwEntityBase + (baseCombatHandle * 0x10) - 0x10);

	bool AKPYJPQROV = true;
char OOUHELXJKM = 'Y';
int XNFKJGLMVC = 0x4EDB5F32;
char PRCKOMMAWJ = 'F';
int UKLYLPGIWM = XNFKJGLMVC + XNFKJGLMVC;

	m_nWeaponID = pCSGO->m_Mem.Read<int>(weapBase + pCSGO->m_Offsets.m_dwNetvar_AttributeManager + pCSGO->m_Offsets.m_dwNetvar_Item + pCSGO->m_Offsets.m_dwNetvar_iItemDefinitionIndex);

	m_nAmmo = pCSGO->m_Mem.Read<int>(weapBase + pCSGO->m_Offsets.m_dwNetvar_iClip1);

	int ZXWVSSBXFX = 0x1DEF1031;
char* MQUMTJYVBG = "QUWPYZOLEIKOZSSWNJJCG";
int EFTOOOCEWP = 0x3D2C4B2;
char HHXRFMECCV = 'U';
int LSEOUQSJEL = EFTOOOCEWP - ZXWVSSBXFX;
int YTNBSTDKMI = 0x2A0209AF;
int MQIKAODWEG = 0x66AD69F2;
char TNKQQGGRMV = 'J';
char* OMHLFHZZUS = "ZMZBPHGNKXRYYSWRVVDMAPEO";


	DWORD boneMat = GetDataFromDump<DWORD>(pData, pCSGO->m_Offsets.m_dwNetvar_boneMatrix);

	bool PXIGZVKQDG = true;
int FOVALXOJTI = 0x4FCA575E;
int YKHLRSMRQB = FOVALXOJTI + FOVALXOJTI;
int QTYXEPSRVN = FOVALXOJTI - FOVALXOJTI;
YKHLRSMRQB = YKHLRSMRQB * FOVALXOJTI;
float JTXFYUFLWR = 62.99f;
int SIUUOTVFLK = QTYXEPSRVN + YKHLRSMRQB;
int VWPDJEZZQY = 0x3C94AF48;


	if (boneMat)
		pCSGO->m_Mem.Read(boneMat, m_matBone, sizeof(m_matBone));


	m_fDistanceFromMe = (float)abs((m_vecOrigin - pCSGO->m_Me.m_vecOrigin).Length());/* * 0.01905f*/

	int RPRFRLGCRE = 0x298277BA;
int DWWUWTQJBN = 0x2D138734;
int LOBTIFARIJ = DWWUWTQJBN + DWWUWTQJBN;
int DPUPNVNXLI = RPRFRLGCRE * LOBTIFARIJ;
LOBTIFARIJ = RPRFRLGCRE - LOBTIFARIJ;
float WDEOLMDCWV = 65.87f;


	if (GetHitboxes().empty() && !GetModelName().empty())
	{
		float OVRXSOWWXM = 53.44f;
char* MCZSGQPSQT = "KZKATILSMZGTVDIXSWQ";
bool EGYINDOMTA = true;
char IEPYSWWAUZ = 'T';

		if (!pHitboxes->LoadModelHitboxes(GetModelName(), pCSGO->m_dwStudioHdrPointer))
		{
			pCSGO->GrabStudioHdrPtr();

			float QYUMKVGYQW = 36.88f;
float FTBMXQRTBZ = 81.31f;

		}

		m_vHitboxes = pHitboxes->GetModelHitboxes(GetModelName());

		char HAAENCXXMQ = 'R';
char QPZKNSPDQC = 'Y';

	}

	int DEROQDDZFO = 0x1D6EE077;
char* GRIGLVQACU = "MCCJOEBSDJYFIWMNHK";
DEROQDDZFO = DEROQDDZFO - DEROQDDZFO;

}

// Get Bone Position
// [in] - Bone to return
Vector Player::GetBonePosition(int nBone)
{
	char* WMMLDCXYEA = "QRJEFJZI";
char* ZKYHJPAADK = "UXFIOGRGVIKRMNQTRPHS";


	if (nBone < 0 || nBone >= Bone_MAX)
		return Vector(0, 0, 0);


	bool LBPZRSMDPS = true;
bool SWJLVSJUXW = true;
int BPTULPXEHX = 0x2659D5F5;


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


	int YLVPFOXBYR = 0x57BA541E;
char MUOTLNRRGB = 'C';
YLVPFOXBYR = YLVPFOXBYR - YLVPFOXBYR;


	return Team_NoTeam;

}

// Are we being spectated?
bool Player::IsBeingSpectated()
{
	for (int i = 0; i < 64; i++)

	{
		if (i == m_nID)
			continue;


		bool BSLLKZSVEU = true;


		int specTarget = m_nSpecTarget & 0xFFF;


		if (specTarget == m_nID)
			return true;

	}

	int ZALKGFUNCO = 0x21ABA60B;
float RIYCRTWIZC = 69.84f;


	return false;

}

Matrix3x4 Player::GetBoneMatrix(int nBone) const
{
	char FIXDDWFMMB = 'Q';
char VFQBJRHTXF = 'A';

	return m_matBone[nBone];

}

Vector Player::GetEyePos() const
{
	char VMSDLDBMQA = 'B';
bool URWJZHRQYB = true;

	return m_vecEyePos;

}

// Get ID
int Player::GetID() const
{
	float MEJPQZLDFO = 48.81f;
char* YOZKAZVIRM = "CRSKHQALRMM";

	return m_nID;

}

// Get Origin
Vector Player::GetOrigin() const
{
	char* FVXKRLHXOJ = "RNATYAYAZ";
char YYPDNFCVYM = 'K';

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
	char XYAAXFCIHQ = 'C';
char EBQWRANFPB = 'C';
char* PPOUCRJQDJ = "LHATTBUZ";

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
	bool HMKBFIYJDR = true;
int TYEIOEUXCU = 0x19DFEED3;

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
	int DIWXQLNZPI = 0x792488D1;

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
	char* YMJUAPNCYI = "FETEWTAWGBFDMQJZ";
bool TZHYHUVECB = true;
char* RKSJXERQRH = "WZYSDSFMZILIGVNIODRTAX";

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
	char* CSLWPPCGCM = "JWDMANVYWIREPMJQ";
char* HWCKOYMLFX = "HAJZMPJGFLDYHMC";
int KNWJFZSYGJ = 0xDC534AC;


	if (m_dwBaseAddr == NULL || m_bDormant || !m_bAlive)
		return false;


	int UQKRWYSSAD = 0xED9275C;
char XUYMXBXJNE = 'I';
UQKRWYSSAD = UQKRWYSSAD + UQKRWYSSAD;


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

	
	float EHAQDLCGIO = 49.54f;

	return pBSP->IsVisible(pCSGO->m_Me.GetEyePos(), GetBonePosition(nBone));

}

