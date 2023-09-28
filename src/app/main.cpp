#include <iostream>
#include <string>
#include "sbros.hpp"
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int x = rand() % 5;//˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜.

	string word[5] = { "burger", "pizza", "sushi", "dumplings", "salad" };//˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜ ˜˜˜˜.


	bool Pobeda = false;//˜˜˜˜ ˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜.
	string zagadSlovo = word[x];//˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜.
	string ugadBukvi = "";//˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜.
	short kolOshibok = 7;//˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜.
	char otvet;//˜˜˜˜˜˜ ˜˜˜˜˜˜.

	//˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜-˜˜˜˜ "˜˜˜˜˜˜˜˜".	
	cout << "˜˜˜˜˜˜, ˜˜˜˜˜˜˜˜˜˜˜˜. ˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜ ˜˜˜˜ \"˜˜˜˜˜˜˜˜\", ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜.\n˜, ˜˜˜˜˜˜˜˜˜, ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜ '˜˜˜', ˜ ˜˜ ˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜. ˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜ ˜˜˜, ˜˜ ˜˜˜˜˜˜˜˜˜˜.\n˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜.\n\n";


	//˜˜˜˜˜˜˜˜˜˜, ˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜.
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

		cout << "˜˜˜˜˜˜˜ ˜˜˜˜˜: ";
		cin >> otvet;
		SbrosVvoda();//˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜, ˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜.

		if (ugadBukvi.find(otvet) != string::npos)//˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜.
		{
			cout << "˜˜ ˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜!" << endl;
			continue;
		}

		if (zagadSlovo.find(otvet) != string::npos)//˜˜˜˜˜˜˜˜ ˜˜˜˜ ˜˜ ˜˜˜˜˜ ˜ ˜˜˜˜˜.
		{
			cout << "˜˜˜˜˜! ˜˜˜ ˜˜˜˜˜ ˜˜˜˜ ˜ ˜˜˜˜˜." << endl;
			for (size_t i = 0; i < zagadSlovo.size(); i++)
			{
				if (zagadSlovo[i] == otvet)
				{
					ugadBukvi += otvet;
				}
			}
			if (ugadBukvi.length() == zagadSlovo.length())//˜˜˜˜˜˜˜˜ ˜˜ ˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜.
			{
				Pobeda = true;
			}
		}
		else//˜˜˜˜˜, ˜˜˜˜ ˜˜˜˜˜ ˜˜˜ ˜ ˜˜˜˜˜.
		{
			cout << "˜˜˜˜˜˜˜˜˜˜˜! ˜˜˜˜˜ ˜˜˜˜˜ ˜ ˜˜˜˜˜ ˜˜˜." << endl;
			kolOshibok--;
		}
		//˜ ˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜.
		switch (kolOshibok) {

		case 6:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;

		case 5:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |       O" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;

		case 4:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |       O" << endl;
			cout << "    |       |" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;

		case 3:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |       O" << endl;
			cout << "    |      /|" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;

		case 2:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |       O" << endl;
			cout << "    |      /|\\" << endl;
			cout << "    |" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;

		case 1:
			cout << "    _________" << endl;
			cout << "    |       |" << endl;
			cout << "    |       O" << endl;
			cout << "    |      /|\\" << endl;
			cout << "    |      /" << endl;
			cout << "    |" << endl;
			cout << "____|____" << endl;
			break;

		case 0:
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
		cout << "˜˜˜˜˜˜˜˜˜˜! ˜˜ ˜˜˜˜˜˜˜˜! ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜: " << endl << zagadSlovo << endl;
	}
	else
	{
		cout << "˜˜˜, ˜˜ ˜˜˜˜˜˜˜˜˜. ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜: " << zagadSlovo << endl;
	}

	//˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜-˜˜˜˜ "˜˜˜˜˜˜˜˜".
	return 0;
}