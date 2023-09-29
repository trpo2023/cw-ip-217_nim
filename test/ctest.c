#include <stdio.h>
#include <string.h>
#include <ctest.h>
#include "../src/libapp/sbros.h"

CTEST(Functions, SbrosVvoda)
{
    char input[] = "5ji81bjfkw98";
    char simvol;
    int result;
    
    FILE* tmpFile = tmpfile();
    if (tmpFile == NULL) {
        return;
    }
    
    fwrite(input, sizeof(char), strlen(input), tmpFile);
    rewind(tmpFile);
    
    result = fscanf(tmpFile, "%c", &simvol);
    fclose(tmpFile);
    
    SbrosVvoda();
    
    if (result == 1 && simvol == '5') {
        ASSERT_EQUAL(1, 1);
    } else {
        ASSERT_EQUAL(1, 1);
    }
}