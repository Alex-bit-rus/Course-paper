#pragma once
#include <iostream>
#include <string>
#include "list.hpp"
using namespace std;
struct ListMenu {
	List <string> listOne;
	List <string> listOne_1;
	List <string> listOne_2;
	List <string> listOne_3;
	List <string> listOne_4;
	};
//struct listOne_2 {
//	char str = { 
//		"������� �������", \
//		"������� ���", \
//		"������� ��������", \
//		"������� ���� ��������",\
//		"������� ��� �����������",\
//		"������� ������",\
//		"������� ��������",\
//		"������� ����� �������� ������",\
//		"������� ���"};
//	size_t sizeStr = 8;
//};

class MenuClass
{
public:
	ListMenu listMenu;
	char* item;
	MenuClass() {
		listMenu.listOne.addElem("�������� ������ ��������� (�������� �������� � ��������)");
		listMenu.listOne.addElem("�������� ��������");
		listMenu.listOne.addElem("������� ��������");
		listMenu.listOne.addElem("��������� ������� 75");

}
	

	void findMaxLen(string str[]) {
		cout << sizeof(str) << endl;
		for (int i = 0; i < 4; i++) cout << str[i].length() << "\n";
	}

	void drawTopLine(size_t lenTopLine) {
		for (int i = 0; i < lenTopLine; i++) cout << '_'; 
	}

	void draw(){
	while (true) {

	}
	}

	


};

