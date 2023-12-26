//#include <iostream>
//#include <cstring>
//using namespace std;
//// for dijecksra algorithm
//
//const int NULL_EDGE = 0;
//const int INFINITY_VALUE = 1000000;
//struct node
//{
//    int data;
//    node* next;
//
//    node()
//    {
//        data = 0;
//        next = NULL;
//    }
//    node(int data)
//    {
//        this->data = data;
//        next = NULL;
//    }
//};
//class queue
//{
//private:
//    node* frontQ;
//    node* rear;
//
//public:
//    queue() { frontQ = rear = NULL; }
//    void push(int data)
//    {
//        node* temp = new node(data);
//        if (frontQ == NULL)
//        {
//            frontQ = temp;
//            rear = temp;
//        }
//        else
//        {
//            rear->next = temp;
//            rear = temp;
//        }
//    }
//    void pop()
//    {
//        if (frontQ == NULL)
//        {
//            cout << "Queue is empty\n";
//        }
//        else
//        {
//            node* temp = frontQ;
//            frontQ = frontQ->next;
//            delete temp;
//        }
//    }
//    int top()
//    {
//        if (frontQ == NULL)
//        {
//            cout << "Queue is empty\n";
//            return -1;
//        }
//        else
//        {
//            return frontQ->data;
//        }
//    }
//    bool empty()
//    {
//        if (frontQ == NULL)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//
//    ~queue() {}
//};
//
//
//struct vertices
//{
//    string cityName;
//    bool visited;
//    vertices()
//    {
//        visited = false;
//        cityName = " ";
//    }
//    vertices(string city) : cityName(city) { visited = false; }
//};
//
//class Graph
//{
//public:
//    vertices arr[100]; // array of vertices (cities) in the graph (array of objects)
//    int edge[100][100]; // 2D array of edges (distances) between vertices (cities) in the graph
//    int numVertices;
//    queue q;
//
//    Graph() : numVertices(0) {}
//
//    void AddVertex(string vertex)
//    {
//        if (numVertices < 100)
//        {
//            arr[numVertices] = vertex; // Add the vertex to the array 
//            for (int index = 0; index <= numVertices; index++)
//            {
//                edge[numVertices][index] = NULL_EDGE; // Initialize the new row
//                edge[index][numVertices] = NULL_EDGE; // Initialize the new column
//            }
//            numVertices++;
//        }
//        else
//        {
//            cout << "Graph is full. Cannot add more vertices.\n";
//        }
//    }
//    void BFS(string startCity)
//    {
//        int startVertex = FindIndex(startCity);
//
//        if (startVertex == -1)
//        {
//            cout << "City not found in the graph.\n";
//            return;
//        }
//
//        bool* visited = new bool[numVertices];
//        // manually set visited to false
//        for (int i = 0; i < numVertices; i++)
//        {
//            visited[i] = false;
//        }
//
//        visited[startVertex] = true;
//        q.push(startVertex);
//
//        while (!q.empty())
//        {
//            int front = q.top();
//            cout << arr[front].cityName << " "; // Print city name instead of vertex index
//            q.pop();
//
//            for (int i = 0; i < numVertices; ++i)
//            {
//                if (edge[front][i] != NULL_EDGE && !visited[i])
//                {
//                    visited[i] = true;
//                    q.push(i);
//                }
//            }
//        }
//
//        delete[] visited;
//    }
//
//    void DFS(string startCity)
//    {
//        // dfs using array
//        int startVertex = FindIndex(startCity);
//        if (startVertex == -1)
//        {
//            cout << "City not found in the graph.\n";
//            return;
//        }
//        // know make array of bool
//        bool* visited = new bool[numVertices];
//        // manually set visited to false
//        for (int i = 0; i < numVertices; i++)
//        {
//            visited[i] = false;
//        }
//        // call dfs util
//
//        DFSUtil(startVertex, visited);
//    }
//    void DFSUtil(int v, bool* visited)
//    {
//        visited[v] = true;
//        cout << arr[v].cityName << " "; // Print city name instead of vertex index
//
//        for (int i = 0; i < numVertices; ++i)
//        {
//            if (edge[v][i] != NULL_EDGE && !visited[i])
//            {
//                DFSUtil(i, visited);
//            }
//        }
//    }
//    void PrintAllNeighbors(int vertex)
//    {
//        if (vertex < 0 || vertex >= numVertices)
//        {
//            cout << "Invalid vertex. Please enter a vertex within the range of 0 to " << numVertices - 1 << ".\n";
//            return;
//        }
//
//        cout << "Neighbors of vertex " << arr[vertex].cityName << ":\n";
//        for (int i = 0; i < numVertices; i++)
//        {
//            if (edge[vertex][i] != NULL_EDGE)
//            {
//                cout << " - " << arr[i].cityName << "\n";
//            }
//        }
//    }
//    void AddEdge(string fromCity, string toCity, int weight)
//    {
//        int fromVertex = FindIndex(fromCity);
//        int toVertex = FindIndex(toCity);
//
//        if (fromVertex == -1 || toVertex == -1)
//        {
//            cout << "One or both cities not found in the graph.\n";
//            return;
//        }
//
//        // Set the weight of the edge in both directions
//        edge[fromVertex][toVertex] = weight;
//        edge[toVertex][fromVertex] = weight; // Assuming an undirected graph
//    }
//
//    int FindIndex(string city)
//    {
//        for (int i = 0; i < numVertices; i++)
//        {
//            if (arr[i].cityName == city)
//                return i;
//        }
//        return -1; // Return -1 if the city is not found
//    }
//
//    bool isCyclicUtil(int v, bool visited[], int parent, int endVertex) // endVertex is the vertex we want to reach from v (startVertex) 
//    {
//        visited[v] = true;
//
//        for (int i = 0; i < numVertices; i++)
//        {
//            if (!visited[i] && edge[v][i] != NULL_EDGE) // if the vertex is not visited and there is an edge between v and i
//            {
//                if (isCyclicUtil(i, visited, v, endVertex)) // recursively call the function with i as the new startVertex and v as the parent
//                    return true; // if the function returns true, return true from here as well
//            }
//            else if (i != parent && edge[v][i] != NULL_EDGE) // if the vertex is visited and there is an edge between v and i,  and i is not the parent of v
//            { // i cannot under stand why i did this  i != parent 
//                // this is because if we have a cycle in the graph then we will reach the parent of the start vertex again
//                if (i == endVertex) // if i is the endVertex, return true
//                    return true;
//            }
//        }
//        return false;
//    }
//
//    void checkCycle(string startCity, string endCity)
//    {
//        int startVertex = FindIndex(startCity);
//        int endVertex = FindIndex(endCity);
//
//        if (startVertex == -1 || endVertex == -1)
//        {
//            cout << "One or both cities not found in the graph.\n";
//            return;
//        }
//
//        // Create a visited array
//        bool* visited = new bool[numVertices];
//        for (int i = 0; i < numVertices; i++)
//            visited[i] = false;
//
//        if (isCyclicUtil(startVertex, visited, -1, endVertex))
//        {
//            cout << "Graph contains cycle between " << startCity << " and " << endCity << "\n";
//        }
//        else
//        {
//            cout << "Graph doesn't contain cycle between " << startCity << " and " << endCity << "\n";
//        }
//    }
//
//    int minDistance(int dist[], bool visited[])
//    {
//        int min = INT_MAX, min_index;
//
//        for (int v = 0; v < numVertices; ++v)
//        {
//            if (!visited[v] && dist[v] <= min)
//            {
//                min = dist[v];
//                min_index = v;
//            }
//        }
//        return min_index;
//    }
//
//    void dijeckstra(string src, string dest)
//    {
//        int srcIndex = FindIndex(src);
//        int destIndex = FindIndex(dest);
//
//        if (srcIndex == -1 || destIndex == -1)
//        {
//            cout << "One or both cities not found in the graph.\n";
//            return;
//        }
//
//        int dist[100];
//
//        bool visited[100] = { false };
//
//        for (int i = 0; i < numVertices; ++i)
//        {
//            dist[i] = INFINITY_VALUE;
//        }
//
//        dist[srcIndex] = 0;
//
//        for (int count = 0; count < numVertices - 1; ++count)
//        {
//            int u = minDistance(dist, visited);
//            visited[u] = true;
//            for (int v = 0; v < numVertices; ++v)
//            {
//                if (!visited[v] && edge[u][v] != NULL_EDGE && dist[u] != INFINITY_VALUE && (dist[u] + edge[u][v]) < dist[v])
//                {
//                    dist[v] = dist[u] + edge[u][v];
//                }
//            }
//        }
//        cout << "Shortest path from " << arr[srcIndex].cityName << " to " << arr[destIndex].cityName << ": ";
//        if (dist[destIndex] == INFINITY_VALUE)
//        {
//            cout << "No path exists.\n";
//        }
//        else
//        {
//            cout << dist[destIndex] << " km\n";
//        }
//    }
//
//    void DisplayMatrix()
//    {
//        cout << "Cost Matrix:\n";
//        for (int i = 0; i < numVertices; i++)
//        {
//            cout << " " << arr[i].cityName;
//        }
//        cout << "\n";
//
//        for (int i = 0; i < numVertices; i++)
//        {
//            cout << arr[i].cityName;
//            for (int j = 0; j < numVertices; j++)
//            {
//                if (edge[i][j] == NULL_EDGE)
//                    cout << " 0";
//                else
//                    cout << " " << edge[i][j];
//            }
//            cout << "\n";
//        }
//    }
//
//    void updateEdge()
//    {
//        string fromCity, toCity;
//        int fare;
//        cout << "Enter the name of the first city: ";
//        cin >> fromCity;
//        cout << "Enter the name of the second city: ";
//        cin >> toCity;
//        cout << "Enter the new fare: ";
//        cin >> fare;
//
//        int fromVertex = FindIndex(fromCity);
//        int toVertex = FindIndex(toCity);
//
//        if (fromVertex == -1 || toVertex == -1)
//        {
//            cout << "One or both cities not found in the graph.\n";
//            return;
//        }
//
//        // Update the weight of the edge in both directions
//        edge[fromVertex][toVertex] = fare;
//        edge[toVertex][fromVertex] = fare; // Assuming an undirected graph
//    }
//
//    ~Graph() {}
//};
//
//void MainMenu()
//{
//    cout << "Main Menu:\n";
//    cout << "1. Add Vertex\n";
//    cout << "2. Update Edge\n";
//    cout << "3. Add Edge\n";
//    cout << "4. Check the cycle\n";
//    cout << "5. Print All Neighbors of a Vertex\n";
//    cout << "6. Print Cost Matrix\n";
//    cout << "7. Shortest Path\n";
//    cout << "8. BFS\n";
//    cout << "9. DFS\n";
//    cout << "0. Exit\n";
//    cout << "Enter your choice: ";
//}
//
//int main()
//{
//    Graph myGraph;
//
//    int choice;
//    do
//    {
//        MainMenu();
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//        {
//            string city;
//            myGraph.AddVertex("Lahore");
//            myGraph.AddVertex("ISB");
//            myGraph.AddVertex("Karachi");
//            myGraph.AddVertex("Multan");
//            break;
//        }
//        case 2:
//        {
//            myGraph.updateEdge();
//            break;
//        }
//        case 3:
//        {
//            myGraph.AddEdge("Lahore", "ISB", 400);
//            myGraph.AddEdge("ISB", "Multan", 540);
//            myGraph.AddEdge("Multan", "Karachi", 840);
//            break;
//        }
//        case 4:
//        {
//            myGraph.checkCycle("Lahore", "Karachi");
//            break;
//        }
//        case 5:
//        {
//            int vertex;
//            cout << "Enter vertex value to get neighbors: ";
//            cin >> vertex;
//            myGraph.PrintAllNeighbors(vertex);
//            break;
//        }
//        case 6:
//            myGraph.DisplayMatrix();
//            break;
//        case 7:
//            myGraph.dijeckstra("Lahore", "Karachi");
//            break;
//        case 8:
//        {
//            string startCity;
//            cout << "Enter the starting city for BFS: ";
//            cin >> startCity;
//            cout << "BFS traversal starting from city " << startCity << ": ";
//            myGraph.BFS(startCity);
//            cout << endl;
//            break;
//        }
//        case 9:
//        {
//            string startCity;
//            cout << "Enter the starting city for DFS: ";
//            cin >> startCity;
//            cout << "DFS traversal starting from city " << startCity << ": ";
//            myGraph.DFS(startCity);
//            cout << endl;
//            break;
//        }
//
//        case 0:
//            cout << "Exiting program.\n";
//            break;
//        default:
//            cout << "Invalid choice. Try again.\n";
//            break;
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}