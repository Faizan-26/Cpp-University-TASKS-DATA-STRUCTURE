#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <algorithm> 
#include <cmath>
using namespace std;

// A function to check if a character is an operator
bool isOperator(char c) {
    return c == '^' || c == 'V' || c == '!' || c == '-' || c == '<';
}

// A function to check if a character is a variable
bool isVariable(char c) {
    return c >= 'A' && c <= 'Z';
}

// A function to convert an infix expression to a postfix expression
string infixToPostfix(string infix) {
    string postfix = "";
    stack<char> s;
    for (char c : infix) {
        if (isVariable(c)) { // if c is a variable, append it to postfix
            postfix += c;
        }
        else if (c == '(') { // if c is an opening parenthesis, push it to the stack
            s.push(c);
        }
        else if (c == ')') { // if c is a closing parenthesis, pop and append all operators until an opening parenthesis is found
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') { // pop and discard the opening parenthesis
                s.pop();
            }
        }
        else if (isOperator(c)) { // if c is an operator, pop and append all operators with higher or equal precedence, then push c to the stack
            if (c == '-') { // if c is '-', check the next character for '>'
                if (postfix.back() == '>') { // if the previous character was '>', append '-' to postfix
                    postfix += c;
                }
                else { // otherwise, push '-' to the stack
                    s.push(c);
                }
            }
            else if (c == '<') { // if c is '<', check the next character for '-'
                postfix += c; // append '<' to postfix
            }
            else { // for other operators, pop and append all operators with higher or equal precedence
                while (!s.empty() && s.top() != '(' && s.top() != '-' && s.top() != '<') {
                    postfix += s.top();
                    s.pop();
                }
                s.push(c); // push c to the stack
            }
        }
    }
    while (!s.empty()) { // pop and append any remaining operators
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// A function to evaluate a postfix expression with a given assignment of variables
bool evaluatePostfix(string postfix, map<char, bool> vars) {
    stack<bool> s;
    for (char c : postfix) {
        if (isVariable(c)) { // if c is a variable, push its value to the stack
            s.push(vars[c]);
        }
        else if (isOperator(c)) { // if c is an operator, pop and apply it to the operands
            bool result;
            if (c == '!') { // if c is NOT, pop one operand and negate it
                bool a = s.top();
                s.pop();
                result = !a;
            }
            else { // for other operators, pop two operands and apply the operator
                bool b = s.top();
                s.pop();
                bool a = s.top();
                s.pop();
                if (c == '^') { // if c is AND, apply logical and
                    result = a && b;
                }
                else if (c == 'V') { // if c is OR, apply logical or
                    result = a || b;
                }
                else if (c == '>') { // if c is IMPLIES, apply logical implication
                    result = !a || b;
                }
                else if (c == '-') { // if c is BIDIRECTIONAL, apply logical equivalence
                    result = a == b;
                }
            }
            s.push(result); // push the result to the stack
        }
    }
    return s.top(); // return the final result
}

// A function to print the truth table of an expression
void printTruthTable(string expression) {
    // convert the expression to postfix notation
    string postfix = infixToPostfix(expression);

    // find the variables in the expression and store them in a vector
    vector<char> vars;
    for (char c : expression) {
        if (isVariable(c) && find(vars.begin(), vars.end(), c) == vars.end()) {
            vars.push_back(c);
        }
    }

    // sort the variables in alphabetical order
    sort(vars.begin(), vars.end());

    // print the header of the truth table
    for (char c : vars) {
        cout << c << " ";
    }
    cout << "| " << expression << "\n";

    // print a horizontal line
    for (int i = 0; i < vars.size() + expression.size() + 3; i++) {
        cout << "-";
    }
    cout << "\n";

    // print the rows of the truth table
    int n = vars.size(); // the number of variables
    int rows = pow(2, n); // the number of rows
    for (int i = 0; i < rows; i++) {
        // create a map to store the values of the variables for the current row
        map<char, bool> values;
        for (int j = 0; j < n; j++) {
            // assign the j-th bit of i to the j-th variable
            values[vars[j]] = (i >> (n - j - 1)) & 1;
        }

        // print the values of the variables
        for (char c : vars) {
            cout << values[c] << " ";
        }
        cout << "| ";

        // evaluate and print the value of the expression
        bool result = evaluatePostfix(postfix, values);
        cout << result << "\n";
    }
}

int main() {
    // get the expression from the user
    string expression;
    cout << "Enter an expression (use ^ for AND, V for OR, ! for NOT, -> for IMPLIES, and <-> for BIDIRECTIONAL): ";
    getline(cin, expression);

    // print the truth table of the expression
    printTruthTable(expression);

    return 0;
}
