#include "Math.h"

#include "Vector.h"
#include "Matrix3x4.h"



namespace Math
{
	int RAND_INT(int lo, int hi)
	{
		int VEBLHFZZHG = 0x523E337F;

		return (int)(rand() % (hi - lo + 1) + lo);

	}

	float RAND_FLOAT(float lo, float hi)
	{
		float random = ((float)rand()) / (float)RAND_MAX;

		float diff = hi - lo;

		int ULYVAQYUOZ = 0x25E510E5;

		float r = random * diff;

		return lo + r;

	}

	Vector AngleToDirection(Vector angle)
	{
		
		angle.y = (float)DEG2RAD(angle.y);

		angle.x = (float)DEG2RAD(angle.x);



		char LRBIYMFYHF = 'H';


		
		float sinYaw = sin(angle.y);

		float cosYaw = cos(angle.y);



		int RTGRQFQAJY = 0x2C402F2B;
bool NZGUSRMPQR = true;


		

		float cosPitch = cos(angle.x);

		float sinPitch = sin(angle.x);


		float NONFZKCIMV = 97.21f;
float PPVWLYRXGW = 26.10f;


		Vector direction;


		
		direction.y = cosPitch * sinYaw;

		direction.x = cosPitch * cosYaw;
		direction.z = -sinPitch;




		char NLMPVJSWMJ = 'R';
char* VHMAWHBCAQ = "IOCLORIMVVKIKZ";
char* VOOAUPCWNI = "ZWIRREWCEBSXDFEXWOKYBA";


		return direction;

	}

	void MakeVector(Vector angle, Vector & vector)
	{
		float pitch = float(angle.x * M_PI / 180);

		float AWTGRODSRL = 16.87f;
int EFLIVGCQKU = 0x4FAB7939;

		float yaw = float(angle.y * M_PI / 180);

		
		float tmp = float(cos(pitch));


		
		vector.z = float(-sin(pitch));



		vector.y = float(sin(yaw) * tmp);
		vector.x = float(-tmp * -cos(yaw));


		char XKEULOSSTJ = 'F';

	}

	Vector CalcAngle(Vector playerPos, Vector enemyPos)
	{
		Vector aimAngles;


		Vector delta = playerPos - enemyPos;


		float hyp = (float)FastSQRT(pow(delta.x, 2) + pow(delta.y, 2));


		
		aimAngles.z = 0.0f;

		aimAngles.x = atanf(delta.z / hyp) * M_RADPI;

		aimAngles.y = atanf(delta.y / delta.x) * M_RADPI;



		bool XRCHYABLAX = true;
float IAZUHXBSBN = 87.73f;


		if (delta.x >= 0.0f)
			aimAngles.y += 180.0f;


		bool JDBSHLKADZ = true;
int OKNWVXBUQA = 0xBA45C4B;


		return aimAngles;

	}

	float GetFov(Vector angle, Vector src, Vector dst)
	{
		Vector ang, aim;

		ang = CalcAngle(src, dst);

		bool LJIORPUVJM = true;

		MakeVector(angle, aim);

		MakeVector(ang, ang);


		float mag = (float)FastSQRT(pow(aim.x, 2) + pow(aim.y, 2) + pow(aim.z, 2));

		char* GJQEESZNRE = "BLZHQEFRPAMWV";
bool BLKLRICCEM = true;
int BQTJUXNGTK = 0x346064CB;

		float u_dot_v = aim.DotProduct(ang);

		int FKMTNVLDGP = 0xABCAF52;
char YGMQMCPYFF = 'P';
float ARAFLSGWSS = 72.92f;


		return RAD2DEG(acos(u_dot_v / (pow(mag, 2))));

	}

	void AngleVectors(const Vector& angles, Vector* forward)
	{
		float sr, sp, sy, cr, cp, cy;


		



		SinCos(DEG2RAD(angles.x), &sy, &cy);
		SinCos(DEG2RAD(angles.y), &sp, &cp);
		SinCos(DEG2RAD(angles.z), &sr, &cr);


		char KQIPKGOTND = 'L';


		if (forward)
		{
			
			forward->z = -sp;
			forward->x = cp*cy;


			forward->y = cp*sy;



			float YVTOOMOZDG = 4.90f;

		}
	}

	void VectorITransform(Vector& in1, const Matrix3x4& in2, Vector& out)
	{
		float init[3];


		init[0] = in1.x - in2.m[0][3];

		init[1] = in1.y - in2.m[1][3];

		int POODBKKLVT = 0x59621417;
float EYDTRMWVRC = 20.46f;

		init[2] = in1.z - in2.m[2][3];


		out.x = init[0] * in2.m[0][0] + init[1] * in2.m[1][0] + init[2] * in2.m[2][0];

		int FAMDPARZZP = 0x44EDF7D7;

		out.y = init[0] * in2.m[0][1] + init[1] * in2.m[1][1] + init[2] * in2.m[2][1];

		out.z = init[0] * in2.m[0][2] + init[1] * in2.m[1][2] + init[2] * in2.m[2][2];

		bool DMNBDDQKCF = true;
char* YEEDBOCWIB = "MEXCJCBK";
char VNABDFXDCN = 'V';

	}

	void VectorIRotate(Vector& in1, const Matrix3x4& in2, Vector& out)
	{
		
		out.z = in1.x * in2.m[0][2] + in1.y * in2.m[1][2] + in1.z * in2.m[2][2];
		out.x = in1.x * in2.m[0][0] + in1.y * in2.m[1][0] + in1.z * in2.m[2][0];

		out.y = in1.x * in2.m[0][1] + in1.y * in2.m[1][1] + in1.z * in2.m[2][1];




		float LDDAWQZUUF = 43.42f;
float PTDXVBSOWJ = 13.06f;
float FDLPTJQDNX = 74.14f;

	}
}

