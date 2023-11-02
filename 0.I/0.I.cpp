#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::stack<char> s;

	std::string str;
	std::getline(std::cin, str);

	bool b = true;

	for (int i = 0; i < str.length(); ++i) {
		if (s.empty()) {
			if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
				s.push(str[i]);
			}
			else {
				b = false;
				break;
			}
		}
		else if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			s.push(str[i]);
		}
		else {
			if (str[i] == ')' && s.top() == '(' ||
				str[i] == ']' && s.top() == '[' ||
				str[i] == '}' && s.top() == '{') {
				s.pop();
			}
			else {
				b = false;
				break;
			}
		}
	}
	std::cout << (s.empty() && b ? "yes" : "no") << '\n';

	return 0;
}