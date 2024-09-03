#include <iostream>
#include<iomanip>
#include <string>
#include <filesystem>
#include "Menu.h"
using namespace std;

void Store::showStore() {
	cout << "-------------------------" << endl;
	cout << "Store!!! Buy you want!" << endl;
	cout << "1.Hpotion          Price: 2" << endl;
	cout << "2.Mpotion          Price: 1" << endl;
	cout << "3.Flame Slash      Price: 4" << endl;
	cout << "4.Frost Piercing   Price: 3" << endl;
	cout << "-------------------------" << endl;
}

void Game::Buy()
{
	int Coins = character.getCoins();
	int Coins_New = Coins;
	int HpotionNum = character.getHpotionNum();
	int MpotionNum = character.getMpotionNum();
	bool Flame_Slash = character.get_Flame_Slash();
	bool Frost_Piercing = character.get_Frost_Piercing();
	int symbolBUY = 0;// symbol = 2Ê±ÍË³ö¹ºÂò
	int symbolTHING = 0;
	do {
		cout << "1.BUY  2.Exit" << endl;
		cin >> symbolBUY;
		if (symbolBUY == 1)
		{
			cout << "please input the number you want buy" << endl;
			cin >> symbolTHING;
			switch (symbolTHING)
			{
			case 1:
				if (Coins < store.Hpotion)
				{
					cout << "Sorry,your money is not enough" << endl;
					break;
				}
				else {
					cout << "Successful purchase!!!" << endl;
					Coins_New = Coins - store.Hpotion;
					HpotionNum = HpotionNum + 1;
				}
			case 2:
				if (Coins < store.Mpotion)
				{
					cout << "Sorry,your money is not enough" << endl;
					break;
				}
				else {
					cout << "Successful purchase!!!" << endl;
					Coins_New = Coins - store.Mpotion;
					MpotionNum = MpotionNum + 1;
				}
			case 3:
				if (Flame_Slash = true)
				{
					cout << "you matter the skill before" << endl;
					break;
				}
				if (Coins < store.skills.state[0])
				{
					cout << "Sorry,your money is not enough" << endl;
					break;
				}
				else {
					cout << "Successful purchase!!!" << endl;
					cout << "You successfully mastered " << store.skills.skill[0] << endl;
					Coins_New = Coins - store.skills.state[0];
				}
			case 4:
				if (Frost_Piercing = true)
				{
					cout << "you matter the skill before" << endl;
					break;
				}
				if (Coins < store.skills.state[1])
				{
					cout << "Sorry,your money is not enough" << endl;
					break;
				}
				else {
					cout << "Successful purchase!!!" << endl;
					cout << "You successfully mastered " << store.skills.skill[1] << endl;
				}
			}
		}
	} while (symbolBUY == 2);

}