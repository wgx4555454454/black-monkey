#include <iostream>
#include<iomanip>
#include <string>
#include <filesystem>
#include<windows.h>
#include "menu.h"

using namespace std;

void welcomePage()
{
	// ��ȡ��ǰ����̨���  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// �����ı���ɫΪ��ɫ  
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

	//����ҳ��ͼ
	vector<string> page = {
	"�q���������������������������������������������������������������������������������������������������������������������������������������������������������������������r",
	"��   HHHHHHHHHHHHHHHHHHH          S            SS                             HHHH  ��",//1
	"��   H HH     H     HH H           S           SS                        HHHHH      ��",//2
	"��   H  HH    H    HH  H       SSSSSSS         SS            HH      HHHH  HH       ��",//3
	"��   H   HH   H   HH   H            S          SS             HH           HH       ��",//4
	"��   HHHHHHHHHHHHHHHHHHH          S      SSSSSSSSSSSSSS        HH   HHHHHHHHHHHHHHH ��",//5
	"��            H                 S  S     SS    SS    SS   HHHHHHH          HH       ��",//6
	"��       HHHHHHHHHHH          S    S S   SSSSSSSSSSSSSS        HH          HH       ��",//7
	"��            H                    S  S  SS    SS    SS        HH     HHHHHHHHHHHH  ��",//8
	"��  HHHHHHHHHHHHHHHHHHHHH          S     SSSSSSSSSSSSSS        HH     HH        HH  ��",//9
	"��                                 S           SS              HH HH  HH        HH  ��",//10
	"��  HH   HH    HH      HH          S           SS              HHHH   HH        HH  ��",//11
	"��HH       HH    HH      HH        S           SS               HH    HHHHHHHHHHHH  ��",//12
	"��                                 S           SS                                   ��",//13
	"�t���������������������������������������������������������������������������������������������������������������������������������������������������������������������s",
	};

	for (int i = 0; i < page.size(); i++) {
		Sleep(36);
		cout << page[i] << endl;
	}

	// �����ı���ɫΪ��ɫɫ  
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	cout << endl << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[";
	cout << endl << "�U\t\t***�й������ѧ2024�ļ�ѧ��c++�γ����***\t\t�U";
	cout << endl << "�U ���ְ桶���񻰡���ա�\t\t\t\t\t\t\t�U";
	cout << endl << "�U ��Ϸ���ܣ�һ���򵥵�����RPG��\t\t\t\t\t\t�U";
	cout << endl << "�U �汾��1.0\t\t\t\t\t\t\t\t�U";
	cout << endl << "�U ����: \t\t\t\t\t\t\t\t�U";
	cout << endl << "�U ����: \t\t\t\t\t\t\t\t�U";
	cout << endl << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a";

	cout << endl;

	// �ָ�Ĭ�ϵĿ���̨�ı���ɫ  
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}
int main() {
	//welcomePage();//���Ʋ��ҳ��ͼ
	Menu _menu;
	_menu.menu();
	return 0;
}