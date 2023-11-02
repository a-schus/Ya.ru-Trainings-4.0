#include <iostream>
#include <cmath>

int main()
{
	unsigned long long a, b, n;

	std::cin >> a >> b >> n;

	std::cout << (a > ceil((float)b / n) ? "Yes" : "No") << '\n';
}