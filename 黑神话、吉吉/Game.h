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
	int attack();//�������棬�漰���ܣ�������֮��������ʾ
				 //���ܷ���0���ɹ����ܹ��ﷵ��1���������ܷ���2	
	int move(vector<string> map, vector<string> map_2);
	void setEnemy();
	void Buy();
	void showBeginPlot();
	void showFinalPlot();
};