# Circle of Life

Project dedicated to simulating life processes and population dynamics. It aims to create a comprehensive model of ecosystem where various organisms interact with each other and their environment.

## How it works?
The simulation takes place on an NxN grid representing the ecosystem. The grid serves as the canvas where animals and plants interact, with each cell representing a specific location within the environment.

### Animals
Animals can move within the ecosystem and eat plants that they step on. Eating a plant gives them energy to walk. When its energy comes to zero, animal 
unfortunately dies. When there are more than one animal on a field, they will reproduce and create new animals. 

### Plants
Plant are not able to move. Each plant have its own energy. When its energy comes to zero, it also dies. If its greater then that,
it will grow up by adding energy to randomly chosen field around it. When an animal step on it, plant will be eaten and will lose part of its energy.

### Ecosystem
The ecosystem is just simple a NxN grid, but there are no boundaries. If an animal want to move to the right wall, it will jump over and appear on the left side of the map. The same thing happens in vertical direction.

## How it looks?

The visualization is pretty simple. Animals are red dots and plants are green dots. Check out the demo video down below:

[![Demo Video](https://img.youtube.com/vi/QOxhfn7AfWg/0.jpg)](https://www.youtube.com/watch?v=QOxhfn7AfWg)



## Instruction

At the beginning of running the project, you can adjust some parameters:
- **Map size**: define the size of your ecosystem.
- **Animals reproducing**: define the tempo of animals reproducing. The higher, the greater amount of new animals.
- **Plants growing**: define the tempo of plants growing, The higher, the greater amount of plants' energy.
When the parameters have been chosen, click "Start!" button to run your simulation. Enjoy the circle of life!

## Installation

To install the Circle of Life project, follow these steps:

1. **Clone the Repository**: Clone the project repository to your local machine using Git:

    ```bash
    git clone https://github.com/your_username/circle_of_life.git
    ```

   Replace `your_username` with your actual GitHub username.

2. **Build the Project with CMake**: Navigate to the project directory and run CMake to generate the build files:

    ```bash
    cd circle_of_life
    cmake .
    ```

   This will configure the build environment based on your system and dependencies.

3. **Build the Project**: Once CMake has generated the build files, you can build the project using your preferred build tool. For example, if you're using Make, you can run:

    ```bash
    make
    ```

   Alternatively, if you're using an integrated development environment (IDE) like Visual Studio or CLion, you can open the project directory in the IDE and build it from there.

4. **Run the Simulation**: After successfully building the project, you can run the simulation executable. Depending on how it was named during the build process, you might run:

    ```bash
    ./circle_of_life
    ```

## Summary
The Circle of Life project offers a comprehensive simulation of ecosystems, enabling users to explore the intricate dynamics of life processes and population interactions. 

Enjoy!
