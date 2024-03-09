/*
E. Подпалиндромы
Ограничение времени	3 секунды
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt

Строка называется палиндромом, если она читается одинаково как слева направо, так и справа налево. 
Например, строки abba, ata являются палиндромами.

Вам дана строка. Ее подстрокой называется некоторая непустая последовательность подряд идущих символов. 
Напишите программу, которая определит, сколько подстрок данной строки является палиндромами.

Формат ввода
Вводится одна строка, состоящая из прописных латинских букв. Длина строки не превышает 100000 символов.

Формат вывода
Выведите одно число — количество подстрок данной строки, которые являются палиндромами
*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

struct Ratio {
	int p;
	long long x;
};

const std::vector<Ratio> ratios{ {1000000007, 257}/*, { 1000000777, 257 } */};

std::vector<int> polynomialHash(const std::string& s, std::vector<Ratio> ratios = ::ratios);

void getPrefixes(const std::string& s, std::vector<std::vector<Ratio>>& resPrefixes, std::vector<Ratio> ratios = ::ratios);

bool isEqual(const std::vector<std::vector<Ratio>>& prefixes1,
	const std::vector<std::vector<Ratio>>& prefixes2,
	int left1, int left2, int len, std::vector<Ratio> ratios = ::ratios);

bool isEqual(const std::vector<std::vector<Ratio>>& prefixes, int left1, int left2, int len, std::vector<Ratio> ratios = ::ratios);

int palindrome(const std::vector<std::vector<Ratio>>& prefixes1, const std::vector<std::vector<Ratio>>& prefixes2, int pos, std::vector<Ratio> ratios = ::ratios);
int palindrome2(const std::vector<std::vector<Ratio>>& prefixes1, const std::vector<std::vector<Ratio>>& prefixes2, int pos, std::vector<Ratio> ratios = ::ratios);

int main()
{
	std::string s;
	std::cin >> s;
	//std::ifstream f("C:\\Users\\a-schus\\Downloads\\Telegram Desktop\\44");
	//f >> s;
	//f.close();
	std::string s2 = s;
	std::reverse(s2.begin(), s2.end());

	if (!s.empty()) {
		std::vector<std::vector<Ratio>> prefixes1(ratios.size(), std::vector<Ratio>(s.length()));
		getPrefixes(s, prefixes1);
		std::vector<std::vector<Ratio>> prefixes2(ratios.size(), std::vector<Ratio>(s.length()));
		getPrefixes(s2, prefixes2);
		std::cout << "!!!!!\n";
		int count = 0;
		for (int i = 0; i < s.size(); ++i) {
			count += palindrome(prefixes1, prefixes2, i);
		}
		std::cout << count << '\n';
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

bool isEqual(const std::vector<std::vector<Ratio>>& prefixes1, 
	const std::vector<std::vector<Ratio>>& prefixes2, 
	int left1, int left2, int len, std::vector<Ratio> ratios)
{
	bool b = true;
	for (int k = 0; k < ratios.size(); ++k) {
		unsigned long long p1, p2;
		if (left1 > 0) {
			p2 = (prefixes2[k][left2 + len - 1].p + prefixes1[k][left1 - 1].p * prefixes1[k][len].x) % ratios[k].p;
		}
		else {
			p2 = (prefixes2[k][left2 + len - 1].p) % ratios[k].p;
		}

		if (left2 > 0) {
			p1 = (prefixes1[k][left1 + len - 1].p + prefixes2[k][left2 - 1].p * prefixes2[k][len].x) % ratios[k].p;
		}
		else {
			p1 = (prefixes1[k][left1 + len - 1].p) % ratios[k].p;
		}
		if (p1 != p2)
		{
			b = false;
			break;
		}
	}
	return b;
}
int palindrome(const std::vector<std::vector<Ratio>>& prefixes1,
	const std::vector<std::vector<Ratio>>& prefixes2,
	int pos, std::vector<Ratio> ratios)
{
	int size = prefixes1[0].size();
	int count = 0;

	int max;
	pos <= size - pos - 1 ? max = pos : max = size - pos - 1;
	int min = 0;
	int mid;
	while (min <= max){
		mid = (max + min) / 2;
		if (isEqual(prefixes1, prefixes2, pos - mid, size - pos - mid - 1, mid * 2 + 1)) {
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}
	count += min;

	int pos2 = pos + 1;
	pos <= size - pos2 - 1 ? max = pos : max = size - pos2 - 1;
	min = 0;
	while (min <= max) {
		mid = (max + min) / 2;
		if (isEqual(prefixes1, prefixes2, pos - mid, size - pos - mid - 2, mid * 2 + 2)) {
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}
	count += min;
	return count;
}

int palindrome2(const std::vector<std::vector<Ratio>>& prefixes1,
	const std::vector<std::vector<Ratio>>& prefixes2,
	int pos, std::vector<Ratio> ratios)
{
	int size = prefixes1[0].size();
	int count = 1;
	for (int i = 1; pos + i < size && pos - i >= 0; ++i) {
		if (isEqual(prefixes1, prefixes2, pos - i, size - pos - i - 1, i * 2 + 1)) {
			++count;
		}
	}

	int pos2 = pos + 1;
	for (int i = 0; pos2 + i < size && pos - i >= 0; ++i) {
		if (isEqual(prefixes1, prefixes2, pos - i, size - pos - i - 2, i * 2 + 2)) {
			++count;
		}
	}

	return count;
}
