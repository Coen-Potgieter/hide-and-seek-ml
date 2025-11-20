# hide-and-seek-ml




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

# THINGS LEARNED (MAY TAKE OUT)
## Time Steps

### **The Core Idea**

- A GPU renders as fast as it can.
- This sim should not update as fast as it can — that leads to chaos.

We need

- **Fixed update rate** for simulation logic (`dt = e.g. 1/60`)
- **Variable render rate** depending on hardware

The accumulator pattern lets us decouple the two.

### **Breakdown Of What The Code Is Doing**

**1. Measure time since last frame**

```cpp
float frameTime = clock.restart().asSeconds();
```

This gives us *variable* frame duration — e.g. 0.016s, 0.017s, 0.015s…

**2. Prevent “spiral of death”**

If we hit a lag spike (say the OS stalls for 500ms), `frameTime` becomes huge.

So we clamp it:

```cpp
if (frameTime > 0.25f)
    frameTime = 0.25f;
```

This prevents a backlog of 200 physics updates trying to catch up at once (and freezing the game).

**3. Accumulate time into a bucket**

```cpp
accumulator += frameTime;
```

Think of the accumulator as “time debt” that needs to be paid off by fixed physics steps.

**4. Run fixed-size simulation steps**

```cpp
while (accumulator >= dt) {
    solarSystem.update();
    accumulator -= dt;
}
```

This is the heart of the pattern:

- The simulation ALWAYS updates in exactly `dt` increments (e.g. 1/120 sec). Even when the frame rate fluctuates, rendering is slow or the machine hiccups.

This ensures stable physics, deterministic simulation, no jitter, smooth rl updates, consistent learning behavior

**5. Render once per frame**

```cpp
window.clear();
bg.draw(window);
solarSystem.draw(window);
window.display();
```

Rendering is **NOT** tied to the simulation tick.


# Contributions

- [SFML - Home](https://www.sfml-dev.org/)



