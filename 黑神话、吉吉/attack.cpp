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

    Enemy *ptrEnemy = &enemy[bossID];

    int choose_Skill = 0;

    ptrEnemy->showWord(0); // ��ʾ���˵ĶԻ�  

    // ������ѭ��  
    while (character.getHP() > 0 && ptrEnemy->getHP() > 0) {
        cout << "���ǣ�" << endl;
        cout << "     Ѫ����" << character.getHP() << endl;
        cout << "     ������" << character.getMP() << endl;
        cout << "���" << endl;
        cout << "     Ѫ����" << ptrEnemy->getHP() << endl;

        int choose = 0;
        string strTemporary6 = "��ѡ����Ҫ�������飺";

        for (int i = 0; i < strTemporary6.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << strTemporary6.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(6);
            cout << strTemporary6[i];
        }

        cout << endl;

        string strTemporary7 = "1. ��ͨ����";

        for (int i = 0; i < strTemporary7.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << strTemporary7.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(6);
            cout << strTemporary7[i];
        }
        cout << endl;

        string strTemporary8 = "2. ʹ�ü��ܹ���";

        for (int i = 0; i < strTemporary8.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << strTemporary8.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(6);
            cout << strTemporary8[i];
        }
        cout << endl;

        string strTemporary9 = "3. ʹ��ҩˮ�ظ�";

        for (int i = 0; i < strTemporary9.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << strTemporary9.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(6);
            cout << strTemporary9[i];
        }
        cout << endl;

        string strTemporary10 = "4. ����";

        for (int i = 0; i < strTemporary10.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << strTemporary10.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(6);
            cout << strTemporary10[i];
        }
        cout << endl;
        choose=getInt();

        switch (choose) {
        case 1: {
            ptrEnemy->setHP(ptrEnemy->getHP() - character.getATK()); // �����ܵ��˺�  
            cout << "��Թ�������� " << character.getATK() << " ���˺���" << endl;
            break;
        }
        case 2: 
            cout << "����ʹ���ĸ����ܣ�" << endl;

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
                    else
                        cout << "���ħ�����㣡" << endl;

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
        case 3: {  
            int potindex = 0;
            string strTemporary14 = "�������ĸ�ҩˮ?";

            for (int i = 0; i < strTemporary14.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << strTemporary14.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(6);
                cout << strTemporary14[i];
            }
            cout << endl;

            string strTemporary15 = "1.Ѫ��ҩˮ";

            for (int i = 0; i < strTemporary15.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << strTemporary15.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(6);
                cout << strTemporary15[i];
            }
            cout << endl;

            string strTemporary16 = "2.����ҩˮ";

            for (int i = 0; i < strTemporary16.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << strTemporary16.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(6);
                cout << strTemporary16[i];
            }
            cout << endl;
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
                            char key = _getch();  // ��ȡ���µļ�
                            if (key == '\r') {  // �ж��Ƿ��»س���
                                cout << strTemporary17.substr(i) << endl;  // ���ʣ�µ�ȫ������
                                break;
                            }
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
                            char key = _getch();  // ��ȡ���µļ�
                            if (key == '\r') {  // �ж��Ƿ��»س���
                                cout << strTemporary18.substr(i) << endl;  // ���ʣ�µ�ȫ������
                                break;
                            }
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
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
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
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
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
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << strTemporary21.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
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
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << strTemporary22.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
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