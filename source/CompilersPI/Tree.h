#pragma once
#include "Node.h"
#include <string>
#include <vector>
#include <map>

class Tree
{
   public:
       const int TRAVEL_STATUS_NIL = -1;
       const int TRAVEL_STATUS_OK = 0;
       const int TRAVEL_STATUS_ERR = 1;
   

       
       virtual void travel(Node* current, std::map<std::string, std::string>& plan) = 0;
       
      
       Node* getRoot();
       int get_travel_status();
   protected:
            
       int travel_status;

       Node* root = nullptr;
       Node* current = nullptr;
 
       std::vector<std::string> splittedWords;
       void setLeft(Node* parent, Node* left);
       void setRight(Node* parent, Node* right);
       virtual void createTree(std::string& selectQuery) = 0;
   private:
};
