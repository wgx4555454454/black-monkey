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

// ��ӡ��ͼ  
void displayMap(vector<string> map) {
    system("cls"); // ����  
    for (const string& str : map) {
        cout << str << endl; // ��ӡÿ���ַ���  
    }
    cout << "w a s d�ƶ�  0 �˵�  b �̵�  m ����" << endl;
}

// ��ӡ����
void displayEnemy(vector<string> map_2) {
    int EnemyX = 0;
    int EnemyY = 0;
    for (const string& str : map_2) {
        EnemyX = str.find('@'); // ���ҵ�һ��@�ַ���λ��
        while (EnemyX != string::npos) {
            moveCursor(EnemyX, EnemyY); 
            cout << '@';
            EnemyX = str.find('@', EnemyX + 1); // ������һ��@�ַ�
        }
        EnemyY++;
    }
}

// ��ӡ��������λ��
void displayP(int X,int Y,vector<string> map_s)
{   
    moveCursor(playerX, playerY); // �ƶ���굽���λ��  
    cout << map_s[playerY][playerX];
    moveCursor(X, Y);
    cout << 'P'; // ������ʾ���λ��Ϊ P
}

// ������  
int Game::move(vector<string> map, vector<string> map_s) {
    int ending_Attack = 0;
    char input;
    int newX = playerX; //��¼X����
    int newY = playerY; //��¼Y����
    displayMap(map);
    displayEnemy(map_s);
    displayP(newX, newY, map_s);
    while (true) {
        input = _getch(); // ��ȡ�û����룬����ʾ����Ļ��  
        int other_Exit = 0;
        // �����������λ��  
        switch (input) {
        case 'w': newY--;
            break; // ��  
        case 'a': newX--; 
            break; // ��  
        case 's': newY++; 
            break; // ��  
        case 'd': newX++; 
            break; // �� 
        case 'b':Buy();
            other_Exit = 1;
            break;
        case 'm':character.showBag();
            other_Exit = 1;
            break;
        case '0': return 0; // �˵� 
        default: continue; // ����������Ч  
        }
        if (other_Exit == 1)
            break;
        // �����λ�õ���Ч��  
        int preY=playerY;
        int preX = playerX;
        if (map_s[newY][newX] != '+') {
            displayP(newX, newY,map_s);
            playerX = newX;
            playerY = newY;
            // ����Ƿ���@��ײ  
            if (map_s[newY][newX] == '@') {
                system("cls");
                switch(attack()){
                case 0://����
                    playerX = preX;
                    playerY = preY;
                    break;
                case 1://���ܹ���
                    map_s[playerY][playerX] = ' ';//��������
                    character.setCoins(character.getCoins() + 5);
                    break;
                case 2:
                    return 2;//��ɫ������
                }
                displayMap(map);
                displayEnemy(map_s);
                displayP(playerX, playerY, map_s);
            }
            // ����Ƿ���*��ײ  
            if (map_s[newY][newX] == '*') {
                system("cls");
                string temporary36 = "��ϲ��ͨ�����أ�";
                for (int i = 0; i < temporary36.length(); i++) {
                    // �����⵽���̰���
                    if (_kbhit()) {
                        char key = _getch();  // ��ȡ���µļ�
                        if (key == '\r') {  // �ж��Ƿ��»س���
                            cout << temporary36.substr(i) << endl;  // ���ʣ�µ�ȫ������
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
                return 1; // ͨ����Ϸ  
            }
        }
        else {
            newX = playerX;
            newY = playerY;
        }
        continue;
    }
}
