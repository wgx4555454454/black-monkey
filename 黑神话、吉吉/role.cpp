#include"Role.h"

int getInt();

void Role::showBag() {
	system("cls");
	cout << "Ѫ��ҩˮ��" << HpotionNum << endl;
	cout << "ħ��ҩˮ��" << MpotionNum << endl;
	cout << "ʣ���ң�" << Coins << endl;
	cout << "����ն�����飺";
	if (Matter_Flame_Slash == true)
		cout << "�ѻ��" << endl;
	else
		cout << "δ���" << endl;
	cout << "��˪���̼����飺";
	if (Matter_Frost_Piercing == true)
		cout << "�ѻ��" << endl;
	else
		cout << "δ���" << endl;
	cout << endl << endl;

	cout << "�Ƿ���Ҫʹ��ҩˮ��" << endl;
	
	int chooseWhether;
	int choosePotion = 0;
	do{
		cout << "1.ʹ��ҩˮ 2.�˳�" << endl;
		do {
			chooseWhether = getInt();
			if (chooseWhether != 1 && chooseWhether != 2)
				cout << "Error!������1-2" << endl;

		} while (chooseWhether != 1 && chooseWhether != 2);
		switch (chooseWhether) {
		case 1:
			cout << "��ѡ��1.Ѫ��ҩˮ  2.ħ��ҩˮ" << endl;
			
			do {
				choosePotion = getInt();
				if (choosePotion != 1 && choosePotion != 2)
					cout << "Error!������1-2" << endl;
			} while (choosePotion != 1 && choosePotion != 2);
			switch (choosePotion) {
			case 1:
				if (HpotionNum > 0) {
					cout << "ʹ�óɹ������Ѫ���ظ�������״̬100��" << endl;
					HpotionNum--;
					HP = 100;
				}
				else
					cout << "���Ѫ��ҩˮ������" << endl;
				break;
			case 2:
				if (MpotionNum > 0) {
					cout << "ʹ�óɹ������ħ���ظ���30��" << endl;
					MpotionNum--;
					MP += 30;
				}
				else
					cout << "���ħ��ҩˮ������" << endl;
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
