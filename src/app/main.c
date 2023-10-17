#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <sbros.h>

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int x = rand() % 5;

    const char* word[5] = { "burger", "pizza", "sushi", "dumplings", "salad" };


    int Pobeda = 0;
    const char* zagadSlovo = word[x];
    char ugadBukvi[26] = "";
    int kolOshibok = 7;
    char otvet;

    printf("������, ������������. ����� ������� � ���� \"��������\", ������� ������� ������.\n�, ���������, ��������� �����, � �� ��� ����������� �� ������. ���� ��������� ������ ���, �� ����������.\n����� ����� �������� �� ���� �������� ��������.\n\n");

    while (kolOshibok > 0 && !Pobeda) {
        for (size_t i = 0; i < strlen(zagadSlovo); i++) {
            if (strchr(ugadBukvi, zagadSlovo[i]) != NULL) {
                printf("%c ", zagadSlovo[i]);
            }
            else {
                printf("_ ");
            }
        }
        printf("\n");

        printf("������� �����: ");
        scanf("%c", &otvet);
        SbrosVvoda();

        if (checkDuplicateLetter(ugadBukvi, otvet)) {
            continue;
        }

        if (checkCorrectLetter(zagadSlovo, ugadBukvi, otvet, &kolOshibok)) {
            Pobeda = 1;
        }
        //else {
        //    kolOshibok;
        //}
        else {
            switch (kolOshibok) {

            case 6:
                printf("    _________\n");
                printf("    |       |\n");
                printf("    |\n");
                printf("    |\n");
                printf("    |\n");
                printf("    |\n");
                printf("____|____\n");
                break;

            case 5:
                printf("    _________\n");
                printf("    |       |\n");
                printf("    |       O\n");
                printf("    |\n");
                printf("    |\n");
                printf("    |\n");
                printf("____|____\n");
                break;

            case 4:
                printf("    _________\n");
                printf("    |       |\n");
                printf("    |       O\n");
                printf("    |       |\n");
                printf("    |\n");
                printf("    |\n");
                printf("____|____\n");
                break;

            case 3:
                printf("    _________\n");
                printf("    |       |\n");
                printf("    |       O\n");
                printf("    |      /|\n");
                printf("    |\n");
                printf("    |\n");
                printf("____|____\n");
                break;

            case 2:
                printf("    _________\n");
                printf("    |       |\n");
                printf("    |       O\n");
                printf("    |      /|\\\n");
                printf("    |\n");
                printf("    |\n");
                printf("____|____\n");
                break;

            case 1:
                printf("    _________\n");
                printf("    |       |\n");
                printf("    |       O\n");
                printf("    |      /|\\\n");
                printf("    |      /\n");
                printf("    |\n");
                printf("____|____\n");
                break;

            case 0:
                printf("    _________\n");
                printf("    |       |\n");
                printf("    |       O\n");
                printf("    |      /|\\\n");
                printf("    |      / \\\n");
                printf("    |\n");
                printf("____|____\n");
                break;
            }
        }
    }

    if (Pobeda) {
        printf("����������! �� �������: %s\n", zagadSlovo);
    }
    else {
        printf("� ���������, �� ��������. ���������� �����: %s\n", zagadSlovo);
    }

    return 0;
}