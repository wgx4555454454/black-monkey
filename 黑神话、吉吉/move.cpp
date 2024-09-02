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

// 显示地图  
void displayMap(vector<string> map) {
    system("cls"); // 清屏  
    for (const string& str : map) {
        cout << str << endl; // 打印每个字符串  
    }
    moveCursor(playerX, playerY); // 移动光标到玩家位置  
    cout << 'P'; // 这里显示玩家位置为 P  
}

// 主函数  
int Game::move(vector<string> map) {
    char input;
    while (true) {
        displayMap(map);
        input = _getch(); // 获取用户输入，不显示在屏幕上  

        int newX = playerX;
        int newY = playerY;

        // 根据输入更新位置  
        switch (input) {
        case 'w': newY--; break; // 上  
        case 'a': newX--; break; // 左  
        case 's': newY++; break; // 下  
        case 'd': newX++; break; // 右  
        case '0': return 0; // 退出  
        default: continue; // 其他输入无效  
        }

        // 检查新位置的有效性  
        if (newX >= 0 && newX < 67 && newY >= 0 && newY < 20) {
            if (map[newY][newX] != '-' && map[newY][newX] != '|') {
                playerX = newX;
                playerY = newY;

                // 检查是否与@碰撞  
                if (map[playerY][playerX] == '@') {
                    system("cls");
                    attack(); // 调用攻击函数  
                }

                // 检查是否与!碰撞  
                if (map[playerY][playerX] == '!') {
                    system("cls");
                    cout << "Succeed!" << endl;
                    return 1; // 通过游戏  
                }
            }
        }
        continue;
    }
}
