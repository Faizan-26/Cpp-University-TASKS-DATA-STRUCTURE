//#include <iostream>
//using namespace std;
//
//struct Edge
//{
//	int des;
//	int weight;
//};
//
//class Graph
//{
//	int V;
//	Edge** adj;
//public:
//	Graph(int V) : V(V)
//	{
//		adj = new Edge * [V];
//		for (int i = 0; i < V; ++i)
//		{
//			adj[i] = new Edge[V];
//			for (int j = 0; j < V; ++j)
//			{
//				adj[i][j].des = -1;
//				adj[i][j].weight = -1;
//			}
//		}
//	}
//	void addEdge(int src, int des, int weight)
//	{
//		adj[src][des].des = des;
//		adj[src][des].weight = weight;
//		adj[des][src].des = src;
//		adj[des][src].weight = weight;
//	}
//	void dijkstra(int src)
//	{
//		int* dist;
//		dist = new int[V];
//
//		bool* visited = new bool[V];
//		for (int i = 0; i < V; ++i)
//		{
//			dist[i] = INT_MAX;
//			visited[i] = false;
//		}
//		dist[src] = 0;
//		for (int i = 0; i < V - 1; ++i)
//		{
//			int u = -1;
//			for (int j = 0; j < V; ++j)
//			{
//				if (!visited[j] && (u == -1 || dist[j] < dist[u]))
//				{
//					u = j;
//				}
//			}
//			visited[u] = true;
//			for (int v = 0; v < V; ++v)
//			{
//				if (!visited[v] && adj[u][v].weight != -1 && dist[u] + adj[u][v].weight < dist[v])
//				{
//					dist[v] = dist[u] + adj[u][v].weight;
//				}
//			}
//		}
//		cout << "Results:\n";
//		for (int i = 0; i < V; ++i)
//		{
//			cout << "Vertex " << i << ": " << dist[i] << '\n';
//		}
//	}
//};
//
//int main()
//{
//	Graph g(4);
//	g.addEdge(0, 1, 2);
//	g.addEdge(0, 3, 6);
//	g.addEdge(2, 1, 12);
//	g.addEdge(3, 2, 9);
//	int start_Ver = 0;
//	cout << "ENter Starting vertix :";
//	cin>>start_Ver;
//	g.dijkstra(start_Ver);
//	system("pause");
//	return 0;
//}