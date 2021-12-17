#include "Tree.h"

Tree::Tree()
{
   this->createTree();
};

int Tree::get_travel_status()
{
   return this->travel_status;
};

void Tree::createTree()
{

};

void Tree::setLeft(Node* parent, Node* left)
{
   parent->left = left;
   left->parent = parent;
};

void Tree::setRight(Node* parent, Node* right)
{
   parent->right = right;
   right->parent = parent;
};
