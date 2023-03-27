#pragma once
#include <string.h>
struct Exam {
    char nameLesson[40];
    unsigned short mark;
    bool empty = true;
};

class Exams
{
private:
    
public:
    Exam lessons[9][10];
    int firstEmpty(const unsigned short);
    int addLesson(const unsigned short, const char[], const unsigned short);
    void writeExamsToFile(FILE*);
    void readExamsToFile(FILE*);
    Exams operator= (const Exams&);
    ~Exams();
};

int Exams::firstEmpty(const unsigned short _numSess) {
    for (int i = 0; i < 10; i++) {
        if (lessons[_numSess][i].empty)  return i;
    }
    return -1;
}


int Exams::addLesson(const unsigned short _numSess, const char _nameLesson[40], const unsigned short _mark) {
    int firstEmp = firstEmpty(_numSess);
    if (firstEmp > -1) {
        strcpy_s(this->lessons[_numSess][firstEmp].nameLesson, _nameLesson);
        this->lessons[_numSess][firstEmp].mark = _mark;
        this->lessons[_numSess][firstEmp].empty = false;
        return 0;
    }
    else return 1;
}

Exams::~Exams() {
    for (int i = 0; i < 9; i++) 
        for (int j = 0; j < 10; j++) {
            //if(!lessons[i][j].empty) delete[] this->lessons[i][j].nameLesson;
        }
}

void Exams::writeExamsToFile(FILE* file) {
    fwrite(lessons, sizeof(lessons), 1, file);
    /*for (int i = 0; i < 9; i++)
        for (int j = 0; j < 10; j++) {*/
            
}void Exams::readExamsToFile(FILE* file) {
    fread(lessons, sizeof(lessons), 1, file);
    /*for (int i = 0; i < 9; i++)
        for (int j = 0; j < 10; j++) {*/
            
}

Exams Exams::operator=(const Exams& exam) {
    for (int i = 0; i < 9; i++) 
        for (int j = 0; i < 10; i++) {
            if (!this->lessons[i][j].empty) {
                strcpy_s(this->lessons[i][j].nameLesson, exam.lessons[i][j].nameLesson);
                this->lessons[i][j].mark = exam.lessons[i][j].mark;
                this->lessons[i][j].empty = exam.lessons[i][j].empty;
            }
            
    }
    return(*this);
}