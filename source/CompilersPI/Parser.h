#pragma once
#include <string>
#include <vector>
#include <map>
#include "Tree.h"

class Parser
{
   public:
    const int PARSE_STATUS_NIL = -1;
	const int PARSE_STATUS_OK = 0;
	const int PARSE_STATUS_ERR = 1;

    void setQuery(std::string& query);
	virtual void parse(Tree* tree, std::map<std::string, std::string>& plan) = 0;
    int get_parse_status();
   protected:
	int parse_status;
	std::string query;
   private:
};
