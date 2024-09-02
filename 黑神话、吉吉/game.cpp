#include <iostream>
#include<iomanip>
#include <string>
#include <filesystem>
#include "Menu.h"

using namespace std;

void Game::game() {
	cout << "welcome to our game" << endl;
	cout << "this is a world about RPG" << endl;
	cout << "please enjoy your game :)" << endl;
	system("pause");//接下来开始进入地图并持续移动
	int ending = 0;
	while(passes<3){
		switch (passes) {
		case 0:cout << "The first adventure:" << endl;
			ending = move(map.map1);
			if (ending == 1)passes++;
			break;
		case 1:cout << "The second adventure:" << endl;
			move(map.map2);
			if (ending == 1)passes++;
			break;
		case 2:cout << "The third adventure:" << endl;
			move(map.map3);
			if (ending == 1)passes++;
			break;
		}
	}
	cout << "over";
}

