#include <iostream>
#include <stack>
using namespace std;
stack<int> st;
void display()
{
    while (!st.empty())
    {
        cout << "the elements of stack are: " << st.top() << endl;
        st.pop();
    }
}
void pop()
{
    if (!st.empty())
    {
        cout << "the popped elements are: " << st.pop() << endl;
    }
    else
    {
        cout << "the stack is empty";
    }
}

int main()
{
    st.push(11);
    st.push(22);
    display();
    pop();
    int choice;
    cout << "enter choice 1)display 2)pop: " << endl;
    cin >> choice;
    switch (choice)
    {

    case 1:
        display();
        break;
    case 2:
        pop();
        break;
    default:
        cout << "invalid choice" << endl;
        break;
    }
}
