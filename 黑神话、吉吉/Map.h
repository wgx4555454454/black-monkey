#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include<vector>
#include <fstream>

using namespace std;

class Map {
private:
	vector<string> map1;
	vector<string> map1_s;
	vector<string> map2;
	vector<string> map2_s;
	vector<string> map3;
	vector<string> map3_s;
public:
	Map();
	vector<string> getMap1();
	vector<string> getMap1_s();
	vector<string> getMap2();
	vector<string> getMap2_s();
	vector<string> getMap3();
	vector<string> getMap3_s();
};
