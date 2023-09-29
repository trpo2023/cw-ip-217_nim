#include <sbros.h>
#include <stdio.h>

void SbrosVvoda() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}