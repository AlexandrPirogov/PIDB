#include "Row.h"
#include <string>
#include <sstream>
#include <iostream>

Row::Row(){};

void Row::setValue(std::string record)
{
    std::stringstream sstreamRecord(record);
    std::string attribute;
    std::string rowsValue = "|";
    
    while(std::getline(sstreamRecord, attribute, ','))
         rowsValue += " " + attribute + " |";
   
    this->value = rowsValue;
};

std::string Row::getValue()
{
   return this->value;
};
