#include <iostream>
#include<iomanip>
#include <string>
#include <filesystem>
#include <windows.h>
#include <conio.h>
#include "Menu.h"

using namespace std;
int getInt();

void Game::game() {
	system("pause");
	system("cls");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

	string strTemporary24 = "��ӭ��������";

	for (int i = 0; i < strTemporary24.length(); i++) {
		// �����⵽���̰���
		if (_kbhit()) {
			char ch = _getch();
			cout << strTemporary24.substr(i) << endl;  // ���ʣ�µ�ȫ������
			break;
		}
		Sleep(16);
		cout << strTemporary24[i];
	}
	cout << endl;

	string strTemporary25 = "����һ���򵥵�RPG��Ϸ";

	for (int i = 0; i < strTemporary25.length(); i++) {
		// �����⵽���̰���
		if (_kbhit()) {
			char ch = _getch();
			cout << strTemporary25.substr(i) << endl;  // ���ʣ�µ�ȫ������
			break;
		}
		Sleep(16);
		cout << strTemporary25[i];
	}

	cout << endl;

	cout << endl;

	showBeginPlot();//�������

	system("pause");//��������ʼ�����ͼ�������ƶ�

	int ending = 0;//ĳһ�ŵ�ͼ�Ľ�֣�1Ϊͨ����0Ϊ�˳���2Ϊʧ��

	int chooseC = 0;//�Ƿ�ѡ��������˳�

	int choose_C = 0;
	int characterLive = 1;//��ɫ���ţ�0Ϊ����

	int choose_Character = 0;

	int passes = character.getPasses();
	while (passes < 3 && chooseC == 0) {
		switch (passes) {
		case 0: {
			string strTemporary27 = "��һ�أ�";

			for (int i = 0; i < strTemporary27.length(); i++) {
				// �����⵽���̰���
				if (_kbhit()) {
					char ch = _getch();
					cout << strTemporary27.substr(i) << endl;  // ���ʣ�µ�ȫ������
					break;
				}
				Sleep(16);
				cout << strTemporary27[i];
			}

			cout << endl;

			system("pause");

			ending = move(map.getMap1(), map.getMap1_s());
			if (ending == 1)
				passes++;

			if (ending == 0)
				chooseC = 1;

			if (ending == 2)
				characterLive = 0;

			break;
		}
		case 1: {
			string strTemporary28 = "�ڶ��أ�";

			for (int i = 0; i < strTemporary28.length(); i++) {
				// �����⵽���̰���
				if (_kbhit()) {
					char ch = _getch(); {
						cout << strTemporary28.substr(i) << endl;  // ���ʣ�µ�ȫ������
						break;
					}
					Sleep(16);
					cout << strTemporary28[i];
				}
				cout << endl;

				system("pause");

				ending = move(map.getMap2(), map.getMap2_s());

				if (ending == 1)
					passes++;

				if (ending == 0)
					chooseC = 1;

				if (ending == 2)
					characterLive = 0;
				break;
			}
			break;
		}
		case 2: {
			string strTemporary29 = "�����أ�";

			for (int i = 0; i < strTemporary29.length(); i++) {
				// �����⵽���̰���
				if (_kbhit()) {
					char ch = _getch();
					cout << strTemporary29.substr(i) << endl;  // ���ʣ�µ�ȫ������
					break;
				}
				Sleep(16);
				cout << strTemporary29[i];
			}

			cout << endl;

			system("pause");

			ending = move(map.getMap3(), map.getMap3_s());

			if (ending == 1)
				passes++;

			if (ending == 0)
				chooseC = 1;

			if (ending == 2)
				characterLive = 0;
			break;
		}
		}
			  if (chooseC == 1) {
				  system("cls");

				  string strTemporary30 = "1.����  2.���沢�˳�  3.��һ��  ";

				  for (int i = 0; i < strTemporary30.length(); i++) {
					  // �����⵽���̰���
					  if (_kbhit()) {
						  char ch = _getch();
						  cout << strTemporary30.substr(i) << endl;  // ���ʣ�µ�ȫ������
						  break;
					  }
					  Sleep(16);
					  cout << strTemporary30[i];
				  }
				  cout << endl;
				  do {
					  choose_C = getInt();

					  if (choose_C != 1 && choose_C != 2 && choose_C != 3) {

						  string strTemporary31 = "Error!������1-3�е�һ����";

						  for (int i = 0; i < strTemporary31.length(); i++) {
							  // �����⵽���̰���
							  if (_kbhit()) {
								  char ch = _getch();
								  cout << strTemporary31.substr(i) << endl;  // ���ʣ�µ�ȫ������
								  break;
							  }
							  Sleep(16);
							  cout << strTemporary31[i];
						  }
						  cout << endl;

					  }
				  } while (choose_C != 1 && choose_C != 2 && choose_C != 3);

				  switch (choose_C) {
				  case 1:
					  chooseC = 0;
					  break;
				  case 2:
					  character.setPasses(passes);//�������
					  return;
					  break;
				  case 3:
					  chooseC = 0;
					  passes++;
					  break;
				  default:
					  string strTemporary32 = "Error!";

					  for (int i = 0; i < strTemporary32.length(); i++) {
						  // �����⵽���̰���
						  if (_kbhit()) {
							  char ch = _getch();
							  cout << strTemporary32.substr(i) << endl;  // ���ʣ�µ�ȫ������
							  break;
						  }
						  Sleep(16);
						  cout << strTemporary32[i];
					  }

					  cout << endl;
				  }
			  }

			  if (characterLive == 0) {
				  system("cls");

				  string strTemporary33 = "��ɫ��������";

				  for (int i = 0; i < strTemporary33.length(); i++) {

					  // �����⵽���̰���
					  if (_kbhit()) {
						  char ch = _getch();
						  cout << strTemporary33.substr(i) << endl;  // ���ʣ�µ�ȫ������
						  break;
					  }
					  Sleep(16);
					  cout << strTemporary33[i];
				  }
				  cout << endl;
				  string strTemporary34 = "1.�˳�  2.��ͷ��ʼ";

				  for (int i = 0; i < strTemporary34.length(); i++) {
					  // �����⵽���̰���
					  if (_kbhit()) {
						  char ch = _getch();
						  cout << strTemporary34.substr(i) << endl;  // ���ʣ�µ�ȫ������
						  break;
					  }
					  Sleep(16);
					  cout << strTemporary34[i];
				  }

				  cout << endl;
				  do {
					  choose_Character = getInt();
					  if (choose_Character != 1 && choose_Character != 2) {
						  string strTemporary35 = "Error��������1-2";

						  for (int i = 0; i < strTemporary35.length(); i++) {
							  // �����⵽���̰���
							  if (_kbhit()) {
								  char ch = _getch();
								  cout << strTemporary35.substr(i) << endl;  // ���ʣ�µ�ȫ������
								  break;
							  }
							  Sleep(16);
							  cout << strTemporary35[i];
						  }
						  cout << endl;

					  }
				  } while (choose_Character != 1 && choose_Character != 2);

				  switch (choose_Character) {
				  case 1:
					  character.setHP(100);
					  character.setMP(35);
					  characterLive = 1;

					  return;
					  break;
				  case 2:
					  character.setHP(100);
					  character.setMP(35);

					  characterLive = 1;
					  passes = 0;
					  break;
				  default:
					  string strTemporary32 = "Error!";

					  for (int i = 0; i < strTemporary32.length(); i++) {
						  // �����⵽���̰���
						  if (_kbhit()) {
							  char ch = _getch();
							  cout << strTemporary32.substr(i) << endl;  // ���ʣ�µ�ȫ������
							  break;
						  }
						  Sleep(16);
						  cout << strTemporary32[i];
					  }
					  cout << endl;

				  }
			  }
			  character.setPasses(passes);
		}
		system("cls");

		showFinalPlot();

		system("pause");
}


