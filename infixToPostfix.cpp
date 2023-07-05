#include <iostream>
#include <stack>
#include <string>

using namespace std;

// function to return precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// function to convert infix expression to postfix
string infixToPostfix(string expression)
{
    string postfix = "";
    stack<char> opStack;

    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        // if current character is an operand, add it to the postfix expression
        if (isalnum(c))
            postfix += c;

        // if current character is an operator
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c))
            {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }

        // if current character is a left parenthesis, push it onto the stack
        else if (c == '(')
            opStack.push(c);

        // if current character is a right parenthesis, pop operators from the stack and add them to postfix until a left parenthesis is found
        else if (c == ')')
        {
            while (!opStack.empty() && opStack.top() != '(')
            {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // remove the left parenthesis from the stack
        }
    }

    // pop any remaining operators from the stack and add them to postfix
    while (!opStack.empty())
    {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

int main()
{
    string infix = "(a-b/c)*(a/k-l)";
    string postfix = infixToPostfix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
