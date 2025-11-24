#include <SFML/Graphics.hpp>
#include <iostream>

#include "./include/being.h"
#include "./include/constants.h"
#include "./include/helper_funcs.h"
#include "./include/world.h"

int testingFuckYou();

int main() {
    // return testingFuckYou();

    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    // Create World
    World myWorld;

    return 0;

    // Create Being
    Being myBeing;

    // Setup Clock for fixed time steps
    sf::Clock clock;

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        while (const std::optional event = window.pollEvent()) {
            // Close window: exit
            if (event->is<sf::Event::Closed>()) window.close();
        }
        static float accumulator = 0.0f;
        float frameTime = clock.restart().asSeconds();

        if (frameTime > 0.25f) frameTime = 0.25f;

        accumulator += frameTime;

        while (accumulator >= DT) {
            // Do next simulation Step
            myBeing.move();
            accumulator -= DT;
        }

        // Do Rendering
        window.clear();
        myBeing.draw(window);
        window.display();
    }
    return 0;
}

int testingFuckYou() {
    std::vector<std::vector<float>> myTestVector = {
        {1, 2, 3, 4, 5, 5, 6},
        {1, 2, 3, 4, 5, 5, 6},
        {1, 4, 5, 5, 6},
        {1, 2, 3, 4, 5, 5, 6},
    };
    printMartix(myTestVector);
    return 0;
}
