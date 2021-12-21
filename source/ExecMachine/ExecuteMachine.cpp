#include "ExecuteMachine.h"
#include <map>
#include <string>
#include "../FileHandlerPI/FileHandler.h"
#include "../Schemes/Table.h"
#include "../Schemes/crudTable.h"
#include "../Schemes/Row.h"
#include <iostream>

ExecuteMachine::ExecuteMachine()
  
{
   exec_status = EXEC_STATUS_NIL;
};

void ExecuteMachine::execute(std::map<std::string, std::string>& plan, FileHandler* filehandler)
{
    auto it = plan.begin();
    std::cout << "it\n";
    std::advance(it, 0);
    if(it->first == "ВЫБРАТЬ")
	    readTable(plan, filehandler);
};

void ExecuteMachine::readTable(std::map<std::string, std::string>& plan, FileHandler* filehandler)
{
	if(this->currentTable != nullptr)
        delete this->currentTable;
    
    std::cout <<"ExecuteReadTable\n";
	std::string path = "/PIDB/data/tables";
	std::cout << "План = " << plan["ИЗ"];
	filehandler->read(path, plan["ИЗ"]);
	std::vector<std::string> rows = filehandler->getRecords();
	this->currentTable = new crudTable(plan["ИЗ"]);
	for(int i = 0; i < rows.size(); i++)
        {
              Row* r = new Row();
	      r->setValue(rows[i]);
	      
	      this->currentTable->insert(r);
	};
	currentTable->toString();
    rows.clear();
};

std::string ExecuteMachine::getTableResult()
{
   return this->currentTable->getRows();
};
