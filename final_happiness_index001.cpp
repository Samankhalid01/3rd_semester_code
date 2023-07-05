#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <climits>
#include <queue>

using namespace std;
struct CountryData
{
    string countryName;
    int year;
    double index;
    int rank;
};

struct Node
{
    string countryName;
    double index;
    int rank;
    int year;
    Node *next;
    Node *prev;
    Node *left;  // Added left pointer for BST
    Node *right; // Added right pointer for BST
    int height;  // Added height for AVL tree
};
int selectMinVertex(int distance[], bool visited[], int v)
{
    int minimum = INT_MAX;
    int vertex = -1;
    for (int i = 0; i < v; ++i)
    {
        if (visited[i] == false && distance[i] < minimum)
        {
            vertex = i;
            minimum = distance[i];
        }
    }
    return vertex;
}

void dijkstra(int cost_matrix[][5], int v, int src)
{
    bool visited[v] = {false};
    int distance[v];

    for (int i = 0; i < v; i++)
    {
        distance[i] = INT_MAX;
    }

    distance[src] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        int u = selectMinVertex(distance, visited, v);
        if (u == -1)
            break;
        visited[u] = true;

        for (int j = 0; j < v; j++)
        {
            if (cost_matrix[u][j] != 0 && visited[j] == false && distance[u] != INT_MAX &&
                distance[u] + cost_matrix[u][j] < distance[j])
            {
                distance[j] = distance[u] + cost_matrix[u][j];
            }
        }
    }

    cout << "Minimum distances from source vertex " << src << ":" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << "Distance to vertex " << i << ": " << distance[i] << endl;
    }
}

// Function to create a new BST node
Node *createNode(string countryName, double index, int year)
{
    Node *newNode = new Node;
    newNode->countryName = countryName;
    newNode->index = index;
    newNode->year = year;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1; // Initialize height as 1 for a new node
    return newNode;
}

int getHeight(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return root->height;
}

int getBalanceFactor(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return leftHeight - rightHeight;
}

Node *leftRotate(Node *root)
{
    Node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    // Update heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

Node *rightRotate(Node *root)
{
    Node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    // Update heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

// Function to insert a node into BST
Node *insertBSTNode(Node *root, string countryName, double index, int year)
{
    if (root == nullptr)
    {
        return createNode(countryName, index, year);
    }

    if (index < root->index)
    {
        root->left = insertBSTNode(root->left, countryName, index, year);
    }
    else if (index > root->index)
    {
        root->right = insertBSTNode(root->right, countryName, index, year);
    }

    return root;
}

// Function to search by index in BST
Node *searchByIndexBST(Node *root, double index)
{
    if (root == nullptr || root->index == index)
    {
        return root;
    }

    if (index < root->index)
    {
        return searchByIndexBST(root->left, index);
    }
    else
    {
        return searchByIndexBST(root->right, index);
    }
}
void BFS(Node *root)
{
    if (root == nullptr)
        return;

    // Create a queue for BFS
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        // Process the current node
        cout << current->index << " ";

        // Enqueue the left child
        if (current->left != nullptr)
            q.push(current->left);

        // Enqueue the right child
        if (current->right != nullptr)
            q.push(current->right);
    }
}

class heap
{
public:
    double arr[1000];
    int size = 0;

    void insert(int val)
    {

        int index = size;
        arr[index] = val;

        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
        size = size + 1;
    }
};

void printIndexGreater(int d) // using heap
{
    Node *head = nullptr;
    Node *ptr = head;
    cout << "Indexes greater than " << d << " are : " << endl;
    heap *h = new heap;
    while (ptr != NULL)
    {
        h->insert(ptr->index);
        ptr = ptr->next;
    }
    int i = 0;
    while (h->arr[i] > d)
    {

        cout << h->arr[i] << endl;
        i++;
    }
}
// using bst
void RangeQueries(Node *root, double minIndex, double maxIndex)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->index < minIndex)
    {
        RangeQueries(root->right, minIndex, maxIndex);
    }
    else if (root->index > maxIndex)
    {
        RangeQueries(root->left, minIndex, maxIndex);
    }
    else
    {
        RangeQueries(root->left, minIndex, maxIndex);
        cout << "Country: " << root->countryName << ", Index: " << root->index << endl;
        RangeQueries(root->right, minIndex, maxIndex);
    }
}

// Function to delete a node only from BST
Node *deleteNode(Node *root, double index)
{
    if (root == nullptr)
    {
        return root;
    }

    if (index < root->index)
    {
        root->left = deleteNode(root->left, index);
    }
    else if (index > root->index)
    {
        root->right = deleteNode(root->right, index);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *minValueNode = root->right;
        while (minValueNode->left != nullptr)
        {
            minValueNode = minValueNode->left;
        }

        root->countryName = minValueNode->countryName;
        root->index = minValueNode->index;
        root->right = deleteNode(root->right, minValueNode->index);
    }

    return root;
}

