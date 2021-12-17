#pragma once
#include "Tree.h"

class Compiler
{
   public:
     
       const int PARSE_STATUS_NIL = -1;
       const int PARSE_STATUS_OK = 0;
       const int PARSE_STATUS_ERR = 1;

       Compiler(char* query);
       virtual void parse(Tree* tree) = 0;
       int get_parse_status();
   protected:
       int parse_status;
       char* query;
   private:
};