void Game::setEnemy() {
	vector<string> strWords1 = {
	   "���Ǻ�ඣ�������ֻ��ͨ���ӣ������й��ĺ��ӣ��Ƿ����λ�ĺ��ӣ�\n"
	   "����ֻ����������һս�����ﰡ����ұ���������һս�������ɣ�\n"
	   "һ�������ǰ��ˣ��Ҵ���ػ���ɽ�����ǣ����������ƽ����ɽ��\n"
	   "���������ˣ��Ҷ�Ȼ������ݣ�����������ƽ����ɽ������Ϳ̿����\n"
	   "�ô�Ҳͬ��һ�����治���Ҫ�������ڹ����ϸ������¾�������ȥ����Σ�",
	   "�ɶ��һ����ٻ�����",
	   "������Ļ���ɽ��!"
	};

	Enemy e1(150, 15, "���", strWords1);

	enemy[0] = e1;

	vector<string> strWords2 = {
		"���ߺ��ˣ������˴��������ޣ��ţ�����ֻ���ӣ�ʩ��������¹���������ѧ�·𷨣���Σ�",
		"�����ˣ��������Ӯ��",
		"���ޱߣ�������Ե"
	};

	Enemy e2(120, 6, "����", strWords2);

	enemy[1] = e2;

	vector<string> strWords3 = {
		"Сɮ���Ź�ı��"
		"��С���������֣��鷳���Ҵ��仰��ʦ��."
		"���۷�������������ɹ�."
		"���ٰ�ݣ�����֪�ǳ���·",
		"ʩ�����ִ�����������ʦ�����кηֱ�",
		"�˼���ٻ�������ֶ���һ��"
	};
	Enemy e3(130, 8, "��ı", strWords3);

	enemy[2] = e3;

	vector<string> strWords4 = {
		"������⣬���߲����ɣ������̿�׷��\n"
		"Сʦ������ɫ����������������֮�ش�ɱ�䣬�����Ǻξ���",
		"������Ժ����û�ˣ����ǳ��ϵ�ԩ��û��ɢ",
		"����ƥ��֮�°���"
	};
	Enemy e4(200, 16, "������ʿ", strWords4);

	enemy[3] = e4;

	vector<string> strWords5 = {
		"�����ӷ������ں�����������\n"
		"ͽ���ǣ������������ү�����ˣ����Ҵ��±�����\n"
		"�ҿ�������ò���������ŵ��ǹ�ɧζ��Ī�����㣬�������\n"
		"������������Ĳ������ˣ��컹���ң�",
		"�ҽ���270��\n"
		"�����˼��ټ�����\n"
		"��ô��������һ����\n"
		"�������Ҳ�Ҫ�ˣ��������Ҳ�Ҫ�ˣ�����������~",
		"��������������ģ���������֪�ҳ�Ե�Ѷϣ��𺣾���"
	};

	Enemy e5(200, 7, "��س���", strWords5);

	enemy[4] = e5;

	vector<string> strWords6 = {
		"������ˣ����ؽ��˹�����Ժ����ģ��֮ǰ�ĸ���\n"
		"��Щ����𺣵�ɮ�ڣ���Ϊ�»�Ұ������ڷ�ɽ���ε�\n"
		"���ң����ֽ�����һһ����\n"
		"��������������֪������һ�죬�㻹�ǻ���������",
		"����ȷŹ��㣬���Ǻ��滹���ټ���!",
		"�龪һ������"
	};

	Enemy e6(170, 9, "�ڷ����", strWords6);

	enemy[5] = e6;

	vector<string> strWords7 = {
		"�Ǽһ���������˵���۲������Ĳ���\n"
		"Ѱ����Ϊ����һ���࣬��һ���࣬��������\n"
		"�������Լ�������Щ�����󣬲�Ҳ������?",
		"���ձ������Ȳ��������",
		"����ʲô��������������̰��\n"
		"��ȡ�ҵı������㻹����"
	};

	Enemy e7(100, 10, "���ܾ�", strWords7);

	enemy[6] = e7;

}

