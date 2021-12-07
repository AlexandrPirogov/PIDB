#pragma once

class crudStatuses
{
   public:
       const int CREATE_STATUS_OK = 0;
       const int CREATE_STATUS_ERR = 1;
       const int CREATE_STATUS_NIL = -1;

       const int DROP_STATUS_OK = 0;
       const int DROP_STATUS_ERR = -1;
       const int DROP_STATUS_NIL = 1;

       const int UPDATE_STATUS_OK = 0;
       const int UPDATE_STATUS_ERR = -1;
       const int UPDATE_STATUS_NIL = 1;
    protected:
       int create_status;
       int drop_status;
       int update_status;
};
