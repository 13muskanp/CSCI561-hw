#### Overview
This project implements a graph-based pathfinding solution for navigating a terrain with elevation changes. The algorithms used include Breadth-First Search (BFS), Uniform Cost Search (UCS), and A* Search. The graph represents nodes with coordinates and edges with costs based on Euclidean distance.

#### Files
- [`homework.cpp`](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/Users/muskanp/Desktop/CSCI561-hw/hw1/homework.cpp"): Contains the main implementation of the graph, nodes, and pathfinding algorithms.

#### Key Components

1. **Node Structure**:
    - Represents a point in the graph with coordinates (x, y, z) and a list of edges to other nodes.

2. **Graph Class**:
    - Manages nodes and edges.
    - Methods:
        - [`addNode(name, x, y, z)`](command:_github.copilot.openSymbolFromReferences?%5B%22addNode(name%2C%20x%2C%20y%2C%20z)%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A42%2C%22character%22%3A9%7D%7D%5D%5D "Go to definition"): Adds a node to the graph.
        - [`addEdge(from, to)`](command:_github.copilot.openSymbolFromReferences?%5B%22addEdge(from%2C%20to)%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A46%2C%22character%22%3A9%7D%7D%5D%5D "Go to definition"): Adds an edge between two nodes with a cost based on Euclidean distance.

3. **Pathfinding Algorithms**:
    - **BFS**: Explores nodes level by level.
    - **UCS**: Explores nodes based on the lowest cumulative cost.
    - **A***: Uses a heuristic to guide the search towards the goal.

4. **Helper Functions**:
    - [`isMoveAllowed(from, to, energyLimit, momentum)`](command:_github.copilot.openSymbolFromReferences?%5B%22isMoveAllowed(from%2C%20to%2C%20energyLimit%2C%20momentum)%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A56%2C%22character%22%3A5%7D%7D%5D%5D "Go to definition"): Checks if a move is allowed based on energy and momentum.
    - [`calculate3DDistance(from, to)`](command:_github.copilot.openSymbolFromReferences?%5B%22calculate3DDistance(from%2C%20to)%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A134%2C%22character%22%3A7%7D%7D%5D%5D "Go to definition"): Calculates the 3D Euclidean distance between two nodes.
    - [`heuristic(current, goal)`](command:_github.copilot.openSymbolFromReferences?%5B%22heuristic(current%2C%20goal)%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A138%2C%22character%22%3A7%7D%7D%5D%5D "Go to definition"): Heuristic function for A*.
    - [`reconstructPath(cameFrom, start, goal)`](command:_github.copilot.openSymbolFromReferences?%5B%22reconstructPath(cameFrom%2C%20start%2C%20goal)%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A142%2C%22character%22%3A15%7D%7D%5D%5D "Go to definition"): Reconstructs the path from start to goal.

5. **Input Parsing**:
    - [`parseInput(filename, algorithm, energyLimit, graph)`](command:_github.copilot.openSymbolFromReferences?%5B%22parseInput(filename%2C%20algorithm%2C%20energyLimit%2C%20graph)%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A285%2C%22character%22%3A5%7D%7D%5D%5D "Go to definition"): Reads the input file to initialize the graph and parameters.

6. **Main Function**:
    - Reads input from [`input.txt`](command:_github.copilot.openSymbolFromReferences?%5B%22input.txt%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A314%2C%22character%22%3A16%7D%7D%5D%5D "Go to definition").
    - Executes the specified algorithm (BFS, UCS, A*).
    - Writes the result to [`output.txt`](command:_github.copilot.openSymbolFromReferences?%5B%22output.txt%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A325%2C%22character%22%3A25%7D%7D%5D%5D "Go to definition").

#### Usage
1. **Input File ([`input.txt`](command:_github.copilot.openSymbolFromReferences?%5B%22input.txt%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A314%2C%22character%22%3A16%7D%7D%5D%5D "Go to definition"))**:
    - First line: Algorithm name ([`BFS`](command:_github.copilot.openSymbolFromReferences?%5B%22BFS%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A72%2C%22character%22%3A15%7D%7D%5D%5D "Go to definition"), [`UCS`](command:_github.copilot.openSymbolFromReferences?%5B%22UCS%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A155%2C%22character%22%3A15%7D%7D%5D%5D "Go to definition"), [`A*`](command:_github.copilot.openSymbolFromReferences?%5B%22A*%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A321%2C%22character%22%3A29%7D%7D%5D%5D "Go to definition")) and energy limit.
    - Second line: Number of nodes.
    - Next lines: Node details (name, x, y, z).
    - Next line: Number of edges.
    - Remaining lines: Edge details (from, to).

2. **Output File ([`output.txt`](command:_github.copilot.openSymbolFromReferences?%5B%22output.txt%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A325%2C%22character%22%3A25%7D%7D%5D%5D "Go to definition"))**:
    - Contains the path from start to goal or "FAIL" if no path is found.

#### Example
**Input ([`input.txt`](command:_github.copilot.openSymbolFromReferences?%5B%22input.txt%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A314%2C%22character%22%3A16%7D%7D%5D%5D "Go to definition"))**:
```
A* 10
3
start 0 0 0
mid 1 1 1
goal 2 2 2
2
start mid
mid goal
```

**Output ([`output.txt`](command:_github.copilot.openSymbolFromReferences?%5B%22output.txt%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A325%2C%22character%22%3A25%7D%7D%5D%5D "Go to definition"))**:
```
start mid goal
```

#### Compilation and Execution
```sh
g++ -o pathfinder homework.cpp
./pathfinder
```

This will read the input, execute the specified algorithm, and write the result to [`output.txt`](command:_github.copilot.openSymbolFromReferences?%5B%22output.txt%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw1%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A325%2C%22character%22%3A25%7D%7D%5D%5D "Go to definition").