void Game::showBeginPlot()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	string strWordbegin = {
		"����վܾ��˷������⡰��սʤ�𡱵�����ְλ��ѡ��ص�����ɽ��ƽ\n"
		"�����������ϱ��ذ��ɴ��У�������ͥ������Ϊ����ɽ����ı��ذ��ɲ�̫����ò\n"
		"��Ҫԭ������Ϊ����ժ�˽�����������ѹ��������\n"
		"���Ǳ���ǲʮ��������Ĵ������Լ����������\n"
		"����������ɽ�ĺ��Ӻ���İ�Σ��ҪЮ����գ������ȥ������\n"
		"����պò����װ����������϶���Ը��ȥ����ͥ������\n"
		"��������������콫��Ȼ�ǲ����������һԾ���������������������콫���Ҫ����ս��е���\n"
		"�Դ�һ����ս��ʽչ��\n"
	};

	int pos = 0;  // ��ʽ�����������ڸ��ٵ�ǰ�ַ���λ��

	for (char c : strWordbegin) {
		// ����Ƿ��а���������
		if (_kbhit()) {
			char ch = _getch();
			cout << strWordbegin.substr(pos) << endl;  // ���ʣ����ַ�
			break;
		}
		cout << c;  // �����ǰ�ַ�
		Sleep(20);  // �ӳ�
		pos++;  // ����λ������
	}
	cout << endl;

}
void Game::showFinalPlot() {

	string strWordend = {
		"��ʵ��յġ��⡱���Ѳ��٣�����������������һ�̾���֮��ɢ\n"
		"��������ղ������������ϵĸ����ˣ�����ػ�����ѡ��һ������գ�Ҳ����������\n"
		"���Գ�Ϊ��յġ��⡱�����Գ�Ϊ��һ�������\n"
		"��Ϊ����Ϊ�����ˣ���������֮��\n"
		"�������������ѣ���������������Ҳ��˿���͹����Ϊ�������\n"
	};

	int pos = 0;  // ��ʽ�����������ڸ��ٵ�ǰ�ַ���λ��

	for (char c : strWordend) {
		// ����Ƿ��а���������
		if (_kbhit()) {
			char ch = _getch(); 
			cout << strWordend.substr(pos) << endl;  // ���ʣ����ַ�
			break;
		}
		cout << c;  // �����ǰ�ַ�
		Sleep(20);  // �ӳ�
		pos++;  // ����λ������
	}

	cout << endl;
}
