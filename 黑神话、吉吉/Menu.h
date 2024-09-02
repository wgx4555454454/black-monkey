#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include"Role.h"
#include"Map.h"
#include"Enemy.h"
#include"Skills.h"
#include"Store.h"
#include"Game.h"

using namespace std;


class Menu {
private:
	string username;
	string base_adress = "C:\\ºÚÉñ»°";
	string user_adress;
	Game* game = NULL;
public:
	void menu();
};