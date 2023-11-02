#include <iostream>
#include <vector>



int partition(std::vector<long long>& vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });

void quickSort(std::vector<long long>& vec, int left, int right, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });


int main()
{
	int n;
	std::cin >> n;
	std::vector<long long> vec(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}

	quickSort(vec, 0, vec.size() - 1/*, [](long long a, long long b) { return a < b; }*/);

	for (int i = 0; i < n; ++i) {
		std::cout << vec[i] << ' ';
	}
	std::cout << '\n';

}


void quickSort(std::vector<long long>& vec, int left, int right, bool(*predicate)(long long a, long long b))
{
	if (left >= right)
		return;

	long long pivot = vec[right / 2];

	//if ((vec[left] < vec[right] && vec[left] > pivot) ||
	//	(vec[left] > vec[right] && vec[left] < pivot)) {
	//	pivot = vec[left];
	//}
	//else if ((vec[right] < vec[left] && vec[right] > pivot) ||
	//		(vec[right] > vec[left] && vec[right] < pivot)) {
	//	pivot = vec[right];
	//}

	//bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; };

	int p = partition(vec, left, right, pivot, predicate);

	quickSort(vec, left, p - 1);
	quickSort(vec, p, right);

	return;
}


int partition(std::vector<long long>& vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b)) {
	
	if (left == right) {
		if (vec[left] < pivot) {
			return left + 1;
		}
		else {
			return left;
		}
	}

	//loop forever
	//	while A[i] < pivot
	//		i : = i + 1
	//		while A[j] > pivot
	//			j : = j - 1
	//			if i >= j then
	//				return j
	//				swap A[i++] with A[j--]
	
	while (true) {
		while (vec[left] < pivot) 
			++left;
		while (vec[right] > pivot) 
			--right;
		if (left >= right)
			return right;
		std::swap(vec[left], vec[right]);
	}

	/*while (left <= right)
	{
		if (vec[left] >= pivot)
		{
			if (pivot >= vec[right])
			{
				if (vec[left] != vec[right])
				{
					std::swap(vec[left], vec[right]);
				}
				++left;
				--right;
			}
			else --right;
		}
		else
		{
			++left;
		}
	}*/

	return left;
}
