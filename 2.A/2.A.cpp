#include <iostream>
#include <string>
#include <vector>

struct Ratio {
	int p;
	long long x;
};

const std::vector<Ratio> ratios{ {1000000007, 257} };

std::vector<int> polynomialHash(const std::string& s, std::vector<Ratio> ratios = ::ratios);

std::vector<int> subPolynomialHash(const std::vector<std::vector<int>>& prefixes, int left, int len);

void getPrefixes(const std::string& s, std::vector<std::vector<int>>& resPrefixes, std::vector<Ratio> ratios = ::ratios);



int main()
{

}

std::vector<int> polynomialHash(const std::string& s, std::vector<Ratio> ratios)
{
	std::vector<int> heshs(ratios.size());

	for (int k = 0; k < ratios.size(); ++k) {
		for (int i = 0; i < s.length(); ++i) {
			heshs[k] += (heshs[k] * ratios[k].x + s[i]) % ratios[k].p;
		}
	}
	return heshs;
}

std::vector<int> subPolynomialHash(const std::vector<std::vector<int>>& prefixes, int left, int len)
{


	return std::vector<int>();
}

void getPrefixes(const std::string& s, std::vector<std::vector<int>>& resPrefixes, std::vector<Ratio> ratios)
{
	for (int k = 0; k < ratios.size(); ++k) {
		for (int i = 0; i < s.length(); ++i) {
			resPrefixes[k][i] = polynomialHash(s.substr(0, i + 1))[k];
		}
	}
}
