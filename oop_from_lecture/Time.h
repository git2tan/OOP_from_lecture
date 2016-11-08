#pragma once
#include <fstream>
class Time
{
public:
	Time();
	~Time();
	int compare(Time);
	void save(std::ofstream &);
	void load(std::ifstream &);
};

