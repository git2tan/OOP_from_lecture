#pragma once
#include "List.h"				//подключаем класс-родитель?

class CyList:public List		//Класс CyList наследован от класса List
{
public:
	CyList();					//Конструктор по умолчанию
	void add(Time *);			//Метод добавления элемента Time
	Time * remove(int);			//Метод удаления по индексу. Возвращает указатель на удаляемый элемент
	Time * remove(Time *);		//Метод удаления по содержимому. Возвращает указатель на удаляемый элемент	
};
/*
Пример:
List * p = new List();
CyList * q = new CyList();
p=q;

*/

