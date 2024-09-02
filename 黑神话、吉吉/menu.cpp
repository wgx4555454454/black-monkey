#include <iostream>  
#include <iomanip>  
#include <string>  
#include <filesystem>  
#include <windows.h>  
#include <memory> // 需要包含这个头文件以使用智能指针  
#include "Menu.h"  

using namespace std;

void Menu::menu() {
    int choice2 = 1;
    string newGameMenu = "   1.新的游戏  2.读取存档  3.退出游戏";
    for (int i = 0; i < newGameMenu.length(); i++) {
        Sleep(50);
        cout << newGameMenu[i];
    }
    cout << endl << endl << '\t' << '\t' << '\t' << '\t' << "   ";

    // 使用智能指针  
    shared_ptr<Game> game = nullptr; // 初始化智能指针  

    do {
        int choice1 = 0;
        cin >> choice1;
        while (choice1 != 1 && choice1 != 2 && choice1 != 3) {
            cout << "Error! Please enter 1-3" << endl;
            cin >> choice1;
        }
        switch (choice1) {
        case 1:
            cout << "Please register your username:";
            cin >> username;
            user_adress = base_adress + "\\user\\" + username + "\\basic.txt";

            // 直接使用 shared_ptr 的 reset 方法  
            game = make_shared<Game>(); // 创建新的 Game 实例  
            game->game();
            break;

        case 2: {
            cout << "Please enter your username:";
            cin >> username;
            user_adress = base_adress + "\\user\\" + username + "\\basic.txt";

            // 创建新的 Game 实例  
            game = make_shared<Game>();

            ifstream ifs(user_adress, ios::binary);
            ifs.read(reinterpret_cast<char*>(game.get()), sizeof(Game)); // 使用 get() 获取裸指针  
            ifs.close();
            game->game();
            break;
        }
        case 3:
            if (game != nullptr) {
                filesystem::create_directories(user_adress); // 创建用户目录  
                ofstream ifs_a(user_adress, ios::binary | ios::trunc);
                ifs_a.write(reinterpret_cast<char*>(game.get()), sizeof(Game)); // 保存用户基本信息  
                ifs_a.close();
                choice2 = 0; // 退出游戏  
            }
        }
    } while (choice2);
}