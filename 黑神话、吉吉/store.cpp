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

void Store::Buy(Role& Role)
{
	int Coins = Role.getCoins();
	int HpotionNum = Role.getHpotionNum();
	int MpotionNum = Role.getMpotionNum();
	bool Flame_Slash = Role.get_Flame_Slash();
	bool Frost_Piercing = Role.get_Frost_Piercing();
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
				if (Coins < Hpotion)
				{
					cout << "Sorry,your money is not enough" << endl;
					break;
				}
				else {
					cout << "Successful purchase!!!" << endl;
					int Coins_New = Coins - Hpotion;
					Role.setCoins(Coins_New);
					HpotionNum = HpotionNum + 1;
					Role.setHpotionNum(HpotionNum);
				}
			case 2:
				if (Coins < Mpotion)
				{
					cout << "Sorry,your money is not enough" << endl;
					break;
				}
				else {
					cout << "Successful purchase!!!" << endl;
					int Coins_New = Coins - Mpotion;
					Role.setCoins(Coins_New);
					MpotionNum = MpotionNum + 1;
					Role.setMpotionNum(MpotionNum);
				}
			case 3:
				if (Flame_Slash = true)
				{
					cout << "you matter the skill before" << endl;
					break;
				}
				if (Coins < moneySkill_1)
				{
					cout << "Sorry,your money is not enough" << endl;
					break;
				}
				else {
					cout << "Successful purchase!!!" << endl;
					cout << "You successfully mastered " << skill_1 << endl;
					Role.set_Flame_Slash_true();
					int Coins_New = Coins - moneySkill_1;
					Role.setCoins(Coins_New);
				}
			case 4:
				if (Frost_Piercing = true)
				{
					cout << "you matter the skill before" << endl;
					break;
				}
				if (Coins < moneySkill_2)
				{
					cout << "Sorry,your money is not enough" << endl;
					break;
				}
				else {
					cout << "Successful purchase!!!" << endl;
					cout << "You successfully mastered " << skill_2 << endl;
					Role.set_Frost_Piercing_true();
					int Coins_New = Coins - moneySkill_2;
					Role.setCoins(Coins_New);
				}
			}
		}
	} while (symbolBUY == 2);

}