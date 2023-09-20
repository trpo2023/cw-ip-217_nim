#define CTEST_MAIN
#include <sstream>
#include <iostream>
#include <string>
#include <ctest.h>
#include "sbros.hpp"

using namespace std;

CTEST(Functions, SbrosVvoda)
{
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

int main(int argc, const char** argv)
{
    int test_result = ctest_main(argc, argv);
    return test_result;
}