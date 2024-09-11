#pragma once
#include "stdafx.h"
#include "Menu.h"

using namespace std;
 
class Game  {
public:
	Map map;//游戏地图
	Enemy enemy[7];//7个NPC随机刷新
	Store store;//游戏商店
	Role character = Role(100, 35, 30, 0);

	void game();

	int attack();//攻击界面，涉及技能，攻击力之类的输出提示
				 //逃跑返回0，成功击败怪物返回1，被怪物打败返回2	
	int move(vector<string> map, vector<string> map_2);//游戏主要交互函数，包括地图，敌人

	void setEnemy();//设置boss参数

	void Buy();//购买页面

	void showBeginPlot();//游戏开始剧情
	void showFinalPlot();//游戏结束剧情
};