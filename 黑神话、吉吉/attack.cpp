#include <iostream>  
#include <iomanip>  
#include <string>  
#include <filesystem>  
#include <windows.h>  
#include <conio.h>
#include <ctime> // ����ʱ�亯��  
#include "Menu.h"  

using namespace std;
int getInt();

int Game::attack() {
    setEnemy();
    srand(static_cast<unsigned int>(time(0))); // ���������  
    int bossID = rand() % 7; // ���ѡ��һ������ 
    Enemy *enemy = &_enemy[bossID];
     
    enemy->showWord(0); // ��ʾ���˵ĶԻ�  

    // ������ѭ��  
    while (character.getHP() > 0 && enemy->getHP() > 0) {
        int choose = 0;
        string temporary6 = "��ѡ����Ҫ�������飺";
        for (int i = 0; i < temporary6.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << temporary6.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(6);
            cout << temporary6[i];
        }
        cout << endl;

        string temporary7 = "1. ��ͨ����";
        for (int i = 0; i < temporary7.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << temporary7.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(6);
            cout << temporary7[i];
        }
        cout << endl;

        string temporary8 = "2. ʹ�ü��ܹ���";
        for (int i = 0; i < temporary8.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << temporary8.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(6);
            cout << temporary8[i];
        }
        cout << endl;

        string temporary9 = "3. ʹ��ҩˮ�ظ�";
        for (int i = 0; i < temporary9.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << temporary9.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(6);
            cout << temporary9[i];
        }
        cout << endl;

        string temporary10 = "4. ����";
        for (int i = 0; i < temporary10.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << temporary10.substr(i) << endl;  // ���ʣ�µ�ȫ������
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
            enemy->setHP(enemy->getHP() - character.getATK()); // �����ܵ��˺�  
            cout << "��Թ�������� " << character.getATK() << " ���˺���" << endl;
            break;
        }
        case 2: {
            string temporary11 = "����ʹ���ĸ����ܣ�";
            for (int i = 0; i < temporary11.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << temporary11.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(6);
                cout << temporary11[i];
            }
            for (size_t i = 0; i < store.skills.skill.size(); ++i) {
                cout << (i + 1) << ". " << store.skills.skill[i] << endl; // ��ʾ�����б�  
            }
            int skillIndex = 0;
            skillIndex=getInt();
            // ��ȥ1��ƥ��0������  
            if (store.skills.checkSkill(skillIndex - 1) && (character.getMpotionNum() % 10)) {
                character.setMP(character.getMP() - 10);
                enemy->setHP(enemy->getHP() - store.skills.getSkillhurt(skillIndex - 1)); // ʹ�ü�������˺�  
                cout << "��Թ�������� " << store.skills.getSkillhurt(skillIndex - 1) << " ���˺���" << endl;
            }
            else {
                if (character.getMP())
                {
                    string temporary12 = "�㻹û������������ܡ�";
                    for (int i = 0; i < temporary12.length(); i++) {
                        // �����⵽���̰���
                        if (_kbhit()) {
                            char key = _getch();  // ��ȡ���µļ�
                            if (key == '\r') {  // �ж��Ƿ��»س���
                                cout << temporary12.substr(i) << endl;  // ���ʣ�µ�ȫ������
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
                    string temporary13 = "��û���㹻����";
                    for (int i = 0; i < temporary13.length(); i++) {
                        // �����⵽���̰���
                        if (_kbhit()) {
                            char key = _getch();  // ��ȡ���µļ�
                            if (key == '\r') {  // �ж��Ƿ��»س���
                                cout << temporary13.substr(i) << endl;  // ���ʣ�µ�ȫ������
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
            string temporary14 = "�������ĸ�ҩˮ?";
            for (int i = 0; i < temporary14.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << temporary14.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(6);
                cout << temporary14[i];
            }
            cout << endl;

            string temporary15 = "1.Ѫ��ҩˮ";
            for (int i = 0; i < temporary15.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << temporary15.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(6);
                cout << temporary15[i];
            }
            cout << endl;

            string temporary16 = "2.����ҩˮ";
            for (int i = 0; i < temporary16.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << temporary16.substr(i) << endl;  // ���ʣ�µ�ȫ������
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
                    string temporary17 = "��û��Ѫ��ҩˮ";
                    for (int i = 0; i < temporary17.length(); i++) {
                        // �����⵽���̰���
                        if (_kbhit()) {
                            char key = _getch();  // ��ȡ���µļ�
                            if (key == '\r') {  // �ж��Ƿ��»س���
                                cout << temporary17.substr(i) << endl;  // ���ʣ�µ�ȫ������
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
                    string temporary18 = "��û������ҩˮ";
                    for (int i = 0; i < temporary18.length(); i++) {
                        // �����⵽���̰���
                        if (_kbhit()) {
                            char key = _getch();  // ��ȡ���µļ�
                            if (key == '\r') {  // �ж��Ƿ��»س���
                                cout << temporary18.substr(i) << endl;  // ���ʣ�µ�ȫ������
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
            string temporary19 = "�ɹ����ܣ�";
            for (int i = 0; i < temporary19.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << temporary19.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(6);
                cout << temporary19[i];
            }
            cout << endl;
            return 0; // �˳���������  
        }
        default: {
            string temporary20 = "������Ч���";
            for (int i = 0; i < temporary20.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << temporary20.substr(i) << endl;  // ���ʣ�µ�ȫ������
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

        // ����ɫ�ڹ������Ƿ���Ȼ���  
        if (enemy->getHP() > 0) {
            cout << "��������� " << enemy->getATK() << " ���˺���" << endl;
            character.setHP(character.getHP() - enemy->getATK()); // ��ɫ�ܵ��˺�  
        }
    }

    // ���ս�����  
    if (character.getHP() > 0) {
        string temporary21 = "���ﱻ��ɱ��";
        for (int i = 0; i < temporary21.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << temporary21.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(0);
            cout << temporary21[i];
        }
        cout << endl;
        enemy->showWord(1); // ��ʾ���˱����ܵĶԻ�  
        cout << "������5����ң�" << endl;
        system("pause");
        return 1;
    }
    else {
        string temporary22 = "�㱻��ɱ�ˡ�";
        for (int i = 0; i < temporary22.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << temporary22.substr(i) << endl;  // ���ʣ�µ�ȫ������
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

    system("pause"); // ��ͣϵͳ�Բ鿴��Ϣ  
}