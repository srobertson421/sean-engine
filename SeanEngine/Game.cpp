#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "ECS.hpp"
#include "Components.hpp"

Game::Game() {}
Game::~Game() {}

GameObject* player;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

  int flags = 0;
  if(fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    // SDL Initialized correctly
    std::cout << "SDL Subsystems Initialized" << std::endl;

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(window) {
      std::cout << "Window Successfully Created" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer Successfully Created" << std::endl;
    }

    isRunning = true;
  } else {
    isRunning = false;
  }

  player = new GameObject("../assets/player.png", 0, 0);
  map = new Map();
  newPlayer.addComponent<PositionComponent>();
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch(event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;
    default:
      break;
  }
}

void Game::update() {
  player->Update();
  manager.update();
  std::cout << newPlayer.getComponent<PositionComponent>().x() << " : " << newPlayer.getComponent<PositionComponent>().y() << std::endl;
}

void Game::render() {
  SDL_RenderClear(renderer);
  map->DrawMap();
  player->Render();
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game Cleaned" << std::endl;
}
