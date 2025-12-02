
#ifndef MANUAL_WORLD_H
#define MANUAL_WORLD_H

#include "./world.h"

class ManualWorld : public World {
   private:
    void addPlayers();

   public:
    ManualWorld();
    ManualWorld(const Obstacles& inpObstacles);
};
#endif
