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
struct StructStudent {
	char firstname[40];
	char name[40];
	char patronymic[40];
	unsigned short dayBirth;
	unsigned short monthBirth;
	unsigned short yearBirth;
	unsigned short yearStart;
	char faculty[40];
	char department[40];
	char group[40];
	char id[40];
	char sex[40];
	Exams exam;
};

class MenuClass
{
	public:
	ListMenu listMenu;
	StructStudent menuStudent;
	MenuClass() {
		listMenu.listOne.addElem("Выход");
		listMenu.listOne.addElem("Выполнить вариант 75");
		listMenu.listOne.addElem("Сохранить БД студентов в файл");
		listMenu.listOne.addElem("Добавить студента");
		listMenu.listOne.addElem("Вывести список студентов (добавить сведения о студенте)");

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

	void draw(FILE* file) {
		fopen_s(&file, "file.bin", "a+");
		List<Student> students;
		unsigned long long page = 0;
		size_t len;
		size_t choice = 1;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD c;
		char key;
		
		fseek(file, 0, SEEK_END);
		size_t lenFile = ftell(file) / 4288;
		for (int i = 0; i < lenFile; i++) {
			fseek(file, 4288 * (i), SEEK_SET);
			Student tempStudent;
			fread(&tempStudent, sizeof(Student), 1, file);
			students.addElem(tempStudent);
		}

		while (true) {
startWhile:	system("cls"); // очищаем экран
			SetConsoleTextAttribute(h, 0x0007);
			cout << "Меню:" << endl;

			for (int i = 0; i < 15; i++) {


				if (page == 0) {
					len = listMenu.listOne.getSize();
					(choice == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					cout << listMenu.listOne[i] << endl;
					if (i + 1 == len) break;
				}
				if (page == 1) {
				len = lenFile + 2;
				Student tempStudent;
				(choice == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
				if (i == 0) cout << "Удалить студента" << endl;

				else if (i + 1 <= len-1) {
					fseek(file, 4288 * (i - 1), SEEK_SET);
					fread(&tempStudent, sizeof(Student), 1, file);
					cout << tempStudent << endl;
				}
				else cout << "Назад";
				if (i + 1 == len) break;
			}
			if (page == 2) {
				len = listMenu.listOne_2.getSize();
				(choice == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
				cout << listMenu.listOne_2[i] << endl;
				if (i + 1 == len) break;
			}
			if (page == 1001) {
				len = lenFile + 1;
				Student tempStudent;
				(choice == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
				if (i + 1 != len) {
					fseek(file, 4288 * (i), SEEK_SET);
					fread(&tempStudent, sizeof(Student), 1, file);
					cout << tempStudent << endl;
				}
				else {
					cout << "Назад";
					break;
				}
			}
			if (page >= 1001001 and page <= 1001999) {
				len = lenFile + 1;
				size_t index = lenFile - (page - 1001001)-1;
				students.removeElem(index);
				lenFile--;
				fclose(file);
				fopen_s(&file, "file.bin", "w");
				for (int j = lenFile-1; j > -1; j--) {
					fwrite(&students[j], sizeof(Student), 1, file);
				}
				fclose(file);
				fopen_s(&file, "file.bin", "a+");
				system("cls");
				page = 1; choice = 1; i = 0;
				goto startWhile;
				
			}
			if (page > 2000) {
				if (page == 2001) {
					cout << "Ddtlbnt afvbkb.";
					cin.getline(menuStudent.firstname, 40);
					page = 2;
					system("cls");
					goto startWhile;

				}
				if (page == 2002) {
					cout << "Ddtlbnt afvbkb.";
					cin.getline(menuStudent.name, 40);
					page = 2;
					system("cls");
					goto startWhile;

				}
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
					else page = page / 1000;

				}
				else page = page * 1000 + choice;
				choice = 1;

			}
		}


		fclose(file);

	}

};