#include <iostream>
#include <string>
#include <ctest.h>
#include "sbros.hpp"

using namespace std;

CTEST(Functions, SbrosVvoda)
{
 const char simvol = ' ';
 cin >> simvol;
 SbrosVvoda();
 if (strlen(simvol) == 1)
	 ASSERT_EQUAL(1,1);
 else 
	 ASSERT_EQUAL(1,0);
}
