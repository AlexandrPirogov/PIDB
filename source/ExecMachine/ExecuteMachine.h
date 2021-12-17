#pragma once
#include "map"
#include "vector"

class ExecuteMachine
{
   public:
       const int EXEC_STATUS_NIL = -1;
       const int EXEC_STATUS_OK = 0;
       const int EXEC_STATUS_ERR = 1;

       ExecuteMachine(std::map<char*, std::vector<char*>> plan ); 
       void execute();

   protected:
       int exec_status;
       std::map<char*, std::vector<char*>> plan;
   private:
       void createScheme(char* name);
       void dropScheme(char* name);

       void createTable(char* name);
       void dropTable(char* name);
       void readTable(char* name, char** columns, char** conditions);

       void createRow(char* tableName, char** columns, char** conditions);
       void dropRow(char* tableName, char** conditions);
       void updateRow(char* tableName, char** columns, char** conditions);
       
};
