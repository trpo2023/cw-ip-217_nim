#define _CRT_SECURE_NO_WARNINGS
#include <sbros.h>
#include <stdio.h>
#include <string.h>

void SbrosVvoda() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int checkDuplicateLetter(char* ugadBukvi, char otvet) {
    if (strchr(ugadBukvi, otvet) != NULL) {
        printf("Такая буква уже была!\n");
        return 1; // Возвращаем 1, если буква уже была
    }
    return 0; // Возвращаем 0, если буква не была ранее
}

int checkCorrectLetter(const char* zagadSlovo, char* ugadBukvi, char otvet, int* kolOshibok) {
    if (strchr(zagadSlovo, otvet) != NULL) {
        printf("Верно! Есть такая буква.\n");
        for (size_t i = 0; i < strlen(zagadSlovo); i++) {
            if (zagadSlovo[i] == otvet) {
                strncat(ugadBukvi, &otvet, 1);
            }
        }
        if (strlen(ugadBukvi) == strlen(zagadSlovo)) {
            return 1; // Возвращаем 1, если все буквы угаданы
        }
    }
    else {
        printf("Неверно! Такой буквы нет.\n");
        (*kolOshibok)--;
    }
    if (kolOshibok == 0) {
        return 0; // Возвращаем 0 в остальных случаях
    }
    return 0;
}