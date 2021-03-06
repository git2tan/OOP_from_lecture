#pragma once
#include <fstream>
#include <iostream>
#include "Time.h"

/*14.11.16 �/� �������� ��������� last (��������� �� ����� ������) � ���������� ���������� ���������*/

class List						//����� ������ (List)
{
protected:
	
	class Elem					//����� ������� ������ (Elem)
	{
		Time * data;			//��������� �� ���������� (�� ��������� �������� ��� private)

		Elem * next;			//��������� �� ��������� ������� ������	(�� ��������� �������� ��� private)

	public:
		//������������:
		Elem(Time *);			//����������� ������ Elem ����������� �� ���� ��������� �� ������ ���� Time 
		
		Elem(const Elem &);		//����������� �����������. �� ����� ��������� ������ ������ ������ �� ���� (Elem)
		
		//����������:
		~Elem();				//����������
		
		//�������:
		Elem *getNext();		//����� ��� ������ �������� �������� ��������� �� ��������� ������� (�� �� ��� ��������� ��������� next � ���12)
		
		Time *getData();		//����� ���������� ���������� ������� � ���� ��������� �� ������ ���� Time (�-�: Time * tPtr = �������_�������.getData())

		//������:
		void setNext(Elem *);	//����� ����������� ������������� ����� ����� ������� �������� � ��������� (���������� ���������)
		
		//������ ��������:
		int compare(Elem *);	//����� ��� ��������� �������� ������� � ������������ �� ��������� � ���������� (�-�: �������_�������.compare(������ � ������� ����������))

		int compare(Time * t);	//���������� � ������ ��������� 0, -1 - ���� obj1 < obj2, +1 - ���� obj1 > obj2
	};

	Elem *head;					//���������� head ��� �������� ��������� �� ������������ ������ ���� Elem

	Elem *last;					//��������� ��� �������� ��������� �� �������� ������� ���� Elem
	
	int count;					//���������� ��� �������� �������� ���������� ������������ ���������

public:

	List();						//����������� �� ���������

	~List();					//����������

	void add(Time *);			//���������� ��������� ��������� �� ������ ���� Time

	Time *remove(int);			//�������� �� �������
	
	Time *remove(Time *);		//�������� �� ����������� (��������� ��������� �� ������ ���� Time)
	
	List& concat(const List&);	//���������� ���� ������� � ����������� ������ ������ � �������� ��������� ������ ������
								//��� ���� ����� ����������� ������ �� ������ ���� ��� ���� ����� ���� ����������� ������������
								//������������� ������������. ��������: ������1.concat(������2).concat(������3);
	
	List& copy(const List&);	//����������� ������
	
	int search(Time *);			//����� �� ������ ������ �����������, �� ������� ��������� ��������� �� ������ ���� Time, 
								//� �������� ���������� ���������� ������ �������� �������� 
	void sort();				//����������
	
	void save(std::ofstream &);	//����� ��� ���������� � ���� (������������)

	void load(std::ifstream &);	//����� ��� �������� �� ����� (��������������)

	Time *get(int) const;		//����� ��� ��������� ��������� �� ���������� (�� ������ ���� Time) ��������� ������
	
	int getCount();				//������ ��� ��������� ���������� ��������� � ������. ���������� int

	List& operator+(Time *);	//��������? ���������� List + Time

	List& operator+(const List&);	//���������� List + List

	List& operator-(Time*);		//���������� List - Time

	List& operator-();			//���������� -List

	friend std::ostream& operator<<(std::ostream &,List&);		//���������� ��������� ��������� � �����

	friend std::istream& operator>> (std::istream &, List&);	//���������� ��������� ���������� �� ������
};

/*
	���������� ����������
	List + Time
	List + List
	List - Time
	ios<<List
	ios>>List
	-List	
	*/