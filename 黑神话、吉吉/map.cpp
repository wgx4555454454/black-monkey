#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include "Menu.h"

using namespace std;

vector<string> Map::getMap1() {
	return map1;
}

vector<string> Map::getMap1_s() {
	return map1_s;
}

vector<string> Map::getMap2() {
	return map2;
}

vector<string> Map::getMap2_s() {
	return map2_s;
}

vector<string> Map::getMap3() {
	return map3;
}

vector<string> Map::getMap3_s() {
	return map3_s;
}


Map::Map() {
	ifstream ifs("map.data");
	string line;
	if (ifs.is_open()) {
		// 假设每个容器中的数据按顺序存储在文件中
		while (getline(ifs, line)) {
			if (line == "MAP1_END") 
				break;  // 假设用特殊标记区分不同地图数据
			map1.push_back(line);
		}
		while (getline(ifs, line)) {
			if (line == "MAP1_S_END") 
				break;
			map1_s.push_back(line);
		}
		while (getline(ifs, line)) {
			if (line == "MAP2_END") 
				break;
			map2.push_back(line);
		}
		while (getline(ifs, line)) {
			if (line == "MAP2_S_END") 
				break;
			map2_s.push_back(line);
		}
		while (getline(ifs, line)) {
			if (line == "MAP3_END") 
				break;
			map3.push_back(line);
		}
		while (getline(ifs, line)) {
			if (line == "MAP3_S_END") 
				break;
			map3_s.push_back(line);
		}
		ifs.close();
	}
	else {
		cerr << "地图读取失败!" << endl;
	}
}
