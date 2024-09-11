#include "stdafx.h"
#include "Menu.h"  

using namespace std;
void welcomePage();
void setColor(int);
void gameEndThankYou();
int getInt(int min, int max);   //从键盘获取int类型数据

// 自定义延迟输出函数，按下回车键后立即输出剩余的内容
void delayedPrintVector(const vector<string>& temporary, int delay = 0);
void delayedPrintString(const string temporary, int delay = 0);



//创建，读取，保存存档
void Menu::menu() {

    //存档在桌面上
    //获取桌面目录
    {
        char path[MAX_PATH];
        SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, path);
        strBase_adress = string(path) + "\\黑神话";
    }

    shared_ptr<Game> strGame = nullptr; // 初始化智能指针
    filesystem::create_directories(strBase_adress); // 创建游戏根目录（如果已经存在则无操作）

    int choice2 = 1;
    do {
        //打印首页
        system("cls");
        welcomePage();  //首页
        setColor(FOREGROUND_RED | FOREGROUND_GREEN);
        delayedPrintString("   1.新的游戏  2.读取存档  3.退出游戏\n\n   ●请选择：", 2);

        //功能选择
        int choice1 = getInt(1, 3);

        //case1:新存档
        switch (choice1) {
        case 1: {
            delayedPrintString("   ●请输入新存档名：", 2);


            cin >> strUsername;

            strUser_adress = strBase_adress + "\\" + strUsername;

            // 直接使用 shared_ptr 的 reset 方法  
            strGame.reset(); // 释放之前的实例  
            strGame = make_shared<Game>(); // 创建新的 Game 实例
            strGame->game();
            gameEndThankYou();

            //保存游戏存档
            if (strGame != nullptr) {
                filesystem::create_directories(strUser_adress); // 创建目录  
                ofstream ifs_a(strUser_adress + "\\basic.txt", ios::binary | ios::trunc);
                ifs_a.write(reinterpret_cast<char*>(&(strGame->character)), sizeof(Game)); // 保存用户基本信息  
                ifs_a.close();
            }

            break;

        }
        case 2: {   //读取存档
            strGame.reset(); // 释放之前的实例  
            strGame = make_shared<Game>(); // 创建新的 Game 实例
            int sum = 0;            //记录查找到的存档总数
            vector<string> str;     //记录存档名
            cout << endl;           //界面更美观

            //循环遍历文件夹，查找存档并记录
            for (const auto& entry : filesystem::recursive_directory_iterator(strBase_adress)) {
                if (entry.path().filename() == "basic.txt") {
                    cout << "   *" << ++sum << ": " << (entry.path().parent_path().filename().string()) << endl;
                    str.push_back(entry.path().parent_path().filename().string());
                }
            }

            //存档总数为0时
            if (sum == 0) {
                delayedPrintString("   没有找到存档或存档不存在…\n   ", 2);
                system("pause");
                continue;
            }

            delayedPrintString("   ●请选择所需存档(0 返回)：", 2);
           
            int m_choice = getInt(1, sum);

            if (m_choice == 0) continue;   //打开对应存档
            else {
                strUser_adress = strBase_adress + "\\" + str[m_choice - 1];
                ifstream ifs(strUser_adress + "\\basic.txt", ios::binary);
                ifs.read(reinterpret_cast<char*>(&(strGame->character)), sizeof(Role)); // 使用 get() 获取裸指针  
                ifs.close();
                strGame->game();
                gameEndThankYou();

                //保存游戏存档
                if (strGame != nullptr) {
                    filesystem::create_directories(strUser_adress); // 创建目录(若目录存在则无操作)  
                    ofstream ifs_a(strUser_adress + "\\basic.txt", ios::binary | ios::trunc);
                    ifs_a.write(reinterpret_cast<char*>(&(strGame->character)), sizeof(Game)); // 保存用户基本信息  
                    ifs_a.close();
                }

                break;
            }
        }
        case 3: {
            choice2 = 0; // 退出游戏  
            break;
        }
        }
    } while (choice2);
}