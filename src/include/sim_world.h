
#ifndef SIM_WORLD_H
#define SIM_WORLD_H

#include <iostream>
#include <vector>

#include "./being.h"
#include "./obstacles.h"
#include "./world.h"

class SimWorld : public World {
   public:
    class Builder {
       private:
        int num_hiders = 5;
        int num_seekers = 2;
        Obstacles obstacles{};

       public:
        Builder& withHiders(int inpNumHiders) {
            this->num_hiders = inpNumHiders;
            return *this;
        }
        Builder& withSeekers(int inpNumSeekers) {
            this->num_seekers = inpNumSeekers;
            return *this;
        }

        Builder& withObstacles(const Obstacles& inpObstacles) {
            this->obstacles = inpObstacles;
            return *this;
        }

        SimWorld build() {
            return SimWorld(this->num_hiders, this->num_seekers,
                            this->obstacles);
        }
    };

   private:
    // ==================== Internal Variables ====================
    int num_hiders;
    int num_seekers;
    Obstacles obstacles;

    // ==================== Constructor ====================
    // Make this the only way we can create an object (using `explicit`), since
    //  this will always be done by the `Builder` exclusively
    explicit SimWorld(int inpNumHiders, int inpNumSeekers,
                      const Obstacles& inpObstacles);

   public:
    // ==================== Methods ====================
    // Called to create the SimWorld object
    static Builder create() { return Builder{}; }
};

#endif
