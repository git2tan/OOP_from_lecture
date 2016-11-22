#pragma once
#include <fstream>

class ISaveLoader
{
public:
	virtual int compare(ISaveLoader *) = 0;
	virtual void save(std::ofstream &) = 0;
	virtual void load(std::ifstream &) = 0;
	virtual friend std::ostream& operator<<(std::ostream &, ISaveLoader&);
	virtual friend std::istream& operator >> (std::istream &, ISaveLoader&);
};

