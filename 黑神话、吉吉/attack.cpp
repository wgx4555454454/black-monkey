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
    Enemy enemy_ = _enemy[bossID];
    Enemy* enemy = &enemy_; // ��ȡ��ǰ���˵�ָ��  
    enemy->showWord(1); // ��ʾ���˵ĶԻ�  

    // ������ѭ��  
    while (character.getHP() > 0 && enemy->getHP() > 0) {
        int choose = 0;
        cout << "��ѡ����Ҫ�������飺" << endl;
        cout << "1. ��ͨ����" << endl;
        cout << "2. ʹ�ü��ܹ���" << endl;
        cout << "3. ����" << endl;
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
            if (store.skills.checkSkill(skillIndex - 1)) {
                enemy->setHP(enemy->getHP() - store.skills.getSkillhurt(skillIndex - 1)); // ʹ�ü�������˺�  
                cout << "��Թ�������� " << store.skills.getSkillhurt(skillIndex - 1) << " ���˺���" << endl;
            }
            else {
                cout << "�㻹û������������ܡ�" << endl;
            }
            break;
        }
        case 3:
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