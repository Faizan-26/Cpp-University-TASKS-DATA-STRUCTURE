#include <iostream>
#include <string>
using namespace std;

struct Node {
    string courseCode;
    Node* left;
    Node* right;

    Node(string code) : courseCode(code), left(NULL), right(NULL) {}
};

class CourseScheduler {

public:
    Node* root;
    CourseScheduler() : root(NULL) {}

    Node* EnrollCourse(Node* node, string code) {
        if (node == NULL) {
            return new Node(code);
        }

        if (code < node->courseCode) {
            node->left = EnrollCourse(node->left, code);
        }
        else if (code > node->courseCode) {
            node->right = EnrollCourse(node->right, code);
        }

        return node;
    }

    Node* WithdrawCourse(Node* node, string code) {
        if (node == NULL) {
            return node;
        }
        if (code > node->courseCode) {
            node->right = WithdrawCourse(node->right, code);
        }
        else if (code < node->courseCode) {
            node->left = WithdrawCourse(node->left, code);
        }
        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* minRight = findMinimum(node->right);
            node->courseCode = minRight->courseCode;
            node->right = WithdrawCourse(node->right, minRight->courseCode);
        }
        return node;
    }

    Node* search(Node* node, string code) {
        if (node == NULL || node->courseCode == code) {
            return node;
        }

        if (code < node->courseCode) {
            return search(node->left, code);
        }
        else {
            return search(node->right, code);
        }
    }

    void inOrderTraversal(Node* node) {
        if (node != NULL) {
            inOrderTraversal(node->left);
            cout << node->courseCode << endl;
            inOrderTraversal(node->right);
        }
    }

    Node* findMinimum(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    CourseScheduler scheduler;
    scheduler.root= scheduler.EnrollCourse(scheduler.getRoot(), "Data");
    scheduler.root = scheduler.EnrollCourse(scheduler.getRoot(), "COAL");
    scheduler.root = scheduler.EnrollCourse(scheduler.getRoot(), "Discrete");
    cout << "Enrolled Courses :\n";
    scheduler.inOrderTraversal(scheduler.getRoot());
    cout << "\nWithdraw Course COAL.\n";
    scheduler.root = scheduler.WithdrawCourse(scheduler.getRoot(), "COAL");
    cout << "\nFinding DATA COURSE.\n";
    Node* course = scheduler.search(scheduler.getRoot(), "Data");
    if (course != NULL) {
        cout << "Found: " << course->courseCode << endl;
    }
    else {
        cout << "Course not found." << endl;
    }
    scheduler.inOrderTraversal(scheduler.getRoot());

    return 0;
}
