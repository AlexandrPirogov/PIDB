#pragma once
#include "Table.h"
#include <string>
#include "crudStatuses.h"


class Scheme : crudStatuses
{
   public:
     
       Scheme(std::string name);
       ~Scheme();
       void create(Table table);
       void drop(std::string tableName);
       void update(std::string tableName);

   protected:

   private:
       std::string name;
       Table* tables;
};
