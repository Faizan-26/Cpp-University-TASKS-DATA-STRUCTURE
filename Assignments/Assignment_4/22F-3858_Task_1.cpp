#include<iostream>
#include<fstream>
using namespace std;


struct Node {
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

class QueueLinkedListAdt {
	Node* rear;
	Node* front;
	int numItems;

public:
	QueueLinkedListAdt() {
		rear = NULL;
		front = NULL;
		numItems = 0;
	}

	bool isEmpty() {
		return numItems == 0;
	}

	void enqueue(int data) {
		Node* newNode = new Node(data);
		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		numItems++;
	}

	void dequeue(int& num) {
		if (isEmpty()) {
			cout << "\nQueue is already empty.\n";
			return;
		}
		numItems--;
		num = front->data;
		Node* deletedNode = front;
		front = front->next;
		delete deletedNode;
	}

	void makeNull() {
		int x;
		while (!isEmpty()) {
			dequeue(x);
		}
	}

	~QueueLinkedListAdt() {
		makeNull();
	}
};

struct StackNode {
    int data;
    StackNode* next;
    StackNode() {
        data = 0;
        next = NULL;
    }
    StackNode(int data) {
        this->data = data;
        next = NULL;
    }
};
class StackAdt {
    StackNode* top;
public:
    StackAdt() {
        top = NULL;
    }
    bool isEmpty() {
        return top == NULL;
    }
    bool push(int data) {
        StackNode* newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
        return true;
    }
    bool pop(int& tempData) {
        if (isEmpty()) {
            return false;
        }
        StackNode* tempNode = top;
        tempData = tempNode->data;
        top = tempNode->next;
        delete tempNode;
    }
    void displayStack() {
        StackNode* cur = top;

        cout << endl;
        while (cur != NULL) {
            cout << cur->data << "   ";
            cur = cur->next;
        }
        cout << endl;
    }
    ~StackAdt() {
        int n;
        while (top != NULL) {
            pop(n);
        }
        delete top;
    }
};

struct Cell {
    bool isObstacle;
    bool isVisited;
    int cost;
    char type; // ' ' for empty, 'S' for start, 'G' for goal, '*' for path

    Cell() {
        isObstacle = false;
        isVisited= false;
        cost = 0;
        type = ' ';
    }
};

class RobotNavGraph {
    Cell** grid;
    int size;
    int startRow, startCol;
    int goalRow, goalCol;
    int cost = 0;
public:
    RobotNavGraph(int S) : size(S) {
        grid = new Cell*[size];
        for (int i = 0; i < size; i++) {
            grid[i] = new Cell[size];
            for (int j = 0; j < size; j++) {
                grid[i][j].isObstacle = false;
                grid[i][j].isVisited = false;
                grid[i][j].cost = 0;
                grid[i][j].type = ' ';
            }
        }
    }

    void loadFromFile() {
        ifstream fin("input.txt");
        if (!fin.is_open()) {
            cout << "Cannot open file.\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fin >> grid[i][j].type;
                if (grid[i][j].type == '1') {
                    grid[i][j].isObstacle = true;
                }
                else if (grid[i][j].type == 'S') {
                    startRow = i;
                    startCol = j;
                }
                else if (grid[i][j].type == 'G') {
                    goalRow = i;
                    goalCol = j;
                }
            }
        }
        fin.close();
    }

    void displayPath() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << grid[i][j].type << "\t";
            }
            cout << endl;
        }


    }

    void setGoal_Destination() {
        grid[14][0].type = 'S';
        grid[0][14].type = 'G';
        grid[0][14].isObstacle = true;
        goalRow = 0;
        goalCol = 14;
        startCol = 0;
        startRow = 14;
    }
    void bfs() {
        QueueLinkedListAdt q;
        q.enqueue(startRow * size + startCol);
        grid[startRow][startCol].isVisited = true;
        grid[startRow][startCol].cost = 0;
        bool moreTraverse = true;
        while (!q.isEmpty()) {
            int curPos;
            q.dequeue(curPos);

            int curRow = curPos / size;
            int curCol = curPos % size;

            for (int i = -1; i <= 1 && moreTraverse; i++) {
                for (int j = -1; j <= 1 && moreTraverse; j++) {
                    int newRow = curRow + i;
                    int newCol = curCol + j;

                    if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
                       
                        if (!grid[newRow][newCol].isObstacle && !grid[newRow][newCol].isVisited) {
                            q.enqueue(newRow * size + newCol);
                            grid[newRow][newCol].isVisited = true;
                            grid[newRow][newCol].type = '*';  // Mark the path

                            if (i == 0 && j == 0) {
                               
                            }
                            else if (i == 0) {
                                cost += 2;
                                cout << "\nMove UP\n";
                            }
                            else if (i == 0 || j == 0) {
                                cost+=  2;  // Move up or right, cost 2
                                cout << "\nMove Right\n";
                            }
                            else{
                                cout << "\nMove Diagonal\n";
                                cost+= 3;  // Move up or right, cost 2
                                grid[newRow][newCol].cost = grid[curRow][curCol].cost + 3;  // Diagonal move, cost 3
                            }
                           // displayPath();
                        }
                        if (grid[newRow][newCol].type == 'G') {
                            cout << "\nGOAL REACHEDn\n";
                            cout << "YOUR COST WITH BFS :" <<cost<< endl;
                            moreTraverse = false;
                            break;
                        }
                    }
                }
            }
        }
    }

    void dfs() {
        cost = 0;
        StackAdt s;
        s.push(startRow * size + startCol);
        grid[startRow][startCol].isVisited = true;
        grid[startRow][startCol].cost = 0;

        bool moreTraverse = true;

        while (!s.isEmpty() && moreTraverse) {
            int curPos;
            s.pop(curPos);

            int curRow = curPos / size;
            int curCol = curPos % size;

            for (int i = -1; i <= 1 && moreTraverse; i++) {
                for (int j = -1; j <= 1 && moreTraverse; j++) {
                    int newRow = curRow + i;
                    int newCol = curCol + j;

                    if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {

                        if (!grid[newRow][newCol].isObstacle && !grid[newRow][newCol].isVisited) {
                            s.push(newRow * size + newCol);
                            grid[newRow][newCol].isVisited = true;
                            grid[newRow][newCol].type = '*';  // Mark the path

                            if (i == 0 && j == 0) {
                                // for the same cell, no change in cost
                            }
                            else if (i == 0 || j == 0) {
                                cost += 2;  // Move up or right, cost 2
                                cout << "\nMOVED UP OR RIGHT\n";
                            }
                            else {
                                cout << "\nMOVED DIAGONAL\n";
                                cost += 3;  // Move diagonally, cost 3
                                grid[newRow][newCol].cost = grid[curRow][curCol].cost + 3;  // Diagonal move, cost 3
                            }

                            // displayPath();

                            if (grid[newRow][newCol].type == 'G' || grid[newRow][newCol].isObstacle) {
                                cout << "\nGOAL REACHED\n";
                                cout << "YOUR COST WITH DFS: " << cost << endl;
                                moreTraverse = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout << "YOUR COST WITH DFS :" << cost<<endl;
    }


};

int main() {
    RobotNavGraph robot(15);
    RobotNavGraph robot2(15);
    robot.loadFromFile();
    robot.setGoal_Destination();
    robot.displayPath();

    // Perform BFS
    robot.bfs();
    robot.displayPath();
    cout << endl;
    robot2.loadFromFile();
    robot2.setGoal_Destination();
    robot2.dfs();
    robot2.displayPath();
   
    // Display the final grid after BFS traversal

    return 0;
}
