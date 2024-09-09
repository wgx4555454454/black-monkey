#include <iostream>
#include<iomanip>
#include <string>
#include <filesystem>
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
	map1 = {
		"�����������������������Щ����������������������������Щ���������������",//1
		"��         ����              ��     * ��",//2
		"��               ��     ��           ��",//3
		"����������������      �����ة���   ������         ��",//4
		"��      ������    ��   ���������ة�     ����   ��",//5
		"��                             ��   ��",//6
		"��  ��          ��     �������ة�����   ��   ��",//7
		"��  ������   ������������  ��������         ��   ��",//8
		"��    ��   ��    ��  ��      ��   �����ة�  ��",//9
		"��    ��           ��    �����ة�������     ��",//10
		"������������    ����    ����    ��           ��",//11
		"��         ��           ��       ����������",//12
		"��   ���������Щ���   ����������           ��   ��",//13
		"��             ��            ��      ��",//14
		"��      ��      ��  ��         ��      ��",//15
		"���������������ة������������ة����ة������������������ة�������������",//16
	};
	map1_s = {
		"+++++++++++++++++++++++++++++++++++",//1
		"+         ++    @     @   +     * +",//2
		"+               +     +      @    +",//3
		"++++++++      +++++   +++         +",//4
		"+      +++    +   ++++++     ++   +",//5
		"+                      @      +   +",//6
		"+  +          +     +++++++   +   +",//7
		"+  +++   ++++++  ++++      @  +   +",//8
		"+    +   +    +  +      +   ++++  +",//9
		"+  @ +           +    +++++++     +",//10
		"++++++    ++    ++    +      @    +",//11
		"+         +           +       +++++",//12
		"+   +++++++   +++++           +   +",//13
		"+             +            +      +",//14
		"+  @   +      +  +    @    +      +",//15
		"+++++++++++++++++++++++++++++++++++",//16
	};
	map2 = {
		"�����������������������������Щ������������������Щ����������������������������������Щ���������������",//1
		"��             ��         ��                 ��     * ��",//2
		"����������������    ������  ��������   ��   ����������������������   ��    ��������",//3
		"��      ��    ��    ��  ��       ��         ��   ��    ��  ��",//4
		"��  ��             ��  ��������    ��    ��    ��   ������     ��",//5
		"��  ������   ������������������          ��    ��    ��        ��  ��",//6
		"��    ��   ��       ��  ��    �������ة���������    �������Щ�����������  ��",//7
		"������������   ������  ��������  ��    ��               ��        ��",//8
		"��          ��      �����ة������Щ�       ��           ������������",//9
		"����������������   ������   ����     ��   �����������ة���������   ��  ��  ������",//10
		"��      ��         ��      ��   ��         ��   ��     �� ��",//11
		"��  ��   ������       ��     ����   ��    ��    ��   ������   �� ��",//12
		"��  ������   ����������   ��  ��            ��    ��         �� ��",//13
		"��    ��           ��  ��    ������������������    �������Щ�   ������ ��",//14
		"������������  ��������  ��������       ��               ��        ��",//15
		"��       ��  ��       ��������������     ���Щ�������        ������������",//16
		"��                 ����            ��         ��������    ��",//17
		"����������������    ���੤   ����    ��   ���������ة�����������   ��       ��",//18
		"��                       ��             ��           ��",//19
		"�����������������������������������������ة������ة��������������������������ة�����������������������",//20
	};

	map2_s = {
		"+++++++++++++++++++++++++++++++++++++++++++++++++++",//1
		"+             +    @    +     @     @     +     * +",//2
		"++++++++    +++  ++++   +   +++++++++++   +    ++++",//3
		"+      +    +    +  +       +         +   +    +  +",//4
		"+  +         @   +  ++++    +    +    +   +++     +",//5
		"+  +++   +++++++++     @    +    +    +    @   +  +",//6
		"+ @  +   +  @    +  +    +++++++++    ++++++++++  +",//7
		"++++++   +++  ++++  +    +    @          +        +",//8
		"+          +      ++++++++    @  +       @   ++++++",//9
		"++++++++ @ +++   ++  @  +   +++++++++++   +  +  +++",//10
		"+      +         +      +   +         +   +     + +",//11
		"+  +   +++       +     ++   +    +    + @ +++   + +",//12
		"+  +++   +++++   +  +      @@    +    +         + +",//13
		"+ @  +   @       +  +    +++++++++    +++++   +++ +",//14
		"++++++  ++++  ++++       + @             +        +",//15
		"+ @     +  +       +++++++     ++++++        ++++++",//16
		"+                 ++            + @       ++++    +",//17
		"++++++++    +++   ++    +   +++++++++++   +    @  +",//18
		"+  @              @     +         @   +           +",//19
		"+++++++++++++++++++++++++++++++++++++++++++++++++++",//20
	};

	map3 = {
		"���������������������Щ������������������������Щ��������������������Щ����������������������������������Щ���������������",//1
		"��         ����           ��          ��                 ��     * ��",//2
		"����������������   ������   ��������  ������  ������   ��   ����������������������   ��  ��  �� ��",//3
		"��      ��         ��  ��         ��       ��         ��   ��     �� ��",//4
		"��  ��   ����������     ��  ����������������  ����������   ��    �����������ੴ ���ة���   �� ��",//5
		"��  ������           ��         ��  ��   ��        ��    ��         �� ��",//6
		"��    ��           ��  ��   ��  ��������   ����   ����������    �������Щ������������� ��",//7
		"������������  ��������   ������  ��  ����         ��                ��        ��",//8
		"��       ��  ����       ��  ��   ����������������             ��������   ������������",//9
		"���������������Щ�   ����   ��������  ����  ��������   ��   ����������������������      ��    ��",//10
		"��      ��         ��  ��         ��   ��   ��         ��   ��      ����",//11
		"��  ��   ����������     ��  ����������     ����������   ��    ��    ��   ��������    ��",//12
		"��  ������           ��         ��  ��       ��    ��    ��      ��    ��",//13
		"��    ��           ��  ��   ��  ��������    �������ة���������    �������Щ������ة���  ��",//14
		"������������  ��������  ��������  ��   ��          ��               ��        ��",//15
		"��       ��  ��     ��  ��   ��   ����������������    �����Щ���������       ������������",//16
		"��                ��  ��       ��             ��        ���Щ�����    ��",//17
		"����������������         ��������  �����������ة���   ��   ���������ة�����������   ��  ��  ������",//18
		"��      ��         ��  ��         ��   ��   ��         ��   ��     �� ��",//19
		"��  ��   ������       ��  ����������������  ���������ة�������    ��    ��   ������   �� ��",//20
		"��  ������   ����������   ��         ��  ��            ��    ��         �� ��",//21
		"��    ��           ��  ��   ��  ��������    ������������������    �������Щ���  ������ ��",//22
		"������������  ��������  ��������  ��   ��          ��               ��        ��",//23
		"��          ��        ��   ��          ��     ��������������       ������������",//24
		"�����������������������ة����������������ة������ة��������������������ة����������������������ة�������������������������",//25
	};

	map3_s = {
		"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",//1
		"+         ++           +     @    +       @   @     +     * +",//2
		"++++++++   +++   ++++@@+++  +++   +   +++++++++++   +  +  + +",//3
		"+      +         +  +         +   @   +         +   +     + +",//4
		"+  +   +++++     +  ++++++++  +++++   + @  +++++++@++++   + +",//5
		"+  +++      @    +         +  + @ +        +    +         + +",//6
		"+  @ +           +  +   +  ++++   ++   +++++    +++++++++++ +",//7
		"++++++  ++++   +++  +  ++         +            @   +    @   +",//8
		"+       +  ++       +  +   ++++++++             ++++   ++++++",//9
		"+++++++++   ++   ++++  ++  ++++ @ +   +++++++++++      +  @ +",//10
		"+      +         +  +      @  +   +   +         +   +      ++",//11
		"+  +   +++++  @  +  +++++     +++++   +    +    +   ++++    +",//12
		"+  +++   @       +  @      +  +       +    +    +  @   +    +",//13
		"+    +           +  +   +  ++++    +++++++++ @  ++++++++++  +",//14
		"++++++  ++++  ++++  +   +  @ @     +               +        +",//15
		"+ @     +  +     +  +   +   ++++++++    ++++++++       ++++++",//16
		"+                +  +       +        @    +        +++++  @ +",//17
		"++++++++   @     ++++  ++++++++   +   +++++++++++   +  +  +++",//18
		"+      +         +  +       @ +   +   +         +   +     + +",//19
		"+  +   +++       +  ++++++++  +++++++++    +    +   +++   + +",//20
		"+  +++   +++++   +         +  + @          +    +         + +",//21
		"+ @  +           +  +   +  ++++    +++++++++    ++++++  +++ +",//22
		"++++++  ++++  ++++  +   +          +      @        +      @ +",//23
		"+ @        +        +   +    @     +     +++++++       ++++++",//24
		"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",//25
	};
}