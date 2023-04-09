﻿#include <iostream>
#include <windows.h>
#include <conio.h>
#include "list.hpp"
#include "Student.h"
#include "Exams.h"
#include "MenuClass.h"

using namespace std;





void WRITE(FILE* file) {
    fopen_s(&file, "file.bin", "a+");
    Student Alex("Алекс", "Жик", "Миха1234567899 ", 127, 82, 2004, 2022, "IKB2", "KB-22", "БАСО-07-20", "7527", "M");
    Student Boris("Борямба", "Русал", "Алексеич", 17, 8, 2004, 2022, "IKB", "KB-2", "БАСО-05-20", "757", "M");
    Student Rusakov("Русаков", "Алексей", "Михайлович", 11, 11, 1911, 2002, "IKB3", "KB-2", "БИСО-01-11", "7526", "M");
    Student Filatov("Филатов", "Валерий", "Вячеславович", 22, 12, 1922, 2002, "IKB4", "KB-2", "БИСО-02-11", "7525", "M");
    Alex.addExam(0, "Программирование", 5);
    Boris.addExam(0, "Программирование", 5);
    Rusakov.addExam(0, "Программирование", 5);
    Filatov.addExam(0, "Программирование", 4);
    Alex.addExam(0, "Психология", 4);
    Boris.addExam(0, "Психология", 3);
    Rusakov.addExam(0, "Психология", 4);
    Filatov.addExam(0, "Психология", 4);
    Alex.addExam(0, "Информатика", 5);
    Boris.addExam(0, "Информатика", 5);
    Rusakov.addExam(0, "Информатика", 1);
    Filatov.addExam(0, "Информатика", 3);
    Alex.addExam(1, "История", 5);
    Boris.addExam(1, "История", 3);
    Rusakov.addExam(1, "История", 4);
    Filatov.addExam(1, "История", 2);
    fwrite(&Alex, sizeof(Student), 1, file);
    fwrite(&Boris, sizeof(Student), 1, file);
    fwrite(&Rusakov, sizeof(Student), 1, file);
    fwrite(&Filatov, sizeof(Student), 1, file);
    fclose(file);
}


int main()
{
    FILE* file = NULL;
    //WRITE(file);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

   MenuClass menu;
   menu.draw(file);
}
