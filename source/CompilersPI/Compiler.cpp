#pragma once
#include <map>
#include <string>
#include "Parser.h"
#include "Tree.h"
#include "Compiler.h"

Compiler::Compiler()
{
  
};

Compiler::Compiler(std::string& query) : query(query)
{
   compile_status = COMPILE_STATUS_NIL;
};

void Compiler::setQuery(std::string& query)
{
   this->query = query;
};

void Compiler::compile(Parser* parser, Tree* tree)
{
   parser->parse(tree, this->plan);
   this->compile_status = parser->get_parse_status();
};

int Compiler::get_compile_status()
{
   return this->compile_status;
};

std::map<std::string, std::string> Compiler::get_plan()
{
   return this->plan;
};
