#include <iostream>
#include <string>
#include <vector>

struct Ratio {
	int p;
	long long x;
};

const std::vector<Ratio> ratios{ {1000000007, 257}, { 1000000777, 257 } };

std::vector<int> polynomialHash(const std::string& s, std::vector<Ratio> ratios = ::ratios);

//std::vector<int> subPolynomialHash(const std::vector<std::vector<int>>& prefixes, int left, int len);

void getPrefixes(const std::string& s, std::vector<std::vector<Ratio>>& resPrefixes, std::vector<Ratio> ratios = ::ratios);

bool isEqual(const std::vector<std::vector<Ratio>>& prefixes, int left1, int left2, int len, std::vector<Ratio> ratios = ::ratios);



int main()
{
	std::string s;
	std::cin >> s;
	int q;
	std::cin >> q;

	std::vector<std::vector<Ratio>> prefixes(ratios.size(), std::vector<Ratio> (s.length()));
	getPrefixes(s, prefixes);


	for (int i = 0; i < q; ++i) {
		int len, left1, left2;
		std::cin >> len >> left1 >> left2;
		if (isEqual(prefixes, left1, left2, len)) {
			std::cout << "yes\n";
		}
		else {
			std::cout << "no\n";
		}
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
			p2 = (prefixes[k][left2 + len - 1].p + prefixes[k][left1 - 1].p * prefixes[k][len/* - 1*/].x) % ratios[k].p;
		}
		else {
			p2 = (prefixes[k][left2 + len - 1].p/* + prefixes[k][left1 - 1].p * prefixes[k][len - 1].x*/) % ratios[k].p;
		}

		if (left2 > 0) {
			p1 = (prefixes[k][left1 + len - 1].p + prefixes[k][left2 - 1].p * prefixes[k][len/* - 1*/].x) % ratios[k].p;
		}
		else {
			p1 = (prefixes[k][left1 + len - 1].p) % ratios[k].p;
		}
		if (p1 != p2)
			//(prefixes[k][left1 + len - 1].p + prefixes[k][left2/* - 1*/].p * prefixes[k][len - 1].x) % ratios[k].p !=
			//((prefixes[k][left2 + len - 1].p + prefixes[k][left1/* - 1*/].p * prefixes[k][len - 1].x) % ratios[k].p)) 
		{
			b = false;
			break;
		}
	}
	return b;
}
