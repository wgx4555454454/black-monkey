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

// �ӳ�������������»س������������������ʣ�������
void delayedPrintVector(const vector<string>& temporary, int delay = 0) {
    for (size_t i = 0; i < temporary.size(); ++i) {
        const string& line = temporary[i];
        for (char ch : line) {
            if (_kbhit()) {
                char ch = _getch();
                // ���������ʱ�������ʣ������
                delay = 0;
            }
            cout << ch;  // �����ǰ�ַ�
            Sleep(delay);  // �ӳ�
        }
    }
}

void setColor(int color);


int Game::attack() {
    using namespace std;

    setEnemy();//����boss����

    srand(static_cast<unsigned int>(time(0))); // ���������  
    int bossID = rand() % 7; // ���ѡ��һ������ 

    Enemy *ptrEnemy = &enemy[bossID];

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
            "4. ����\n"
            "��ѡ����Ҫ�������飺",
        };
        setColor(14);
        delayedPrintVector(menuOptions, 6);

        do{
            choose = getInt();
            if (choose != 1 && choose != 2 && choose != 3 && choose != 4)
                cout << "������1-4" << endl;

        } while (choose != 1 && choose != 2 && choose != 3 && choose != 4);

        setColor(10);
        switch (choose) {
        case 1: {
            ptrEnemy->setHP(ptrEnemy->getHP() - character.getATK()); // �����ܵ��˺�  
            cout << "��Թ�������� " << character.getATK() << " ���˺���" << endl;
            break;
        }
        case 2: 
            cout << "����ʹ���ĸ����ܣ�" << endl;//ѡ����
            cout << "1.����ն     " << ((character.get_Flame_Slash()) ? "�ѻ��" : "δ���") << endl;
            cout << "2.��˪����   " << ((character.get_Frost_Piercing()) ? "�ѻ��" : "δ���") << endl;
            cout << "3.�˳�" << endl;
            do {
                choose_Skill = getInt();
                if (choose_Skill != 1 && choose_Skill != 2 && choose_Skill != 3)
                    cout << "Error!������1-3" << endl;
            } while (choose_Skill != 1 && choose_Skill != 2 && choose_Skill != 3);
            switch (choose_Skill) {
            case 1:
                if (character.get_Flame_Slash()) {
                    if (character.getMP() >= 10) {
                        cout << "��ʹ������ն�Ե��������" << store.skills.hurt[0] << "���˺�!" << endl;
                        ptrEnemy->setHP(ptrEnemy->getHP() - store.skills.hurt[0]);
                        character.setMP(character.getMP() - 10);
                    }
                    else{
                        cout << "���ħ�����㣡" << endl;
                    }
                }
                else
                    cout << "�㻹û�л�øü��ܣ�" << endl;

                break;
            case 2: {
                if (character.get_Frost_Piercing()) {
                    if (character.getMP() >= 10) {
                        cout << "��ʹ�ñ�˪���̶Ե��������" << store.skills.hurt[1] << "���˺�!" << endl;
                        ptrEnemy->setHP(ptrEnemy->getHP() - store.skills.hurt[1]);
                    }
                    else
                        cout << "���ħ�����㣡" << endl;

                }
                else
                    cout << "�㻹û�л�øü��ܣ�" << endl;
                break;
            }
            case 3:
                break;
            default:
                break;
            }
            break;
        case 3: {  //ҩˮ
            int potindex = 0;
            vector<string> menuOptions2 = {
                "\n1.Ѫ��ҩˮ\n",
                "2.����ҩˮ\n",
                "�������ĸ�ҩˮ: ",
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
                    string strTemporary17 = "��û��Ѫ��ҩˮ";

                    for (int i = 0; i < strTemporary17.length(); i++) {
                        // �����⵽���̰���
                        if (_kbhit()) {
                            char ch = _getch();
                            cout << strTemporary17.substr(i) << endl;  // ���ʣ�µ�ȫ������
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
                    string strTemporary18 = "��û������ҩˮ";

                    for (int i = 0; i < strTemporary18.length(); i++) {
                        // �����⵽���̰���
                        if (_kbhit()) {
                            char ch = _getch();
                            cout << strTemporary18.substr(i) << endl;  // ���ʣ�µ�ȫ������
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
            string strTemporary19 = "�ɹ����ܣ�";

            for (int i = 0; i < strTemporary19.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char ch = _getch();  // ��ȡ���µļ�
                     {  // �ж��Ƿ��»س���
                        cout << strTemporary19.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(6);
                cout << strTemporary19[i];
            }
            cout << endl;
            return 0; // �˳���������  
        }
        default: {
            string strTemporary20 = "������Ч���";

            for (int i = 0; i < strTemporary20.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char ch = _getch();  // ��ȡ���µļ�
                     {  // �ж��Ƿ��»س���
                        cout << strTemporary20.substr(i) << endl;  // ���ʣ�µ�ȫ������
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
        // ����ɫ�ڹ������Ƿ���Ȼ���  
        if (ptrEnemy->getHP() > 0) {
            cout << "��������� " << ptrEnemy->getATK() << " ���˺���" << endl;
            character.setHP(character.getHP() - ptrEnemy->getATK()); // ��ɫ�ܵ��˺�  
        }
        system("pause");
        system("cls");
    }

    // ���ս�����  
    if (character.getHP() > 0) {
        string strTemporary21 = "���ﱻ��ɱ��";

        for (int i = 0; i < strTemporary21.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char ch = _getch();
                cout << strTemporary21.substr(i) << endl;  // ���ʣ�µ�ȫ������
                break;

            }
            Sleep(0);
            cout << strTemporary21[i];
        }
        cout << endl;
        ptrEnemy->showWord(1); // ��ʾ���˱����ܵĶԻ�  
        cout << "������5����ң�" << endl;

        system("pause");
        return 1;
    }
    else {
        string strTemporary22 = "�㱻��ɱ�ˡ�";

        for (int i = 0; i < strTemporary22.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char ch = _getch();
                cout << strTemporary22.substr(i) << endl;  // ���ʣ�µ�ȫ������
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
    system("pause"); // ��ͣϵͳ�Բ鿴��Ϣ  
}