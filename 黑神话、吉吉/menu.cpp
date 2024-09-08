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

void Menu::menu() {

    //��ȡ����Ŀ¼
    {
        char path[MAX_PATH];
        SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, path);
        base_adress = string(path) + "\\����";
    }

    shared_ptr<Game> game = nullptr; // ��ʼ������ָ��
    filesystem::create_directories(base_adress); // ������Ϸ��Ŀ¼������Ѿ��������޲�����

    int choice2 = 1;
    do {
        //��ӡ��ҳ
        system("cls");
        void welcomePage();
        welcomePage();

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

        string newGameMenu = "   1.�µ���Ϸ  2.��ȡ�浵  3.�˳���Ϸ";
        for (int i = 0; i < newGameMenu.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << newGameMenu.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(2);
            cout << newGameMenu[i];
        }

        string temporary1 = "\n\n   ����ѡ��";
        for (int i = 0; i < temporary1.length(); i++) {
            // �����⵽���̰���
            if (_kbhit()) {
                char key = _getch();  // ��ȡ���µļ�
                if (key == '\r') {  // �ж��Ƿ��»س���
                    cout << temporary1.substr(i) << endl;  // ���ʣ�µ�ȫ������
                    break;
                }
            }
            Sleep(2);
            cout << temporary1[i];
        }

        //����ѡ��
        int choice1 = 0;
        cin >> choice1;
        while (choice1 != 1 && choice1 != 2 && choice1 != 3) {
            string temporary2 = "Error! ������ 1-3 ֮������� ";
            for (int i = 0; i < temporary2.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << temporary2.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(2);
                cout << temporary2[i];
            }
            cout << endl;
            cin >> choice1;
        }

        //case1:�´浵
        switch (choice1) {
        case 1:{
            string temporary3 = "   ���������´浵����";
            for (int i = 0; i < temporary3.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << temporary3.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(2);
                cout << temporary3[i];
            }
            cin >> username;
            user_adress = base_adress + "\\" + username;

            // ֱ��ʹ�� shared_ptr �� reset ����  
            game.reset(); // �ͷ�֮ǰ��ʵ��  
            game = make_shared<Game>(); // �����µ� Game ʵ��
            game->game();


            //������Ϸ�浵
            if (game != nullptr) {
                filesystem::create_directories(user_adress); // ����Ŀ¼  
                ofstream ifs_a(user_adress + "\\basic.txt", ios::binary | ios::trunc);
                ifs_a.write(reinterpret_cast<char*>(&(game->character)), sizeof(Game)); // �����û�������Ϣ  
                ifs_a.close();
            }

            break;
        }
        case 2: {   //��ȡ�浵
            game.reset(); // �ͷ�֮ǰ��ʵ��  
            game = make_shared<Game>(); // �����µ� Game ʵ��
            int sum = 0;            //��¼���ҵ��Ĵ浵����
            vector<string> str;     //��¼�浵��
            cout << endl;           //���������

            //ѭ�������ļ��У����Ҵ浵����¼
            for (const auto& entry : filesystem::recursive_directory_iterator(base_adress)){
                if (entry.path().filename() == "basic.txt"){
                    cout << "   *" << ++sum << ": " << (entry.path().parent_path().filename().string()) << endl;
                    str.push_back(entry.path().parent_path().filename().string());
                }
            }

            //�浵����Ϊ0ʱ
            if (sum == 0){
                string temporary4 = "   û���ҵ��浵��浵�����ڡ�\n   ";
                for (int i = 0; i < temporary4.length(); i++) {
                    // �����⵽���̰���
                    if (_kbhit()) {
                        char key = _getch();  // ��ȡ���µļ�
                        if (key == '\r') {  // �ж��Ƿ��»س���
                            cout << temporary4.substr(i) << endl;  // ���ʣ�µ�ȫ������
                            break;
                        }
                    }
                    Sleep(2);
                    cout << temporary4[i];
                }
                system("pause");
                continue;
            }

            string temporary5 = "   ����ѡ������浵(0 ����)��";
            for (int i = 0; i < temporary5.length(); i++) {
                // �����⵽���̰���
                if (_kbhit()) {
                    char key = _getch();  // ��ȡ���µļ�
                    if (key == '\r') {  // �ж��Ƿ��»س���
                        cout << temporary5.substr(i) << endl;  // ���ʣ�µ�ȫ������
                        break;
                    }
                }
                Sleep(2);
                cout << temporary5[i];
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
                user_adress = base_adress + "\\" + str[m_choice - 1];
                ifstream ifs(user_adress + "\\basic.txt", ios::binary);
                ifs.read(reinterpret_cast<char*>(&(game->character)), sizeof(Role)); // ʹ�� get() ��ȡ��ָ��  
                ifs.close();
                game->game();

                //������Ϸ�浵
                if (game != nullptr) {
                    filesystem::create_directories(user_adress); // ����Ŀ¼(��Ŀ¼�������޲���)  
                    ofstream ifs_a(user_adress + "\\basic.txt", ios::binary | ios::trunc);
                    ifs_a.write(reinterpret_cast<char*>(&(game->character)), sizeof(Game)); // �����û�������Ϣ  
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