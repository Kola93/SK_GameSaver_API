

#include "GameSaver.h"
#include "UserTest.h"

int main()
{
	UserTest s;
	s.health = 5;
	s.life = 88;
	GameSaver GS("");
	GS.Save(s);

	GameSaver ss("");
	UserTest l;
	ss.Load(l);

	return 0;
}
