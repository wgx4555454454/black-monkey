#include <iostream>
#include<iomanip>
#include <string>
#include <filesystem>
#include "Menu.h"

using namespace std;

void Game::setEnemy() {
	vector<string> words1 = {
	   "都记好喽，他不是只普通猴子，他是有功的猴子，是封过佛位的猴子，\n"
	   "这里只有我配与他一战，猴孙啊猴孙，我本不想与你一战，这样吧，\n"
	   "一会你若是败了，我带你回花果山，他们，留在这里铲平花果山，\n"
	   "若是我输了，我定然不会罢休，他们照样铲平花果山，生灵涂炭啊，\n"
	   "好歹也同僚一场，真不想打，要不你现在跪下认个错，这事就这样过去，如何？",
	   "可恶！我还会再回来的",
	   "滚回你的花果山吧!"
	};
	Enemy e1(150, 5, "杨戬", words1);
	_enemy[0] = e1;

	vector<string> words2 = {
		"来者何人，敢来此处扰我请修，嗯？又是只猴子，施主不如放下棍棒，跟我学下佛法，如何？",
		"天命人，这次你又赢了",
		"佛法无边，不度无缘"
	};
	Enemy e2(120, 6, "广智", words2);
	_enemy[1] = e2;

	vector<string> words3 = {
		"小僧法号广谋，"
		"若小夫身死你手，麻烦给我带句话给师傅."
		"肉眼凡夫，求而不得神仙骨."
		"半荣半枯，几人知是长生路",
		"hhh"

	};
}

void Game::game() {
	cout << "welcome to our game" << endl;
	cout << "this is a world about RPG" << endl;
	cout << "please enjoy your game :)" << endl;
	system("pause");//接下来开始进入地图并持续移动
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

