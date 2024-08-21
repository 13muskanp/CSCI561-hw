
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <chrono>

using namespace std;

// Global variables
const int BOARD_SIZE = 12;
const int MAX_DEPTH = 5;

// Struct to store the board
struct Board {
    char board[BOARD_SIZE][BOARD_SIZE];
    int score;
    int x;
    int y;
};

// Struct to store the move
struct Move {
    int x;
    int y;
};

// Function prototypes
void readInputFile(char &player, double &time, double &opponentTime, Board &board);
void writeOutputFile(Move move);
void copyBoard(Board &newBoard, Board board);
void makeMove(Board &board, Move move, char player);
bool isLegalMove(Board board, Move move, char player);
vector<Move> getLegalMoves(Board board, char player);
int evaluateBoard(Board board, char player);
int minimax(Board board, int depth, int alpha, int beta, char player, char opponent, bool maximizingPlayer, double time, double opponentTime);
Move findBestMove(Board board, char player, double time, double opponentTime);
double getTime();
bool isGameOver(Board board, char player, char opponent);
void printBoard(Board board);

// Main function
int main() {
    char player;
    double time, opponentTime; // These will store the total remaining time for each player
    Board board;

    // Read input file
    readInputFile(player, time, opponentTime, board);
    // printBoard(board);

    auto start = std::chrono::high_resolution_clock::now(); // Start time measurement

    // Find best move
    Move bestMove = findBestMove(board, player, time, opponentTime);
    printBoard(board);

    auto end = std::chrono::high_resolution_clock::now(); // End time measurement
    std::chrono::duration<double> elapsed = end - start; // Calculate elapsed time

    time -= elapsed.count(); // Subtract the elapsed time from the player's remaining time

    // Write output file
    writeOutputFile(bestMove);

    // update the remaining time in a file or a global variable if needed for subsequent moves, show the persistence of time across moves
    ofstream timeFile;
    timeFile.open("time.txt");
    timeFile << time << endl;
    timeFile.close();

    return 0;
}

void printBoard(Board board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board.board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Function to read input file
void readInputFile(char &player, double &time, double &opponentTime, Board &board) {
    // Open input file
    ifstream inputFile;
    inputFile.open("input.txt");

    // Read input file
    inputFile >> player >> time >> opponentTime;
    for (int i = 0; i < BOARD_SIZE; i++) {
        string row;
        inputFile >> row;
        for (int j = 0; j < BOARD_SIZE; j++) {
            board.board[i][j] = row[j];
        }
    }

    // Close input file
    inputFile.close();
}

// Function to write output file
void writeOutputFile(Move move) {
    // Open output file
    ofstream outputFile;
    outputFile.open("output.txt");

    // Write output file
    outputFile << char(move.y + 'a') << move.x + 1 << endl;

    // Close output file
    outputFile.close();
}

// Function to copy the board
void copyBoard(Board &newBoard, Board board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            newBoard.board[i][j] = board.board[i][j];
        }
    }
}

// Function to make a move
void makeMove(Board &board, Move move, char player) {
    board.board[move.x][move.y] = player; // Place the piece
    char opponent = (player == 'X') ? 'O' : 'X';
    for (int direction = 0; direction < 8; direction++) {
        int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
        int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
        int x = move.x, y = move.y;
        x += dx[direction];
        y += dy[direction];
        bool foundOpponentPiece = false;
        while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board.board[x][y] == opponent) {
            foundOpponentPiece = true;
            x += dx[direction];
            y += dy[direction];
        }
        if (foundOpponentPiece && x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board.board[x][y] == player) {
            // Flip opponent pieces
            x = move.x + dx[direction];
            y = move.y + dy[direction];
            while (board.board[x][y] == opponent) {
                board.board[x][y] = player;
                x += dx[direction];
                y += dy[direction];
            }
        }
    }
    // update score here
    board.score = evaluateBoard(board, player);
    board.x = move.x;
    board.y = move.y;
}


