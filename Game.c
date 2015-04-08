#include "Game.h"

bool game_init(const char* title, int x_position, int y_position, int width, int height, bool fullscreen) {
  int flags = 0;

  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    return false;
  }

  window = SDL_CreateWindow(title, x_position, y_position, width, height, flags);

  if (window == 0) {
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (renderer == 0) {
    return false;
  }

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  game_running = true;

  SDL_Surface* tempSurface = IMG_Load("char5.png");
  texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
  SDL_FreeSurface(tempSurface);
  SDL_QueryTexture(texture, NULL, NULL, &sourceRectangle.w, &sourceRectangle.h);

  destinationRectangle.x = 0;
  destinationRectangle.y = 0;
  destinationRectangle.w = 45;
  destinationRectangle.h = 65;

  sourceRectangle.x = 0;
  sourceRectangle.y = 70;
  sourceRectangle.w = 45;
  sourceRectangle.h = 65;

  return true;
}

void game_render() {
  SDL_RenderClear(renderer);
  SDL_RenderCopyEx(renderer, texture, &sourceRectangle, &destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
  SDL_RenderPresent(renderer);
}

void game_update() {
  sourceRectangle.x = 135 * ((SDL_GetTicks() / 1000) % 4);
  // sourceRectangle.x = SDL_GetTicks() / 100;
}

void game_handle_events() {
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        game_running = false;
      break;
      default:
      break;
    }
  }
}

void game_clean() {
  SDL_DestroyTexture(texture);
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

bool is_game_running() {
  return game_running;
}
