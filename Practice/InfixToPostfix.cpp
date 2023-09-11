// Problem Statement: 
// Create a class Expression having.
// •	A data member expression' to store a mathematical expression. The expression may consist of alphabets as operands and binary operators (+), parenthesis 
// •	A setExpression() method to set the value of expression. 
// •	A Member function infixToPostfix() that returns the postfix expression

// Input: 
// (a+b)-c*d-e 

// Expected Output:
//  ab+cd*-e-

// Input: 
// (a-b)*c-d 

// Expected Output:
// ab-c*d-

// Code:

#include <iostream>
#include <stack>
using namespace std;

int main() {
    string exp = "(a+b)-c*d^e";

    string postfix = "";
    stack<char> operators;

    auto getPrecedence = [](char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    };

    for (char ch : exp) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else {
            while (!operators.empty() && operators.top() != '(' && getPrecedence(ch) <= getPrecedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

