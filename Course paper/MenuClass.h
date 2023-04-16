#pragma once
#include <iostream>
#include <string>
#include "list.hpp"
#include <time.h>
#include <windows.h>
using namespace std;
struct ListMenu {
	List <string> listOne;
	List <string> listOne_1;
	List <string> listOne_2;
	List <string> listOne_1000;
	List <string> listSex;
	List <string> listSafeStudent;
	List <string> listExams;
	List <string> AddLast;
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
	bool sex;
	Exams exam;
	int countFill = 0;
};

class MenuClass
{
private:
	List<Student> students;
	bool firstEditSes = true;
	bool skipInput = false;
	bool settingSex = false;
	bool time_to_exam = false;
	bool page_before_time_to_exam = false;
	bool page_before_add_exam = false;
	bool page_add_exam = false;
	bool page_before_edit_exam = false;
	bool page_edit_exam = false;
	unsigned long long page = 0;
	unsigned short maxCount = 0;
	unsigned short startYears[76];
	unsigned short yearMaxCount = 0;
	const unsigned short maxCountOfStudents = 1000;

	size_t len;
	size_t CHOICE = 1, choice = 1;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	char key;
	public:
	ListMenu listMenu;
	StructStudent menuStudent;
	MenuClass() {
		
		for (int i = 0; i < 76; i++) startYears[i] = 0;

		listMenu.listOne.addElem("�����");
		listMenu.listOne.addElem("��������� ������� 75");
		listMenu.listOne.addElem("��������� �� ��������� � ����");
		listMenu.listOne.addElem("�������� ��������");
		listMenu.listOne.addElem("������� ������ ��������� (�������� �������� � ��������)");

		listMenu.listOne_1000.addElem("�����");
		listMenu.listOne_1000.addElem("������� ��� ������ � ��������");
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

		listMenu.AddLast.addElem("�����");
		listMenu.AddLast.addElem("��������");
		

	}
	

	void var75() {
		List <Student> GroupMax;
		List <Student> GroupOther;
		unsigned short countStudents = students.getSize();
		for (int index = 0; index < students.getSize(); index++) {
			if (yearMaxCount == students[index].getStartYear()) {
				GroupMax.addElem(students[index]);
			}
			else GroupOther.addElem(students[index]);
		}
		
		GroupMax.quickSort(0, GroupMax.getSize()-1);
		GroupOther.quickSort(0, GroupOther.getSize()-1);
		
		unsigned short lenMax = GroupMax.getSize(), lenOthers = GroupOther.getSize();
		char _key = 0;
		while (_key != 13) {
			system("cls");
			cout << "��� ����������� ����� ������� Enter\n";
			cout << "\n��������, ����������� � ��� � " << yearMaxCount << " :\n";
			for (int i = 0; i < lenMax; i++) cout << GroupMax[i] << " " << GroupMax[i].getID() << "\n";
			cout << "\n��������, ����������� � ��� � ������ �����:\n";
			for (int i = 0; i < lenOthers; i++) cout << GroupOther[i] << " " << GroupOther[i].getID() << "\n";
			_key = _getch();
		}
		page = 0;
		skipInput = true;
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
		menuStudent.sex = 0;
		menuStudent.exam.clear();
		menuStudent.countFill = 0;
	}
	bool correctString(char _string []) {
		unsigned short _len = strlen(_string);
		for (unsigned short i = 0; i < _len; i++) {
			if ((unsigned int)_string[i] < 192) {
				return false;
			}
		}
		return true;
	}
	void printDate(const unsigned short& day, const unsigned short& month,const unsigned short& year, int wLine) {
		int w = 10;
		int delta = (wLine - w) / 2 - 1;
		cout.width(delta); cout << " ";
		if (day > 9) {
			cout << day;
		}
		else {
			cout << "0" << day;
		}
		cout << ".";
		if (month > 9) {
			cout << month;
		}
		else {
			cout << "0" << month;
		}
		cout << ".";
		cout << year;
		cout.width(delta); cout << " ";
	}



