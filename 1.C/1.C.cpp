/*
C. Слияние
Ограничение времени	5 секунд
Ограничение памяти	512Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt

Базовый алгоритм для сортировки слиянием — алгоритм слияния двух упорядоченных массивов в один 
упорядоченный массив. Эта операция выполняется за линейное время с линейным потреблением памяти. 
Реализуйте слияние двух массивов в качестве первого шага для написания сортировки слиянием.

Формат ввода
В первой строке входного файла содержится число N — количество элементов первого массива (0 ≤ N ≤ 10^6).
Во второй строке содержатся N целых чисел ai, разделенных пробелами, отсортированные по неубыванию (-10^9 ≤ ai ≤ 10^9).
В третьей строке входного файла содержится число M — количество элементов второго массива (0 ≤ M ≤ 10^6).
В третьей строке содежатся M целых чисел bi, разделенных пробелами, отсортированные по неубыванию (-10^9 ≤ bi ≤ 10^9).

Формат вывода
Выведите результат слияния этих двух массивов, то есть M + N целых чисел, разделенных пробелами, в порядке неубывания.
*/


#include <iostream>

void merge(long long* a, int aSize, long long* b, int bSize, long long* c, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });

int main()
{
	int n;
	std::cin >> n;
	long long* a = new long long[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	int m;
	std::cin >> m;
	long long* b = new long long[m];
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i];
	}

	long long* c = new long long[m + n];
	merge(a, n, b, m, c);

	for (int i = 0; i < m + n; ++i) {
		std::cout << c[i] << ' ';
	}
	std::cout << '\n';


	delete[] a; delete[] b; delete[] c;

	return 0;
}

void merge(long long* a, int aSize, long long* b, int bSize, long long* c, bool (*predicate)(long long a, long long b))
{
	if (aSize + bSize == 0) {
		return;
	} if (aSize == 0) {
		c[0] = b[0];
		return;
	} if (bSize == 0) {
		c[0] = a[0];
		return;
	}

	int cSize = aSize + bSize;
	int i = 0, j = 0, k = 0;
	for (; k < cSize && i < aSize && j < bSize; ++k) {
		if (a[i] == b[j]) {
			c[k] = a[i];
			++k;
			c[k] = b[j];
			++i; ++j;
		}
		else if (predicate(a[i], b[j])) {
			c[k] = a[i];
			++i;
		}
		else {
			c[k] = b[j];
			++j;
		}
	}

	for (; i < aSize; ++i) {
		c[k] = a[i];
		++k;
	}

	for (; j < bSize; ++j) {
		c[k] = b[j];
		++k;
	}

	return;
}
