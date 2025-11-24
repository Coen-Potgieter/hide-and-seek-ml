
#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>

#include "./being.h"

class World {
   public:
    class Builder {
       private:
        int num_hiders = 5;
        int num_seekers = 2;
        GameObjects objects{};

       public:
        Builder& withHiders(int hiders) {
            num_hiders = hiders;
            return *this;
        }
        Builder& withSeekers(int seekers) {
            num_seekers = seekers;
            return *this;
        }

        Builder& withObjects(const GameObjects& objs) {
            objects = objs;
            return *this;
        }

        World build() { return World(num_hiders, num_seekers, objects); }
    };

   private:
    int num_hiders;
    int num_seekers;
    GameObjects objects;

    // ==================== Constructor ====================
    World(int hiders, int seekers, const GameObjects& objs)
        : num_hiders(hiders), num_seekers(seekers), objects(objs) {}

   public:
    // ==================== Internal Variables ====================
    std::vector<Being> players;
    std::vector<std::vector<float>> objects;

    // ==================== Methods ====================
    // Called to create the World object
    static Builder create() { return Builder{}; }
    // Update & Draw the World
    void update();
    void draw(sf::RenderWindow& target) const;
};

#endif
