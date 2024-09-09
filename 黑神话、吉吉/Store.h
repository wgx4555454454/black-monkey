#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include"Skills.h"

using namespace std;

class Store  {
public:
	Skills skills;

	int Hpotion;//血量药水价格
	int Mpotion;//蓝条（魔法药水）价格

	Store() :Hpotion(2), Mpotion(1) {}
	~Store() {}

	void showStore();
};