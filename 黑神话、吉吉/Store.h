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

	int Hpotion;//Ѫ��ҩˮ�۸�
	int Mpotion;//������ħ��ҩˮ���۸�

	Store() :Hpotion(2), Mpotion(1) {}
	~Store() {}

	void showStore();
};