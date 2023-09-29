//#include<iostream>
//#include<string>
//using namespace std;
//struct MessageData {
//	string message;
//	int priority; // message having higher priority will display at end in frontEnd
//	MessageData() {
//		message = " ";
//		priority = 0;
//	}
//	MessageData(string Message, int pri = 0) {
//		message = Message;
//		priority = pri;
//	}
//};
//struct Node {
//	MessageData Message;
//	Node* next;
//	Node() {
//		Message.message = " ";
//		Message.priority = 0;
//		next = NULL;
//	}
//	Node(string MessageText, int pri = 0) {
//		Message.message = MessageText;
//		Message.priority = pri;
//		next = NULL;
//	}
//};
//class QueueMessages {
//	Node* rear;
//	int numOfMessages;
//	bool activeUser; // if user is offline then dequeue will wait for user to active
//	Node* front;
//public:
//	QueueMessages() {
//		rear = NULL;
//		numOfMessages = 0;
//		activeUser = false;
//		front = NULL;
//	}
//	bool isEmpty() {
//		return numOfMessages == 0;
//	}
//	void sendMessage(string messageinfo, int priority = 0) { // add message in queue like enqueue
//		Node* newMessage = new Node(messageinfo, priority);
//	
//		if (isEmpty()) {
//			rear = newMessage;
//			front = newMessage;
//			numOfMessages++;
//			return;
//		}
//		numOfMessages++;
//		rear->next = newMessage;
//		rear = newMessage;
//	}
//	void dequeue() { // when message is recieved it will delete from queue
//		int choice = 0;
//		if (!activeUser) {
//			cout << "Enter Any value(1-10) to get online and recieve messages! and invalid input to make it offline\n";
//			cin >> choice;
//			if (choice > 0 && choice <= 10) {
//				cout << "\nYou are know online!\n";
//				activeUser = true;
//			}
//			else {
//				activeUser = false;
//			}
//		}
//
//		if (activeUser) {
//			if (isEmpty()) {
//				cout << "\n No message exists in queue\n";
//				return;
//			}
//			Node* recievedMessage = front; // the message that is recieved similar to deleteMessage at this stage
//			front = front->next;
//
//			cout << "\n" << recievedMessage->Message.message << "is recived by user.\n";
//			cout << "\n Priority of message :" << recievedMessage->Message.priority << endl;
//
//			delete  recievedMessage; // delete after displaying the priority
//			numOfMessages--;
//		}
//		else {
//			activeUser = false;
//			cout << "\nUser is not active yet.\n";
//		}
//	}
//	~QueueMessages() {
//		while (!isEmpty()) {
//			dequeue();
//		}
//		rear = NULL;
//		front = NULL;
//	}
//};
//void menu() {
//	cout << "\n1. Send Message.\n";
//	cout << "\n2. Recieve Message.\n";
//	cout << "\n Enter -1 to exit";
//}
//int main() {
//	QueueMessages message;
//	int choice = 0;
//	string tempMessage;
//	int pri;
//
//	while (1) {
//		menu();
//		cin >> choice;
//
//		if (choice == 1) {
//			cout << "\n Enter Message to send to user :";
//			cin >> tempMessage;
//
//			cout << "\nEnter Priority of message :";
//			cin >> pri;
//
//			message.sendMessage(tempMessage, pri);
//		}
//		else if (choice == 2) {
//			message.dequeue();
//		}
//
//		if (choice == -1) {
//			break;
//		}
//	}
//
//	cout << "\nMessage app closed.\n";
//	return 0;
//
//}
