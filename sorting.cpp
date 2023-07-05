#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[smallest])
            {
                smallest = j;
            }
        }
        swap(array[i], array[smallest]);
    }
}

void bubbleSort(int array[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && temp < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

int main()
{
    int array[] = {58, 12, 85, 89, 6, 8};
    int size = sizeof(array) / sizeof(int);

    cout << "Select a sorting algorithm: " << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Insertion Sort" << endl;

    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        selectionSort(array, size);
        cout << "Selection Sort: ";
        break;
    case 2:
        bubbleSort(array, size);
        cout << "Bubble Sort: ";
        break;
    case 3:
        insertionSort(array, size);
        cout << "Insertion Sort: ";
        break;
    default:
        cout << "Invalid choice. Sorting using Selection Sort by default." << endl;
        selectionSort(array, size);
        cout << "Selection Sort: ";
        break;
    }

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
