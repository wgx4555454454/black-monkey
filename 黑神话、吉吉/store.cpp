#include "stdafx.h"
#include "Menu.h"
using namespace std;

int getInt(int min,int max);//�Ӽ��̻�ȡint��������

// �Զ����ӳ�������������»س������������ʣ�������
void delayedPrintVector(const vector<string>& temporary, int delay = 0);
void delayedPrintString(string temporary, int delay = 0);
//������ɫ
void setColor(int);

void Store::showStore() {
    vector<string> outputs = {
        "---------------------------\n",
        "�̵�\n",
        "1.Ѫ��ҩˮ          �۸�: " + to_string(Hpotion) + "\n",
        "2.ħ��ҩˮ          �۸�: " + to_string(Mpotion) + "\n",
        "3.����ն            �۸�: " + to_string(skills.price[0]) + "\n",
        "4.��˪����          �۸�: " + to_string(skills.price[1]) + "\n",
        "---------------------------"
    };

    delayedPrintVector(outputs, 2);  // ͳһ���
}

void Game::Buy() {
    int symbolTHING = 0;

    do {
        system("cls");
        delayedPrintString("ʣ���ң�" + to_string(character.getCoins()) + "\n");

        store.showStore();

        delayedPrintString("\n����������Ҫ��������(0�˳�)��");

        symbolTHING = getInt(0, 4);

        switch (symbolTHING) {
        case 1:
            if (character.getCoins() < store.Hpotion) {
                delayedPrintString("��Ľ�Ҳ�����\n");
            }
            else {
                delayedPrintString("����ɹ�!!!\n");
                character.setCoins(character.getCoins() - store.Hpotion);
                character.setHpotionNum(character.getHpotionNum() + 1);
            }
            system("pause");
            break;

        case 2:
            if (character.getCoins() < store.Mpotion) {
                delayedPrintString("��Ľ�Ҳ�����\n");
            }
            else {
                delayedPrintString("����ɹ�\n");
                character.setCoins(character.getCoins() - store.Mpotion);
                character.setMpotionNum(character.getMpotionNum() + 1);
            }
            system("pause");
            break;

        case 3:
            if (character.get_Flame_Slash()) {
                delayedPrintString("���Ѿ�����������ն\n");
            }
            else if (character.getCoins() < store.skills.price[0]) {
                delayedPrintString("��Ľ�Ҳ�����\n");
            }
            else {
                delayedPrintString("�ɹ�����!!!\n��ɹ������� " + store.skills.strSkillname[0] + "\n");
                character.setCoins(character.getCoins() - store.skills.price[0]);
                character.set_Flame_Slash_true();
            }
            system("pause");
            break;

        case 4:
            if (character.get_Frost_Piercing()) {
                delayedPrintString("���Ѿ������˱�˪����\n");
            }
            else if (character.getCoins() < store.skills.price[1]) {
                delayedPrintString("��Ľ�Ҳ���\n");
            }
            else {
                delayedPrintString("�ɹ�����!!!\n��ɹ������� " + store.skills.strSkillname[1] + "\n");
                character.setCoins(character.getCoins() - store.skills.price[1]);
                character.set_Frost_Piercing_true();
            }
            system("pause");
            break;
        }
    } while (symbolTHING != 0);
}
