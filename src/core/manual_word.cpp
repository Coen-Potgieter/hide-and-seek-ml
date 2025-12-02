
#include "../include/manual_world.h"

ManualWorld::ManualWorld() : World() { this->addPlayers(); }

ManualWorld::ManualWorld(const Obstacles& inpObstacles) : World(inpObstacles) {
    this->addPlayers();
}

void ManualWorld::addPlayers() {
    this->hiders.push_back(Hider(new KeyboardController));
    this->seekers.push_back(Seeker(new KeyboardController));
}
