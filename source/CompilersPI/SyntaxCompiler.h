#pragma once
#include "Compiler.h"
#include "Tree.h"

class SyntaxCompiler : public Compiler
{
   public:
       SyntaxCompiler(char* query);
       void parse(Tree* tree);
   protected:
   private:
};
