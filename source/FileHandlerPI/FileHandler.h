#pragma once

class FileHandler
{
   public:
       
       const int READ_STATUS_NIL = -1;
       const int WRITE_STATUS_NIL = -1;
       const int OPEN_STATUS_NIL = -1;
       
       FileHandler();
       
       void write();
       void open();
       void read();
       
       int get_write_status();
       int get_open_status();
       int get_read_status();
   protected:
       void init();
   private:
       int write_status;
       int open_status;
       int read_status;
};
