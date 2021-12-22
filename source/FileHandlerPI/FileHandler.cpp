#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <string>
#include <vector>
#include <dirent.h>
#include <stdio.h>


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

void FileHandler::read(std::string& path, std::string& filename)
{
    records.clear();
	std::string line;
	std::ifstream infile(path + "/" + filename);
	if(infile.is_open())
	{
	   while(std::getline(infile, line))
	   {
           std::cout << "Adding " << line << '\n';
           this->records.push_back(line);	
	   };
	   this->read_status = READ_STATUS_OK;
	} else {

            this->read_status = READ_STATUS_ERR;
	}
};

void FileHandler::init()
{
    system("sudo mkdir -p /PIDB");
    system("sudo mkdir -p /PIDB/meta");
    system("sudo mkdir -p /PIDB/data");
    system("sudo mkdir -p /PIDB/data/schemes");
    system("sudo mkdir -p /PIDB/data/tables");
    system("sudo mkdir -p /PIDB/meta/schemes");
    system("sudo mkdir -p /PIDB/meta/tables");
 
};

void FileHandler::readEntities(std::string& path)
{
DIR *d;
  struct dirent *dir;
  d = opendir(path.c_str());
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      this->entities.push_back(dir->d_name);
     
    }
    closedir(d);
  }
  this->entities.erase(this->entities.begin());
  this->entities.erase(this->entities.begin());

};

std::vector<std::string> FileHandler::getEntities()
{
   return this->entities;
};

std::vector<std::string> FileHandler::getRecords()
{
    return this->records;
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

int FileHandler::get_getEntities_status()
{
   return this->getEntities_status;
};
