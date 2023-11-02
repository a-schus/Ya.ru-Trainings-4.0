#include <iostream>
#include <math.h>

const float pi = 3.14159265;

struct Vec {
	double x, y;
	double len() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}
};

int main()
{
	Vec v1, v2;
	std::cin >> v1.x >> v1.y >> v2.x >> v2.y;

	double ang1 = atan2(v1.y, v1.x);
	if (abs(round(ang1) - ang1) < 0.00001) ang1 = round(ang1);
	double ang2 = atan2(v2.y, v2.x);
	if (abs(round(ang2) - ang2) < 0.00001) ang2 = round(ang2);
	double ang = abs(ang1 - ang2);

	if (ang >= pi) ang = 2 * pi - ang;

	double len1 = v1.len(), len2 = v2.len();
	if (abs(round(len1) - len1) < 0.00001) len1 = round(len1);
	if (abs(round(len2) - len2) < 0.00001) len2 = round(len2);

	if (len1 > len2) {
		std::swap(v1, v2);
		std::swap(len1, len2);
	}

	double res;

	if (ang < 2) {
		res = ang * len1 + len2 - len1;
	}
	else {
		res = len1 + len2;
	}

	std::cout << std::fixed << res << '\n';

	return 0;
}
