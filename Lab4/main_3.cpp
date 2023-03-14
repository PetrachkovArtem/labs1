/**
 * Лабораторная работ №4
 * Задание 3
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
        int m, n;

        // ввод данных
        cout << "Введите колличество столбцов от 1 до 100:";
        cin >> n;

        if (n < 1 || n > 100)
        {
            cout << "Не верный диапозон столбцов\n";
            continue;
        }

        cout << "Введите колличество строк от 1 до 100:";
        cin >> m;

        if (m < 1 || m > 100)
        {
            cout << "Не верный диапозон строк\n";
            continue;
        }

        int array[m][n];

        // устанвливаем параметр функции случайных значений
        srand(time(NULL));

        // заполнение данными
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                array[i][j] = abs(rand());
            }
        }

        int min = INT_MAX;

        int row_index = -1;

        // находим строку с минимальной суммой
        for (int i = 0; i < m; i++)
        {
            int current_sum = 0;
            for (int j = 0; j < n; j++)
            {
                current_sum += array[i][j];
            }

            if (current_sum < min)
            {
                min = current_sum;
                row_index = i;
            }
        }

        // зануляем минимальную строку
        for (int i = 0; i < n; i++)
        {
            array[row_index][i] = 0;
        }

        cout << "Номер строки с минимальной суммой: " << (row_index + 1) << "\n";

        // вывод матрицы, что бы показать строку с "0"
        for (int i = 0; i < m; i++)
        {
            cout << (i + 1) << ".\t";

            for (int j = 0; j < n; j++)
            {
                cout << array[i][j] << "\t";
            }

            cout << "\n";
        }

        break;
    }
}