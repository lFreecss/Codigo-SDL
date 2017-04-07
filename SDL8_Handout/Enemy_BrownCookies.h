#ifndef __ENEMY_BROWNCOOKIES_H__
#define __ENEMY_BROWNCOOKIES_H__

#include "Enemy.h"

class Enemy_BrownCookies : public Enemy
{
private:
	
	iPoint original_pos;
	Animation fly;
	Path path;

public:
	
	Enemy_BrownCookies(int x, int y);

	void Move();
};

#endif // __ENEMY_BROWNCOOKIES_H__
