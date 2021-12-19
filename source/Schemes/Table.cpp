#include "Row.h"
#include <string>
#include "Table.h"
#include <iostream>

Table::Table(std::string name) : name(name) {};

void Table::readRow()
{

};

std::string Table::getName()
{
    return this->name;
};

void Table::toString()
{
    for(int i = 0; i < this->rows.size(); i++)
    {
	    std::cout << rows[i]->getValue()<<"\n";
    };
};

Table::~Table()
{
    this->rows.clear(); 
};
