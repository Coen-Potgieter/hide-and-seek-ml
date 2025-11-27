

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <stdint.h>

#include <SFML/Graphics.hpp>
#include <array>
#include <utility>
#include <vector>

// Window Config
constexpr uint16_t WINDOW_WIDTH = 1300;
constexpr uint16_t WINDOW_HEIGHT = 800;
constexpr float PI = 3.141592653589793;
constexpr float DT = 0.01f;

// constexpr uint16_t LEFT_MARGIN = 20;
// constexpr uint16_t RIGHT_MARGIN = 350;
// constexpr uint16_t VERTICAL_MARGIN = 20;

// constexpr uint16_t MAIN_START_X = LEFT_MARGIN;
// constexpr uint16_t MAIN_END_X = WINDOW_WIDTH - RIGHT_MARGIN;

// constexpr uint16_t MAIN_START_Y = VERTICAL_MARGIN;
// constexpr uint16_t MAIN_END_Y = WINDOW_HEIGHT - VERTICAL_MARGIN;

// UI
// constexpr sf::Color BG = sf::Color(237, 241, 214);
// constexpr sf::Color SLIDER_AXIS_COL = sf::Color(157, 192, 139);
// constexpr sf::Color TEXT_COL = sf::Color(64, 81, 59);

// Being Config
constexpr sf::Color BEING_COL = sf::Color(7, 128, 5);
constexpr float BEING_SIZE = 3;
/* constexpr sf::Color BIRD_COL = sf::Color(96, 153, 102); */
/* constexpr sf::Color BIRD_COL = sf::Color(16, 135, 14); */
/* const sf::Color BIRD_COL = sf::Color::Blue; */

#endif
