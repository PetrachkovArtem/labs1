/**
 * Лабораторная работ №1
 * Задание 1
 * Вариант 1
 * Петрачков А.Е. ПМИ_АДМО подгруппа 2
*/

#include <iostream>
#include <math.h>

using std::cin;
using std::cout;

int main()
{
	int a, b, c;

	// Ввод данных
	cout << "Введите А:";
	cin >> a;

	cout << "Введите B:";
	cin >> b;

	cout << "Введите C:";
	cin >> c;

	// вычесление полу периметра
	double p = (a + b + c) / 2.0;

	// вычесление площади
	double s = sqrt(p * (p - a) * (p - b) * (p - c));

	// вывод результата
	cout << "S = " << s;
}