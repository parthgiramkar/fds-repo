#include <iostream>
#include <stack>
#include <cctype>  // For isdigit function
#include <string>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char current = infix[i];
        
        // If current character is an operand, add it to the result
        if (isalnum(current)) {
            postfix += current;
        }
        // If current character is '(', push it to the stack
        else if (current == '(') {
            s.push(current);
        }
        // If current character is ')', pop from stack until '(' is found
        else if (current == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // pop '('
        }
        // If current character is an operator
        else if (isOperator(current)) {
            while (!s.empty() && precedence(s.top()) >= precedence(current)) {
                postfix += s.top();
                s.pop();
            }
            s.push(current);
        }
    }
    
    // Pop all the remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    stack<int> s;
    
    for (int i = 0; i < postfix.length(); i++) {
        char current = postfix[i];
        
        // If current character is an operand (digit), push it onto the stack
        if (isdigit(current)) {
            s.push(current - '0'); // Convert char to integer
        }
        // If current character is an operator
        else if (isOperator(current)) {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            
            switch (current) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
            }
        }
    }
    
    // The final result will be at the top of the stack
    return s.top();
}

int main() {
    string infix, postfix;
    
    cout << "Enter infix expression (single character operands and operators only): ";
    cin >> infix;
    
    // Convert the infix expression to postfix
    postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    
    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    cout << "Evaluation of Postfix expression: " << result << endl;
    
    return 0;
}
