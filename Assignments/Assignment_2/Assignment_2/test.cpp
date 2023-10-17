//#include <iostream>
//#include <string>
//using namespace std;
//
//struct Node
//{
//    string data;
//    Node* next;
//
//    Node(string dat) : data(dat), next(nullptr) {}
//};
//
//class Stack
//{
//    Node* top;
//
//public:
//    Stack() : top(nullptr) {}
//    ~Stack()
//    {
//        clear();
//    }
//
//    void push(string ch)
//    {
//        Node* newNode = new Node(ch);
//        newNode->next = top;
//        top = newNode;
//    }
//
//    string pop()
//    {
//        if (!isEmpty())
//        {
//            string temp = top->data;
//            Node* tempNode = top;
//            top = top->next;
//            delete tempNode;
//            return temp;
//        }
//        return " ";
//    }
//
//    bool isEmpty()
//    {
//        return top == nullptr;
//    }
//
//    void clear()
//    {
//        while (!isEmpty())
//        {
//            pop();
//        }
//    }
//
//    string getTop()
//    {
//        if (!isEmpty())
//        {
//            return top->data;
//        }
//        return " ";
//    }
//
//    int checkPrecedence(string c)
//    {
//        if (c == "*" || c == "/" || c == "%")
//            return 2;
//        else if (c == "+" || c == "-")
//            return 1;
//        else
//            return 0;
//    }
//
//    string infixtoPostfix(string input)
//    {
//        string outputStream;
//
//        string temp;
//        int length = input.length();
//        for (int i = 0; i < length; i++)
//        {
//            temp = input[i];
//            if (temp >= "0" && temp <= "9")
//            {
//                outputStream += temp;
//            }
//            else if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
//            {
//
//                while (!isEmpty() && checkPrecedence(getTop()) >= checkPrecedence(temp) && getTop() != "(")
//                {
//                    outputStream += getTop();
//                    pop();
//                }
//
//                push(temp);
//            }
//            else if (temp == " ")
//            {
//                outputStream += temp;
//            }
//            else if (temp == "(")
//            {
//                push(temp);
//            }
//            else if (temp == ")")
//            {
//                while (!isEmpty() && getTop() != "(")
//                {
//                    outputStream += getTop();
//                    pop();
//                }
//                if (!isEmpty() && getTop() == "(")
//                    pop();
//            }
//        }
//        while (!isEmpty())
//        {
//            outputStream += getTop();
//            pop();
//        }
//        return outputStream;
//    }
//
//    string infixtoPrefix(string& input)
//    {
//        string reverseinfix = input, outputString= "";
//        string temp;
//        for (int i = input.length() - 1; i > 0; i--)
//        {
//            reverseinfix += input[i];
//        }
//
//        for (int i = 0; i < input.length(); i++)
//        {
//            temp = reverseinfix[i];
//            if (temp >= "0" && temp <= "9")
//            {
//                outputString += temp;
//            }
//            else if (temp == " ")
//            {
//                outputString += temp;
//            }
//            else if (temp == ")")
//            {
//                temp = temp;
//                push(temp);
//            }
//            else if (temp == "+" || temp == "-" || temp == "*" || temp == "/" || temp == "%")
//            {
//                while (!isEmpty() && checkPrecedence(getTop()) > checkPrecedence(temp) && getTop() != "(")
//                {
//                    outputString += getTop();
//                    pop();
//                }
//                push(temp);
//            }
//            else if (temp == "(")
//            {
//                while (!isEmpty() && getTop() != ")")
//                {
//                    outputString += getTop();
//                    pop();
//                }
//                if (!isEmpty() && getTop() == ")")
//                    pop();
//            }
//        }
//        while (!isEmpty() && getTop() != "(")
//        {
//            outputString += getTop();
//            pop();
//        }
//        if (!isEmpty() && getTop() == "(")
//            pop();
//        string result;
//        for (int i = outputString.length() - 1; i > 0; i--)
//        {
//            result += outputString[i];
//        }
//        return result;
//    }
//
//    bool isOperator(char ch)
//    {
//        return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
//    }
//
//    int performOperation(char op, int operand1, int operand2)
//    {
//        int result = 0;
//        if (op == '+')
//        {
//            result = operand1 + operand2;
//        }
//        else if (op == '-')
//        {
//            result = operand1 - operand2;
//        }
//        else if (op == '/')
//        {
//            if (operand2 == 0)
//            {
//                cout << "Operand 2 is Zero" << endl;
//            }
//            result = operand1 / operand2;
//        }
//        else if (op == '*')
//        {
//            result = operand1 * operand2;
//        }
//        else if (op == '%')
//        {
//            result = operand1 % operand2;
//        }
//        return result;
//    }
//
//    string evaluatePostexpression(string ch)
//    {
//        int length = ch.length();
//        char op;
//        int operand2, operand1, operationResult;
//        string temp;
//        string temp2 = " ";
//        for (int i = 0; i < length; i++)
//        {
//            temp2 = ch[i];
//            if (temp2 == " ") {
//                continue;
//            }
//            if (!isOperator(ch[i]) && ch[i] != ' ' && ch[i] != '(' && ch[i] != ')')
//            {
//               /* temp = "";
//                while ((i < length) && (!isOperator(ch[i])) && (ch[i] != ' '))
//                {
//                    temp += ch[i];
//                    i++;
//                }*/
//                push(temp);
//            }
//            else if (isOperator(ch[i]))
//            {
//                operand2 = stoi(pop());
//                operand1 = stoi(pop());
//                cout << " -----------------------------------------------" << endl;
//                cout << "Operand 1 is: " << operand1 << " Operand 2 is " << operand2 << endl;
//                op = ch[i];
//                cout << "Operation to be perfomed is " << op << endl;
//                operationResult = performOperation(op, operand1, operand2);
//                cout << "Result of operation " << operationResult << endl;
//                push(to_string(operationResult));
//            }
//        }
//        string finalResult = pop();
//        return finalResult;
//    }
//};
//
//int main()
//{
//    string input, Postfix, Prefix;
//    string choice;
//    Stack stack1;
//
//    do
//    {
//        cout << "Infix to Prefix && Postfix Converter :" << endl;
//        cout << "1. Convert to Postfix" << endl;
//        cout << "2. Convert to Prefix" << endl;
//        cout << "3. Evaluate your Answer" << endl;
//        cout << "4. Exit" << endl;
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        cin.ignore();
//        if (choice == "1")
//        {
//            cout << "Enter the infix expression: ";
//            getline(cin, input);
//            Postfix = stack1.infixtoPostfix(input);
//            cout << "Postfix notation is: " << Postfix << endl;
//        }
//        else if (choice == "2")
//        {
//            cout << "Enter the infix expression: ";
//            getline(cin, input);
//            Prefix = stack1.infixtoPrefix(input);
//            cout << "Prefix notation is: " << Prefix << endl;
//        }
//        else if (choice == "3")
//        {
//            if (!Postfix.empty())
//            {
//                string answer = stack1.evaluatePostexpression(Postfix);
//
//                cout << "Result is " << answer << endl
//                    << endl;
//            }
//            else
//                cout << "Postfix String Empty!";
//        }
//        else if (choice == "4")
//        {
//            return 0;
//        }
//        else cout << "Error Wrong input" << endl;
//
//    } while (choice != "4");
//
//    return 0;
//}