

#include "../include/neural_controller.h"

#include "../include/being.h"

Action NeuralController::getAction(const Being &self, const World &world) {
    // Distribution
    std::uniform_int_distribution<int> unifDistr(0, 3);

    Action beingAction = {0.f, 0.f};

    int randomNum = unifDistr(this->engine);

    if (randomNum == 0)
        beingAction.moveY -= self.getSpeed();
    else if (randomNum == 1)
        beingAction.moveY += self.getSpeed();
    else if (randomNum == 2)
        beingAction.moveX += self.getSpeed();
    else if (randomNum == 3)
        beingAction.moveX -= self.getSpeed();

    return beingAction;
}
