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