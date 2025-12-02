
#ifndef NEURAL_CONTROLLER_H
#define NEURAL_CONTROLLER_H

#include <random>

#include "./controller.h"

class NeuralController : public Controller {
   private:
    // Seed Source
    std::random_device rd{};
    // Random Number Engine
    std::mt19937 engine{rd()};

   public:
    Action getAction(const Being &self, const World &world) override;
};

#endif
