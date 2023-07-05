#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int v = 5;
    int visited[v] = {0}; // Initialize visited array to 0
    int cost_matrix[v][v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << "Enter the path between " << i << " and " << j << ": ";
            cin >> cost_matrix[i][j];
        }
    }

    int u = 0;
    queue<int> myQueue;

    myQueue.push(u); // Start BFS from vertex u
    visited[u] = 1;  // Mark vertex u as visited

    cout << "The BFS traversal of this graph is: ";
    while (!myQueue.empty())
    {
        u = myQueue.front();
        myQueue.pop();

        cout << u << " "; // Display the current vertex

        // Push the adjacent vertices of u into the queue
        for (int j = 0; j < v; j++)
        {
            if (cost_matrix[u][j] == 1 && visited[j] == 0)
            {
                myQueue.push(j); // Add the adjacent vertex j to the queue
                visited[j] = 1;  // Mark vertex j as visited
            }
        }
    }
    cout << endl;

    return 0;
}
