#include <iostream>
#include <windows.h>
#include <conio.h>
#include "list.hpp"
#include "Student.h"
#include "Exams.h"
#include "MenuClass.h"




using namespace std;


void menu() {
    
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c;
    int choice = 1; // начальный выбор
    char key; // переменная для хранения нажатой клавиши

    while (true) {
        // выводим меню
        system("cls"); // очищаем экран
        SetConsoleTextAttribute(h, 0x0007);
        cout << "Меню:" << endl;


        (choice == 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Вывыести список студентов (добавить сведения о студенте)" << endl;
        (choice == 2 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Добавить студента" << endl;
        (choice == 3 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Удалить студента" << endl;
        (choice == 4 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Выполнить вариант 75" << endl;


        // ждем нажатия клавиши
        key = _getch();

        // обрабатываем нажатие клавиши
        switch (key) {
        case 72: // стрелка вверх
            choice--;
            if (choice < 1) choice = 4;
            break;
        case 80: // стрелка вниз
            choice++;
            if (choice > 4) choice = 1;
            break;
        case 13: // Enter
            system("cls");
            switch (choice)
            {
            case 1: {
                break;
            }
            case 2: {
                while (true) {
                    int choice_2 = 1; char key_2;
                    (choice_2 == 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Вывыести список студентов (добавить сведения о студенте)" << endl;
                    (choice_2 == 2 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Добавить студента" << endl;
                    (choice_2 == 3 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Удалить студента" << endl;
                    (choice_2 == 4 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Выполнить вариант 75" << endl;
                    key_2 = _getch();

                    // обрабатываем нажатие клавиши
                    switch (key_2) {
                    case 72: // стрелка вверх
                        choice_2--;
                        if (choice_2 < 1) choice_2 = 4;
                        break;
                    case 80: // стрелка вниз
                        choice++;
                        if (choice_2 > 4) choice_2 = 1;
                        break;
                    case 13: // Enter
                        system("cls");
                        break;
                    }
                    system("cls");
                }
            }
                  break;
            }
        }

    }
    
}


int main()
{
    List<Student> name;
    pair<int,const char*> p1;
    p1 = make_pair(1, "e");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    MenuClass menuClass;
    //menuClass.findMaxLen(menuClass.listMenu.listOne);
    Student Alex;
    Student Boris("ddd", "22", "22", 17, 8, 2004, 2022, "IKB", "KB-2", "БАСО-05-20", "757", "M");
    cout << menuClass.findMaxLen(menuClass.listMenu.listOne);
    return 0;
}
