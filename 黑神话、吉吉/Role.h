#pragma once
#include "stdafx.h"

using namespace std;

class Role {
private://h
	int HP;//ealth points
	int MP;//mana points
	int ATK;//attack;
	int passes;//ͨ���Ĺؿ�

	int Coins=35;//��Ǯ
	int HpotionNum = 0;//Ѫ��ҩˮ
	int MpotionNum = 0;//����ҩˮ

	bool Matter_Flame_Slash=false;//�Ƿ�ѧϰ����ն
	bool Matter_Frost_Piercing=false;//�Ƿ�ѧϰ��˪����
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
