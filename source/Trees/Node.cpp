#include "Node.h"

Node::Node()
{
   this->value = "NULL";
};

Node::Node(char* value) : value(value) {} ;

void Node::setValue(char*value) { this->value = value;};

char* Node::getValue() { return this->value; };

Node::~Node()
{
    delete left;
    delete right;
    delete parent;
};
