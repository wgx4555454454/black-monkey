#pragma once

class Skills {
public:
	//随便想几个技能名，int 类型，技能学习所需硬币价格
	int MatterFlame_Slash;
	int MatterFrost_Piercing;
	string skill_1 = "Flame Slash"; //烈焰斩
	string skill_2 = "Frost Piercing"; // 冰霜穿刺
	Skills() :MatterFlame_Slash(0), MatterFrost_Piercing(0) {}
	Skills(int a, int b) {
		MatterFlame_Slash = a; MatterFrost_Piercing = b;
	}
	int moneySkill_1 = 4;
	int moneySkill_2 = 3;
};