#include "FileHandler.h"
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
    std::cout << "fh start\n";
    FileHandler* fh = new FileHandler();
    std::cout <<"fh end\n";
    
    struct passwd *pw = getpwuid(getuid());
    std::cout << pw->pw_dir;

    return 0;
};
