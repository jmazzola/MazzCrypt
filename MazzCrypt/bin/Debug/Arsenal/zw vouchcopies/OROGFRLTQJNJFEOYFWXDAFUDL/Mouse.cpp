#include "Mouse.h"



namespace Mouse
{
	void Move(float x, float y)
	{
		INPUT input = { 0 };

		
		


		input.mi.dy = (LONG)y;
		input.mi.dx = (LONG)x;
		input.mi.dwFlags = MOUSEEVENTF_MOVE;

		input.type = INPUT_MOUSE;



		float UKCYOXPTTT = 76.74f;
char HGCXTACKST = 'O';
char* NAJWHFSYJI = "VNKFXDKF";

		
		SendInput(1, &input, sizeof(INPUT));

	}

	void Click(int type)
	{
		INPUT input = { 0 };


		input.type = INPUT_MOUSE;

		int UKMKAFYAWS = 0x37C048DA;
bool MOBVYYFGKJ = true;

		input.mi.dwFlags = type;

		char OHQDRGBXTH = 'X';
char KAZUZRJKYR = 'F';


		SendInput(1, &input, sizeof(INPUT));

	}
}

