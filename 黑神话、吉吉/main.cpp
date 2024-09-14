#include "stdafx.h"
#include"Menu.h"

using namespace std;

//�����ı���ɫ
void setColor(int color) {
	// ��ȡ��ǰ����̨���  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// �����ı���ɫ
	SetConsoleTextAttribute(hConsole, color);
}

// ��ȡһ����Ч��������ȷ���ڸ����ķ�Χ��
int getInt(int minVal, int maxVal) {

	string input;
	int result;

	while (true) {
		getline(cin, input);

		// ����Ƿ�Ϊ������
		if (input.empty()) {
			continue;
		}
		// ʹ�� stringstream ���������벢����Ƿ�Ϊ����
		stringstream ss(input);
		if (!(ss >> result)) {
			cout << "������Ч����ȷ�������������:";
			continue;
		}
		// ����Ƿ��ж������Ч�ַ�
		char extraChar;
		if (ss >> extraChar) {
			cout << "��������Ƿ��ַ����������������";
			continue;
		}
		// ��鷶Χ
		if (result < minVal || result > maxVal) {
			cout << "������Χ�������� " << minVal << " �� " << maxVal << " ֮���������";
			continue;
		}
		// ����Ϸ������ؽ��
		return result;
	}
}


// �ӳ�������������»س������������������ʣ�������
void delayedPrintVector(const vector<string>& temporary, int delay = 0) {
	for (size_t i = 0; i < temporary.size(); ++i) {
		const string& line = temporary[i];
		for (char ch : line) {
			if (_kbhit()) {
				char c = _getch();
				// ���������ʱ�������ʣ������
				delay = 0;
			}
			cout << ch;  // �����ǰ�ַ�
			this_thread::sleep_for(chrono::milliseconds(delay));  // �ӳ�
		}
	}
}

// �ӳ�������������»س������������ʣ�������
void delayedPrintString(string temporary, int delay = 0) {
	const string& line = temporary;
	for (char ch : line) {
		if (_kbhit()) {
			char c = _getch();
			// ���������ʱ�������ʣ������
			delay = 0;
		}
		cout << ch;  // �����ǰ�ַ�
		this_thread::sleep_for(chrono::milliseconds(delay));	//�ӳ�
	}
}

void welcomePage()
{
	
	setColor(FOREGROUND_RED);

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
	"�t���������������������������������������������������������������������������������������������������������������������������������������������������������������������s\n",
	};

	for (int i = 0; i < strPage.size(); i++) {
		Sleep(36);
		cout << strPage[i] << endl;
	}

	// �����ı���ɫΪ��ɫ  
	setColor(FOREGROUND_GREEN);
	vector<string> strPage2 = {
	"�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[",
	"�U\t\t***�й������ѧ2024�ļ�ѧ��c++�γ����***\t\t�U",
	"�U �����񻰡�������\t\t\t\t\t\t\t�U",
	"�U ��Ϸ���ܣ�һ���򵥵�RPG����MUD��Ϸ��\t\t\t\t\t�U",
	"�U �汾��1.0\t\t\t\t\t\t\t\t�U",
	"�U ����: ������ Ԭ���� ���� �̴��� ����\t\t\t\t\t�U",
	"�U github��ַ: https://github.com/wgx4555454454/black-monkey.git\t\t�U",
	"�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a",
	};
	for (int i = 0; i < strPage2.size(); i++) {
		Sleep(0);
		cout << strPage2[i] << endl;
	}
}


void gameEndThankYou() {
	system("cls");
	setColor(10);  // ������ɫ
	cout << "��Ϸ�Ѿ���������������Ȼ�ڼ���..." << endl << endl;
	Sleep(36);  

	setColor(11);  // ������ɫ
	cout << "��л��һ·������֧������顣" << endl << endl;
	Sleep(36);  

	setColor(14);  // ���û�ɫ
	cout << "û�����Ĳ��룬���ǵ���Ϸ������˾��ʡ�" << endl << endl;
	Sleep(36);  

	setColor(12);  // ���ú�ɫ
	cout << "��л���Ļ���ʦ��Ϥ��ָ��" << endl << endl;
	Sleep(36);  

	setColor(11);  // ������ɫ
	cout << "ϣ����������δ�����ó����ٴ�������" << endl << endl;
	Sleep(25); 

	setColor(14);  // ���û�ɫ
	cout << "�ڴ������ٴι��٣��ټ���" << endl << endl;
	Sleep(3);

	setColor(7);   // �ָ�Ĭ����ɫ
	system("pause");
}

int main() {
	Menu _menu;
	_menu.menu();
	return 0;
}