#include "filemanager.h"
#include <iostream>
#include <thread>

void Filemanager::WriteNumber(int number)
{
	std::lock_guard<std::mutex> guard(mutexFilemaneger);
    file.open (dataFileName, std::ios::out | std::ios::app);
    file << number << ",";
    file.close();
}

Filemanager::Filemanager(std::string fileNameArg)
{
	dataFileName = fileNameArg;
}

Filemanager::~Filemanager()
{
	if (file.is_open())
	{
  		file.close();
	}
}