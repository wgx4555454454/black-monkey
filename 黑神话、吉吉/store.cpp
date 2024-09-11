#include "stdafx.h"
#include "Menu.h"
using namespace std;

int getInt(int min,int max);//从键盘获取int类型数据

// 自定义延迟输出函数，按下回车键后立即输出剩余的内容
void delayedPrintVector(const vector<string>& temporary, int delay = 0);
void delayedPrintString(string temporary, int delay = 0);
//设置颜色
void setColor(int);

void Store::showStore() {
    vector<string> outputs = {
        "---------------------------\n",
        "商店\n",
        "1.血量药水          价格: " + to_string(Hpotion) + "\n",
        "2.魔法药水          价格: " + to_string(Mpotion) + "\n",
        "3.烈焰斩            价格: " + to_string(skills.price[0]) + "\n",
        "4.冰霜穿刺          价格: " + to_string(skills.price[1]) + "\n",
        "---------------------------"
    };

    delayedPrintVector(outputs, 2);  // 统一输出
}

void Game::Buy() {
    int symbolTHING = 0;

    do {
        system("cls");
        delayedPrintString("剩余金币：" + to_string(character.getCoins()) + "\n");

        store.showStore();

        delayedPrintString("\n请输入你需要购买的序号(0退出)：");

        symbolTHING = getInt(0, 4);

        switch (symbolTHING) {
        case 1:
            if (character.getCoins() < store.Hpotion) {
                delayedPrintString("你的金币不够！\n");
            }
            else {
                delayedPrintString("购买成功!!!\n");
                character.setCoins(character.getCoins() - store.Hpotion);
                character.setHpotionNum(character.getHpotionNum() + 1);
            }
            system("pause");
            break;

        case 2:
            if (character.getCoins() < store.Mpotion) {
                delayedPrintString("你的金币不够！\n");
            }
            else {
                delayedPrintString("购买成功\n");
                character.setCoins(character.getCoins() - store.Mpotion);
                character.setMpotionNum(character.getMpotionNum() + 1);
            }
            system("pause");
            break;

        case 3:
            if (character.get_Flame_Slash()) {
                delayedPrintString("你已经掌握了烈焰斩\n");
            }
            else if (character.getCoins() < store.skills.price[0]) {
                delayedPrintString("你的金币不够！\n");
            }
            else {
                delayedPrintString("成功购买!!!\n你成功掌握了 " + store.skills.strSkillname[0] + "\n");
                character.setCoins(character.getCoins() - store.skills.price[0]);
                character.set_Flame_Slash_true();
            }
            system("pause");
            break;

        case 4:
            if (character.get_Frost_Piercing()) {
                delayedPrintString("你已经掌握了冰霜穿刺\n");
            }
            else if (character.getCoins() < store.skills.price[1]) {
                delayedPrintString("你的金币不够\n");
            }
            else {
                delayedPrintString("成功购买!!!\n你成功掌握了 " + store.skills.strSkillname[1] + "\n");
                character.setCoins(character.getCoins() - store.skills.price[1]);
                character.set_Frost_Piercing_true();
            }
            system("pause");
            break;
        }
    } while (symbolTHING != 0);
}
