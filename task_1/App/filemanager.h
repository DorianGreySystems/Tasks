#ifndef _FILEMANAGER_H_
#define _FILEMANAGER_H_

#include <string>
#include <mutex>
#include <fstream>

class Filemanager
{
public:

	void WriteNumber(int );

	Filemanager(std::string );

	~Filemanager();

	Filemanager(const Filemanager&) = delete;

    Filemanager& operator=(const Filemanager&) = delete;

private:
	std::ofstream file;
	std::string dataFileName;
	std::mutex mutexFilemaneger;
};

#endif // _FILEMANAGER_H_