// Function to search by index BST OR AVL , JUST PASS ROOT OR AVLROOT HERE
Node *searchByIndex(Node *root, double index)
{
    if (root == nullptr || root->index == index)
    {
        return root;
    }

    if (index < root->index)
    {
        return searchByIndex(root->left, index);
    }
    else
    {
        return searchByIndex(root->right, index);
    }
}

// Function to insert a node into AVL tree
Node *insertAVLNode(Node *avlroot, string countryName, double index, int year)
{
    if (avlroot == nullptr)
    {
        return createNode(countryName, index, year);
    }

    if (index < avlroot->index)
    {
        avlroot->left = insertAVLNode(avlroot->left, countryName, index, year);
    }
    else if (index > avlroot->index)
    {
        avlroot->right = insertAVLNode(avlroot->right, countryName, index, year);
    }
    else
    {
        // Duplicate indexes are not allowed, so return the avlroot
        return avlroot;
    }

    // Update the height of the current node
    avlroot->height = 1 + max(getHeight(avlroot->left), getHeight(avlroot->right));

    // Calculate the balance factor
    int balanceFactor = getBalanceFactor(avlroot);

    // Left case
    if (balanceFactor > 1 && index < avlroot->left->index)
    {
        return rightRotate(avlroot);
    }

    // Right case
    if (balanceFactor < -1 && index > avlroot->right->index)
    {
        return leftRotate(avlroot);
    }

    // Left-Right case
    if (balanceFactor > 1 && index > avlroot->left->index)
    {
        avlroot->left = leftRotate(avlroot->left);
        return rightRotate(avlroot);
    }

    // Right-Left case
    if (balanceFactor < -1 && index < avlroot->right->index)
    {
        avlroot->right = rightRotate(avlroot->right);
        return leftRotate(avlroot);
    }

    return avlroot;
}

// Function to print indexes greater than a given value in BST
void printIndexGreaterBST(Node *root, double value)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->index > value)
    {
        cout << root->index << endl;
    }

    printIndexGreaterBST(root->left, value);
    printIndexGreaterBST(root->right, value);
}

// Function to print indexes greater than a given value in AVL tree
void printIndexGreaterAVL(Node *root, double value)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->index > value)
    {
        cout << root->index << endl;
    }

    printIndexGreaterAVL(root->left, value);
    printIndexGreaterAVL(root->right, value);
}

struct Node *head = NULL;
struct Node *tail = NULL;

// adding nodes in linked list
void addNode(string countryName, int year, double index, int rank)
{
    // adding data to new node
    Node *new_node = new Node;
    new_node->countryName = countryName;
    new_node->year = year;
    new_node->index = index;
    new_node->rank = rank;
    new_node->next = NULL;
    // empty list
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        new_node->next = NULL;
        return;
    }
    // non-empty
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
} // adding node function ends here

