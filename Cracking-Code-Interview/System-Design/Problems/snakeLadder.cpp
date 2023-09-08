
//Design snake and ladder game
//source: https://www.codingninjas.com/studio/library/design-snake-and-ladder-low-level-design


#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

class Player {
public:
    string name;
    int position;
    int moves;
    
    // Constructor to initialize player's name, position, and moves
    Player(string n) {
        name = n;
        position = 0;
        moves = 0;
    }
    
    // Simulate rolling a dice
    int rollDice() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 6);
        return dis(gen);
    }
    
    // Update player's position
    void move(int spaces) {
        position += spaces;
        moves++;
    }
};

class Board {
public:
    int size;
    vector<int> playerPositions;
    vector<int> snakePositions;
    vector<int> ladderPositions;
    
    // Constructor to initialize board size
    Board(int s) {
        size = s;
    }
    
    // Move the player and handle snakes and ladders
    void movePlayer(Player &p, int roll) {
        int newPos = p.position + roll;
        if (newPos > size) {
            return; // Do not move if new position is beyond board size
        }
        
        // Check if new position is a ladder or snake
        for (int i = 0; i < ladderPositions.size(); i += 2) {
            if (newPos == ladderPositions[i]) {
                newPos = ladderPositions[i + 1];
                break;
            }
        }
        for (int i = 0; i < snakePositions.size(); i += 2) {
            if (newPos == snakePositions[i]) {
                newPos = snakePositions[i + 1];
                break;
            }
        }
        p.position = newPos;
    }
    
    // Check if a player has won
    bool checkWinner(Player &p) {
        if (p.position == size) {
            cout << p.name << " wins!" << endl;
            return true;
        }
        return false;
    }
};

class Game {
public:
    Board board;
    vector<Player> players;
    vector<pair<int, int>> snakes;
    vector<pair<int, int>> ladders;
    
    // Constructor to initialize game with board size, player names, snakes, and ladders
    Game(int boardSize, vector<string> playerNames, vector<pair<int, int>> s, vector<pair<int, int>> l)
        : board(boardSize), snakes(s), ladders(l) {
        for (int i = 0; i < playerNames.size(); i++) {
            players.push_back(Player(playerNames[i]));
        }
        initializeBoard();
    }
    
    // Initialize snake and ladder positions on the board
    void initializeBoard() {
        for (int i = 0; i < snakes.size(); i++) {
            board.snakePositions.push_back(snakes[i].first);
            board.snakePositions.push_back(snakes[i].second);
        }
        for (int i = 0; i < ladders.size(); i++) {
            board.ladderPositions.push_back(ladders[i].first);
            board.ladderPositions.push_back(ladders[i].second);
        }
    }
    
    // Start the game loop
    void play() {
        while (true) {
            for (int i = 0; i < players.size(); i++) {
                int roll = players[i].rollDice();
                cout << players[i].name << " rolled a " << roll << endl;
                board.movePlayer(players[i], roll);
                cout << players[i].name << " is now on square " << players[i].position << endl;
                if (board.checkWinner(players[i])) {
                    return;
                }
            }
        }
    }
};

int main() {
    vector<string> playerNames = {"Player 1", "Player 2"};
    vector<pair<int, int>> snakes = {{17, 7}, {54, 34}};
    vector<pair<int, int>> ladders = {{62, 81}, {87, 96}};
    
    // Create a game instance and start playing
    Game game(100, playerNames, snakes, ladders);
    game.play();
    
    return 0;
}
