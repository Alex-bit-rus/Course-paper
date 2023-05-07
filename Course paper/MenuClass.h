#pragma once
#include <iostream>
#include <string>
#include "list.hpp"
#include <time.h>
#include <windows.h>
#include "ClassEditData.h"
#include "EditStudent.h"
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


class MenuClass: public EditStudent {
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
	bool page2_is_first = true;
	bool page1Exam_is_first = true;
	bool page2012_is_first = true;
	unsigned long long page = 0;
	unsigned short maxCount = 0;
	unsigned short startYears[76];
	unsigned short yearMaxCount = 0;
	const unsigned short maxCountOfStudents = 1000;
	size_t len;
	size_t CHOICE = 1, choice;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	char key;
	ListMenu listMenu;
	public:
	
	MenuClass() {
		
		

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

	void maxCounterYear() {
		for (int i = 0; i < 76; i++) startYears[i] = 0;
		maxCount = 0;
		for (int i = 0; i < students.getSize(); i++) {
			startYears[students[i].getStartYear() - 1947]++;
			if (startYears[students[i].getStartYear() - 1947] > maxCount) {
				maxCount = startYears[students[i].getStartYear() - 1947];
				yearMaxCount = students[i].getStartYear();
			}
		}
	}

	void var75() {
		maxCounterYear();
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
			cout << "���";
			cout.fill(' ');
			cout.width(23);
			ios::left;
			cout << "������";
			cout.fill(' ');
			cout.width(31);
			cout << "����� �������� ������\n";
			for (int i = 0; i < lenMax; i++) {
				cout << GroupMax[i] << "\n";
			}
			cout << "\n��������, ����������� � ��� � ������ �����:\n";
			cout << "���";
			cout.fill(' ');
			cout.width(23);
			ios::left;
			cout << "������";
			cout.fill(' ');
			cout.width(31);
			cout << "����� �������� ������\n";
			for (int i = 0; i < lenOthers; i++)
			{
				cout << GroupOther[i] << "\n";
			}
			_key = _getch();
		}
		page = 0;
		skipInput = true;
	}



