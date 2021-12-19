#include <iostream>
#include <string>
#include <map>
#include "./CompilersPI/Tree.h"
#include "./CompilersPI/SelectTree.h"
#include "./CompilersPI/Compiler.h"
#include "./CompilersPI/Parser.h"
#include "./CompilersPI/SyntaxParser.h"
#include "./CompilersPI/Node.h"
#include "Console.h"
#include "./ExecMachine/ExecuteMachine.h"

int main()
{ 
   Console* console = new Console();
   ExecuteMachine* mc = new ExecuteMachine();
   FileHandler* fh = new FileHandler();
   std::string st;
   while(true)
   {
      std::cout << ">";
      console->readCommand();
      st = console->getCommand();
      Tree* selectTree = new SelectTree(st);
      Parser* sp = new SyntaxParser(st);
      Compiler* comp = new Compiler(st);  
     
      comp->compile(sp, selectTree);
      
      std::map<std::string, std::string> plan = comp->get_plan(); 
      for(auto& [key, value] : comp->get_plan())
	     std::cout << key << " = " << value << std::endl; 
      mc->execute(plan, fh);
      
      delete selectTree;
      delete sp;
      delete comp;
   };
   return 0;
};
