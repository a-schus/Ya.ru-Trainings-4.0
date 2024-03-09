/*
B. Сложить две дроби
Ограничение времени	1 секунда
Ограничение памяти	64Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt

Даны две рациональные дроби: a/b и c/d. Сложите их и результат представьте в виде несократимой дроби m/n.

Формат ввода
Программа получает на вход 4 натуральных числа a, b, c, d, каждое из которых не больше 100.

Формат вывода
Программа должна вывести два натуральных числа m и n такие, что m/n=a/b+c/d и дробь m/n – несократима.
*/


#include <iostream>

struct Fraction {
    int numerator;
    int denominator;
};

Fraction reduction(Fraction f);

int main()
{
    Fraction f1, f2, F;

    std::cin >> f1.numerator >> f1.denominator >> f2.numerator >> f2.denominator;

    F.denominator = f1.denominator * f2.denominator;
    F.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;

    F = reduction(F);

    std::cout << F.numerator << ' ' << F.denominator << '\n';

    return 0;
}

Fraction reduction(Fraction f) {
    // Находим наибольший общий делитель дроби методом Евклида
    int min = f.numerator, max = f.denominator;
    if (min > max) std::swap(min, max);
    while (min > 1) {
        max %= min;
        std::swap(max, min);
    } // Теперь если min == 0, то в max хранится НОД. Если min == 1, дробь не сокращается

    if (min != 0) {
        return { f.numerator, f.denominator };
    }
    else {
        return { f.numerator / max, f.denominator / max };
    }

    return (min != 0 ? Fraction{ f.numerator, f.denominator } : Fraction{ f.numerator / max, f.denominator / max });
}
