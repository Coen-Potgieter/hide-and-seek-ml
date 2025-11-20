# hide-and-seek-ml


## Setup




## Mac OS Setup 💻

### Prerequisites

1. Ensure You Have Git Installed
    - *Not Explaining This...*

2. Ensure You Have The **SFML Libraries** Installed:
    - Using Homebrew
        ```bash
        brew install sfml
        ```

    - Using ATP
        ```bash
        sudo apt update sudo apt install \
        libxrandr-dev \
        libxcursor-dev \
        libxi-dev \
        libudev-dev \
        libflac-dev \
        libvorbis-dev \ 
        libgl1-mesa-dev \
        libegl1-mesa-dev \
        libdrm-dev \
        libgbm-dev
        ```

    - From [official SFML website](https://www.sfml-dev.org/download/)

3. Ensure You Have The **CMake** Installed:

    - Using Homebrew
        ```bash
        brew install cmake
        ```

    - Using ATP
        ```bash
        sudo apt install cmake
        ```

### Build & Run

1. **Build The Project**:
    - In the root directory run:
        ```bash
        mkdir build
        cd build
        cmake ..
        make
        ```

2. **Run The Application**
    - Simply Execute:
        ```bash
        ./bin/main
        ```

# Contributions

- [SFML - Home](https://www.sfml-dev.org/)


