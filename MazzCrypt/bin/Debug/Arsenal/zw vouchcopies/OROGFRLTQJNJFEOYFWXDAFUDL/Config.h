// Config.h - Our config settings
#pragma once

#include "stdafx.h"



struct TriggerWeaponSettings
{
	
	float m_fRCSScale;

	int m_nDelayAfter;


	std::vector<int> m_hitboxes;

	int m_nDelayBefore;


	char* ZPOYEFTWER = "OVJSBTQHGLPAEXPJDEZHBI";

};


struct TriggerSettings
{

public:

	



	int m_nKey;

	bool m_bKeyHeld;

	bool m_bInvertMouse;



	TriggerWeaponSettings m_tAWP;
	TriggerWeaponSettings m_tBizon;
	TriggerWeaponSettings m_tSG553;

	int m_nMethod;
	TriggerWeaponSettings m_tRevolver;


	TriggerWeaponSettings m_tG3SG1;
	TriggerWeaponSettings m_tM249;

	TriggerWeaponSettings m_tP90;
	bool m_bAntiJump;


	TriggerWeaponSettings m_tScout;


	TriggerWeaponSettings m_tM4A4;
	int m_nDelayAfter;


	TriggerWeaponSettings m_tSCAR20;
	TriggerWeaponSettings m_tUSP;

	bool m_bDeathmatch;
	TriggerWeaponSettings m_tXM1014;


	TriggerWeaponSettings m_tP250;
	TriggerWeaponSettings m_tGalil;

	bool m_bAfterburst;
	bool m_bRevolverMode;
	bool m_bSniperMode;
	TriggerWeaponSettings m_tAUG;
	TriggerWeaponSettings m_tGlock;

	TriggerWeaponSettings m_tMP7;

	bool m_bRecoilControl;


	TriggerWeaponSettings m_tTec9;
	TriggerWeaponSettings m_tSawedOff;
	bool m_bActive;
	TriggerWeaponSettings m_tNova;

	float m_fMinFlash;




	TriggerWeaponSettings m_tMP9;


	bool m_bAntiSpectate;


	int m_nToggleKey;
	TriggerWeaponSettings m_tP2K;
	int m_nDelayBefore;
	TriggerWeaponSettings m_tFAMAS;

	TriggerWeaponSettings m_tFiveSeven;
	TriggerWeaponSettings m_tMag7;

	TriggerWeaponSettings m_tUMP45;

	TriggerWeaponSettings m_tMAC10;


	bool m_bSprayUntilDeadMode;

	TriggerWeaponSettings m_tNegev;
	TriggerWeaponSettings m_tDuelies;
	float m_fMinSpeed;


	TriggerWeaponSettings m_tM4A1S;


	bool m_bAntiFlash;


	TriggerWeaponSettings m_tAK47;

	float m_fFOV;


	bool m_bMoveCheck;





	TriggerWeaponSettings m_tDeagle;
	bool m_bKnifebot;
	int m_nTargetType;
	TriggerWeaponSettings m_tCZ75;



	char VNMHLJAWDP = 'O';
int XQPZWDJLYU = 0x3FEA53D8;


};


struct ThreadHandling
{
public:

	
	bool m_bStopBSPHandler;
	bool m_bStopRCS;

	bool m_bStopTriggerbot;
	bool m_bStopUpdate;





	char NLZYZKPVRG = 'K';
int HODHAAFPDA = 0x292D2A90;
float SZLVIJHDVV = 98.90f;

};


class Config
{
public:

	Config() = default;

	~Config() = default;


	

	void SetString(char* section, char* option, std::string szValue);
	float GetFloat(char* section, char* option);
	void SetCommaSeperatedInts(char* section, char* option, std::vector<int> vValue);


	bool GetBool(char* section, char* option);
	void SetKey(char* section, char* option, int nKey);
	std::vector<int> GetCommaSeperatedInts(char* section, char* option);
	bool SaveConfig();
	bool LoadConfig();
	int GetKey(char* section, char* option);
	int GetInt(char* section, char* option);




	std::string GetString(char* section, char* option);
	void Init(std::string szConfigName);


	void SetInt(char* section, char* option, int nValue);

	std::string GetHash();


	void SetFloat(char* section, char* option, float fValue);

	void SetBool(char* section, char* option, bool bValue);







public:

	


	ThreadHandling m_ThreadSettings;
	TriggerSettings m_TriggerSettings;
	std::string m_szHash;



	char OEOEIJJDSE = 'P';
float CGVIDMGWJS = 30.05f;


private:

	std::string m_szConfigFile;


	char* HFSFWPECIU = "ZQOSXLQKEFPHDEZQ";
float YWWPJXBDLM = 32.95f;
int IZYBVDWSDL = 0x1E83D7B1;

};


