/**
 * Лабораторная работ №2
 * Задание 2
 * Вариант 1
 * Петрачков А.Е. ПМИ_АДМО подгруппа 2
*/

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int n;

    // Ввод данных
    cout << "Введите N(номер месяца):";
    cin >> n;

    switch (n)
    {
    case 1:
        cout << "Январь";
        break;

    case 2:
        cout << "Февраль";
        break;

    case 3:
        cout << "Март";
        break;

    case 4:
        cout << "Апрель";
        break;

    case 5:
        cout << "Май";
        break;

    case 6:
        cout << "Июнь";
        break;

    case 7:
        cout << "Июль";
        break;

    case 8:
        cout << "Август";
        break;

    case 9:
        cout << "Сентябрь";
        break;

    case 10:
        cout << "Октябрь";
        break;

    case 11:
        cout << "Ноябрь";
        break;

    case 12:
        cout << "Декабрь";
        break;

        // Проверка на выход за границы
    default:
        cout << "Не верный номер месяца";
        break;
    }
}