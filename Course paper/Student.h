#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "Exams.h"




class Student {
private:
    char* firstname;
    char* name;
    char* patronymic;
    unsigned short dayBirds;
    unsigned short monthBirds;
    unsigned short yearBirds;
    unsigned short yearStart;
    char* faculty;
    char* department;
    char* group;
    char* id;
    char* sex; // 0 - man, 1 - human
    Exams exam;
    
public:
    Student();
    Student(const char*, const char*, const char*, const unsigned short, const unsigned short, const unsigned short,\
        const unsigned short, const char*, const char*, const char*, const char*, const char*);
    Student(const Student&);
    void writeToFile(FILE*);
    void readToFile(FILE*);
    void clear();
    bool operator== (const Student&);
    Student operator= (const Student&);
    friend std::ostream& operator<< (std::ostream& out, const Student& student);
    ~Student();
};


Student::Student() {
    this->firstname = new char[strlen("f") + 1];
    memcpy(this->firstname, "f", strlen("f") + 1);
    this->name = new char[strlen("n") + 1];
    memcpy(this->name, "n", strlen("n") + 1);
    this->patronymic = new char[strlen("p") + 1];
    memcpy(this->patronymic, "p", strlen("p") + 1);
    this->dayBirds = 0;
    this->monthBirds = 0;
    this->yearBirds = 0;
    this->yearStart = 0;
    this->faculty = new char[strlen("f") + 1];
    memcpy(this->faculty, "f", strlen("f") + 1);
    this->department = new char[strlen("d") + 1];
    memcpy(this->department, "d", strlen("d") + 1);
    this->group = new char[strlen("g") + 1];
    memcpy(this->group, "g", strlen("g") + 1);
    this->id = new char[strlen("i") + 1];
    memcpy(this->id, "i", strlen("i") + 1);
    this->sex = new char[strlen("s") + 1];
    memcpy(this->sex, "s", strlen("s") + 1);
    
}



Student::Student(const char* firstname, const char* name, const char* patronymic, const unsigned short dayBirds, const unsigned short monthBirds\
    , const unsigned short yearBirds, const unsigned short yearStart, const char* faculty, const char* department, const char* group, const char* id, const char* sex) {
    this->firstname = new char[strlen(firstname) + 1];
    memcpy(this->firstname, firstname, strlen(firstname) + 1);
    this->name = new char[strlen(name) + 1];
    memcpy(this->name, name, strlen(name) + 1);
    this->patronymic = new char[strlen(patronymic) + 1];
    memcpy(this->patronymic, patronymic, strlen(patronymic) + 1);
    this->dayBirds = dayBirds;
    this->monthBirds = monthBirds;
    this->yearBirds = yearBirds;
    this->yearStart = yearStart;
    this->faculty = new char[strlen(faculty) + 1];
    memcpy(this->faculty, faculty, strlen(faculty) + 1);
    this->department = new char[strlen(department) + 1];
    memcpy(this->department, department, strlen(department) + 1);
    this->group = new char[strlen(group) + 1];
    memcpy(this->group, group, strlen(group) + 1);
    this->id = new char[strlen(id) + 1];
    memcpy(this->id, id, strlen(id) + 1);
    this->sex = new char[strlen(sex) + 1];
    memcpy(this->sex, sex, strlen(sex) + 1);
    

}

Student::Student(const Student& student) {
    this->firstname = new char[strlen(student.firstname) + 1];
    memcpy(this->firstname, student.firstname, strlen(student.firstname) + 1);
    this->name = new char[strlen(student.name) + 1];
    memcpy(this->name, student.name, strlen(student.name) + 1);
    this->patronymic = new char[strlen(student.patronymic) + 1];
    memcpy(this->patronymic, student.patronymic, strlen(student.patronymic) + 1);
    this->dayBirds = student.dayBirds;
    this->monthBirds = student.monthBirds;
    this->yearBirds = student.yearBirds;
    this->yearStart = student.yearStart;
    this->faculty = new char[strlen(student.faculty) + 1];
    memcpy(this->faculty, student.faculty, strlen(student.faculty) + 1);
    this->department = new char[strlen(student.department) + 1];
    memcpy(this->department, student.department, strlen(student.department) + 1);
    this->group = new char[strlen(student.group) + 1];
    memcpy(this->group, student.group, strlen(student.group) + 1);
    this->id = new char[strlen(student.id) + 1];
    memcpy(this->id, student.id, strlen(student.id) + 1);
    this->sex = new char[strlen(student.sex) + 1];
    memcpy(this->sex, student.sex, strlen(student.sex) + 1);
    
}


bool Student::operator==(const Student& student) {
    return (strcmp(this->id, student.id) == 0);
}

