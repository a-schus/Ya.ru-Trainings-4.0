#include <iostream>


int partition(long long *vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });

void quickSort(long long* vec, int left, int right, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });



int main()
{
	int n;
	std::cin >> n;
	long long* vec = new long long[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}

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
	
	//long long pivot = vec[(right - left) / 2 + left];

	//if ((vec[left] < vec[right] && vec[left] > pivot) ||
	//	(vec[left] > vec[right] && vec[left] < pivot)) {
	//	pivot = vec[left];
	//}
	//else if ((vec[right] < vec[left] && vec[right] > pivot) ||
	//		(vec[right] > vec[left] && vec[right] < pivot)) {
	//	pivot = vec[right];
	//}


	int p = partition(vec, left, right, pivot, predicate);

	quickSort(vec, left, p - 1);
	quickSort(vec, p, right);

	return;
}


int partition( long long* vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b)) {
	if (left == right)
		return left + 1;

	while (left <= right)
	{
		if (!predicate(vec[left], pivot))
		{
			if (!predicate(pivot, vec[right]))
			{
				//if (vec[left] != vec[right])
				//{
					std::swap(vec[left], vec[right]);
				//}
				++left;
				--right;
			}
			else --right;
		}
		else
		{
			++left;
		}
	}

	return left;
}
