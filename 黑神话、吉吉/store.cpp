#include <iostream>
#include<iomanip>
#include <string>
#include <filesystem>
#include<Windows.h>
#include "Menu.h"
using namespace std;
int getInt();

void Store::showStore() {
	string temporary37 = "-------------------------";
	for (int i = 0; i < temporary37.length(); i++) {
		Sleep(50);
		cout << temporary37[i];
	}
	cout << endl;

	string temporary38 = "Store!!! Buy you want!";
	for (int i = 0; i < temporary38.length(); i++) {
		Sleep(50);
		cout << temporary38[i];
	}
	cout << endl;

	string temporary39 = "1.Hpotion          Price: 2";
	for (int i = 0; i < temporary39.length(); i++) {
		Sleep(50);
		cout << temporary39[i];
	}
	cout << endl;

	string temporary40 = "2.Mpotion          Price: 1";
	for (int i = 0; i < temporary40.length(); i++) {
		Sleep(50);
		cout << temporary40[i];
	}
	cout << endl;

	string temporary41 = "3.Flame Slash      Price: 4";
	for (int i = 0; i < temporary41.length(); i++) {
		Sleep(50);
		cout << temporary41[i];
	}
	cout << endl;

	string temporary42 = "4.Frost Piercing   Price: 3";
	for (int i = 0; i < temporary42.length(); i++) {
		Sleep(50);
		cout << temporary42[i];
	}
	cout << endl;

	string temporary43 = "-------------------------";
	for (int i = 0; i < temporary43.length(); i++) {
		Sleep(50);
		cout << temporary43[i];
	}
	cout << endl;
}

void Game::Buy()
{
	int Coins = character.getCoins();
	int HpotionNum = character.getHpotionNum();
	int MpotionNum = character.getMpotionNum();
	bool Flame_Slash = character.get_Flame_Slash();
	bool Frost_Piercing = character.get_Frost_Piercing();
	int symbolBUY = 0;// symbol = 2Ê±ÍË³ö¹ºÂò
	int symbolTHING = 0;
	do {
		system("cls");
		store.showStore();
		string temporary44 = "1.BUY  2.Exit";
		for (int i = 0; i < temporary44.length(); i++) {
			Sleep(50);
			cout << temporary44[i];
		}
		cout << endl;
		symbolBUY=getInt();
		if (symbolBUY == 1)
		{
			string temporary45 = "please input the number you want buy";
			for (int i = 0; i < temporary45.length(); i++) {
				Sleep(50);
				cout << temporary45[i];
			}
			cout << endl;
			symbolTHING=getInt();
			switch (symbolTHING)
			{
			case 1:
				if (Coins < store.Hpotion)
				{
					string temporary46 = "Sorry,your money is not enough";
					for (int i = 0; i < temporary46.length(); i++) {
						Sleep(50);
						cout << temporary46[i];
					}
					cout << endl;
					system("pause");
					break;
				}
				else {
					string temporary47 = "Successful purchase!!!";
					for (int i = 0; i < temporary47.length(); i++) {
						Sleep(50);
						cout << temporary47[i];
					}
					cout << endl;
					Coins = Coins - store.Hpotion;
					HpotionNum = HpotionNum + 1;
					system("pause");
					break;
				}
			case 2:
				if (Coins < store.Mpotion)
				{
					string temporary46 = "Sorry,your money is not enough";
					for (int i = 0; i < temporary46.length(); i++) {
						Sleep(50);
						cout << temporary46[i];
					}
					cout << endl;
					system("pause");
					break;
				}
				else {
					string temporary47 = "Successful purchase!!!";
					for (int i = 0; i < temporary47.length(); i++) {
						Sleep(50);
						cout << temporary47[i];
					}
					cout << endl;
					Coins = Coins - store.Mpotion;
					MpotionNum = MpotionNum + 1;
					system("pause");
					break;
				}
			case 3:
				if (Flame_Slash = true)
				{
					string temporary48 = "you matter the skill before";
					for (int i = 0; i < temporary48.length(); i++) {
						Sleep(50);
						cout << temporary48[i];
					}
					cout << endl;
					system("pause");
					break;
				}
				if (Coins < store.skills.state[0])
				{
					string temporary46 = "Sorry,your money is not enough";
					for (int i = 0; i < temporary46.length(); i++) {
						Sleep(50);
						cout << temporary46[i];
					}
					cout << endl;
					system("pause");
					break;
				}
				else {
					string temporary47 = "Successful purchase!!!";
					for (int i = 0; i < temporary47.length(); i++) {
						Sleep(50);
						cout << temporary47[i];
					}
					cout << endl;
					cout << "You successfully mastered " << store.skills.skill[0] << endl;
					Coins= Coins - store.skills.state[0];
					Flame_Slash = true;
					character.set_Flame_Slash_true();
					system("pause");
					break;
				}
			case 4:
				if (Frost_Piercing = true)
				{
					string temporary48 = "you matter the skill before";
					for (int i = 0; i < temporary48.length(); i++) {
						Sleep(50);
						cout << temporary48[i];
					}
					cout << endl;
					system("pause");
					break;
				}
				if (Coins < store.skills.state[1])
				{
					string temporary46 = "Sorry,your money is not enough";
					for (int i = 0; i < temporary46.length(); i++) {
						Sleep(50);
						cout << temporary46[i];
					}
					cout << endl;
					system("pause");
					break;
				}
				else {
					string temporary47 = "Successful purchase!!!";
					for (int i = 0; i < temporary47.length(); i++) {
						Sleep(50);
						cout << temporary47[i];
					}
					cout << endl;
					cout << "You successfully mastered " << store.skills.skill[1] << endl;
					Coins = Coins - store.skills.state[1];
					Frost_Piercing = true;
					character.set_Frost_Piercing_true();
					system("pause");
					break;
				}
			}
		}
	} while (symbolBUY == 1);
	character.setCoins(Coins);
	character.setHpotionNum(HpotionNum);
	character.setMpotionNum(MpotionNum);
}