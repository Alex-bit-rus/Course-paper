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
    char sex[40]; // 0 - man, 1 - human
    Exams exam;
    
public:
    Student();
    Student(const char*, const char*, const char*, const unsigned short, const unsigned short, const unsigned short,\
        const unsigned short, const char*, const char*, const char*, const char*, const char*);
    Student(const Student&);
    int addExam(const unsigned short, const char[], const unsigned short);
    bool operator== (const Student&);
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
    strcpy_s(this->sex, "s");
    
}



Student::Student(const char* firstname, const char* name, const char* patronymic, const unsigned short dayBirth, const unsigned short monthBirth\
    , const unsigned short yearBirth, const unsigned short yearStart, const char* faculty, const char* department, const char* group, const char* id, const char* sex) {
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
    strcpy_s(this->sex, sex);
    

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
    strcpy_s(this->sex, student.sex);
    this->exam = student.exam;
}



bool Student::operator==(const Student& student) {
    return (strcmp(this->id, student.id) == 0);
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
    strcpy_s(this->sex, student.sex);
    this->exam = student.exam;
    
    return (*this);
}


std::ostream& operator<<(std::ostream& out, const Student& student)
{
    out << student.firstname << " " << student.name \
        << " " << student.patronymic << " " << student.group;
    return out;
}

int Student::addExam(const unsigned short _numSess, const char _nameLesson[40], const unsigned short _mark) {
    return exam.addLesson(_numSess, _nameLesson, _mark);
}