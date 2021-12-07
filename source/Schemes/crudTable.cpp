#include "crudTable.h"
#include <string>

crudTable::crudTable(std::string name):Table(name)
{
};

void crudTable::create()
{

};

void crudTable::drop()
{

};

void crudTable::update()
{

};

int crudTable::get_create_status()
{
    return this->create_status;
};

int crudTable::get_drop_status()
{
   return this->drop_status;
};

int crudTable::get_update_status()
{
   return this->update_status;
};

crudTable::~crudTable()
{
   delete[] rows;
};