	void setID() {
		cout << "������� ����� �������� ������ ��������: ";
		cin.getline(menuStudent.id, 15);
		Student tempStudent(menuStudent.id);
		int find = students.findElem(tempStudent);
		while (find != -1) {
			cout << "������� � ����� ������� �������� ������ ��� ����! ��������� �������: ";
			cin.getline(menuStudent.id, 15);
			Student tempStudent(menuStudent.id);
			find = students.findElem(tempStudent);
		}
		menuStudent.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;

	}
	void setSex() {
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
		ClassEditData EditLesson;
		EditLesson.setLabel("������� �������� ����������: ");
		strcpy_s(nameLesson, EditLesson.getData(editType::alphaAndSpace, 40).c_str());

		ClassEditData EditMark;
		EditMark.setLabel("\n������� ������ �� ������� �� 2 �� 5 ��� 0 - �������, 1 - �����: ");
		mark = EditMark.getData(editType::onlyDigit, 0, 5);
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


	bool page_0(const unsigned int& _currentChoice) {
		
		len = listMenu.listOne.getSize();
		(CHOICE == _currentChoice + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
		cout << listMenu.listOne[_currentChoice] << endl;
		if (_currentChoice + 1 == len) return false;
		return true;
		
		
	}

	bool page_1(const unsigned int& _currentChoice) {
		len = students.getSize() + 2;
		Student tempStudent;
		(CHOICE == _currentChoice + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
		if (_currentChoice == 0) cout << "������� ��������" << endl;

		else if (_currentChoice + 1 <= len - 1) {
			cout << students[_currentChoice - 1] << endl;
		}
		else cout << "�����";
		if (_currentChoice + 1 == len) return false;
		return true;

	}
	bool page_2(const unsigned int& _currentChoice) {
		if (page2_is_first) {
			cout << "�������: " << menuStudent.firstname << " ���: " << menuStudent.name << " ��������: " << menuStudent.patronymic << endl;
			cout << "���� ��������: "; printDate(7);
			cout << " ��� ������ ��������: " << menuStudent.yearStart << " ���: " << (settingSex ? (menuStudent.sex == 0 ? "�������" : "�������") : "") << endl;
			cout << "����� �������� ������: " << menuStudent.id << " ������: " << menuStudent.group;
			cout << endl << " ��������: " << menuStudent.faculty << " �������: " << menuStudent.department << endl;
			page2_is_first = false;
		}
		len = listMenu.listOne_2.getSize();
		(CHOICE == _currentChoice + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
		cout << listMenu.listOne_2[_currentChoice] << endl;
		if (_currentChoice + 1 == len) return false;
		return true;

	}
	bool page_3(FILE* _file) {
		len = 1;
		writeToFile(_file);
		cout << "�� �������� � ���� 'file.bin' \n";
		system("PAUSE");
		page = 0;
		skipInput = true;
		return false;

	}
	void page_4() {
		var75();
	}
	bool page_printDeleteStudents(const unsigned int& _currentChoice) {
		len = students.getSize() + 1;
		(CHOICE == _currentChoice + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
		if (_currentChoice + 1 != len) {
			cout << students[_currentChoice] << endl;
			return true;
		}
		cout << "�����";
		return false;
		

	}
	bool page_printEditList(const unsigned int& _currentChoice) {
		len = listMenu.listOne_1000.getSize();
		(CHOICE == _currentChoice + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
		cout << listMenu.listOne_1000[_currentChoice] << endl;
		firstEditSes = true;
		if (_currentChoice + 1 == len) return false;
		return true;
		

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
			
		}
		
		
		while (true) {
			system("cls"); // ������� �����
			SetConsoleTextAttribute(h, 0x0007);
			cout << "����:" << endl;
			
			skipInput = false;
			
			for (int i = 0; i < 15; i++) {
				if (page == 0) {
					if(!page_0(i)) break;
				}
				if (page == 1) {
					if (!page_1(i)) break;
				}
				if (page == 2) {
					if (!page_2(i)) break;
				}
				if (page == 3) {
					if (!page_3(file)) break;
				}	
				if (page == 4) {
					page_4();
				}
				if (page == maxCountOfStudents+1) {
					if (!page_printDeleteStudents(i)) break;
				}
				if (page >= maxCountOfStudents+2 and page <= 2*maxCountOfStudents-1) {
					if(!page_printEditList(i)) break;
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
					EditStudent::setFirstname();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editFirstname(menuStudent.firstname);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 2) {
					EditStudent::setName();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editName(menuStudent.name);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 3) {
					EditStudent::setPatronymic();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editPatronymic(menuStudent.patronymic);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 4) {
					EditStudent::setBirthday();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editBirth(menuStudent.dayBirth, menuStudent.monthBirth, menuStudent.yearBirth);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 5) {
					EditStudent::setStartYear();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editYearStart(menuStudent.yearStart);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 6) {
					EditStudent::setGroup();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editGroup(menuStudent.group);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 7) {
					EditStudent::setDepartment();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editDepartment(menuStudent.department);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 8) {
					EditStudent::setFaculty();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].editFaculty(menuStudent.faculty);
					page = page / maxCountOfStudents;
					break;
				}
				else if (page % maxCountOfStudents == 9) {
					setID();
					skipInput = true;
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
				len = students.getSize();
				size_t index = (page - (maxCountOfStudents + 1)* maxCountOfStudents)-1 ;
				cout << students[index];
				students.removeElem(index);
				len--;
				system("cls");
				page = 1; CHOICE = 1; i = 0;
				skipInput = true;
				
			}
			if (page > 2*maxCountOfStudents) {
				if (page == 2 * maxCountOfStudents+1) {
					EditStudent::setFirstname();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+2) {
					EditStudent::setName();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+3) {
					EditStudent::setPatronymic();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+4) {
					EditStudent::setBirthday();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+5) {
					EditStudent::setStartYear();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+6) {
					EditStudent::setGroup();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+7) {
					EditStudent::setDepartment();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
					page = 2;
				}
				if (page == 2 * maxCountOfStudents+8) {
					EditStudent::setFaculty();
					CHOICE = page % maxCountOfStudents;
					system("cls");
					skipInput = true;
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
				if (page >= (2 * maxCountOfStudents+11)* maxCountOfStudents+1 and page < (2*maxCountOfStudents+11) * maxCountOfStudents + 9) {
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
			page1Exam_is_first = true;
			page2_is_first = true;
			page2012_is_first = true;
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
						fclose(file);
						SetConsoleTextAttribute(h, 0x0007);
						return;
					}
					else if (page == 2) {
						page = 2*maxCountOfStudents+12;
					}
					else if (page == 2* maxCountOfStudents+12) {
						EditStudent::clearStudent();
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


		

	}
	
	
};