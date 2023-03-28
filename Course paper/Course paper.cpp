#include <iostream>
#include <windows.h>
#include <conio.h>
#include "list.hpp"
#include "Student.h"
#include "Exams.h"
#include "MenuClass.h"

using namespace std;



//void menu() {
//    
//    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD c;
//    int CHOICE = 1; // начальный выбор
//    char key; // переменная для хранения нажатой клавиши
//
//    while (true) {
//        // выводим меню
//        system("cls"); // очищаем экран
//        SetConsoleTextAttribute(h, 0x0007);
//        cout << "Меню:" << endl;
//
//
//        (CHOICE == 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Вывыести список студентов (добавить сведения о студенте)" << endl;
//        (CHOICE == 2 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Добавить студента" << endl;
//        (CHOICE == 3 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Удалить студента" << endl;
//        (CHOICE == 4 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Выполнить вариант 75" << endl;
//
//
//        // ждем нажатия клавиши
//        key = _getch();
//
//        // обрабатываем нажатие клавиши
//        switch (key) {
//        case 72: // стрелка вверх
//            CHOICE--;
//            if (CHOICE < 1) CHOICE = 4;
//            break;
//        case 80: // стрелка вниз
//            CHOICE++;
//            if (CHOICE > 4) CHOICE = 1;
//            break;
//        case 13: // Enter
//            system("cls");
//            switch (CHOICE)
//            {
//            case 1: {
//                break;
//            }
//            case 2: {
//                while (true) {
//                    int CHOICE_2 = 1; char key_2;
//                    (CHOICE_2 == 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Вывыести список студентов (добавить сведения о студенте)" << endl;
//                    (CHOICE_2 == 2 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Добавить студента" << endl;
//                    (CHOICE_2 == 3 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Удалить студента" << endl;
//                    (CHOICE_2 == 4 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Выполнить вариант 75" << endl;
//                    key_2 = _getch();
//
//                    // обрабатываем нажатие клавиши
//                    switch (key_2) {
//                    case 72: // стрелка вверх
//                        CHOICE_2--;
//                        if (CHOICE_2 < 1) CHOICE_2 = 4;
//                        break;
//                    case 80: // стрелка вниз
//                        CHOICE++;
//                        if (CHOICE_2 > 4) CHOICE_2 = 1;
//                        break;
//                    case 13: // Enter
//                        system("cls");
//                        break;
//                    }
//                    system("cls");
//                }
//            }
//                  break;
//            }
//        }
//
//    }
//    
//}

void WRITE(FILE* file) {
    fopen_s(&file, "file.bin", "a+");
    Student Alex("Алекс", "Жик", "Миха1234567899 ", 127, 82, 2004, 2022, "IKB2", "KB-22", "БАСО-07-20", "7527", "M");
    Student Boris("Борямба", "Русал", "Алексеич", 17, 8, 2004, 2022, "IKB", "KB-2", "БАСО-05-20", "757", "M");
    Student Rusakov("Русаков", "Алексей", "Михайлович", 11, 11, 1911, 2002, "IKB3", "KB-2", "БИСО-01-11", "7526", "M");
    Student Filatov("Филатов", "Валерий", "Вячеславович", 22, 12, 1922, 2002, "IKB4", "KB-2", "БИСО-02-11", "7525", "M");
    Student Dany;
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
