#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Order {
public:
    int id;
    int age;
    Order(int id, int age) {
        this->id = id;
        this->age = age;
    }
};

class ElderFirstQueue {
private:
    queue<Order> elder_queue;
    queue<Order> regular_queue;

public:
    void addOrder(Order order) {
        if (order.age >= 60) {
            elder_queue.push(order);
        }
        else {
            regular_queue.push(order);
        }
    }

    bool isEmpty() {
        return elder_queue.empty() && regular_queue.empty();
    }

    void serveNextOrder() {
        if (!elder_queue.empty()) {
            Order order = elder_queue.front();
            elder_queue.pop();
            cout << "Order " << order.id << " (age " << order.age << ") served and removed from elder queue.\n";
        }
        else if (!regular_queue.empty()) {
            Order order = regular_queue.front();
            regular_queue.pop();
            cout << "Order " << order.id << " (age " << order.age << ") served and removed from regular queue.\n";
        }
        else {
            cout << "No more orders in queue.\n";
        }
    }
};

int main() {
    int max_orders = 0;
    cout << "Enter the maximum number of orders: ";
    cin >> max_orders;

    ElderFirstQueue order_queue;
    vector<Order> orders;
    for (int i = 1; i <= max_orders; i++) {
        int age = 0;
        cout << "Enter age of customer " << i << ": ";
        cin >> age;
        Order order(i, age);
        orders.push_back(order);
        order_queue.addOrder(order);
    }

    while (!order_queue.isEmpty()) {
        order_queue.serveNextOrder();
    }

    return 0;
}
