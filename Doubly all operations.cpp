

#include <iostream>
using namespace std;
void insert_end();
void dislay();
void delete_start();
void reverse_list();
void print_reverse();

struct stu
{
    int data;
    stu *prev;
    stu *next;
};

stu *head = NULL;

void insert_start()
{

    int x;
    stu *curr = new stu();
    curr->prev = NULL;
    curr->next = NULL;

    std::cout << "Enter the data: ";
    cin >> x;
    curr->data = x;

    if (head == NULL)
    {
        head = curr;
    }
    else
    {
        head->prev = curr;
        curr->next = head;
        head = curr;
        head->prev = NULL;
    }
}
void display()
{
    stu *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << endl;
}
void insert_end()
{
    int x;
    cout << "Enter the data: " << endl;
    cin >> x;
    stu *curr = new stu();
    curr->prev = NULL;
    curr->next = NULL;
    if (head = NULL)
    {
        head = curr;
    }
    else
    {
        stu *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
        }
        temp->next = curr;
        curr->prev = temp;
    }
}
void delete_start()
{
    if (head == NULL)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    stu *temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }
    delete temp;
}

void delete_end()
{
    if (head == NULL)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    stu *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    stu *to_delete = temp->next;
    temp->next = NULL;
    delete to_delete;
}
void reverse_list()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    stu *prev = NULL;
    stu *curr = head;
    stu *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }

    head = prev;
}
void print_reverse()
{
    if (head == NULL)
    {
        std::cout << "List is empty:(" << std::endl;
        return;
    }
    stu *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    while (tail != NULL)
    {
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
    std::cout << std::endl;
}

int main()
{
    insert_start();
    insert_end();
    display();
    return 0;
}
