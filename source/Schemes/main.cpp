#include <iostream>
#include "Row.h"
#include <string>

int main()
{
   Row* r = new Row();
   std::string test = "test";
   r->setValue(test);
   std::cout << r->getValue() << std::endl;
};
