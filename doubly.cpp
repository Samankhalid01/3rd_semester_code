#include <iostream>
using namespace std;

void insert_start();
void insert_end();
Void delete_start();
void delete_end();
void reverse_list();
void reverse_display();
void display();

struct stu
{
    string name;
    long reg_no;
    float gpa;
    struct stu *next;
    struct stu *prev;
};

stu *head = NULL;
stu *tail = NULL;

void insert_start()
{
    stu *curr = new stu();
    curr->prev = nullptr;
    curr->next = head;
    cout << "Enter the name: \n";
    cin >> curr->name;
    cout << "Enter the reg no.: \n";
    cin >> curr->reg_no;
    cout << "Enter the gpa: \n";
    cin >> curr->gpa;
    if (head == NULL)
    {
        head = curr;
        tail = curr;
        return;
    }
    else
    {
        head->prev = curr;
        head = curr;
    }
    cout << "Element inserted successfully\n";
}

void insert_end()
{
    stu *curr = new stu();
    curr->next = nullptr;
    cout << "Enter the name: \n";
    cin >> curr->name;
    cout << "Enter the reg no.: \n";
    cin >> curr->reg_no;
    cout << "Enter the gpa: \n";
    cin >> curr->gpa;
    if (head == NULL)
    {
        head = curr;
        tail = curr;
        return;
    }
    else
    {
        curr->prev = tail;
        tail->next = curr;
        tail = curr;
    }
    cout << "Element inserted successfully\n";
}
void delete_end()
{
    if (head == nullptr)
    {
        cout << "List is empty.... :( \n";
        return;
    }

    stu *curr = tail;
    tail = tail->prev;
    delete curr;

    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    else
    {
        head = nullptr;
    }

    cout << "The end node of the list has been deleted....... :( \n";
}
void delete_start()
{
    if (head == NULL)
    {
        cout << "No element is present to delete..\n";
        return;
    }
    stu *curr = head;
    head = curr->next;
    delete curr;
    if (head != nullptr)
    {
        head->prev = NULL;
    }
    else
    {
        cout << "......deleted successfully.....\n";
    }
}
void reverse_list()
{
    stu *curr = head;
    stu *temp = NULL;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
    {
        head = temp;
    }
    cout << "List has been reversed successfully." << endl;
}

void reverse_display(stu *current)
{
    if (current = NULL)
    {
        current = current->next;
    }
    else
    {
    }
}
void display()
{
    stu *temp = head;
    while (temp != NULL)
    {
        cout << "Name of student: " << temp->name << ", Reg. no.: " << temp->reg_no << ", GPA: " << temp->gpa << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insert_start();
    insert_end();
    delete_end();
    delete_start();
    reverse_list();
    reverse_display();
    display();
    return 0;
}
