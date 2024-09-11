#pragma once
#include "stdafx.h"

using namespace std;

class Role {
private://h
	int HP;//ealth points
	int MP;//mana points
	int ATK;//attack;
	int passes;//通过的关卡

	int Coins=35;//金钱
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

	int getHP();

	void setHP(int hp);

	int getMP();

	void setMP(int mp);

	int getATK();

	void setATK(int atk);

	int getPasses();

	void setPasses(int passes_s);

	int getCoins();

	void setCoins(int coins);

	int getHpotionNum();

	void setHpotionNum(int hpotionNum);

	int getMpotionNum();

	void setMpotionNum(int mpotionNum);

	bool get_Flame_Slash();

	bool get_Frost_Piercing();

	void set_Flame_Slash_true();

	void set_Frost_Piercing_true();

	void showBag();
};
