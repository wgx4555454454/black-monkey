#include <iostream>  
#include <iomanip>  
#include <string>  
#include <filesystem>  
#include <windows.h>  
#include <limits>  
#include <thread>     // �����ӳٹ���
#include <chrono>     // �����ӳ�ʱ��
#include"Menu.h"

using namespace std;

int getInt() {
	string strX;

	while (true) {
		getline(cin, strX); // ʹ�� getline ��ȡ��������  
		bool valid = true;

		// ��������Ƿ�Ϊ��Ч������  
		if (strX.empty()) {
			continue;
		}
		if (strX[0] != '-' && !isdigit(strX[0])) {
			valid = false;
		}
		else {
			for (size_t i = 1; i < strX.length(); ++i) {
				if (!isdigit(strX[i])) {
					valid = false;
					break;
				}
			}
		}
		if (valid) {
			return stoi(strX); // string to int  
		}
		cout << "�����ˣ����������룺";
	}
}

void welcomePage()
{
	// ��ȡ��ǰ����̨���  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// �����ı���ɫΪ��ɫ  
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

	//����ҳ��ͼ
	vector<string> strPage = {
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

	for (int i = 0; i < strPage.size(); i++) {
		Sleep(36);
		cout << strPage[i] << endl;
	}

	// �����ı���ɫΪ��ɫ  
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	cout << endl;
	string strTemporary49 = "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[";

	for (int i = 0; i < strTemporary49.length(); i++) {
		Sleep(0);
		cout << strTemporary49[i];
	}

	cout << endl;

	string strTemporary50 = "�U\t\t***�й������ѧ2024�ļ�ѧ��c++�γ����***\t\t�U";

	for (int i = 0; i < strTemporary50.length(); i++) {
		Sleep(0);
		cout << strTemporary50[i];
	}

	cout << endl;

	string strTemporary51 = "�U ���ְ桶���񻰡���ա�\t\t\t\t\t\t\t�U";

	for (int i = 0; i < strTemporary51.length(); i++) {
		Sleep(0);
		cout << strTemporary51[i];
	}

	cout << endl;

	string strTemporary52 = "�U ��Ϸ���ܣ�һ���򵥵�����RPG��\t\t\t\t\t\t�U";

	for (int i = 0; i < strTemporary52.length(); i++) {
		Sleep(0);
		cout << strTemporary52[i];
	}

	cout << endl;

	string strTemporary53 = "�U �汾��1.0\t\t\t\t\t\t\t\t�U";

	for (int i = 0; i < strTemporary53.length(); i++) {
		Sleep(0);
		cout << strTemporary53[i];
	}

	cout << endl;

	string strTemporary54 = "�U ����: ������ Ԭ���� ���� �̴��� ����\t\t\t\t\t�U";

	for (int i = 0; i < strTemporary54.length(); i++) {
		Sleep(0);
		cout << strTemporary54[i];
	}

	cout << endl;
	string strTemporary55 = "�U github��ַ: https://github.com/wgx4555454454/black-monkey.git\t\t�U";

	for (int i = 0; i < strTemporary55.length(); i++) {
		Sleep(0);
		cout << strTemporary55[i];
	}

	cout << endl;
	string strTemporary56 = "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a";
	for (int i = 0; i < strTemporary56.length(); i++) {
		Sleep(0);
		cout << strTemporary56[i];
	}

	cout << endl;

	// �ָ�Ĭ�ϵĿ���̨�ı���ɫ  
	//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}


void setColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void gameEndThankYou() {
	system("cls");
	setColor(10);  // ������ɫ
	cout << "��Ϸ�Ѿ���������������Ȼ�ڼ���..." << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(10));  

	setColor(11);  // ������ɫ
	cout << "��л��һ·������֧������顣" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(20));  

	setColor(14);  // ���û�ɫ
	cout << "û�����Ĳ��룬���ǵ���Ϸ������˾��ʡ�" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(20));  

	setColor(12);  // ���ú�ɫ
	cout << "��л���Ļ���ʦ��Ϥ��ָ��" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(15));  

	setColor(11);  // ������ɫ
	cout << "ϣ����������δ�����ó����ٴ�������" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(25)); 

	setColor(14);  // ���û�ɫ
	cout << "�ڴ������ٴι��٣��ټ���" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(3));

	setColor(7);   // �ָ�Ĭ����ɫ
	system("pause");
}

int main() {
	Menu _menu;
	_menu.menu();
	return 0;
}