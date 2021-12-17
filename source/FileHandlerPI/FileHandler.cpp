#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

FileHandler::FileHandler()
{
   init(); 
};

void FileHandler::write()
{

};

void FileHandler::open()
{

};

void FileHandler::read()
{

};

void FileHandler::init()
{
    int meta = mkdir("/home/alex/PIDB", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    mkdir("/home/alex/PIDB/meta", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    mkdir("/home/alex/PIDB/data", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    mkdir("/home/alex/PIDB/data/schemes", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    mkdir("/home/alex/PIDB/data/tables", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    mkdir("/home/alex/PIDB/meta/schemes", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    mkdir("/home/alex/PIDB/meta/tables", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
};

int FileHandler::get_write_status()
{
   return this->write_status;
};

int FileHandler::get_open_status()
{
   return this->open_status;
};

int FileHandler::get_read_status()
{
   return this->read_status;
};