// printing info about all movies from linked list
void print()
{
    Node *ptr = head;
    cout << "Country Name ,year , Index , Rank " << endl;
    if (head != NULL)
    {
        while (ptr)
        {
            cout << ptr->countryName << " , " << ptr->year << " , " << ptr->index << " , " << ptr->rank << endl;
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
} // printing function ends here

// printing movies info only from a specific country through linked list
void print(string countryName, int year)
{
    Node *ptr = head;
    cout << "Country Name ,year , Index , Rank" << endl;
    if (head != NULL)
    {
        while (ptr)
        {
            if (ptr->countryName == countryName && ptr->year == year)
            {
                cout << ptr->countryName << " , " << ptr->year << " , " << ptr->index << " , " << ptr->rank << endl;
            }
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
} // printing movie of a country function ends here

// delete nodes having an index less than d from linked list
void deleteLess(double d)
{
    Node *ptr = head;
    while (ptr)
    {
        if (ptr->index < d)
        {
            // deleting
            // one node and head or tail
            if ((ptr == head || ptr == tail) && head == tail)
            {
                head = NULL;
                tail = NULL;
            }
            // multiple nodes and head
            else if (ptr == head)
            {
                head = head->next;
                head->prev = NULL;
            }
            // multiple nodes and tail
            else if (ptr == tail)
            {
                tail = tail->prev;
                tail->next = NULL;
            }
            // neither head nor tail
            else
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
        }
        ptr = ptr->next;
    }
}
Node *binarySearch(Node *left, Node *right, string countryName, int year)
{
    while (left != NULL && right != NULL && left != right && right->next != left)
    {
        Node *mid = left;
        Node *temp = left;
        while (temp != right)
        {
            mid = temp;
            temp = temp->next;
        }

        if (mid != NULL && mid->countryName == countryName && mid->year == year)
        {
            return mid;
        }
        else if (mid->year < year || (mid->year == year && mid->countryName < countryName))
        {
            left = mid->next;
        }
        else
        {
            right = mid->prev; // Corrected line: change 'right' to 'mid->prev'
        }
    }

    if (left != NULL && left->countryName == countryName && left->year == year)
    {
        return left;
    }

    // Check if the last node is the desired country
    if (right != NULL && right->countryName == countryName && right->year == year)
    {
        return right;
    }

    return NULL;
}
int hashFunction(double index, int tableSize)
{
    return static_cast<int>(index) % tableSize;
}
void insertionSort()
{
    if (head == NULL || head->next == NULL)
        return;

    Node *current = head->next;
    while (current != NULL)
    {
        Node *temp = current;
        while (temp->prev != NULL && temp->prev->countryName > temp->countryName)
        {
            // Swap nodes
            Node *prevNode = temp->prev;
            Node *nextNode = temp->next;

            if (prevNode != NULL)
                prevNode->next = nextNode;
            if (nextNode != NULL)
                nextNode->prev = prevNode;

            temp->prev = prevNode->prev;
            temp->next = prevNode;

            if (prevNode == head)
                head = temp;
            else
                prevNode->prev->next = temp;

            prevNode->prev = temp;

            temp = temp->prev;
        }

        current = current->next;
    }
}
int main()
{
    Node *root = nullptr;
    Node *avlroot = nullptr;
    Node *head = nullptr;
    vector<CountryData> countryData;

    // Reading data from file
    ifstream fin;
    fin.open("World Happiness Index by Reports 2013-2023.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;
    while (getline(fin, line))
    {
        stringstream s(line);
        while (getline(s, word, ','))
        {
            lineData.push_back(word);
        }
        if (lines != 0)
        {
            // Extracting data from the line
            string countryName = lineData[0];
            int year = stoi(lineData[1]);
            double index = stod(lineData[2]);
            int rank = stoi(lineData[3]);

            // Adding data to the BST and AVL tree
            root = insertBSTNode(root, countryName, index, year);
            avlroot = insertAVLNode(avlroot, countryName, index, year);

            // Adding data to the vector of structs
            CountryData data;
            data.countryName = countryName;
            data.year = year;
            data.index = index;
            data.rank = rank;
            countryData.push_back(data);
        }
        lineData.clear();
        lines++;
    }
    int v = 5;
    int cost_matrix[5][5] = {
        {1, 3, 2, 4, 5},
        {3, 1, 6, 7, 8},
        {2, 6, 1, 9, 10},
        {4, 7, 9, 1, 11},
        {5, 8, 10, 11, 1}};

    fin.close();

    int choice;
    cout << "Enter your choice:\n";
    cout << "1. Perform Dijkstra's algorithm\n";
    cout << "2. Search for an index\n";
    cout << "3. Perform range queries\n";
    cout << "4. Perform BFS traversal\n";
    cout << "5. Search by index using hash table\n";
    cout << "6. Binary search by country name and year\n";
    cout << "7. Sort countries by name\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int d;
        cout << "Enter the value for D: ";
        cin >> d;
        int src = 0;
        dijkstra(cost_matrix, d, src);
        break;
    }
    case 2:
    {
        double index;
        cout << "Enter the index to search: ";
        cin >> index;
        Node *resultIndex = searchByIndex(root, index);
        if (resultIndex != nullptr)
        {
            cout << "Index found: " << resultIndex->index << endl;
            // Handle the found index as needed
        }
        else
        {
            cout << "Index not found." << endl;
            // Handle the case when the index is not found
        }
        break;
    }
    case 3:
    {
        double minIndex, maxIndex;
        cout << "Enter the minimum index: ";
        cin >> minIndex;
        cout << "Enter the maximum index: ";
        cin >> maxIndex;
        RangeQueries(root, minIndex, maxIndex);
        break;
    }
    case 4:
    {
        cout << "BFS traversal: ";
        BFS(root);
        cout << endl;
        break;
    }
    case 5:
    {
        double index;
        cout << "Enter index to search: ";
        cin >> index;
        int tableSize = 100; // Adjust the table size as per your requirement
        int hashIndex = hashFunction(index, tableSize);
        Node *ptr = head;
        bool found = false;
        while (ptr)
        {
            if (hashFunction(ptr->index, tableSize) == hashIndex && ptr->index == index)
            {
                cout << "Country Name: " << ptr->countryName << endl;
                cout << "Year: " << ptr->year << endl;
                cout << "Index: " << ptr->index << endl;
                cout << "Rank: " << ptr->rank << endl;
                found = true;
            }
            ptr = ptr->next;
        }
        if (!found)
        {
            cout << "Country not found with the given index." << endl;
        }
        break;
    }
    case 6:
    {
        string countryName;
        int year;
        cout << "Enter country name: ";
        cin >> countryName;
        cout << "Enter year: ";
        cin >> year;
        Node *result = binarySearch(head, tail, countryName, year);
        if (result != NULL)
        {
            cout << "Country Name: " << result->countryName << endl;
            cout << "Year: " << result->year << endl;
            cout << "Index: " << result->index << endl;
            cout << "Rank: " << result->rank << endl;
        }
        else
        {
            cout << "Country not found with the given name and year." << endl;
        }
        break;
    }
    case 7:
    {
        insertionSort();
        cout << "Countries sorted by name." << endl;
        break;
    }
    default:
    {
        cout << "Invalid choice." << endl;
        break;
    }
    }

    return 0;
}
