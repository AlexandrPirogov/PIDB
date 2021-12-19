#pragma once
#include <map>
#include <vector>
#include <string>
#include "../FileHandlerPI/FileHandler.h"
#include "../Schemes/Table.h"
#include "../Schemes/Row.h"

class ExecuteMachine
{
   public:
       const int EXEC_STATUS_NIL = -1;
       const int EXEC_STATUS_OK = 0;
       const int EXEC_STATUS_ERR = 1;

       ExecuteMachine( ); 
       void execute(std::map<std::string, std::string>& plan, FileHandler* filehandler);

   protected:
       int exec_status;
     
       Table* currentTable = nullptr;
   private:
     /*void createScheme(char* name);
       void dropScheme(char* name);

       void createTable(char* name);
       void dropTable(char* name); */
       void readTable(std::map<std::string, std::string>& plan, FileHandler* filehandler);

    /*   void createRow(char* tableName, char** columns, char** conditions);
       void dropRow(char* tableName, char** conditions);
       void updateRow(char* tableName, char** columns, char** conditions);
      */
      
};
