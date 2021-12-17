#include "Node.h"

Node::Node()
{
    value = "";
};

Node::Node(char* value):value(value){};

void Node::setValue(char* value)
{
    this->value = value;
};

char* Node::getValue()
{
   return this->value;
};


