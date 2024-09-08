#include<iostream>
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
	vector<string> word = getWords();
	if (index < 0 || index >= word.size()) {
		string temporary23 = "Invalid index!";
		for (int i = 0; i < temporary23.length(); i++) {
			Sleep(50);
			cout << temporary23[i];
		}
		cout << endl;
		return;
	}
	for (char c : word[index]) {
		Sleep(50);
		cout << c;
	}
	cout << endl;
	}