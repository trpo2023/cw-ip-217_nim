 #include <sstream>
 #include <iostream>
 #include <string>
#include <ctest.h>
 #include "../src/libapp/sbros.hpp"

CTEST(Functions, SbrosVvoda)
{
    ASSERT_EQUAL(1, 1);
     string input = "5";
     stringstream iss(input); 
     cin.rdbuf(iss.rdbuf());
     char simvol = ' ';
     cin >> simvol;
     SbrosVvoda();
     if (cin.peek() == '\n'){
         ASSERT_EQUAL(1, 1);
         }
     else{
         ASSERT_EQUAL(1, 0);
         }
}