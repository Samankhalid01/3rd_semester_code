#include <iostream>
#include <stack>
#include <string>

using namespace std;

void palindrome_check(char *s);

int main()
{
    char s[100];
    cout << "Please enter the string: ";
    cin.getline(s, 100);
    palindrome_check(s);
    return 0;
}

void palindrome_check(char *s)
{
    int choice;
    stack<char> st;
    int i = 0;
    while (s[i] != '\0') // till it is not null
    {
        st.push(s[i]);
        i++;
    }
    i = 0;
    while (s[i] != '\0')
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
