#include "Application.h"
#include "Enemy_BrownCookies.h"
#include "ModuleCollision.h""

Enemy_BrownCookies::Enemy_BrownCookies(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 5,72,21,22 });

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 21, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;

	
}

void Enemy_BrownCookies::Move()
{
	position = original_pos + path.GetCurrentPosition();
	//path.PushBack({ 0.5f, 0.5f }, 200, nullptr);
	path.PushBack({ -0.2f, 0.0f }, 11500, nullptr);
	position = original_pos + path.GetCurrentPosition();
	path.PushBack({ 0.0f, 0.2f }, 11500, nullptr);
	position = original_pos + path.GetCurrentPosition();
	path.PushBack({ 0.2f, 0.0f }, 11500, nullptr);
	position = original_pos + path.GetCurrentPosition();
	path.PushBack({0.0f, -0.2f }, 11500, nullptr);
	//path.PushBack({ 0.5f, -0.5f }, 500, nullptr);
	//position.y = original_y + (25.0f * sinf(wave));
	//position.x -= 1;
}
