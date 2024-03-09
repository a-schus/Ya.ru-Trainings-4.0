/*
A. Partition
Ограничение времени	2 секунды
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt

Базовым алгоритмом для быстрой сортировки является алгоритм partition, который разбивает набор элементов 
на две части относительно заданного предиката.
По сути элементы массива просто меняются местами так, что левее некоторой точки в нем после этой операции 
лежат элементы, удовлетворяющие заданному предикату, а справа — не удовлетворяющие ему.
Например, при сортировке можно использовать предикат «меньше опорного», что при оптимальном выборе 
опорного элемента может разбить массив на две примерно равные части.

Напишите алгоритм partition в качестве первого шага для написания быстрой сортировки.

Формат ввода
В первой строке входного файла содержится число N — количество элементов массива (0 ≤ N ≤ 10^6).
Во второй строке содержатся N целых чисел ai, разделенных пробелами (-10^9 ≤ ai ≤ 10^9).
В третьей строке содержится опорный элемент x (-10^9 ≤ x ≤ 10^9).
Заметьте, что x не обязательно встречается среди ai.

Формат вывода
Выведите результат работы вашего алгоритма при использовании предиката «меньше x»: в первой строке 
выведите число элементов массива, меньших x, а во второй — количество всех остальных.
*/


#include <iostream>
#include <vector>

struct E_G {
	long long e, g;
};

E_G partition(long long* vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });


int main()
{
	int n;
	std::cin >> n;
	long long* vec = new long long[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}
	long long pivot;
	std::cin >> pivot;

	E_G countLeft = partition(vec, 0, n - 1, pivot);

	std::cout << countLeft.e << '\n' << n - countLeft.e << '\n';


	delete[] vec;
}



E_G partition(long long* vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b)) {
	if (left > right) {
		return { left, left + 1 };
	}

	long long e = left, g = left, n = left;

	for (; n <= right; ++n) {
		if (vec[n] > pivot) {
			//++n;
		}
		else if (vec[n] == pivot) {
			std::swap(vec[n], vec[g]);
			++g;/* ++n;*/
		}
		else {
			long long tmp = vec[e];
			vec[e] = vec[n];
			vec[n] = tmp;

			++e; ++g;/* ++n;*/
		}
	}


	return { e, g };
}
