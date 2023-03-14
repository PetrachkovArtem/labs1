/**
 * Лабораторная работ №5
 * Задание 1
 * Вариант 1
 * Петрачков А.Е. ПМИ_АДМО подгруппа 2
 */

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using std::cin;
using std::cout;

int main()
{
    // 101 символ прозапас для \n
    char str[101];

    cout << "Введите строку не более 100 символов: ";
    // т.к. собираю через g++
    fgets(str, sizeof str, stdin);

    // размер строки
    int str_len = strlen(str);

    for (int i = 0; i < str_len; i++)
    {
        // перевод вверхний регистр
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y')
        {
            str[i] = toupper(str[i]);
        }
    }

    cout << str;
}