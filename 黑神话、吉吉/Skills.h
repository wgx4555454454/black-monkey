#pragma once  

#include <iostream>  
#include <vector>  
#include <string>  

using namespace std;

class Skills {
public:
    // ����뼸���������������˺���״̬  
    vector<string> skill = { "����ն", "��˪����" };
    vector<int> hurt = { 60, 60 };
    vector<int> price= { 20, 20 };

    // ���ü���״̬  
    void setSkill(int index);

    // ��ȡ�����˺�  
    int getSkillhurt(int index);

    // ��鼼���Ƿ���ѧϰ  
    bool checkSkill(int index);
};
