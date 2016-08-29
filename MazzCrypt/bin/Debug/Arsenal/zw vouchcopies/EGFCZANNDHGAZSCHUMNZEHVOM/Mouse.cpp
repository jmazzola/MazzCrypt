#include "Mouse.h"



namespace Mouse
{
	void Move(float x, float y)
	{
		INPUT input = { 0 };

		
		
		input.mi.dx = (LONG)x;
		input.mi.dy = (LONG)y;


		input.type = INPUT_MOUSE;

		input.mi.dwFlags = MOUSEEVENTF_MOVE;



		int FEUNSVVCHQ = 0x5176BE46;
FEUNSVVCHQ = FEUNSVVCHQ + FEUNSVVCHQ;
char DVQWLTXLII = 'L';

		
		SendInput(1, &input, sizeof(INPUT));

	}

	void Click(int type)
	{
		INPUT input = { 0 };


		input.type = INPUT_MOUSE;

		int FPJQMDRGAB = 0x63D49E5D;

		input.mi.dwFlags = type;

		char* FGJAKNXBZY = "TYERLSZPGPEHUZ";
int KWKZWXPZGS = 0x55A6378B;
float IOKSBJSBJQ = 9.19f;


		SendInput(1, &input, sizeof(INPUT));

	}
}

