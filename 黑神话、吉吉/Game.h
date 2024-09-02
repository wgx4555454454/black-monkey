#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include"Menu.h"

using namespace std;

class Game  {
public:
	Map map;
	Enemy _enemy[7];
	Store store;
	Role character = Role(100, 35, 100);
	int passes = 0;
	void game();
	void attack();//攻击界面，涉及技能，攻击力之类的输出提示
	int move(vector<string> map);
	void setMap();
};