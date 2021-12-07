#pragma once
#include "Row.h"
#include "crudStatuses.h"
#include <string>



class Table :public crudStatuses
{
   public:
       Table(std::string name);
       ~Table();
       void readRow();
       std::string getName();
   private:
       
   protected:
       std::string name;
       Row* rows;
};
