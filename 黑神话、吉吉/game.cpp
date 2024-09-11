#include "stdafx.h"
#include "Menu.h"

using namespace std;
int getInt(int min,int max);    //�Ӽ��̻�ȡint��������

// �Զ����ӳ�������������»س������������ʣ�������
void delayedPrintVector(const vector<string>& temporary, int delay = 0);
void delayedPrintString(const string temporary, int delay = 0);

void Game::game() {
    system("pause");
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

    delayedPrintString("��ӭ�������� \n����һ���򵥵�RPG��Ϸ\n\n", 16);

    showBeginPlot();//�������
    cout << endl;

    system("pause");//��������ʼ�����ͼ�������ƶ�
    int ending = 0;//ĳһ�ŵ�ͼ�Ľ�֣�1Ϊͨ����0Ϊ�˳���2Ϊʧ��
    int characterLive = 1;//��ɫ���ţ�0Ϊ����
    int chooseC = 0;//�ϵ�ģʽ�ı��

    //��ȡ�ؿ�
    int passes = character.getPasses();
    while (passes < 3 && chooseC == 0) {
        system("cls");
        switch (passes) {
        case 0:
            delayedPrintString("��һ�أ�\n", 16);
            system("pause");
            ending = move(map.getMap1(), map.getMap1_s());//��ȡͨ��״̬
            break;
        case 1:
            delayedPrintString("�ڶ��أ�\n", 16);
            system("pause");
            ending = move(map.getMap2(), map.getMap2_s());//��ȡͨ��״̬
            break;
        case 2:
            delayedPrintString("�����أ�\n", 16);
            system("pause");
            ending = move(map.getMap3(), map.getMap3_s());//��ȡͨ��״̬
            break;
        }

        //ͨ��״̬
        if (ending == 1) {
            passes++;
        }
        else if (ending == 0) {
            chooseC = 1;    //�������ϵ�ģʽ
        }
        else if (ending == 2) {
            characterLive = 0;  //��ɫ����
        }


        //�ϵ�ģʽ�е�ѡ��
        if (chooseC == 1) {
            system("cls");
            delayedPrintString("1.����  2.���沢�˳�  3.��һ��  ", 16);
            int choose_C = getInt(1, 3); //��ȡѡ��

            switch (choose_C) {
            case 1:
                chooseC = 0;
                break;
            case 2:
                character.setPasses(passes);
                return;
            case 3:
                chooseC = 0;
                passes++;
                break;
            default:
                delayedPrintString("Error!", 16);
                break;
            }
        }

        //��ɫ����
        if (characterLive == 0) {
            system("cls");
            delayedPrintString("��ɫ��������", 16);
            delayedPrintString("1.�˳�  2.��ͷ��ʼ", 16);

            int choose_Character = getInt(1, 2);//��ȡ�û�ѡ��
            switch (choose_Character) {
            case 1:
                character.setHP(100);
                character.setMP(35);
                characterLive = 1;
                return;
            case 2:
                character.setHP(100);
                character.setMP(35);
                characterLive = 1;
                passes = 0;
                break;
            default:
                cout << "Error!" << endl;
                break;
            }
        }
        character.setPasses(passes);
    }

    system("cls");
    showFinalPlot();    //չʾ����ҳ��
    system("pause");
}

void Game::showBeginPlot() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    delayedPrintString("����վܾ��˷������⡰��սʤ�𡱵�����ְλ��ѡ��ص�����ɽ��ƽ\n"
        "�����������ϱ��ذ��ɴ��У�������ͥ������Ϊ����ɽ����ı��ذ��ɲ�̫����ò\n"
        "��Ҫԭ������Ϊ����ժ�˽�����������ѹ��������\n"
        "���Ǳ���ǲʮ��������Ĵ������Լ����������\n"
        "����������ɽ�ĺ��Ӻ���İ�Σ��ҪЮ����գ������ȥ������\n"
        "����պò����װ����������϶���Ը��ȥ����ͥ������\n"
        "��������������콫��Ȼ�ǲ����������һԾ���������������������콫���Ҫ����ս��е���\n"
        "�Դ�һ����ս��ʽչ��\n", 16);
}

