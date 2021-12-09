#include "Node.h"

class Tree
{
   public:
       const int ADDNODE_STATUS_NIL = -1;
       const int ADDNODE_STATUS_OK = 0;
       const int ADDNODE_STATUS_ERR = 1;

       const int TRAVEL_STATUS_NIL = -1;
       const int TRAVEL_STATUS_OK = 0;
       const int TRAVEL_STATUS_ERR = 1;
        
       Tree();
       ~Tree();      
   protected:
       Node* root = nullptr;
       int addNode_status;
       int travel_status;
   private:
};
