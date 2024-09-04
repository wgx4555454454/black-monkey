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



void Enemy::showWord(int index) { // Êä³öNPCÌ¨´Ê  
	vector<string> word = getWords();
	if (index < 0 || index >= word.size()) {
		cout << "Invalid index!" << endl;
		return;
	}
	for (char c : word[index]) {
		Sleep(50);
		cout << c;
	}
	cout << endl;
	}