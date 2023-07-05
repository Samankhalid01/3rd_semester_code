#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    string countryName;
    double index;
    int rank;
    int year;
    Node *next;
    Node *prev;
    Node *left; // i have added left & right pointers for BST
    Node *right;
};

// Function to create a new BST node
Node *createNode(string countryName, double index, int year)
{
    Node *newNode = new Node;
    newNode->countryName = countryName;
    newNode->index = index;
    newNode->year = year;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into BST
Node *insertNode(Node *root, string countryName, double index, int year)
{
    if (root == nullptr)
    {
        return createNode(countryName, index, year);
    }

    if (index < root->index)
    {
        root->left = insertNode(root->left, countryName, index, year);
    }
    else if (index > root->index)
    {
        root->right = insertNode(root->right, countryName, index, year);
    }

    return root;
}

// function to search by index

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

// Function to search for a country in BST by index
Node *searchByCountry(Node *root, const string &country)
{
    if (root == nullptr || root->countryName == country)
    {
        return root;
    }

    if (country < root->countryName)
    {
        return searchByCountry(root->left, country);
    }
    else
    {
        return searchByCountry(root->right, country);
    }
}

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

// Function to delete a node from BST
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

struct Node *head = NULL;
struct Node *tail = NULL;

// adding nodes
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
    // non empty
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
} // adding node function ends here

// printing info about all movies
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
// printing movies info only from a specific country
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

// printing movies info with duration greater than d minutes
void printIndexGreater(int d)
{
    Node *ptr = head;
    cout << "Country Name ,year , Index , Rank" << endl;
    if (head != NULL)
    {
        while (ptr)
        {
            if (ptr->index > d)
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
} // printing movie greater than duration function ends here

// delete nodes having movie less than duration d
void deleteLess(int d)
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

int main()
{
    // reading data from file
    ifstream fin;
    fin.open("World Happiness Index by Reports 2013-2023.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;
    while (!fin.eof())
    {
        // reading data and adding to vector
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            lineData.push_back(word);
        }
        // type casting year from string to int
        stringstream s2(lineData[1]);
        int year;
        s2 >> year;

        stringstream s3(lineData[2]);
        int index;
        s3 >> index;

        stringstream s4(lineData[3]);
        int rank;
        s4 >> rank;
        // adding data to linked list
        if (lines != 0)
        {
            addNode(lineData[0], year, index, rank);
        }
        // clearing vector
        lineData.clear();
        lines++;
    }
    Node *root = insertNode(nullptr, head->countryName, head->index, head->year);
    string country;
    cout << "Enter the name of the country to search: ";
    cin >> country;

    Node *result = searchByCountry(root, country);

    if (result != nullptr)
    {
        cout << "Country found: " << result->countryName << endl;
        // Handle the found country as needed
    }
    else
    {
        cout << "Country not found." << endl;
        // Handle the case when the country is not found
    }

    double index;

    cout << "Enter the index to search: ";
    cin >> index;

    Node *resultIndex = searchByIndex(root, index);

    if (resultIndex != nullptr)
    {
        cout << "Country found: " << resultIndex->countryName << ", Index: " << resultIndex->index << endl;
        // Handle the found country as needed
    }
    else
    {
        cout << "Country not found." << endl;
        // Handle the case when the country is not found
    }

    double minIndex, maxIndex;

    cout << "Enter the minimum index for range query: ";
    cin >> minIndex;

    cout << "Enter the maximum index for range query: ";
    cin >> maxIndex;

    RangeQueries(root, minIndex, maxIndex);

    return 0;
}

// switch to ask user what to do
int choice = 0;
do
{
    cout << "\n 1.Print information about all countries" << endl;
    cout << "2.Print information about country from an year" << endl;
    cout << "3.Print information about country having index more than specific value " << endl;
    cout << "4.Delete countries having index less than a specific value" << endl;
    cout << "Select an option and 0 to exit:";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        print();
        break;
    }
    case 2:
    {
        print(country, year);
        break;
    }
    case 3:
    {
        int index;
        cout << "Enter index:";
        cin >> index;
        printIndexGreater(index);
        break;
    }
    case 4:
    {
        double value;
        cout << "Enter the value: ";
        cin >> value;
        deleteLess(value);
        break;
    }
    default:
    {
        cout << "Invalid choice!" << endl;
    }
    }
} while (choice != 0);
return 0;
}
;
