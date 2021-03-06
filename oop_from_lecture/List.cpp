#include "List.h"
//-----------------------------------------------------------------------------------------------------
//Methods class Elem
//������������:
List::Elem::Elem(Time *t)							//����������� ������ Elem ��������� �� ���� ��������� �� ��� Time (Time *t)
{													
	data = t;										//������������ ��������� �� ���������� ��������� �� ������������ �� ����
	next = NULL;									//��������� �� ��������� ������������� ������������� �� NULL
}

List::Elem::Elem(const List::Elem & t)				//����������� �����������. �� ����� ��������� ������ ������ ������ �� ���� (Elem)
{
	this->data = t.data;							//������������� ������ ���������� ������� (this) ������ �� ������������� �� ����
	this->next = t.next;							//---//---
}

//����������:
List::Elem::~Elem()									//����������
{
	data = NULL;									//������������� �������� ���������� ������� ��� NULL
	next = NULL;									//---//---
}

//�������:
List::Elem * List::Elem::getNext()					//����� ��� ������ �������� �������� ��������� �� ��������� ������� (�� �� ��� ��������� ��������� next)
{													
	return this->next;//����� ������ next			//��� ��� ������������ ��� ��� ���������, �� ���������� ��������� next � �������� �������
}

Time * List::Elem::getData()						//����� ���������� ���������� ������� � ���� ��������� �� ������ ���� Time (�-�: Time * tPtr = �������_�������.getData())
{
	return this->data;								//����� ������ data
}

//������:
void List::Elem::setNext(List::Elem * next)			//����� ����������� ������������� ����� ����� ������� �������� � ��������� (���������� ���������)
{
	this->next = next;								//��� ��� ����� ��������� ��������� �� ������� �� ��������� ���������� ���������� ����� ������������ ����������
}

//������ ���������:
int List::Elem::compare(Elem *t)					//����� ��� ��������� �������� ������� � ������������ �� ��������� � ���������� (�-�: �������_�������.compare(������ � ������� ����������))
{
	return this->data->compare((t->data));			//�.�. � ���� Time ���������� ����� compare �� �������� ��� � �������� �������� Elem (this) ��������� � ��� �����������-��������� �� Time
}

int List::Elem::compare(Time * t)					//���������� � ������ ��������� 0, -1 - ���� obj1 < obj2, +1 - ���� obj1 > obj2
{
	return this->data->compare(t);					//���������� ����������� ������
}

//----------------------------------------------------------------------------------------------------------
//Methods class List

//�����������:
List::List():head(NULL), count(0), last(NULL)		//��������� ������ ����������� ����������� �������� head � last NULL
{
}

//����������:
List::~List()
{
	Elem * cure = head;			//������������� ��������� ��������� ���� Elem �� �������� �������
	while (head != NULL)		//���� �������� ������� �� ����� NULL
	{							
		head = head->getNext();	//��������� ��������� �� �������� ������� �� ���������
		delete cure;			//������� �������
		cure = head;			//������������� ��������� ��������� �� ����� �������� �������
	}
	last = NULL;				//�������� �������� ��������� �� �����
	count = 0;					//�������� �������� ���������� ��� �������� ����������
}

void List::add(Time *t)			//���������� ��������� ��������� �� ������ ���� Time
{
	Elem * n = new Elem(t);		//�������� ������ ��� �������� ������ ������� ���� Elem � �������� ����������� �����������
	n->setNext(head);			//������������� � ���������� � ���������� ������ �������� �������� ������� (�������� ������� � ������ ������)
	head = n;					//������������� � ����� ������ ��������� �� ����� ��������� �������
	if (count == 0)				//���� ���� ��������� ������� �������� �� ������������� ��������� �� ����� �� ���� ������� (�� �����������)
		last = n;
	count++;					//����������� ������� ���������� ���������
}

