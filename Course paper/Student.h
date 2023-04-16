#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "Exams.h"





class Student {
private:
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
    bool sex = 0; 
    Exams exam;
    
public:
    Student();
    Student(char[]);
    Student(const char*, const char*, const char*, const unsigned short, const unsigned short, const unsigned short,\
        const unsigned short, const char*, const char*, const char*, const char*, const bool, Exams);
    Student(const char*, const char*, const char*, const unsigned short, const unsigned short, const unsigned short,\
        const unsigned short, const char*, const char*, const char*, const char*, const bool);
    Student(const Student&);
    int addExam(const unsigned short, const char[], const unsigned short, const int);
    void editFirstname(const char*);
    void editName(const char*);
    void editExam(const Exams&);
    void editPatronymic(const char*);
    void editFaculty(const char*);
    void editDepartment(const char*);
    void editGroup(const char*);
    void editID(const char*);
    void editSex(const bool);
    void editBirth(const unsigned short&, const unsigned short&, const unsigned short&);
    void editYearStart(const unsigned short&);
    void copyExam(Exams&);
    void printDate();
    void printAllData();
    unsigned short getStartYear() { return yearStart; }
    char* getID() { return id; }
    bool operator== (const Student&);
    bool operator< (const Student&);
    Student operator= (const Student&);
    friend std::ostream& operator<< (std::ostream& out, const Student& student);
    ~Student();
};


Student::Student() {
    strcpy_s(this->firstname, "f");
    strcpy_s(this->name, "n");
    strcpy_s(this->patronymic, "p");
    this->dayBirth = 0;
    this->monthBirth = 0;
    this->yearBirth = 0;
    this->yearStart = 0;
    strcpy_s(this->faculty, "f");
    strcpy_s(this->department, "d");
    strcpy_s(this->group, "g");
    strcpy_s(this->id, "i");
    sex = 0;
    
}
Student::Student(char id[40]) {
    strcpy_s(this->firstname, "f");
    strcpy_s(this->name, "n");
    strcpy_s(this->patronymic, "p");
    this->dayBirth = 0;
    this->monthBirth = 0;
    this->yearBirth = 0;
    this->yearStart = 0;
    strcpy_s(this->faculty, "f");
    strcpy_s(this->department, "d");
    strcpy_s(this->group, "g");
    strcpy_s(this->id, id);
    sex = 0;
}



Student::Student(const char* firstname, const char* name, const char* patronymic, const unsigned short dayBirth, const unsigned short monthBirth\
    , const unsigned short yearBirth, const unsigned short yearStart, const char* faculty, const char* department, const char* group, const char* id, const bool sex, Exams exam) {
    strcpy_s(this->firstname, firstname);
    strcpy_s(this->name, name);
    strcpy_s(this->patronymic, patronymic);
    this->dayBirth = dayBirth;
    this->monthBirth = monthBirth;
    this->yearBirth = yearBirth;
    this->yearStart = yearStart;
    strcpy_s(this->faculty, faculty);
    strcpy_s(this->department, department);
    strcpy_s(this->group, group);
    strcpy_s(this->id, id);
    this->sex = sex;
    this->exam = exam;
    

}

Student::Student(const char* firstname, const char* name, const char* patronymic, const unsigned short dayBirth, const unsigned short monthBirth\
    , const unsigned short yearBirth, const unsigned short yearStart, const char* faculty, const char* department, const char* group, const char* id, const bool sex) {
    strcpy_s(this->firstname, firstname);
    strcpy_s(this->name, name);
    strcpy_s(this->patronymic, patronymic);
    this->dayBirth = dayBirth;
    this->monthBirth = monthBirth;
    this->yearBirth = yearBirth;
    this->yearStart = yearStart;
    strcpy_s(this->faculty, faculty);
    strcpy_s(this->department, department);
    strcpy_s(this->group, group);
    strcpy_s(this->id, id);
    this->sex = sex;
    this->exam = exam;


}

