/**
 * Лабораторная работ №3
 * Задание 1
 * Вариант 1
 * Петрачков А.Е. ПМИ_АДМО подгруппа 2
 */
#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int n, index;
    int mult = 1;

    // Ввод длинны последовательности
    cout << "Введите N:";
    cin >> n;

    int min = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int number;

        // Ввод числа последовательности
        cout << "Введите число:";
        cin >> number;

        // последняя цифра числа
        int last_char = number % 10;

        if (last_char == 2 || last_char == 4)
        {
            mult *= number;

            if (min > number)
            {
                min = number;
                index = i + 1;
            }
        }
    }

    cout << "Произведение чисел заканчивающихся цифрой 2 или 4:" << mult << "\n";
    cout << "Наименьшее число из них:" << min << "\n";
    cout << "Номер этого числа:" << index << "\n";
}