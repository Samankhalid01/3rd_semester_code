#include <iostream>
using namespace std;

struct node {
    int data;
    int height;
    struct node* left;
    struct node* right;
};

int height(node* node) {
    if (node == NULL) {
        return -1;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

int balanceFactor(node* node) {
    if (node == NULL) {
        return 0;
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    int balanceFactor = leftHeight - rightHeight;

    return balanceFactor;
}
void inOrderTraversal(node* n) {
    if (n == NULl){
        return;
    }
    
    inOrderTraversal(n->left);
    cout << n->data << " ";
    inOrderTraversal(n->right);
}
void PreOrderTraversal(node*n){
	   if (n == NULL) {
        return;
    }
     cout << n->data << " ";
    PreOrderTraversal(n->left);
    PreOrderTraversal(n->right);
}
void PostOrderTraversal(node*n){
	   if (n == NULL) {
        return;
    }
     
    PostOrderTraversal(n->left);
    PostOrderTraversal(n->right);
    cout << n->data << " ";
}

void insert(node* n,int data){
if(n==NULL){
	node* n1=new node;
	n1->left=NULL;
	n1->right=NULL;
	n1->data=data;
	n1->height=1;

}
if (data<n->data){
	n->left=insert(n->left , data);
}
if (data>node->data){
    n->right=insert(n->right,data);
}
else{
	cout<<"duplicate values are not allowed "<<endl;
	return n;
}
//update height
n->height=(max(height(n->left),height(n->right))+1);

}
void rotation(node* node, int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    int bf = balanceFactor(node);
    if (bf >= -1 && bf <= 1) {
        cout << "Tree is balanced" << endl;
        return;
    } else if (bf > 1 && data < node->left->data) {
        // Left-Left Rotation
        node* rightChild = node->right;
        node*t2=rightChild->left;
        //rotations
        rightChild->left = node;
        node->right=t2;
        //node->right==NULL;
        //udating heights
        rightChild->height=max(height(rightChild->left,rightChild->right)+1);
        node->height=max(height(node->left,node->right))+1;
        //now returning the new root
        return rightChild;
    } else if (bf < -1 && data > node->right->data) {
        // Right-Right Rotation
        node* leftChild = node->left;
        node*t2=leftChild->right;
        //rotations
        leftChild->right = node;
        node->left=t2;
        //node->left==NULL;
        //updating height
        leftChild->height=max(height(leftChild->left,leftChild->right))+1;
        node->height=max(height(node->left,node->right))+1;
        //now returning the new root
        return leftChild;
    } else if (bf > 1 && data > node->left->data) {
        // Left-Right Rotation

    node* leftChild = node->left;
    node* rightOfLeft = leftChild->right;
    node* t2 = rightOfLeft->left;

    // Perform rotations
    leftChild->right = t2;
    rightOfLeft->left = leftChild;
    node->left = rightOfLeft;

    // Update heights
    leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;
    rightOfLeft->height = max(height(rightOfLeft->left), height(rightOfLeft->right)) + 1;
    node->height = max(height(node->left), height(node->right)) + 1;

    return node;
}

    } else if (bf < -1 && data < node->right->data) {
        node* rightChild = node->right;
    node* leftOfRight = rightChild->left;
    node* t2 = leftOfRight->left;

    // Perform rotations
    rightChild->left = t2;
    leftOfRight->left = rightChild;
    node->right = leftOfRight;

    // Update heights
  rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;
    leftOfRight ->height = max(height( leftOfRight->left), height( leftOfRight->right)) + 1;
    node->height = max(height(node->left), height(node->right)) + 1;

    return node;
}
}

int main() {
    node* root = NULL;

    // Insert nodes into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Perform inorder traversal
    inOrderTraversal(n);
    PostOrderTraversal(n);
     PreOrderTraversal(n);
    return 0;

