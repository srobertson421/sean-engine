#include "../include/Map.hpp"
#include "../include/TextureManager.hpp"

int lvl1[20][25] = {
  {1,1,1,0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1},
  {1,1,1,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,2,2,0,0,0,0,0,0,0},
  {1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,2,2,0,0,0,0,0,0,0},
  {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0},
  {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,2,2,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,2,2,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1}
};

Map::Map() {
  dirt = TextureManager::LoadTexture("../assets/dirt.png");
  grass = TextureManager::LoadTexture("../assets/grass.png");
  water = TextureManager::LoadTexture("../assets/water.png");

  LoadMap(lvl1);

  src.x = 0;
  src.y = 0;
  src.h = 32;
  src.w = 32;
  dest.w = 32;
  dest.h = 32;
  dest.x = 0;
  dest.y = 0;
}

void Map::LoadMap(int arr[20][25]) {
  for(int row = 0; row < 20; row++) {
    for(int col = 0; col < 25; col++) {
      map[row][col] = arr[row][col];
    }
  }
}

void Map::DrawMap() {
  int type = 0;

  for(int row = 0; row < 20; row++) {
    for(int col = 0; col < 25; col++) {
      type = map[row][col];
      dest.x = col * 32;
      dest.y = row * 32;
      switch(type) {
        case 0:
          // display water
          TextureManager::Draw(water, src, dest);
          break;
        case 1:
          // display grass
          TextureManager::Draw(grass, src, dest);
          break;
        case 2:
          //display dirt
          TextureManager::Draw(dirt, src, dest);
          break;
        default:
          break;
      }
    }
  }
}