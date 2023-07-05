#include <iostream>
using namespace std;

int main()
{
    int array[] = {5, 8, 9, 13};
    int size = sizeof(array) / sizeof(int);
    int hashArray[size];
    for (int i = 0; i < size; i++)
    {
        hashArray[i] = -1;
    }

    for (int i = 0; i < size; i++)
    {
        int index = array[i] % size;
        if (hashArray[index] == -1)
        {
            hashArray[index] = array[i];
        }
        else
        {
            int j = index;
            while (hashArray[j] != -1)
            {
                j = (j + 1) % size;
            }
            hashArray[j] = array[i];
        }
    }

    cout << "Hash Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << hashArray[i] << " ";
    }
    cout << endl;

    return 0;
}
