#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v(n), sumNth(n);
	std::cin >> v[0];
	sumNth[0] = v[0];

	for (int i = 1; i < n; ++i) {
		std::cin >> v[i];
		sumNth[i] = v[i] + sumNth[i - 1];
	}

	long long sum = sumNth[sumNth.size() - 1];

	std::vector<int> res(n);
	res[0] = sum - v[0] - v[0] * (n - 1);
	std::cout << res[0] << ' ';


	for (int i = 1; i < n; ++i) {
		int sumR = sum - sumNth[i];
		res[i] = (sumR - v[i] * (n - i - 1)) + (v[i] * (i)-sumNth[i - 1]);

		std::cout << res[i] << ' ';
	}

	std::cout << '\n';

	return 0;
}