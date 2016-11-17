#include "Time.h"

Time::Time()
{
}

Time::~Time()
{
}

int Time::compare(Time)
{
	return 0;
}

void Time::save(std::ofstream &)
{

}

void Time::load(std::ifstream &)
{

}

std::ostream & operator<<(std::ostream &os, Time &t)
{
	return os;
}

std::istream & operator >> (std::istream &is, Time &t)
{
	return is;
}
