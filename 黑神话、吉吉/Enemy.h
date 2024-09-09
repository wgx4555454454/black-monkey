#pragma once
#include <iostream>
#include<vector>
#include <string>
#include <cstring>
#include <fstream>

//001

using namespace std;

class Enemy {
private:
	int hp;
	int atk;

	string name;
	vector<string> words;
public:
	Enemy():hp(0),atk(0),words(),name(){
	}//Ĭ�Ϲ��캯��

	Enemy(int Hp,int Atk,string Name,vector<string> Words) :hp(Hp),atk(Atk),name(Name),words(Words){
	}//���������캯��

	Enemy(const Enemy& other) : hp(other.hp), atk(other.atk),name(other.name), words(other.words) {
	}//�������캯��

    void setHP(int);

	void setAtk(int);

	vector<string> getWords();

	int getATK();

 	int getHP();

	void showWord(int);//���NPC̨�ʣ�1Ϊ����̨�ʣ�2Ϊ����ս��ʤ��NPC̨�ʣ�3Ϊ����ս��ʧ��NPC̨��

};

