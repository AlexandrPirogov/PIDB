#pragma once
#include "Row.h"
#include "crudStatuses.h"
#include <string>
#include <vector>


class Table :public crudStatuses
{
   public:
       Table(std::string name);
       ~Table();
       void readRow();
       virtual void insert(Row* row) = 0;
       std::string getName();
       void toString();
       std::string getRows(); 
   private:
       
   protected:
       std::string name;
       std::vector<Row*> rows;
};
