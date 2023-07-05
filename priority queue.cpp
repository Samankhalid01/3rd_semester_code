
#include <iostream>
using namespace std;

class priorityOrdersQueue
{
public:
    int front, rear;
    int size;
    int *orders;

    priorityOrdersQueue()
    {
        front = -1;
        rear = -1;
        size = 10;
        orders = new int[size];
    }

    priorityOrdersQueue(int x)
    {
        front = -1;
        rear = -1;
        size = x;
        orders = new int[size];
    }

    bool is_empty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool is_full()
    {
        if (front == 0 && rear == size - 1)
        {
            return true;
        }
        return false;
    }
    void enqueue()
    {

        if (is_full())
        {
            cout << "Place full." << endl;
        }
        else
        {
            int age;
            cout << "Enter age:" << endl;
            cin >> age;
            if (is_empty())
            {
                front = rear = 0;
                orders[rear] = age;
            }
            else
            {
                int i = front;
                while (age < orders[i] && !(i > rear))
                {
                    i++;
                }
                if (i > rear)
                {
                    orders[i] = age;
                }
                else
                {
                    for (int j = rear; j >= i; j--)
                    {
                        orders[j + 1] = orders[j];
                    }
                    orders[i] = age;
                }
                rear += 1;
            }
        }
    }

    void dequeue()
    {
        if (is_empty())
        {
            cout << "No order exist." << endl;
        }
        else
        {
            cout << "Order " << orders[front] << " served." << endl;
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                for (int i = front; i <= rear; i++)
                {
                    orders[i] = orders[i + 1];
                }

                rear -= 1;
            }
        }
    }

    void display()
    {
        if (is_empty())
        {
            cout << "No order exist." << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << "Order " << i + 1 << " : " << orders[i] << endl;
            }
        }
        cout << endl;
    }
};

int main()
{
    int total;
    cout << "Enter maximum no. of orders:" << endl;
    cin >> total;
    priorityOrdersQueue q(total);
    int opt = 0;
    while (opt != 4)
    {

        cout << "Enter one option:" << endl;
        cout << "1. Place order\n2. Serve order\n3. Display\n4. Exit" << endl;
        cin >> opt;
        if (opt == 1)
        {
            q.enqueue();
        }
        else if (opt == 2)
        {
            q.dequeue();
        }
        else if (opt == 3)
        {
            q.display();
        }
        else if (opt == 4)
        {
            break;
        }
        else
        {
            cout << "You entered something wrong...TRY AGAIN!" << endl;
        }
        cout << endl;
    }
    cout << "BYE...";
    return 0;
}