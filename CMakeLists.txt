cmake_minimum_required(VERSION 3.28)
project(solar-system-2d LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)


# Set source files
set(SOURCES
    ./src/main.cpp
    ./src/core/world.cpp
    ./src/core/sim_world.cpp
    ./src/core/manual_word.cpp
    ./src/core/being.cpp
    ./src/core/hider.cpp
    ./src/core/seeker.cpp
    ./src/core/keyboard_controller.cpp
    ./src/core/neural_controller.cpp
    ./src/core/obstacles.cpp
    ./src/core/helper_funcs.cpp
)


# Set headers files
set(HEADERS
    ./src/include/world.h
    ./src/include/sim_world.h
    ./src/include/manual_world.h
    ./src/include/being.h
    ./src/include/hider.h
    ./src/include/seeker.h
    ./src/include/obstacles.h
    ./src/include/controller.h
    ./src/include/keyboard_controller.h
    ./src/include/neural_controller.h
    ./src/include/constants.h
    ./src/include/helper_funcs.h

)

add_executable(main ${SOURCES} ${HEADERS})
target_compile_features(main PRIVATE cxx_std_17)
target_include_directories(main PRIVATE src/) 
target_link_libraries(main PRIVATE SFML::Graphics)

# Add run target that depends on the main executable
add_custom_target(run
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --green --bold "Running the application..."
    COMMAND ${CMAKE_COMMAND} -E echo "" # Adds line after terminal output of program
    COMMAND ./bin/main
    COMMAND ${CMAKE_COMMAND} -E echo "" # Adds line after terminal output of program
    COMMAND ${CMAKE_COMMAND} -E echo "------------------ Program Ended ---------------------\n"
    COMMAND ${CMAKE_COMMAND} -E echo "" # Adds line after terminal output of program
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
