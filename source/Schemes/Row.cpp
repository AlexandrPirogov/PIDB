#include "Row.h"
#include <string>

Row::Row(){};

void Row::setValue(std::string value)
{
    this->value = value;
};

std::string Row::getValue()
{
   return this->value;
};
