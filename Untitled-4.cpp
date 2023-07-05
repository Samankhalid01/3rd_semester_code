#include <iostream>
using namespace std;

#define MAX_ORDERS 10

class CircularQueue {
private:
    int front, rear;
    int arr[MAX_ORDERS];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_ORDERS == front;
    }

    void enqueue(int order) {
        if (isFull()) {
            cout << "Order queue is full. Try again later.\n";
        }
        else {
            if (isEmpty()) {
                front = rear = 0;
            }
            else {
                rear = (rear + 1) % MAX_ORDERS;
            }
            arr[rear] = order;
            cout << "Order " << order << " added to queue.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Order queue is empty.\n";
        }
        else {
            cout << "Order " << arr[front] << " served and removed from queue.\n";
            if (front == rear) {
                front = rear = -1;
            }
            else {
                front = (front + 1) % MAX_ORDERS;
            }
        }
    }
};

int main() {
    int max_orders = 0;
    cout << "Enter the maximum number of orders: ";
    cin >> max_orders;

    CircularQueue order_queue;
    int order = 1;
    char choice;
    do {
        cout << "Do you want to place an order? (Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            if (order <= max_orders) {
                order_queue.enqueue(order);
                order++;
            }
            else {
                cout << "Maximum number of orders reached.\n";
            }
        }
        else if (choice == 'N' || choice == 'n') {
            if (order_queue.isEmpty()) {
                cout << "No more orders in queue.\n";
            }
            else {
                order_queue.dequeue();
            }
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (order <= max_orders || !order_queue.isEmpty());

    return 0;
}
