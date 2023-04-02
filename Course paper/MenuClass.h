#pragma once
#include <iostream>
#include <string>
#include "list.hpp"
using namespace std;
struct ListMenu {
	List <string> listOne;
	List <string> listOne_1;
	List <string> listOne_2;
	List <string> listOne_1000;
	List <string> listSex;
	List <string> listSafeStudent;
	List <string> listExams;
	};
struct StructStudent {
	char firstname[40] = "";
	char name[40] = "";
	char patronymic[40] = "";
	unsigned short dayBirth = 0;
	unsigned short monthBirth = 0;
	unsigned short yearBirth = 0;
	unsigned short yearStart = 0;
	char faculty[40] = "";
	char department[40] = "";
	char group[40] = "";
	char id[40] = "";
	char sex[40] = "";
	Exams exam;
	int countFill = 0;
};

class MenuClass
{
private:
	List<Student> students;
	bool firstEditSes = true;
	bool skipInput = false;
	unsigned long long page = 0;
	size_t len;
	size_t CHOICE = 1, choice = 1;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	char key;
	public:
	ListMenu listMenu;
	StructStudent menuStudent;
	MenuClass() {

		listMenu.listOne.addElem("Выход");
		listMenu.listOne.addElem("Выполнить вариант 75");
		listMenu.listOne.addElem("Сохранить БД студентов в файл");
		listMenu.listOne.addElem("Добавить студента");
		listMenu.listOne.addElem("Вывести список студентов (добавить сведения о студенте)");

		listMenu.listOne_1000.addElem("Выход");
		listMenu.listOne_1000.addElem("Добавить результаты сессии");
		listMenu.listOne_1000.addElem("Изменить пол");
		listMenu.listOne_1000.addElem("Изменить номер зачетной книжки");
		listMenu.listOne_1000.addElem("Изменить институт");
		listMenu.listOne_1000.addElem("Изменить кафедру");
		listMenu.listOne_1000.addElem("Изменить группу");
		listMenu.listOne_1000.addElem("Изменить год поступления");
		listMenu.listOne_1000.addElem("Изменить дату рождения");
		listMenu.listOne_1000.addElem("Изменить отчество");
		listMenu.listOne_1000.addElem("Изменить имя");
		listMenu.listOne_1000.addElem("Изменить фамилию");

		listMenu.listOne_2.addElem("Назад");
		listMenu.listOne_2.addElem("Добавить результаты сессий");
		listMenu.listOne_2.addElem("Введите пол");
		listMenu.listOne_2.addElem("Введите номер зачетной книжки");
		listMenu.listOne_2.addElem("Введите институт");
		listMenu.listOne_2.addElem("Введите кафедру");
		listMenu.listOne_2.addElem("Введите группу");
		listMenu.listOne_2.addElem("Введите год поступления");
		listMenu.listOne_2.addElem("Введите дату рождения");
		listMenu.listOne_2.addElem("Введите отчество");
		listMenu.listOne_2.addElem("Введите имя");
		listMenu.listOne_2.addElem("Введите фамилию");

		listMenu.listSex.addElem("Мужской");
		listMenu.listSex.addElem("Женский");

		listMenu.listSafeStudent.addElem("Да");
		listMenu.listSafeStudent.addElem("Нет");

		listMenu.listExams.addElem("Назад");
		listMenu.listExams.addElem("Сессия 9");
		listMenu.listExams.addElem("Сессия 8");
		listMenu.listExams.addElem("Сессия 7");
		listMenu.listExams.addElem("Сессия 6");
		listMenu.listExams.addElem("Сессия 5");
		listMenu.listExams.addElem("Сессия 4");
		listMenu.listExams.addElem("Сессия 3");
		listMenu.listExams.addElem("Сессия 2");
		listMenu.listExams.addElem("Сессия 1");
		

	}


	void clearStudent() {
		strcpy_s(menuStudent.firstname,"");
		strcpy_s(menuStudent.name,"");
		strcpy_s(menuStudent.patronymic, "");
		menuStudent.dayBirth = 0;
		menuStudent.monthBirth = 0;
		menuStudent.yearBirth = 0;
		menuStudent.yearStart = 0;
		strcpy_s(menuStudent.faculty,"");
		strcpy_s(menuStudent.department,"");
		strcpy_s(menuStudent.group,"");
		strcpy_s(menuStudent.id, "");
		strcpy_s(menuStudent.sex, "");
		menuStudent.exam.clear();
		menuStudent.countFill = 0;
	}

