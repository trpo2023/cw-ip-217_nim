#include <iostream>
#include <string>
#include "sbros.hpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	int x = rand() % 5;//Создаём переменную для выбора слова рандомным образом.
	
	string word[5] = { "burger", "pizza", "sushi", "dumplings", "salad" };//Записываем слова для игры.

	
	bool Pobeda = false;//Флаг выхода из бесконечного цикла.
	string zagadSlovo = word[x];//Выбор слова для отгадывания.
	string ugadBukvi = "";//Уже угаданные буквы.
	short kolOshibok = 7;//Счетчик допустимых ошибок.
	char otvet;//Символ ответа.

	//Вступительный текст программы-игры "Виселица".	
	cout << "Привет, пользователь. Давай сыграем в игру \"Виселица\", правила которой просты.\nЯ, программа, загадываю слово из категории 'Еда', а ты его отгадываешь по буквам. Если ошибешься семь раз, то проиграешь.\nСлово будет состоять из букв Английского алфавита.\n\n";
	

	//Собственно, сам процесс игры.
	while (kolOshibok > 0 && !Pobeda)
	{
		for (size_t i = 0; i < zagadSlovo.length(); i++) 
		{
			if (ugadBukvi.find(zagadSlovo[i]) != string::npos)
			{
				cout << zagadSlovo[i] << " ";
			}
			else
			{
				cout << "_ ";
			}
		}
		cout << endl;

		cout << "Введите букву: ";
		cin >> otvet;
		SbrosVvoda();//Сброс лишних введёных символов, если такие имеются.

		if (ugadBukvi.find(otvet) != string::npos)//Проверка на повторение уже угаданных букв.
		{
			cout << "Вы уже угадали эту букву!" << endl;
			continue;
		}

		if (zagadSlovo.find(otvet) != string::npos)//Проверка есть ли буква в слове.
		{
			cout << "Верно! Эта буква есть в слове." << endl;
			for (size_t i = 0; i < zagadSlovo.size(); i++)
			{
				if (zagadSlovo[i] == otvet)
				{
					ugadBukvi += otvet;
				}
			}
			if (ugadBukvi.length() == zagadSlovo.length())//Проверка всё ли слово угадано.
			{
				Pobeda = true;
			}
		}
		else//Вывод, если буквы нет в слове.
		{
			cout << "Неправильно! Такой буквы в слове нет." << endl;
			kolOshibok--;
		}
		//С уменьшением количества возможных ошибок рисуется картинка.
		switch (kolOshibok) {
		
		case 6:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |       O" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;

		case 5:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |       O" << endl;
			cout << "    |       |" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;

		case 4:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |       O" << endl;
			cout << "    |      /|" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;

		case 3:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |       O" << endl;
			cout << "    |      /|\\" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;

		case 2:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |       O" << endl;
			cout << "    |      /|\\" << endl;
			cout << "    |      /" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;

		case 1:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |       O" << endl;
			cout << "    |      /|\\" << endl;
			cout << "    |      / \\" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;
		}
	}

	if (Pobeda)
	{
		cout << "Поздравляю! Вы выиграли!" << endl << zagadSlovo << endl;
	}
	else
	{
		cout << "Вы проиграли. Загаданное слово: " << zagadSlovo << endl;
	}

	//Выход из программы-игры "Виселица".
	return 0;
}