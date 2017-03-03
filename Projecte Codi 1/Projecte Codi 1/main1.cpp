#include "include/SDL.h"
#include <iostream>

#pragma comment( lib, "lib/x86/SDL2.lib")
#pragma comment( lib, "lib/x86/SDL2main.lib" )

int main(int argc, char *args[]) {
	SDL_Init(SDL_INIT_EVERYTHING); // Inici Llibrería SDL
	SDL_Window *MainWindow = SDL_CreateWindow("SDL_RenderClear", // Creació de la finestra on volem que surti el programa
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, // Establim una posició a la finestra
		1024, 768, // Mides
		SDL_WINDOW_SHOWN // Visibilitat de la pantalla
	);

	SDL_Renderer *renderer = SDL_CreateRenderer(MainWindow, -1, 0); // Actua com a inici per dibuixar la pantalla, el -1 representa el numero de gráficas y el 0 representa el numero de SDL_RendererFlags

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer); // Pantalla roja

	SDL_Rect square; //Crees el quadrat y li dones posicions
	square.x = 50;
	square.y = 50;
	square.w = 50;
	square.h = 50;

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Li apliques el color
	SDL_RenderFillRect(renderer, &square);

	SDL_RenderPresent(renderer);
	/*SDL_Delay(5000);*/ // Que la pantalla tardi uns segons en tancar
	SDL_Quit;
	system("pause");
	return EXIT_SUCCESS;
} //https://wiki.libsdl.org/SDL_CreateRenderer//Deures:Finestra vermella, quadrat blau
