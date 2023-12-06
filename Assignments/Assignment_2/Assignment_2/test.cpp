////required library:
//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//#include<Windows.h>
//#include<conio.h>
//#include <string>
//#include <fstream>
//using namespace std;
//// Assuming start_time is a global variable or declared in the appropriate scope:
//time_t start_time = time(0);
//
//const int BEGINNER = 0;
//const int INTERMEDIATE = 1;
//const int ADVANCED = 2;
//const int MAXSIDE = 25;
//const int MAXMINES = 99;
//const int MOVESIZE = 526; // (25 * 25 - 99)
//
//int SIDE; // side length of the board
//int MINES; // number of mines on the board
//int timer = 60;
//int scores = 0;
//int rowNeighbours[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
//int colNeighbours[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
//
////Functions Prototypes:
//bool isValid(int row, int col);
//bool isMine(int row, int col, char board[][MAXSIDE]);
//void makeMove(int& x, int& y);
//void printBoard(char myBoard[][MAXSIDE]);
//int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE]);
//bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE],
//    int mines[][2], int row, int col, int& movesLeft);
//void placeMines(int mines[][2], char realBoard[][MAXSIDE]);
//void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE]);
//void cheatMinesweeper(char realBoard[][MAXSIDE]);
//void replaceMine(int row, int col, char board[][MAXSIDE]);
//void playMinesweeper();
//void chooseDifficultyLevel();
//void updateScoreboard(int score, int rollNumber);
//void displayLeaderboard();
//
//int rollNumber; // Assuming you have a variable to store the player's roll number.
//
////Function For the difficulty Level of Game:
//void chooseDifficultyLevel() {
//    int level;
//    cout << "Enter the Difficulty Level\n";
//    cout << "Press 0 for BEGINNER (9 * 9 Cells and 10 Mines)\n";
//    cout << "Press 1 for INTERMEDIATE (16 * 16 Cells and 40 Mines)\n";
//    cout << "Press 2 for ADVANCED (24 * 24 Cells and 99 Mines)\n";
//    cin >> level;
//    if (level == BEGINNER) {
//        SIDE = 9;
//        MINES = 10;
//    }
//    if (level == INTERMEDIATE) {
//        SIDE = 16;
//        MINES = 40;
//    }
//    if (level == ADVANCED) {
//        SIDE = 24;
//        MINES = 99;
//    }
//}
//
////Function For Movement of Rows and Columns:
//void makeMove(int& x, int& y) {
//    cout << "Enter your move, (row, column) -> ";
//    cin >> x >> y;
//    start_time = time(0); // Start or reset the timer.
//}
//
////Timer:
//bool isTimeOver() {
//    return start_time <= 0;
//}
//
////Function for Updated Board:
//void updateScoreboard(int score, int rollNumber) {
//    cout << "Roll Number: " << rollNumber << " Score: " << score << "\n";
//    std::ofstream scoreboardFile("scoreboard.txt", ios::app); // Append mode
//    if (scoreboardFile.is_open()) {
//        scoreboardFile << "a";
//        scoreboardFile << "Roll Number: " << rollNumber << " Score: " << score << "\n";
//
//        scoreboardFile.close();
//    }
//    else {
//        cout << "Error opening the scoreboard file for writing.\n";
//    }
//}
//
////Function to display Leaderboard:
//void displayLeaderboard() {
//    cout << "Leaderboard:\n";
//    ifstream scoreboardFile("scoreboard.txt");
//    if (scoreboardFile.is_open()) {
//        string line;
//        while (getline(scoreboardFile, line)) {
//            cout << line << endl;
//        }
//        scoreboardFile.close();
//    }
//    else {
//        cout << "Unable to open scoreboard file.\n";
//    }
//}
//
////Main Function to play minesweeper:
//void playMinesweeper() {
//    bool gameOver = false;
//    char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE];
//    int movesLeft = SIDE * SIDE - MINES, x, y;
//    int mines[MAXMINES][2];
//    initialise(realBoard, myBoard);
//    placeMines(mines, realBoard);
//    int currentMoveIndex = 0;
//    int score = 0;
//    while (gameOver == false  && timer >= 0) {
//        system("CLS");
//     
//        cout << "Scores :" << score;
//        score = SIDE * SIDE - MINES - movesLeft;
//        cout << "\nTimer :" << timer<<endl;
//    //    cout << "\nScores :" << score;
//        cout << "Press Enter To move \n";
//        cout << "Current Status of Board: \n";
//        printBoard(myBoard);
//        if (_kbhit()) {
//            char keyPress = _getch();
//
//            if (keyPress == 13) // ASCII FOR ENTER
//            {
//                makeMove(x, y);
//                updateScoreboard(SIDE * SIDE - MINES - movesLeft, rollNumber);
//                if (currentMoveIndex == 0) {
//                    if (isMine(x, y, realBoard))
//                        replaceMine(x, y, realBoard);
//                }
//                currentMoveIndex++;
//                gameOver = playMinesweeperUtil(myBoard, realBoard, mines, x, y, movesLeft);
//            }
//        }
//       
//        if (!gameOver && movesLeft == 0) {
//            cout << "\nYou won!\n";
//            gameOver = true;
//        }
//        timer--;
//        Sleep(1000);
//    }
//
//    // Update scoreboard when the game is over
//    updateScoreboard(score, rollNumber);
//}
//
//void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE]) {
//    srand(time(NULL));
//    for (int i = 0; i < SIDE; i++) {
//        for (int j = 0; j < SIDE; j++) {
//            myBoard[i][j] = realBoard[i][j] = '-';
//        }
//    }
//}
//
//void placeMines(int mines[][2], char realBoard[][MAXSIDE]) {
//    bool mark[MAXSIDE * MAXSIDE];
//    memset(mark, false, sizeof(mark));
//    for (int i = 0; i < MINES;) {
//        int random = rand() % (SIDE * SIDE);
//        int x = random / SIDE;
//        int y = random % SIDE;
//        if (mark[random] == false) {
//            mines[i][0] = x;
//            mines[i][1] = y;
//            realBoard[mines[i][0]][mines[i][1]] = '*';
//            mark[random] = true;
//            i++;
//        }
//    }
//}
//
//bool isValid(int row, int col) {
//    return (row >= 0) && (row < SIDE) && (col >= 0) && (col < SIDE);
//}
//
//bool isMine(int row, int col, char board[][MAXSIDE])
//{
//    return (board[row][col] == '*');
//}
//void printBoard(char myBoard[][MAXSIDE]) {
//    int i, j;
//    cout << "   ";
//    for (i = 0; i < SIDE; i++) {
//        if (i > 9) {
//            cout << i << "  ";
//        }
//        else cout << i << "   ";
//    }
//    cout << "\n\n";
//
//    for (i = 0; i < SIDE; i++) {
//        if (i <= 9)
//            cout << i << "  ";
//        else cout << i << " ";
//        for (j = 0; j < SIDE; j++)
//            cout << myBoard[i][j] << "   ";
//        cout << "\n";
//    }
//}
//
//
//int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE]) {
//    int i;
//    int count = 0;
//    for (i = 0; i < 8; i++) {
//        int newRow = row + rowNeighbours[i];
//        int newCol = col + colNeighbours[i];
//        if (isValid(newRow, newCol) && isMine(newRow, newCol, realBoard))
//            count++;
//    }
//    return count;
//}
//
//bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE],
//    int mines[][2], int row, int col, int& movesLeft) {
//    if (myBoard[row][col] != '-')
//        return false;
//    if (realBoard[row][col] == '*') {
//        myBoard[row][col] = '*';
//        for (int i = 0; i < MINES; i++)
//            myBoard[mines[i][0]][mines[i][1]] = '*';
//        printBoard(myBoard);
//        cout << "\nYou lost!\n";
//        return true;
//    }
//    else {
//        int count = countAdjacentMines(row, col, mines, realBoard);
//        movesLeft--;
//        myBoard[row][col] = count + '0';
//        if (count == 0) {
//            for (int i = 0; i < 8; i++) {
//                int newRow = row + rowNeighbours[i];
//                int newCol = col + colNeighbours[i];
//                if (isValid(newRow, newCol) && isMine(newRow, newCol, realBoard) == false)
//                    playMinesweeperUtil(myBoard, realBoard, mines, newRow, newCol, movesLeft);
//            }
//        }
//        return false;
//    }
//}
//
//void cheatMinesweeper(char realBoard[][MAXSIDE]) {
//    cout << "The mines locations are-\n";
//    printBoard(realBoard);
//}
//
//void replaceMine(int row, int col, char board[][MAXSIDE]) {
//    for (int i = 0; i < SIDE; i++) {
//        for (int j = 0; j < SIDE; j++)
//        {
//            if (board[i][j] != '*') {
//                board[i][j] = '*';
//                board[row][col] = '-';
//                return;
//            }
//        }
//    }
//}
//
//int main() {
//    chooseDifficultyLevel();
//    cout << "Enter your Roll Number: ";
//    cin >> rollNumber;
//    playMinesweeper();
//    displayLeaderboard();
//    return 0;
//}