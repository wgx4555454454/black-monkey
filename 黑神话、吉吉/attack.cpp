#include "stdafx.h"
#include "Menu.h"  

using namespace std;

//�Զ���Ӽ����л�ȡ��������
int getInt(int min, int max);

// �ӳ�������������»س������������ʣ�������
void delayedPrintVector(const vector<string>& temporary, int delay = 0);
void delayedPrintString(string temporary, int delay = 0);

//�޸���ɫ
void setColor(int color);

int Game::attack() {
    using namespace std;

    setEnemy(); // ����boss����

    srand(static_cast<unsigned int>(time(0))); // ���������  
    int bossID = rand() % 7; // ���ѡ��һ������ 

    Enemy* ptrEnemy = &enemy[bossID];

    int choose_Skill = 0;
    setColor(12);
    ptrEnemy->showWord(0); // ��ʾ���˵ĶԻ�  
    setColor(10);
    system("pause");
    system("cls");

    // ������ѭ��  
    while (character.getHP() > 0 && ptrEnemy->getHP() > 0) {
        cout << "���ǣ�" << endl;
        cout << "     Ѫ����" << character.getHP() << endl;
        cout << "     ������" << character.getMP() << endl;
        cout << "���" << endl;
        cout << "     Ѫ����" << ptrEnemy->getHP() << endl;

        int choose = 0;
        vector<string> menuOptions = {
            "\n1. ��ͨ����\n",
            "2. ʹ�ü��ܹ���\n",
            "3. ʹ��ҩˮ�ظ�\n",
            "4. ����\n",
            "��ѡ����Ҫ�������飺"
        };
        setColor(14);
        delayedPrintVector(menuOptions, 6);

        do {
            choose = getInt(1, 4);
            if (choose < 1 || choose > 4)
                cout << "������1-4" << endl;
        } while (choose < 1 || choose > 4);

        setColor(10);

        switch (choose) {
        case 1: {  // ��ͨ����
            ptrEnemy->setHP(ptrEnemy->getHP() - character.getATK());
            cout << "��Թ�������� " << character.getATK() << " ���˺���" << endl;
            break;
        }
        case 2: {  // ���ܹ���
            cout << "����ʹ���ĸ����ܣ�" << endl;
            cout << "1. ����ն     " << (character.get_Flame_Slash() ? "�ѻ��" : "δ���") << endl;
            cout << "2. ��˪����   " << (character.get_Frost_Piercing() ? "�ѻ��" : "δ���") << endl;
            cout << "3. �˳�" << endl;
            choose_Skill = getInt(1, 3);

            switch (choose_Skill) {
            case 1:
                if (character.get_Flame_Slash()) {
                    if (character.getMP() >= 10) {
                        cout << "��ʹ������ն�Ե�������� " << store.skills.hurt[0] << " ���˺�!" << endl;
                        ptrEnemy->setHP(ptrEnemy->getHP() - store.skills.hurt[0]);
                        character.setMP(character.getMP() - 10);
                    }
                    else {
                        cout << "���ħ�����㣡" << endl;
                    }
                }
                else {
                    cout << "�㻹û�л�øü��ܣ�" << endl;
                }
                break;

            case 2:
                if (character.get_Frost_Piercing()) {
                    if (character.getMP() >= 10) {
                        cout << "��ʹ�ñ�˪���̶Ե�������� " << store.skills.hurt[1] << " ���˺�!" << endl;
                        ptrEnemy->setHP(ptrEnemy->getHP() - store.skills.hurt[1]);
                        character.setMP(character.getMP() - 10);
                    }
                    else {
                        cout << "���ħ�����㣡" << endl;
                    }
                }
                else {
                    cout << "�㻹û�л�øü��ܣ�" << endl;
                }
                break;

            case 3:
                break;
            }
            break;
        }
        case 3: {  // ʹ��ҩˮ
            int potindex = 0;
            vector<string> menuOptions2 = {
                "\n1. Ѫ��ҩˮ\n",
                "2. ����ҩˮ\n",
                "�������ĸ�ҩˮ: "
            };
            delayedPrintVector(menuOptions2);

            potindex = getInt(1, 2);

            if (potindex == 1) {
                if (character.getHpotionNum()) {
                    character.setHP(100);
                    character.setHpotionNum(character.getHpotionNum() - 1);
                }
                else {
                    delayedPrintString("��û��Ѫ��ҩˮ\n");
                }
            }
            else if (potindex == 2) {
                if (character.getMpotionNum()) {
                    character.setMP(character.getMP() + 30);
                    character.setMpotionNum(character.getMpotionNum() - 1);
                }
                else {
                    delayedPrintString("��û������ҩˮ\n");
                }
            }
            break;
        }
        case 4: {  // ����
            delayedPrintString("�ɹ����ܣ�\n");
            return 0;
        }
        }

        // �������Ƿ���
        if (ptrEnemy->getHP() > 0) {
            cout << "��������� " << ptrEnemy->getATK() << " ���˺���\n" << endl;
            character.setHP(character.getHP() - ptrEnemy->getATK());
        }
        system("pause");
        system("cls");
    }

    // ս��������Ĵ���
    if (character.getHP() > 0) {
        delayedPrintString("���ﱻ��ɱ��\n");
        ptrEnemy->showWord(1); // ��ʾ���˱����ܵĶԻ�
        cout << "������5����ң�\n" << endl;
        system("pause");
        return 1;
    }
    else {
        delayedPrintString("�㱻��ɱ�ˡ�\n");
        ptrEnemy->showWord(2);
        system("pause");
        return 2;
    }
}
