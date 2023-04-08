#pragma once
#include <string.h>
struct Exam {
    char nameLesson[40] = "";
    unsigned short mark;
    bool empty = true;
};

class Exams
{
private:
    
public:
    Exam lessons[9][10];
    int firstEmpty(const unsigned short);
    unsigned short countLessons(const unsigned short);
    int addLesson(const unsigned short, const char[], const unsigned short, const int);
    unsigned short getSizeSess(const unsigned short);
    void writeExamsToFile(FILE*);
    void readExamsToFile(FILE*);
    void clear();
    Exams operator= (const Exams&);
    ~Exams();
};


int Exams::firstEmpty(const unsigned short _numSess) {
    for (int i = 0; i < 10; i++) {
        if (lessons[_numSess][i].empty)  return i;
    }
    return -1;
}
unsigned short Exams::countLessons(const unsigned short _numSess) {
    unsigned short countLes = 0;
    for (int i = 0; i < 10; i++) {
        if (!lessons[_numSess][i].empty) countLes++;
    }
    return countLes;
}



int Exams::addLesson(const unsigned short _numSess, const char _nameLesson[40], const unsigned short _mark, const int _lessonNum) {
    if (_lessonNum == -1) {
        int firstEmp = firstEmpty(_numSess);
        if (firstEmp < 10) {
            if (firstEmp == -1) {
                return -1;
            }
            else {
                strcpy_s(this->lessons[_numSess][firstEmp].nameLesson, _nameLesson);
                this->lessons[_numSess][firstEmp].mark = _mark;
                this->lessons[_numSess][firstEmp].empty = false;
                return 0;
            }
        }


        else return 1;
    }
    else {
        strcpy_s(this->lessons[_numSess][_lessonNum].nameLesson, _nameLesson);
        this->lessons[_numSess][_lessonNum].mark = _mark;
        this->lessons[_numSess][_lessonNum].empty = false;
        return 0;



    }
}

Exams::~Exams() {
    
}
void Exams::clear()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 10; j++) {
            if (!lessons[i][j].empty) {
                strcpy_s(this->lessons[i][j].nameLesson,"");
                lessons[i][j].empty = true;
            }
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
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++) {
            if (!exam.lessons[i][j].empty) {
                strcpy_s(this->lessons[i][j].nameLesson, exam.lessons[i][j].nameLesson);
                this->lessons[i][j].mark = exam.lessons[i][j].mark;
                this->lessons[i][j].empty = exam.lessons[i][j].empty;
            }
        }
            
    }
    return(*this);
}