﻿#include"Skills.h"
using namespace std;
void Skills::setSkill(int number)
{
    state[number] = 1;
}
int Skills::getSkillhurt(int number)
{
    if (checkSkill(number))
    {
        return hurt[number];
    }
    else
    {
        return 0;
    }
}
bool Skills::checkSkill(int number)
{
    if (state[number] == 1)
    {
        return 1;
    }
    else
        return 0;
}