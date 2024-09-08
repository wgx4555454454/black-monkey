#include <iostream>  
#include <iomanip>  
#include <string>  
#include <filesystem>  
#include <windows.h>  
#include <limits>  
#include"Menu.h"

using namespace std;

int getInt() {
	string x;
	while (true) {
		getline(cin, x); // ʹ�� getline ��ȡ��������  
		bool valid = true;

		// ��������Ƿ�Ϊ��Ч������  
		if (x.empty() || (x[0] != '-' && !isdigit(x[0]))) {
			valid = false;
		}
		else {
			for (size_t i = 1; i < x.length(); ++i) {
				if (!isdigit(x[i])) {
					valid = false;
					break;
				}
			}
		}

		if (valid) {
			return stoi(x); // string to int  
		}
		else {
			cout << "Invalid input. Please enter a valid integer." << '\n';
		}
	}
}

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

	cout << endl;
	string temporary49 = "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[";
	for (int i = 0; i < temporary49.length(); i++) {
		Sleep(5);
		cout << temporary49[i];
	}

	cout << endl;
	string temporary50 = "�U\t\t***�й������ѧ2024�ļ�ѧ��c++�γ����***\t\t�U";
	for (int i = 0; i < temporary50.length(); i++) {
		Sleep(25);
		cout << temporary50[i];
	}

	cout << endl;
	string temporary51 = "�U ���ְ桶���񻰡���ա�\t\t\t\t\t\t\t�U";
	for (int i = 0; i < temporary51.length(); i++) {
		Sleep(25);
		cout << temporary51[i];
	}

	cout << endl;
	string temporary52 = "�U ��Ϸ���ܣ�һ���򵥵�����RPG��\t\t\t\t\t\t�U";
	for (int i = 0; i < temporary52.length(); i++) {
		Sleep(25);
		cout << temporary52[i];
	}

	cout << endl;
	string temporary53 = "�U �汾��1.0\t\t\t\t\t\t\t\t�U";
	for (int i = 0; i < temporary53.length(); i++) {
		Sleep(25);
		cout << temporary53[i];
	}

	cout << endl;
	string temporary54 = "�U ����: \t\t\t\t\t\t\t\t�U";
	for (int i = 0; i < temporary54.length(); i++) {
		Sleep(25);
		cout << temporary54[i];
	}

	cout << endl;
	string temporary55 = "�U ����: \t\t\t\t\t\t\t\t�U";
	for (int i = 0; i < temporary55.length(); i++) {
		Sleep(25);
		cout << temporary55[i];
	}

	cout << endl;
	string temporary56 = "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a";
	for (int i = 0; i < temporary56.length(); i++) {
		Sleep(5);
		cout << temporary56[i];
	}

	cout << endl;

	// �ָ�Ĭ�ϵĿ���̨�ı���ɫ  
	//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

int main() {
	//welcomePage();//����ҳ��ͼ

	Menu _menu;
	_menu.menu();
	return 0;
}