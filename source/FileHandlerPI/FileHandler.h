#pragma once
#include <string>
#include <vector>

class FileHandler
{
   public:

       const int READ_STATUS_NIL = -1;
       const int READ_STATUS_OK =  0;
       const int READ_STATUS_ERR =  1;

       const int WRITE_STATUS_NIL = 0;
       const int WRITE_STATUS_OK = -1;
       const int WRITE_STATUS_ERR = -1;

       const int OPEN_STATUS_NIL = -1;
       const int OPEN_STATUS_OK = 0;
       const int OPEN_STATUS_ERR = 1;
    
       const int GETENTITIES_STATUS_NIL = -1;
       const int GETENTITIES_STATUS_OK = 0;
       const int GETENTITIES_STATUS_ERR = 1;
       FileHandler();
       
       void write();
       void open();
       void read(std::string& path, std::string& filename);
       void readEntities(std::string& path);
       std::vector<std::string> getRecords();
       std::vector<std::string> getEntities();

       int get_write_status();
       int get_open_status();
       int get_read_status();
       int get_getEntities_status();
   protected:
       void init();
   private:
       int write_status;
       int open_status;
       int read_status;
       int getEntities_status; 
       std::vector<std::string> records;
       std::vector<std::string> entities;
};
