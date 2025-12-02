
#include "../include/world.h"

// ==================== Constructors ====================
// Default constructor with font initialisation
World::World() { this->initText("../src/assets/fonts/arial.ttf"); }

// Constructor to initialise obstacles provided
World::World(const Obstacles& inpObstacles) {
    this->obstacles = inpObstacles;
    this->initText("../src/assets/fonts/arial.ttf");
}

void World::initText(const std::string& fontSrc) {
    // Load Font
    if (!this->endProgramFont.openFromFile(fontSrc)) {
        throw std::runtime_error("Font Could Not Be Found");
    }

    // Init Text
    float textSize = 32;
    this->endingText.emplace(this->endProgramFont, "Game Over",
                             static_cast<int>(textSize));
    // set the color
    this->endingText->setFillColor(sf::Color::Red);
    // set the text style
    this->endingText->setStyle(sf::Text::Bold | sf::Text::Underlined);
    // Center the origin
    sf::FloatRect bounds = this->endingText->getLocalBounds();
    this->endingText->setOrigin(
        {bounds.position.x / 2.f, bounds.position.y / 2.f});
    // Set position in middle of the screen
    this->endingText->setPosition(
        {WINDOW_WIDTH / 2.f - textSize, WINDOW_HEIGHT / 2.f - textSize});
}

// ==================== Getters ====================
Obstacles World::getObstacles() const { return this->obstacles; }
std::vector<Hider> World::getHiders() const { return this->hiders; }
std::vector<Seeker> World::getSeekers() const { return this->seekers; }

// ==================== Setters ====================
void World::setGameEnded(bool isGameEnded) { this->ended = isGameEnded; }

// ==================== World Logic ====================
void World::update() {
    for (Hider& hider : this->hiders) hider.update(*this);
    for (Seeker& seeker : this->seekers) seeker.update(*this);
}

void World::draw(sf::RenderWindow& target) const {
    if (!this->ended) {
        this->obstacles.draw(target);
        for (const Hider& hider : this->hiders) hider.draw(target);
        for (const Seeker& seeker : this->seekers) seeker.draw(target);
    } else {
        target.draw(*this->endingText);
    }
}
