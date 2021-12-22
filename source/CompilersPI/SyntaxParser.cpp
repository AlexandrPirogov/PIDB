#pragma once
#include <map>
#include <string>
#include <vector>
#include "SyntaxParser.h"
#include "Tree.h"
#include <iostream>

SyntaxParser::SyntaxParser(std::string& query)
{
   this->query = query;
   this->parse_status = PARSE_STATUS_NIL;
};

void SyntaxParser::parse(Tree* tree, std::map<std::string, std::string>& plan)
{
   tree->travel(tree->getRoot(), plan);
   this->parse_status = tree->get_travel_status();
   this->checkQuery(plan);
};

void SyntaxParser::checkQuery(std::map<std::string, std::string>& plan)
{

    std::cout << "CHECKQUERY\n";
    for(auto& [key, value] : plan)
	     std::cout << key << " = " << value << std::endl;

   if(plan.count("ВЫБРАТЬ") > 0 && plan.count("ИЗ") >0)
   {
       this->parse_status = PARSE_STATUS_OK;
   } else {
       this->parse_status = PARSE_STATUS_ERR;
   }
};
