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
	vector<string> map2;
	vector<string> map3;
public:
	vector<string> getMap1();
	vector<string> getMap2();
	vector<string> getMap3();
	Map();
};
