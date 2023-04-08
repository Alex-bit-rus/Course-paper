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
	bool page_befor_time_to_exam = false;
	bool page_before_add_exam = false;
	bool page_add_exam = false;
	bool page_before_edit_exam = false;
	bool page_edit_exam = false;
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

		listMenu.AddLast.addElem("�����");
		listMenu.AddLast.addElem("ADD");
		

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
		menuStudent.countFill++;
		CHOICE = page % 1000;
		system("cls");
		skipInput = true;
	}
	void setName() {
		cout << "������� ��� ��������: ";
		cin.getline(menuStudent.name, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		system("cls");
		skipInput = true;
	}
	void setPatronymic() {
		cout << "������� �������� ��������: ";
		cin.getline(menuStudent.patronymic, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
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
		system("cls");
		skipInput = true;
	}
	void setGroup() {
		cout << "������� ������ ��������: ";
		cin.getline(menuStudent.group, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		system("cls");
		skipInput = true;
	}
	void setDepartment() {
		cout << "������� ������� ��������: ";
		cin.getline(menuStudent.department, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
		system("cls");
		skipInput = true;
	}
	void setFaculty() {
		cout << "������� �������� ��������: ";
		cin.getline(menuStudent.faculty, 40);
		menuStudent.countFill++;
		CHOICE = page % 1000;
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
		CHOICE = page % 1000;
		system("cls");
		skipInput = true;

	}void setSex() {
		if (page % 10 == 1) menuStudent.sex = 0;
		else menuStudent.sex = 1;
		menuStudent.countFill++;
		CHOICE = 10;

		system("cls");
		skipInput = true;
		CHOICE = page % 1000;
	}
	void setExam(int _lessonNum = -1) {
		unsigned short numSessia = page % 10-1, mark;
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
				/*fseek(file, 0, SEEK_END);
				lenFile = ftell(file) / 4288;
				students.clear();
				for (int i = 0; i < lenFile; i++) {
					fseek(file, 4288 * (i), SEEK_SET);
					Student tempStudent;
					fread(&tempStudent, sizeof(Student), 1, file);
					students.addElem(tempStudent);
				}*/
				cout << "�� �������� � ���� 'file.bin' \n";
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
			if (page / 1000 >= 1002 and page / 1000 <= 1999 or (page == 1002010001 or page == 1002010002) or time_to_exam or page_add_exam or page_edit_exam) {

				if (page == 1002010001 or page == 1002010002) {
					setSex();
					students[(int)(page / 1000/1000 % 1000 - 2)].editSex(menuStudent.sex);
					page = page / 1000 / 1000;
				}
				else if (time_to_exam) {
					if (page1Exam_is_first)
						cout << "Bpvtybnm/lj,fdbnm:\n";
					page1Exam_is_first = false;
					students[page / 1000 / 1000 % 1000 - 2].copyExam(menuStudent.exam);
					len = menuStudent.exam.countLessons(page % 10 - 1)+2;
					if (i < len - 2) {
						int mark = menuStudent.exam.lessons[page % 1000 - 1][i].mark;
						(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						cout << menuStudent.exam.lessons[page % 1000 - 1][i].nameLesson << " Mark: ";
						if (mark == 1 or mark == 0) {
							if (mark == 1) cout << "Pachet\n";
							else cout << "Nepachet\n";
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
					students[(int)(page / 1000 / 1000 % 1000 - 2)].editExam(menuStudent.exam);
					time_to_exam = true;
					page_add_exam = false;
					skipInput = true;
					break;

				}
				else if (page_edit_exam) {
					setExam(choice-1);
					students[(int)(page / 1000 / 1000 % 1000 - 2)].editExam(menuStudent.exam);
					time_to_exam = true;
					page_add_exam = false;
					skipInput = true;
					break;

				}
				else if (page % 1000 == 1) {
					setFirstname();	
					students[(int)(page / 1000 % 1000 - 2)].editFirstname(menuStudent.firstname);
					page = page / 1000;
					break;
				}
				else if (page % 1000 == 2) {
					setName();
					students[(int)(page / 1000 % 1000 - 2)].editName(menuStudent.name);
					page = page / 1000;
					break;
				}
				else if (page % 1000 == 3) {
					setPatronymic();
					students[(int)(page / 1000 % 1000 - 2)].editPatronymic(menuStudent.patronymic);
					page = page / 1000;
					break;
				}
				else if (page % 1000 == 4) {
					setBirthday();
					students[(int)(page / 1000 % 1000 - 2)].editBirth(menuStudent.dayBirth, menuStudent.monthBirth, menuStudent.yearBirth);
					page = page / 1000;
					break;
				}
				else if (page % 1000 == 5) {
					setStartYear();
					students[(int)(page / 1000 % 1000 - 2)].editYearStart(menuStudent.yearStart);
					page = page / 1000;
					break;
				}
				else if (page % 1000 == 6) {
					setGroup();
					students[(int)(page / 1000 % 1000 - 2)].editGroup(menuStudent.group);
					page = page / 1000;
					break;
				}
				else if (page % 1000 == 7) {
					setDepartment();
					students[(int)(page / 1000 % 1000 - 2)].editDepartment(menuStudent.department);
					page = page / 1000;
					break;
				}
				else if (page % 1000 == 8) {
					setFaculty();
					students[(int)(page / 1000 % 1000 - 2)].editFaculty(menuStudent.faculty);
					page = page / 1000;
					break;
				}
				else if (page % 1000 == 9) {
					setID();
					students[(int)(page / 1000 % 1000 - 2)].editID(menuStudent.id);
					page = page / 1000;
					break;
				}
				else if (page % 1000 == 10) {
					len = 3;
					(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					if (i + 1 < len) cout << listMenu.listSex[i] << endl;
					else {
						cout << "�����";
						break;
					}

				}
				else if (page % 1000 == 11) {
					len = listMenu.listExams.getSize();
					(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					cout << listMenu.listExams[i] << endl;
					page_befor_time_to_exam = true;
					if (i + 1 == len) break;
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
				page = 1; CHOICE = 1; i = 0;
				skipInput = true;
				
			}
			if (page > 2000) {
				if (page == 2001) {
					setFirstname();
					page = 2;
				}
				if (page == 2002) {
					setName();
					page = 2;
				}
				if (page == 2003) {
					setPatronymic();
					page = 2;
				}
				if (page == 2004) {
					setBirthday();
					page = 2;
				}
				if (page == 2005) {
					setStartYear();
					page = 2;
				}
				if (page == 2006) {
					setGroup();
					page = 2;
				}
				if (page == 2007) {
					setDepartment();
					page = 2;
				}
				if (page == 2008) {
					setFaculty();
					page = 2;
				}
				if (page == 2009) {
					setID();
					page = 2;
				}
				if (page == 2010) {
					len = 3;
					(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					if (i + 1 < len) cout << listMenu.listSex[i] << endl;
					else {
						cout << "�����";
						break;
					}
				}
				if (page == 2010001 or page == 2010002) {
					setSex();
					page = 2;
					settingSex = true;
				}
				if (page == 2011) {
					len = listMenu.listExams.getSize();
					(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
					cout << listMenu.listExams[i] << endl;
					if (i + 1 == len) break;
						
				}
				if (page >= 2011001 and page < 2011009) {
					setExam();
					students[(int)(page / 1000 % 1000 - 2)].editExam(menuStudent.exam);
					page = 2011;
				}
				
				if (page == 2012) {
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
						page = 2012;
					}
					else if (page == 2012) {
						clearStudent();
						page = 0;
					}
					else if (time_to_exam) {
						time_to_exam = false;
						page = page / 1000;
					}
					else page = page / 1000;

				}
				else {
					if (page_befor_time_to_exam) {
						time_to_exam = true;
						page_befor_time_to_exam = false;
						page = page * 1000 + CHOICE;
					}
					else if (page == 2012) page = page / 1000;
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
					else page = page * 1000 + CHOICE;
					

				}
				choice = CHOICE;
				CHOICE = 1;
				firstEditSes = true;
				settingSex = false;
			}
		}


		fclose(file);

	}

};