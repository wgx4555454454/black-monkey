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
			// 按下任意键时立即输出剩余内容
			delay = 0;
		}
		cout << ch;  // 输出当前字符
		Sleep(delay);  // 延迟
	}
}



void Enemy::showWord(int index) { // 输出NPC台词  
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

	int pos = 0;  // 显式计数器，用于跟踪字符的索引

	delayedPrintString(strWord[index], 6);

	cout << endl;
}