void Game::showFinalPlot() {
    delayedPrintString("��ʵ��յġ��⡱���Ѳ��٣�����������������һ�̾���֮��ɢ\n"
        "��������ղ������������ϵĸ����ˣ�����ػ�����ѡ��һ������գ�Ҳ����������\n"
        "���Գ�Ϊ��յġ��⡱�����Գ�Ϊ��һ�������\n"
        "��Ϊ����Ϊ�����ˣ���������֮��\n"
        "�������������ѣ���������������Ҳ��˿���͹����Ϊ�������\n", 16);
}

void Game::setEnemy() {
    vector<string> strWords1 = {
        "���Ǻ�ඣ�������ֻ��ͨ���ӣ������й��ĺ��ӣ��Ƿ����λ�ĺ��ӣ�\n"
        "����ֻ����������һս�����ﰡ����ұ���������һս�������ɣ�\n"
        "һ�������ǰ��ˣ��Ҵ���ػ���ɽ�����ǣ����������ƽ����ɽ��\n"
        "���������ˣ��Ҷ�Ȼ������ݣ�����������ƽ����ɽ������Ϳ̿����\n"
        "�ô�Ҳͬ��һ�����治���Ҫ�������ڹ����ϸ������¾�������ȥ����Σ�",
        "�ɶ��һ����ٻ�����",
        "������Ļ���ɽ��!"
    };
    enemy[0] = Enemy(150, 15, "���", strWords1);

    vector<string> strWords2 = {
        "���ߺ��ˣ������˴��������ޣ��ţ�����ֻ���ӣ�ʩ��������¹���������ѧ�·𷨣���Σ�",
        "�����ˣ��������Ӯ��",
        "���ޱߣ�������Ե"
    };
    enemy[1] = Enemy(120, 6, "����", strWords2);

    vector<string> strWords3 = {
        "Сɮ���Ź�ı��"
        "��С���������֣��鷳���Ҵ��仰��ʦ��."
        "���۷�������������ɹ�."
        "���ٰ�ݣ�����֪�ǳ���·",
        "ʩ�����ִ�����������ʦ�����кηֱ�",
        "�˼���ٻ�������ֶ���һ��"
    };
    enemy[2] = Enemy(130, 8, "��ı", strWords3);

    vector<string> strWords4 = {
        "������⣬���߲����ɣ������̿�׷��\n"
        "Сʦ������ɫ����������������֮�ش�ɱ�䣬�����Ǻξ���",
        "������Ժ����û�ˣ����ǳ��ϵ�ԩ��û��ɢ",
        "����ƥ��֮�°���"
    };
    enemy[3] = Enemy(200, 16, "������ʿ", strWords4);

    vector<string> strWords5 = {
        "�����ӷ������ں�����������\n"
        "ͽ���ǣ������������ү�����ˣ����Ҵ��±�����\n"
        "�ҿ�������ò���������ŵ��ǹ�ɧζ��Ī�����㣬�������\n"
        "������������Ĳ������ˣ��컹���ң�",
        "�ҽ���270��\n"
        "�����˼��ټ�����\n"
        "��ô��������һ����\n"
        "�������Ҳ�Ҫ�ˣ��������Ҳ�Ҫ�ˣ�����������~",
        "��������������ģ���������֪�ҳ�Ե�Ѷϣ��𺣾���"
    };
    enemy[4] = Enemy(200, 7, "��س���", strWords5);

    vector<string> strWords6 = {
        "������ˣ����ؽ��˹�����Ժ����ģ��֮ǰ�ĸ���\n"
        "��Щ����𺣵�ɮ�ڣ���Ϊ�»�Ұ������ڷ�ɽ���ε�\n"
        "���ң����ֽ�����һһ����\n"
        "��������������֪������һ�죬�㻹�ǻ���������",
        "����ȷŹ��㣬���Ǻ��滹���ټ���!",
        "�龪һ������"
    };
    enemy[5] = Enemy(170, 9, "�ڷ����", strWords6);

    vector<string> strWords7 = {
        "�Ǽһ���������˵���۲������Ĳ���\n"
        "Ѱ����Ϊ����һ���࣬��һ���࣬��������\n"
        "�������Լ�������Щ�����󣬲�Ҳ������?",
        "���ձ������Ȳ��������",
        "����ʲô��������������̰��\n"
        "��ȡ�ҵı������㻹����"
    };
    enemy[6] = Enemy(100, 10, "���ܾ�", strWords7);
}
