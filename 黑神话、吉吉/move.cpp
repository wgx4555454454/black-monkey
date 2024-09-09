#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<iostream>
#include <windows.h>
#include "map.h"
#include"Menu.h"
#include <conio.h> // for _getch() on Windows  
#include <cstdlib> // for system()  
using namespace std;

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
    int newX = playerX; //记录X坐标
    int newY = playerY; //记录Y坐标
    displayMap(map);
    displayEnemy(map_s);
    displayP(newX, newY, map_s);
    while (true) {
        input = _getch(); // 获取用户输入，不显示在屏幕上  
        int other_Exit = 0;
        // 根据输入更新位置  
        switch (input) {
        case 'w': newY--;
            break; // 上  
        case 'a': newX--; 
            break; // 左  
        case 's': newY++; 
            break; // 下  
        case 'd': newX++; 
            break; // 右 
        case 'b':Buy();
            other_Exit = 1;
            break;
        case 'm':character.showBag();
            other_Exit = 1;
            break;
        case '0': return 0; // 菜单 
        default: continue; // 其他输入无效  
        }
        if (other_Exit == 1)
            break;
        // 检查新位置的有效性  
        int preY=playerY;
        int preX = playerX;
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
                    break;
                case 1://击败怪物
                    map_s[playerY][playerX] = ' ';//消除怪物
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
                string temporary36 = "恭喜你通过本关！";
                for (int i = 0; i < temporary36.length(); i++) {
                    // 如果检测到键盘按下
                    if (_kbhit()) {
                        char key = _getch();  // 获取按下的键
                        if (key == '\r') {  // 判断是否按下回车键
                            cout << temporary36.substr(i) << endl;  // 输出剩下的全部内容
                            break;
                        }
                    }
                    Sleep(50);
                    cout << temporary36[i];
                }
                cout << endl;
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
