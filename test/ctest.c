#include <iostream>
#include <string>
#include <ctest.h>
#include "sbros.hpp"

using namespace std;

CTEST(Functions, SbrosVvoda)
{
 char simvol = ' ';
 cin >> simvol;
 SbrosVvoda();
 if (cin.peek() == '\n')
	 ASSERT_EQUAL(1,1);
 else 
	 ASSERT_EQUAL(1,0);
}
