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

class MenuClass
{
public:
	ListMenu listMenu;
	MenuClass() {
		listMenu.listOne.addElem("�������� ������ ��������� (�������� �������� � ��������)");
		listMenu.listOne.addElem("�������� ��������");
		listMenu.listOne.addElem("������� ��������");
		listMenu.listOne.addElem("��������� ������� 75");

		listMenu.listOne_2.addElem("������� �������");
		listMenu.listOne_2.addElem("������� ���");
		listMenu.listOne_2.addElem("������� ��������");
		listMenu.listOne_2.addElem("������� ���� ��������");
		listMenu.listOne_2.addElem("������� ��� �����������");
		listMenu.listOne_2.addElem("������� ������");
		listMenu.listOne_2.addElem("������� ��������");
		listMenu.listOne_2.addElem("������� ����� �������� ������");
		listMenu.listOne_2.addElem("������� ���");
		listMenu.listOne_2.addElem("�������� ���������� ������");



}
	
	

	size_t findMaxLen(List<string>& str) {
		size_t maxLen = 0;
		for (int i = 0; i < str.getSize(); i++) {
			if (maxLen < str[i].size()) maxLen = str[i].size();
		}
		return maxLen;
		
	}

	void drawTopLine(size_t lenTopLine) {
		for (int i = 0; i < lenTopLine; i++) cout << '_'; 
	}

	void draw(){
	while (true) {

	}
	}

	


};

