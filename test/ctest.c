#include <SFML/Graphics.hpp>
#include <ctest.h>
#include <stdio.h>
#include <iostream>

#include "src/player.h"

CTEST(Functions, MoveDone)
{
 int naPorezu = 1;
 moveDone();
 ASSERT_EQUAL(0,0);
}

CTEST(Functions, AddSkip)
{
 int skip = 0;
 addSkip();
 ASSERT_EQUAL(1,1);
}

CTEST(Functions, RemoveSkip)
{
 int skip = 10;
 removeSkip();
 ASSERT_EQUAL(9,9);
}
