#include "stdafx.h"
#include"Menu.h"

using namespace std;

//设置文本颜色
void setColor(int color) {
	// 获取当前控制台句柄  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// 设置文本颜色
	SetConsoleTextAttribute(hConsole, color);
}

// 获取一个有效的整数，确保在给定的范围内
int getInt(int minVal, int maxVal) {

	string input;
	int result;

	while (true) {
		getline(cin, input);

		// 检查是否为空输入
		if (input.empty()) {
			continue;
		}
		// 使用 stringstream 来处理输入并检查是否为整数
		stringstream ss(input);
		if (!(ss >> result)) {
			cout << "输入无效，请确保输入的是整数:";
			continue;
		}
		// 检查是否有额外的无效字符
		char extraChar;
		if (ss >> extraChar) {
			cout << "输入包含非法字符，请仅输入整数：";
			continue;
		}
		// 检查范围
		if (result < minVal || result > maxVal) {
			cout << "超出范围，请输入 " << minVal << " 至 " << maxVal << " 之间的整数：";
			continue;
		}
		// 输入合法，返回结果
		return result;
	}
}


// 延迟输出函数，按下回车键后立即输出容器中剩余的内容
void delayedPrintVector(const vector<string>& temporary, int delay = 0) {
	for (size_t i = 0; i < temporary.size(); ++i) {
		const string& line = temporary[i];
		for (char ch : line) {
			if (_kbhit()) {
				char c = _getch();
				// 按下任意键时立即输出剩余内容
				delay = 0;
			}
			cout << ch;  // 输出当前字符
			this_thread::sleep_for(chrono::milliseconds(delay));  // 延迟
		}
	}
}

// 延迟输出函数，按下回车键后立即输出剩余的内容
void delayedPrintString(string temporary, int delay = 0) {
	const string& line = temporary;
	for (char ch : line) {
		if (_kbhit()) {
			char c = _getch();
			// 按下任意键时立即输出剩余内容
			delay = 0;
		}
		cout << ch;  // 输出当前字符
		this_thread::sleep_for(chrono::milliseconds(delay));	//延迟
	}
}

void welcomePage()
{
	
	setColor(FOREGROUND_RED);

	//黑神话页面图
	vector<string> strPage = {
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
	"╰──────────────────────────────────────────────────────────────────────────────────╯\n",
	};

	for (int i = 0; i < strPage.size(); i++) {
		Sleep(36);
		cout << strPage[i] << endl;
	}

	// 设置文本颜色为绿色  
	setColor(FOREGROUND_GREEN);
	vector<string> strPage2 = {
	"╔═══════════════════════════════════════════════════════════════════════╗",
	"║\t\t***中国海洋大学2024夏季学期c++课程设计***\t\t║",
	"║ 《黑神话·吉吉》\t\t\t\t\t\t\t║",
	"║ 游戏介绍：一个简单的RPG类型MUD游戏。\t\t\t\t\t║",
	"║ 版本：1.0\t\t\t\t\t\t\t\t║",
	"║ 作者: 王桂鑫 袁东霖 王杰 程传哲 杨扬\t\t\t\t\t║",
	"║ github地址: https://github.com/wgx4555454454/black-monkey.git\t\t║",
	"╚═══════════════════════════════════════════════════════════════════════╝",
	};
	for (int i = 0; i < strPage2.size(); i++) {
		Sleep(0);
		cout << strPage2[i] << endl;
	}
}


void gameEndThankYou() {
	system("cls");
	setColor(10);  // 设置绿色
	cout << "游戏已经结束，但故事依然在继续..." << endl << endl;
	Sleep(36);  

	setColor(11);  // 设置青色
	cout << "感谢您一路以来的支持与陪伴。" << endl << endl;
	Sleep(36);  

	setColor(14);  // 设置黄色
	cout << "没有您的参与，我们的游戏不会如此精彩。" << endl << endl;
	Sleep(36);  

	setColor(12);  // 设置红色
	cout << "感谢徐文华老师的悉心指导" << endl << endl;
	Sleep(36);  

	setColor(11);  // 设置青色
	cout << "希望我们能在未来的旅程中再次相遇！" << endl << endl;
	Sleep(25); 

	setColor(14);  // 设置黄色
	cout << "期待您的再次光临，再见！" << endl << endl;
	Sleep(3);

	setColor(7);   // 恢复默认颜色
	system("pause");
}

int main() {
	Menu _menu;
	_menu.menu();
	return 0;
}