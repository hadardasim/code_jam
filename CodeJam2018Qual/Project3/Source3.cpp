#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <math.h>
#include <iomanip>

// question: cubic UFO
#define PI 3.1415926535897932384626433832795028

struct vector3
{
	double x, y, z;
	vector3(double _x, double _y, double _z): x(_x), y(_y), z(_z)
	{

	}
	void print()
	{
		std::cout << std::setprecision(12) << x << " " << y << " " << z << std::endl;
	}

	vector3 rotZ(double radians)
	{
		vector3 res = *this;
		double cs = cos(radians);
		double sn = sin(radians);
		res.x = +cs * x + sn * y;
		res.y = -sn * x + cs * y;
		return res;
	}

	vector3 rotX(double radians)
	{
		vector3 res = *this;
		double cs = cos(radians);
		double sn = sin(radians);
		res.z = +cs * z + sn * y;
		res.y = -sn * z + cs * y;
		return res;
	}
};

int main()
{
	int nTests;
	std::cin >> nTests;

	double sqrt2 = sqrt(2.0);
	double sqrt3 = sqrt(3.0);

	double gamma0 = asin(sqrt(2.0 / 3.0));

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		double space;
		std::cin >> space;
		std::cout << "Case #" << nCase + 1 << ":" << std::endl;

		vector3 center0(0.5, 0.0, 0.0);
		vector3 center1(0.0, 0.5, 0.0);
		vector3 center2(0.0, 0.0, 0.5);

		if (space < sqrt2)
		{
			double alpha = PI/4.0 - acos(space / sqrt2);
			center0.rotZ(alpha).print();
			center1.rotZ(alpha).print();
			center2.print();
		}
		else
		{
			center0 = center0.rotZ(PI / 4.0);
			center1 = center1.rotZ(PI / 4.0);
			// S = cos(gamma)*sqrt2 + sin(gamma)
			// gamma = x-rot
			// S/sqrt3 = sin(gamma + gamma0) = cos(gamma)sin(gamma0) + sin(gamma)cos(gamma0)
			// sin(gamma0) = sqrt(2/3)
			
			if (space > sqrt3)
				space = sqrt3;
			double gamma = asin(space/sqrt3)-gamma0;

			center0.rotX(gamma).print();
			center1.rotX(gamma).print();
			center2.rotX(gamma).print();
			

		}
	}

	return 0;
}
