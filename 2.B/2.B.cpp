/*
B. Основание строки
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt

Строка S была записана много раз подряд, после чего от получившейся строки взяли префикс и дали вам. 
Ваша задача определить минимально возможную длину исходной строки S.

Формат ввода
В первой и единственной строке входного файла записана строка, которая содержит только латинские буквы, 
длина строки не превышает 50000 символов.

Формат вывода
Выведите ответ на задачу.
*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Ratio {
	int p;
	long long x;
};

const std::vector<Ratio> ratios{ /*{1000000007, 257}, */{ 1000000777, 257 } };

std::vector<int> polynomialHash(const std::string& s, std::vector<Ratio> ratios = ::ratios);

void getPrefixes(const std::string& s, std::vector<std::vector<Ratio>>& resPrefixes, std::vector<Ratio> ratios = ::ratios);

bool isEqual(const std::vector<std::vector<Ratio>>& prefixes, int left1, int left2, int len, std::vector<Ratio> ratios = ::ratios);

int find(const std::string& s, const std::vector<std::vector<Ratio>>& prefixes/*, int left, int size*/, std::vector<Ratio> ratios = ::ratios);



int main()
{
	std::string s;
	std::cin >> s;
	//std::ifstream f("C:\\Users\\a-schus\\Downloads\\Telegram Desktop\\15(3)");
	//f >> s;
	//f.close();
	if (!s.empty()) {
		std::vector<std::vector<Ratio>> prefixes(ratios.size(), std::vector<Ratio>(s.length()));
		getPrefixes(s, prefixes);

		std::cout << find(s, prefixes/*, 0, prefixes[0].size()*/) << '\n';
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

int find(const std::string& s, const std::vector<std::vector<Ratio>>& prefixes/*, int left, int size*/, std::vector<Ratio> ratios)
{
	int size = prefixes[0].size();
	int k = size - 2;
	for (; k >= 0 && k >= size / 2 - 1; --k) {
		if (isEqual(prefixes, 0, size - k - 1, k + 1)) {
			return size - k - 1;
		}
	}

	int n = 0;
	for (; s.length() > 3 && n < size / 2 + 1; ++n) {
		if (!(s.length() > 3 && s[n] == s[s.length() - (n + 1)] && s[s.length() - (n + 1)] == s[s.length() - (n + 2)])) {
			break;
		}
	}
	if (n > 0 && s[n] == s[0])
		++n;
	return size - n;/*(s.length() > 3 && s[0] == s[s.length() - 1] && s[s.length() - 1] == s[s.length() - 2]) ?
		size - 1 : size;*/
}
