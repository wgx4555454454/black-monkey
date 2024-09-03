#include <iostream>
#include<iomanip>
#include <string>
#include <filesystem>
#include "Menu.h"

using namespace std;

void Game::setEnemy() {
	vector<string> words1 = {
	   "���Ǻ�ඣ�������ֻ��ͨ���ӣ������й��ĺ��ӣ��Ƿ����λ�ĺ��ӣ�\n"
	   "����ֻ����������һս�����ﰡ����ұ���������һս�������ɣ�\n"
	   "һ�������ǰ��ˣ��Ҵ���ػ���ɽ�����ǣ����������ƽ����ɽ��\n"
	   "���������ˣ��Ҷ�Ȼ������ݣ�����������ƽ����ɽ������Ϳ̿����\n"
	   "�ô�Ҳͬ��һ�����治���Ҫ�������ڹ����ϸ������¾�������ȥ����Σ�",
	   "�ɶ��һ����ٻ�����",
	   "������Ļ���ɽ��!"
	};
	Enemy e1(150, 5, "���", words1);
	_enemy[0] = e1;

	vector<string> words2 = {
		"���ߺ��ˣ������˴��������ޣ��ţ�����ֻ���ӣ�ʩ��������¹���������ѧ�·𷨣���Σ�",
		"�����ˣ��������Ӯ��",
		"���ޱߣ�������Ե"
	};
	Enemy e2(120, 6, "����", words2);
	_enemy[1] = e2;

	vector<string> words3 = {
		"Сɮ���Ź�ı��"
		"��С���������֣��鷳���Ҵ��仰��ʦ��."
		"���۷�������������ɹ�."
		"���ٰ�ݣ�����֪�ǳ���·",
		"hhh"

	};
}

void Game::game() {
	cout << "welcome to our game" << endl;
	cout << "this is a world about RPG" << endl;
	cout << "please enjoy your game :)" << endl;
	system("pause");//��������ʼ�����ͼ�������ƶ�
	int ending = 0;
	while(passes<3){
		switch (passes) {
		case 0:cout << "The first adventure:" << endl;
			ending = move(map.getMap1());
			if (ending == 1)passes++;
			break;
		case 1:cout << "The second adventure:" << endl;
			move(map.getMap2());
			if (ending == 1)passes++;
			break;
		case 2:cout << "The third adventure:" << endl;
			move(map.getMap3());
			if (ending == 1)passes++;
			break;
		}
	}
	cout << "over";
}

