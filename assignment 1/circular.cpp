#include <iostream>
using namespace std;

// Node structure for the circular linked list
struct Node
{
    int data;
    Node *next;
};

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;

    if (*head == nullptr)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;

    if (*head == nullptr)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete the first node from the circular linked list
void deleteFirstNode(Node **head)
{
    if (*head == nullptr)
    {
        return;
    }

    if ((*head)->next == *head)
    {
        delete *head;
        *head = nullptr;
    }
    else
    {
        Node *temp = *head;
        Node *lastNode = *head;
        while (lastNode->next != *head)
        {
            lastNode = lastNode->next;
        }
        *head = (*head)->next;
        lastNode->next = *head;
        delete temp;
    }
}

// Function to delete the last node from the circular linked list
void deleteLastNode(Node **head)
{
    if (*head == nullptr)
    {
        return;
    }

    if ((*head)->next == *head)
    {
        delete *head;
        *head = nullptr;
    }
    else
    {
        Node *temp = *head;
        Node *prevNode = nullptr;
        while (temp->next != *head)
        {
            prevNode = temp;
            temp = temp->next;
        }
        prevNode->next = *head;
        delete temp;
    }
}

// Function to reverse the circular linked list
void reverse(Node **head)
{
    if (*head == nullptr)
    {
        return;
    }

    Node *current = *head;
    Node *prev = nullptr;
    Node *next = nullptr;

    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    (*head)->next = prev;
    *head = prev;
}

// Function to check if the circular linked list is palindrome
bool isPalindrome(Node *head)
{
    if (head == nullptr)
    {
        return true;
    }

    Node *slowPtr = head;
    Node *fastPtr = head;
    Node *prevSlowPtr = head;
    Node *midNode = nullptr;
    bool isPalindrome = true;

    // Find the middle node of the circular linked list
    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
        fastPtr = fastPtr->next->next;
        prevSlowPtr = slowPtr;
        slowPtr = slowPtr->next;
    }

    // Handling the case of odd number of nodes
    if (fastPtr != nullptr)
    {
        midNode = slowPtr;
        slowPtr = slowPtr->next;
    }

    // Reverse the second half of the circular linked list
    Node *secondHalf = slowPtr;
    prevSlowPtr->next = nullptr;
    reverse(&secondHalf);

    // Compare the first half and reversed second half of the circular linked list
    Node *ptr1 = head;
    Node *ptr2 = secondHalf;
    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->data != ptr2->data)
        {
            isPalindrome = false;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Reconstruct the original circular linked list
    reverse(&secondHalf);
    if (midNode != nullptr)
    {
        prevSlowPtr->next = midNode;
        midNode->next = secondHalf;
    }
    else
    {
        prevSlowPtr->next = secondHalf;
    }

    return isPalindrome;
}

// Function to merge two sorted circular linked lists into a single sorted circular linked list
Node *mergeLists(Node *head1, Node *head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }
    if (head2 == nullptr)
    {
        return head1;
    }

    Node *mergedHead = nullptr;
    Node *tail = nullptr;

    if (head1->data <= head2->data)
    {
        mergedHead = head1;
        head1 = head1->next;
    }
    else
    {
        mergedHead = head2;
        head2 = head2->next;
    }

    tail = mergedHead;
    tail->next = mergedHead;

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
        tail->next = mergedHead;
    }

    if (head1 != nullptr)
    {
        tail->next = head1;
    }
    if (head2 != nullptr)
    {
        tail->next = head2;
    }

    return mergedHead;
}

// Function to print the circular linked list
void printList(Node *head)
{
    if (head == nullptr)
    {
        return;
    }

    Node *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    // Insert elements at the beginning of the circular linked list
    insertAtBeginning(&head, 13);
    insertAtBeginning(&head, 9);
    insertAtBeginning(&head, 8);
    insertAtBeginning(&head, 5);

    cout << "Original Circular Linked List: ";
    printList(head);

    // Delete the first and last node from the circular linked list
    deleteFirstNode(&head);
    deleteLastNode(&head);

    cout << "Modified Circular Linked List: ";
    printList(head);

    // Reverse the circular linked list
    reverse(&head);

    cout << "Reversed Circular Linked List: ";
    printList(head);

    // Check if the circular linked list is palindrome
    bool palindrome = isPalindrome(head);
    if (palindrome)
    {
        cout << "The Circular Linked List is a palindrome." << endl;
    }
    else
    {
        cout << "The Circular Linked List is not a palindrome." << endl;
    }

    // Create a seconfid circular linked list for merging
    Node *head2 = nullptr;
    insertAtEnd(&head2, 2);
    insertAtEnd(&head2, 4);
    insertAtEnd(&head2, 7);
    insertAtEnd(&head2, 11);

    cout << "Second Circular Linked List: ";
    printList(head2);

    // Merge the two circular linked lists
    Node *mergedList = mergeLists(head, head2);

    cout << "Merged Circular Linked List: ";
    printList(mergedList);

    return 0;
}
