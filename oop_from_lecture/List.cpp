#include "List.h"
//-----------------------------------------------------------------------------------------------------
//Methods class Elem

List::Elem::Elem(Time *t)
{
	data = t;
	next = NULL;
}
List::Elem::Elem(const List::Elem & t)
{
	data = t.data;
	next = t.next;
}

List::Elem::~Elem()
{
	data = NULL;
	next = NULL;
}

List::Elem * List::Elem::getNext()
{
	return this->next;
}

void List::Elem::setNext(List::Elem * next)
{
	this->next = next;
}

Time * List::Elem::getData()
{
	return this->data;
}

int List::Elem::compare(Elem *t)
{
	return this->data->compare(*(t->data));
}

int List::Elem::compare(Time * t)
{
	return this->data->compare(*t);
}
//----------------------------------------------------------------------------------------------------------
//Methods class List

List::List():head(NULL), count(0)
{
}

List::~List()
{
	Elem * cure = head;
	while (head != NULL)
	{
		head = head->getNext();
		delete cure;
		cure = head;
	}
	count = 0;
}

void List::add(Time *t)	//Вставка в начало
{
	Elem * n = new Elem(t);
	n->setNext(head);
	head = n;
	count++;
}

Time * List::remove(int indx)	//Функция удалающая элемент по индексу
{
	Time * resData = NULL;
	Elem * cure = head;
	if (indx < count&&indx >= 0)
	{
		if (indx == 0)
		{
			head = head->getNext();
			resData = cure->getData();
			delete cure;
		}
		else
		{
			for (int i = 0; i < indx - 1; i++, cure = cure->getNext());
			Elem * temp = cure->getNext();
			cure->setNext(temp->getNext());
			resData = temp->getData();
			delete temp;
		}
		count--;
	}
	return resData;
}

Time * List::remove(Time * t)
{
	return this->remove(this->search(t));
}

List& List::concat(const List& t)
{
	for (int i = 0; i < t.count; i++)
	{
		this->add(t.get(i));
	}
	return *this;
}

List& List::copy(const List & t)
{
	this->~List();
	return this->concat(t);
}

int List::search(Time * t)
{
	int resIndx = -1, i = 0;

	for (Elem * cure = head; cure != NULL; i++, cure = cure->getNext())
	{
		if (cure->compare(t) == 0)
		{
			resIndx = i;
			break;
		}
	}
	return resIndx;
}

void List::sort()
{
	throw NotSupportedException();//Не реализовано
}

void List::save(std::ofstream &ofs)
{
	ofs << this->count << std::endl;
	for (Elem*cure = head; cure != NULL; cure = cure->getNext())
	{
		cure->getData()->save(ofs);
	}
	//return ofs;
}

void List::load(std::ifstream &ifs)
{
	int cnt;
	this->~List();
	ifs >>cnt;
	for (int i = 0; i < cnt; i++)
	{
		Time * t = new Time();
		t->load(ifs);
		this->add(t);
	}
}

Time * List::get(int indx) const
{
	Time * resData = NULL;
	if (indx < count&&indx >= 0)
	{
		Elem * cure = head;
		for (; indx != 0; indx--, cure = cure->getNext());
		resData = cure->getData();
		//for (Elem * cure = head;; (indx != 0) ? (indx--, cure = cure->getNext()) : (return cure->getData()));
		
	}
	return resData;
}

int List::getCount()
{
	return this->count;
}

List & List::operator+(Time * t)
{
	this->add(t);
	return *this;
}

List & List::operator+(const List & t)
{
	return this->concat(t);
}

List & List::operator-(Time *t)
{
	this->remove(t);
	return *this;
}

List & List::operator-()
{
	this->~List();
	return *this;
}

std::ostream & operator<<(std::ostream & os, List & t)
{
	os << t.count << std::endl;
	List::Elem* cure = t.head;
	while (cure != NULL)
	{
		os << *(cure->getData())<<"  ";	//Подразумеваем, что для Time функция "помещения в поток" уже пергергужена 
		cure = cure->getNext();
	}	
	return os;
}

std::istream & operator >> (std::istream & is, List & t)
{
	std::cout << "Enter size:\n";
	int size;
	is >> size;
	for (int i = 0; i < size; i++)
	{
		Time * tmp = new Time();
		is >> *tmp;				//Подразумеваем, что для Time функция "взять из потока" уже пергергужена
		t.add(tmp);
	}
	return is;
}
