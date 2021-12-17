#include "SyntaxCompiler.h"
#include "Tree.h"

SyntaxCompiler::SyntaxCompiler(char* query) : Compiler(query)
{

};

void SyntaxCompiler::parse(Tree* tree)
{
    tree->travel();
};
