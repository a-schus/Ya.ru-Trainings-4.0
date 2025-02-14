/*
D. Сортировка слиянием
Ограничение времени	15 секунд
Ограничение памяти	512Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt

Реализуйте сортировку слиянием, используя алгоритм из предыдущей задачи.

На каждом шаге делите массив на две части, сортируйте их независимо и сливайте с помощью уже реализованной функции.

Формат ввода
В первой строке входного файла содержится число N — количество элементов массива (0 ≤ N ≤ 10^6).
Во второй строке содержатся N целых чисел ai, разделенных пробелами (-10^9 ≤ ai ≤ 10^9).

Формат вывода
Выведите результат сортировки, то есть N целых чисел, разделенных пробелами, в порядке неубывания.
*/


#include <iostream>

void merge(long long* c, int aSize, int bSize/*, int cSize*/, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });

void mergeSort(long long* c, int cSize, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });


int main()
{
	int n;
	std::cin >> n;
	long long* a = new long long[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	mergeSort(a, n);

	for (int i = 0; i <  n; ++i) {
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';

	delete[] a;

	return 0;
}





void merge(long long* c, int aSize, int bSize/*, int cSize*/, bool (*predicate)(long long a, long long b)) {
	if (aSize + bSize == 0) {
		return;
	} /*if (aSize == 0 || bSize == 0) {
		return;
	}*/

	long long* tmp = new long long[aSize];
	for (int i = 0; i < aSize; ++i) {
		tmp[i] = c[i];
	}

	int cSize = aSize + bSize;
	int i = 0, j = aSize, k = 0;
	for (; k < cSize && i < aSize && j < bSize + aSize; ++k) {
		if (tmp[i] == c[j]) {
			c[k] = tmp[i];
			++k;
			c[k] = c[j];
			++i; ++j;
		}
		else if (predicate(tmp[i], c[j])) {
			c[k] = tmp[i];
			++i;
		}
		else {
			c[k] = c[j];
			//std::swap(c[k], c[j]);
			++j;
		}
	}

	for (; i < aSize; ++i) {
		c[k] = tmp[i];
		++k;
	}

	for (; j < bSize; ++j) {
		c[k] = c[j];
		++k;
	}

	delete[] tmp;
	return;
}

void mergeSort(long long* c, int cSize, bool(*predicate)(long long a, long long b))
{
	if (cSize <= 1) {
		return;
	} if (cSize == 2) {
		if (predicate(c[1], c[0])) {
			std::swap(c[1], c[0]);
			return;
		}
	}

	int mid = cSize / 2;
	mergeSort(c, mid);
	mergeSort(c + mid, cSize - mid);
	merge(c, mid, cSize - mid);

	return;
}
