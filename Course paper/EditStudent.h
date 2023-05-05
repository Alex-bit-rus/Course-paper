#pragma once
#include "ClassEditData.h"
#include "string.h"
#include "list.hpp"
#include "Exams.h"

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


class EditStudent
{
protected:
	StructStudent menuStudent;
public:
	
	void printDate(int wLine) {
		int w = 10;
		int delta = (wLine - w) / 2 - 1;
		cout.width(delta); cout << " ";
		if (menuStudent.dayBirth > 9) {
			cout << menuStudent.dayBirth;
		}
		else {
			cout << "0" << menuStudent.dayBirth;
		}
		cout << ".";
		if (menuStudent.monthBirth > 9) {
			cout << menuStudent.monthBirth;
		}
		else {
			cout << "0" << menuStudent.monthBirth;
		}
		cout << ".";
		cout << menuStudent.yearBirth;
		cout.width(delta); cout << " ";
	}

	void clearStudent() {
		strcpy_s(menuStudent.firstname, "");
		strcpy_s(menuStudent.name, "");
		strcpy_s(menuStudent.patronymic, "");
		menuStudent.dayBirth = 0;
		menuStudent.monthBirth = 0;
		menuStudent.yearBirth = 0;
		menuStudent.yearStart = 0;
		strcpy_s(menuStudent.faculty, "");
		strcpy_s(menuStudent.department, "");
		strcpy_s(menuStudent.group, "");
		strcpy_s(menuStudent.id, "");
		menuStudent.sex = 0;
		menuStudent.exam.clear();
		menuStudent.countFill = 0;
	}
	void setFirstname() {
		ClassEditData EditFirstname;
		EditFirstname.setLabel("¬ведите фамилию студента: ");
		strcpy_s(menuStudent.firstname, EditFirstname.getData(editType::onlyAlpha, 40).c_str());
		EditFirstname.clear();
		menuStudent.countFill++;
	}
	void setName() {
		ClassEditData EditName;
		EditName.setLabel("¬ведите им€ студента: ");
		strcpy_s(menuStudent.name, EditName.getData(editType::onlyAlpha, 40).c_str());
		menuStudent.countFill++;
	}
	void setPatronymic() {
		ClassEditData EditPatronymic;
		EditPatronymic.setLabel("¬ведите отчечтво студента: ");
		strcpy_s(menuStudent.patronymic, EditPatronymic.getData(editType::onlyAlpha, 40).c_str());
		menuStudent.countFill++;
	}
	void setBirthday() {
		ClassEditData EditBirth;
		EditBirth.setLabel("¬ведите день рождени€ студента: ");
		menuStudent.dayBirth = EditBirth.getData(editType::onlyDigit, 1, 31);
		EditBirth.clear();
		EditBirth.setLabel("¬ведите мес€ц рождени€ студента: ");
		menuStudent.monthBirth = EditBirth.getData(editType::onlyDigit, 1, 12);
		EditBirth.clear();
		EditBirth.setLabel("¬ведите год рождени€ студента: ");
		menuStudent.yearBirth = EditBirth.getData(editType::onlyDigit, 1920, 2010);
		menuStudent.countFill += 3;
	}
	void setStartYear() {
		ClassEditData EditYearStart;
		EditYearStart.setLabel("¬ведите год начала обучени€ студента: ");
		menuStudent.yearStart = EditYearStart.getData(editType::onlyDigit, 1947, 2023);
		menuStudent.countFill++;
	}
	void setGroup() {
		ClassEditData EditGroup;
		EditGroup.setLabel("¬ведите группу студента: ");
		strcpy_s(menuStudent.group, EditGroup.getData(editType::all, 10).c_str());
		menuStudent.countFill++;
	}
	void setDepartment() {
		ClassEditData EditDepartment;
		EditDepartment.setLabel("¬ведите кафедру студента: ");
		strcpy_s(menuStudent.department, EditDepartment.getData(editType::all, 20).c_str());
		menuStudent.countFill++;
	}
	void setFaculty() {
		ClassEditData EditFaculty;
		EditFaculty.setLabel("¬ведите институт студента: ");
		strcpy_s(menuStudent.faculty, EditFaculty.getData(editType::onlyAlpha, 10).c_str());
		menuStudent.countFill++;
	}
	
};

