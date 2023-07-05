#include <iostream>
#include <stack>
#include <string>

using namespace std;

char *reverse(char *S, int len)
{
    stack<char> st;
    for (int i = 0; i < len; i++)
        st.push(S[i]);
    char *a = new char[len + 1]; // allocate memory for null terminator
    int i = 0;
    while (!st.empty())
    { // add parentheses
        a[i++] = st.top();
        st.pop();
    }
    a[i] = '\0';
    return a;
}

int main()
{
    string x;
    cout << "Enter the string you want to reverse: " << endl;
    getline(cin, x);
    char *r = reverse(&x[0], x.length()); // pass address of first character in string
    cout << r << endl;
    delete[] r;
    return 0;
}
