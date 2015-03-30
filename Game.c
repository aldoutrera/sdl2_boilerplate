#include "Game.h"

bool game_init(const char* title, int x_position, int y_position, int width, int height, int flags) {
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

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  game_running = true;
  return true;
}

void game_render() {
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

void game_update() {
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
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

bool is_game_running() {
  return game_running;
}
