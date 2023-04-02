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

		listMenu.listOne.addElem("�����");
		listMenu.listOne.addElem("��������� ������� 75");
		listMenu.listOne.addElem("��������� �� ��������� � ����");
		listMenu.listOne.addElem("�������� ��������");
		listMenu.listOne.addElem("������� ������ ��������� (�������� �������� � ��������)");

		listMenu.listOne_1000.addElem("�����");
		listMenu.listOne_1000.addElem("�������� ���������� ������");
		listMenu.listOne_1000.addElem("�������� ���");
		listMenu.listOne_1000.addElem("�������� ����� �������� ������");
		listMenu.listOne_1000.addElem("�������� ��������");
		listMenu.listOne_1000.addElem("�������� �������");
		listMenu.listOne_1000.addElem("�������� ������");
		listMenu.listOne_1000.addElem("�������� ��� �����������");
		listMenu.listOne_1000.addElem("�������� ���� ��������");
		listMenu.listOne_1000.addElem("�������� ��������");
		listMenu.listOne_1000.addElem("�������� ���");
		listMenu.listOne_1000.addElem("�������� �������");

		listMenu.listOne_2.addElem("�����");
		listMenu.listOne_2.addElem("�������� ���������� ������");
		listMenu.listOne_2.addElem("������� ���");
		listMenu.listOne_2.addElem("������� ����� �������� ������");
		listMenu.listOne_2.addElem("������� ��������");
		listMenu.listOne_2.addElem("������� �������");
		listMenu.listOne_2.addElem("������� ������");
		listMenu.listOne_2.addElem("������� ��� �����������");
		listMenu.listOne_2.addElem("������� ���� ��������");
		listMenu.listOne_2.addElem("������� ��������");
		listMenu.listOne_2.addElem("������� ���");
		listMenu.listOne_2.addElem("������� �������");

		listMenu.listSex.addElem("�������");
		listMenu.listSex.addElem("�������");

		listMenu.listSafeStudent.addElem("��");
		listMenu.listSafeStudent.addElem("���");

		listMenu.listExams.addElem("�����");
		listMenu.listExams.addElem("������ 9");
		listMenu.listExams.addElem("������ 8");
		listMenu.listExams.addElem("������ 7");
		listMenu.listExams.addElem("������ 6");
		listMenu.listExams.addElem("������ 5");
		listMenu.listExams.addElem("������ 4");
		listMenu.listExams.addElem("������ 3");
		listMenu.listExams.addElem("������ 2");
		listMenu.listExams.addElem("������ 1");
		

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
		cout << "������� ������� ��������: ";
		cin.getline(menuStudent.firstname, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setName() {
		cout << "������� ��� ��������: ";
		cin.getline(menuStudent.name, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setPatronymic() {
		cout << "������� �������� ��������: ";
		cin.getline(menuStudent.patronymic, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setBirthday() {
		cout << "������� ���� �������� ��������: ";
		cin >> menuStudent.dayBirth;
		while (menuStudent.dayBirth > 31 or menuStudent.dayBirth < 1) {
			cout << "����� �� ��������� ��������! ��������� �������: ";
			cin >> menuStudent.dayBirth;
		}
		cout << "\n������� ����� �������� ��������: ";
		cin >> menuStudent.monthBirth;
		cout << "\n������� ��� �������� ��������: ";
		cin >> menuStudent.yearBirth;
		menuStudent.countFill += 3;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setStartYear() {
		cout << "������� ��� ������ �������� ��������: ";
		cin >> menuStudent.yearStart;
		while (menuStudent.yearStart > 2022 or menuStudent.yearStart < 2020) {
			cout << "����� �� ��������� ��������! ��������� �������: ";
			cin >> menuStudent.yearStart;
		}
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setGroup() {
		cout << "������� ������ ��������: ";
		cin.ignore();
		cin.getline(menuStudent.group, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setDepartment() {
		cout << "������� ������� ��������: ";
		cin.getline(menuStudent.department, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}
	void setFaculty() {
		cout << "������� �������� ��������: ";
		cin.getline(menuStudent.faculty, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		page = 2;
		system("cls");
		skipInput = true;
	}void setID() {
		cout << "������� ����� �������� ������ ��������: ";
		cin.getline(menuStudent.id, 40);
		Student tempStudent(menuStudent.id);
		int find = students.findElem(tempStudent);
		while (find != -1) {
			cout << "������� � ����� ������� �������� ������ ��� ����! ��������� �������: ";
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
		if (page % 10 == 1) strcpy_s(menuStudent.sex, "�������");
		else strcpy_s(menuStudent.sex, "�������");
		menuStudent.countFill++;
		CHOICE = 10;
		page = 2;

		system("cls");
		skipInput = true;

	}
	void setExam() {
		unsigned short numSessia = page % 10, mark;
		char nameLesson[40] = "";
		cout << "������� �������� ����������: ";
		if (!firstEditSes) cin.ignore();
		cin.getline(nameLesson, 40);
		cout << "\n������� ������ �� ������� �� 2 �� 5 ��� 0 - �������, 1 - �����: ";
		cin >> mark;
		while (mark < 0 or mark > 5) {
			cout << "����� �� ��������� ��������!��������� ������� : ";
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
			system("cls"); // ������� �����
			SetConsoleTextAttribute(h, 0x0007);
			cout << "����:" << endl;
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
				if (i == 0) cout << "������� ��������" << endl;

				else if (i + 1 <= len-1) {
					fseek(file, 4288 * (i - 1), SEEK_SET);
					fread(&tempStudent, sizeof(Student), 1, file);
					cout << tempStudent << endl;
				}
				else cout << "�����";
				if (i + 1 == len) break;
			}
			if (page == 2) {
				if (page2_is_first) {
					cout << "�������: " << menuStudent.firstname << " ���: " << menuStudent.name << " ��������: " << menuStudent.patronymic << endl;
					cout << "���� ��������: " << menuStudent.dayBirth << "." << menuStudent.monthBirth << "." << menuStudent.yearBirth << " ��� ������ ��������: "\
						<< menuStudent.yearStart << " ���: "<< menuStudent.sex << endl;
					cout << "����� �������� ������: " << menuStudent.id << " ������: " << menuStudent.group << " ��������: " << menuStudent.faculty << " �������: " << menuStudent.department << endl;
					page2_is_first = false;
				}
				len = listMenu.listOne_2.getSize();
				(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
				cout << listMenu.listOne_2[i] << endl;
				if (i + 1 == len) break;
			}
			if (page == 3) {
				len = 1;
				cout << "������� �������� �����: ";
				char nameFile[40] = "";
				cin.getline(nameFile, 40);
				writeToFile(nameFile);
				cout << "�� �������� � ����'" << nameFile << "'\n";
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
					cout << "�����";
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
						cout << "�����";
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
						
						if (page2012_is_first)cout << "�� ����� �� ��� ������ � ��������, �� �������� ��� ������ �����, ������� �� ����� ������� � ���� ������\n";
						(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						cout << listMenu.listSafeStudent[i] << endl;
						if (i + 1 == len) break;
						page2012_is_first = false;
					}
				}
				
			}
			



			}
			if (skipInput) continue;

			// ���� ������� �������
			key = _getch();

			// ������������ ������� �������
			switch (key) {
			case 72: // ������� �����
				CHOICE--;
				if (CHOICE < 1) CHOICE = len;
				break;
			case 80: // ������� ����
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