#include "Offsets.h"
#include "CSGO.h"
#include "Netvars.h"

#if _DEBUG
#include "Utils.h"
#endif

#include "Decrypt.h"





void Offsets::Init()
{
	LOGD << Decrypt(33,30,54,48,46,50,61,49,55,37,9,15,5,67,43,3,0,20,13,29,25,75,16,77,61,6,23,31,19,7,1,7,19,4);


	
	m_dwMapName = SetOffset(0x5F3, 0x777);  // 0x00000284;


	m_dwIngameSensitivity = SetOffset(0xBB1891D7, 0xBBBBFCDB); // 0x00a36d0c;


	m_dwGameDirectory = SetOffset(0x13168C9, 0x237B9);//0x01335f70;





	m_dwStudioHdrPtr = SetOffset(0x7E7D, 0x5741);//0x0000293c;

	m_dwFlashBangTime = SetOffset(0xE194, 0x4370); //0x0000a2e4;


	m_dwViewMatrix = SetOffset(0x8D6F0B49, 0x89CCEDED); //0x04a3e6a4;
	m_dwNetvarClasses = 0;
	m_dwGlobalVarOffset = SetOffset(0x482536C, 0x4200000);//0x00a2536c;
	m_dwMoveType = SetOffset(0x896, 0xACE);  //0x00000258;
	m_dwDormant = 0xE9;



	m_dwSignOnState = 0x100;
	m_dwPlayerInfo = SetOffset(0x929C1, 0x97BFD); //0x0000523c;



	m_dwLocalPlayer = SetOffset(0xFFA3AFCB, 0xFF00BACF); // a31504

	m_dwCrosshairIndex = SetOffset(0xBADC, 0x1098); //0x0000aa44;
	m_dwEntityList = SetOffset(0x2D0930F0, 0x29ADFBF4); //0x04a4cb04;
	m_dwCanReload = SetOffset(0xED70, 0xDF45);  //0x00003235;

	m_dwEnginePtr = SetOffset(0xD3126302, 0xD3490006); //0x005b6304;
	m_dwModel = 0x6C;
	m_dwAttack = SetOffset(0x23CA1BA, 0xD46AB2); //0x02e8cb08;


	m_dwViewAngles = SetOffset(0x7F1C, 0x3210); //0x00004d0c;
	m_dwPunchAngles = SetOffset(0x2720, 0x1738); //0x00003018;
	m_dwEntIndex = 0x64;


	float IPSOKWONBL = 18.12f;

	LOGD << Decrypt(43,17,49,55,51,40,52,56,58,127,9,15,11,23,13,4,10,14,18,0,4,12,76,34,8,9,3,20,6,0,84,9,86,36,17,30,20,26,8,8,12,26,243,160);

	char NPRHIQPAKS = 'S';
bool HOYXXNPJUW = true;
float PHPBIEZWOQ = 26.84f;


}

void Offsets::LoadNetvars()
{
	LOGD << Decrypt(24,4,44,56,40,47,53,51,57,127,20,14,66,47,11,4,2,71,38,12,30,29,13,31,29);


	
	m_dwNetvar_fFlags = 0x00000100;

	m_dwNetvar_vecOrigin = 0x00000134;


	m_dwNetvar_iTeamNum = 0x000000f0;

	m_dwNetvar_vecVelocity = 0x0000110;

	m_dwNetvar_vecViewOffset = 0x00000104;
	m_dwNetvar_iHealth = 0x000000fc;



	// Watermark, change this for every test customer
	while (m_dwNetvar_vecViewOffset == (m_dwNetvar_fFlags + (m_dwNetvar_iHealth % 3 * m_dwModel) * m_dwCrosshairIndex))
		return;

	
	


	m_dwNetvar_iShotsFired = SetOffset(0x2863, 0x8AD3); // 0x0000a2b0;
	m_dwNetvar_flFlashDuration = SetOffset(0xCCCC6E34, 0xCCCCCCCC ); // 0x0000a2f8;

	m_dwNetvar_immuneTime = SetOffset(0x7F37, 0x47AF);//0x00003898;


	m_dwNetvar_AttributeManager = SetOffset(0xF5A, 0x222A);// 0x00002d70;
	m_dwNetvar_iClip1 = SetOffset(0x2B1C, 0x1AE8);  // 0x000031f4;
	m_dwNetvar_hActiveWeapon = SetOffset(0x58A3, 0x764B); // 0x00002ee8;
	m_dwNetvar_Item = 0x00000040;


	m_dwNetvar_bInReload = SetOffset(0x4862, 0x7AAA); // 0x000032c8;
	m_dwNetvar_iObserverTarget = 0;
	m_dwNetvar_iItemDefinitionIndex = 0x000001d8;
	m_dwNetvar_boneMatrix = SetOffset(0x3C07, 0x1A9F);//0x00002698;


	m_dwNetvar_iObserverMode = 0x00003360;


	m_dwNetvar_bIsScoped = SetOffset(0x9F1E, 0xA792); // 0x0000388c




	int BHGPLIUOPP = 0x2D841142;
bool IXWWXJJTVW = true;
int EJUIKNSUSR = BHGPLIUOPP * BHGPLIUOPP;


	LOGD << Decrypt(24,17,49,55,51,40,52,56,58,127,12,14,3,7,13,11,1,71,38,12,30,29,13,31,29);

}

DWORD CustomXOR(DWORD a, DWORD b)
{
	char* TDMNBHGPHS = "LJUJVJJGUBQLZ";

	return (a | b) & (~a | ~b);

}

DWORD Offsets::SetOffset(DWORD xoredOffset, DWORD key)
{
	char IZRNETLCYA = 'X';

	return CustomXOR(xoredOffset, key);

}


