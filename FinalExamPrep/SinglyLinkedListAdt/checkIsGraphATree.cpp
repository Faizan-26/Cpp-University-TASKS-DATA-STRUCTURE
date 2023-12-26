#include<iostream>
using namespace std;

// to check weather a given graph is a tree or not
// without using list or any external library
// we will not use the concept of union
class Graph {
	int V;
	int E;
	int** adj;
	public:
		Graph(int V, int E) {
		this->V = V;
		this->E = E;
		adj = new int*[V];
		for (int i = 0; i < V; ++i) {
			adj[i] = new int[V];
			for (int j = 0; j < V; ++j) {
				adj[i][j] = 0;
			}
		}
	}
		void addEdge(int u, int v) {
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

		bool isTree() { // if a graph is a tree then it must be connected and it must not have any cycle
		bool* visited = new bool[V]; // to check weather a graph is connected or not
		for (int i = 0; i < V; ++i) {// initially all the vertices are unvisited
			visited[i] = false;
		}
		bool ans = isTreeHelper(0, visited, -1);	// if a graph is connected then it must be connected from any vertex
		if (ans) { // if a graph is connected then we will check weather it has any cycle or not
			for (int i = 0; i < V; ++i) { // if a graph is connected then all the vertices must be visited
				if (!visited[i]) {
					return false;
				}
			}
		}
		return ans;
	}
		bool isTreeHelper(int src, bool* visited, int parent) { // to check weather a graph has any cycle or not we will use dfs traversal
		visited[src] = true;	// initially we will mark the source as visited and we will check all the adjacent vertices of the source
		for (int i = 0; i < V; ++i) { // we will check all the adjacent vertices of the source
			if (adj[src][i] == 1 && !visited[i]) { // if the adjacent vertex is not visited then we will call the function recursively
				bool ans = isTreeHelper(i, visited, src); // if the function returns true then we will return true
				if (ans) { // if the function returns false then we will return false
					return true;
				}
			}
			else if (adj[src][i] == 1 && visited[i] && i != parent) { // if the adjacent vertex is visited and it is not the parent of the source then we will return true
				return true;
			}
		}
		return false;
	}
};

int main() {
	
	return 0;
}