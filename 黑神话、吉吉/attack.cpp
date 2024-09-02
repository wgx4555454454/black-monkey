#include <iostream>
#include<iomanip>
#include <string>
#include <filesystem>
#include<windows.h>
#include "Menu.h"

using namespace std;

void Game::attack() {
	cout << "hello";
	srand(static_cast<unsigned int>(time(0)));
	// 生成0到6之间的随机整数  
	int bossID = rand() % 7;
	Enemy* enemy = &_enemy[bossID];
	while (character.getHP() > 0 && enemy->getHP() > 0)
	{
		int choose = 0;
		cout << "choose what you next to do" << endl;
		cout << "1.normal attack" << endl << "2.attack with skills" << endl << "3.escape" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			enemy->setHP(enemy->getHP() - character.getATK());
			cout << "u have made " << character.getATK() << " damage to monster" << endl;
			break;
		case 2:
			//空缺暂时
			break;
		case 3:
			cout << "escape successfully" << endl;
			return;
		default:
			cout << "error command" << endl;
			break;
		}
		if ((character.getHP() >= 0 && enemy->getHP() >= 0))
			break;
		cout << "monster made " << enemy->getATK() << " damage" << endl;
		character.setHP(character.getHP() - enemy->getATK());
	}
	if (character.getHP() > 0)
	{
		cout << "monster is killed" << endl;
	}
	else
	{
		cout << "u are killed" << endl;
	}
	system("pause");
};
