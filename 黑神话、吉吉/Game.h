#pragma once
#include "stdafx.h"
#include "Menu.h"

using namespace std;
 
class Game  {
public:
	Map map;//��Ϸ��ͼ
	Enemy enemy[7];//7��NPC���ˢ��
	Store store;//��Ϸ�̵�
	Role character = Role(100, 35, 30, 0);

	void game();

	int attack();//�������棬�漰���ܣ�������֮��������ʾ
				 //���ܷ���0���ɹ����ܹ��ﷵ��1���������ܷ���2	
	int move(vector<string> map, vector<string> map_2);//��Ϸ��Ҫ����������������ͼ������

	void setEnemy();//����boss����

	void Buy();//����ҳ��

	void showBeginPlot();//��Ϸ��ʼ����
	void showFinalPlot();//��Ϸ��������
};