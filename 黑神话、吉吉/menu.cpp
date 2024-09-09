#include <iostream>  
#include <iomanip>  
#include <string>  
#include <filesystem>  
#include <windows.h>  
#include <conio.h>
#include <memory> // ��Ҫ�������ͷ�ļ���ʹ������ָ�� 
#include <shlobj.h>
#include "Menu.h"  

//�浵��������
using namespace std;
void setColor(int);
void gameEndThankYou();

void Menu::menu() {

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
        void welcomePage();
        welcomePage();

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

        string strNewGameMenu = "   1.�µ���Ϸ  2.��ȡ�浵  3.�˳���Ϸ";

        for (int i = 0; i < strNewGameMenu.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << strNewGameMenu.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(2);
            cout << strNewGameMenu[i];
        }

        string strTemporary1 = "\n\n   ����ѡ��";

        for (int i = 0; i < strTemporary1.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << strTemporary1.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(2);
            cout << strTemporary1[i];
        }

        //����ѡ��
        int choice1 = 0;
        cin >> choice1;

        while (choice1 != 1 && choice1 != 2 && choice1 != 3) {
            string strTemporary2 = "Error! ������ 1-3 ֮������� ";
            for (int i = 0; i < strTemporary2.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << strTemporary2.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(2);
                cout << strTemporary2[i];
            }

            cout << endl;
            cin >> choice1;
        }

        //case1:�´浵
        switch (choice1) {
        case 1:{
            string strTemporary3 = "   ���������´浵����";

            for (int i = 0; i < strTemporary3.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << strTemporary3.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(2);
                cout << strTemporary3[i];
            }

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
            for (const auto& entry : filesystem::recursive_directory_iterator(strBase_adress)){
                if (entry.path().filename() == "basic.txt"){
                    cout << "   *" << ++sum << ": " << (entry.path().parent_path().filename().string()) << endl;
                    str.push_back(entry.path().parent_path().filename().string());
                }
            }

            //�浵����Ϊ0ʱ
            if (sum == 0){
                string strTemporary4 = "   û���ҵ��浵��浵�����ڡ�\n   ";
                for (int i = 0; i < strTemporary4.length(); i++) {
                    // �����⵽���̰���
                    if (_kbhit()) {
                        char key = _getch();  // ��ȡ���µļ�
                        if (key == '\r') {  // �ж��Ƿ��»س���
                            cout << strTemporary4.substr(i) << endl;  // ���ʣ�µ�ȫ������
                            break;
                        }
                    }
                    Sleep(2);
                    cout << strTemporary4[i];
                }
                system("pause");
                continue;
            }

            string strTemporary5 = "   ����ѡ������浵(0 ����)��";
            for (int i = 0; i < strTemporary5.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << strTemporary5.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(2);
                cout << strTemporary5[i];
            }
            int m_choice = -1;
            cin >> m_choice;

            //��ֹ����
            while (m_choice<0 || m_choice>sum){
                cout << "   ������(0��" << sum << ")֮�������";
                cin >> m_choice;
            }

            if (m_choice == 0) continue;   //�򿪶�Ӧ�浵
            else{
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
        case 3:{
            choice2 = 0; // �˳���Ϸ  
            break;
        }
        }
    } while (choice2);
}