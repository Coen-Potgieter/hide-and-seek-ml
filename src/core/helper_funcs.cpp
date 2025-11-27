

#include "../include/helper_funcs.h"

#include <iostream>

void printMartix(const std::vector<std::vector<float>>& inpMatrix) {
    for (size_t rowIdx = 0; rowIdx < inpMatrix.size(); rowIdx++) {
        size_t numElems = inpMatrix[rowIdx].size();
        for (size_t elemIdx = 0; elemIdx < numElems; elemIdx++) {
            std::cout << inpMatrix[rowIdx][elemIdx];
            if (elemIdx != numElems - 1) std::cout << ',';
            std::cout << ' ';
        }
        std::cout << '\n';
    }
    return;
}

bool areColliding(const sf::FloatRect& boundingBox1,
                  const sf::FloatRect& boundingBox2) {
    if (const std::optional intersection =
            boundingBox1.findIntersection(boundingBox2))
        return true;
    else
        return false;
}

std::vector<std::array<float, 4>> createCourse(CourseType inpCourseType) {
    std::vector<std::array<float, 4>> myCourse;

    // ---- Actual In game obstacles
    if (inpCourseType == CourseType::BLANK) {
    } else if (inpCourseType == CourseType::ROOMS) {
        std::vector<std::array<float, 4>> room1 = {
            {5, 300, 150, 0},  {105, 5, 200, 150}, {5, 50, 250, 175},
            {5, 50, 250, 250}, {5, 25, 250, 312},  {225, 5, 140, 325}};
        myCourse.insert(myCourse.end(), room1.begin(), room1.end());

        std::vector<std::array<float, 4>> room2 = {
            {5, 300, WINDOW_WIDTH - 150, 0},
            {105, 5, WINDOW_WIDTH - 200, 150},
            {5, 50, WINDOW_WIDTH - 250, 175},
            {5, 50, WINDOW_WIDTH - 250, 250},
            {5, 25, WINDOW_WIDTH - 250, 312},
            {225, 5, WINDOW_WIDTH - 140, 325}};
        myCourse.insert(myCourse.end(), room2.begin(), room2.end());

        std::vector<std::array<float, 4>> room3 = {
            {5, 300, 150, WINDOW_HEIGHT},
            {105, 5, 200, WINDOW_HEIGHT - 150},
            {5, 50, 250, WINDOW_HEIGHT - 175},
            {5, 50, 250, WINDOW_HEIGHT - 250},
            {5, 25, 250, WINDOW_HEIGHT - 312},
            {225, 5, 140, WINDOW_HEIGHT - 325}};
        myCourse.insert(myCourse.end(), room3.begin(), room3.end());

        std::vector<std::array<float, 4>> room4 = {
            {5, 300, WINDOW_WIDTH - 150, WINDOW_HEIGHT},
            {105, 5, WINDOW_WIDTH - 200, WINDOW_HEIGHT - 150},
            {5, 50, WINDOW_WIDTH - 250, WINDOW_HEIGHT - 175},
            {5, 50, WINDOW_WIDTH - 250, WINDOW_HEIGHT - 250},
            {5, 25, WINDOW_WIDTH - 250, WINDOW_HEIGHT - 312},
            {225, 5, WINDOW_WIDTH - 140, WINDOW_HEIGHT - 325}};
        myCourse.insert(myCourse.end(), room4.begin(), room4.end());
    }

    // ---- Boundaries of Game
    // Top Boundary
    myCourse.push_back({WINDOW_WIDTH, 10, WINDOW_WIDTH / 2, 0});
    // Bottom Boundary
    myCourse.push_back({WINDOW_WIDTH, 10, WINDOW_WIDTH / 2, WINDOW_HEIGHT});
    // Left Boundary
    myCourse.push_back({10, WINDOW_HEIGHT, 0, WINDOW_HEIGHT / 2});
    // // Right Boundary
    myCourse.push_back({10, WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT / 2});
    return myCourse;
}
