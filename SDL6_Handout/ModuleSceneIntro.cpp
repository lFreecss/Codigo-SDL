#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneIntro.h"
#include "ModuleSceneSpace.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneIntro::ModuleSceneIntro()
{}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading intro scene");

	background = App->textures->Load("rtype/intro.png");

		LOG("Init SDL audio");
		bool ret = true;

		if (SDL_Init(SDL_INIT_AUDIO) < 0)
		{
			LOG("SDL_AUDIO could not initialize! SDL_Error:\n");
			LOG(SDL_GetError());
			ret = false;
		}
		else
		{
			Mix_Init(MIX_INIT_OGG);
			Mix_OpenAudio(44000, MIX_DEFAULT_FORMAT, 2, 2048);
			music = Mix_LoadMUS("rtype/intro.ogg");
			Mix_PlayMusic(music, -1);
		}

	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{


	LOG("Unloading SDL audio");
	Mix_FreeMusic(music);

	LOG("Unloading space scene");

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(this, App->scene_space, 2);
		LOG("Init SDL audio");

		if (SDL_Init(SDL_INIT_AUDIO) < 0)
		{
			LOG("SDL_AUDIO could not initialize! SDL_Error:\n");
			LOG(SDL_GetError());
		}
		else
		{
			Mix_Init(MIX_INIT_MP3);
			Mix_OpenAudio(44000, MIX_DEFAULT_FORMAT, 2, 2048);
			music = Mix_LoadMUS("rtype/starting.wav");
			Mix_PlayMusic(music, -1);
		}
		Mix_FreeChunk(starting);
}

	return UPDATE_CONTINUE;
}