//#include <iostream>
//#include <stack>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int checkPrecedence(char c)
//{
//    if (c == '*' || c == '/')
//        return 2;
//    else if (c == '+' || c == '-')
//        return 1;
//    else
//        return 0;
//}
////*+ABC
//string infixtoPrefix(string& input)
//{
//    string reverseinfix = input, outputString;
//    stack<char> charStack;
//    reverse(reverseinfix.begin(), reverseinfix.end()); // First Reverse the string using reverse from algorithm header file
//    for (int i = 0; i < input.length(); i++)
//    {
//        if ((reverseinfix[i] >= 'a' && reverseinfix[i] <= 'z') || (reverseinfix[i] >= 'A' && reverseinfix[i] <= 'Z') || (reverseinfix[i] >= '0' && reverseinfix[i] <= '9'))
//        {
//            outputString += reverseinfix[i];
//        }
//        else if (reverseinfix[i] == ')')
//        {
//            charStack.push(reverseinfix[i]);
//        }
//        else if (reverseinfix[i] == '+' || reverseinfix[i] == '-' || reverseinfix[i] == '*' || reverseinfix[i] == '/')
//        {
//            while (!charStack.empty() && checkPrecedence(charStack.top()) > checkPrecedence(input[i]) && charStack.top() != '(')
//            {
//                outputString += charStack.top();
//                charStack.pop();
//            }
//            charStack.push(input[i]);
//        }
//        else if (reverseinfix[i] == '(')
//        {
//            while (!charStack.empty() && charStack.top() != ')')
//            {
//                outputString += charStack.top();
//                charStack.pop();
//            }
//            if (!charStack.empty() && charStack.top() == ')')
//                charStack.pop(); // Pop the closing parenthesis
//        }
//    }
//    while (!charStack.empty() && charStack.top() != '(')
//    {
//        outputString += charStack.top();
//        charStack.pop();
//    }
//    if (!charStack.empty() && charStack.top() == '(')
//        charStack.pop(); // Pop the opening parenthesis
//    reverse(outputString.begin(), outputString.end());
//    return outputString;
//}
//
//// AB+C*
//string infixtoPostfix(string& input)
//{
//    stack<char> charStack;
//    string outputStream;
//    int length = input.length();
//    for (int i = 0; i < length; i++)
//    {
//        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9'))
//        {
//            outputStream += input[i];
//        }
//        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
//        {
//
//            while (!charStack.empty() && checkPrecedence(charStack.top()) >= checkPrecedence(input[i]) && charStack.top() != '(')
//            {
//                outputStream += charStack.top();
//                charStack.pop();
//            }
//            charStack.push(input[i]);
//        }
//        else if (input[i] == '(')
//        {
//            charStack.push(input[i]);
//        }
//        else if (input[i] == ')')
//        {
//            while (!charStack.empty() && charStack.top() != '(')
//            {
//                outputStream += charStack.top();
//                charStack.pop();
//            }
//            if (!charStack.empty() && charStack.top() == '(')
//                charStack.pop(); // Pop the opening parenthesis
//        }
//    }
//    while (!charStack.empty())
//    {
//        outputStream += charStack.top();
//        charStack.pop();
//    }
//    return outputStream;
//}
//
//int main()
//{
//    string input, postfix, prefix;
//    cout << "Enter Expression: ";
//    getline(cin, input); // Read the expression as a line
//    postfix = infixtoPostfix(input);
//    cout << "Postfix Notation: " << postfix << endl;
//    prefix = infixtoPrefix(input);
//    cout << "Prefix Notation: " << prefix << endl;
//
//    return 0;
//}