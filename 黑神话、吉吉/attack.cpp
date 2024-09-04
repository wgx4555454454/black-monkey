#include <iostream>  
#include <iomanip>  
#include <string>  
#include <filesystem>  
#include <windows.h>  
#include <ctime> // ����ʱ�亯��  
#include "Menu.h"  

using namespace std;

void Game::attack() {
    cout << "��ã�" << endl; // ��ӻ�������߿ɶ���  
    srand(static_cast<unsigned int>(time(0))); // ���������  
    int bossID = rand() % 7; // ���ѡ��һ������ 
    Enemy *enemy = &_enemy[bossID];
     
    enemy->showWord(1); // ��ʾ���˵ĶԻ�  

    // ������ѭ��  
    while (character.getHP() > 0 && enemy->getHP() > 0) {
        int choose = 0;
        cout << "��ѡ����Ҫ�������飺" << endl;
        cout << "1. ��ͨ����" << endl;
        cout << "2. ʹ�ü��ܹ���" << endl;
        cout << "3.ʹ��ҩˮ�ظ�" << endl;
        cout << "4. ����" << endl;
        cin >> choose;

        switch (choose) {
        case 1: {
            enemy->setHP(enemy->getHP() - character.getATK()); // �����ܵ��˺�  
            cout << "��Թ�������� " << character.getATK() << " ���˺���" << endl;
            break;
        }
        case 2: {
            cout << "����ʹ���ĸ����ܣ�" << endl;
            for (size_t i = 0; i < store.skills.skill.size(); ++i) {
                cout << (i + 1) << ". " << store.skills.skill[i] << endl; // ��ʾ�����б�  
            }
            int skillIndex = 0;
            cin >> skillIndex;
            // ��ȥ1��ƥ��0������  
            if (store.skills.checkSkill(skillIndex - 1) && (character.getMpotionNum() % 10)) {
                character.setMP(character.getMP() - 10);
                enemy->setHP(enemy->getHP() - store.skills.getSkillhurt(skillIndex - 1)); // ʹ�ü�������˺�  
                cout << "��Թ�������� " << store.skills.getSkillhurt(skillIndex - 1) << " ���˺���" << endl;
            }
            else {
                if (character.getMP())
                {
                    cout << "�㻹û������������ܡ�" << endl;
                }
                else
                {
                    cout << "��û���㹻����" << endl;
                }
            }
            break;
        }
        case 3:
        {
            int potindex = 0;
            cout << "�������ĸ�ҩˮ?" << endl;
            cout << "1.Ѫ��ҩˮ" << endl;
            cout << "2.����ҩˮ" << endl;
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
                    cout << "��û��Ѫ��ҩˮ" << endl;
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
                    cout << "��û������ҩˮ" << endl;
                    break;
                }
            }
            break;
        }
        case 4:
            cout << "�ɹ����ܣ�" << endl;
            return; // �˳���������  
        default:
            cout << "������Ч���" << endl;
            break;
        }

        // ����ɫ�ڹ������Ƿ���Ȼ���  
        if (enemy->getHP() > 0) {
            cout << "��������� " << enemy->getATK() << " ���˺���" << endl;
            character.setHP(character.getHP() - enemy->getATK()); // ��ɫ�ܵ��˺�  
        }
    }

    // ���ս�����  
    if (character.getHP() > 0) {
        cout << "���ﱻ��ɱ��" << endl;
        enemy->showWord(2); // ��ʾ���˱����ܵĶԻ�  
    }
    else {
        cout << "�㱻��ɱ�ˡ�" << endl;
    }

    system("pause"); // ��ͣϵͳ�Բ鿴��Ϣ  
}