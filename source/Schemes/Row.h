#pragma once
#include <string>

class Row 
{
   public:
       const int SET_STATUS_OK = 0;
       const int SET_STATUS_ERR = 1;
       const int SET_STATUS_NIL = -1;

       Row();
       void setValue(std::string value);
       std::string getValue();
   protected:
       
   private:
       std::string value;
};
