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

int Game::attack() {
    setEnemy();
    srand(static_cast<unsigned int>(time(0))); // 随机数种子  
    int bossID = rand() % 7; // 随机选择一个敌人 
    Enemy *enemy = &_enemy[bossID];
     
    enemy->showWord(0); // 显示敌人的对话  

    // 主攻击循环  
    while (character.getHP() > 0 && enemy->getHP() > 0) {
        int choose = 0;
        string temporary6 = "请选择你要做的事情：";
        for (int i = 0; i < temporary6.length(); i++) {
            // 如果检测到键盘按下
            if (_kbhit()) {
                char key = _getch();  // 获取按下的键
                if (key == '\r') {  // 判断是否按下回车键
                    cout << temporary6.substr(i) << endl;  // 输出剩下的全部内容
                    break;
                }
            }
            Sleep(6);
            cout << temporary6[i];
        }
        cout << endl;

        string temporary7 = "1. 普通攻击";
        for (int i = 0; i < temporary7.length(); i++) {
            // 如果检测到键盘按下
            if (_kbhit()) {
                char key = _getch();  // 获取按下的键
                if (key == '\r') {  // 判断是否按下回车键
                    cout << temporary7.substr(i) << endl;  // 输出剩下的全部内容
                    break;
                }
            }
            Sleep(6);
            cout << temporary7[i];
        }
        cout << endl;

        string temporary8 = "2. 使用技能攻击";
        for (int i = 0; i < temporary8.length(); i++) {
            // 如果检测到键盘按下
            if (_kbhit()) {
                char key = _getch();  // 获取按下的键
                if (key == '\r') {  // 判断是否按下回车键
                    cout << temporary8.substr(i) << endl;  // 输出剩下的全部内容
                    break;
                }
            }
            Sleep(6);
            cout << temporary8[i];
        }
        cout << endl;

        string temporary9 = "3. 使用药水回复";
        for (int i = 0; i < temporary9.length(); i++) {
            // 如果检测到键盘按下
            if (_kbhit()) {
                char key = _getch();  // 获取按下的键
                if (key == '\r') {  // 判断是否按下回车键
                    cout << temporary9.substr(i) << endl;  // 输出剩下的全部内容
                    break;
                }
            }
            Sleep(6);
            cout << temporary9[i];
        }
        cout << endl;

        string temporary10 = "4. 逃跑";
        for (int i = 0; i < temporary10.length(); i++) {
            // 如果检测到键盘按下
            if (_kbhit()) {
                char key = _getch();  // 获取按下的键
                if (key == '\r') {  // 判断是否按下回车键
                    cout << temporary10.substr(i) << endl;  // 输出剩下的全部内容
                    break;
                }
            }
            Sleep(6);
            cout << temporary10[i];
        }
        cout << endl;
        choose=getInt();

        switch (choose) {
        case 1: {
            enemy->setHP(enemy->getHP() - character.getATK()); // 敌人受到伤害  
            cout << "你对怪物造成了 " << character.getATK() << " 点伤害。" << endl;
            break;
        }
        case 2: {
            string temporary11 = "你想使用哪个技能？";
            for (int i = 0; i < temporary11.length(); i++) {
                // 如果检测到键盘按下
                if (_kbhit()) {
                    char key = _getch();  // 获取按下的键
                    if (key == '\r') {  // 判断是否按下回车键
                        cout << temporary11.substr(i) << endl;  // 输出剩下的全部内容
                        break;
                    }
                }
                Sleep(6);
                cout << temporary11[i];
            }
            for (size_t i = 0; i < store.skills.skill.size(); ++i) {
                cout << (i + 1) << ". " << store.skills.skill[i] << endl; // 显示技能列表  
            }
            int skillIndex = 0;
            skillIndex=getInt();
            // 减去1以匹配0基索引  
            if (store.skills.checkSkill(skillIndex - 1) && (character.getMpotionNum() % 10)) {
                character.setMP(character.getMP() - 10);
                enemy->setHP(enemy->getHP() - store.skills.getSkillhurt(skillIndex - 1)); // 使用技能造成伤害  
                cout << "你对怪物造成了 " << store.skills.getSkillhurt(skillIndex - 1) << " 点伤害。" << endl;
            }
            else {
                if (character.getMP())
                {
                    string temporary12 = "你还没有掌握这个技能。";
                    for (int i = 0; i < temporary12.length(); i++) {
                        // 如果检测到键盘按下
                        if (_kbhit()) {
                            char key = _getch();  // 获取按下的键
                            if (key == '\r') {  // 判断是否按下回车键
                                cout << temporary12.substr(i) << endl;  // 输出剩下的全部内容
                                break;
                            }
                        }
                        Sleep(6);
                        cout << temporary12[i];
                    }
                    cout << endl;
                }
                else
                {
                    string temporary13 = "你没有足够能量";
                    for (int i = 0; i < temporary13.length(); i++) {
                        // 如果检测到键盘按下
                        if (_kbhit()) {
                            char key = _getch();  // 获取按下的键
                            if (key == '\r') {  // 判断是否按下回车键
                                cout << temporary13.substr(i) << endl;  // 输出剩下的全部内容
                                break;
                            }
                        }
                        Sleep(6);
                        cout << temporary13[i];
                    }
                    cout << endl;
                }
            }
            break;
        }
        case 3: {  
            int potindex = 0;
            string temporary14 = "你想用哪个药水?";
            for (int i = 0; i < temporary14.length(); i++) {
                // 如果检测到键盘按下
                if (_kbhit()) {
                    char key = _getch();  // 获取按下的键
                    if (key == '\r') {  // 判断是否按下回车键
                        cout << temporary14.substr(i) << endl;  // 输出剩下的全部内容
                        break;
                    }
                }
                Sleep(6);
                cout << temporary14[i];
            }
            cout << endl;

            string temporary15 = "1.血量药水";
            for (int i = 0; i < temporary15.length(); i++) {
                // 如果检测到键盘按下
                if (_kbhit()) {
                    char key = _getch();  // 获取按下的键
                    if (key == '\r') {  // 判断是否按下回车键
                        cout << temporary15.substr(i) << endl;  // 输出剩下的全部内容
                        break;
                    }
                }
                Sleep(6);
                cout << temporary15[i];
            }
            cout << endl;

            string temporary16 = "2.能量药水";
            for (int i = 0; i < temporary16.length(); i++) {
                // 如果检测到键盘按下
                if (_kbhit()) {
                    char key = _getch();  // 获取按下的键
                    if (key == '\r') {  // 判断是否按下回车键
                        cout << temporary16.substr(i) << endl;  // 输出剩下的全部内容
                        break;
                    }
                }
                Sleep(6);
                cout << temporary16[i];
            }
            cout << endl;
            do {
                potindex=getInt();
            } while (potindex != 1 && potindex != 2);
            if (potindex == 1)
            {
                if (character.getHpotionNum())
                {
                    character.setHP(character.getHP() + 1 * 10);
                    character.setHpotionNum(character.getHpotionNum() - 1);
                }
                else
                {
                    string temporary17 = "你没有血量药水";
                    for (int i = 0; i < temporary17.length(); i++) {
                        // 如果检测到键盘按下
                        if (_kbhit()) {
                            char key = _getch();  // 获取按下的键
                            if (key == '\r') {  // 判断是否按下回车键
                                cout << temporary17.substr(i) << endl;  // 输出剩下的全部内容
                                break;
                            }
                        }
                        Sleep(6);
                        cout << temporary17[i];
                    }
                    cout << endl;
                    break;
                }
            }
            if (potindex == 2)
            {
                if (character.getMpotionNum())
                {
                    character.setMP(character.getMP() + 1 * 10);
                    character.setMpotionNum(character.getMpotionNum() - 1);
                }
                else
                {
                    string temporary18 = "你没有能量药水";
                    for (int i = 0; i < temporary18.length(); i++) {
                        // 如果检测到键盘按下
                        if (_kbhit()) {
                            char key = _getch();  // 获取按下的键
                            if (key == '\r') {  // 判断是否按下回车键
                                cout << temporary18.substr(i) << endl;  // 输出剩下的全部内容
                                break;
                            }
                        }
                        Sleep(6);
                        cout << temporary18[i];
                    }
                    cout << endl;
                    break;
                }
            }
            break;
        }
        case 4: {
            string temporary19 = "成功逃跑！";
            for (int i = 0; i < temporary19.length(); i++) {
                // 如果检测到键盘按下
                if (_kbhit()) {
                    char key = _getch();  // 获取按下的键
                    if (key == '\r') {  // 判断是否按下回车键
                        cout << temporary19.substr(i) << endl;  // 输出剩下的全部内容
                        break;
                    }
                }
                Sleep(6);
                cout << temporary19[i];
            }
            cout << endl;
            return 0; // 退出攻击方法  
        }
        default: {
            string temporary20 = "错误：无效命令。";
            for (int i = 0; i < temporary20.length(); i++) {
                // 如果检测到键盘按下
                if (_kbhit()) {
                    char key = _getch();  // 获取按下的键
                    if (key == '\r') {  // 判断是否按下回车键
                        cout << temporary20.substr(i) << endl;  // 输出剩下的全部内容
                        break;
                    }
                }
                Sleep(6);
                cout << temporary20[i];
            }
            cout << endl;
            break;
        }
    }

        // 检查角色在攻击后是否仍然存活  
        if (enemy->getHP() > 0) {
            cout << "怪物造成了 " << enemy->getATK() << " 点伤害。" << endl;
            character.setHP(character.getHP() - enemy->getATK()); // 角色受到伤害  
        }
    }

    // 检查战斗结果  
    if (character.getHP() > 0) {
        string temporary21 = "怪物被击杀！";
        for (int i = 0; i < temporary21.length(); i++) {
            // 如果检测到键盘按下
            if (_kbhit()) {
                char key = _getch();  // 获取按下的键
                if (key == '\r') {  // 判断是否按下回车键
                    cout << temporary21.substr(i) << endl;  // 输出剩下的全部内容
                    break;
                }
            }
            Sleep(0);
            cout << temporary21[i];
        }
        cout << endl;
        enemy->showWord(1); // 显示敌人被击败的对话  
        cout << "你获得了5个金币！" << endl;
        system("pause");
        return 1;
    }
    else {
        string temporary22 = "你被击杀了。";
        for (int i = 0; i < temporary22.length(); i++) {
            // 如果检测到键盘按下
            if (_kbhit()) {
                char key = _getch();  // 获取按下的键
                if (key == '\r') {  // 判断是否按下回车键
                    cout << temporary22.substr(i) << endl;  // 输出剩下的全部内容
                    break;
                }
            }
            Sleep(6);
            cout << temporary22[i];
        }
        cout << endl;
        enemy->showWord(2);
        system("pause");
        return 2;
    }

    system("pause"); // 暂停系统以查看消息  
}