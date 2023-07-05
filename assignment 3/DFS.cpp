#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int v = 5;
    int arr[5];
    int visited[5] = {0}; // Initialize visited array to 0
    int cost_matrix[5][5];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << "Enter the path between " << i << " and " << j << ": ";
            cin >> cost_matrix[i][j];
        }
    }

    int u = 0;
    stack<int> myStack;
    visited[u] = 1;
    myStack.push(u);
    int index = 0;

    while (!myStack.empty())
    {
        int value = myStack.top();
        arr[index++] = value;
        myStack.pop();

        for (int j = 0; j < v; j++)
        {
            if (visited[j] == 0 && cost_matrix[value][j] == 1)
            {
                myStack.push(j);
                visited[j] = 1;
            }
        }
    }

    for (int i = 0; i < index; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
