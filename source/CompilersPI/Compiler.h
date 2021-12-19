#pragma once
#include <string>
#include <map>
#include "Parser.h"
#include "Tree.h"

class Compiler
{
   public:
         const int COMPILE_STATUS_NIL = -1;
	 const int COMPILE_STATUS_OK = 0;
	 const int COMPILE_STATUS_ERR = 1;

	 Compiler(std::string& query);
	 void compile(Parser* parser, Tree* tree);
	 int get_compile_status();
	 std::map<std::string, std::string> get_plan();
   protected:
	 int compile_status;
	 std::string query;
	 std::map<std::string, std::string> plan; 
           
   private:
};
