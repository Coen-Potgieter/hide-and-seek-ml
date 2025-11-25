
#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>

#include "./being.h"
#include "./obstacles.h"

class World {
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

        Builder& withObjects(const Obstacles& inpObstacles) {
            this->obstacles = inpObstacles;
            return *this;
        }

        World build() {
            return World(this->num_hiders, this->num_seekers, this->obstacles);
        }
    };

   private:
    // ==================== Internal Variables ====================
    int num_hiders;
    int num_seekers;
    Obstacles obstacles;
    std::vector<Being> players;

    // ==================== Constructor ====================
    World(int inpNumHiders, int inpNumSeekers, const Obstacles& inpObstacles)
        : num_hiders(inpNumHiders),
          num_seekers(inpNumSeekers),
          obstacles(inpObstacles) {}

   public:
    // ==================== Methods ====================
    // Called to create the World object
    static Builder create() { return Builder{}; }
    // Update & Draw the World
    void update();
    void draw(sf::RenderWindow& target) const;
};

#endif
