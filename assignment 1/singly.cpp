#include <iostream>
using namespace std;
void menu();
void insert_start();
void insert_end();
void delete_end();
void delete_start();
void reverse();
void reverse_display();
void insert_after_specific();
void insert_before_specific();
void delete_specfic();
void merge_lists();
void swap_list();
void display();

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
         << "Enter 5 to reverse the list.\n"
         << "Enter 6 to insert after specific value. \n"
         << "Enter 7 to insert before specific value. \n"
         << "Enter  8 to delete a specific value from list. \n"
         << "Enter 9 to display list.\n";

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
    case 6:
        reverse_display();
        break;
    case 7:
        insert_after_specific();
        break;
    case 8:
        insert_before_specific();
        break;
    case 9:
        delete_specific();
        break;
    case 10:
        display();
        break;
    case 11:
        merge_lists();
        break;
    case 12:
        swap_list();
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
void insert_after_specific()
{
    if (first == NULL)
    {
        cout << "List is empty..:(\n";
    }
    else
    {
        int value;
        cout << "Enter the ID after which you want to insert node: ";
        cin >> value;
        stu *curr = first;
        while (curr != NULL)
        {
            if (curr->ID == value)
            {
                stu *temp = new stu();
                temp->next = curr->next;
                curr->next = temp;
                return;
            }
            curr = curr->next;
        }

        cout << "ID not found in the list.\n";
    }
}

void insert_before_specific()
{
    if (first == NULL)
    {
        cout << "List is empty :( ...\n";
    }
    else
    {
        int val;
        cout << "Enter the ID before which you want to insert node: ";
        cin >> val;
        stu *curr = first;
        stu *prev = NULL;
        while (curr != NULL && curr->next != NULL)
        {
            if (curr->next->ID == val)
            {
                stu *temp = new stu;
                if (prev != NULL)
                {
                    prev->next = temp;
                }
                else
                {
                    first = temp;
                }
                return;
            }
            curr = curr->next;
        }

        cout << "ID not found in the list" << endl;
    }
}
void delete_specfic()
{
    if (first == NULL)
    {
        cout << "List is empty nothing present to delete. \n";
        return;
    }
    else
    {
        stu *curr = first;
        int val;
        cin >> "Enter the id you want to delete. \n";
        curr->next = val;
        if (curr != val)
        {
            curr = curr->next;
        }
        else
        {
        }
    }
}
void reverse_display()
{
}
void merge_lists()
{
}
void swap_list()
{
}
void display()
{
    if (first == NULL)
    {
        cout << "List is empty :( \n";
    }
    else
    {
        stu *curr = first;
        cout << "the list contents are as follows: \n";
        while (curr != NULL)
        {
            cout << "the ID of student is : " << curr->ID << " the marks of the student are : " << curr->marks << endl;
            curr = curr->next;
        }
        cout << "\n";
        return;
    }
}
