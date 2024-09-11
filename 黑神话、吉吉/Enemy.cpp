#include "stdafx.h"
#include "Enemy.h"

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

void delayedPrintString(string temporary, int delay = 0);



void Enemy::showWord(int index) { // 输出NPC台词  
	if (index == 0) {
		cout << name << ":" << endl;
	}

	vector<string> strWord = getWords();

	if (index < 0 || index >= strWord.size()) {	//检验内容是否越界
		string strTemporary23 = "Invalid index!";
		delayedPrintString(strTemporary23, 20);
		cout << endl;
		return;
	}
	delayedPrintString(strWord[index], 6); //自定义输出函数
	cout << endl;
}