#pragma once
#include <string>

class Node
{
   public:
       Node();
       Node(std::string& value);
       void setValue(std::string& value);
       std::string getValue();

       Node* parent = nullptr;
       Node* left = nullptr;
       Node* right = nullptr;
    private:
       std::string value;
};
