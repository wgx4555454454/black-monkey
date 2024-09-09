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



void Enemy::showWord(int index) { // 输出NPC台词  
	if (index == 0) {
		cout << name << ":" << endl;
	}
	vector<string> word = getWords();
	if (index < 0 || index >= word.size()) {
		string temporary23 = "Invalid index!";
		for (int i = 0; i < temporary23.length(); i++) {
			// 如果检测到键盘按下
			if (_kbhit()) {
				char key = _getch();  // 获取按下的键
				if (key == '\r') {  // 判断是否按下回车键
					cout << temporary23.substr(i) << endl;  // 输出剩下的全部内容
					break;
				}
			}
			Sleep(20);
			cout << temporary23[i];
		}
		cout << endl;
		return;
	}
	int pos = 0;  // 显式计数器，用于跟踪字符的索引
	for (int i = 0; i < word[index].length(); i++) {
		Sleep(6);
		cout << word[index][i];
	}
	cout << endl;
}