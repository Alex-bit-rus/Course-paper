#include <iostream>
#include <windows.h>
#include <conio.h>
#include "list.hpp"
#include "Student.h"
#define use_CRT_SECURE_NO_WARNINGS 




using namespace std;


void menu() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c;
    int choice = 1; // начальный выбор
    char key; // переменная для хранения нажатой клавиши

    while (true) {
        // выводим меню
        system("cls"); // очищаем экран
        SetConsoleTextAttribute(h, 0x0007);
        cout << "Меню:" << endl;

        for (int i = 1; i < 7; i++) {
            (choice == i ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Пункт " <<i << endl;
        }
    /*    (choice == 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Пункт 1" << endl;
        (choice == 2 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Пункт 2" << endl;
        (choice == 3 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Пункт 3" << endl;
        (choice == 4 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Пункт 4" << endl;
        (choice == 5 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Пункт 5" << endl;
        (choice == 6 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007)); cout << "Пункт 6" << endl;*/

        // ждем нажатия клавиши
        key = _getch();

        // обрабатываем нажатие клавиши
        switch (key) {
        case 72: // стрелка вверх
            choice--;
            if (choice < 1) choice = 6;
            break;
        case 80: // стрелка вниз
            choice++;
            if (choice > 6) choice = 1;
            break;
        case 13: // Enter
            system("cls");
            cout << "Выбран пункт " << choice << endl;
            _getch();
            break;
        }
    }
    
    
    
}


int main()
{
    
   /* List<int> B;
    B.addElem(1);
    B.addElem(2);
    B.addElem(3);
    B.addElem(4);
    B.addElem(5);
    cout << B.findElem(89);*/
    List<Student> group;
    Student Boris("ddd", "22", "22", 17, 8, 2004, 2022, "IKB", "KB-2", "БАСО-05-20", "757", "M");
    group.addElem(Boris);
    return 0;
}
