#pragma once
#include "Tree.h"
#include "Node.h"
#include <string>
#include <map>
#include <vector>


class SelectTree : public Tree
{
   public:
       SelectTree(std::string& selectQuery);
       void travel(Node* current, std::map<std::string, std::string>& plan);

   protected:
       void createTree(std::string& selectQuery);
       void takeKeyWord();
       void takeArgs();
   private:
       void fillVector(std::string& expression);
};
