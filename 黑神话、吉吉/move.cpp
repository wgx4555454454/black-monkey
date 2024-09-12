#include "stdafx.h"
#include "Map.h"
#include "Menu.h"

using namespace std;

// 自定义延迟输出函数，按下回车键后立即输出剩余的内容
void delayedPrintVector(const vector<string>& temporary, int delay = 0);
void delayedPrintString(const string temporary, int delay = 0);

int playerX = 2;
int playerY = 1;

// 在终端上移动光标  
void moveCursor(int x, int y) {
    cout << "\033[" << (y + 1) << ";" << (x + 1) << "H"; // 以行列为基础移动光标  
}

// 打印地图  
void displayMap(vector<string> map) {
    system("cls"); // 清屏 

    for (const string& str : map) {
        cout << str << endl; // 打印每个字符串  
    }

    cout << "w a s d移动  0 菜单  b 商店  m 背包" << endl;
}

// 打印敌人
void displayEnemy(vector<string> map_2) {
    int EnemyX = 0;
    int EnemyY = 0;

    for (const string& str : map_2) {
        EnemyX = str.find('@'); // 查找第一个@字符的位置
        while (EnemyX != string::npos) {
            moveCursor(EnemyX, EnemyY); 
            cout << '@';
            EnemyX = str.find('@', EnemyX + 1); // 查找下一个@字符
        }
        EnemyY++;
    }
}

// 打印与更新玩家位置
void displayP(int X,int Y,vector<string> map_s)
{   
    moveCursor(playerX, playerY); // 移动光标到玩家位置  

    cout << map_s[playerY][playerX];

    moveCursor(X, Y);

    cout << 'P'; // 这里显示玩家位置为 P
}

// 主函数  
int Game::move(vector<string> map, vector<string> map_s) {
    int ending_Attack = 0;
    
    char input;

    int newX = playerX = 2; //记录新X坐标
    int newY = playerY = 1; //记录新Y坐标
    
    displayMap(map);//地图
    displayEnemy(map_s);//敌人
    displayP(newX, newY, map_s);//玩家位置

    while (true) {
        int preY = playerY;//记录旧Y坐标
        int preX = playerX;//记录旧X坐标
        input = _getch(); // 获取用户输入，不显示在屏幕上  
        int other_Exit = 0;
        // 根据输入更新位置  

        switch (input) {
        case 'W':
        case 'w': newY--;
            break; // 上  
        case 'A':
        case 'a': newX--; 
            break; // 左  
        case 'S':
        case 's': newY++; 
            break; // 下  
        case 'D':
        case 'd': newX++; 
            break; // 右 
        case 'B':
        case 'b':Buy();
            displayMap(map);
            displayEnemy(map_s);
            displayP(playerX, playerY, map_s);

            other_Exit = 1;
            break;
        case 'M':
        case 'm':character.showBag();
            displayMap(map);
            displayEnemy(map_s);
            displayP(playerX, playerY, map_s);

            other_Exit = 1;
            break;
        case '0': 
            return 0; // 菜单 
        default: 
            continue; // 其他输入无效  
        }
        if (other_Exit == 1)
            continue;

        // 检查新位置的有效性  
        if (map_s[newY][newX] != '+') {
            displayP(newX, newY,map_s);
            playerX = newX;
            playerY = newY;

            // 检查是否与@碰撞  
            if (map_s[newY][newX] == '@') {
                system("cls");
                switch(attack()){
                case 0://逃跑
                    playerX = preX;
                    playerY = preY;

                    newY = preY;
                    newX = preX;

                    break;
                case 1://击败怪物
                    map_s[newY][newX] = ' ';//消除怪物

                    character.setCoins(character.getCoins() + 5);

                    break;
                case 2:
                    return 2;//角色已死亡
                }
                displayMap(map);
                displayEnemy(map_s);
                displayP(playerX, playerY, map_s);
            }
            // 检查是否与*碰撞  
            if (map_s[newY][newX] == '*') {
                system("cls");

                delayedPrintString("恭喜你通过本关！\n", 6);

                playerX = 2;
                playerY = 1;

                system("pause");

                return 1; // 通过游戏  
            }

        }
        else {
            newX = playerX;
            newY = playerY;
        }
        continue;
    }
}
