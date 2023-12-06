////#include <iostream>
////using namespace std;
////
////class QueueArrayAdt {
////    int size;
////    int rear;
////    int front;
////    int numItems;
////    int* array;
////
////public:
////    QueueArrayAdt(int size) {
////        this->size = size;
////        front = -1;
////        rear = -1;
////        numItems = 0;
////        array = new int[size];
////    }
////
////    bool isEmpty() {
////        return numItems == 0;
////    }
////
////    bool isFull() {
////        return numItems == size - 1;
////    }
////
////    void enqueue(int data) {
////        if (isFull()) {
////            cout << "\nQueue is Full.\n";
////            return;
////        }
////        rear = (rear + 1) % size;
////        array[rear] = data;
////        numItems++;
////    }
////
////    void dequeue() {
////        if (isEmpty()) {
////            cout << "\nQueue is Empty.\n";
////            return;
////        }
////        front = (front + 1) % size;
////        numItems--;
////    }
////
////    int peek() {
////        if (isEmpty()) {
////            cout << "\nQueue is Empty.\n";
////            return -1; // Return a special value indicating an empty queue
////        }
////        return array[(front + 1) % size];
////    }
////
////    ~QueueArrayAdt() {
////        front = -1;
////        rear = -1;
////        numItems = 0;
////        delete[] array;
////    }
////};
////
////class Graph {
////    int** adjMat;
////    int noOfVertices;
////
////public:
////    Graph(int num) : noOfVertices(num) {
////        adjMat = new int* [num];
////        for (int i = 0; i < noOfVertices; i++) {
////            adjMat[i] = new int[noOfVertices];
////            for (int j = 0; j < noOfVertices; j++) {
////                adjMat[i][j] = 0;
////            }
////        }
////    }
////
////    bool makeConnect(int a, int b) {
////        adjMat[a][b] = 1;
////        adjMat[b][a] = 1;
////        return true;
////    }
////
////    void bfsTraversal(int initialVertex) {
////        bool* visited = new bool[noOfVertices] {false};
////        QueueArrayAdt queue(noOfVertices);
////
////        visited[initialVertex] = true;
////        queue.enqueue(initialVertex);
////
////        while (!queue.isEmpty()) {
////            int currentVertex = queue.peek();
////            cout << currentVertex << " ";
////            queue.dequeue();
////
////            for (int i = 0; i < noOfVertices; ++i) {
////                if (adjMat[currentVertex][i] == 1 && !visited[i]) {
////                    visited[i] = true;
////                    queue.enqueue(i);
////                }
////            }
////        }
////
////        delete[] visited;
////    }
////
////    ~Graph() {
////        for (int i = 0; i < noOfVertices; i++) {
////            delete[] adjMat[i];
////        }
////        delete[] adjMat;
////    }
////};
////
////int main() {
////    Graph graph(10);
////
////    graph.makeConnect(0, 1);
////    graph.makeConnect(0, 6);
////    graph.makeConnect(0, 8);
////    graph.makeConnect(1, 4);
////    graph.makeConnect(1, 6);
////    graph.makeConnect(1, 9);
////    graph.makeConnect(2, 4);
////    graph.makeConnect(2, 6);
////    graph.makeConnect(3, 4);
//    graph.makeConnect(3, 5);
//    graph.makeConnect(3, 8);
//    graph.makeConnect(4, 5);
//    graph.makeConnect(4, 9);
//    graph.makeConnect(7, 8);
//    graph.makeConnect(7, 9);
//
//    cout << "BFS Traversal starting from vertex 0:\n";
//    graph.bfsTraversal(0);
//
//    return 0;
//}
