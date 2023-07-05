#include <iostream>
#include <climits>
using namespace std;

int selectMinVertex(int distance[], bool visited[], int v)
{
    int minimum = INT_MAX;
    int vertex;
    for (int i = 0; i < v; ++i)
    {
        if (visited[i] == false && distance[i] < minimum)
        {
            vertex = i;
            minimum = distance[i];
        }
    }
    return vertex;
}

void primMST(int cost_matrix[][5], int v)
{
    bool visited[v] = {false};
    int distance[v];

    for (int i = 0; i < v; i++)
    {
        distance[i] = INT_MAX;
    }

    int src = 0;
    distance[src] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        int u = selectMinVertex(distance, visited, v);
        visited[u] = true;

        for (int j = 0; j < v; j++)
        {
            if (cost_matrix[u][j] != 0 && visited[j] == false && cost_matrix[u][j] < distance[j])
            {
                distance[j] = cost_matrix[u][j];
            }
        }
    }

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < v; i++)
    {
        cout << "Edge: " << i << " - " << distance[i] << endl;
    }
}

int main()
{
    int v = 5;
    int cost_matrix[5][5];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << "Enter the cost between " << i << " and " << j << ": ";
            cin >> cost_matrix[i][j];
        }
    }

    primMST(cost_matrix, v);

    return 0;
}
