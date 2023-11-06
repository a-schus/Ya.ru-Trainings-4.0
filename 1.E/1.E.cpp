#include <iostream>
#include <vector>
#include <string>
#include <map>

void /*std::vector<std::string> */radixSort(std::vector<std::string>& s);

int main()
{
	int n;
	std::cin >> n;

	std::vector<std::string> s(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> s[i];
	}

	std::cin.clear();

	std::cout << "Initial array:\n";

	for (int i = 0; i < n; ++i) {
		std::cout << s[i];
		if (i != n - 1) std::cout << ", ";
	}
	std::cout << "\n**********\n";

	radixSort(s);


	std::cout << "Sorted array:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << s[i];
		if (i != n - 1) std::cout << ", ";
	}

}

void /*std::vector<std::string>*/ radixSort(std::vector<std::string>& s)
{
	std::map<char, std::vector<std::string>> b;

	for (int i = s[0].length() - 1; i >= 0; --i) {
		std::cout << "Phase " << s[0].length() - i << '\n';
		for (int j = 0; j < s.size(); ++j) {
			b[s[j][i]].push_back(s[j]);
		}
		for (char c = '0'; c <= '9'; ++c) {
			if (b.find(c) != b.end()) {
				std::cout << "Bucket " << c << ": " << b[c][0];
				for (int k = 1; k < b[c].size(); ++k) {
					std::cout << ", " << b[c][k];
				}
				std::cout << '\n';
			}
			else {
				std::cout << "Bucket " << c << ": " << "empty \n";
			}
		}
		std::cout << "**********\n";

		s.clear();
		for (auto k = b.begin(); k != b.end(); ++k) {
			for (int l = 0; l < k->second.size(); ++l) {
				s.push_back(k->second[l]);
			}
		}

		b.clear();
	}

	//return std::string();
}
