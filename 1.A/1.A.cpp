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

	
//int partition(long long* vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b)) {
//		if (left > right) {
//		return left;
//	}
//	else if (left == right) {
//		if (predicate(vec[left], pivot)) {
//			return left + 1;
//		}
//		else {
//			return left;
//		}
//	}
//
//	int i = left;
//	int j = right;
//
//	while (i <= j)
//	{
//		if (!predicate(vec[i], pivot))
//		{
//			if (predicate(vec[j], pivot))
//			{
//				if (vec[i] != vec[j])
//				{
//					std::swap(vec[i], vec[j]);
//				}
//				++i;
//				--j;
//			}
//			else --j;
//		}
//		else
//		{
//			++i;
//		}
//	}
//
//	return i;
//}