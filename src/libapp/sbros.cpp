#include <iostream>
#include <sbros.hpp>

using namespace std;

//—брасывает лишние символы, т.к. ввод идет с клавиатуры
void SbrosVvoda() { if (cin.peek() != '\n') while (cin.peek() != '\n') cin.ignore(); }