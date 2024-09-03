#include <iostream>
#include<iomanip>
#include <string>
#include <filesystem>
#include "Menu.h"

using namespace std;

vector<string> Map::getMap1() {
	return map1;
}

vector<string> Map::getMap2() {
	return map2;
}

vector<string> Map::getMap3() {
	return map3;
}

Map::Map() {
	map1 = {
	"|-----------------------------------------------------------|",//1
	"| @       |-  |        |          |                 |       !",//2
	"|-------    |-|  |--   |-  |--|   |   -----------   |  |  --|",//3
	"|      |         |  |         | @ |   |         |   |     |@|",//4
	"|  |   ----- @   |  |-----    |---|   |   @|    |   |--   | |",//5
	"|  --    |----   |         | @|            |    |         | |",//6
	"|   @|           |  |   |  |--|    --------     |---------| |",//7
	"|----|   --   |--   |   |          |               |        |",//8
	"|       |  |        | @ |   |------| @  |------|       |----|",//9
	"|-------    |-|  |--   |-  |--|   |   -----------   |  |  --|",//10
	"|      |         |  |         | @ |   |         |   |     |@|",//11
	"|  |   ----- @   |  |-----    |---|   |   @|    |   |--   | |",//12
	"|  --    |----   |         | @|            |    |         | |",//13
	"|   @|           |  |   |  |--|    --------     |---------| |",//14
	"|----|   --   |--   |   |          |               |        |",//15
	"|       |@ |        | @ |   |------| @  |------|       |----|",//16
	"|----         @  |---       |             |        ----    @|",//17
	"|-------    |-|  |--   |-  |--|   |   -----------   |  |  --|",//18
	"|      |         |  |         | @ |   |         |   |     |@|",//19
	"|  |   ----- @   |  |-----    |---|   |   @|    |   |--   | |",//20
	"|  --    |----   |         | @|            |    |         | |",//21
	"|   @|           |  |   |  |--|    --------     |---------| |",//22
	"|----|   --   |--   |   |          |               |        |",//23
	"!       |  |        | @ |   |------| @  |------|       |----|",//24
	"|-----------------------------------------------------------|",//25

	};
	map2 = {
		"|-----------------------------------------------------------|",//1
	"| @       |-  |        |          |                 |       !",//2
	"|-------    |-|  |--   |-@@|--|   |   -----------   |  |  --|",//3
	"|      |         |  |         | @ |   |         |   |     |@|",//4
	"|  |   ----- @   |  |-----    |---|   |   @|    |   |--   | |",//5
	"|  --    |-------|         | @|            |    |         | |",//6
	"|   @|   |       |  |   |  |--|    --------     |---------| |",//7
	"|----|   --   |--   |   |  @       |               |        |",//8
	"|       |  |        | @ |   |------| @  |------|       |----|",//9
	"| ------   ------|@@                   |    @     ----      |",//10
	"|  @   |         |  |         | @ |   |         |   |     |@|",//11
	"|  |   ----- @   |  |-----    |---|   |   @|    |   |--   | |",//12
	"|  --    |----   |         | @|            |    |         | |",//13
	"|   @|           |  |   |  |--|    --------     |---------| |",//14
	"|----|  ----  |--   |   |          |               |        |",//15
	"|       |@ |        | @ |   |------| @  |------|@@@    |----|",//16
	"| @        -  |        |   @      |   |@    |        |      |",//17
	"|-------    |-|  |--   |-  |--|   |   -----------   |  |  --|",//18
	"|      |         |  |         | @ |   |         |   |     |@|",//19
	"|  |   ----- @   |  |-----    |---|   |   @|    |   |--   | |",//20
	"|  --    |----   |         | @|            |    |         | |",//21
	"|   @|   @       |  |   |  |--|    --------     |---------| |",//22
	"|----|   --   |--   |   |          |               |        |",//23
	"!       |  |        | @ |   |------| @  |------|       |----|",//24
	"|-----------------------------------------------------------|",//25

	};
	map3 = {
		"|-----------------------------------------------------------|",//1
	"| @       |-  |   @    |          |   @             |    @  !",//2
	"|-------    |-|  |--   |-  |--|   |   -----------   |  |  --|",//3
	"|      |    @    |  |     @   | @ |   |         |   |     |@|",//4
	"|  |   ----- @   |  |-----    |---|   |   @|    |@@@|--   | |",//5
	"|  --    |-------|         | @|   @   |    |    |         | |",//6
	"|   @|   |       |  |   |  |--|    --------     |---------| |",//7
	"|----|   --   |--   |   |   @      |               |        |",//8
	"|       |  |     @  | @ |   |------| @  |------|       |----|",//9
	"|-------    |-|  |--   |-  |--|   |   -----------   |  |  --|",//10
	"|      |         |  |         | @ |   |    @    |   |     |@|",//11
	"|  |   ----- @   |  |-----    |---|   |   @|    |   |--   | |",//12
	"|  --    |----   |  @      | @|            |    |         | |",//13
	"|   @|        @  |  |   |  |--|    --------     |---------| |",//14
	"|----|   --   |--   |   |     @    |               |        |",//15
	"|       |@ |  @     | @ |   |------| @  |------|@@     |----|",//16
	"|----   |     @  |---    ---|             |       -----    @|",//17
	"|-------   @|-|  |--   |-  |--|   |   -----------   |  |  --|",//18
	"|      |         |  |     @   | @ |   |         |   |     |@|",//19
	"|  |   ----- @   |  |-----    |---|   |   @|    |   |--   | |",//20
	"|  --    |----   |         | @|            |    |  @      | |",//21
	"|   @|@@@        |  |   |  |--|    --------     |---------| |",//22
	"|----|   --   |--   |   |   @      |           @   |        |",//23
	"!       |  |@@      | @ |   |------| @  |------|       |----|",//24
	"|-----------------------------------------------------------|",//25

	};
}