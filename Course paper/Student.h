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
    void writeToFile(FILE*);
    void readToFile(FILE*);
    void clear();
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
    
    return (*this);
}



Student::~Student() {
     
    


}

void Student::clear() {


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
    fwrite(&this->dayBirth, sizeof(unsigned short), 1, file);
    fwrite(&this->monthBirth, sizeof(unsigned short), 1, file);
    fwrite(&this->yearBirth, sizeof(unsigned short), 1, file);
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
    Student temp = Student();
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
    fread(&this->dayBirth, sizeof(unsigned short), 1, file);
    fread(&this->monthBirth, sizeof(unsigned short), 1, file);
    fread(&this->yearBirth, sizeof(unsigned short), 1, file);
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