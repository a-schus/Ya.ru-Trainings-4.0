#include <iostream>
#include <vector>


int partition(std::vector<long long> vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b) = [](long long a, long long b) { return a < b; });


int main()
{
	int n;
	std::cin >> n;
	std::vector<long long> vec(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}
	long long pivot;
	std::cin >> pivot;

	int countLeft = partition(vec, 0, vec.size() - 1, pivot);

	std::cout << countLeft << '\n' << vec.size() - countLeft << '\n';
}



int partition(std::vector<long long> vec, int left, int right, long long pivot, bool (*predicate)(long long a, long long b)) {
	if (left > right) {
		return left;
	}
	else if (left == right) {
		if (predicate(vec[left], pivot)) {
			return left + 1;
		}
		else {
			return left;
		}
	}

	int i = left;
	int j = right;

	while (i <= j)
	{
		if (!predicate(vec[i], pivot))
		{
			if (predicate(vec[j], pivot))
			{
				if (vec[i] != vec[j])
				{
					std::swap(vec[i], vec[j]);
				}
				++i;
				--j;
			}
			else --j;
		}
		else
		{
			++i;
		}
	}

	return i;
}

//
//void fastSort(int arr[50], long long start, long long end)
//{
//
//	srand(time(NULL));
//	int pivot = arr[start + rand() % (end - start + 1)];
//
//	long long i = start;
//	long long j = end;
//
//	while (i <= j)
//	{
//		if (arr[i] >= pivot)
//		{
//			if (arr[j] <= pivot)
//			{
//				if (arr[i] != arr[j])
//				{
//					int buf = arr[i];
//					arr[i] = arr[j];
//					arr[j] = buf;
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
//	fastSort(arr, start, j);
//	fastSort(arr, i, end);
//}
