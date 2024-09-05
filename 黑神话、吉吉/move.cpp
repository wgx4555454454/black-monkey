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
    vector<string> Map = map;
    int ending_Attack = 0;
    char input;
    while (true) {
        displayMap(Map);
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
            if (Map[newY][newX] != '-' && Map[newY][newX] != '|') {
                playerX = newX;
                playerY = newY;

                // ����Ƿ���@��ײ  
                if (Map[playerY][playerX] == '@') {
                    system("cls");
                    ending_Attack = attack();
                    if (ending_Attack == 0)//����
                        continue;
                    if (ending_Attack == 1)//���ܹ���
                        Map[playerY][playerX] = ' ';//��������
                    if(ending_Attack == 2)
                        return 2;//��ɫ������
                }

                // ����Ƿ���!��ײ  
                if (Map[playerY][playerX] == '!') {
                    system("cls");
                    cout << "Succeed!" << endl;
                    return 1; // ͨ����Ϸ  
                }
            }
        }
        continue;
    }
}
