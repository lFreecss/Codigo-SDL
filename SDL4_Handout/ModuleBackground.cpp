#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	//boat
	ship.x = 20;
	ship.y = 25;
	ship.w = 520;
	ship.h = 195;

	// flag animation
	flag.PushBack({848, 208, 40, 40});
	flag.PushBack({848, 256, 40, 40});
	flag.PushBack({848, 304, 40, 40});
	flag.speed = 0.08f;
	
	//girl animation
	girl.PushBack({ 624, 16, 32, 56 });
	girl.PushBack({ 624, 80, 32, 56 });
	girl.PushBack({ 624, 144, 32, 56 });
	girl.speed = 0.05f;

	//boy animation
	boy.PushBack({ 664, 16, 32, 56 });
	boy.PushBack({ 664, 80, 32, 56 });
	boy.speed = 0.05f;

	//men animation
	men.PushBack({ 552, 16, 64, 62 });
	men.PushBack({ 552, 80, 64, 62 });
	men.PushBack({ 552, 144, 64, 62 });
	men.speed = 0.05f;

	

	
	Boat.PushBack({ 20, 25, 550, 195 });
	Boat.PushBack({ 20, 20, 550, 195 });
	Boat.speed = 0.05f;
	
		
	
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("ken_stage.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &background, 0.75f); // sea and sky
	App->render->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 0.75f); // flag animation
	App->render->Blit(graphics, 0, tilting, &ship, 0.75f); // boat
	tilting += 2;
	tilting -= 2;
	/*App->render->Blit(graphics, 0, 0, &(Boat.GetCurrentFrame()), 0.75f); */
	//App->render->Blit(graphics, 0,0 , &(Boat.GetCurrentFrame()), 0.75f);//Boat animation 
	App->render->Blit(graphics, 116, 103, &(men.GetCurrentFrame()), 0.75f); // men animation 
	App->render->Blit(graphics, 180, 103, &(girl.GetCurrentFrame()), 0.75f); //girl animation
	App->render->Blit(graphics, 212, 103, &(boy.GetCurrentFrame()), 0.75f); //  boy animation
	// TODO 2: Draw the ship from the sprite sheet with some parallax effect
	// TODO 3: Animate the girl on the ship (see the sprite sheet)
	
	App->render->Blit(graphics, 0, 170, &ground);

	return UPDATE_CONTINUE;
}