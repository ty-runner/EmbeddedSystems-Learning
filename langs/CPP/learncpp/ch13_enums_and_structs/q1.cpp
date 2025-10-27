#include <iostream>

namespace Monster{
	enum MonsterType{
		orc,
		goblin,
		troll,
		ogre,
		skeleton,
	};
};

int main(){
	Monster::MonsterType char1 {Monster::troll};

	return 0;
}
