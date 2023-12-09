////Minesweeper:
////PF Lab Final Project:
////Made by: 23F-0740 , 23F-0723 , 23F-0823:
//
//
////required library:
//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//#include<Windows.h> // for Sleep(1000) 1000 mean 1 second delay
//#include<conio.h> // for kbhit this function is use to get key input from keyboard if key is not pressed then it ignore to get input and continue execution
//#include <string>
//#include <fstream>
//
//using namespace std;
//// Assuming start_time is a global variable or declared in the appropriate scope:
//time_t start_time = time(0);
//// decleration of level 
//const int BEGINNER = 0;
//const int INTERMEDIATE = 1;
//const int ADVANCED = 2;
//// declare side 
//const int MAXSIDE = 25;
//// declare maximum mines 
//const int MAXMINES = 99;
//// declare moves size
//const int MOVESIZE = 526; // (25 * 25 - 99)
//// side length of the board
//int SIDE;
//// number of mines on the board
//int MINES;
//// initalize time
//int timer = 60;
//// initalize score
//int scores = 0;
//// declare row and colums
//int rowNeighbours[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
//int colNeighbours[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
//
////Functions Prototypes:
//bool isValid(int row, int col);
//bool isMine(int row, int col, char board[][MAXSIDE]);
//void makeMove(int& x, int& y);
//void printBoard(char myBoard[][MAXSIDE]);
//int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE]);
//bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE], int mines[][2], int row, int col, int& movesLeft, int isHint);
//void placeMines(int mines[][2], char realBoard[][MAXSIDE]);
//void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE]);
//void cheatMinesweeper(char realBoard[][MAXSIDE]);
//void replaceMine(int row, int col, char board[][MAXSIDE]);
//void playMinesweeper();
//void chooseDifficultyLevel();
//void updateScoreboard(int score, int rollNumber);
//void displayLeaderboard();
//
//
//void displayHint(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE],
//    int mines[][2], int& movesLeft, int timer) {
//    if (timer > 0 && timer % 10 == 2) {
//        int random_x = rand() % SIDE;
//        int random_y = rand() % SIDE;
//        if(realBoard[random_x][random_y] !='*') {
//        if (myBoard[random_x][random_y] == '-') {
//            myBoard[random_x][random_y] ='H';
//        }
//        }
//    }
//}
//
//void clearHint(char myboard[][MAXSIDE]) {
//    for (int i = 0; i < SIDE; i++)
//    {
//        for (int j = 0; j < SIDE; j++) {
//            if (myboard[i][j] == 'H') {
//                myboard[i][j] = '-';
//            }
//        }
//    }
//}
//
//
//// Assuming you have a variable to store the player's roll number.
//int rollNumber;
////The Main Function:
//int main()
//{
//    system("Color F5");
//    cout << "_______Welcome to Minesweeper Game_______" << endl;
//
//    //Function Call:
//    //call to Difficulty:
//    chooseDifficultyLevel();
//    //User Rollnumber input:
//    cout << "Enter your Roll Number: ";
//    cin >> rollNumber;
//    //Call to play the game:
//    playMinesweeper();
//    //Function to Display Leader board:
//    displayLeaderboard();
//    //System pause to control the console screen:
//    system("pause");
//    //As int main is a integer function to it return 0:
//    return 0;
//}
//
////Function For the difficulty Level of Game:
//void chooseDifficultyLevel()
//{   // initalize level 
//    int level;
//    cout << "Enter the Difficulty Level\n";
//    cout << "Press 0 for BEGINNER (9 * 9 Cells and 10 Mines)\n";
//    cout << "Press 1 for INTERMEDIATE (16 * 16 Cells and 40 Mines)\n";
//    cout << "Press 2 for ADVANCED (24 * 24 Cells and 99 Mines)\n";
//    // take difficulty level from user 
//    cin >> level;
//    if (level == BEGINNER)
//    {
//        SIDE = 9;
//        MINES = 10;
//    }
//    if (level == INTERMEDIATE)
//    {
//        SIDE = 16;
//        MINES = 40;
//    }
//    if (level == ADVANCED)
//    {
//        SIDE = 24;
//        MINES = 99;
//    }
//}
//
////Function For Movement of Rows and Columns:
//void makeMove(int& x, int& y)
//{
//    cout << "Enter your move, (row, column) -> ";
//    cin >> x >> y;
//    // Start or reset the timer.
//    start_time = time(0);
//}
//
////Timer:
//bool isTimeOver()
//{
//    return start_time <= 0;
//}
//
////Function for Updated Board:
//void updateScoreboard(int score, int rollNumber)
//{
//    cout << "Roll Number: " << rollNumber << " Score: " << score << "\n";
//    // Append mode 
//    std::ofstream scoreboardFile("scoreboard.txt", ios::app);
//    if (scoreboardFile.is_open())
//    {
//        scoreboardFile << " a. ";
//        scoreboardFile << "Roll Number: " << rollNumber << " Score: " << score << "\n";
//        scoreboardFile.close();
//    }
//    else
//    {
//        cout << "Error opening the scoreboard file for writing.\n";
//    }
//}
//
////Function to display Leaderboard:
//void displayLeaderboard()
//{
//    cout << "Leaderboard:\n";
//    ifstream scoreboardFile("scoreboard.txt");
//    if (scoreboardFile.is_open())
//    {
//        string line;
//        while (getline(scoreboardFile, line))
//        {
//            cout << line << endl;
//        }
//        scoreboardFile.close();
//    }
//    else
//    {
//        cout << "Unable to open scoreboard file.\n";
//    }
//}
//
////Main Function to play minesweeper:
//void playMinesweeper()
//{
//    // declare that when gameis over than bool is false 
//    bool gameOver = false;
//    char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE];
//    int movesLeft = SIDE * SIDE - MINES, x, y;
//    int mines[MAXMINES][2];
//    initialise(realBoard, myBoard);
//    placeMines(mines, realBoard);
//    // initialize the currentMoveIndex and score
//    int currentMoveIndex = 0;
//    int score = 0;
//    while (gameOver == false && timer >= 0)
//    {
//        system("CLS");
//        // print score 
//        cout << "Scores :" << score;
//        score = SIDE * SIDE - MINES - movesLeft;
//        // print time 
//        cout << "\nTimer :" << timer << endl;
//        cout << "\nScores : " << score;
//        cout << "\n Press Enter To Move.\n";
//        cout << "\n Press SPACE To Place Flag.\n";
//        cout << "Current Status of Board: \n";
//        printBoard(myBoard);
//        displayHint(myBoard, realBoard, mines, movesLeft, timer);
//        if (_kbhit())
//        {
//            char keyPress = _getch();
//            if (keyPress == 13) // ASCII FOR ENTER
//            {
//                makeMove(x, y);
//                if (myBoard[x][y] != '*') { // if myBoard is not staric then it can be - , P or H so convert it into - when user make that turn
//                    myBoard[x][y] = '-';
//                }
//               
//                updateScoreboard(SIDE * SIDE - MINES - movesLeft, rollNumber);
//                if (currentMoveIndex == 0)
//                {
//                    if (isMine(x, y, realBoard))
//                    {
//                        replaceMine(x, y, realBoard);
//                    }
//                }
//                // increment in currentMoveIndex
//                currentMoveIndex++;
//                gameOver = playMinesweeperUtil(myBoard, realBoard, mines, x, y, movesLeft, 0);
//            }
//            else if (keyPress == 32) { // for placing flag
//                cout << "\nPlace Your Flag (row, Column):";
//                cin >> x >> y;
//                myBoard[x][y] = 'P';
//            }
//        }
//        if (!gameOver && movesLeft == 0)
//        {
//            cout << "\nYou won!\n";
//            gameOver = true;
//        }
//        // decrement in time
//        timer--;
//        Sleep(1000);
//    }
//    // Update scoreboard when the game is over
//    updateScoreboard(score, rollNumber);
//}
//
//// declare void initialise function
//void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE])
//{
//    srand(time(NULL));
//    for (int i = 0; i < SIDE; i++)
//    {
//        for (int j = 0; j < SIDE; j++)
//        {
//            myBoard[i][j] = realBoard[i][j] = '-';
//        }
//    }
//}
//// declare void placeMines fuction
//void placeMines(int mines[][2], char realBoard[][MAXSIDE])
//{
//    srand(time(NULL));
//
//    for (int i = 0; i < MINES;)
//    {
//        int x = rand() % SIDE;
//        int y = rand() % SIDE;
//
//        if (realBoard[x][y] != '*')
//        {
//            mines[i][0] = x;
//            mines[i][1] = y;
//            realBoard[x][y] = '*';
//            i++;
//        }
//    }
//}
//
//// declare function bool isValid 
//bool isValid(int row, int col)
//{
//    return (row >= 0) && (row < SIDE) && (col >= 0) && (col < SIDE);
//}
//// declare bool function in mine
//bool isMine(int row, int col, char board[][MAXSIDE])
//{
//    return (board[row][col] == '*');
//}
//
////Function to Print Board:
//void printBoard(char myBoard[][MAXSIDE])
//{
//    int i, j;
//    cout << "   ";
//    for (i = 0; i < SIDE; i++)
//    {
//        if (i > 9)
//        {
//            cout << i << "  ";
//        }
//        else cout << i << "   ";
//    }
//    cout << "\n\n";
//
//    for (i = 0; i < SIDE; i++)
//    {
//        if (i <= 9)
//            cout << i << "  ";
//        else cout << i << " ";
//        for (j = 0; j < SIDE; j++)
//            cout << myBoard[i][j] << "   ";
//        cout << "\n";
//    }
//}
//
////Function to Count Adjacent Mines:
//int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE])
//{
//    int i;
//    int count = 0;
//    for (i = 0; i < 8; i++)
//    {
//        int newRow = row + rowNeighbours[i];
//        int newCol = col + colNeighbours[i];
//        if (isValid(newRow, newCol) && isMine(newRow, newCol, realBoard))
//            count++;
//    }
//    return count;
//}
//
////Function to Play Minesweeper:
//bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE],
//    int mines[][2], int row, int col, int& movesLeft, int isHint = 0) // isHint is zero when this function is called in DisplayHint function its value will be 1
//{
//    if (isHint == 1) {
//        myBoard[row][col] = 'H';
//        return false;
//    }
//   
//    if (myBoard[row][col] != '-')
//        return false;
//    if (realBoard[row][col] == '*')
//    {
//        myBoard[row][col] = '*';
//        for (int i = 0; i < MINES; i++)
//            myBoard[mines[i][0]][mines[i][1]] = '*';
//        printBoard(myBoard);
//        cout << "\nYou lost!\n";
//        return true;
//    }
//    else
//    {
//      
//        int count = countAdjacentMines(row, col, mines, realBoard);
//        // decrement in movesLeft 
//        movesLeft--;
//        myBoard[row][col] = count + '0';
//        if (count == 0)
//        {
//            for (int i = 0; i < 8; i++)
//            {
//                int newRow = row + rowNeighbours[i];
//                int newCol = col + colNeighbours[i];
//                if (isValid(newRow, newCol) && isMine(newRow, newCol, realBoard) == false)
//                {
//                    playMinesweeperUtil(myBoard, realBoard, mines, newRow, newCol, movesLeft, 0);
//                }
//            }
//        }
//        return false;
//    }
//
//}
//
////Function to Cheat Minesweeper:
//void cheatMinesweeper(char realBoard[][MAXSIDE])
//{
//    cout << "The mines locations are-\n";
//    printBoard(realBoard);
//}
//
//// declare fuction void replaceMine 
//void replaceMine(int row, int col, char board[][MAXSIDE])
//{
//    for (int i = 0; i < SIDE; i++)
//    {
//        for (int j = 0; j < SIDE; j++)
//        {
//            if (board[i][j] != '*')
//            {
//                board[i][j] = '*';
//                board[row][col] = '-';
//                return;
//            }
//        }
//    }
//}
