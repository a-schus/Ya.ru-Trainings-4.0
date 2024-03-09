/*
A. Равенство подстрок
Ограничение времени	15 секунд
Ограничение памяти	512Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt

Дана строка S, состоящая из строчных латинских букв.

Определите, совпадают ли строки одинаковой длины L, начинающиеся с позиций A и B.

Формат ввода
В первой строке записана S (1 ≤ |S| ≤ 2 ⋅ 10^5), состоящая из строчных латинских букв.

Во второй строке записано число Q (1 ≤ Q ≤ 2 ⋅ 10^5) — количество запросов.

В следющих Q строках записаны запросы: целые числа L, A и B (1 ≤ L ≤ |S|, 0 ≤ A, B ≤ (|S| - L)) — длина подстрок 
и позиции, с которых они начинаются.

Формат вывода
Если строки совпадают — выведите "yes", иначе — "no".
*/


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
