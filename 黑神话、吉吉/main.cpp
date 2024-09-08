#include <iostream>  
#include <iomanip>  
#include <string>  
#include <filesystem>  
#include <windows.h>  
#include <limits>  
#include"Menu.h"

using namespace std;

int getInt() {
	string x;
	while (true) {
		getline(cin, x); // 使用 getline 读取整行输入  
		bool valid = true;

		// 检查输入是否为有效的整数  
		if (x.empty() || (x[0] != '-' && !isdigit(x[0]))) {
			valid = false;
		}
		else {
			for (size_t i = 1; i < x.length(); ++i) {
				if (!isdigit(x[i])) {
					valid = false;
					break;
				}
			}
		}

		if (valid) {
			return stoi(x); // string to int  
		}
		else {
			cout << "Invalid input. Please enter a valid integer." << '\n';
		}
	}
}

void welcomePage()
{
	// 获取当前控制台句柄  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// 设置文本颜色为红色  
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

	//黑神话页面图
	vector<string> page = {
	"╭──────────────────────────────────────────────────────────────────────────────────╮",
	"│   HHHHHHHHHHHHHHHHHHH          S            SS                             HHHH  │",//1
	"│   H HH     H     HH H           S           SS                        HHHHH      │",//2
	"│   H  HH    H    HH  H       SSSSSSS         SS            HH      HHHH  HH       │",//3
	"│   H   HH   H   HH   H            S          SS             HH           HH       │",//4
	"│   HHHHHHHHHHHHHHHHHHH          S      SSSSSSSSSSSSSS        HH   HHHHHHHHHHHHHHH │",//5
	"│            H                 S  S     SS    SS    SS   HHHHHHH          HH       │",//6
	"│       HHHHHHHHHHH          S    S S   SSSSSSSSSSSSSS        HH          HH       │",//7
	"│            H                    S  S  SS    SS    SS        HH     HHHHHHHHHHHH  │",//8
	"│  HHHHHHHHHHHHHHHHHHHHH          S     SSSSSSSSSSSSSS        HH     HH        HH  │",//9
	"│                                 S           SS              HH HH  HH        HH  │",//10
	"│  HH   HH    HH      HH          S           SS              HHHH   HH        HH  │",//11
	"│HH       HH    HH      HH        S           SS               HH    HHHHHHHHHHHH  │",//12
	"│                                 S           SS                                   │",//13
	"╰──────────────────────────────────────────────────────────────────────────────────╯",
	};

	for (int i = 0; i < page.size(); i++) {
		Sleep(36);
		cout << page[i] << endl;
	}

	// 设置文本颜色为蓝色色  
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	cout << endl;
	string temporary49 = "╔═══════════════════════════════════════════════════════════════════════╗";
	for (int i = 0; i < temporary49.length(); i++) {
		Sleep(5);
		cout << temporary49[i];
	}

	cout << endl;
	string temporary50 = "║\t\t***中国海洋大学2024夏季学期c++课程设计***\t\t║";
	for (int i = 0; i < temporary50.length(); i++) {
		Sleep(25);
		cout << temporary50[i];
	}

	cout << endl;
	string temporary51 = "║ 文字版《黑神话·悟空》\t\t\t\t\t\t\t║";
	for (int i = 0; i < temporary51.length(); i++) {
		Sleep(25);
		cout << temporary51[i];
	}

	cout << endl;
	string temporary52 = "║ 游戏介绍：一个简单的文字RPG。\t\t\t\t\t\t║";
	for (int i = 0; i < temporary52.length(); i++) {
		Sleep(25);
		cout << temporary52[i];
	}

	cout << endl;
	string temporary53 = "║ 版本：1.0\t\t\t\t\t\t\t\t║";
	for (int i = 0; i < temporary53.length(); i++) {
		Sleep(25);
		cout << temporary53[i];
	}

	cout << endl;
	string temporary54 = "║ 作者: \t\t\t\t\t\t\t\t║";
	for (int i = 0; i < temporary54.length(); i++) {
		Sleep(25);
		cout << temporary54[i];
	}

	cout << endl;
	string temporary55 = "║ 邮箱: \t\t\t\t\t\t\t\t║";
	for (int i = 0; i < temporary55.length(); i++) {
		Sleep(25);
		cout << temporary55[i];
	}

	cout << endl;
	string temporary56 = "╚═══════════════════════════════════════════════════════════════════════╝";
	for (int i = 0; i < temporary56.length(); i++) {
		Sleep(5);
		cout << temporary56[i];
	}

	cout << endl;

	// 恢复默认的控制台文本颜色  
	//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

int main() {
	//welcomePage();//黑神话页面图

	Menu _menu;
	_menu.menu();
	return 0;
}