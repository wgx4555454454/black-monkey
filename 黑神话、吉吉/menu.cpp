#include "stdafx.h"
#include "Menu.h"  

using namespace std;
void welcomePage();
void setColor(int);
void gameEndThankYou();
int getInt(int min, int max);   //�Ӽ��̻�ȡint��������

// �Զ����ӳ�������������»س������������ʣ�������
void delayedPrintVector(const vector<string>& temporary, int delay = 0);
void delayedPrintString(const string temporary, int delay = 0);



//��������ȡ������浵
void Menu::menu() {

    //�浵��������
    //��ȡ����Ŀ¼
    {
        char path[MAX_PATH];
        SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, path);
        strBase_adress = string(path) + "\\����";
    }

    shared_ptr<Game> strGame = nullptr; // ��ʼ������ָ��
    filesystem::create_directories(strBase_adress); // ������Ϸ��Ŀ¼������Ѿ��������޲�����

    int choice2 = 1;
    do {
        //��ӡ��ҳ
        system("cls");
        welcomePage();  //��ҳ
        setColor(FOREGROUND_RED | FOREGROUND_GREEN);
        delayedPrintString("   1.�µ���Ϸ  2.��ȡ�浵  3.�˳���Ϸ\n\n   ����ѡ��", 2);

        //����ѡ��
        int choice1 = getInt(1, 3);

        //case1:�´浵
        switch (choice1) {
        case 1: {
            delayedPrintString("   ���������´浵����", 2);


            cin >> strUsername;

            strUser_adress = strBase_adress + "\\" + strUsername;

            // ֱ��ʹ�� shared_ptr �� reset ����  
            strGame.reset(); // �ͷ�֮ǰ��ʵ��  
            strGame = make_shared<Game>(); // �����µ� Game ʵ��
            strGame->game();
            gameEndThankYou();

            //������Ϸ�浵
            if (strGame != nullptr) {
                filesystem::create_directories(strUser_adress); // ����Ŀ¼  
                ofstream ifs_a(strUser_adress + "\\basic.txt", ios::binary | ios::trunc);
                ifs_a.write(reinterpret_cast<char*>(&(strGame->character)), sizeof(Game)); // �����û�������Ϣ  
                ifs_a.close();
            }

            break;

        }
        case 2: {   //��ȡ�浵
            strGame.reset(); // �ͷ�֮ǰ��ʵ��  
            strGame = make_shared<Game>(); // �����µ� Game ʵ��
            int sum = 0;            //��¼���ҵ��Ĵ浵����
            vector<string> str;     //��¼�浵��
            cout << endl;           //���������

            //ѭ�������ļ��У����Ҵ浵����¼
            for (const auto& entry : filesystem::recursive_directory_iterator(strBase_adress)) {
                if (entry.path().filename() == "basic.txt") {
                    cout << "   *" << ++sum << ": " << (entry.path().parent_path().filename().string()) << endl;
                    str.push_back(entry.path().parent_path().filename().string());
                }
            }

            //�浵����Ϊ0ʱ
            if (sum == 0) {
                delayedPrintString("   û���ҵ��浵��浵�����ڡ�\n   ", 2);
                system("pause");
                continue;
            }

            delayedPrintString("   ����ѡ������浵(0 ����)��", 2);
           
            int m_choice = getInt(1, sum);

            if (m_choice == 0) continue;   //�򿪶�Ӧ�浵
            else {
                strUser_adress = strBase_adress + "\\" + str[m_choice - 1];
                ifstream ifs(strUser_adress + "\\basic.txt", ios::binary);
                ifs.read(reinterpret_cast<char*>(&(strGame->character)), sizeof(Role)); // ʹ�� get() ��ȡ��ָ��  
                ifs.close();
                strGame->game();
                gameEndThankYou();

                //������Ϸ�浵
                if (strGame != nullptr) {
                    filesystem::create_directories(strUser_adress); // ����Ŀ¼(��Ŀ¼�������޲���)  
                    ofstream ifs_a(strUser_adress + "\\basic.txt", ios::binary | ios::trunc);
                    ifs_a.write(reinterpret_cast<char*>(&(strGame->character)), sizeof(Game)); // �����û�������Ϣ  
                    ifs_a.close();
                }

                break;
            }
        }
        case 3: {
            choice2 = 0; // �˳���Ϸ  
            break;
        }
        }
    } while (choice2);
}