	void setFirstname() {
		cout << "������� ������� ��������: ";
		cin.getline(menuStudent.firstname, 40);
		while (!correctString(menuStudent.firstname)) {
			cout << "������� ������ �������� �� ������������� ��������! ��������� �������: ";
			cin.getline(menuStudent.firstname, 40);
		}
		menuStudent.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}
	void setName() {
		cout << "������� ��� ��������: ";
		cin.getline(menuStudent.name, 40);
		while (!correctString(menuStudent.name)) {
			cout << "��� �����o �������� �� ������������� ��������! ��������� �������: ";
			cin.getline(menuStudent.name, 40);
		}
		menuStudent.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}
	void setPatronymic() {
		cout << "������� �������� ��������: ";
		cin.getline(menuStudent.patronymic, 40);
		while (!correctString(menuStudent.patronymic)) {
			cout << "�������� �����o �������� �� ������������� ��������! ��������� �������: ";
			cin.getline(menuStudent.patronymic, 40);
		}
		menuStudent.countFill++;
		CHOICE = page % maxCountOfStudents;
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
		CHOICE = page % maxCountOfStudents;
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
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}
	void setGroup() {
		cout << "������� ������ ��������: ";
		cin.getline(menuStudent.group, 40);
		menuStudent.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}
	void setDepartment() {
		cout << "������� ������� ��������: ";
		cin.getline(menuStudent.department, 40);
		menuStudent.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}
	void setFaculty() {
		cout << "������� �������� ��������: ";
		cin.getline(menuStudent.faculty, 40);
		menuStudent.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}
	void setID() {
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
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;

	}void setSex() {
		if (page % 10 == 1) menuStudent.sex = 0;
		else menuStudent.sex = 1;
		menuStudent.countFill++;
		CHOICE = 10;

		system("cls");
		skipInput = true;
		CHOICE = page % maxCountOfStudents;
	}
	void setExam(int _lessonNum = -1) {
		unsigned short numSessia = page % 10-1, mark;
		char nameLesson[40] = "";
		cout << "������� �������� ����������: ";
		if (!firstEditSes) 
			cin.ignore();
		cin.getline(nameLesson, 40);
		cout << "\n������� ������ �� ������� �� 2 �� 5 ��� 0 - �������, 1 - �����: ";
		cin >> mark;
		while (mark < 0 or mark > 5) {
			cout << "����� �� ��������� ��������!��������� ������� : ";
			cin >> mark;
		}
		menuStudent.exam.addLesson(numSessia, nameLesson, mark, _lessonNum);
		firstEditSes = false;
		skipInput = true;

	}


