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

int main()
{
    int v = 5;
    bool visited[v] = {false};
    int distance[v];
    int cost_matrix[5][5];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << "Enter the cost between " << i << " and " << j << ": ";
            cin >> cost_matrix[i][j];
        }
    }

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
            if (cost_matrix[u][j] != 0 && visited[j] == false && distance[u] != INT_MAX &&
                distance[u] + cost_matrix[u][j] < distance[j])
            {
                distance[j] = distance[u] + cost_matrix[u][j];
            }
        }
    }

    cout << "Minimum distances from source vertex " << src << ":" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << "Distance to vertex " << i << ": " << distance[i] << endl;
    }

    return 0;
}
