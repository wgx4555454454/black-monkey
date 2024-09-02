#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include"Skills.h"

using namespace std;

class Store :public Skills {
public:
	int Hpotion;//血量药水价格
	int Mpotion;//蓝条（魔法药水）价格
	Store() :Hpotion(0), Mpotion(0) {}
	~Store() {}
	void showStore();
	void Buy(Role& Role);
};