Student Student::operator=(const Student& student) {
    this->firstname = new char[strlen(student.firstname) + 1];
    memcpy(this->firstname, student.firstname, strlen(student.firstname) + 1);
    this->name = new char[strlen(student.name) + 1];
    memcpy(this->name, student.name, strlen(student.name) + 1);
    this->patronymic = new char[strlen(student.patronymic) + 1];
    memcpy(this->patronymic, student.patronymic, strlen(student.patronymic) + 1);
    this->dayBirds = student.dayBirds;
    this->monthBirds = student.monthBirds;
    this->yearBirds = student.yearBirds;
    this->yearStart = student.yearStart;
    this->faculty = new char[strlen(student.faculty) + 1];
    memcpy(this->faculty, student.faculty, strlen(student.faculty) + 1);
    this->department = new char[strlen(student.department) + 1];
    memcpy(this->department, student.department, strlen(student.department) + 1);
    this->group = new char[strlen(student.group) + 1];
    memcpy(this->group, student.group, strlen(student.group) + 1);
    this->id = new char[strlen(student.id) + 1];
    memcpy(this->id, student.id, strlen(student.id) + 1);
    this->sex = new char[strlen(student.sex) + 1];
    memcpy(this->sex, student.sex, strlen(student.sex) + 1);
    
    return (*this);
}



Student::~Student() {
        delete[] firstname;
        delete[] name;
        delete[] patronymic;
        delete[] faculty;
        delete[] department;
        delete[] group;
        delete[] id;
    


}

void Student::clear() {
    delete[] firstname;
    delete[] name;
    delete[] patronymic;
    delete[] faculty;
    delete[] department;
    delete[] group;
    delete[] id;

}





std::ostream& operator<<(std::ostream& out, const Student& student)
{
    out << student.firstname << " " << student.name \
        << " " << student.patronymic << " " << student.group;
    return out;
}

void Student::writeToFile(FILE* file) {
   /* size_t len = strlen(firstname);
    fwrite(&len, sizeof(size_t), 1, file);
    fwrite(this->firstname, sizeof(firstname), 1, file);
    len = strlen(name);
    fwrite(&len, sizeof(size_t), 1, file);
    fwrite(this->name, sizeof(name), 1, file);
    len = strlen(patronymic);
    fwrite(&len, sizeof(size_t), 1, file);
    fwrite(this->patronymic, sizeof(patronymic), 1, file);
    fwrite(&this->dayBirds, sizeof(unsigned short), 1, file);
    fwrite(&this->monthBirds, sizeof(unsigned short), 1, file);
    fwrite(&this->yearBirds, sizeof(unsigned short), 1, file);
    fwrite(&this->yearStart, sizeof(unsigned short), 1, file);
    len = strlen(faculty);
    fwrite(&len, sizeof(size_t), 1, file);
    fwrite(this->faculty, sizeof(faculty), 1, file);
    len = strlen(department);
    fwrite(&len, sizeof(size_t), 1, file);
    fwrite(this->department, sizeof(department), 1, file);
    len = strlen(group);
    fwrite(&len, sizeof(size_t), 1, file);
    fwrite(this->group, sizeof(group), 1, file);
    len = strlen(id);
    fwrite(&len, sizeof(size_t), 1, file);
    fwrite(this->id, sizeof(id), 1, file);
    len = strlen(sex);
    fwrite(&len, sizeof(size_t), 1, file);
    fwrite(this->sex, sizeof(sex), 1, file);
    exam.writeExamsToFile(file);*/
    fwrite((char*)this, sizeof(Student), 1, file);
    //clear();
    
}
void Student::readToFile(FILE* file) {
    fseek(file, 0, SEEK_SET);
    /*
    char* f;
    char* n;
    char* p;
    
    size_t len ;
    fread(&len, sizeof(size_t), 1, file);
    f = new char[len + 1];
    fread(f, sizeof(f), 1, file);
    fread(&len, sizeof(size_t), 1, file);
    n = new char[len + 1];
    fread(n, sizeof(n), 1, file);
    fread(&len, sizeof(size_t), 1, file);
   
    p = new char[len + 1];
  
    fread(p, sizeof(p), 1, file);
    fread(&this->dayBirds, sizeof(unsigned short), 1, file);
    fread(&this->monthBirds, sizeof(unsigned short), 1, file);
    fread(&this->yearBirds, sizeof(unsigned short), 1, file);
    fread(&this->yearStart, sizeof(unsigned short), 1, file);
    fread(&len, sizeof(size_t), 1, file);
    delete[]faculty;
    faculty = new char[len + 1];
    fread(this->faculty, sizeof(faculty), 1, file);
    fread(&len, sizeof(size_t), 1, file);
    delete[]department;
    department = new char[len + 1];
    fread(this->department, sizeof(department), 1, file);
    fread(&len, sizeof(size_t), 1, file);
    delete[]group;
    group = new char[len + 1];
    fread(this->group, sizeof(group), 1, file);
    fread(&len, sizeof(size_t), 1, file);
    delete[]id;
    id = new char[len + 1];
    fread(this->id, sizeof(id), 1, file);
    fread(&len, sizeof(size_t), 1, file);
    delete[]sex;
    sex = new char[len + 1];
    fread(this->sex, sizeof(sex), 1, file);
    exam.readExamsToFile(file);
    */
    fread((char*)this, sizeof(Student), 1, file);
}//выводить по строке и считывать аккуратно seek