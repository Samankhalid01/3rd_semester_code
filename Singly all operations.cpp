#include <iostream>

using namespace std;

void menu();
void insert_start();
void insert_end();
void delete_end();
void delete_start();
void reverse();
void insert_specific();

struct stu
{
    int ID;
    int marks;
    stu *next = NULL;
};

stu *first = NULL;
stu *last = NULL;

int main()
{
    menu();
    return 0;
}

void menu()
{
    int x;
    cout << "Enter 1 to insert at start.\n"
         << "Enter 2 to insert at end.\n"
         << "Enter 3 to delete at end.\n"
         << "Enter 4 to delete from start.\n"
         << "Enter 5 to reverse the list.\n";
    cin >> x;

    switch (x)
    {
    case 1:
        insert_start();
        break;
    case 2:
        insert_end();
        break;
    case 3:
        delete_end();
        break;
    case 4:
        delete_start();
        break;
    case 5:
        reverse();
        break;
    default:
        cout << "Invalid choice.";
        menu();
    }
}

void insert_start()
{
    stu *curr = new stu;
    cout << "Enter the ID of the student: ";
    cin >> curr->ID;
    cout << "Enter the marks of the student: ";
    cin >> curr->marks;

    if (first == NULL)
    {
        first = last = curr;
    }
    else
    {
        curr->next = first;
        first = curr;
    }

    menu();
}

void insert_end()
{
    stu *curr = new stu;
    cout << "Enter the ID of the student: ";
    cin >> curr->ID;
    cout << "Enter the marks of the student: ";
    cin >> curr->marks;

    if (first == NULL)
    {
        first = last = curr;
    }
    else
    {
        last->next = curr;
        last = curr;
    }

    menu();
}

void delete_end()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
    }
    else if (first == last)
    {
        first = last = NULL;
    }
    else
    {
        stu *a = first;
        while (a->next != last)
        {
            a = a->next;
        }

        last = a;
        last->next = NULL;
    }

    menu();
}

void delete_start()
{
    if (first == NULL)
    {
        cout << "There is nothing to delete.\n";
    }
    else if (first == last)
    {
        first = last = NULL;
    }
    else
    {
        first = first->next;
    }

    menu();
}

void reverse()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
    }
    else
    {
        stu *current = first;
        stu *prev = NULL;
        stu *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        last = first;
        first = prev;
    }

    menu();
}
