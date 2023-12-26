//#include<iostream>
//#include<queue>
//using namespace std;
//
//struct StackNode {
//    int data;
//    StackNode* next;
//    StackNode() {
//        data = 0;
//        next = NULL;
//    }
//    StackNode(int data) {
//        this->data = data;
//        next = NULL;
//    }
//};
//
//class StackAdt {
//public:
//    StackNode* top;
//    StackAdt() {
//        top = NULL;
//    }
//    void push(int data) {
//        StackNode* temp = new StackNode(data);
//        if (top == NULL) {
//            top = temp;
//        }
//        else {
//            temp->next = top;
//            top = temp;
//        }
//    }
//    bool isEmpty() {
//        return top == NULL;
//    }
//    void pop(int& data) {
//        if (top == NULL) {
//            cout << "Stack is empty" << endl;
//            return;
//        }
//        else {
//            data = top->data;
//            StackNode* temp = top;
//            top = top->next;
//            delete temp;
//        }
//    }
//    void peek(int& data) {
//        if (top == NULL) {
//            cout << "Stack is empty" << endl;
//            return;
//        }
//        else {
//            data = top->data;
//        }
//    }
//    void displayStack() {
//        StackNode* temp = top;
//        while (temp != NULL) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//};
//
//class Heap {
//    int* arr;
//    int size;
//    int totalItems;
//public:
//    Heap() {
//        arr = new  int[10]; // by default have size of 10
//        size = 10;
//        totalItems = 0;
//        for (int i = 0; i < 10; i++)
//        {
//            arr[i] = -1;
//        }
//    }
//    bool isEmpty() {
//        return totalItems == 0;
//    }
//    Heap(int S) {
//        size = S;
//        arr = new int[size];
//        for (int i = 0; i < S; i++)
//        {
//            arr[i] = -1;
//        }
//        totalItems = 0;
//    }
//
//    int getMin() {
//        return arr[1];
//    }
//
//    void perculateUp(int index) {
//        while (index > 1 && arr[index] < arr[index / 2] && arr[index / 2] != -1) {
//            swap(arr[index], arr[index / 2]);
//            index = index / 2;
//        }
//    }
//
//
//    void perculateDown(int index)
//    {
//        int smallerChild = index;
//        while (true)
//        {
//            if (index * 2 < size && arr[index * 2] < arr[index] && arr[index * 2] != -1) {
//                smallerChild = index * 2;
//            }
//            if (index * 2 + 1 < size && arr[index * 2 + 1] < arr[index] && arr[index * 2 + 1] != -1) {
//                smallerChild = index * 2 + 1;
//            }
//            if (smallerChild == index) {
//                break;
//            }
//            swap(arr[index], arr[smallerChild]);
//            index = smallerChild;
//        }
//    }
//    void insert(int data) {
//        if (totalItems == size - 1) {
//            cout << "Heap is full\n";
//            return;
//        }
//        else {
//            ++totalItems;
//            arr[totalItems] = data;
//            perculateUp(totalItems);
//        }
//    }
//
//
//    void extractMin() {
//        cout << arr[1] << " deleted.\n";
//        arr[1] = arr[totalItems--]; // this 1st assign the last element to the root and then decrease the totalItems
//        perculateDown(1);
//    }
//    void display() {
//        for (int i = 1; i <= totalItems; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//
//
//struct Node {
//    int data;
//    Node* next;
//    Node() {
//        data = 0;
//        next = NULL;
//    }
//    Node(int data) {
//        this->data = data;
//        next = NULL;
//    }
//};
//class QueueLinkedListAdt {
//    int numItems;
//public:
//    Node* rear;
//    Node* front;
//    QueueLinkedListAdt() {
//        rear = NULL;
//        front = NULL;
//        numItems = 0;
//    }
//    bool isEmpty() {
//        return numItems == 0;
//    }
//    void enqueue(int data) {
//        Node* newNode = new Node(data);
//        if (isEmpty()) {
//            front = newNode;
//            rear = newNode;
//        }
//        else {
//            rear->next = newNode;
//            rear = newNode;
//        }
//        numItems++;
//    }
//    void dequeue() {
//        if (isEmpty()) {
//            cout << "\nQueue is already empty.\n";
//            return;
//        }
//        numItems--;
//        //num = front->data;
//        Node* deletedNode = front;
//        front = front->next;
//        delete deletedNode;
//    }
//    void makeNull() {
//        
//        while (!isEmpty()) {
//            dequeue();
//        }
//    }
//    ~QueueLinkedListAdt() {
//        makeNull();
//    }
//};
//
////implement a graph using adjacency matrix
//class Graph {
//    int** adjMat;
//	int numVertices;
//public:
//	Graph(int numVert) {
//		numVertices = numVert;
//		adjMat = new int * [numVertices];
//		for (int i = 0; i < numVertices; i++) {
//			adjMat[i] = new int[numVertices];
//			for (int j = 0; j < numVertices; j++) {
//				adjMat[i][j] = 0;
//			}
//		}
//	}
//	void addEdge(int i, int j) {
//		adjMat[i][j] = 1;
//		adjMat[j][i] = 1;
//	}
//
//	void removeEdge(int i, int j) {
//		adjMat[i][j] = 0;
//		adjMat[j][i] = 0;
//	}
//
//    void bfsTraversal(int v) {
//        bool* visited = new bool[numVertices];
//       for (int i = 0; i < numVertices; i++) {
//			visited[i]=false;
//		}
//		QueueLinkedListAdt q;
//		q.enqueue(v);
//		visited[v]=true;
//        
//        while (!q.isEmpty()) {
//			int cur = q.front->data;
//			cout<<cur<<" ";
//			q.dequeue();
//            for (int i = 0; i < numVertices; i++) {
//                if (adjMat[cur][i] == 1 && !visited[i]) {
//					q.enqueue(i);
//					visited[i]=true;
//				}
//			}
//		}
//    }
//    void dfsTraversal(int v) {
//		bool* visited = new bool[numVertices];
//        for (int i = 0; i < numVertices; i++) {
//            visited[i]=false;
//        }
//        StackAdt s;
//        s.push(v);
//        visited[v]=true;
//        while (!s.isEmpty()) {
//            int cur = s.top->data;
//			cout<<cur<<" ";
//			s.pop(cur);
//            for (int i = 0; i < numVertices; i++) {
//                if (adjMat[cur][i] == 1 && !visited[i]) {
//					s.push(i);
//					visited[i]=true;
//				}
//			}
//		
//        }
//    }
//   
//};
//int main() {
//    Graph g(5);
//	g.addEdge(0, 1);
//	g.addEdge(0, 2);
//	g.addEdge(0, 3);
//	g.addEdge(1, 4);
//	g.addEdge(2, 4);
//	g.addEdge(3, 4);
//	g.bfsTraversal(4);
//    cout << endl;
//    g.dfsTraversal(0);
//    cout << endl;
//	return 0;
//}