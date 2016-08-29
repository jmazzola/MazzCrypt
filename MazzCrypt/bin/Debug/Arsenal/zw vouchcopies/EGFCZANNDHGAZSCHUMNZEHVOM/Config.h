// Config.h - Our config settings
#pragma once

#include "stdafx.h"



struct TriggerWeaponSettings
{
	

	float m_fRCSScale;



	int m_nDelayBefore;
	int m_nDelayAfter;
	std::vector<int> m_hitboxes;


	char JRIXJISSYD = 'P';
char* BJWAJXOWFF = "KKMYYVDMBTGKMQRWK";

};


struct TriggerSettings
{

public:

	



	bool m_bAfterburst;
	bool m_bDeathmatch;



	int m_nToggleKey;

	TriggerWeaponSettings m_tFAMAS;

	TriggerWeaponSettings m_tM4A4;
	bool m_bAntiSpectate;

	TriggerWeaponSettings m_tUSP;

	TriggerWeaponSettings m_tGlock;



	TriggerWeaponSettings m_tMP7;


	bool m_bSniperMode;

	TriggerWeaponSettings m_tDeagle;
	bool m_bRecoilControl;
	int m_nDelayBefore;
	TriggerWeaponSettings m_tTec9;
	float m_fMinSpeed;





	TriggerWeaponSettings m_tCZ75;
	TriggerWeaponSettings m_tMP9;
	TriggerWeaponSettings m_tDuelies;
	TriggerWeaponSettings m_tP2K;
	TriggerWeaponSettings m_tAUG;
	TriggerWeaponSettings m_tG3SG1;

	bool m_bInvertMouse;
	TriggerWeaponSettings m_tP90;

	bool m_bAntiJump;
	bool m_bRevolverMode;
	TriggerWeaponSettings m_tNova;
	TriggerWeaponSettings m_tRevolver;


	TriggerWeaponSettings m_tM249;

	TriggerWeaponSettings m_tMAC10;




	int m_nTargetType;
	TriggerWeaponSettings m_tGalil;
	TriggerWeaponSettings m_tUMP45;



	float m_fFOV;

	TriggerWeaponSettings m_tP250;
	TriggerWeaponSettings m_tAWP;
	TriggerWeaponSettings m_tM4A1S;

	bool m_bAntiFlash;

	int m_nDelayAfter;


	int m_nKey;
	TriggerWeaponSettings m_tScout;
	TriggerWeaponSettings m_tMag7;

	TriggerWeaponSettings m_tSawedOff;
	bool m_bMoveCheck;
	float m_fMinFlash;
	TriggerWeaponSettings m_tBizon;
	int m_nMethod;


	TriggerWeaponSettings m_tSG553;



	TriggerWeaponSettings m_tSCAR20;
	TriggerWeaponSettings m_tXM1014;
	bool m_bActive;
	bool m_bKnifebot;



	TriggerWeaponSettings m_tNegev;
	TriggerWeaponSettings m_tAK47;
	TriggerWeaponSettings m_tFiveSeven;

	bool m_bKeyHeld;



	bool m_bSprayUntilDeadMode;







	char NBDAOKDLIC = 'S';
float KRHNUVCLMP = 72.38f;


};


struct ThreadHandling
{
public:

	
	bool m_bStopUpdate;



	bool m_bStopTriggerbot;
	bool m_bStopRCS;

	bool m_bStopBSPHandler;


	float KXRSXTVMDT = 84.44f;
char APNSZYPTFK = 'E';
bool USZVUZYPGB = true;

};


class Config
{
public:

	Config() = default;

	~Config() = default;


	
	void SetInt(char* section, char* option, int nValue);
	std::string GetString(char* section, char* option);


	bool GetBool(char* section, char* option);
	int GetKey(char* section, char* option);

	bool LoadConfig();

	void Init(std::string szConfigName);
	std::vector<int> GetCommaSeperatedInts(char* section, char* option);
	void SetFloat(char* section, char* option, float fValue);



	void SetString(char* section, char* option, std::string szValue);
	int GetInt(char* section, char* option);
	std::string GetHash();
	void SetCommaSeperatedInts(char* section, char* option, std::vector<int> vValue);
	float GetFloat(char* section, char* option);





	void SetKey(char* section, char* option, int nKey);


	void SetBool(char* section, char* option, bool bValue);

	bool SaveConfig();





public:

	

	ThreadHandling m_ThreadSettings;
	std::string m_szHash;

	TriggerSettings m_TriggerSettings;



	float NTHXMBTKOK = 36.57f;
char ZWTODOIKSM = 'G';


private:

	std::string m_szConfigFile;


	char KNFJHTBPHD = 'O';

};


