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
		Sleep(0);
		cout << temporary37[i];
	}
	cout << endl;

	string temporary38 = "�̵�";
	for (int i = 0; i < temporary38.length(); i++) {
		Sleep(0);
		cout << temporary38[i];
	}
	cout << endl;

    string temporary39 = "1.Ѫ��ҩˮ          �۸�: " + to_string(Hpotion);
	for (int i = 0; i < temporary39.length(); i++) {
		Sleep(0);
		cout << temporary39[i];
	}
	cout << endl;

    string temporary40 = "2.ħ��ҩˮ          �۸�: " + to_string(Mpotion);
	for (int i = 0; i < temporary40.length(); i++) {
		Sleep(0);
		cout << temporary40[i];
	}
	cout << endl;

    string temporary41 = "3.����ն          �۸�: " + to_string(skills.price[0]);
	for (int i = 0; i < temporary41.length(); i++) {
		Sleep(0);
		cout << temporary41[i];
	}
	cout << endl;

	string temporary42 = "4.��˪����        �۸�: " + to_string(skills.price[1]);
	for (int i = 0; i < temporary42.length(); i++) {
		Sleep(0);
		cout << temporary42[i];
	}
	cout << endl;
    
	string temporary43 = "-------------------------";
	for (int i = 0; i < temporary43.length(); i++) {
		Sleep(0);
		cout << temporary43[i];
	}
	cout << endl;
}

void Game::Buy() {
    int symbolBUY = 0;  // symbol = 2ʱ�˳�����
    int symbolTHING = 0;
    do {
        system("cls");
        cout << "ʣ���ң�" << character.getCoins() << endl;
        store.showStore();
        string temporary44 = "1.����  2.�˳�";
        for (int i = 0; i < temporary44.length(); i++) {
            Sleep(0);
            cout << temporary44[i];
        }
        cout << endl;
        do {
            symbolBUY = getInt();
            if (symbolBUY != 1 && symbolBUY != 2)
                cout << "Error!������1-2" << endl;
        } while (symbolBUY != 1 && symbolBUY != 2);

        if (symbolBUY == 1) {
            string temporary45 = "����������Ҫ��������";
            for (int i = 0; i < temporary45.length(); i++) {
                Sleep(0);
                cout << temporary45[i];
            }
            cout << endl;
            symbolTHING = getInt();

            switch (symbolTHING) {
            case 1:
                if (character.getCoins() < store.Hpotion) {
                    string temporary46 = "��Ľ�Ҳ�����";
                    for (int i = 0; i < temporary46.length(); i++) {
                        Sleep(0);
                        cout << temporary46[i];
                    }
                    cout << endl;
                    system("pause");
                }
                else {
                    string temporary47 = "����ɹ�!!!";
                    for (int i = 0; i < temporary47.length(); i++) {
                        Sleep(0);
                        cout << temporary47[i];
                    }
                    cout << endl;
                    character.setCoins(character.getCoins() - store.Hpotion);
                    character.setHpotionNum(character.getHpotionNum() + 1);
                    system("pause");
                }
                break;

            case 2:
                if (character.getCoins() < store.Mpotion) {
                    string temporary46 = "��Ľ�Ҳ�����";
                    for (int i = 0; i < temporary46.length(); i++) {
                        Sleep(0);
                        cout << temporary46[i];
                    }
                    cout << endl;
                    system("pause");
                }
                else {
                    string temporary47 = "����ɹ�";
                    for (int i = 0; i < temporary47.length(); i++) {
                        Sleep(0);
                        cout << temporary47[i];
                    }
                    cout << endl;
                    character.setCoins(character.getCoins() - store.Mpotion);
                    character.setMpotionNum(character.getMpotionNum() + 1);
                    system("pause");
                }
                break;

            case 3:
                if (character.get_Flame_Slash()) {
                    string temporary48 = "���Ѿ�����������ն";
                    for (int i = 0; i < temporary48.length(); i++) {
                        Sleep(0);
                        cout << temporary48[i];
                    }
                    cout << endl;
                    system("pause");
                }
                else if (character.getCoins() < store.skills.price[0]) {
                    string temporary46 = "��Ľ�Ҳ�����";
                    for (int i = 0; i < temporary46.length(); i++) {
                        Sleep(0);
                        cout << temporary46[i];
                    }
                    cout << endl;
                    system("pause");
                }
                else {
                    string temporary47 = "�ɹ�����!!!";
                    for (int i = 0; i < temporary47.length(); i++) {
                        Sleep(0);
                        cout << temporary47[i];
                    }
                    cout << endl;
                    cout << "��ɹ������� " << store.skills.skill[0] << endl;
                    character.setCoins(character.getCoins() - store.skills.price[0]);
                    character.set_Flame_Slash_true();
                    system("pause");
                }
                break;

            case 4:
                if (character.get_Frost_Piercing()) {
                    string temporary48 = "���Ѿ������˱�˪����";
                    for (int i = 0; i < temporary48.length(); i++) {
                        Sleep(0);
                        cout << temporary48[i];
                    }
                    cout << endl;
                    system("pause");
                }
                else if (character.getCoins() < store.skills.price[1]) {
                    string temporary46 = "��Ľ�Ҳ���";
                    for (int i = 0; i < temporary46.length(); i++) {
                        Sleep(0);
                        cout << temporary46[i];
                    }
                    cout << endl;
                    system("pause");
                }
                else {
                    string temporary47 = "�ɹ�����!!!";
                    for (int i = 0; i < temporary47.length(); i++) {
                        Sleep(0);
                        cout << temporary47[i];
                    }
                    cout << endl;
                    cout << "��ɹ�������" << store.skills.skill[1] << endl;
                    character.setCoins(character.getCoins() - store.skills.price[1]);
                    character.set_Frost_Piercing_true();
                    system("pause");
                }
                break;
            }
        }
    } while (symbolBUY == 1);
}
