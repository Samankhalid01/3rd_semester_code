#include <iostream>
#include <climits>
using namespace std;

int getMinDistanceNode(int min_cost_array[], bool visited[], int n)
{
    int minDistance = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < n; ++v)
    {
        if (!visited[v] && min_cost_array[v] < minDistance)
        {
            minDistance = min_cost_array[v];
            minIndex = v;
        }
    }

    return minIndex;
}

int main()
{
    const int n = 3;
    int min_cost_array[n];
    int cost_matrix[n][n];
    int path_matrix[n][n];
    bool visited[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter 0 for no path and 1 for path in matrix " << i << " " << j << ": ";
            cin >> path_matrix[i][j];

            if (path_matrix[i][j] == 1)
            {
                cout << "Enter the cost for the valid path in matrix " << i << " " << j << ": ";
                cin >> cost_matrix[i][j];
            }
            else if (i == 0 && j == 0)
            {
                cost_matrix[i][j] = 0;
            }
            else
            {
                cout << "As no path exists, INT_MAX is being used for cost_matrix[" << i << "][" << j << "]." << endl;
                cost_matrix[i][j] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            min_cost_array[i] = 0;
        else
            min_cost_array[i] = INT_MAX;
    }

    for (int count = 0; count < n - 1; count++)
    {
        int u = getMinDistanceNode(min_cost_array, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && cost_matrix[u][v] && min_cost_array[u] != INT_MAX &&
                min_cost_array[u] + cost_matrix[u][v] < min_cost_array[v])
            {
                min_cost_array[v] = min_cost_array[u] + cost_matrix[u][v];
            }
        }
    }

    cout << "MIN COST IS: ";
    for (int i = 0; i < n; i++)
    {
        cout << min_cost_array[i] << " ";
    }
    cout << endl;
    return 0;
}
