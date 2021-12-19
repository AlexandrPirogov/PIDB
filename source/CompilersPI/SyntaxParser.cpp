#pragma once
#include <map>
#include <string>
#include <vector>
#include "SyntaxParser.h"
#include "Tree.h"

SyntaxParser::SyntaxParser(std::string& query)
{
   this->query = query;
};

void SyntaxParser::parse(Tree* tree, std::map<std::string, std::string>& plan)
{
   tree->travel(tree->getRoot(), plan);
   this->parse_status = tree->get_travel_status();
};
