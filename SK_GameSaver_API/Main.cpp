

#include "GameSaver.h"
#include "UserTest.h"

int main()
{
	UserTest s;
	s.health = 5;
	s.life = 88;
	GameSaver GS("");
	GS.Save(s);


	UserTest l;
	GS.Load(l);

	return 0;
}
