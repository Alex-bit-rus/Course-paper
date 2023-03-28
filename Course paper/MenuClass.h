#pragma once
#include <iostream>
#include <string>
#include "list.hpp"
using namespace std;
struct ListMenu {
	List <string> listOne;
	List <string> listOne_1;
	List <string> listOne_2;
	List <string> listSex;
	List <string> listSafeStudent;
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
	public:
	ListMenu listMenu;
	StructStudent menuStudent;
	MenuClass() {
		listMenu.listOne.addElem("�����");
		listMenu.listOne.addElem("��������� ������� 75");
		listMenu.listOne.addElem("��������� �� ��������� � ����");
		listMenu.listOne.addElem("�������� ��������");
		listMenu.listOne.addElem("������� ������ ��������� (�������� �������� � ��������)");

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
startWhile:	system("cls"); // ������� �����
			SetConsoleTextAttribute(h, 0x0007);
			cout << "����:" << endl;
			bool page2_is_first = true;
			bool page2011_is_first = true;
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
					cout << "�����";
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
					cout << "������� ������� ��������: ";
					cin.getline(menuStudent.firstname, 40);
					menuStudent.countFill++;
					page = 2;
					system("cls");
					goto startWhile;

				}
				if (page == 2002) {
					cout << "������� ��� ��������: ";
					cin.getline(menuStudent.name, 40);
					menuStudent.countFill++;
					page = 2;
					system("cls");
					goto startWhile;

				}
				if (page == 2003) {
					cout << "������� �������� ��������: ";
					cin.getline(menuStudent.patronymic, 40);
					menuStudent.countFill++;
					page = 2;
					system("cls");
					goto startWhile;

				}
				if (page == 2004) {
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
					page = 2;
					system("cls");
					goto startWhile;

				}
				if (page == 2005) {
					cout << "������� ��� ������ �������� ��������: ";
					cin >> menuStudent.yearStart;
					while (menuStudent.yearStart > 2022 or menuStudent.yearStart < 2020) {
						cout << "����� �� ��������� ��������! ��������� �������: ";
						cin >> menuStudent.yearStart;
					}
					menuStudent.countFill++;
					page = 2;
					system("cls");
					goto startWhile;

				}
				if (page == 2006) {
					cout << "������� ������ ��������: ";
					cin.getline(menuStudent.group, 40);
					menuStudent.countFill++;
					page = 2;
					system("cls");
					goto startWhile;

				}if (page == 2007) {
					cout << "������� ������� ��������: ";
					cin.getline(menuStudent.department, 40);
					menuStudent.countFill++;
					page = 2;
					system("cls");
					goto startWhile;

				}
				if (page == 2008) {
					cout << "������� �������� ��������: ";
					cin.getline(menuStudent.faculty, 40);
					menuStudent.countFill++;
					page = 2;
					system("cls");
					goto startWhile;

				}
				if (page == 2009) {
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
					page = 2;
					system("cls");
					goto startWhile;

				}
				 
					if (page == 2010) {
						len = 3;
						(choice == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						if (i + 1 < len) cout << listMenu.listSex[i] << endl;
						else {
							cout << "�����";
							break;
						}
					}
					if (page == 2010001 or page == 2010002) {
						if (page == 2010001) strcpy_s(menuStudent.sex, "�������");
						else strcpy_s(menuStudent.sex, "�������");
						menuStudent.countFill++;
						page = 2;
						system("cls");
						goto startWhile;
					}
				
				if (page == 2011) {
					len = 2;
					if (menuStudent.countFill == 13) {
						Student newStudent(menuStudent.firstname, menuStudent.name, menuStudent.patronymic, menuStudent.dayBirth, \
							menuStudent.monthBirth, menuStudent.yearBirth, menuStudent.yearStart, menuStudent.faculty, menuStudent.department, \
							menuStudent.group, menuStudent.id, menuStudent.sex);
						students.addElem(newStudent);
						fwrite(&newStudent, sizeof(Student), 1, file);
						page = 0;
						lenFile++;
						goto startWhile;
					}
					else {
						
						if (page2011_is_first)cout << "�� ����� �� ��� ������ � ��������, �� �������� ��� ������ �����, ������� �� ����� ������� � ���� ������\n";
						(choice == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						cout << listMenu.listSafeStudent[i] << endl;
						if (i + 1 == len) break;
						page2011_is_first = false;
					}
				}
				if (page > 2010 and page < 2001000 and page != 2011) goto startWhile;
			}



			}


			// ���� ������� �������
			key = _getch();

			// ������������ ������� �������
			switch (key) {
			case 72: // ������� �����
				choice--;
				if (choice < 1) choice = len;
				break;
			case 80: // ������� ����
				choice++;
				if (choice > len) choice = 1;
				break;
			case 13: // Enter
				system("cls");
				if (choice == len) {
					if (page == 0) return;
					else if (page == 2) {
						page = 2011;
					}
					else if (page == 2011) page = 0;
					else page = page / 1000;

				}
				else {
					if (page == 2011) page = page / 1000;
					else page = page * 1000 + choice;

				}
				choice = 1;

			}
		}


		fclose(file);

	}

};