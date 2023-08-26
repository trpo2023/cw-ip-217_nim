#include <iostream>
#include <cstring>
#include <ctest.h>

using namespace std;

CTEST(Functions, SbrosVvoda)
{
 char simvol = ' ';
 cin >> simvol;
 SbrosVvoda();
 if (strlen(simvol) == 1)
	 ASSERT_EQUAL(1,1);
 else 
	 ASSERT_EQUAL(1,0);
}
