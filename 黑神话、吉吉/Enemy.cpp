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



void Enemy::showWord(int index) { // ���NPC̨��  
	if (index == 0) {
		cout << name << ":" << endl;
	}

	vector<string> strWord = getWords();

	if (index < 0 || index >= strWord.size()) {
		string strTemporary23 = "Invalid index!";
		for (int i = 0; i < strTemporary23.length(); i++) {
			// �����⵽���̰���
			if (_kbhit()) {
				char key = _getch();  // ��ȡ���µļ�
				if (key == '\r') {  // �ж��Ƿ��»س���
					cout << strTemporary23.substr(i) << endl;  // ���ʣ�µ�ȫ������
					break;
				}
			}
			Sleep(20);
			cout << strTemporary23[i];
		}
		cout << endl;
		return;
	}

	int pos = 0;  // ��ʽ�����������ڸ����ַ�������

	for (int i = 0; i < strWord[index].length(); i++) {
		Sleep(6);
		cout << strWord[index][i];
	}

	cout << endl;
}