#pragma once
#include <string.h>


class Exams
{
private:
    struct Exam {
        char* nameLesson;
        unsigned short mark;
        bool empty = true;
    };
public:
    Exam lessons[9][10];
    int firstEmpty(const unsigned short);
    int addLesson(const unsigned short, const char* ,const unsigned short);
};

int Exams::firstEmpty(const unsigned short _numSess) {
    for (size_t i = 0; i < 10; i++) {
        if (!lessons[_numSess][i].empty)  return i;
    }
    return -1;
}


int Exams::addLesson(const unsigned short _numSess, const char* _nameLesson,const unsigned short _mark) {
    int firstEmp = firstEmpty(_numSess);
    if (firstEmp > -1) {
        this->lessons[_numSess][firstEmp].nameLesson = new char[strlen(_nameLesson) + 1];
        memcpy(this->lessons[_numSess][firstEmp].nameLesson, _nameLesson, strlen(_nameLesson) + 1);
        this->lessons[_numSess][firstEmp].mark = _mark;
        this->lessons[_numSess][firstEmp].empty = false;
        return 0;
    }
    else return 1;
}

