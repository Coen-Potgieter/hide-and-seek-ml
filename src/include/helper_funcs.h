

#ifndef HELPER_FUNCS_H
#define HELPER_FUNCS_H

enum CourseType { BLANK, ROOMS };

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>

#include "./constants.h"

// Pre-processing Operations
void printMartix(const std::vector<std::vector<float>>& inpMatrix);

bool areColliding(const sf::FloatRect& boundingBox1,
                  const sf::FloatRect& boundingBox2);

std::vector<std::array<float, 4>> createCourse(CourseType inpCourseType);
#endif
