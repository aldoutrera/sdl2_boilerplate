#include "Game.h"

int main(int argc, char* argv[]) {
  game_init("Title", 100, 100, 640, 480, false);

  while(is_game_running()) {
    game_handle_events();
    game_update();
    game_render();
  }

  game_clean();

  return 0;
}
