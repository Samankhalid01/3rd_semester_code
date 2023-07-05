#include <iostream>
using namespace std;

// Linear search
int linearSearch(int key)
{
    int arr[] = {4, 7, 8, 9, 11};
    int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            cout << "The element is found at index " << i << endl;
            return i; // Return the index if the element is found
        }
    }

    cout << "The element is not found in the array" << endl;
    return -1; // Return -1 to indicate that the element is not found
}

// Binary search
int binarySearch(int array[], int key, int size)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (array[mid] == key)
        {
            cout << "The element is found at index " << mid << endl;
            return mid;
        }
        else if (array[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << "The element is not found in the array" << endl;
    return -1;
}

int main()
{
    int key = 8;
    int choice;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        linearSearch(key);
        break;
    case 2:
    {
        int array[] = {4, 7, 8, 9, 11};
        int size = sizeof(array) / sizeof(array[0]);
        binarySearch(array, key, size);
        break;
    }
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    return 0;
}
