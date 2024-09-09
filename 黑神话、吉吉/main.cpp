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

	// 设置文本颜色为绿色  
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	cout << endl;
	string temporary49 = "╔═══════════════════════════════════════════════════════════════════════╗";
	for (int i = 0; i < temporary49.length(); i++) {
		Sleep(0);
		cout << temporary49[i];
	}

	cout << endl;
	string temporary50 = "║\t\t***中国海洋大学2024夏季学期c++课程设计***\t\t║";
	for (int i = 0; i < temporary50.length(); i++) {
		Sleep(0);
		cout << temporary50[i];
	}

	cout << endl;
	string temporary51 = "║ 文字版《黑神话·悟空》\t\t\t\t\t\t\t║";
	for (int i = 0; i < temporary51.length(); i++) {
		Sleep(0);
		cout << temporary51[i];
	}

	cout << endl;
	string temporary52 = "║ 游戏介绍：一个简单的文字RPG。\t\t\t\t\t\t║";
	for (int i = 0; i < temporary52.length(); i++) {
		Sleep(0);
		cout << temporary52[i];
	}

	cout << endl;
	string temporary53 = "║ 版本：1.0\t\t\t\t\t\t\t\t║";
	for (int i = 0; i < temporary53.length(); i++) {
		Sleep(0);
		cout << temporary53[i];
	}

	cout << endl;
	string temporary54 = "║ 作者: 王桂鑫 袁东霖 王杰 程传哲 扬杨\t\t\t\t\t║";
	for (int i = 0; i < temporary54.length(); i++) {
		Sleep(0);
		cout << temporary54[i];
	}

	cout << endl;
	string temporary55 = "║ github地址: https://github.com/wgx4555454454/black-monkey.git\t\t║";
	for (int i = 0; i < temporary55.length(); i++) {
		Sleep(0);
		cout << temporary55[i];
	}

	cout << endl;
	string temporary56 = "╚═══════════════════════════════════════════════════════════════════════╝";
	for (int i = 0; i < temporary56.length(); i++) {
		Sleep(0);
		cout << temporary56[i];
	}

	cout << endl;

	// 恢复默认的控制台文本颜色  
	//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}
#include <iostream>
#include <windows.h>  // 用于设置控制台颜色
#include <thread>     // 用于延迟功能
#include <chrono>     // 用于延迟时间

void setColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void gameEndThankYou() {
	system("cls");
	setColor(10);  // 设置绿色
	cout << "游戏已经结束，但故事依然在继续..." << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(10));  

	setColor(11);  // 设置青色
	cout << "感谢您一路以来的支持与陪伴。" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(20));  

	setColor(14);  // 设置黄色
	cout << "没有您的参与，我们的游戏不会如此精彩。" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(20));  

	setColor(12);  // 设置红色
	cout << "感谢徐文华老师的悉心指导" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(15));  

	setColor(11);  // 设置青色
	cout << "希望我们能在未来的旅程中再次相遇！" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(25)); 

	setColor(14);  // 设置黄色
	cout << "期待您的再次光临，再见！" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(3));

	setColor(7);   // 恢复默认颜色
	system("pause");
}

int main() {
	Menu _menu;
	_menu.menu();
	return 0;
}