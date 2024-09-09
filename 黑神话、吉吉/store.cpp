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

	string strTemporary38 = "商店";

	for (int i = 0; i < strTemporary38.length(); i++) {
		Sleep(0);
		cout << strTemporary38[i];
	}
	cout << endl;

    string strTemporary39 = "1.血量药水          价格: " + to_string(Hpotion);

	for (int i = 0; i < strTemporary39.length(); i++) {
		Sleep(0);
		cout << strTemporary39[i];
	}
	cout << endl;

    string strTemporary40 = "2.魔法药水          价格: " + to_string(Mpotion);

	for (int i = 0; i < strTemporary40.length(); i++) {
		Sleep(0);
		cout << strTemporary40[i];
	}
	cout << endl;

    string strTemporary41 = "3.烈焰斩          价格: " + to_string(skills.price[0]);

	for (int i = 0; i < strTemporary41.length(); i++) {
		Sleep(0);
		cout << strTemporary41[i];
	}
	cout << endl;

	string strTemporary42 = "4.冰霜穿刺        价格: " + to_string(skills.price[1]);

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
    int symbolBUY = 0;  // symbol = 2时退出购买
    int symbolTHING = 0;

    do {
        system("cls");
        cout << "剩余金币：" << character.getCoins() << endl;

        store.showStore();

        string strTemporary44 = "1.购买  2.退出";

        for (int i = 0; i < strTemporary44.length(); i++) {
            Sleep(0);
            cout << strTemporary44[i];
        }

        cout << endl;
        do {
            symbolBUY = getInt();
            if (symbolBUY != 1 && symbolBUY != 2)
                cout << "Error!请输入1-2" << endl;

        } while (symbolBUY != 1 && symbolBUY != 2);

        if (symbolBUY == 1) {
            string strTemporary45 = "请输入你需要购买的序号";

            for (int i = 0; i < strTemporary45.length(); i++) {
                Sleep(0);
                cout << strTemporary45[i];
            }

            cout << endl;

            symbolTHING = getInt();

            switch (symbolTHING) {
            case 1:
                if (character.getCoins() < store.Hpotion) {
                    string strTemporary46 = "你的金币不够！";

                    for (int i = 0; i < strTemporary46.length(); i++) {
                        Sleep(0);
                        cout << strTemporary46[i];
                    }
                    cout << endl;
                    system("pause");
                }
                else {
                    string strTemporary47 = "购买成功!!!";

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
                    string strTemporary46 = "你的金币不够！";

                    for (int i = 0; i < strTemporary46.length(); i++) {
                        Sleep(0);
                        cout << strTemporary46[i];
                    }
                    cout << endl;
                    system("pause");
                }
                else {
                    string strTemporary47 = "购买成功";

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
                    string strTemporary48 = "你已经掌握了烈焰斩";

                    for (int i = 0; i < strTemporary48.length(); i++) {
                        Sleep(0);
                        cout << strTemporary48[i];
                    }

                    cout << endl;

                    system("pause");
                }
                else if (character.getCoins() < store.skills.price[0]) {
                    string strTemporary46 = "你的金币不够！";

                    for (int i = 0; i < strTemporary46.length(); i++) {
                        Sleep(0);
                        cout << strTemporary46[i];
                    }

                    cout << endl;

                    system("pause");
                }
                else {
                    string strTemporary47 = "成功购买!!!";

                    for (int i = 0; i < strTemporary47.length(); i++) {
                        Sleep(0);
                        cout << strTemporary47[i];
                    }
                    cout << endl;
                    cout << "你成功掌握了 " << store.skills.strSkillname[0] << endl;

                    character.setCoins(character.getCoins() - store.skills.price[0]);
                    character.set_Flame_Slash_true();

                    system("pause");

                }
                break;

            case 4:
                if (character.get_Frost_Piercing()) {
                    string strTemporary48 = "你已经掌握了冰霜穿刺";

                    for (int i = 0; i < strTemporary48.length(); i++) {
                        Sleep(0);
                        cout << strTemporary48[i];
                    }
                    cout << endl;

                    system("pause");
                }
                else if (character.getCoins() < store.skills.price[1]) {
                    string strTemporary46 = "你的金币不够";

                    for (int i = 0; i < strTemporary46.length(); i++) {
                        Sleep(0);
                        cout << strTemporary46[i];
                    }

                    cout << endl;

                    system("pause");
                }
                else {
                    string strTemporary47 = "成功购买!!!";

                    for (int i = 0; i < strTemporary47.length(); i++) {
                        Sleep(0);
                        cout << strTemporary47[i];
                    }

                    cout << endl;

                    cout << "你成功掌握了" << store.skills.strSkillname[1] << endl;

                    character.setCoins(character.getCoins() - store.skills.price[1]);
                    character.set_Frost_Piercing_true();

                    system("pause");
                }
                break;
            }
        }
    } while (symbolBUY == 1);
}
