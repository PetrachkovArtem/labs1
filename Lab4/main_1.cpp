/**
 * Лабораторная работ №4
 * Задание 1
 * Вариант 1
 * Петрачков А.Е. ПМИ_АДМО подгруппа 2
 */

#include <iostream>
#include <ctime>
#include <math.h>

using std::cin;
using std::cout;

int main()
{
    while (true)
    {
        int n;

        cout << "Введите размер массива от 1 до 10000:";
        cin >> n;

        if (n < 1 || n > 10000)
        {
            cout << "Не верный диапозон\n";
            continue;
        }

        int array[n];

        // устанвливаем параметр функции случайных значений
        srand(time(NULL));

        bool has_number_starts_with_one = false;

        // заполнение данными
        for (int i = 0; i < n; i++)
        {
            array[i] = abs(rand());

            int current = array[i];

            // проверяем что число начинается с 1
            if (!has_number_starts_with_one)
            {
                int number = 0;

                while (current > 0)
                {
                    number = current % 10;
                    current /= 10;
                }

                has_number_starts_with_one = number == 1;
            }
        }

        if (has_number_starts_with_one)
        {

            // сортировка массива
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }

            // вывод части массива для наглядности сортировки
            for (int i = 0; i < n && i < 20; i++)
            {
                cout << array[i] << "\n";
            }
        }
        else
        {
            cout << "Последовательность не содержит чисел начинающих с цифры 1";
        }

        break;
    }
}