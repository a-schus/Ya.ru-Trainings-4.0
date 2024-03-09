/*
B. Быстрая сортировка
Ограничение времени	10 секунд
Ограничение памяти	512Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt

Реализуйте быструю сортировку, используя алгоритм из предыдущей задачи.

На каждом шаге выбирайте опорный элемент и выполняйте partition относительно него. 
Затем рекурсивно запуститесь от двух частей, на которые разбился исходный массив.

Формат ввода
В первой строке входного файла содержится число N — количество элементов массива (0 ≤ N ≤ 10^6).
Во второй строке содержатся N целых чисел ai, разделенных пробелами (-10^9 ≤ ai ≤ 10^9).

Формат вывода
Выведите результат сортировки, то есть N целых чисел, разделенных пробелами.
*/



#include <iostream>
#include <fstream>

struct E_G {
	long long e, g;
};

void quickSort(long long* vec, int left, int right, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });

E_G partition(long long* vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b));


int main()
{
	int n;

	//std::ifstream f("D:\\!!! Downloads !!!\\Telegram Desktop\\11");
	//f >> n;
	//long long* vec = new long long[n];
	//for (int i = 0; i < n; ++i) {
	//	f >> vec[i];
	//	//std::cout << vec[i] << ' ';
	//}
	//std::cout << "\n!!!!!!\n";
	//f.close();
	
	
	
	std::cin >> n;
	long long* vec = new long long[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}



	bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; };

	quickSort(vec, 0, n - 1, predicate);

	//int ii = 1;
	//for (; ii < n; ++ii) {
	//	if (vec[ii] < vec[ii - 1]) break;
	//}

	//std::cout << (ii == n ? "Yes\n" : "No\n");

	for (int i = 0; i < n; ++i) {
		std::cout << vec[i] << ' ';
	}
	std::cout << '\n';

	delete[] vec;

}


void quickSort(long long* vec, int left, int right, bool(*predicate)(long long a, long long b))
{
	if (left >= right)
		return;

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// Индекс для pivot выбирать только случайным образом
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	srand(time(NULL));
	long long pivot = vec[left + rand() % (right - left + 1)];

	E_G p = partition(vec, left, right, pivot, predicate);

	quickSort(vec, left, p.e - 1);
	quickSort(vec, p.g, right);

	//if (p.e - 1 > left) quickSort(vec, left, p.e - 1);
	//if (p.g < right) quickSort(vec, p.g, right);

	return;
}


E_G partition(long long* vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b)) {

	long long e = left, g = left, n = left;

	for (; n <= right; ++n) {
		if (predicate(vec[n], pivot)) {
			if (e == g) {
				std::swap(vec[n], vec[g]);
				++e; ++g;
			}
			else if (g == n) {
				std::swap(vec[e], vec[g]);
				++e; ++g;
			}
			else {
				long long tmp = vec[e];
				vec[e] = vec[n];
				vec[n] = vec[g];
				vec[g] = tmp;
				++e; ++g;
			}
		}
		else if (vec[n] == pivot) {
			std::swap(vec[n], vec[g]);
			++g;
		}
	}

	return { e, g };
}
