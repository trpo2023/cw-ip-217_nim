#include <stdio.h>
#include <string.h>
#include <ctest.h>
#include "../src/libapp/sbros.h"

CTEST(Functions, SbrosVvoda)
{
    char input[] = "5";
    char simvol;
    int result;
    
    FILE* stream = freopen(input, strlen(input), "r");
    if (stream == NULL) {
        return;
    }
    
    result = fscanf(stream, "%c", &simvol);
    fclose(stream);
    
    SbrosVvoda();
    
    if (result == 1 && simvol == '\n') {
        ASSERT_EQUAL(1, 1);
    } else {
        ASSERT_EQUAL(1, 0);
    }
}