	void writeToFile(FILE* _file) {
		fclose(_file);
		fopen_s(&_file, "file.bin", "w");
		for (int i = 0; i < students.getSize(); i++) {
			fwrite(&students[i], sizeof(Student), 1, _file);
		}
		fclose(_file);
		fopen_s(&_file, "file.bin", "a+");

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
		size_t lenFile = ftell(file) / sizeof(Student);
		for (int i = 0; i < lenFile; i++) {
			fseek(file, sizeof(Student) * (i), SEEK_SET);
			Student tempStudent;
			fread(&tempStudent, sizeof(Student), 1, file);
			students.addElem(tempStudent);
			startYears[tempStudent.getStartYear() - 1947]++;
			if (startYears[tempStudent.getStartYear() - 1947] > maxCount) {
				maxCount = startYears[tempStudent.getStartYear() - 1947];
				yearMaxCount = tempStudent.getStartYear();
			}
		}

		

	
		
		while (true) {
			system("cls"); // ������� �����
			SetConsoleTextAttribute(h, 0x0007);
			cout << "����:" << endl;
			bool page2_is_first = true;
			bool page1Exam_is_first = true;
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
				len = students.getSize() + 2;
				Student tempStudent;
				(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
				if (i == 0) cout << "������� ��������" << endl;

				else if (i + 1 <= len-1) {
					cout << students[i-1] << endl;
				}
				else cout << "�����";
				if (i + 1 == len) break;
			}
			if (page == 2) {
				if (page2_is_first) {
					cout << "�������: " << menuStudent.firstname << " ���: " << menuStudent.name << " ��������: " << menuStudent.patronymic << endl;
					cout << "���� ��������: "; printDate(menuStudent.dayBirth, menuStudent.monthBirth, menuStudent.yearBirth,7);
					cout << " ��� ������ ��������: " << menuStudent.yearStart << " ���: " << (settingSex?(menuStudent.sex == 0 ? "�������" : "�������"):"") << endl;
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
				writeToFile(file);
				cout << "�� �������� � ���� 'file.bin' \n";
				system("PAUSE");
				page = 0;
				skipInput = true;

			}
			if (page == 4) {
				var75();
				break;
			}
			if (page == maxCountOfStudents+1) {
				len = lenFile + 1;
				Student tempStudent;
				(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
				if (i + 1 != len) {
					fseek(file, sizeof(Student) * (i), SEEK_SET);
					fread(&tempStudent, sizeof(Student), 1, file);
					cout << tempStudent << endl;
				}
				else {
					cout << "�����";
					break;
				}
			}
			if (page >= maxCountOfStudents+2 and page <= 2*maxCountOfStudents-1) {
				len = listMenu.listOne_1000.getSize();
				(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
				cout << listMenu.listOne_1000[i] << endl;
				firstEditSes = true;
				if (i + 1 == len) 
					break;
			}
			if (page / maxCountOfStudents >= maxCountOfStudents+2 and page / maxCountOfStudents <= 2*maxCountOfStudents-1 or (page ==  ((maxCountOfStudents+2)* maxCountOfStudents+10)* maxCountOfStudents+1 or page == ((maxCountOfStudents + 2) * maxCountOfStudents + 10) * maxCountOfStudents + 2) or time_to_exam or page_add_exam or page_edit_exam) {

				if (page == ((maxCountOfStudents + 2) * maxCountOfStudents + 10) * maxCountOfStudents + 1 or page == ((maxCountOfStudents + 2) * maxCountOfStudents + 10) * maxCountOfStudents + 2) {
					setSex();
					students[(int)(page / maxCountOfStudents / maxCountOfStudents % maxCountOfStudents - 2)].editSex(menuStudent.sex);
					page = page / maxCountOfStudents / maxCountOfStudents;
				}
				else if (time_to_exam) {
					if (page1Exam_is_first)
						cout << "��������/�������� �������:\n";
					page1Exam_is_first = false;
					students[page / maxCountOfStudents / maxCountOfStudents % maxCountOfStudents - 2].copyExam(menuStudent.exam);
					len = menuStudent.exam.countLessons(page % 10 - 1)+2;
					if (i < len - 2) {
						int mark = menuStudent.exam.lessons[page % maxCountOfStudents - 1][i].mark;
						(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						cout << menuStudent.exam.lessons[page % maxCountOfStudents - 1][i].nameLesson << " ������: ";
						if (mark == 1 or mark == 0) {
							if (mark == 1) cout << "�����\n";
							else cout << "�������\n";
						}
						else cout << mark << "\n";

					}
					if (i + 1 == len - 1) {
						(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						cout << listMenu.AddLast[0] << "\n";
					}
					else if (i == len - 1) {
						(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						cout << listMenu.AddLast[1] << "\n";
					}
					page_before_add_exam = true;
					page_before_edit_exam = true;
					if (i  == len-1) {
						break;
					}

				}
				else if (page_add_exam) {
					setExam();
					students[(int)(page / maxCountOfStudents / maxCountOfStudents % maxCountOfStudents - 2)].editExam(menuStudent.exam);
					time_to_exam = true;
					page_add_exam = false;
					skipInput = true;
					break;

				}
				else if (page_edit_exam) {
					//firstEditSes = false;
					setExam(choice-1);
					students[(int)(page / maxCountOfStudents / maxCountOfStudents % maxCountOfStudents - 2)].editExam(menuStudent.exam);
					time_to_exam = true;
					page_add_exam = false;
					skipInput = true;
					break;

				}
				else if (page % 1000 == 1) {
					setFirstname();	
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editFirstname(menuStudent.firstname);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 2) {
					setName();
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editName(menuStudent.name);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 3) {
					setPatronymic();
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editPatronymic(menuStudent.patronymic);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 4) {
					setBirthday();
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editBirth(menuStudent.dayBirth, menuStudent.monthBirth, menuStudent.yearBirth);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 5) {
					setStartYear();
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editYearStart(menuStudent.yearStart);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 6) {
					setGroup();
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editGroup(menuStudent.group);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 7) {
					setDepartment();
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editDepartment(menuStudent.department);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 8) {
					setFaculty();
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editFaculty(menuStudent.faculty);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 9) {
					setID();
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editID(menuStudent.id);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 10) {
					len = 3;
					(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					if (i + 1 < len) cout << listMenu.listSex[i] << endl;
					else {
						cout << "�����";
						break;
					}

				}
				else if (page % maxCountOfStudents == 11) {
					len = listMenu.listExams.getSize();
					(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					cout << listMenu.listExams[i] << endl;
					page_before_time_to_exam = true;
					if (i + 1 == len) break;
				}
				else if (page % maxCountOfStudents == 12) {
					system("cls");
					char _key = 0;
					while (_key != 13) {
						cout << "��� ������ ������� Enter\n";
						students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].printAllData();
						_key = _getch();
						system("cls");

					}
					page = page / maxCountOfStudents;
					skipInput = true;
					break;

				}
				
			}
			if (page >= (maxCountOfStudents+1)* maxCountOfStudents+1 and page <= (maxCountOfStudents+1)* maxCountOfStudents+ maxCountOfStudents-1) {
				len = lenFile + 1;
				size_t index = lenFile - (page - maxCountOfStudents + 1) * maxCountOfStudents;
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
			if (page > 2*maxCountOfStudents) {
				if (page == 2 * maxCountOfStudents+1) {
					setFirstname();
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+2) {
					setName();
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+3) {
					setPatronymic();
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+4) {
					setBirthday();
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+5) {
					setStartYear();
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+6) {
					setGroup();
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+7) {
					setDepartment();
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+8) {
					setFaculty();
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+9) {
					setID();
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+10) {
					len = 3;
					(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					if (i + 1 < len) cout << listMenu.listSex[i] << endl;
					else {
						cout << "�����";
						break;
					}
				}
				if (page == (2 * maxCountOfStudents+10)* maxCountOfStudents+1 or page == (2 * maxCountOfStudents + 10) * maxCountOfStudents + 2) {
					setSex();
					page = 2;
					settingSex = true;
				}
				if (page == 2 * maxCountOfStudents+11) {
					len = listMenu.listExams.getSize();
					(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					cout << listMenu.listExams[i] << endl;
					if (i + 1 == len) break;
						
				}
				if (page >= 2 * maxCountOfStudents* maxCountOfStudents+1 and page < maxCountOfStudents * maxCountOfStudents + 9) {
					setExam();
					page = 2;
					
				}
				
				if (page == 2 * maxCountOfStudents+12) {
					len = 2;
					if (menuStudent.countFill >= 12) {
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
						page = 2*maxCountOfStudents+12;
					}
					else if (page == 2* maxCountOfStudents+12) {
						clearStudent();
						page = 0;
					}
					else if (time_to_exam) {
						time_to_exam = false;
						page_before_add_exam = false;
						page_before_edit_exam = false;
						page_edit_exam = false;
						page_before_time_to_exam = false;
						page = page / maxCountOfStudents;
					}
					else if (page % maxCountOfStudents == 11 and page_before_time_to_exam) {
						page_before_time_to_exam = false;
						page = page / maxCountOfStudents;
					}
					else page = page / maxCountOfStudents;

				}
				else {
				if (page_before_time_to_exam) {
						time_to_exam = true;
						page_before_time_to_exam = false;
						page = page * maxCountOfStudents + CHOICE;
					}
					else if (page == 2* maxCountOfStudents+12) page = page / maxCountOfStudents;
					else if (CHOICE == len - 1 and page_before_add_exam) {
						page_before_add_exam = false;
						time_to_exam = false;
						page_add_exam = true;
					}
					else if (page_before_edit_exam) {
						page_before_edit_exam = false;
						time_to_exam = false;
						page_edit_exam = true;
					}
					else page = page * maxCountOfStudents + CHOICE;
					

				}
				choice = CHOICE;
				CHOICE = 1;
				
				settingSex = false;
			}
		}


		fclose(file);

	}
	
};