#include<iostream>
using namespace std;

struct Node {
	int id;
	Node* next;
	bool read , unread, trash;
	Node() {
		id = 0;
		read = false;
		unread = true; // by default unread is true
		trash = false;
		next = NULL;
	}
	Node(int Id) {
		id = Id;
		read = false;
		unread = true; // by default unread is true
		trash = false;
		next = NULL;
	}
};
class Linkedlist {
private :
	Node* head;
	int id;
public:
	Linkedlist() {
		id = 0;
		head = NULL;
	}
	bool isEmpty() {
		return (head == NULL);
	}
	void addMessage() {
		id++; // assign id to every message greater than 1 to previous
		Node* newNode = new Node(id);
		if (isEmpty()) {
			head = newNode;
		}
		else {
			Node* cur = head;
			// traverse till end
			while (cur->next != NULL) {
				cur = cur->next;
			}
			cur->next = newNode;
		}
	}
	void displayUnreadSection() {
		cout << "\nInitial UNREAD Section : ";
		if (isEmpty()) {
			cout << "\nNo node present.\n";
		}
		Node* cur = head;
		bool found = false;
		while (cur != NULL) {
			if (cur->unread) { // if cur->unread == true
				cout << cur->id << "  ";
				found = true;
			}
			cur = cur->next;
		}
		if (!found) {
			cout << "\"Empty\"\n";
		}
	}
	void displayreadSection() {
		cout << "\nREAD Section : ";
		if (isEmpty()) {
			cout << "\nNo node present.\n";
		}
		Node* cur = head;
		bool found = false;
		while (cur != NULL) {
			if (cur->read) { // if cur->read != false
				cout << cur->id << "  ";
				found = true;
			}
			cur = cur->next;
		}
		if (!found) {
			cout << "\"Empty\"\n";
		}
	}
	void displaytrashSection() {
		cout << "\nTrash Section : ";
		if (isEmpty()) {
			cout << "\nNo node present.\n";
		}
		Node* cur = head;
		bool found = false;
		while (cur != NULL) {
			if (cur->trash) { // if cur->trash != false
				cout << cur->id<<"  ";
				found = true;
			}
			cur = cur->next;
		}
		if (!found) {
			cout << "\"Empty\"\n";
		}
	}
	void messageActions(int action_Id, int message_Id) {
		// for traverse to 1st check if message exists in list having that message_Id
		Node* cur = head;
		bool found = false;
		while (cur != NULL && message_Id != cur->id) { /// loop until cur have same id as message_ID
			cur = cur->next;
		}
		if (cur->id == message_Id) {
			found = true;
		}
		else {
			found = false;
		}
		if (!found) {
			cout << "\n Message cannot found having that id :" << message_Id << ", Please try again with different id.\n";
			return;
		}
		if (action_Id == 1) { // to convert unread to read
			if (cur->unread == true) {
				cur->read = true;
				cur->unread = false;
				cur->trash = false;
			}
			else if (cur->unread == false) {
				cout << "\n Message is already in read OR trash section.\n";
			}
		}
		else if (action_Id == 2) { // to convert read to trash
			if (cur->read == true) {
				cur->unread = false;
				cur->read = false;
				cur->trash = true;
			}
			else if (cur->read == false) {
				cout << "\n Message is already in unread OR trash section.\n";
			}
		}
		else if (action_Id == 3) { // to convert unread to trash
			if (cur->unread == true) {
				cur->read = false;
				cur->unread = false;
				cur->trash = true;
			}
			else if (cur->unread == false) {
				cout << "\n Message is already in read OR trash section.\n";
			}
		}
		else if (action_Id == 4) { // to convert trash to read
			if (cur->trash == true) {
				cur->read = true;
				cur->unread = false;
				cur->trash = false;
			}
			else if (cur->trash == false) {
				cout << "\n Message is already in read OR unread section.\n";
			}
		}
		else {
			cout << "\n Invalid Action id!\n";
		}
	}
	void displaySections() {
		displayUnreadSection();
		displayreadSection();
		displaytrashSection();
	}
};
void actionMenu() {
	cout << "\n1. Move the message with ID X from UNREAD to READ.";
	cout << "\n2. Move the message with ID X from READ to TRASH.";
	cout << "\n3. Move the message with ID X from UNREAD to TRASH.";
	cout << "\n4. Move the message with ID X from TRASH to READ.";
	cout << "\n Choose the action to perfrom :";
}
int main() {
	Linkedlist emailSystem;
	int n;
	cout << "How many messsages you want to add in you inbox :";
	cin >> n;
	while (n > 0) {
		emailSystem.addMessage(); // id will automatically be generated and incremented by 1
		n--;
	}
	int actionId = 0 , messageId = 0;
	while (actionId >= 0 && messageId >= 0) {
		cout << "\nEnter Your queries (-1 to exit) :\n";
		emailSystem.displaySections();
		cout << endl;
		actionMenu();
		cin >> actionId;
		cout << "\nEnter Id of message on which you want to perform an action :";
		cin >> messageId;
		emailSystem.messageActions(actionId, messageId);
	}
	return 0;
}