#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	int maxL = 0;
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> vec(n, std::vector<int>(m, 0));

	int t;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			std::cin >> t;
			vec[i][j] = t;
		}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (vec[i][j] != 0) {
				vec[i][j] = std::min(vec[i - 1][j - 1], std::min(vec[i][j - 1], vec[i - 1][j])) + 1;
				if (vec[i][j] > maxL) maxL = vec[i][j];
			}
		}
	}

	std::cout << maxL << '\n';

	return 0;
}



//int findSquare(const std::vector<std::vector<bool>>& vec, int row, int col, int n, int m) {
//	int res = 1;
//	int endRow;
//	int endCol;
//	int endRow1 = n - row;
//	int endCol1 = m - col;
//	bool isRow = true;
//
//	for (int i = 1; i < endRow1 && i < endCol1; ++i) {
//		endRow = row + i;
//		endCol = col + i;
//		for (int j = col, j2 = row; j < m  && j <= endCol && j2 <= endRow; ++j, ++j2) {
//			if (vec[endRow][j] != 1 || vec[j2][endCol] != 1) {
//				isRow = false;
//				break;
//			}
//		}
//		//if (isRow) {
//		//	//endRow = row + i;
//		//	//endCol = col + i;
//		//	for (int j = row; j < n  && j <= endRow; ++j) {
//		//		if (vec[j][endCol] != 1) {
//		//			isRow = false;
//		//			break;
//		//		}
//		//	}
//		//}
//		if (isRow) {
//			++res;
//		}
//		else {
//			break;
//		}
//	}
//	return res;
//}