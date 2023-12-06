//#include <iostream>
//using namespace std;
//
//class Graph {
//    int** adjMat;
//    int noOfVertices;
//
//public:
//    Graph(int num) : noOfVertices(num) {
//        adjMat = new int* [num];
//        for (int i = 0; i < noOfVertices; i++) {
//            adjMat[i] = new int[noOfVertices];
//            for (int j = 0; j < noOfVertices; j++) {
//                adjMat[i][j] = 0;
//            }
//        }
//    }
//
//    bool makeConnect(int a, int b) {
//        adjMat[a][b] = 1;
//        adjMat[b][a] = 1;
//        return true;
//    }
//
//    void disp() {
//        for (int i = 0; i < noOfVertices; i++) {
//            for (int j = 0; j < noOfVertices; j++) {
//                if (adjMat[i][j] == 1) {
//                    cout << "This has " << i << " Connection with " << j << endl;
//                }
//            }
//        }
//        cout << endl;
//    }
//
//    ~Graph() {
//        for (int i = 0; i < noOfVertices; i++) {
//            delete[] adjMat[i];
//        }
//        delete[] adjMat;
//    }
//};
//
//int main() {
//    Graph graph(10);
//
//    graph.makeConnect(0, 1);
//    graph.makeConnect(0, 6);
//    graph.makeConnect(0, 8);
//    graph.makeConnect(1, 4);
//    graph.makeConnect(1, 6);
//    graph.makeConnect(1, 9);
//    graph.makeConnect(2, 4);
//    graph.makeConnect(2, 6);
//    graph.makeConnect(3, 4);
//    graph.makeConnect(3, 5);
//    graph.makeConnect(3, 8);
//    graph.makeConnect(4, 5);
//    graph.makeConnect(4, 9);
//    graph.makeConnect(7, 8);
//    graph.makeConnect(7, 9);
//    
//    graph.disp();
//
//    return 0;
//}
