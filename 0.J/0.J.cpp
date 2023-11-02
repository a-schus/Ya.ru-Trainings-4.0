#include <iostream>

void foo(long long n, long long a, long long b);

int main()
{
	long long t, n, a, b;
	std::cin >> t;

	for (long long i = 0; i < t; ++i) {
		std::cin >> n >> a >> b;
		foo(n, a, b);
	}

	return 0;
}

void foo(long long n, long long a, long long b) {
	long long k = n / a;
	if (n - k * a <= k * (b - a)) {
		std::cout << "YES" << '\n';
	}
	else {
		std::cout << "NO" << '\n';
	}
}