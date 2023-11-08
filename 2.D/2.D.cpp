#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Ratio {
	int p;
	long long x;
};

const std::vector<Ratio> ratios{ {1000000007, 1000007}/*, { 1000000777, 257 } */};

std::vector<int> polynomialHash(const std::vector<int>& s, std::vector<Ratio> ratios = ::ratios);

void getPrefixes(const std::vector<int>& s, std::vector<std::vector<Ratio>>& resPrefixes, std::vector<Ratio> ratios = ::ratios);

bool isEqual(const std::vector<std::vector<Ratio>>& prefixes, int left1, int left2, int len, std::vector<Ratio> ratios = ::ratios);

//int z(const std::vector<std::vector<Ratio>>& prefixes, int i, std::vector<Ratio> ratios = ::ratios);

/*std::vector<int>*/ void petia(const std::vector<std::vector<Ratio>>& prefixes, /*int pos, */std::vector<Ratio> ratios = ::ratios);

int main()
{
	//std::ifstream f("C:\\Users\\a-schus\\Downloads\\Telegram Desktop\\92");
	//f >> s;
	//f.close();

	int n, m;
	std::cin >> n >> m;
	std::vector<int> vec;
	vec.resize(n * 2);
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[n + i];
		vec[n - i - 1] = vec[n + i];
	}

	//if (n % 2) {
	//	std::cout << n << '\n';
	//}
	//else {
		if (!vec.empty()) {
			std::vector<std::vector<Ratio>> prefixes(ratios.size(), std::vector<Ratio>(vec.size()));
			getPrefixes(vec, prefixes);

			petia(prefixes);
		}

	//}

	return 0;
}



std::vector<int> polynomialHash(const std::vector<int>& s, std::vector<Ratio> ratios)
{
	std::vector<int> heshs(ratios.size());

	for (int k = 0; k < ratios.size(); ++k) {
		for (int i = 0; i < s.size(); ++i) {
			heshs[k] = (heshs[k] * ratios[k].x + s[i]) % ratios[k].p;
		}
	}
	return heshs;
}

void getPrefixes(const std::vector<int>& s, std::vector<std::vector<Ratio>>& resPrefixes, std::vector<Ratio> ratios)
{
	for (int k = 0; k < ratios.size(); ++k) {
		resPrefixes[k][0].p = s[0] % ratios[k].p;
		resPrefixes[k][0].x = 1;
		for (int i = 1; i < s.size(); ++i) {
			resPrefixes[k][i].p = (resPrefixes[k][i - 1].p * ratios[k].x + s[i]) % ratios[k].p;
			resPrefixes[k][i].x = (resPrefixes[k][i - 1].x * ratios[k].x) % ratios[k].p;
		}
	}
}

bool isEqual(const std::vector<std::vector<Ratio>>& prefixes, int left1, int left2, int len, std::vector<Ratio> ratios)
{
	bool b = true;
	for (int k = 0; k < ratios.size(); ++k) {
		unsigned long long p1, p2;
		if (left1 > 0) {
			p2 = (prefixes[k][left2 + len - 1].p + prefixes[k][left1 - 1].p * prefixes[k][len].x) % ratios[k].p;
		}
		else {
			p2 = (prefixes[k][left2 + len - 1].p) % ratios[k].p;
		}

		if (left2 > 0) {
			p1 = (prefixes[k][left1 + len - 1].p + prefixes[k][left2 - 1].p * prefixes[k][len].x) % ratios[k].p;
		}
		else {
			p1 = (prefixes[k][left1 + len - 1].p) % ratios[k].p;
		}
		if (p1 != p2)
		{
			b = false;
			break;
		}
	}
	return b;
}
/*std::vector<int>*/ void petia(const std::vector<std::vector<Ratio>>& prefixes, std::vector<Ratio> ratios)
{
	int pos = prefixes[0].size() / 4;
	int pos0 = prefixes[0].size() / 2;

	for (; pos > 0; --pos) {
		if (isEqual(prefixes, pos0 - pos * 2 , pos0, pos)) {
			std::cout << pos0 - pos << ' ';
		}
		
	}
	std::cout << pos0 << '\n';
	//return std::vector<int>();
}
