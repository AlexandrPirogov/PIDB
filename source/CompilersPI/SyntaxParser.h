#pragma once
#include "Parser.h"
#include <map>
#include <vector>
#include <string>
#include "Tree.h"


class SyntaxParser : public Parser
{
   public:
	   SyntaxParser(std::string& query);
	   void parse(Tree* tree, std::map<std::string, std::string>& plan);
   protected:
       void checkQuery(std::map<std::string, std::string>& plan);	 
   private:
};
