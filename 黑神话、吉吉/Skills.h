#pragma once  
#include "stdafx.h"


using namespace std;

class Skills {
public:
   
    vector<string> strSkillname = { "����ն", "��˪����" };//������

    vector<int> hurt = { 60, 60 };//������ɵ��˺�

    vector<int> price= { 20, 20 };//���ܵļ۸�

    // ���ü���״̬  
    void setSkill(int index);

    // ��ȡ�����˺�  
    int getSkillhurt(int index);

    // ��鼼���Ƿ���ѧϰ  
    bool checkSkill(int index);
};
