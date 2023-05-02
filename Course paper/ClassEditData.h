#pragma once
#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
 
using namespace std;

enum class editType : char { onlyDigit, onlyAlpha, alphaAndSpace ,all };


class ClassEditData
{
private:
	string label;
	string data;
public:
	ClassEditData() {
		label = "";
		data = "";
	}
	void setLabel(string _label = "Введите значение") {
		if (_label.length() > 1)
			this->label = _label;
		else
			label = "";
	}
	bool isDigit(char ch) {
		if (ch >= 48 and ch <= 57)
			return true;
		else
			return false;
	}
	bool isStringDigit(string _str) {
		for (int i = 0; i < _str.length(); i++)
			if (not isDigit(_str[i]))
				return false;
		if (_str.length() == 0)
			return false;
		return true;
	}
	bool isAlpha(int ch) {
		if (ch >= 65 and ch <= 90)
			return true;
		if (ch >= 97 and ch <= 122)
			return true;
		if (ch >= -200 and ch <= -1)
			return true;
		return false;
	}
	bool isSpace(char ch) {
		if (ch == 32)
			return true;
		else
			return false;
	}
	bool isSpec(char ch) {
		if (ch >= 33 and ch <= 47)
			return true;
		else
			return false;
	}
	
	bool isControl(char ch) {
		if ((ch <= 13 and ch >= 0) or ch == 31)
			return true;
		else
			return false;
	}
	void clear(string _data = "") {
		system("cls");
		data = _data;
	}

	string getData(enum class editType et) {
		char ch = 0;
		cout << label << endl << data;
		while (ch != 13) { //13 - код enter чтобы ввести значения
			ch = _getch();
			if (ch == 8) {  // Backspace удалить символ
				if (data.length() > 0) {
					data.pop_back();
					system("cls");
					cout << endl;
					cout << label << endl << data;
				}
				continue;
			}
			if (et == editType::onlyDigit)
				if (isDigit(ch)) {
					cout << ch;
					data = data + ch;
				}
			if (et == editType::onlyAlpha)
				if (isAlpha(ch)) {
					cout << ch;
					data = data + ch;
				}
			if (et == editType::alphaAndSpace)
				if (isAlpha(ch) or isSpace(ch)) {
					cout << ch;
					data = data + ch;
				}
			if (et == editType::all) {
				if (!isControl(ch)) {
					cout << ch;
					data = data + ch;
				}
			}
		}
		return data;
	}
	int getData(enum class editType et, int min, int max) {
		if (et == editType::onlyDigit) {
			getData(et);
			int num = max + 1;
			if (isStringDigit(data))
				num = atoi(data.c_str());
			if (not (num >= min and num <= max)) {
				cout << endl << "Ошибка: Число которое вы ввели: " << num << " Выходит из диапазона (" << min << "; " << max << ") ";
				getData(et, min, max);
			}
			if (isStringDigit(data))
				num = atoi(data.c_str());
			return num;
		}
	}
	string getData(enum class editType et, int len) {
		if (et == editType::onlyAlpha) {
			getData(et);
			if (data.length() > len) {
				cout << endl << "Ошибка: Длина строки больше чем допускается: " << data.length() << " Разрешено: " << len << " ";
				getData(et, len);
			}
			return data;
		}
		if (et == editType::alphaAndSpace) {
			getData(et);
			if (data.length() > len) {
				cout << endl << "Ошибка: Длина строки больше чем допускается: " << data.length() << " Разрешено: " << len << " ";
				getData(et, len);
			}
			return data;
		}
	}
};



