/*
I. Правильная скобочная последовательность
Ограничение времени	1 секунда
Ограничение памяти	64Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt

Рассмотрим последовательность, состоящую из круглых, квадратных и фигурных скобок. 
Программа должна определить, является ли данная скобочная последовательность правильной. 
Пустая последовательность является правильной. Если A — правильная, то последовательности (A), [A], {A} — правильные. 
Если A и B — правильные последовательности, то последовательность AB — правильная.

Формат ввода
В единственной строке записана скобочная последовательность, содержащая не более 100000 скобок.

Формат вывода
Если данная последовательность правильная, то программа должна вывести строку "yes", иначе строку "no".
*/


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
