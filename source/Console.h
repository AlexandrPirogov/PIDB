#include <iostream>

class Console
{
   public:
       const int READ_STATUS_OK = 0;
       const int READ_STATUS_NIL = -1;
       const int READ_STATUS_ERR = 1;

       Console();
       void readCommand();
       int get_read_status();
       protected:
   private:
       int read_status;
       char* command;
};
