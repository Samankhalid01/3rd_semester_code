#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int height(node *node)
{
    if (node == NULL)
    {
        cout << "node is null" << endl;
        return -1;
    }
    else
    {
        int leftheight = height(node->left);
        int rightheight = height(node->right);
        if (leftheight > rightheight)
            return leftheight + 1;

        else
            return rightheight + 1;
    }
}
int balanceFactor(node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    int balanceFactor = leftHeight - rightHeight;

    return balanceFactor;
}
void rotation(node *node, int data)
{

    int bf = balanceFactor(node);
    if (bf >= -1 && bf <= 1)
    {
        cout << "tree is balanced" << endl;
        return;
    }
    else if (bf > 1 && data < node->left->data)
    {
        node->left->right = node;
        node->left = NULL;
    }
    else if (bf < -1 && data > node->right->data)
    {
        node->right->left = node;
        node->right = NULL;
    }

    else if (bf > 1 && data > node->left->data)
    {
        // Left-Right Rotation
        node *leftChild = node->left;
        node *newRoot = leftChild->right;

        leftChild->right = newRoot->left;
        newRoot->left = leftChild;
        node->left = newRoot->right;
        newRoot->right = node;
    }

    else if (bf < -1 && data < node->right->data)
    {
    }
}
