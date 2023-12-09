#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define the size of the grid
const int N = 15;
const int M = 15;

// Define the cost of each move
const int COST_UP = 2;
const int COST_RIGHT = 2;
const int COST_DIAGONAL = 3;

// Define the grid
int grid[N][M];

// Define the visited array
bool visited[N][M];

// Define the cost array
int cost[N][M];

// Define the directions of movement
int dx[] = { -1, 0, -1 }; // Up, Right, Diagonal Up Right
int dy[] = { 0, 1, 1 }; // Up, Right, Diagonal Up Right

// Define the BFS function
void BFS(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;
    cost[startX][startY] = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int newX = current.first + dx[i];
            int newY = current.second + dy[i];

            if (newX >= 0 && newX < N && newY >= 0 && newY < M && !visited[newX][newY]) {
                visited[newX][newY] = true;
                cost[newX][newY] = cost[current.first][current.second] + (i == 2 ? COST_DIAGONAL : COST_UP);
                q.push({ newX, newY });
            }
        }
    }
}

int main() {
    // Initialize the grid and the visited array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            grid[i][j] = 0;
            visited[i][j] = false;
        }
    }

    // Call the BFS function
    BFS(1, 2);

    // Print the cost to reach the goal state
    cout << "The cost to reach the goal state is: " << cost[14][13] << endl;

    return 0;
}
