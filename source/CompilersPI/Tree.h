#pragma once
#include "Node.h"

class Tree
{
   public:
       const int TRAVEL_STATUS_NIL = -1;
       const int TRAVEL_STATUS_OK = 0;
       const int TRAVEL_STATUS_ERR = 1;
   
       Tree();
       virtual void travel() = 0;
       int get_travel_status();
   protected:
       virtual void createTree() = 0;
       Node* root = nullptr;
       int travel_status;

       void setLeft(Node* parent, Node* left);
       void setRight(Node* parent, Node* right);
   private:
};
