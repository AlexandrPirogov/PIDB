#include "Scheme.h"
#include "Table.h"
#include <string>


Scheme::Scheme(std::string name) : name(name) {};

void Scheme::create(Table table)
{

};

void Scheme::drop(std::string tableName)
{

};

void Scheme::update(std::string tableName)
{

};

Scheme::~Scheme()
{
   delete[] tables;
};
