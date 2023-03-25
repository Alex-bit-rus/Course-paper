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
		listMenu.listOne.addElem("Выход");
		listMenu.listOne.addElem("Выполнить вариант 75");
		listMenu.listOne.addElem("Сохранить БД студентов в файл");
		listMenu.listOne.addElem("Добавить студента");
		listMenu.listOne.addElem("Вывыести список студентов (добавить сведения о студенте)");
		
		listMenu.listOne_2.addElem("Назад");
		listMenu.listOne_2.addElem("Добавить результаты сессий");
		listMenu.listOne_2.addElem("Введите пол");
		listMenu.listOne_2.addElem("Введите номер зачетной книжки");
		listMenu.listOne_2.addElem("Введите институт");
		listMenu.listOne_2.addElem("Введите группу");
		listMenu.listOne_2.addElem("Введите год поступление");
		listMenu.listOne_2.addElem("Введите дату рождения");
		listMenu.listOne_2.addElem("Введите отчество");
		listMenu.listOne_2.addElem("Введите имя");
		listMenu.listOne_2.addElem("Введите фамилию");
		
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

	void draw() {
		unsigned short page = 0;
		size_t len;
		int choice = 1;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD c;
		char key;

		while (true) {

			system("cls"); // очищаем экран
			SetConsoleTextAttribute(h, 0x0007);
			cout << "Меню:" << endl;

			for (int i = 1; i < 15; i++) {
				if (page == 0) {
					len = listMenu.listOne.getSize();
					(choice == i ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); 
					cout << listMenu.listOne[i-1] << endl;
					if (i == len) break;
				}
				if (page == 2) {
					len = listMenu.listOne_2.getSize();
					(choice == i ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					cout << listMenu.listOne_2[i - 1] << endl;
					if (i == len) break;
				}
				
			}
			

			// ждем нажатия клавиши
			key = _getch();

			// обрабатываем нажатие клавиши
			switch (key) {
			case 72: // стрелка вверх
				choice--;
				if (choice < 1) choice = len;
				break;
			case 80: // стрелка вниз
				choice++;
				if (choice > len) choice = 1;
				break;
			case 13: // Enter
				system("cls");
				if (choice == len) {
					if (page == 0) return;
					else page = page / 10;
				
				}
				else page = page*10+choice;
				choice = 1;

			}
		}




	}

};