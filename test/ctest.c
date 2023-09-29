#include <stdio.h>
#include <string.h>
#include <ctest.h>
#include "../src/libapp/sbros.h"

CTEST(Functions, SbrosVvoda)
{
    char input[] = "5";
    char simvol;
    int result;
    
    FILE* tmpFile = tmpfile();
    if (tmpFile == NULL) {
        // handle error
        return;
    }
    
    fwrite(input, sizeof(char), strlen(input), tmpFile);
    rewind(tmpFile);
    
    result = fscanf(tmpFile, "%c", &simvol);
    fclose(tmpFile);
    
    SbrosVvoda();
    
    if (result == 1 && simvol == '\n') {
        ASSERT_EQUAL(1, 1);
    } else {
        ASSERT_EQUAL(1, 0);
    }
}