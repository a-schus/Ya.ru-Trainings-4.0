#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	long long k;
	std::cin >> k;

	long long n;
	std::cin >> n;

	std::vector<long long> a(n);
	for (long long i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	unsigned long long res = 0;

	for (long long i = n - 1; i > 0; --i) {
		if (a[i] != 0) {
			if (a[i] < 0) {
				a[i - 1] += a[i];
				a[i] = 0;
			}
			else {
				long long shortfall = k - (a[i] % k);
				if (shortfall < k) {
					a[i] += shortfall;
					a[i - 1] -= shortfall;
				}
				res += a[i] / k * (i + 1) * 2;
			}
		}
	}
	if (a[0] <= 0) {
		//a[0] = 0;
	}
	else if (a[0] < k) {
		res += 2;
	}
	else {
		res += a[0] / k * 2;
		if (a[0] % k) res += 2;
	}

	std::cout << res << '\n';
}