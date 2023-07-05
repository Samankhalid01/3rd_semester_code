#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear, Q[5];

public:
    Queue() : rear{-1}, front{-1} {}

    void insertQueue(int n)
    {
        if (rear >= 4)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            rear = rear + 1;
            Q[rear] = n;
        }
        if (front == -1)
        {
            front = 0;
        }
    }

    void removeQueue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "item deleted & that item is: " << Q[front] << endl;
            front++;
        }
    }

    void Isfull()
    {
        if (rear >= 4)
        {
            cout << "Queue is Full." << endl;
        }
        else
        {
            cout << "Queue is not full yet." << endl;
        }
    }

    void IsEmpty()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "Queue is not empty." << endl;
        }
    }

    int Peek()
    {
        if (front == -1)
        {
            cout << "Cannot peek because the queue is empty." << endl;
        }
        else
        {
            cout << "The peek of the Queue is " << Q[front] << endl;
        }
        return Q[front];
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
};

void menu()
{
    Queue obj1;
    char choice;

    do
    {
        int x;
        cout << "Enter 1 to Enqueue.\n"
             << "Enter 2 to Dequeue.\n"
             << "Enter 3 to check if the queue is full.\n"
             << "Enter 4 to check if the queue is empty.\n"
             << "Enter 5 to peek the front value from the queue.\n"
             << "Enter 6 to display the queue. \n";
        cin >> x;

        switch (x)
        {
        case 1:
        {
            int num;
            for (int i = 0; i < 5; i++)
            {
                cout << "Enter " << i + 1 << " value to insert in Queue" << endl;
                cin >> num;
                obj1.insertQueue(num);
            }
            break;
        }
        case 2:
            obj1.removeQueue();
            break;
        case 3:
            obj1.Isfull();
            break;
        case 4:
            obj1.IsEmpty();
            break;
        case 5:
            obj1.Peek();
            break;
        case 6:
            obj1.display();
            break;
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }

        cout << "Do you want to continue (Y/N)? ";
        cin >> choice;
        system("cls"); // to clear the console
    } while (choice == 'Y' || choice == 'y');
}

int main()
{
    menu();
    return 0;
}
