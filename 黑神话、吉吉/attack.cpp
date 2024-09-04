#include <iostream>  
#include <iomanip>  
#include <string>  
#include <filesystem>  
#include <windows.h>  
#include <ctime> // 包含时间函数  
#include "Menu.h"  

using namespace std;

void Game::attack() {
    cout << "你好！" << endl; // 添加换行以提高可读性  
    srand(static_cast<unsigned int>(time(0))); // 随机数种子  
    int bossID = rand() % 7; // 随机选择一个敌人 
    Enemy *enemy = &_enemy[bossID];
     
    enemy->showWord(1); // 显示敌人的对话  

    // 主攻击循环  
    while (character.getHP() > 0 && enemy->getHP() > 0) {
        int choose = 0;
        cout << "请选择你要做的事情：" << endl;
        cout << "1. 普通攻击" << endl;
        cout << "2. 使用技能攻击" << endl;
        cout << "3.使用药水回复" << endl;
        cout << "4. 逃跑" << endl;
        cin >> choose;

        switch (choose) {
        case 1: {
            enemy->setHP(enemy->getHP() - character.getATK()); // 敌人受到伤害  
            cout << "你对怪物造成了 " << character.getATK() << " 点伤害。" << endl;
            break;
        }
        case 2: {
            cout << "你想使用哪个技能？" << endl;
            for (size_t i = 0; i < store.skills.skill.size(); ++i) {
                cout << (i + 1) << ". " << store.skills.skill[i] << endl; // 显示技能列表  
            }
            int skillIndex = 0;
            cin >> skillIndex;
            // 减去1以匹配0基索引  
            if (store.skills.checkSkill(skillIndex - 1) && (character.getMpotionNum() % 10)) {
                character.setMP(character.getMP() - 10);
                enemy->setHP(enemy->getHP() - store.skills.getSkillhurt(skillIndex - 1)); // 使用技能造成伤害  
                cout << "你对怪物造成了 " << store.skills.getSkillhurt(skillIndex - 1) << " 点伤害。" << endl;
            }
            else {
                if (character.getMP())
                {
                    cout << "你还没有掌握这个技能。" << endl;
                }
                else
                {
                    cout << "你没有足够能量" << endl;
                }
            }
            break;
        }
        case 3:
        {
            int potindex = 0;
            cout << "你想用哪个药水?" << endl;
            cout << "1.血量药水" << endl;
            cout << "2.能量药水" << endl;
            do {
                cin >> potindex;
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
                    cout << "你没有血量药水" << endl;
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
                    cout << "你没有能量药水" << endl;
                    break;
                }
            }
            break;
        }
        case 4:
            cout << "成功逃跑！" << endl;
            return; // 退出攻击方法  
        default:
            cout << "错误：无效命令。" << endl;
            break;
        }

        // 检查角色在攻击后是否仍然存活  
        if (enemy->getHP() > 0) {
            cout << "怪物造成了 " << enemy->getATK() << " 点伤害。" << endl;
            character.setHP(character.getHP() - enemy->getATK()); // 角色受到伤害  
        }
    }

    // 检查战斗结果  
    if (character.getHP() > 0) {
        cout << "怪物被击杀！" << endl;
        enemy->showWord(2); // 显示敌人被击败的对话  
    }
    else {
        cout << "你被击杀了。" << endl;
    }

    system("pause"); // 暂停系统以查看消息  
}