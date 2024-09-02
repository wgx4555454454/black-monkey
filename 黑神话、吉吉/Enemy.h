#pragma once
#include <iostream>
#include<vector>
#include <string>
#include <cstring>
#include <fstream>

#include"role.h"

using namespace std;

class Enemy {
public:
    void setHP(int);
	void showword(int);
	int hp;
	int atk;
	int getATK();
 	int getHP();
	vector<string> words;
};

