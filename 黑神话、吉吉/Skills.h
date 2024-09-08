#pragma once  

#include <iostream>  
#include <vector>  
#include <string>  

using namespace std;

class Skills {
public:
    // 随便想几个技能名，技能伤害及状态  
    vector<string> skill = { "烈焰斩", "冰霜穿刺" };
    vector<int> hurt = { 60, 60 };
    vector<int> price= { 20, 20 };

    // 设置技能状态  
    void setSkill(int index);

    // 获取技能伤害  
    int getSkillhurt(int index);

    // 检查技能是否已学习  
    bool checkSkill(int index);
};
