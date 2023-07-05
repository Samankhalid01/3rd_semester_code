#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> st;

bool isValid(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (!st.empty() && ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{'))) // if the stack is not empty and the top of the stack matches the closing bracket
            {
                st.pop(); // pop the opening bracket from the stack
            }
            else
            {
                return false;
            }
        }
    }

    if (!st.empty())
    {
        return false;
    }

    return true;
}

bool checkPrecedence(string input)
{
    stack<char> st;

    string validOrder = "[{()}]";
    int index = 0;
    for (int i = 0; i < input.size(); i++)
    {
        char c = input[i];
        if (c == validOrder[index])
        {
            st.push(c);
            index++;
        }
        else if (st.empty() || c != validOrder[index])
        {
            return false;
        }
        else if (c == validOrder[index])
        {
            st.pop();
            index++;
        }
    }
    return st.empty() && index == validOrder.size();
}

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    bool isValidStr = isValid(s);
    bool hasCorrectPrecedence = checkPrecedence(s);

    if (isValidStr && hasCorrectPrecedence)
    {
        cout << "Valid string with correct precedence" << endl;
    }
    else if (isValidStr && !hasCorrectPrecedence)
    {
        cout << "Valid string, but incorrect precedence" << endl;
    }
    else
    {
        cout << "Invalid string" << endl;
    }
    return 0;
}
