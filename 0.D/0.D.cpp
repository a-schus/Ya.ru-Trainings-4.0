#include <iostream>
#include <string>
#include <map>

int main()
{
	std::string s1, s2;
	std::cin >> s1 >> s2;
	std::map<char, int> c1, c2;

	if (s1.length() != s2.length()) {
		std::cout << "NO" << '\n';
	}
	else {
		for (int i = 0; i < s1.length(); ++i) {
			if (c1.find(s1[i]) == c1.end()) {
				c1[s1[i]] = 1;
			}
			else {
				++c1[s1[i]];
			}

			if (c2.find(s2[i]) == c2.end()) {
				c2[s2[i]] = 1;
			}
			else {
				++c2[s2[i]];
			}
		}
		if (c1 == c2) {
			std::cout << "YES" << '\n';
		}
		else {
			std::cout << "NO" << '\n';
		}
	}

	return 0;
}