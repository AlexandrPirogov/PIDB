#pragma once
#include <string>
#include <map>
#include <vector>
#include "Parser.h"

int Parser::get_parse_status()
{
   return parse_status;
};

void Parser::setQuery(std::string& query)
{
  this->query = query;
};
