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
        printf("����� ����� ��� ����!\n");
        return 1; // ���������� 1, ���� ����� ��� ����
    }
    return 0; // ���������� 0, ���� ����� �� ���� �����
}

int checkCorrectLetter(const char* zagadSlovo, char* ugadBukvi, char otvet, int* kolOshibok) {
    if (strchr(zagadSlovo, otvet) != NULL) {
        printf("�����! ���� ����� �����.\n");
        for (size_t i = 0; i < strlen(zagadSlovo); i++) {
            if (zagadSlovo[i] == otvet) {
                strncat(ugadBukvi, &otvet, 1);
            }
        }
        if (strlen(ugadBukvi) == strlen(zagadSlovo)) {
            return 1; // ���������� 1, ���� ��� ����� �������
        }
    }
    else {
        printf("�������! ����� ����� ���.\n");
        (*kolOshibok)--;
    }
    if (kolOshibok == 0) {
        return 0; // ���������� 0 � ��������� �������
    }
    return 0;
}