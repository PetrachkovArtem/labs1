/**
 * Лабораторная работ №4
 * Задание 2
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

        cout << "Введите размер массива от 1 до 1000:";
        cin >> n;

        if (n < 1 || n > 1000)
        {
            cout << "Не верный диапозон\n";
            continue;
        }

        int array[n];

        // устанвливаем параметр функции случайных значений
        srand(time(NULL));

        // заполнение данными
        for (int i = 0; i < n; i++)
        {
            array[i] = abs(rand());

            int current = array[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                // сортировка массива по первой цифре

                // ищем первую цифру первого числа
                int current = array[j];
                int number_first = 0;

                while (current > 0)
                {
                    number_first = current % 10;
                    current /= 10;
                }

                // ищем первую цифру второго числа
                current = array[j + 1];
                int number_second = 0;

                while (current > 0)
                {
                    number_second = current % 10;
                    current /= 10;
                }

                // флаг для сортировки
                bool isSwap = false;

                // сортируем по сумме если первые цифры одинаковые
                if (number_first == number_second)
                {
                    // сумма первого числа
                    int sum_firts = 0;
                    current = array[j];

                    while (current > 0)
                    {
                        sum_firts += current % 10;
                        current /= 10;
                    }

                    // сумма второго числа
                    int sum_second = 0;
                    current = array[j + 1];

                    while (current > 0)
                    {
                        sum_second += current % 10;
                        current /= 10;
                    }

                    // если суммы одинковые то сортируем по самому числу
                    if (sum_firts == sum_second)
                    {
                        isSwap = array[j] > array[j + 1];
                    }
                    else if (sum_firts > sum_second)
                    {
                        isSwap = true;
                    }
                }
                // сортируем по первой цифре
                else if (number_first > number_second)
                {
                    isSwap = true;
                }

                if (isSwap)
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

        break;
    }
}