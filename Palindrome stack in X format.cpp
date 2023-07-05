
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void palindrome_check(char *s);

int main()
{
    char s[100];
    cout << "Please enter the string in (--X--) format ";
    cin >> s;
    palindrome_check(s);
    return 0;
}

void palindrome_check(char *s)
{
    stack<char> st;
    int i = 0;
    while (s[i] != 'X')
    {
        st.push(s[i]);
        i++;
    }
    i++;
    while (s[i])
    {
        if (st.empty() || s[i] != st.top())
        {
            cout << "Not a palindrome" << endl;
            exit(1);
        }
        st.pop();
        i++;
    }
    cout << "It is a palindrome" << endl;
}
