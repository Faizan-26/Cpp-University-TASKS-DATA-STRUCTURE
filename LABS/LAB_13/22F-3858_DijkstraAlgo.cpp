//#include<iostream>
//using namespace std;
//
//const int vertices = 4;
//
//int getMinimum(bool inSPT[], int dist[]) {
//    int minDist = INT_MAX, minIndex = -1;
//
//    for (int v = 0; v < vertices; ++v) {
//        if (!inSPT[v] && dist[v] < minDist) {
//            minDist = dist[v];
//            minIndex = v;
//        }
//    }
//
//    return minIndex;
//}
//
//void Dijkstra(int graph[vertices][vertices], int src) {
//    int dist[vertices];    // The output array dist[i] holds the shortest distance from src to i
//    bool inSPT[vertices];   // inSPT[i] will be true if vertex i is included in the shortest path tree or the shortest distance from src to i is finalized
//
//    for (int i = 0; i < vertices; ++i) {
//        dist[i] = INT_MAX;
//        inSPT[i] = false;
//    }
//
//    dist[src] = 0;
//
//    for (int count = 0; count < vertices - 1; ++count) {
//        int u = getMinimum(inSPT, dist);
//
//        inSPT[u] = true;
//
//        for (int v = 0; v < vertices; ++v) {
//            if (!inSPT[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v] ) {
//                dist[v] = dist[u] + graph[u][v];
//            }
//        }
//    }
//
//    // Print the shortest distances
//    cout << "Vertex   Distance from Source\n";
//    for (int i = 0; i < vertices; ++i)
//        cout << i << "        " << dist[i] << endl;
//}
//
//int main() {
//    int graph[vertices][vertices] = {
//        {0, 2, 3, 4},
//        {2, 0, 1, 6},
//        {3, 1, 0, 4},
//        {4, 6, 4, 0},
//    };
//
//    int source = 0;
//
//    Dijkstra(graph, source);
//
//    return 0;
//}
