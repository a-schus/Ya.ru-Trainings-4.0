#include <iostream>
#include <vector>
#include <algorithm>

void foo(const std::vector<int>& vec, int l, int r);

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}

	int l, r;
	for (int i = 0; i < m; ++i) {
		std::cin >> l >> r;
		foo(vec, l, r);
	}

	return 0;
}


void foo(const std::vector<int>& vec, int l, int r) {
	while (l < r) {
		if (vec[l] == vec[l + 1]) {
			++l;
		}
		else {
			std::cout << std::max(vec[l], vec[l + 1]) << '\n';
			return;
		}
	}
	std::cout << "NOT FOUND" << '\n';
}
