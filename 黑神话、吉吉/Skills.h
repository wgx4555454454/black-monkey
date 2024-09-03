#pragma once  

#include <iostream>  
#include <vector>  
#include <string>  

using namespace std;

class Skills {
public:
    // 随便想几个技能名，技能伤害及状态  
    vector<string> skill = { "flameSlash", "frostPiercing" };
    vector<int> hurt = { 10, 10 };
    vector<int> state = { 0, 0 };

    // 设置技能状态  
    void setSkill(int index);

    // 获取技能伤害  
    int getSkillhurt(int index);

    // 检查技能是否已学习  
    bool checkSkill(int index);
};
