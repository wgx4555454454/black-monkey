#pragma once  

#include <iostream>  
#include <vector>  
#include <string>  

using namespace std;

class Skills {
public:
    // ����뼸���������������˺���״̬  
    vector<string> skill = { "flameSlash", "frostPiercing" };
    vector<int> hurt = { 10, 10 };
    vector<int> state = { 0, 0 };

    // ���ü���״̬  
    void setSkill(int index);

    // ��ȡ�����˺�  
    int getSkillhurt(int index);

    // ��鼼���Ƿ���ѧϰ  
    bool checkSkill(int index);
};
