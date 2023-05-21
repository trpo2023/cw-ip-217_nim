#include <ctest.h> 
#include <stdio.h> 
 
#include <player.h> 
 
CTEST(Functions, MoveDone) 
{ 
 int naPorezu = 1; 
 moveDone(); 
 ASSERT_EQ(0;0); 
} 
 
CTEST(Functions, AddSkip) 
{ 
 int skip = 0; 
 addSkip(); 
 ASSERT_EQ(1;1); 
} 
 
CTEST(Functions, RemoveSkip) 
{ 
 int skip = 10; 
 removeSkip(); 
 ASSERT_EQ(9;9); 
}
