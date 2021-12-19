#include "SelectTree.h"
#include <string>
#include <cstring>
#include <iostream>

SelectTree::SelectTree(std::string& selectQuery)
{
   this->createTree(selectQuery);
};

void SelectTree::createTree(std::string& selectQuery)
{
	std::string expression(selectQuery);
	expression += " ";
	int len = expression.length();

	this->fillVector(expression);
	this->takeKeyWord();

};

void SelectTree::takeKeyWord()
{
     if(splittedWords.size() == 0)return;
     if(this->root == nullptr)
     {
	 this->root = new Node(this->splittedWords[0]);
         this->splittedWords.erase(this->splittedWords.begin());
	 this->current = this->root;
     } else {
	 Node* rightChild = new Node(this->splittedWords[0]);
	 this->splittedWords.erase(this->splittedWords.begin());
         this->setRight(current, rightChild);
	 this->current = rightChild;
     }  
     this->takeArgs();
};

void SelectTree::takeArgs()
{
   if(splittedWords.size() == 0)return;
   Node* leftChild = new Node(this->splittedWords[0]);
   this->splittedWords.erase(splittedWords.begin());
   this->setLeft(this->current, leftChild);
   this->takeKeyWord(); 
};

void SelectTree::travel(Node* current, std::map<std::string, std::string>& plan)
{
    if(current == nullptr)
    {
	this->travel_status = TRAVEL_STATUS_OK;
        return ;
    };
    std::cout << current->getValue() << std::endl;
    if(current->getValue() == "ВЫБРАТЬ") 
        plan["ВЫБРАТЬ"] = current->left->getValue();
    if(current->getValue() == "ИЗ")
        plan["ИЗ"] = current->left->getValue();	    
    travel(current->left, plan);
    travel(current->right, plan);
};

void SelectTree::fillVector(std::string& expression)
{
    int pos = 0;
    while((pos = expression.find(" ")) != std::string::npos)
    {
        this->splittedWords.push_back(expression.substr(0,pos));
	expression.erase(0, pos+1);
    }
};