// Function to check if a move is legal
bool isLegalMove(Board board, Move move, char player) {
    if (board.board[move.x][move.y] != '.') {
        return false; // Move must be on an empty cell
    }
    char opponent = (player == 'X') ? 'O' : 'X';
    for (int direction = 0; direction < 8; direction++) {
        int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
        int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
        int x = move.x + dx[direction], y = move.y + dy[direction];
        bool foundOpponentPiece = false;
        while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board.board[x][y] == opponent) {
            foundOpponentPiece = true;
            x += dx[direction];
            y += dy[direction];
        }
        if (foundOpponentPiece && x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board.board[x][y] == player) {
            return true; // A legal move captures at least one opponent piece
        }
    }
    return false;
}


// Function to get legal moves
vector<Move> getLegalMoves(Board board, char player) {
    vector<Move> legalMoves;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Move move = {i, j};
            if (isLegalMove(board, move, player)) {
                legalMoves.push_back(move);
            }
        }
    }
    return legalMoves;
}

// Function to evaluate the board
int evaluateBoard(Board board, char player) {
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.board[i][j] == player) {
                score++;
            }
        }
    }
    return score;
}

// Function to find the best move
Move findBestMove(Board board, char player, double time, double opponentTime) {
    Move bestMove;
    int bestScore = INT_MIN;
    vector<Move> legalMoves = getLegalMoves(board, player);
    cout<<"LEGAL "<<legalMoves.size()<<endl;
    for (int i = 0; i < legalMoves.size(); i++) {
        Board newBoard;
        copyBoard(newBoard, board);
        makeMove(newBoard, legalMoves[i], player);
        int score = minimax(newBoard, 0, INT_MIN, INT_MAX, player, (player == 'X') ? 'O' : 'X', false, time, opponentTime);
        cout << "Move: " << char(legalMoves[i].y + 'a') << legalMoves[i].x + 1 << " with score: " << score << endl;
        if (score > bestScore) {
            bestScore = score;
            bestMove = legalMoves[i];
        }
    }
    board.score = bestScore;
    board.x = bestMove.x;
    board.y = bestMove.y;
    makeMove(board, bestMove, player);
    cout << "printing best move: "<<endl;
    printBoard(board);
    cout << "Best move: " << char(bestMove.y + 'a') << bestMove.x + 1 << " with score: " << bestScore << endl;
    return bestMove;
}

// Function to get the current time
double getTime() {
    return (double)clock() / CLOCKS_PER_SEC;
}

// Function to check if the game is over
bool isGameOver(Board board, char player, char opponent) {
    if (getLegalMoves(board, player).empty() && getLegalMoves(board, opponent).empty()) {
        return true; // Game ends when neither player can move
    }
    return false;
}


// Function to implement minimax algorithm
int minimax(Board board, int depth, int alpha, int beta, char player, char opponent, bool maximizingPlayer, double time, double opponentTime) {
    if (depth == MAX_DEPTH || getTime() > time || getTime() > opponentTime) {
        return evaluateBoard(board, player);
    }
    if (isGameOver(board, player, opponent)) {
        return evaluateBoard(board, player);
    }
    if (maximizingPlayer) {
        int maxScore = INT_MIN;
        vector<Move> legalMoves = getLegalMoves(board, player);
        if(legalMoves.size() == 0){
            return evaluateBoard(board, player);
        }
        for (int i = 0; i < legalMoves.size(); i++) {
            Board newBoard;
            copyBoard(newBoard, board);
            makeMove(newBoard, legalMoves[i], player);
            int score = minimax(newBoard, depth + 1, alpha, beta, player, opponent, false, time, opponentTime);
            maxScore = max(maxScore, score);
            alpha = max(alpha, score);
            if (beta <= alpha) {
                break;
            }
        }
        return maxScore;
    } else {
        int minScore = INT_MAX;
        vector<Move> legalMoves = getLegalMoves(board, opponent);
        if(legalMoves.size() == 0){
            return evaluateBoard(board, player);
        }
        for (int i = 0; i < legalMoves.size(); i++) {
            Board newBoard;
            copyBoard(newBoard, board);
            makeMove(newBoard, legalMoves[i], opponent);
            int score = minimax(newBoard, depth + 1, alpha, beta, player, opponent, true, time, opponentTime);
            minScore = min(minScore, score);
            beta = min(beta, score);
            if (beta <= alpha) {
                break;
            }
        }
        return minScore;
    }
}

/*

at depth where are no legal moves, return the score of the board
*/