	void setFirstname() {
		cout << "Введите фамилию студента: ";
		cin.getline(menuStudent.firstname, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setName() {
		cout << "Введите имя студента: ";
		cin.getline(menuStudent.name, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setPatronymic() {
		cout << "Введите отчество студента: ";
		cin.getline(menuStudent.patronymic, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setBirthday() {
		cout << "Введите день рождения студента: ";
		cin >> menuStudent.dayBirth;
		while (menuStudent.dayBirth > 31 or menuStudent.dayBirth < 1) {
			cout << "Выход из диапазона значений! Повторите попытку: ";
			cin >> menuStudent.dayBirth;
		}
		cout << "\nВведите месяц рождения студента: ";
		cin >> menuStudent.monthBirth;
		cout << "\nВведите год рождения студента: ";
		cin >> menuStudent.yearBirth;
		menuStudent.countFill += 3;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setStartYear() {
		cout << "Введите год начала обучения студента: ";
		cin >> menuStudent.yearStart;
		while (menuStudent.yearStart > 2022 or menuStudent.yearStart < 2020) {
			cout << "Выход из диапазона значений! Повторите попытку: ";
			cin >> menuStudent.yearStart;
		}
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setGroup() {
		cout << "Введите группу студента: ";
		cin.ignore();
		cin.getline(menuStudent.group, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setDepartment() {
		cout << "Введите кафедру студента: ";
		cin.getline(menuStudent.department, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setFaculty() {
		cout << "Введите институт студента: ";
		cin.getline(menuStudent.faculty, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}void setID() {
		cout << "Введите номер зачетной книжки студента: ";
		cin.getline(menuStudent.id, 40);
		Student tempStudent(menuStudent.id);
		int find = students.findElem(tempStudent);
		while (find != -1) {
			cout << "Студент с таким номером зачетной книжки уже есть! Повторите попытку: ";
			cin.getline(menuStudent.id, 40);
			Student tempStudent(menuStudent.id);
			find = students.findElem(tempStudent);
		}
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;

	}void setSex() {
		if (page % 10 == 1) strcpy_s(menuStudent.sex, "Женский");
		else strcpy_s(menuStudent.sex, "Мужской");
		menuStudent.countFill++;
		CHOICE = 10;
		page = 2;

		system("cls");
		skipInput = true;

	}
	void setExam() {
		unsigned short numSessia = page % 10, mark;
		char nameLesson[40] = "";
		cout << "Введите название дисциплины: ";
		if (!firstEditSes) cin.ignore();
		cin.getline(nameLesson, 40);
		cout << "\nВведите оценку за экзамен от 2 до 5 или 0 - незачет, 1 - зачет: ";
		cin >> mark;
		while (mark < 0 or mark > 5) {
			cout << "Выход из диапазона значений!Повторите попытку : ";
			cin >> mark;
		}
		menuStudent.exam.addLesson(numSessia, nameLesson, mark);
		CHOICE = page % 1000;
		page = 2011;
		firstEditSes = false;
		skipInput = true;

	}

	void writeToFile(char* nameFile) {
		FILE* file;
		fopen_s(&file, nameFile, "a+");
		for (int i = 0; i < students.getSize(); i++) {
			fwrite(&students[i], sizeof(Student), 1, file);
		}
		fclose(file);


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
		
		
		fseek(file, 0, SEEK_END);
		size_t lenFile = ftell(file) / 4288;
		for (int i = 0; i < lenFile; i++) {
			fseek(file, 4288 * (i), SEEK_SET);
			Student tempStudent;
			fread(&tempStudent, sizeof(Student), 1, file);
			students.addElem(tempStudent);
		}

		while (true) {
			system("cls"); // очищаем экран
			SetConsoleTextAttribute(h, 0x0007);
			cout << "Меню:" << endl;
			bool page2_is_first = true;
			bool page2012_is_first = true;
			skipInput = false;
			
			for (int i = 0; i < 15; i++) {


				if (page == 0) {
					len = listMenu.listOne.getSize();
					(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					cout << listMenu.listOne[i] << endl;
					if (i + 1 == len) break;
				}
				if (page == 1) {
				len = lenFile + 2;
				Student tempStudent;
				(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
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
				if (page2_is_first) {
					cout << "Фамилия: " << menuStudent.firstname << " Имя: " << menuStudent.name << " Отчество: " << menuStudent.patronymic << endl;
					cout << "Дата рождения: " << menuStudent.dayBirth << "." << menuStudent.monthBirth << "." << menuStudent.yearBirth << " Год начала обучения: "\
						<< menuStudent.yearStart << " Пол: "<< menuStudent.sex << endl;
					cout << "Номер зачетной книжки: " << menuStudent.id << " Группа: " << menuStudent.group << " Институт: " << menuStudent.faculty << " Кафедра: " << menuStudent.department << endl;
					page2_is_first = false;
				}
				len = listMenu.listOne_2.getSize();
				(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
				cout << listMenu.listOne_2[i] << endl;
				if (i + 1 == len) break;
			}
			if (page == 3) {
				len = 1;
				cout << "Введите название файла: ";
				char nameFile[40] = "";
				cin.getline(nameFile, 40);
				writeToFile(nameFile);
				cout << "БД записана в файл'" << nameFile << "'\n";
				system("PAUSE");
				page = 0;
				skipInput = true;

			}
			if (page == 1001) {
				len = lenFile + 1;
				Student tempStudent;
				(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
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
			if (page >= 1002 and page <= 1999) {
				len = listMenu.listOne_1000.getSize();
				(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
				cout << listMenu.listOne_1000[i] << endl;
				if (i + 1 == len) break;
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
				page = 1; CHOICE = 1; i = 0;
				skipInput = true;
				
			}
			if (page > 2000) {
				if (page == 2001) setFirstname();
				if (page == 2002) setName();
				if (page == 2003) setPatronymic();
				if (page == 2004) setBirthday();
				if (page == 2005) setStartYear();
				if (page == 2006) setGroup();
				if (page == 2007) setDepartment();
				if (page == 2008) setFaculty();
				if (page == 2009) setID();
				if (page == 2010) {
					len = 3;
					(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					if (i + 1 < len) cout << listMenu.listSex[i] << endl;
					else {
						cout << "Назад";
						break;
					}
				}
				if (page == 2010001 or page == 2010002) setSex();
				if (page == 2011) {
					len = listMenu.listExams.getSize();
					(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					cout << listMenu.listExams[i] << endl;
					if (i + 1 == len) break;
						
				}
				if (page >= 2011001 and page < 2011009) setExam();
				
				if (page == 2012) {
					len = 2;
					if (menuStudent.countFill == 12) {
						Student newStudent(menuStudent.firstname, menuStudent.name, menuStudent.patronymic, menuStudent.dayBirth, \
							menuStudent.monthBirth, menuStudent.yearBirth, menuStudent.yearStart, menuStudent.faculty, menuStudent.department, \
							menuStudent.group, menuStudent.id, menuStudent.sex, menuStudent.exam);
						students.addElem(newStudent);
						fwrite(&newStudent, sizeof(Student), 1, file);
						page = 0;
						lenFile++;
						skipInput = true;
					}
					else {
						
						if (page2012_is_first)cout << "Вы ввели не все данные о студенте, вы уверенны что хотите выйти, студент не будет занесен в базу данных\n";
						(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						cout << listMenu.listSafeStudent[i] << endl;
						if (i + 1 == len) break;
						page2012_is_first = false;
					}
				}
				
			}
			



			}
			if (skipInput) continue;

			// ждем нажатия клавиши
			key = _getch();

			// обрабатываем нажатие клавиши
			switch (key) {
			case 72: // стрелка вверх
				CHOICE--;
				if (CHOICE < 1) CHOICE = len;
				break;
			case 80: // стрелка вниз
				CHOICE++;
				if (CHOICE > len) CHOICE = 1;
				break;
			case 13: // Enter
				system("cls");
				if (CHOICE == len) {
					if (page == 0) {
						SetConsoleTextAttribute(h, 0x0007);
						return;
					}
					else if (page == 2) {
						page = 2012;
					}
					else if (page == 2012) {
						clearStudent();
						page = 0;
					}
					else page = page / 1000;

				}
				else {
					if (page == 2012) page = page / 1000;
					else page = page * 1000 + CHOICE;

				}
				choice = CHOICE;
				CHOICE = 1;
				firstEditSes = true;

			}
		}


		fclose(file);

	}

};