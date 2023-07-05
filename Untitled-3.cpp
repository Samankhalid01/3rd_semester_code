#include <iostream>
#include <string>

using namespace std;

struct Node {
    char ch;
    Node *next = NULL;
};

Node *first = NULL;
Node *last = NULL;

bool isPalindrome() {
    Node *p = first;
    Node *k = last;
    Node *prev = NULL;

    while (p != NULL) {
        Node *next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }

    first = prev;
    p = first;

    while (p != NULL) {
        if (p->ch != k->ch) {
            return false;
        }
        p = p->next;
        k = k->next;
    }

    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        Node *n = new Node;
        n->ch = s[i];

        if (first == NULL) {
            first = n;
            last = n;
        } else {
            last->next = n;
            last = n;
        }
    }

    if (isPalindrome()) {
        cout << "The string is a palindrome" << endl;
    } else {
        cout << "The string is not a palindrome" << endl;
    }

    return 0;
}
