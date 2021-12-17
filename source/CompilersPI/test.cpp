#include <iostream>
#include <string>

int main()
{
    std::string words = "Выбрать то-то и тото";
    std::string word;
   std::stringstream(words)>>word ;
   std::cout << word << std::endl;
   return 0;
};
