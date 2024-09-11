#include <iostream>  
#include <iomanip>  
#include <string>  
#include <filesystem>  
#include <windows.h>  
#include <conio.h>
#include <ctime> // 包含时间函数  
#include "Menu.h"  

using namespace std;
int getInt();

// 延迟输出函数，按下回车键后立即输出容器中剩余的内容
void delayedPrintVector(const vector<string>& temporary, int delay = 0) {
    for (size_t i = 0; i < temporary.size(); ++i) {
        const string& line = temporary[i];
        for (char ch : line) {
            if (_kbhit()) {
                char ch = _getch();
                // 按下任意键时立即输出剩余内容
                delay = 0;
            }
            cout << ch;  // 输出当前字符
            Sleep(delay);  // 延迟
        }
    }
}

void setColor(int color);


int Game::attack() {
    using namespace std;

    setEnemy();//设置boss参数

    srand(static_cast<unsigned int>(time(0))); // 随机数种子  
    int bossID = rand() % 7; // 随机选择一个敌人 

    Enemy *ptrEnemy = &enemy[bossID];

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
            "4. 逃跑\n"
            "请选择你要做的事情：",
        };
        setColor(14);
        delayedPrintVector(menuOptions, 6);

        do{
            choose = getInt();
            if (choose != 1 && choose != 2 && choose != 3 && choose != 4)
                cout << "请输入1-4" << endl;

        } while (choose != 1 && choose != 2 && choose != 3 && choose != 4);

        setColor(10);
        switch (choose) {
        case 1: {
            ptrEnemy->setHP(ptrEnemy->getHP() - character.getATK()); // 敌人受到伤害  
            cout << "你对怪物造成了 " << character.getATK() << " 点伤害。" << endl;
            break;
        }
        case 2: 
            cout << "你想使用哪个技能？" << endl;//选择技能
            cout << "1.烈焰斩     " << ((character.get_Flame_Slash()) ? "已获得" : "未获得") << endl;
            cout << "2.冰霜穿刺   " << ((character.get_Frost_Piercing()) ? "已获得" : "未获得") << endl;
            cout << "3.退出" << endl;
            do {
                choose_Skill = getInt();
                if (choose_Skill != 1 && choose_Skill != 2 && choose_Skill != 3)
                    cout << "Error!请输入1-3" << endl;
            } while (choose_Skill != 1 && choose_Skill != 2 && choose_Skill != 3);
            switch (choose_Skill) {
            case 1:
                if (character.get_Flame_Slash()) {
                    if (character.getMP() >= 10) {
                        cout << "你使用烈焰斩对敌人造成了" << store.skills.hurt[0] << "点伤害!" << endl;
                        ptrEnemy->setHP(ptrEnemy->getHP() - store.skills.hurt[0]);
                        character.setMP(character.getMP() - 10);
                    }
                    else{
                        cout << "你的魔法不足！" << endl;
                    }
                }
                else
                    cout << "你还没有获得该技能！" << endl;

                break;
            case 2: {
                if (character.get_Frost_Piercing()) {
                    if (character.getMP() >= 10) {
                        cout << "你使用冰霜穿刺对敌人造成了" << store.skills.hurt[1] << "点伤害!" << endl;
                        ptrEnemy->setHP(ptrEnemy->getHP() - store.skills.hurt[1]);
                    }
                    else
                        cout << "你的魔法不足！" << endl;

                }
                else
                    cout << "你还没有获得该技能！" << endl;
                break;
            }
            case 3:
                break;
            default:
                break;
            }
            break;
        case 3: {  //药水
            int potindex = 0;
            vector<string> menuOptions2 = {
                "\n1.血量药水\n",
                "2.能量药水\n",
                "你想用哪个药水: ",
            };
            delayedPrintVector(menuOptions2);

            do {
                potindex=getInt();
            } while (potindex != 1 && potindex != 2);
            if (potindex == 1){
                if (character.getHpotionNum()){
                    character.setHP(100);
                    character.setHpotionNum(character.getHpotionNum() - 1);
                }
                else{
                    string strTemporary17 = "你没有血量药水";

                    for (int i = 0; i < strTemporary17.length(); i++) {
                        // 如果检测到键盘按下
                        if (_kbhit()) {
                            char ch = _getch();
                            cout << strTemporary17.substr(i) << endl;  // 输出剩下的全部内容
                            break;
                        }
                        Sleep(6);
                        cout << strTemporary17[i];
                    }
                    cout << endl;
                    break;
                }
            }
            if (potindex == 2){
                if (character.getMpotionNum()){
                    character.setMP(character.getMP() + 30);
                    character.setMpotionNum(character.getMpotionNum() - 1);
                }
                else{
                    string strTemporary18 = "你没有能量药水";

                    for (int i = 0; i < strTemporary18.length(); i++) {
                        // 如果检测到键盘按下
                        if (_kbhit()) {
                            char ch = _getch();
                            cout << strTemporary18.substr(i) << endl;  // 输出剩下的全部内容
                            break;
                        }
                        Sleep(6);
                        cout << strTemporary18[i];
                    }
                    cout << endl;
                    break;
                }
            }
            break;
        }
        case 4: {
            string strTemporary19 = "成功逃跑！";

            for (int i = 0; i < strTemporary19.length(); i++) {
                // 如果检测到键盘按下
                if (_kbhit()) {
                    char ch = _getch();  // 获取按下的键
                     {  // 判断是否按下回车键
                        cout << strTemporary19.substr(i) << endl;  // 输出剩下的全部内容
                        break;
                    }
                }
                Sleep(6);
                cout << strTemporary19[i];
            }
            cout << endl;
            return 0; // 退出攻击方法  
        }
        default: {
            string strTemporary20 = "错误：无效命令。";

            for (int i = 0; i < strTemporary20.length(); i++) {
                // 如果检测到键盘按下
                if (_kbhit()) {
                    char ch = _getch();  // 获取按下的键
                     {  // 判断是否按下回车键
                        cout << strTemporary20.substr(i) << endl;  // 输出剩下的全部内容
                        break;
                    }
                }
                Sleep(6);
                cout << strTemporary20[i];
            }
            cout << endl;
            break;
        }
    }
        // 检查角色在攻击后是否仍然存活  
        if (ptrEnemy->getHP() > 0) {
            cout << "怪物造成了 " << ptrEnemy->getATK() << " 点伤害。" << endl;
            character.setHP(character.getHP() - ptrEnemy->getATK()); // 角色受到伤害  
        }
        system("pause");
        system("cls");
    }

    // 检查战斗结果  
    if (character.getHP() > 0) {
        string strTemporary21 = "怪物被击杀！";

        for (int i = 0; i < strTemporary21.length(); i++) {
            // 如果检测到键盘按下
            if (_kbhit()) {
                char ch = _getch();
                cout << strTemporary21.substr(i) << endl;  // 输出剩下的全部内容
                break;

            }
            Sleep(0);
            cout << strTemporary21[i];
        }
        cout << endl;
        ptrEnemy->showWord(1); // 显示敌人被击败的对话  
        cout << "你获得了5个金币！" << endl;

        system("pause");
        return 1;
    }
    else {
        string strTemporary22 = "你被击杀了。";

        for (int i = 0; i < strTemporary22.length(); i++) {
            // 如果检测到键盘按下
            if (_kbhit()) {
                char ch = _getch();
                cout << strTemporary22.substr(i) << endl;  // 输出剩下的全部内容
                break;
            }
            Sleep(6);
            cout << strTemporary22[i];
        }
        cout << endl;
        ptrEnemy->showWord(2);
        system("pause");
        return 2;
    }
    system("pause"); // 暂停系统以查看消息  
}