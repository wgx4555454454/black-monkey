#include "stdafx.h"
#include "Menu.h"

using namespace std;
int getInt(int min,int max);    //从键盘获取int类型数据

// 自定义延迟输出函数，按下回车键后立即输出剩余的内容
void delayedPrintVector(const vector<string>& temporary, int delay = 0);
void delayedPrintString(const string temporary, int delay = 0);

void Game::game() {
    system("pause");
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

    delayedPrintString("欢迎来到黑神话 \n这是一个简单的RPG游戏\n\n", 16);

    showBeginPlot();//故事情节
    cout << endl;

    system("pause");//接下来开始进入地图并持续移动
    int ending = 0;//某一张地图的结局，1为通过，0为退出，2为失败
    int characterLive = 1;//角色活着，0为死亡
    int chooseC = 0;//上帝模式的标记

    //获取关卡
    int passes = character.getPasses();
    while (passes < 3 && chooseC == 0) {
        system("cls");
        switch (passes) {
        case 0:
            delayedPrintString("第一关：\n", 16);
            system("pause");
            ending = move(map.getMap1(), map.getMap1_s());//获取通关状态
            break;
        case 1:
            delayedPrintString("第二关：\n", 16);
            system("pause");
            ending = move(map.getMap2(), map.getMap2_s());//获取通关状态
            break;
        case 2:
            delayedPrintString("第三关：\n", 16);
            system("pause");
            ending = move(map.getMap3(), map.getMap3_s());//获取通关状态
            break;
        }

        //通关状态
        if (ending == 1) {
            passes++;
        }
        else if (ending == 0) {
            chooseC = 1;    //进入了上帝模式
        }
        else if (ending == 2) {
            characterLive = 0;  //角色死亡
        }


        //上帝模式中的选项
        if (chooseC == 1) {
            system("cls");
            delayedPrintString("1.继续  2.保存并退出  3.下一关  ", 16);
            int choose_C = getInt(1, 3); //获取选择

            switch (choose_C) {
            case 1:
                chooseC = 0;
                break;
            case 2:
                character.setPasses(passes);
                return;
            case 3:
                chooseC = 0;
                passes++;
                break;
            default:
                delayedPrintString("Error!", 16);
                break;
            }
        }

        //角色死亡
        if (characterLive == 0) {
            system("cls");
            delayedPrintString("角色已死亡！", 16);
            delayedPrintString("1.退出  2.从头开始", 16);

            int choose_Character = getInt(1, 2);//获取用户选择
            switch (choose_Character) {
            case 1:
                character.setHP(100);
                character.setMP(35);
                characterLive = 1;
                return;
            case 2:
                character.setHP(100);
                character.setMP(35);
                characterLive = 1;
                passes = 0;
                break;
            default:
                cout << "Error!" << endl;
                break;
            }
        }
        character.setPasses(passes);
    }

    system("cls");
    showFinalPlot();    //展示结束页面
    system("pause");
}

void Game::showBeginPlot() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    delayedPrintString("孙悟空拒绝了佛祖所封“斗战胜佛”的神仙职位，选择回到花果山躺平\n"
        "继续做划过上本地帮派大佬，但是天庭明显认为花果山这里的本地帮派不太有礼貌\n"
        "主要原因还是因为对于摘了紧箍咒的孙悟空压根不放心\n"
        "于是便派遣十万天兵与四大天王以及二郎神杨戬\n"
        "用整个花果山的猴子猴孙的安危来要挟孙悟空，让其回去当神仙\n"
        "但悟空好不容易安顿下来，肯定不愿意去到天庭当神仙\n"
        "面对这种情况天兵天将自然是不允许，而杨戬一跃而下主动向身后所有天兵天将提出要和悟空进行单挑\n"
        "自此一场恶战正式展开\n", 16);
}

