#pragma once
#include <iostream>
#include <string>
#include "list.hpp"
using namespace std;
struct ListMenu {
	List <string> listOne;
	List <string> listOne_1;
	List <string> listOne_2;
	List <string> listOne_3;
	List <string> listOne_4;
	};

class MenuClass
{
public:
	ListMenu listMenu;
	MenuClass() {
		listMenu.listOne.addElem("Вывыести список студентов (добавить сведения о студенте)");
		listMenu.listOne.addElem("Добавить студента");
		listMenu.listOne.addElem("Удалить студента");
		listMenu.listOne.addElem("Выполнить вариант 75");

		listMenu.listOne_2.addElem("Введите фамилию");
		listMenu.listOne_2.addElem("Введите имя");
		listMenu.listOne_2.addElem("Введите отчество");
		listMenu.listOne_2.addElem("Введите дату рождения");
		listMenu.listOne_2.addElem("Введите год поступление");
		listMenu.listOne_2.addElem("Введите группу");
		listMenu.listOne_2.addElem("Введите институт");
		listMenu.listOne_2.addElem("Введите номер зачетной книжки");
		listMenu.listOne_2.addElem("Введите пол");
		listMenu.listOne_2.addElem("Добавить результаты сессий");



}
	
	

	size_t findMaxLen(List<string>& str) {
		size_t maxLen = 0;
		for (int i = 0; i < str.getSize(); i++) {
			if (maxLen < str[i].size()) maxLen = str[i].size();
		}
		return maxLen;
		
	}

	void drawTopLine(size_t lenTopLine) {
		for (int i = 0; i < lenTopLine; i++) cout << '_'; 
	}

	void draw(){
	while (true) {

	}
	}

	


};

