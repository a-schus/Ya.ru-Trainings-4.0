#include <iostream>
#include <string>
#include <vector>

struct Ratio {
	int p;
	long long x;
};

const std::vector<Ratio> ratios{ {1000000007, 257}, { 1000000777, 257 } };

std::vector<int> polynomialHash(const std::string& s, std::vector<Ratio> ratios = ::ratios);

void getPrefixes(const std::string& s, std::vector<std::vector<Ratio>>& resPrefixes, std::vector<Ratio> ratios = ::ratios);

bool isEqual(const std::vector<std::vector<Ratio>>& prefixes, int left1, int left2, int len, std::vector<Ratio> ratios = ::ratios);

int find(const std::vector<std::vector<Ratio>>& prefixes, std::vector<Ratio> ratios = ::ratios);



int main()
{
	std::string s;
	std::cin >> s;

	if (!s.empty()) {
		std::vector<std::vector<Ratio>> prefixes(ratios.size(), std::vector<Ratio>(s.length()));
		getPrefixes(s, prefixes);

		std::cout << find(prefixes) << '\n';
	}
	else {
		std::cout << '0' << '\n';
	}

	return 0;
}



std::vector<int> polynomialHash(const std::string& s, std::vector<Ratio> ratios)
{
	std::vector<int> heshs(ratios.size());

	for (int k = 0; k < ratios.size(); ++k) {
		for (int i = 0; i < s.length(); ++i) {
			heshs[k] = (heshs[k] * ratios[k].x + s[i]) % ratios[k].p;
		}
	}
	return heshs;
}

void getPrefixes(const std::string& s, std::vector<std::vector<Ratio>>& resPrefixes, std::vector<Ratio> ratios)
{
	for (int k = 0; k < ratios.size(); ++k) {
		resPrefixes[k][0].p = s[0] % ratios[k].p;
		resPrefixes[k][0].x = 1;
		for (int i = 1; i < s.length(); ++i) {
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

int find(const std::vector<std::vector<Ratio>>& prefixes, std::vector<Ratio> ratios)
{
	int min = 0, size = prefixes[0].size(), max = prefixes[0].size() - 1;
	int mid = ceil((float)size / 2);
	while (min < max) {
		if (isEqual(prefixes, 0, size - mid - 1, mid)) {
			min = mid + 1;
			mid = (max - min/* + 1*/) / 2 + min;
		}
		else {
			max = mid - 1;
			mid = (max - min/* + 1*/) / 2 + min;
		}
	}

	return min = max ? min - 1 : prefixes[0].size();
}
