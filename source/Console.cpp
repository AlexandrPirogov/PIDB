#include "Console.h"
#include <iostream>
#include <string>

Console::Console()
{
   std::cout << "Welcome to PIDB\n";
   std::cout << "When PIDB is ready to execute your commands you'll the sign \">\" \n";
   read_status = READ_STATUS_NIL;
};

void Console::readCommand()
{
    std::cout << ">";
    std::getline(std::cin, this->command);
};

int Console::get_read_status()
{
   return read_status;
};

std::string Console::getCommand()
{
   return this->command;
};

