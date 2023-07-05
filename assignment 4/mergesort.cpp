#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            swap(arr[i], arr[minIndex]);
    }
}

void mergeArrays(int leftArray[], int rightArray[], int mergedArray[], int leftSize, int rightSize)
{
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            mergedArray[k] = leftArray[i];
            i++;
        }
        else
        {
            mergedArray[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        mergedArray[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        mergedArray[k] = rightArray[j];
        j++;
        k++;
    }
}

int main()
{
    int array[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(array) / sizeof(int);
    int mid = size / 2;
    int leftSize = mid;
    int rightSize = size - mid;

    int *leftArray = new int[leftSize];
    int *rightArray = new int[rightSize];

    for (int i = 0; i < mid; i++)
    {
        leftArray[i] = array[i];
    }

    for (int i = mid; i < size; i++)
    {
        rightArray[i - mid] = array[i];
    }

    selectionSort(leftArray, leftSize);
    selectionSort(rightArray, rightSize);

    int *mergedArray = new int[size];

    mergeArrays(leftArray, rightArray, mergedArray, leftSize, rightSize);

    cout << "Merged and sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    delete[] leftArray;
    delete[] rightArray;
    delete[] mergedArray;

    return 0;
}
