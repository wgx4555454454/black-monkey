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
	Role character = Role(100, 35, 30, 0);
	void game();
	int attack();//攻击界面，涉及技能，攻击力之类的输出提示
				 //逃跑返回0，成功击败怪物返回1，被怪物打败返回2	
	int move(vector<string> map, vector<string> map_2);
	void setEnemy();
	void Buy();
	void showBeginPlot();
	void showFinalPlot();
};