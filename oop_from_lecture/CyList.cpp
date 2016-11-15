#include "CyList.h"

CyList::CyList():List()
{
}

void CyList::add(Time * t)
{
	this->List::add(t);
	this->last->setNext(this->head);
}

Time * CyList::remove(int indx)
{
	
	Time *r = this->List::remove(indx);
	if (last != NULL)
		last->setNext(head);
	return r;
}

Time * CyList::remove(Time *t)
{
	Time *r = this->List::remove(t);
	if (last != NULL)
		last->setNext(head);
	return r;
}
