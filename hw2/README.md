#### Overview
This project implements a game board with pathfinding and move evaluation capabilities. The code includes definitions for the board and move structures, as well as global constants for board size and search depth.

#### Key Components

1. **Global Constants**:
    - [`BOARD_SIZE`](command:_github.copilot.openSymbolFromReferences?%5B%22BOARD_SIZE%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A15%2C%22character%22%3A10%7D%7D%5D%5D "Go to definition"): Size of the game board (12x12).
    - [`MAX_DEPTH`](command:_github.copilot.openSymbolFromReferences?%5B%22MAX_DEPTH%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A16%2C%22character%22%3A10%7D%7D%5D%5D "Go to definition"): Maximum depth for search algorithms (5).

2. **Board Structure**:
    - Represents the game board as a 2D array of characters.
    - Contains additional attributes for score and coordinates ([`x`](command:_github.copilot.openSymbolFromReferences?%5B%22x%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A22%2C%22character%22%3A8%7D%7D%5D%5D "Go to definition"), [`y`](command:_github.copilot.openSymbolFromReferences?%5B%22y%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A23%2C%22character%22%3A8%7D%7D%5D%5D "Go to definition")).

3. **Move Structure**:
    - Represents a move with coordinates ([`x`](command:_github.copilot.openSymbolFromReferences?%5B%22x%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A22%2C%22character%22%3A8%7D%7D%5D%5D "Go to definition"), [`y`](command:_github.copilot.openSymbolFromReferences?%5B%22y%22%2C%5B%7B%22uri%22%3A%7B%22%24mid%22%3A1%2C%22fsPath%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22scheme%22%3A%22file%22%7D%2C%22pos%22%3A%7B%22line%22%3A23%2C%22character%22%3A8%7D%7D%5D%5D "Go to definition")).

#### Files
- [`homework.cpp`](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2FUsers%2Fmuskanp%2FDesktop%2FCSCI561-hw%2Fhw2%2Fhomework.cpp%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/Users/muskanp/Desktop/CSCI561-hw/hw2/homework.cpp"): Contains the main implementation of the game board and move structures.

#### Compilation and Execution
```sh
g++ -o game homework.cpp
./game
```

This will compile and run the program, initializing the game board and allowing for move evaluations.
