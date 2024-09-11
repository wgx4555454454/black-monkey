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



void Enemy::showWord(int index) { // ���NPC̨��  
	if (index == 0) {
		cout << name << ":" << endl;
	}

	vector<string> strWord = getWords();

	if (index < 0 || index >= strWord.size()) {	//���������Ƿ�Խ��
		string strTemporary23 = "Invalid index!";
		delayedPrintString(strTemporary23, 20);
		cout << endl;
		return;
	}
	delayedPrintString(strWord[index], 6); //�Զ����������
	cout << endl;
}