

#include <iostream>
using namespace std;

struct Node
{
    int ID;
    int marks;
    Node *next = NULL;
};
Node *first = NULL;
Node *last = NULL;

void delete_Secific(){
    int val;
    cin >> val;
        cout << "enter the value you want to delete." << endl;
    Node *curr = new Node;
    Node *p = new Node;
    while (curr != NULL)
    {
       
        if (curr->next->ID == val)
        {
            curr->next = curr->next->next;
            curr->next = p;
            delete
        }
        else
            cout << "no such value exists" << endl;
    }
    curr = curr->next;
}


int main()
{
    int x;
    cout << "Enter 1 to delete at specific.\n";
    cin >> x;
    switch (x)
    {
    case 1:
        delete ();
        break;
        return 0;
    }
}