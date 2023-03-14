/**
 * Лабораторная работ №5
 * Задание 2
 * Вариант 1
 * Петрачков А.Е. ПМИ_АДМО подгруппа 2
 */

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

int main()
{
    // для того что бы читал русские символы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true)
    {

        std::string data_string;
        std::string temp_string;
        std::string word_string;
        std::vector<std::string> words_end_by_char;
        char end_of_word;
        int n;

        // открытие файла с данными для чтение
        std::ifstream data_file;
        data_file.open("data.txt");

        while (!data_file.eof())
        {
            getline(data_file, temp_string);
            data_string += temp_string;
        }

        data_file.close();

        // открытие файла с номером на чтение
        data_file.open("number.txt", std::ios::in);

        // чтение длинны из файла
        while (!data_file.eof())
        {
            getline(data_file, temp_string);
            n = std::stoi(temp_string);
        }

        data_file.close();

        if (n > 100)
        {
            n = 100;
        }

        std::cout << "Буква окончания слова:";

        std::cin >> end_of_word;

        int data_string_len = data_string.length();

        int start = 0;
        for (int i = 0; i < data_string_len; i++)
        {
            // проверка окончания слова
            char current_symbol = data_string.at(i);
            if (current_symbol == ' ' || current_symbol == '.' || current_symbol == '!' || i == data_string_len - 1)
            {
                // получение слова
                word_string = data_string.substr(start, i - start);
                start = i + 1;

                // если это пустое слово то пропускаем
                int end_index = word_string.length() - 1;
                if (end_index < 0)
                {
                    continue;
                }

                // последний символ слова
                char end_char = word_string.at(end_index);

                if (end_char == end_of_word)
                {

                    // проверка на уникальность
                    bool isExist = false;
                    int words_end_by_char_size = words_end_by_char.size();

                    for (int s = 0; s < words_end_by_char_size; s++)
                    {
                        if (words_end_by_char[s].compare(word_string) == 0)
                        {
                            isExist = true;
                            break;
                        }
                    }

                    if (!isExist)
                    {
                        words_end_by_char.push_back(word_string);
                    }
                }
            }
        }

        int words_end_by_char_size = words_end_by_char.size();

        // сортировка слов
        for (int i = 0; i < words_end_by_char_size - 1; i++)
        {
            for (int j = 0; j < words_end_by_char_size - i - 1; j++)
            {
                if (words_end_by_char[j].length() > words_end_by_char[j + 1].length())
                {
                    std::string temp = words_end_by_char[j];
                    words_end_by_char[j] = words_end_by_char[j + 1];
                    words_end_by_char[j + 1] = temp;
                }
            }
        }

        std::ofstream result_data("result.txt");

        int start_index = words_end_by_char_size - n;
        if (start_index < 0)
        {
            start_index = 0;
        }

        for (int i = start_index; i < words_end_by_char_size; i++)
        {
            result_data.write(words_end_by_char[i].c_str(), words_end_by_char[i].length());
            result_data.write("\r\n", 2);
        }

        result_data.close();

        break;
    }
}