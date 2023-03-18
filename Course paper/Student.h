#pragma once
struct Exams {
    char* nameLesson;
    unsigned short scoreExam;
};


class Studdent {
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
    bool sex; // 0 - man, 1 - human
    Exams exams[9][10];
public:



};
