#include "Compiler.h"

Compiler::Compiler(char* query) : query(query)
{
   this->parse_status = PARSE_STATUS_NIL;
};

int Compiler::get_parse_status()
{
   return this->parse_status;
};
