#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

class Role {
private://h
	int HP;//ealth points
	int MP;//mana points
	int ATK;//attack;
	int passes;//通过的关卡
	int Coins=100;//金钱
	int HpotionNum = 0;//血量药水
	int MpotionNum = 0;//能量药水

	bool Matter_Flame_Slash=false;//是否学习烈焰斩
	bool Matter_Frost_Piercing=false;//是否学习冰霜穿刺
public:
	Role() : HP(0), MP(0), ATK(0), passes(0){};
	~Role() {};
	Role(int hp, int mp, int atk, int passes_s) {
		HP = hp;
		MP = mp;
		ATK = atk;
		passes = passes_s;
	}

	int getHP() {
		return HP;
	}
	void setHP(int hp) {
		HP = hp;
	}

	int getMP() {
		return MP;
	}
	void setMP(int mp) {
		MP = mp;
	}

	int getATK() {
		return ATK;
	}
	void setATK(int atk) {
		ATK = atk;
	}

	int getPasses(){
		return passes;
	}
	void setPasses(int passes_s){
		passes = passes_s;
	}

	int getCoins() {
		return Coins;
	}
	void setCoins(int coins) {
		Coins = coins;
	}

	int getHpotionNum() {
		return HpotionNum;
	}
	void setHpotionNum(int hpotionNum) {
		HpotionNum = hpotionNum;
	}

	int getMpotionNum() {
		return MpotionNum;
	}
	void setMpotionNum(int mpotionNum) {
		MpotionNum = mpotionNum;
	}

	bool get_Flame_Slash() {
		return Matter_Flame_Slash;
	}

	bool get_Frost_Piercing() {
		return Matter_Frost_Piercing;
	}

	void set_Flame_Slash_true()
	{
		Matter_Flame_Slash = true;
	}

	void set_Frost_Piercing_true()
	{
		Matter_Frost_Piercing = true;
	}
};
