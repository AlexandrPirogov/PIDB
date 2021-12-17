#pragma once

class Node
{
   public:
       Node();
       Node(char* value);
       void setValue(char* value);
       char* getValue();

       Node* parent = nullptr;
       Node* left = nullptr;
       Node* right = nullptr;
    private:
       char* value;
};
