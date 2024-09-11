#pragma once
#include "stdafx.h"
#include"Role.h"
#include"Map.h"
#include"Enemy.h"
#include"Skills.h"
#include"Store.h"
#include"Game.h"

using namespace std;


class Menu {
private:
	string strUsername;
	string strBase_adress = "C:\\ºÚÉñ»°";
	string strUser_adress;

	Game* ptrGame = NULL;
public:
	void menu();
};