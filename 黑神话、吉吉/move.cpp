#include "stdafx.h"
#include "Map.h"
#include "Menu.h"

using namespace std;

// �Զ����ӳ�������������»س������������ʣ�������
void delayedPrintVector(const vector<string>& temporary, int delay = 0);
void delayedPrintString(const string temporary, int delay = 0);

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

    int newX = playerX = 2; //��¼��X����
    int newY = playerY = 1; //��¼��Y����
    
    displayMap(map);//��ͼ
    displayEnemy(map_s);//����
    displayP(newX, newY, map_s);//���λ��

    while (true) {
        int preY = playerY;//��¼��Y����
        int preX = playerX;//��¼��X����
        input = _getch(); // ��ȡ�û����룬����ʾ����Ļ��  
        int other_Exit = 0;
        // �����������λ��  

        switch (input) {
        case 'W':
        case 'w': newY--;
            break; // ��  
        case 'A':
        case 'a': newX--; 
            break; // ��  
        case 'S':
        case 's': newY++; 
            break; // ��  
        case 'D':
        case 'd': newX++; 
            break; // �� 
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
            return 0; // �˵� 
        default: 
            continue; // ����������Ч  
        }
        if (other_Exit == 1)
            continue;

        // �����λ�õ���Ч��  
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

                    newY = preY;
                    newX = preX;

                    break;
                case 1://���ܹ���
                    map_s[newY][newX] = ' ';//��������

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

                delayedPrintString("��ϲ��ͨ�����أ�\n", 6);

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