Student::Student(const Student& student) {
    strcpy_s(this->firstname, student.firstname);
    strcpy_s(this->name, student.name);
    strcpy_s(this->patronymic, student.patronymic);
    this->dayBirth = student.dayBirth;
    this->monthBirth = student.monthBirth;
    this->yearBirth = student.yearBirth;
    this->yearStart = student.yearStart;
    strcpy_s(this->faculty, student.faculty);
    strcpy_s(this->department, student.department);
    strcpy_s(this->group, student.group);
    strcpy_s(this->id, student.id);
    this->sex = student.sex;
    this->exam = student.exam;
}



bool Student::operator==(const Student& student) {
    return (strcmp(this->id, student.id) == 0);
}

bool Student::operator<(const Student& student)
{
    if (strlen(this->id) < strlen(student.id)) return true;
    else if (strlen(this->id) > strlen(student.id)) return false;
    if (strcmp(this->id, student.id) < 0) 
        return true;
    return false;
}

Student Student::operator=(const Student& student) {
    strcpy_s(this->firstname, student.firstname);
    strcpy_s(this->name, student.name);
    strcpy_s(this->patronymic, student.patronymic);
    this->dayBirth = student.dayBirth;
    this->monthBirth = student.monthBirth;
    this->yearBirth = student.yearBirth;
    this->yearStart = student.yearStart;
    strcpy_s(this->faculty, student.faculty);
    strcpy_s(this->department, student.department);
    strcpy_s(this->group, student.group);
    strcpy_s(this->id, student.id);
    this->sex = student.sex;
    this->exam = student.exam;
    
    return (*this);
}


std::ostream& operator<<(std::ostream& out, const Student& student)
{
    out << student.firstname << " " << student.name \
        << " " << student.patronymic << " " << student.group;
    return out;
}

int Student::addExam(const unsigned short _numSess, const char _nameLesson[40], const unsigned short _mark, const int _lessonNum = -1) {
    return exam.addLesson(_numSess, _nameLesson, _mark, _lessonNum);
}

Student::~Student() {

}


void Student::editFirstname(const char* _firstname) {strcpy_s(firstname, _firstname);}
void Student::editName(const char* _name) {strcpy_s(name, _name);}
void Student::editPatronymic(const char* _patronymic) {strcpy_s(patronymic, _patronymic);}
void Student::editGroup(const char* _group) {strcpy_s(group,10, _group);}
void Student::editFaculty(const char* _faculty) {strcpy_s(faculty, _faculty);}
void Student::editDepartment(const char* _department) {strcpy_s(department, _department);}
void Student::editID(const char* _id) {strcpy_s(id, _id);}
void Student::editSex(const bool _sex) {sex = _sex;}
void Student::editBirth(const unsigned short& _day, const unsigned short& _month, const unsigned short& _year) {
    dayBirth = _day;
    monthBirth = _month;
    yearBirth = _year;
}
void Student::editYearStart(const unsigned short& _year) {
    yearStart =_year;
}
void Student::editExam(const Exams& _exam) {
    exam = _exam;
}

void Student::copyExam(Exams& _exam) {
    _exam = exam;
}

void Student::printDate() {
    int wLine = 15;
    int w = 10;
    int delta = (wLine - w) / 2 - 1;
    std::cout.width(delta); std::cout << " ";
    if (this->dayBirth > 9) {
        std::cout << this->dayBirth;
    }
    else {
        std::cout << "0" << this->dayBirth;
    }
    std::cout << ".";
    if (this->monthBirth > 9) {
        std::cout << this->monthBirth;
    }
    else {
        std::cout << "0" << this->monthBirth;
    }
    std::cout << ".";
    std::cout << this->yearBirth;
    std::cout.width(delta); std::cout << " ";
}

void Student::printAllData() {
    std::cout << "Фамилия: " << this->firstname << "\n";
    std::cout << "Имя: " << this->name << "\n";
    std::cout << "Отчество: " << this->patronymic << "\n";
    std::cout << "Номер зачетной книжки: " << this->id << "\n";
    std::cout << "Дата раждения: "; printDate(); std::cout << "\n";
    std::cout << "Пол: " << (sex?"Мужской":"Женский") << "\n";
    std::cout << "Год поступления: " << this->yearStart << "\n";
    std::cout << "Группа: " << this->group << "\n";
    std::cout << "Кафедра: " << this->department << "\n";
    std::cout << "Институт: " << this->faculty << "\n";
    exam.print();

}



