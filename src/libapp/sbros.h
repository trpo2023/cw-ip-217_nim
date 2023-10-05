#pragma once

#include <stdio.h>
#include <string.h>

void SbrosVvoda();

int checkDuplicateLetter(char* ugadBukvi, char otvet);

int checkCorrectLetter(const char* zagadSlovo, char* ugadBukvi, char otvet, int* kolOshibok);