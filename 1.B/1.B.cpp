#include <iostream>
#include <fstream>

struct E_G {
	long long e, g;
};

//int partition(long long *vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });

void quickSort(long long* vec, int left, int right, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });

E_G partition(long long* vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b));


int main()
{
	int n;

	//std::ifstream f("C:\\Users\\a - schus\\Downloads\\Telegram Desktop\\19(4)");

	std::cin >> n;
	//f >> n;
	long long* vec = new long long[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
		//f >> vec[n];
	}

	//f.close();

	bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; };

	quickSort(vec, 0, n - 1, predicate);

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

	long long pivot = vec[left];

	//srand(time(NULL));
	//long long pivot = vec[left + rand() % (right - left + 1)];
	
	//long long pivot = vec[(right - left) / 2 + left];

	//if ((vec[left] < vec[right] && vec[left] > pivot) ||
	//	(vec[left] > vec[right] && vec[left] < pivot)) {
	//	pivot = vec[left];
	//}
	//else if ((vec[right] < vec[left] && vec[right] > pivot) ||
	//		(vec[right] > vec[left] && vec[right] < pivot)) {
	//	pivot = vec[right];
	//}

	//
	//std::cout << " Pivot " << pivot << ' ';
	//

	E_G p = partition(vec, left, right, pivot, predicate);

	//
	//std::cout << "E: " << p.e << " G: " << p.g << '\t';
	//for (int i = 0; i < 5; ++i) {
	//	std::cout << vec[i] << ' ';
	//}
	//std::cout << '\n';
	//


	quickSort(vec, left, p.e - 1);
	quickSort(vec, p.g, right);

	return;
}


E_G partition(long long* vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b)) {
	//if (left > right) {
	//	return { left, left + 1 };
	//} else if (left == right) {
	//	return { left - 1, left };
	//}

	long long e = left, g = left, n = left;

	for (; n <= right; ++n) {
		if (predicate(vec[n], pivot)) {
			long long tmp = vec[e];
			vec[e] = vec[n];
			vec[n] = vec[g];
			vec[g] = tmp;

			++e; ++g;/* ++n;*/
		}
		else if (vec[n] == pivot) {
			std::swap(vec[n], vec[g]);
			++g;/* ++n;*/
		}
	}

	return { e, g };
}

//int partition( long long* vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b)) {
//	if (left == right)
//		return left + 1;
//
//	while (left <= right)
//	{
//		if (!predicate(vec[left], pivot))
//		{
//			if (!predicate(pivot, vec[right]))
//			{
//				//if (vec[left] != vec[right])
//				//{
//					std::swap(vec[left], vec[right]);
//				//}
//				++left;
//				--right;
//			}
//			else --right;
//		}
//		else
//		{
//			++left;
//		}
//	}
//
//	return left;
//}
