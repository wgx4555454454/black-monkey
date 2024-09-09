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
	}//默认构造函数

	Enemy(int Hp,int Atk,string Name,vector<string> Words) :hp(Hp),atk(Atk),name(Name),words(Words){
	}//带参数构造函数

	Enemy(const Enemy& other) : hp(other.hp), atk(other.atk),name(other.name), words(other.words) {
	}//拷贝构造函数

    void setHP(int);

	void setAtk(int);

	vector<string> getWords();

	int getATK();

 	int getHP();

	void showWord(int);//输出NPC台词，1为启动台词，2为主角战斗胜利NPC台词，3为主角战斗失败NPC台词

};

