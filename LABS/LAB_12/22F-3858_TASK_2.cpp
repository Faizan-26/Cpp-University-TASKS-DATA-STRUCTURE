//#include <iostream>
//using namespace std;
//struct Node {
//        int data;
//        Node* next;
//};
//
//class Graph {
//    int vertices;
//    Node** adjList;
//
//public:
//    Graph(int num) : vertices(num) {
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
//
//    void displayList() {
//        cout << "\nAdjacency list:\n";
//        for (int i = 0; i < vertices; ++i) {
//            cout << "Node " << i << ": ";
//            Node* cur = adjList[i];
//            while (cur != NULL) {
//                cout << cur->data << " ";
//                cur = cur->next;
//            }
//            cout << "\n";
//        }
//    }
//
//    ~Graph() {
//        for (int i = 0; i < vertices; ++i) {
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
//
//    graph.displayList();
//
//    return 0;
//}
