#include"Role.h"

int getInt();

void Role::showBag() {
	system("cls");
	cout << "血量药水：" << HpotionNum << endl;
	cout << "魔法药水：" << MpotionNum << endl;
	cout << "剩余金币：" << Coins << endl;
	cout << "烈焰斩技能书：";
	if (Matter_Flame_Slash == true)
		cout << "已获得" << endl;
	else
		cout << "未获得" << endl;
	cout << "冰霜穿刺技能书：";
	if (Matter_Frost_Piercing == true)
		cout << "已获得" << endl;
	else
		cout << "未获得" << endl;
	cout << endl << endl;

	cout << "是否需要使用药水？" << endl;
	
	int chooseWhether;
	int choosePotion = 0;
	do{
		cout << "1.使用药水 2.退出" << endl;
		do {
			chooseWhether = getInt();
			if (chooseWhether != 1 && chooseWhether != 2)
				cout << "Error!请输入1-2" << endl;

		} while (chooseWhether != 1 && chooseWhether != 2);
		switch (chooseWhether) {
		case 1:
			cout << "请选择：1.血量药水  2.魔法药水" << endl;
			
			do {
				choosePotion = getInt();
				if (choosePotion != 1 && choosePotion != 2)
					cout << "Error!请输入1-2" << endl;
			} while (choosePotion != 1 && choosePotion != 2);
			switch (choosePotion) {
			case 1:
				if (HpotionNum > 0) {
					cout << "使用成功！你的血量回复到了满状态100！" << endl;
					HpotionNum--;
					HP = 100;
				}
				else
					cout << "你的血量药水不够！" << endl;
				break;
			case 2:
				if (MpotionNum > 0) {
					cout << "使用成功！你的魔法回复了30！" << endl;
					MpotionNum--;
					MP += 30;
				}
				else
					cout << "你的魔法药水不够！" << endl;
				break;
			default:
				cout << "Error!" << endl;
				break;
			}
			break;
		case 2:
			return;
		}
	} while (chooseWhether != 2);
}


int Role::getHP() {
	return HP;
}
void Role::setHP(int hp) {
	HP = hp;
}

int Role::getMP() {
	return MP;
}
void Role::setMP(int mp) {
	MP = mp;
}

int Role::getATK() {
	return ATK;
}
void Role::setATK(int atk) {
	ATK = atk;
}

int Role::getPasses() {
	return passes;
}
void Role::setPasses(int passes_s) {
	passes = passes_s;
}

int Role::getCoins() {
	return Coins;
}
void Role::setCoins(int coins) {
	Coins = coins;
}

int Role::getHpotionNum() {
	return HpotionNum;
}
void Role::setHpotionNum(int hpotionNum) {
	HpotionNum = hpotionNum;
}

int Role::getMpotionNum() {
	return MpotionNum;
}
void Role::setMpotionNum(int mpotionNum) {
	MpotionNum = mpotionNum;
}

bool Role::get_Flame_Slash() {
	return Matter_Flame_Slash;
}

bool Role::get_Frost_Piercing() {
	return Matter_Frost_Piercing;
}

void Role::set_Flame_Slash_true(){
	Matter_Flame_Slash = true;
}

void Role::set_Frost_Piercing_true(){
	Matter_Frost_Piercing = true;
}
