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

// ���ն����ƶ����  
void moveCursor(int x, int y) {
    cout << "\033[" << (y + 1) << ";" << (x + 1) << "H"; // ������Ϊ�����ƶ����  
}

// ��ʾ��ͼ  
void displayMap(vector<string> map) {
    system("cls"); // ����  
    for (const string& str : map) {
        cout << str << endl; // ��ӡÿ���ַ���  
    }
    moveCursor(playerX, playerY); // �ƶ���굽���λ��  
    cout << 'P'; // ������ʾ���λ��Ϊ P  
}

// ������  
int Game::move(vector<string> map) {
    char input;
    while (true) {
        displayMap(map);
        input = _getch(); // ��ȡ�û����룬����ʾ����Ļ��  

        int newX = playerX;
        int newY = playerY;

        // �����������λ��  
        switch (input) {
        case 'w': newY--; break; // ��  
        case 'a': newX--; break; // ��  
        case 's': newY++; break; // ��  
        case 'd': newX++; break; // ��  
        case '0': return 0; // �˳�  
        default: continue; // ����������Ч  
        }

        // �����λ�õ���Ч��  
        if (newX >= 0 && newX < 67 && newY >= 0 && newY < 30) {
            if (map[newY][newX] != '-' && map[newY][newX] != '|') {
                playerX = newX;
                playerY = newY;

                // ����Ƿ���@��ײ  
                if (map[playerY][playerX] == '@') {
                    system("cls");
                    attack(); // ���ù�������  
                }

                // ����Ƿ���!��ײ  
                if (map[playerY][playerX] == '!') {
                    system("cls");
                    cout << "Succeed!" << endl;
                    return 1; // ͨ����Ϸ  
                }
            }
        }
        continue;
    }
}