Time * List::remove(int indx)			//������� ��������� ������� �� �������
{
	Time * resData = NULL;				//������� ��������� �� ��� Time � ������������� ��� � NULL
	Elem * cure = head;					//������� ��������� �� ��� Elem � ������������� ��� �� ��������� �������
	if (indx < count&&indx >= 0)		//���� ������ ���������� (������ ���������� � ������ ���� ����� 0)
	{
		if (indx == 0)					//���� ����� ������� ��������� �������
		{
			head = head->getNext();		//������������� ��������� ������� ����� �������� �� ��������� ������� �� ��������� ����� ����������
			resData = cure->getData();	//��������� ��������� �� ������ ������� ���������
			delete cure;				//������� ������ ���� Elem
		}
		else							//���� ����� ������� �� ������ �������
		{
			for (int i = 0; i < indx - 1; i++, cure = cure->getNext());	//��������� � ����� �� ������� ����� ���� (�� ���� ����������� �� ���������� ����� ������) 
			Elem * temp = cure->getNext();	//�������� ��������� ��� �������� ������ ���������� �������� (������� � �������� �������)
			cure->setNext(temp->getNext());	//��������� � �������� ��������� ����� ���� ������� ������� ���� ����� ����������
			resData = temp->getData();		//�������� ��������� ��� �������� ����������� ���������� ��������
			delete temp;					//������� �������, �� �� ����������
			if (indx == (count - 1))		//���� ��������� �������� ���������� �������� ������
				last = cure;				//��������� ��������� �� ��������� ������� ������
		}
		count--;						//��������� ���������� ��������� �� 1 
	}
	return resData;						//���������� ��������� �� �������� � ��������� �������� ������
}

Time * List::remove(Time * t)				//�������� �� ����������� (��������� ��������� �� ������ ���� Time)
{
	return this->remove(this->search(t));	//������� ������� �� ������� ������� ������ ������� ������ ������� �� �����������
}

List& List::concat(const List& t)		//���������� ���� ������� � ����������� ������ ������ � �������� ��������� ������ ������
{
	for (int i = 0; i < t.count; i++)	//��������� � ����� �� ������������� ������
	{
		this->add(t.get(i));			//��������� ������ ������� ��������� ������� ��������
	}
	return *this;						//��� �������� �� ������� �� ���������� ������ �� ������ ����
}

List& List::copy(const List & t)		//����������� ������
{
	this->~List();						//������� ������������� �������� ���������� ��� ���� ����� ���� ���������� � ��� ��� ����� ��������
	return this->concat(t);				//���������� ��������� ������ ������� concat(t)
}

int List::search(Time * t)				//����� �� ������ ������ �����������, �� ������� ��������� ��������� �� ������ ���� Time, 
										//� �������� ���������� ���������� ������ �������� �������� ��� -1 ���� �� �������
{
	int resIndx = -1, i = 0;			//�������� ���������� ��� �������� ���������� � ������� ��� �������� -1

	for (Elem * cure = head; cure != NULL; i++, cure = cure->getNext())	//�������� � ����� �� ������ �� �����
	{
		if (cure->compare(t) == 0)		//���� ��� �����
		{
			resIndx = i;				//����������� ���������� ������� ������
			break;						//��������� ����
		}
	}
	return resIndx;						//���������� ���������
}

void List::sort()						//����������
{
	throw NotSupportedException();		//�� �����������
}

void List::save(std::ofstream &ofs)		//����� ��� ���������� � ���� (������������)
{
	ofs << this->count << std::endl;	//���������� ������� ���������� ��������� � �����
	for (Elem*cure = head; cure != NULL; cure = cure->getNext())	//� ����� �������� �� ������� �������� �� ����� �����
	{
		cure->getData()->save(ofs);		//��������� ����� ������� ��� ����� ���������� � ������ Time �� ���������� ������ � ����
	}
	//return ofs;
}

