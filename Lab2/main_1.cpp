/**
 * Лабораторная работ №2 
 * Задание 1
 * Вариант 1
 * Петрачков А.Е. ПМИ_АДМО подгруппа 2
*/

#include <iostream>

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

    // проверка условий
    if (a % b == 0)
    {
        if (b > c)
        {
            cout << "A/B+C = " << (a / b + c);
        }
        else
        {
            cout << "A/B-C = " << (a / b - c);
        }
    }
    else
    {
        cout << "(A+B)*C = " << ((a + b) * c);
    }
}