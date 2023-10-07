//#include<iostream>
//#include<string>
//using namespace std;
//struct Node {
//	string command;
//	Node* next;
//	Node() {
//		next = NULL;
//		command = "";
//	}
//	Node(string command) {
//		next = NULL;
//		this->command = command;
//	}
//};
//class undoRedo{
//	Node* top;
//	bool enabled;
//public:
//	undoRedo() {
//		top = NULL;
//		enabled = false;
//	}
//	string getEnabled() {
//		return enabled ?"Enabled":"Disabled";
//	}
//	void setEnabled(bool value) {
//		enabled = value;
//	}
//	bool isEmpty() {
//		return top == NULL;
//	}
//	bool push(string command) {
//		Node* newNode = new Node(command);
//		if (isEmpty()) {
//			top = newNode;
//			enabled = true;
//			return true;
//		}
//		newNode->next = top;
//		top = newNode;
//		enabled = true;
//		return true;
//	}
//	bool pop(string & returnData) {
//		if (isEmpty()) {
//			return false;
//		}
//		returnData = top->command;
//		Node* DeleteNode = top;
//		top = top->next;
//		delete DeleteNode;
//		if (isEmpty()) {
//			enabled = false;
//		}
//		return true;
//	}
//	void makeNull() {
//		string temp;
//		while (!isEmpty()) {
//			pop(temp);
//		}
//	}
//};
//int main() {
//	cout << "LIST OF COMMANDS :\n->undo.\n->redo.\n->add(Any text to add).\n->delete.";
//	undoRedo undo, redo;
//	string commands = " ";
//	string deletedCommand = " ";
//	while (1) {
//		cout << "\n[undo: " << undo.getEnabled() << " , " << "redo: " << redo.getEnabled() << "]"<<endl;
//		cout << "Type your command : ";
//		cin >> commands;
//		if (commands == "undo") {
//			if (undo.pop(deletedCommand)) {
//				redo.push(deletedCommand);
//			}
//		}
//		else if (commands == "redo") {
//			if (redo.pop(deletedCommand)) {
//				undo.push(deletedCommand);
//			}
//		}
//		else if (commands == "delete") { // if command is delete 
//			if (undo.pop(deletedCommand)) {
//				redo.makeNull();
//				cout <<endl<< deletedCommand << " undone.\n";
//			}
//		}
//		else if (commands == "quit" || commands == "Quit" || commands == "QUIT") {
//			break;
//		}
//		else { // for add text
//			undo.push(commands);
//		}
//	}
//	return 0;
//}