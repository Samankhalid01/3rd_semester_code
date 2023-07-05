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
        if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    if (isValid(s))
    {
        cout << "Valid string" << endl;
    }
    else
    {
        cout << "Invalid string" << endl;
    }
    return 0;
}
