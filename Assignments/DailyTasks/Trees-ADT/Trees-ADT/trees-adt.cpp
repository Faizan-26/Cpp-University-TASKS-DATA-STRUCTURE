////#include<iostream>
////using namespace std;
////struct Node {
////	int data;
////	Node* left, * right;
////	Node() {
////		data = 0;
////		left = NULL;
////		right = NULL;
////	}
////};
////
////class BST {
////	Node* root;
////public:
////	BST() {
////		root = NULL;
////	}
////	void insertNode(int num) {
////		Node* newNode = new Node;
////		newNode->data = num;
////		if (!root) root = newNode;
////		else {
////			Node* curNode = root;
////			while (1) {
////				if (num < curNode->data) {
////					if (curNode->left)
////						curNode = curNode->left;
////					else {
////						curNode->left = new Node; 
////						return;
////					}
////				}
////				else if (num > curNode->data) {
////					if (curNode->right) {
////						curNode = curNode->right;
////					}
////					else {
////						curNode->right = newNode;
////						return;
////					}
////				}
////				else {
////					cout << "\nDUPLICATE NUMBER FOUND IN TREE.\n";
////				}
////			}
////		}
////	}
////	bool find(int value, Node* startNode) {
////		// start node is to specify searching from specific part of tree
////		while (startNode) { // if start node != NULL
////			if (value < startNode->data) {
////				startNode = startNode->left;
////			}
////			else if (value > startNode->data) {
////				startNode = startNode->right;
////			}
////			else {
////				cout << "VALUE FOUND.\n";
////				return true;
////			}
////		}
////		cout << "Value not found.\n";
////		return false;
////	}
////	void makeDeletion(Node*& nodePtr) {
////		Node* tempNode;
////		if (nodePtr->right == NULL) { // if only left node is NULL
////			tempNode = nodePtr;
////			nodePtr = nodePtr->left;
////			delete tempNode;
////		}
////		else if (nodePtr->left == NULL) { // if only right NODE is null
////			tempNode = nodePtr;
////			nodePtr = nodePtr->right;
////			delete tempNode;
////		}
////		else { // case for two childrens
////			tempNode = nodePtr->right;
////			while (tempNode->left) {
////				tempNode = tempNode->left;
////			}
////			tempNode->left = nodePtr->left;
////			tempNode = nodePtr;
////			nodePtr = nodePtr->right;
////			delete tempNode;
////		}
////	}
////	void deleteNode(int num, Node*& nodePtr) {
////		if (nodePtr == NULL) {
////			cout << "Num not found!\n";
////		}
////		else if (num < nodePtr->data) {
////			deleteNode(num, nodePtr->left);
////		}
////		else if (num > nodePtr->data) {
////			deleteNode(num, nodePtr->right);
////		}
////		else {
////			makeDeletion(nodePtr);
////		}
////	}
////	 
////};
////int main() {
////
////	return 0;
////}
//
//#include<iostream>
//#include<Windows.h>
//#include<fstream>
//#include<conio.h>
//#include<cstring>
//#include<string>
//#include<ctime>
//
//using namespace std;
//#define KEY_UP 72
//#define KEY_DOWN 80
//#define KEY_LEFT 75
//#define KEY_RIGHT 77
//char crushrand(char cand) {  // creates random key in 2D-array easy mode
//	int c;
//	c = rand() % 5 + 1;
//	if (c == 1)
//		cand = '@';
//	else if (c == 2)
//		cand = '#';
//	else if (c == 3)
//		cand = '$';
//	else if (c == 4)
//		cand = '%';
//	else if (c == 5)
//		cand = '&';
//	return cand;
//}
//char crushrandhard(char cand) { // creates random key in 2D-array easy mode
//	int c;
//	c = (rand() % 7) + 1;
//	if (c == 1)
//		cand = '@';
//	else if (c == 2)
//		cand = '#';
//	else if (c == 3)
//		cand = '$';
//	else if (c == 4)
//		cand = '%';
//	else if (c == 5)
//		cand = '&';
//	else if (c == 6)
//		cand = '!';
//	else if (c == 7)
//		cand = '*';
//	return cand;
//}
//void fill(char arr[8][8]) // check if array element has space value and replace with random candy it is executed after swpspaceeasy function
//{
//	char cand = ' ';
//	for (int x = 0; x < 8; x++)
//	{
//		for (int y = 0; y < 8; y++)
//		{
//			if (arr[x][y] == ' ')
//			{
//				arr[x][y] = crushrand(cand);
//				if (arr[x][y] == arr[x][y + 1] && arr[x][y] == arr[x][y + 2] ||//column wise horizontal
//					arr[x][y] == arr[x + 1][y] && arr[x][y] == arr[x + 2][y] || // row wise vertical
//					arr[x][y] == arr[x - 1][y + 1] && arr[x][y] == arr[x + 1][y - 1] || //forward diagonal
//					arr[x][y] == arr[x - 1][y - 1] && arr[x][y] == arr[x + 1][y + 1])  //backward diagonal
//				{
//					char c = ' ';
//					arr[x][y] = crushrand(c);
//				}
//			}
//		}
//	}
//}
//void fillhard(char arr[10][10]) // check if array element has space value and replace with random candy it is executed after swpspacehard function
//{
//	char cand = ' ';
//	for (int x = 0; x < 10; x++)
//	{
//		for (int y = 0; y < 10; y++)
//		{
//			if (arr[x][y] == ' ')
//			{
//				arr[x][y] = crushrandhard(cand);
//				if (arr[x][y] == arr[x][y + 1] && arr[x][y] == arr[x][y + 2] ||//column wise horizontal
//					arr[x][y] == arr[x + 1][y] && arr[x][y] == arr[x + 2][y] || // row wise vertical
//					arr[x][y] == arr[x - 1][y + 1] && arr[x][y] == arr[x + 1][y - 1] || //forward diagonal
//					arr[x][y] == arr[x - 1][y - 1] && arr[x][y] == arr[x + 1][y + 1])  //backward diagonal
//				{
//					arr[x][y] = crushrandhard(cand);
//				}
//			}
//		}
//	}
//}
//void FILLcandies(char arr[8][8])// fill random cadies in table for 1st time easy mode
//{
//	char c = ' ';
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			arr[i][j] = crushrand(c);
//			for (int i = 0; i < 8; i++)
//			{
//				for (int j = 0; j < 8; j++)
//				{
//					if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] ||//column wise horizontal
//						arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] || // row wise vertical
//						arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1] || //forward diagonal
//						arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1])  //backward diagonal
//					{
//						char ch = ' ';
//						arr[i][j] = crushrand(ch);
//					}
//				}
//			}
//		}
//	}
//}
//void FILLcandieshard(char arr[10][10])    // fill random cadies in table for 1st time hard mode
//{
//	char c = ' ';
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//
//			arr[i][j] = crushrandhard(c);
//			for (int i = 0; i < 10; i++)
//			{
//				for (int j = 0; j < 10; j++)
//				{
//					if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] ||//column wise horizontal
//						arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] || // row wise vertical
//						arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1] || //forward diagonal
//						arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1])  //backward diagonal
//					{
//						char ch = ' ';
//						arr[i][j] = crushrandhard(ch);
//					}
//				}
//			}
//		}
//	}
//}
//void swpspaceEASY(char arr[8][8]) //swap spaces to top in easy mode
//{
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			if (arr[i][j] == ' ')
//			{
//				int l = i, m = j;
//				while (l > 0)
//				{
//					arr[l][m] = arr[l - 1][m];
//					l--;
//				}
//			}
//		}
//	}
//}
//void swpspaceHARD(char arr[10][10])//swap spaces to top in hard mode 
//{
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			if (arr[i][j] == ' ')
//			{
//				int l = i, m = j;
//				while (l > 0)
//				{
//					arr[l][m] = arr[l - 1][m];
//					l--;
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//	char replay = 'y';
//	while (replay == 'y' || replay == 'Y')
//	{
//		SetConsoleTextAttribute(h, 6); /// function for text color yellow
//		int game;
//		cout << endl << endl << endl;
//		cout << "\t\t\t\t|+++++++++++++++++++++|" << endl;
//		cout << "\t\t\t\t|______GAME MENU______|" << endl;
//		cout << "\t\t\t\t|                     |" << endl;
//		cout << "\t\t\t\t|    1. Play Game     |" << endl;
//		cout << "\t\t\t\t|    2. Credits       |" << endl;
//		cout << "\t\t\t\t|    3. Instructions  |" << endl;
//		cout << "\t\t\t\t|    4. Scores        |" << endl;
//		cout << "\t\t\t\t|    5. Quit          |" << endl;
//		cout << "\t\t\t\t|   Give Your choice  |" << endl;
//		cout << "\t\t\t\t|_____________________|" << endl;
//		cout << "\t\t\t\t";
//		cin >> game;
//		SetConsoleTextAttribute(h, 15); //function for text color default
//		srand(time(0));
//		if (game == 1)
//		{
//			string name;
//			system("CLS");
//			SetConsoleTextAttribute(h, 6);
//			cout << endl << endl << endl;
//			cout << "\t\t\t\t\t|         PLEASE ENTER YOUR NAME:          |" << endl;
//			cout << "\t\t\t\t\t          ";
//			cin.ignore();// without this control ignores user to input his name..
//			getline(cin, name); // gets input in string with spaces..
//			SetConsoleTextAttribute(h, 7);// white text color
//			int mode;
//			SetConsoleTextAttribute(h, 6);// yellow text color
//			cout << "\n\t\t\t\t\t Select MODE:" << endl;
//			SetConsoleTextAttribute(h, 2);//green text color
//			cout << " \t\t\t\t\t 1. Easy Mode" << endl;
//			SetConsoleTextAttribute(h, 4);// red text color
//			cout << " \t\t\t\t\t 2. Hard Mode" << endl;
//			cout << "\t\t\t\t\t ";
//			SetConsoleTextAttribute(h, 6);
//			cin >> mode;
//			SetConsoleTextAttribute(h, 7);
//			if (mode == 1)
//			{
//				system("CLS");
//				SetConsoleTextAttribute(h, 2);
//				cout << "\t\t\t\t\t " << name << " selected Easy Mode." << endl << endl;
//				SetConsoleTextAttribute(h, 7);
//				int count = 0; // to control filling of random candies in table only for once
//				int score = 0;
//				int turn = 15;
//				char arr[8][8];
//				int stoptimer = 60;
//				if (count == 0)
//					FILLcandies(arr);//fill table with candies
//				count++;
//				while (stoptimer >= 0 && turn > 0)
//				{
//					cout << "\t\tTIMER : " << stoptimer << endl;
//					cout << "\t\tTurns :" << turn << endl;
//					cout << "\t\tScore :" << score << endl;
//					stoptimer--;
//					cout << "    |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |" << endl;
//					cout << "    -------------------------------------------------" << endl;
//					for (int i = 0; i < 8; i++)
//					{
//						cout << " " << i << " " << " | ";
//						for (int j = 0; j < 8; j++)
//						{
//							if (arr[i][j] == '@')
//								SetConsoleTextAttribute(h, 1);//colouring symbols
//							else if (arr[i][j] == '#')
//								SetConsoleTextAttribute(h, 2);
//							else if (arr[i][j] == '$')
//								SetConsoleTextAttribute(h, 3);
//							else if (arr[i][j] == '%')
//								SetConsoleTextAttribute(h, 4);
//							else if (arr[i][j] == '&')
//								SetConsoleTextAttribute(h, 5);
//							cout << " " << arr[i][j] << " ";
//							SetConsoleTextAttribute(h, 15);
//							cout << " | ";
//						}
//						cout << endl;
//						cout << "    -------------------------------------------------";
//						cout << endl;
//					}
//					SetConsoleTextAttribute(h, 3);
//					cout << "Press Rshift To select Candy..." << endl;
//					SetConsoleTextAttribute(h, 7);
//					if (GetAsyncKeyState(VK_RSHIFT))// this function checks when user enters right shift .. otherwise ignore and control moves forward 
//					{
//						int i, j;
//						bool found = 1;
//						bool valid = 1;// for check input validation
//						while (valid == 1)
//						{
//							cout << "Which Element You want to swap?";
//							cout << "\nInput i:";
//							cin >> i;
//							cout << "\nInput j:";
//							cin >> j;
//							if (i >= 0 && i < 8 && j >= 0 && j < 8)// input validation
//								valid = 0;
//							else
//							{
//								cout << "\nInvalid Input... Enter Between 0 and 7." << endl;
//								valid = 1;
//							}
//						}
//						cout << "Selected Sybmol: " << arr[i][j] << endl;
//						cout << "Press Arrow Keys to swipe :";
//						while (found == 1) {
//							int c;
//							switch (c = _getch())
//							{
//							case KEY_UP:
//							{
//								if (i == 0)
//								{
//									cout << "Invalid Move." << endl;
//								}
//								else
//								{
//									char swp = arr[i][j];
//									arr[i][j] = arr[i - 1][j];
//									arr[i - 1][j] = swp;
//									turn--;
//									found = 0;
//									break;
//								}
//							}
//							case KEY_DOWN:
//							{
//								if (i == 7)
//								{
//									cout << "Invalid Move." << endl;
//								}
//								else
//								{
//									char swp = arr[i][j];
//									arr[i][j] = arr[i + 1][j];
//									arr[i + 1][j] = swp;
//									turn--;
//
//								}
//								found = 0;
//								break;
//							}
//							case KEY_LEFT:
//							{
//								if (j == 0)
//									cout << "Invalid Move." << endl;
//								else
//								{
//									char swp = arr[i][j];
//									arr[i][j] = arr[i][j - 1];
//									arr[i][j - 1] = swp;
//									turn--;
//								}
//								found = 0;
//								break;
//							}
//							case KEY_RIGHT:
//							{
//								if (j == 7)
//									cout << "Invalid Move." << endl;
//								else
//								{
//									char swp = arr[i][j];
//									arr[i][j] = arr[i][j + 1];
//									arr[i][j + 1] = swp;
//									turn--;
//								}
//								found = 0;
//								break;
//							}
//
//							cout << endl;
//							}
//						}
//						int pikachuu = 10;
//						while (pikachuu >= 0)
//						{
//							for (int i = 0; i < 8; i++)
//							{
//								for (int j = 0; j < 8; j++)
//								{
//									if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j + 1] && arr[i][j] == arr[i + 2][j + 2])//L shape Condition spaces
//									{
//										arr[i][j] = ' ';
//										arr[i + 1][j] = ' ';
//										arr[i + 2][j] = ' ';
//										arr[i][j + 1] = ' ';
//										arr[i][j + 2] = ' ';
//										score += 25;
//										system("CLS");
//										cout << "------------------------" << endl;
//										cout << "|                      |" << endl;
//										cout << "|         SWEET        |" << endl;
//										cout << "|  lshape       loading|" << endl;
//										cout << "------------------------" << endl;
//										Sleep(500);
//										system("CLS");
//									}
//									else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])// vertical condition check 
//									{
//										arr[i][j] = ' ';
//										arr[i + 1][j] = ' ';
//										arr[i + 2][j] = ' ';
//										score += 10;
//										system("CLS");
//										cout << "------------------------" << endl;
//										cout << "|                      |" << endl;
//										cout << "|         SWEET        |" << endl;
//										cout << "|   vert        loading|" << endl;
//										cout << "------------------------" << endl;
//										Sleep(500);
//										system("CLS");
//									}
//									else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])  // horizontal condition
//									{
//										arr[i][j] = ' ';
//										arr[i][j + 1] = ' ';
//										arr[i][j + 2] = ' ';
//										score += 10;
//										system("CLS");
//										cout << "------------------------" << endl;
//										cout << "|                      |" << endl;
//										cout << "|         SWEET        |" << endl;
//										cout << "|    hori       loading|" << endl;
//										cout << "------------------------" << endl;
//										Sleep(500);
//										system("CLS");
//									}
//									else if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1]) // forward diaginal condition
//									{
//										arr[i][j] = ' ';
//										arr[i - 1][j + 1] = ' ';
//										arr[i + 1][j - 1] = ' ';
//										score += 15;
//										system("CLS");
//										cout << "------------------------" << endl;
//										cout << "|                      |" << endl;
//										cout << "|         SWEET        |" << endl;
//										cout << "|   fdia        loading|" << endl;
//										cout << "------------------------" << endl;
//										Sleep(500);
//										system("CLS");
//
//
//									}
//									else if (arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1])// backward diagonal condition
//									{
//										arr[i][j] = ' ';
//										arr[i - 1][j - 1] = ' ';
//										arr[i + 1][j + 1] = ' ';
//										score += 15;
//										system("CLS");
//										cout << "------------------------" << endl;
//										cout << "|                      |" << endl;
//										cout << "|         SWEET        |" << endl;
//										cout << "|    bdia       loading|" << endl;
//										cout << "------------------------" << endl;
//										Sleep(500);
//										system("CLS");
//									}
//								}
//							}
//							swpspaceEASY(arr);
//							fill(arr);
//							pikachuu--;
//						}
//					}
//					Sleep(1000);
//					system("CLS");
//				}
//				if (stoptimer <= 0 || turn <= 0)
//				{
//
//					cout << name << " scored :" << score << endl;
//					fstream file;/// ifstream  fin..../// ofstream out  ... fout ... fin.>> 
//					file.open("SCOREBOARD.txt", ios::app); // fin.open//ios::in.
//					file << name;
//					file << " ";
//					file << score;
//					file << endl;
//					file.close();
//				}
//			}
//			else if (mode == 2)//////////////////hard modeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
//			{
//				int count = 0;
//				int score = 0;
//				int turn = 15;
//				char arr[10][10];
//				int stoptimer = 40;
//				if (count == 0)
//					FILLcandieshard(arr);//fill table with candies
//				count++;
//				while (stoptimer >= 0 && turn > 0)
//				{
//					system("CLS");
//					SetConsoleTextAttribute(h, 4);
//					cout << "\t\t\t\t " << name << " selected Hard Mode." << endl << endl;
//					SetConsoleTextAttribute(h, 7);
//					cout << "TIMER : " << stoptimer << endl;
//					cout << "Turns :" << turn << endl;
//					cout << "Score :" << score << endl;
//					stoptimer--;
//					cout << "   |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |" << endl;
//					cout << "   -------------------------------------------------------------" << endl;
//					for (int i = 0; i < 10; i++)
//					{
//						cout << " " << i << " | ";
//						for (int j = 0; j < 10; j++)
//						{
//							if (arr[i][j] == '@')
//								SetConsoleTextAttribute(h, 1);//colouring symbols
//							else if (arr[i][j] == '#')
//								SetConsoleTextAttribute(h, 2);
//							else if (arr[i][j] == '$')
//								SetConsoleTextAttribute(h, 3);
//							else if (arr[i][j] == '%')
//								SetConsoleTextAttribute(h, 4);
//							else if (arr[i][j] == '&')
//								SetConsoleTextAttribute(h, 5);
//							else if (arr[i][j] == '!')
//								SetConsoleTextAttribute(h, 6);
//							else if (arr[i][j] == '*')
//								SetConsoleTextAttribute(h, 7);
//							cout << " " << arr[i][j] << " ";
//							SetConsoleTextAttribute(h, 15);
//							cout << "  |";
//						}
//						cout << endl;
//						cout << "   -------------------------------------------------------------";
//						cout << endl;
//					}
//					SetConsoleTextAttribute(h, 3);
//					cout << "Press Rshift To select Candy..." << endl;
//					SetConsoleTextAttribute(h, 7);
//					if (GetAsyncKeyState(VK_RSHIFT))
//					{
//						int i = 0, j = 0;
//						bool found = 1;
//						bool valid = 1;
//						while (valid == 1)
//						{
//							cout << "Which Element You want to swap?";
//							cout << "\nInput i:";
//							cin >> i;
//							cout << "\nInput j:";
//							cin >> j;
//							if (i >= 0 && i < 10 && j >= 0 && j < 10)
//								valid = 0;
//							else
//							{
//								cout << "\nInvalid Input... Enter Between 0 and 7." << endl;
//								valid = 1;
//							}
//						}
//						cout << "Selected Sybmol: " << arr[i][j] << endl;
//						cout << "Press Arrow Keys to swipe :";
//						while (found == 1) {
//							int c;
//							switch (c = _getch())
//							{
//							case KEY_UP:
//							{
//								if (i == 0)
//								{
//									cout << "Invalid Move." << endl;
//								}
//								else
//								{
//									char swp = ' ';
//									swp = arr[i][j];
//									arr[i][j] = arr[i - 1][j];
//									arr[i - 1][j] = swp;
//									turn--;
//									found = 0;
//									break;
//								}
//							case KEY_DOWN:
//							{
//								if (i == 9)
//								{
//									cout << "Invalid Move." << endl;
//								}
//								else
//								{
//									char swp = ' ';
//									swp = arr[i][j];
//									arr[i][j] = arr[i + 1][j];
//									arr[i + 1][j] = swp;
//									turn--;
//								}
//								found = 0;
//								break;
//							}
//							case KEY_LEFT:
//							{
//								if (j == 0)
//									cout << "Invalid Move." << endl;
//								else
//								{
//									char swp = ' ';
//									swp = arr[i][j];
//									arr[i][j] = arr[i][j - 1];
//									arr[i][j - 1] = swp;
//									turn--;
//								}
//								found = 0;
//								break;
//							}
//							case KEY_RIGHT:
//							{
//								if (j == 9)
//									cout << "Invalid Move." << endl;
//								else
//								{
//									char swp = arr[i][j];
//									arr[i][j] = arr[i][j + 1];
//									arr[i][j + 1] = swp;
//									turn--;
//								}
//								found = 0;
//								break;
//							}
//							}
//							cout << endl;
//							}
//						}
//						int pikachu = 10;
//						while (pikachu > 0)
//						{
//							for (int i = 0; i < 10; i++)
//							{
//								for (int j = 0; j < 10; j++)
//								{
//
//									if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j + 1] && arr[i][j] == arr[i + 2][j + 2])//L shape Condition spaces
//									{
//										arr[i][j] = ' ';
//										arr[i + 1][j] = ' ';
//										arr[i + 2][j] = ' ';
//										arr[i][j + 1] = ' ';
//										arr[i][j + 2] = ' ';
//										score += 25;
//										system("CLS");
//										cout << "------------------------" << endl;
//										cout << "|                      |" << endl;
//										cout << "|         SWEET        |" << endl;
//										cout << "|  lshape       loading|" << endl;
//										cout << "------------------------" << endl;
//										Sleep(500);
//										system("CLS");
//									}
//									else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])// vertical condition check 
//									{
//										arr[i][j] = ' ';
//										arr[i + 1][j] = ' ';
//										arr[i + 2][j] = ' ';
//										score += 10;
//										system("CLS");
//										cout << "------------------------" << endl;
//										cout << "|                      |" << endl;
//										cout << "|         SWEET        |" << endl;
//										cout << "|   vert        loading|" << endl;
//										cout << "------------------------" << endl;
//										Sleep(500);
//										system("CLS");
//									}
//									else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])  // horizontal condition
//									{
//										arr[i][j] = ' ';
//										arr[i][j + 1] = ' ';
//										arr[i][j + 2] = ' ';
//										score += 10;
//										system("CLS");
//										cout << "------------------------" << endl;
//										cout << "|                      |" << endl;
//										cout << "|         SWEET        |" << endl;
//										cout << "|    hori       loading|" << endl;
//										cout << "------------------------" << endl;
//										Sleep(500);
//										system("CLS");
//									}
//									else if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1]) // forward diaginal condition
//									{
//										arr[i][j] = ' ';
//										arr[i - 1][j + 1] = ' ';
//										arr[i + 1][j - 1] = ' ';
//										score += 15;
//										system("CLS");
//										cout << "------------------------" << endl;
//										cout << "|                      |" << endl;
//										cout << "|         SWEET        |" << endl;
//										cout << "|   fdia        loading|" << endl;
//										cout << "------------------------" << endl;
//										Sleep(500);
//										system("CLS");
//									}
//									else if (arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1])// backward diagonal condition
//									{
//										arr[i][j] = ' ';
//										arr[i - 1][j - 1] = ' ';
//										arr[i + 1][j + 1] = ' ';
//										score += 15;
//										system("CLS");
//										cout << "------------------------" << endl;
//										cout << "|                      |" << endl;
//										cout << "|         SWEET        |" << endl;
//										cout << "|    bdia       loading|" << endl;
//										cout << "------------------------" << endl;
//										Sleep(500);
//										system("CLS");
//									}
//								}
//							}
//							swpspaceHARD(arr);
//							fillhard(arr);
//							pikachu--;
//						}
//
//					}
//					Sleep(1000);
//					system("CLS");
//				}
//				if (stoptimer <= 0 || turn <= 0)
//				{
//					cout << name << " scored :" << score << endl;
//					fstream file;
//					file.open("SCOREBOARD.txt", ios::app);
//					file << name;
//					file << " ";
//					file << score;
//					file << "\n";
//				}
//			}
//		}
//		else if (game == 2)
//		{
//			system("CLS");
//			char b = ' ';
//			while (b == ' ')
//			{
//				if (GetAsyncKeyState(VK_ESCAPE))
//				{
//					b = 'a';
//				}
//				SetConsoleTextAttribute(h, 6);
//				cout << "\t\t\t\t |----------CREDITS-----------|" << endl;
//				cout << "\t\t\t\t |                            |" << endl;
//				cout << "\t\t\t\t |   Faizan Tariq   22F-3858  |" << endl;
//				cout << "\t\t\t\t |                            |" << endl;
//				cout << "\t\t\t\t | Wareesha Ashraf  22F-3441  |" << endl;
//				cout << "\t\t\t\t |                            |" << endl;
//				cout << "\t\t\t\t |                            |" << endl;
//				cout << "\t\t\t\t |   Press ESC to go back.    |" << endl;
//				cout << "\t\t\t\t |----------------------------|" << endl;
//				Sleep(1000);
//				system("CLS");
//				SetConsoleTextAttribute(h, 7);
//			}
//		}
//		else if (game == 3)
//		{
//			char b = ' ';
//			system("CLS");
//			while (b == ' ')
//			{
//				if (GetAsyncKeyState(VK_ESCAPE))
//				{
//					b = 'a';
//				}
//				SetConsoleTextAttribute(h, 6);
//				cout << "\t\t\t\t |---------------------Instructions---------------------|" << endl;
//				cout << "\t\t\t\t |                                                      |" << endl;
//				cout << "\t\t\t\t | How to Play:                                         |" << endl;
//				cout << "\t\t\t\t |                                                      |" << endl;
//				cout << "\t\t\t\t |   1. Select Play Mode By pressing 1 or 2             |" << endl;
//				cout << "\t\t\t\t |   2. Press Right Shift to Select Candy.              |" << endl;
//				cout << "\t\t\t\t |   3. Give Candy address.                             |" << endl;
//				cout << "\t\t\t\t |   3. Press Arrow Key To Swap with.                   |" << endl;
//				cout << "\t\t\t\t |                                                      |" << endl;
//				cout << "\t\t\t\t | GamePlay:                                            |" << endl;
//				cout << "\t\t\t\t |                                                      |" << endl;
//				cout << "\t\t\t\t |   1. When Player Swipe Candy and candy not crushes,  |" << endl;
//				cout << "\t\t\t\t |  Turn will be lost and Candy will swipe.             |" << endl;
//				cout << "\t\t\t\t |   2.If condition Matches Upper Candies Will move down|" << endl;
//				cout << "\t\t\t\t |   and new Candies will be generated above.           |" << endl;
//				cout << "\t\t\t\t |                                                      |" << endl;
//				cout << "\t\t\t\t |    Press ESC for go back..                           |" << endl;
//				cout << "\t\t\t\t |------------------------------------------------------|" << endl;
//				Sleep(1000);
//				system("CLS");
//				SetConsoleTextAttribute(h, 7);
//			}
//		}
//		else if (game == 4)
//		{
//			SetConsoleTextAttribute(h, 6);
//			system("CLS");
//			char b = ' ';
//			while (b == ' ')
//			{
//				cout << "Press ESC to go back." << endl;
//				if (GetAsyncKeyState(VK_ESCAPE))
//				{
//					b = 'a';
//				}
//				int score;
//				char ch = ' ';
//				string record;
//				string nam;
//				fstream disp;
//				disp.open("SCOREBOARD.txt", ios::in);
//				while (!disp.eof())
//				{
//					getline(disp, record);
//					cout << endl << record;
//				}
//				Sleep(1000);
//				system("CLS");
//			}
//		}
//		else if (game == 5)
//		{
//			replay = 'N';
//		}
//	}
//	SetConsoleTextAttribute(h, 7);
//	for (int z = 1; z < 7; z++)
//	{
//		SetConsoleTextAttribute(h, z);
//		string str = "Happy Coding";
//		cout << str << endl;
//		Sleep(500);
//		if (z == 6) {
//			system("start https://github.com/Faizan-26/Candy-Crush-C-Project-Fast");
//		}
//	}
//	SetConsoleTextAttribute(h, 15);
//	return 0;
//}