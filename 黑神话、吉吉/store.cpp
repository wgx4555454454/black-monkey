#include <iostream>
#include<iomanip>
#include <string>
#include <filesystem>
#include<Windows.h>
#include "Menu.h"
using namespace std;
int getInt();

void Store::showStore() {
	string strTemporary37 = "-------------------------";

	for (int i = 0; i < strTemporary37.length(); i++) {
		Sleep(0);
		cout << strTemporary37[i];
	}
	cout << endl;

	string strTemporary38 = "�̵�";

	for (int i = 0; i < strTemporary38.length(); i++) {
		Sleep(0);
		cout << strTemporary38[i];
	}
	cout << endl;

    string strTemporary39 = "1.Ѫ��ҩˮ          �۸�: " + to_string(Hpotion);

	for (int i = 0; i < strTemporary39.length(); i++) {
		Sleep(0);
		cout << strTemporary39[i];
	}
	cout << endl;

    string strTemporary40 = "2.ħ��ҩˮ          �۸�: " + to_string(Mpotion);

	for (int i = 0; i < strTemporary40.length(); i++) {
		Sleep(0);
		cout << strTemporary40[i];
	}
	cout << endl;

    string strTemporary41 = "3.����ն          �۸�: " + to_string(skills.price[0]);

	for (int i = 0; i < strTemporary41.length(); i++) {
		Sleep(0);
		cout << strTemporary41[i];
	}
	cout << endl;

	string strTemporary42 = "4.��˪����        �۸�: " + to_string(skills.price[1]);

	for (int i = 0; i < strTemporary42.length(); i++) {
		Sleep(0);
		cout << strTemporary42[i];
	}
	cout << endl;
    
	string strTemporary43 = "-------------------------";

	for (int i = 0; i < strTemporary43.length(); i++) {
		Sleep(0);
		cout << strTemporary43[i];
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

        string strTemporary44 = "1.����  2.�˳�";

        for (int i = 0; i < strTemporary44.length(); i++) {
            Sleep(0);
            cout << strTemporary44[i];
        }

        cout << endl;
        do {
            symbolBUY = getInt();
            if (symbolBUY != 1 && symbolBUY != 2)
                cout << "Error!������1-2" << endl;

        } while (symbolBUY != 1 && symbolBUY != 2);

        if (symbolBUY == 1) {
            string strTemporary45 = "����������Ҫ��������";

            for (int i = 0; i < strTemporary45.length(); i++) {
                Sleep(0);
                cout << strTemporary45[i];
            }

            cout << endl;

            symbolTHING = getInt();

            switch (symbolTHING) {
            case 1:
                if (character.getCoins() < store.Hpotion) {
                    string strTemporary46 = "��Ľ�Ҳ�����";

                    for (int i = 0; i < strTemporary46.length(); i++) {
                        Sleep(0);
                        cout << strTemporary46[i];
                    }
                    cout << endl;
                    system("pause");
                }
                else {
                    string strTemporary47 = "����ɹ�!!!";

                    for (int i = 0; i < strTemporary47.length(); i++) {
                        Sleep(0);
                        cout << strTemporary47[i];
                    }
                    cout << endl;
                    character.setCoins(character.getCoins() - store.Hpotion);
                    character.setHpotionNum(character.getHpotionNum() + 1);
                    system("pause");
                }
                break;

            case 2:
                if (character.getCoins() < store.Mpotion) {
                    string strTemporary46 = "��Ľ�Ҳ�����";

                    for (int i = 0; i < strTemporary46.length(); i++) {
                        Sleep(0);
                        cout << strTemporary46[i];
                    }
                    cout << endl;
                    system("pause");
                }
                else {
                    string strTemporary47 = "����ɹ�";

                    for (int i = 0; i < strTemporary47.length(); i++) {
                        Sleep(0);
                        cout << strTemporary47[i];
                    }

                    cout << endl;

                    character.setCoins(character.getCoins() - store.Mpotion);
                    character.setMpotionNum(character.getMpotionNum() + 1);
                    system("pause");
                }
                break;

            case 3:
                if (character.get_Flame_Slash()) {
                    string strTemporary48 = "���Ѿ�����������ն";

                    for (int i = 0; i < strTemporary48.length(); i++) {
                        Sleep(0);
                        cout << strTemporary48[i];
                    }

                    cout << endl;

                    system("pause");
                }
                else if (character.getCoins() < store.skills.price[0]) {
                    string strTemporary46 = "��Ľ�Ҳ�����";

                    for (int i = 0; i < strTemporary46.length(); i++) {
                        Sleep(0);
                        cout << strTemporary46[i];
                    }

                    cout << endl;

                    system("pause");
                }
                else {
                    string strTemporary47 = "�ɹ�����!!!";

                    for (int i = 0; i < strTemporary47.length(); i++) {
                        Sleep(0);
                        cout << strTemporary47[i];
                    }
                    cout << endl;
                    cout << "��ɹ������� " << store.skills.strSkillname[0] << endl;

                    character.setCoins(character.getCoins() - store.skills.price[0]);
                    character.set_Flame_Slash_true();

                    system("pause");

                }
                break;

            case 4:
                if (character.get_Frost_Piercing()) {
                    string strTemporary48 = "���Ѿ������˱�˪����";

                    for (int i = 0; i < strTemporary48.length(); i++) {
                        Sleep(0);
                        cout << strTemporary48[i];
                    }
                    cout << endl;

                    system("pause");
                }
                else if (character.getCoins() < store.skills.price[1]) {
                    string strTemporary46 = "��Ľ�Ҳ���";

                    for (int i = 0; i < strTemporary46.length(); i++) {
                        Sleep(0);
                        cout << strTemporary46[i];
                    }

                    cout << endl;

                    system("pause");
                }
                else {
                    string strTemporary47 = "�ɹ�����!!!";

                    for (int i = 0; i < strTemporary47.length(); i++) {
                        Sleep(0);
                        cout << strTemporary47[i];
                    }

                    cout << endl;

                    cout << "��ɹ�������" << store.skills.strSkillname[1] << endl;

                    character.setCoins(character.getCoins() - store.skills.price[1]);
                    character.set_Frost_Piercing_true();

                    system("pause");
                }
                break;
            }
        }
    } while (symbolBUY == 1);
}
