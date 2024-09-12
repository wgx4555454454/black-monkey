#include "stdafx.h"
#include "Menu.h"  

using namespace std;

//自定义从键盘中获取整型数据
int getInt(int min, int max);

// 延迟输出函数，按下回车键后立即输出剩余的内容
void delayedPrintVector(const vector<string>& temporary, int delay = 0);
void delayedPrintString(string temporary, int delay = 0);

//修改颜色
void setColor(int color);

int Game::attack() {
    using namespace std;

    setEnemy(); // 设置boss参数

    srand(static_cast<unsigned int>(time(0))); // 随机数种子  
    int bossID = rand() % 7; // 随机选择一个敌人 

    Enemy* ptrEnemy = &enemy[bossID];

    int choose_Skill = 0;
    setColor(12);
    ptrEnemy->showWord(0); // 显示敌人的对话  
    setColor(10);
    system("pause");
    system("cls");

    // 主攻击循环  
    while (character.getHP() > 0 && ptrEnemy->getHP() > 0) {
        cout << "主角：" << endl;
        cout << "     血量：" << character.getHP() << endl;
        cout << "     能量：" << character.getMP() << endl;
        cout << "怪物：" << endl;
        cout << "     血量：" << ptrEnemy->getHP() << endl;

        int choose = 0;
        vector<string> menuOptions = {
            "\n1. 普通攻击\n",
            "2. 使用技能攻击\n",
            "3. 使用药水回复\n",
            "4. 逃跑\n",
            "请选择你要做的事情："
        };
        setColor(14);
        delayedPrintVector(menuOptions, 6);

        do {
            choose = getInt(1, 4);
            if (choose < 1 || choose > 4)
                cout << "请输入1-4" << endl;
        } while (choose < 1 || choose > 4);

        setColor(10);

        switch (choose) {
        case 1: {  // 普通攻击
            ptrEnemy->setHP(ptrEnemy->getHP() - character.getATK());
            cout << "你对怪物造成了 " << character.getATK() << " 点伤害。" << endl;
            break;
        }
        case 2: {  // 技能攻击
            cout << "你想使用哪个技能？" << endl;
            cout << "1. 烈焰斩     " << (character.get_Flame_Slash() ? "已获得" : "未获得") << endl;
            cout << "2. 冰霜穿刺   " << (character.get_Frost_Piercing() ? "已获得" : "未获得") << endl;
            cout << "3. 退出" << endl;
            choose_Skill = getInt(1, 3);

            switch (choose_Skill) {
            case 1:
                if (character.get_Flame_Slash()) {
                    if (character.getMP() >= 10) {
                        cout << "你使用烈焰斩对敌人造成了 " << store.skills.hurt[0] << " 点伤害!" << endl;
                        ptrEnemy->setHP(ptrEnemy->getHP() - store.skills.hurt[0]);
                        character.setMP(character.getMP() - 10);
                    }
                    else {
                        cout << "你的魔法不足！" << endl;
                    }
                }
                else {
                    cout << "你还没有获得该技能！" << endl;
                }
                break;

            case 2:
                if (character.get_Frost_Piercing()) {
                    if (character.getMP() >= 10) {
                        cout << "你使用冰霜穿刺对敌人造成了 " << store.skills.hurt[1] << " 点伤害!" << endl;
                        ptrEnemy->setHP(ptrEnemy->getHP() - store.skills.hurt[1]);
                        character.setMP(character.getMP() - 10);
                    }
                    else {
                        cout << "你的魔法不足！" << endl;
                    }
                }
                else {
                    cout << "你还没有获得该技能！" << endl;
                }
                break;

            case 3:
                break;
            }
            break;
        }
        case 3: {  // 使用药水
            int potindex = 0;
            vector<string> menuOptions2 = {
                "\n1. 血量药水\n",
                "2. 能量药水\n",
                "你想用哪个药水: "
            };
            delayedPrintVector(menuOptions2);

            potindex = getInt(1, 2);

            if (potindex == 1) {
                if (character.getHpotionNum()) {
                    character.setHP(100);
                    character.setHpotionNum(character.getHpotionNum() - 1);
                }
                else {
                    delayedPrintString("你没有血量药水\n");
                }
            }
            else if (potindex == 2) {
                if (character.getMpotionNum()) {
                    character.setMP(character.getMP() + 30);
                    character.setMpotionNum(character.getMpotionNum() - 1);
                }
                else {
                    delayedPrintString("你没有能量药水\n");
                }
            }
            break;
        }
        case 4: {  // 逃跑
            delayedPrintString("成功逃跑！\n");
            return 0;
        }
        }

        // 检查怪物是否存活
        if (ptrEnemy->getHP() > 0) {
            cout << "怪物造成了 " << ptrEnemy->getATK() << " 点伤害。\n" << endl;
            character.setHP(character.getHP() - ptrEnemy->getATK());
        }
        system("pause");
        system("cls");
    }

    // 战斗结束后的处理
    if (character.getHP() > 0) {
        delayedPrintString("怪物被击杀！\n");
        ptrEnemy->showWord(1); // 显示敌人被击败的对话
        cout << "你获得了5个金币！\n" << endl;
        system("pause");
        return 1;
    }
    else {
        delayedPrintString("你被击杀了。\n");
        ptrEnemy->showWord(2);
        system("pause");
        return 2;
    }
}
