#include <iostream>
#include <conio.h>
#include "Enemy.h"
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define byte win_byte_override
#include<windows.h>

int Enemy::getATK(){
	return this->atk;
}

int Enemy::getHP(){
	return this->hp;
}

void Enemy::setHP(int hpnew){
	this->hp = hpnew;
}

void Enemy::setAtk(int Atk) {
	atk = Atk;
}

vector<string> Enemy::getWords() {
	return words;
}

void delayedPrintString(string& temporary, int delay = 0) {
	const string& line = temporary;
	for (char ch : line) {
		if (_kbhit()) {
			char ch = _getch();
			// ���������ʱ�������ʣ������
			delay = 0;
		}
		cout << ch;  // �����ǰ�ַ�
		Sleep(delay);  // �ӳ�
	}
}



void Enemy::showWord(int index) { // ���NPC̨��  
	if (index == 0) {
		cout << name << ":" << endl;
	}

	vector<string> strWord = getWords();

	if (index < 0 || index >= strWord.size()) {
		string strTemporary23 = "Invalid index!";
		delayedPrintString(strTemporary23, 20);
		cout << endl;
		return;
	}

	int pos = 0;  // ��ʽ�����������ڸ����ַ�������

	delayedPrintString(strWord[index], 6);

	cout << endl;
}