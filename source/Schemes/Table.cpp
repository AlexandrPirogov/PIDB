#include "Row.h"
#include <string>
#include "Table.h"

Table::Table(std::string name) : name(name) {};

void Table::readRow()
{

};

std::string Table::getName()
{
    return this->name;
};

Table::~Table()
{
   delete[] rows;
};