void List::load(std::ifstream &ifs)		//����� ��� �������� �� ����� (��������������)
{
	int cnt;							//������� ���������� ��� �������� ���������� ���������
	this->~List();						//����������� ������ ��� ����������� ������
	ifs >>cnt;							//��������� �� ����� - ������� ���� �������� ���������
	for (int i = 0; i < cnt; i++)		//�������� ���� �������� � ���� ��������� - ������� ���������� �� �������
	{
		Time * t = new Time();			//�������� ������ ��� ����� ������� ���� Time
		t->load(ifs);					//��������� ������
		this->add(t);					//��������� � ������
	}
}

Time * List::get(int indx) const		//����� ��� ��������� ��������� �� ���������� (�� ������ ���� Time) ��������� ������
{
	Time * resData = NULL;				//������� ��������� ��� �������� ���������� � ���������� ���� NULL ����� � ������ ���� ��������� ��� ��������
	if (indx < count&&indx >= 0)		//���� ������ ����������
	{
		Elem * cure = head;				//������� ��������� � ������������� ��� �� ��������� �������
		for (; indx != 0; indx--, cure = cure->getNext());	//���������� ��������� �� ��������� ������� "������" ��� �����
		resData = cure->getData();		//��������� ������
		//for (Elem * cure = head;; (indx != 0) ? (indx--, cure = cure->getNext()) : (return cure->getData()));
		
	}
	return resData;						//���������� ������ (���� ������ ��� ����� ������� �������� NULL)
}

int List::getCount()					//����� ��� ��������� ��������� �� ���������� (�� ������ ���� Time) ��������� ������
{
	return this->count;					//���������� ���������� ��������� �������� ������
}

List & List::operator+(Time * t)		//���������� ��������� "+" (��� ��������: List + Time)
{
	this->add(t);						//��������� ���� ������� ���� Time  � ������� ������
	return *this;						//���������� ������ �� ���� �� ������
}

List & List::operator+(const List & t)	//���������� ��������� "+" (��� ��������: List +list)
{
	return this->concat(t);				//������ ������ �� ������������ ������ �� ������ �������
}

List & List::operator-(Time *t)			//���������� ��������� "-" (��� ��������: List - Time)
{
	this->remove(t);					//������� ������� ������ �� �����������
	return *this;						//���������� ������ �� ������� ������
}

List & List::operator-()				//���������� ��������� ����������� "-" (��� ��������: -List)
{
	this->~List();						//�������� ���������� ��� �������� ������
	return *this;						//���������� ������ �� ����, �� ���� ��� ������
}

std::ostream & operator<<(std::ostream & os, List & t)	//���������� ��������� ��������� � �����
{
	os << t.count << std::endl;			//�������� � ����� ������� ���������� ��������� � ������, ����� ������ ����� ������
	List::Elem* cure = t.head;			//������� ��������� �� Elem � ������������� ��� �� ������ �������
	while (cure != NULL)				//���� �� ����� ������
	{
		os << *(cure->getData())<<"  ";	//�������������, ��� ��� Time ������� "��������� � �����" ��� ������������ 
		cure = cure->getNext();			//���������� ��������� �� ��������� ������� � ������
	}	
	return os;							//���������� ����� ������
}

std::istream & operator >> (std::istream & is, List & t)	//���������� ��������� ���������� �� ������
{
	std::cout << "Enter size:\n";		//������� �������� ������������ ������ ���������� ��������� � ������
	int size;							//������� ������������� ���������� ��� �������� ����� ��������
	is >> size;							//��������� �� ������ � ��� ����������
	for (int i = 0; i < size; i++)		//���� �� ������� ����������� ���������� ��������
	{
		Time * tmp = new Time();		//�������� ������ ��� ����� ������� ���� Time
		is >> *tmp;						//�������������, ��� ��� Time ������� "����� �� ������" ��� ������������
		t.add(tmp);						//��������� ���� ������� � ������� ������
	}
	return is;							//���������� ����� �����
}
