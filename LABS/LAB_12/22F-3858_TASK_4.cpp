//#include <iostream>
//using namespace std;
//
//class IntStack {
//    int* stackArray;
//    int size;
//    int top;
//
//public:
//    IntStack() {
//        stackArray = NULL;
//        size = 0;
//        top = -1;
//    }
//
//    IntStack(int Size) {
//        size = Size;
//        stackArray = new int[size];
//        top = -1;
//    }
//
//    bool isEmpty() {
//        return top == -1;
//    }
//
//    bool isFull() {
//        return top == size - 1;
//    }
//
//    bool push(int x) {
//        if (isFull()) {
//            return false;
//        }
//        top++;
//        stackArray[top] = x;
//        return true;
//    }
//
//    int pop() {
//        if (isEmpty()) {
//            return -1; // Return a special value indicating an empty stack
//        }
//        int x = stackArray[top];
//        top--;
//        return x;
//    }
//
//    ~IntStack() {
//        delete[] stackArray;
//    }
//};
//
//struct Node {
//    int data;
//    Node* next;
//};
//
//class Graph {
//    int noOfvertices = 0;
//    Node** adjList;
//
//public:
//    Graph(int num) : noOfvertices(num) {
//        adjList = new Node * [num];
//        for (int i = 0; i < num; ++i) {
//            adjList[i] = NULL;
//        }
//    }
//
//    void addEdge(int from, int to) { // undirected graph
//        Node* newNodeFrom = new Node;
//        newNodeFrom->data = to;
//        newNodeFrom->next = adjList[from];
//        adjList[from] = newNodeFrom;
//
//        Node* newNodeTo = new Node;
//        newNodeTo->data = from;
//        newNodeTo->next = adjList[to];
//        adjList[to] = newNodeTo;
//    }
//
//    void dfsTraversal(int initialVertex) {
//        bool* visited = new bool[noOfvertices];
//        for (int i = 0; i < noOfvertices; ++i) {
//            visited[i] = false;
//        }
//
//        IntStack stack(noOfvertices);
//
//        visited[initialVertex] = true;
//        stack.push(initialVertex);
//
//        while (!stack.isEmpty()) {
//            int currentVertex = stack.pop();
//            cout << currentVertex << " ";
//
//            Node* cur = adjList[currentVertex];
//            while (cur != NULL) {
//                if (!visited[cur->data]) {
//                    visited[cur->data] = true;
//                    stack.push(cur->data);
//                }
//                cur = cur->next;
//            }
//        }
//
//        delete[] visited;
//    }
//
//    void displayList() {
//        cout << "\nAdjacency list:\n";
//        for (int i = 0; i < noOfvertices; ++i) {
//            cout << "Node " << i << ": ";
//            Node* cur = adjList[i];
//            while (cur != NULL) {
//                cout << cur->data << " ";
//                cur = cur->next;
//            }
//            cout << "\n";
//        }
//    }
//    ~Graph() {
//        for (int i = 0; i < noOfvertices; ++i) {
//            Node* cur = adjList[i];
//            while (cur != NULL) {
//                Node* temp = cur->next;
//                delete cur;
//                cur = temp;
//            }
//        }
//        delete[] adjList;
//    }
//};
//
//int main() {
//    Graph graph(5);
//
//    graph.addEdge(0, 2);
//    graph.addEdge(0, 1);
//    graph.addEdge(2, 3);
//    graph.addEdge(2, 3);
//    graph.addEdge(1, 4);
//    graph.addEdge(1, 3);
//
//    cout << "DFS Traversal starting from vertex 0:\n";
//    graph.dfsTraversal(0);
//
//    return 0;
//}
