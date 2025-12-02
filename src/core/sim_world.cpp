
#include "../include/sim_world.h"

#include "../include/neural_controller.h"

SimWorld::SimWorld(int inpNumHiders, int inpNumSeekers,
                   const Obstacles& inpObstacles)
    : World(inpObstacles),
      num_hiders(inpNumHiders),
      num_seekers(inpNumSeekers) {
    // Remove Keyboard controlled hiders and seekers
    this->hiders.erase(this->hiders.begin());
    this->seekers.erase(this->seekers.begin());

    // Add neural controlled hiders and seekers
    for (size_t i = 0; i < this->num_hiders; i++)
        this->hiders.push_back(Hider(new NeuralController));
    for (size_t i = 0; i < this->num_seekers; i++)
        this->seekers.push_back(Seeker(new NeuralController));
}
