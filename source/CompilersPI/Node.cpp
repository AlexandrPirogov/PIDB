#include "Node.h"
#include <string>

Node::Node()
{
    value = "";
};

Node::Node(std::string& value):value(value){};

void Node::setValue(std::string& value)
{
    this->value = value;
};

std::string Node::getValue()
{
   return this->value;
};


