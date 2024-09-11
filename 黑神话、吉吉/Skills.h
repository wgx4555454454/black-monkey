#pragma once  
#include "stdafx.h"


using namespace std;

class Skills {
public:
   
    vector<string> strSkillname = { "烈焰斩", "冰霜穿刺" };//技能名

    vector<int> hurt = { 60, 60 };//技能造成的伤害

    vector<int> price= { 20, 20 };//技能的价格

    // 设置技能状态  
    void setSkill(int index);

    // 获取技能伤害  
    int getSkillhurt(int index);

    // 检查技能是否已学习  
    bool checkSkill(int index);
};
