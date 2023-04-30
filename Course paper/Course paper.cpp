#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "list.hpp"
#include "Student.h"
#include "Exams.h"
#include "MenuClass.h"
#include <string>
#include <time.h>


using namespace std;

void crypt() {
	srand(time(NULL));
	char* pass = new char[64];
	for (int i = 0; i < 63; ++i) {
		switch (rand() % 3) {
		case 0:
			pass[i] = rand() % 10 + '0';
			break;
		case 1:
			pass[i] = rand() % 26 + 'A';
			break;
		case 2:
			pass[i] = rand() % 26 + 'a';
		}
	}

	pass[63] = '\0';


	string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in file.bin -out file.bin.enc -pass pass:";
	command += pass;
	system(command.c_str());

	if (remove("file.bin") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	ofstream file;
	file.open("key.txt", ios::binary);
	file.write(pass, 64);
	file.close();


	command = "openssl\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
	system(command.c_str());

	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}


}

void decrypt() {
	string command = "openssl\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";

	system(command.c_str());

	if (remove("key.txt.enc") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}

	char* pass = new char[64];

	ifstream file;
	file.open("key.txt", ios::binary);
	file.read(pass, 64);
	file.close();

	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}

	command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in file.bin.enc -out file.bin -pass pass:";
	
	command += pass;
	system(command.c_str());

	if (remove("file.bin.enc") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}




}




void WRITE(FILE* file) {
    fopen_s(&file, "file.bin", "w");
    Student Alex("Алекс", "Жик", "Миха1234567899 ", 127, 82, 2004, 2022, "IKB2", "KB-04", "БАСО-07-2022", "7527", 1);
    Student Boris("Борямба", "Русал", "Алексеич", 17, 8, 2004, 2002, "IKB", "KB-2", "БАСО-05-2002", "757", "M");
    Student Rusakov("Русаков", "Алексей", "Михайлович", 11, 11, 2011, 2002, "IKB3", "KB-2", "БИСО-01-2002", "7526", 1);
    Student Filatov("Филатов", "Валерий", "Вячеславович", 22, 12, 2011, 2002, "IKB4", "KB-2", "БИСО-02-2002", "7525", 1);
    Student Korol("Королев", "Владислав", "Денисович", 22, 12, 2022, 2005, "IKB", "KB-2", "БИСО-01-2005", "77", 1);
    Student Atavin("Атавин", "Даниил", "Антонович", 22, 12, 2002, 2022, "IKB", "KB-2", "БИСО-01-2022", "60", 1);
    Student Mers("Мерсов", "Андрей", "Александрович", 22, 12, 2002, 2022, "IKB4", "KB-2", "БИСО-02-2022", "1", 1);
    Student Kudj("Кудж", "Станислав ", "Алексеевич", 22, 12, 2002, 2002, "IKB4", "KB-2", "БИСО-02-2002", "701", 1);
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
    fwrite(&Korol, sizeof(Student), 1, file);
    fwrite(&Atavin, sizeof(Student), 1, file);
    fwrite(&Mers, sizeof(Student), 1, file);
    fwrite(&Kudj, sizeof(Student), 1, file);
    fclose(file);
}


int main()
{
    FILE* file = NULL;
	//WRITE(file);
	//crypt();
	decrypt();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	MenuClass menu;
	menu.draw(file);
	crypt();
}
