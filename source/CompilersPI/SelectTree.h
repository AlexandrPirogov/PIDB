#pragma once
#include "Tree.h"
#include "Node.h"

class SelectTree : public Tree
{
   public:
       SelectTree();
       void travel();

   protected:
   private:
       void createTree(char* select_query);
};
