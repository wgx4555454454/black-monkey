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

void Enemy::showWord(int number)
{
	string word = words[number];
	for (int i = 0; i < words[number].size(); i++)
	{
		Sleep(50);
		cout << words[number][i];
	}

}