#include <stdio.h>
#include <stdbool.h>

#include "SDL.h"

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Texture* texture;
SDL_Rect sourceRectangle;
SDL_Rect destinationRectangle;

bool game_running;

bool game_init(const char* title, int x_position, int y_position, int width, int height, bool fullscreen);

void game_render();

void game_update();

void game_handle_events();

void game_clean();

bool is_game_running();

