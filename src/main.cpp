#include <SFML/Graphics.hpp>
#include <iostream>

#include "./include/being.h"
#include "./include/constants.h"
#include "./include/helper_funcs.h"
#include "./include/manual_world.h"
#include "./include/obstacles.h"
#include "./include/sim_world.h"

int testingFuckYou();

int main() {
    // return testingFuckYou();

    // ==================== SFML Setup ====================
    // For smooth edges on shapes
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
                            "My Window", sf::Style::Default,
                            sf::State::Windowed, settings);

    // Fixes visual tearing casued by out of sync window with screen
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    // ==================== Program Setup ====================
    // const auto myCourse = createCourse(CourseType::BLANK);
    const auto myCourse = createCourse(CourseType::ROOMS);

    // World myWorld = World::create().build();
    // ManualWorld myWorld = ManualWorld(myCourse);
    ManualWorld myWorld = ManualWorld();
    // SimWorld myWorld = SimWorld::create()
    //                        .withObstacles(myCourse)
    //                        .withHiders(20)
    //                        .withSeekers(20)
    //                        .build();

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
            myWorld.update();
            accumulator -= DT;
        }

        // Do Rendering
        window.clear();
        // myBeing.draw(window);
        myWorld.draw(window);
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
