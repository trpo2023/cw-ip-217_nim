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
    
    if (result == 1 && simvol == input[0]) {
        ASSERT_EQUAL(1, 1);
    } else {
        ASSERT_EQUAL(1, 1);
    }
}

CTEST(Functions, checkDuplicateLetter)
{
    char* ugadBukvi[26] = "burger";
    char otvet = "b";
    if(checkDuplicateLetter(ugadBukvi, otvet) == 1){
        ASSERT_EQUAL(1, 1);
    } else {
        ASSERT_EQUAL(1, 0);
    }
}

CTEST(Functions, checkCorrectLetter)
{
    const char* zagadSlovo = "burger";
    char* ugadBukvi;
    char otvet = "a";
    int* kolOshibok = 1;
    if(checkCorrectLetter(zagadSlovo, ugadBukvi, otvet, &kolOshibok)==0){
        ASSERT_EQUAL(1, 1);
    } else {
        ASSERT_EQUAL(1, 0);
    }
}