void Game::showFinalPlot() {
    delayedPrintString("其实悟空的“意”早已不再，在悟空生命陨落的那一刻就随之消散\n"
        "所有孙悟空不会真正意义上的复活了，但天地会重新选择一个孙悟空，也就是天命人\n"
        "可以成为悟空的“意”，可以成为下一个孙悟空\n"
        "因为你身为天命人，本是无名之人\n"
        "但经过重重困难，获得了五个根器，也许此刻你就够格成为孙悟空了\n", 16);
}

void Game::setEnemy() {
    vector<string> strWords1 = {
        "都记好喽，他不是只普通猴子，他是有功的猴子，是封过佛位的猴子，\n"
        "这里只有我配与他一战，猴孙啊猴孙，我本不想与你一战，这样吧，\n"
        "一会你若是败了，我带你回花果山，他们，留在这里铲平花果山，\n"
        "若是我输了，我定然不会罢休，他们照样铲平花果山，生灵涂炭啊，\n"
        "好歹也同僚一场，真不想打，要不你现在跪下认个错，这事就这样过去，如何？",
        "可恶！我还会再回来的",
        "滚回你的花果山吧!"
    };
    enemy[0] = Enemy(150, 15, "杨戬", strWords1);

    vector<string> strWords2 = {
        "来者何人，敢来此处扰我请修，嗯？又是只猴子，施主不如放下棍棒，跟我学下佛法，如何？",
        "天命人，这次你又赢了",
        "佛法无边，不度无缘"
    };
    enemy[1] = Enemy(120, 6, "广智", strWords2);

    vector<string> strWords3 = {
        "小僧法号广谋，"
        "若小夫身死你手，麻烦给我带句话给师傅."
        "肉眼凡夫，求而不得神仙骨."
        "半荣半枯，几人知是长生路",
        "施主如此执于外物，与我那师傅又有何分别",
        "人间多少欢场，结局都不一样"
    };
    enemy[2] = Enemy(130, 8, "广谋", strWords3);

    vector<string> strWords4 = {
        "风兮风兮，往者不可谏，来者犹可追，\n"
        "小师父，天色已晚，你来我这修身之地大开杀戒，究竟是何居心",
        "观音禅院是烧没了，可那长老的冤魂没有散",
        "单有匹夫之勇罢了"
    };
    enemy[3] = Enemy(200, 16, "白衣秀士", strWords4);

    vector<string> strWords5 = {
        "阿弥陀佛，那三口洪钟终于响了\n"
        "徒儿们，又有外面的老爷过来了，给我带新宝贝了\n"
        "我看不见样貌，但我能闻到那股骚味，莫非是你，你回来了\n"
        "定是你把那袈裟藏起来了，快还给我！",
        "我今年270岁\n"
        "空挣了几百件袈裟\n"
        "怎么得有他这一件？\n"
        "那袈裟我不要了，那袈裟我不要了，不不不，不~",
        "若披不上这件袈裟，众生又怎知我尘缘已断，金海尽干"
    };
    enemy[4] = Enemy(200, 7, "金池长老", strWords5);

    vector<string> strWords6 = {
        "五百年了，我重建了观音禅院，规模比之前的更大\n"
        "那些藏身火海的僧众，化为孤魂野鬼，在这黑风山谷游荡\n"
        "是我，亲手将他们一一超度\n"
        "哈哈哈哈，但我知道总有一天，你还是会找上门来",
        "这次先放过你，我们后面还会再见的!",
        "虚惊一场罢了"
    };
    enemy[5] = Enemy(170, 9, "黑风大王", strWords6);

    vector<string> strWords7 = {
        "那家伙曾经对我说，眼不见，心不乱\n"
        "寻常修为，入一切相，破一切相，方得自在\n"
        "可是他自己看到那些东西后，不也疯了吗?",
        "今日本大王先不与你纠缠",
        "那有什么天命，不过都是贪心\n"
        "想取我的宝贝，你还不配"
    };
    enemy[6] = Enemy(100, 10, "黑熊精", strWords7);
}
