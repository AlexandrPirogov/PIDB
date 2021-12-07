#include "Console.h"
#include <iostream>

Console::Console()
{
   std::cout << "Welcome to PIDB\n";
   std::cout << "When PIDB is ready to execute your commands you'll the sign \">\" \n";
   read_status = READ_STATUS_NIL;
};

void Console::readCommand()
{
    std::cout << ">";
    char* command;
    while(std::cin >> command)
    {
        
        std::cout << command << std::endl;
        std::cout << ">";
    }
};

int Console::get_read_status()
{
   return read_status;
};


