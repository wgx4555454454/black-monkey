#include <iostream>  
#include <iomanip>  
#include <string>  
#include <filesystem>  
#include <windows.h>  
#include <memory> // 需要包含这个头文件以使用智能指针 
#include <shlobj.h>
#include "Menu.h"  

//存档在桌面上
using namespace std;

void Menu::menu() {

    //获取桌面目录
    {
        char path[MAX_PATH];
        SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, path);
        base_adress = string(path) + "\\黑神话";
    }

    shared_ptr<Game> game = nullptr; // 初始化智能指针
    filesystem::create_directories(base_adress); // 创建游戏根目录（如果已经存在则无操作）

    int choice2 = 1;
    do {
        //打印首页
        system("cls");
        void welcomePage();
        welcomePage();

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

        string newGameMenu = "   1.新的游戏  2.读取存档  3.退出游戏";
        for (int i = 0; i < newGameMenu.length(); i++) {
            Sleep(16);
            cout << newGameMenu[i];
        }

        string temporary1 = "\n\n   ●请选择：";
        for (int i = 0; i < temporary1.length(); i++) {
            Sleep(50);
            cout << temporary1[i];
        }

        //功能选择
        int choice1 = 0;
        cin >> choice1;
        while (choice1 != 1 && choice1 != 2 && choice1 != 3) {
            string temporary2 = "Error! 请输入 1-3 之间的数： ";
            for (int i = 0; i < temporary2.length(); i++) {
                Sleep(50);
                cout << temporary2[i];
            }
            cout << endl;
            cin >> choice1;
        }


        switch (choice1) {
        case 1: //新存档
        {
            string temporary3 = "   ●请输入新存档名：";
            for (int i = 0; i < temporary3.length(); i++) {
                Sleep(50);
                cout << temporary3[i];
            }
            cin >> username;
            user_adress = base_adress + "\\" + username;

            // 直接使用 shared_ptr 的 reset 方法  
            game.reset(); // 释放之前的实例  
            game = make_shared<Game>(); // 创建新的 Game 实例
            game->game();


            //保存游戏存档
            if (game != nullptr) {
                filesystem::create_directories(user_adress); // 创建目录  
                ofstream ifs_a(user_adress + "\\basic.txt", ios::binary | ios::trunc);
                ifs_a.write(reinterpret_cast<char*>(&(game->character)), sizeof(Game)); // 保存用户基本信息  
                ifs_a.close();
            }

            break;
        }
        case 2: {   //读取存档
            game.reset(); // 释放之前的实例  
            game = make_shared<Game>(); // 创建新的 Game 实例
            int sum = 0;            //记录查找到的存档总数
            vector<string> str;     //记录存档名
            cout << endl;           //界面更美观

            //循环遍历文件夹，查找存档并记录
            for (const auto& entry : filesystem::recursive_directory_iterator(base_adress))
            {
                if (entry.path().filename() == "basic.txt")
                {
                    cout << "   *" << ++sum << ": " << (entry.path().parent_path().filename().string()) << endl;
                    str.push_back(entry.path().parent_path().filename().string());
                }
            }

            //存档总数为0时
            if (sum == 0)
            {
                string temporary4 = "   没有找到存档或存档不存在…\n   ";
                for (int i = 0; i < temporary4.length(); i++) {
                    Sleep(50);
                    cout << temporary4[i];
                }
                system("pause");
                continue;
            }

            string temporary5 = "   ●请选择所需存档(0 返回)：";
            for (int i = 0; i < temporary5.length(); i++) {
                Sleep(50);
                cout << temporary5[i];
            }
            int m_choice = -1;
            cin >> m_choice;

            //防止出错
            while (m_choice<0 || m_choice>sum)
            {
                cout << "   请输入(0到" << sum << ")之间的数：";
                cin >> m_choice;
            }

            if (m_choice == 0) continue;
            else    //打开对应存档
            {
                user_adress = base_adress + "\\" + str[m_choice - 1];
                ifstream ifs(user_adress + "\\basic.txt", ios::binary);
                ifs.read(reinterpret_cast<char*>(&(game->character)), sizeof(Role)); // 使用 get() 获取裸指针  
                ifs.close();
                game->game();

                //保存游戏存档
                if (game != nullptr) {
                    filesystem::create_directories(user_adress); // 创建目录(若目录存在则无操作)  
                    ofstream ifs_a(user_adress + "\\basic.txt", ios::binary | ios::trunc);
                    ifs_a.write(reinterpret_cast<char*>(&(game->character)), sizeof(Game)); // 保存用户基本信息  
                    ifs_a.close();
                }

                break;
            }
        }
        case 3:
        {
            choice2 = 0; // 退出游戏  
            break;
        }
        }
    } while (choice2);
}