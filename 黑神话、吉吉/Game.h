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
	void attack();//�������棬�漰���ܣ�������֮��������ʾ
	int move(vector<string> map);
	void setEnemy();
};