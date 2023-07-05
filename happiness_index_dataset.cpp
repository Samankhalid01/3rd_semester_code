#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
    string countryName;
    double index;
    int rank;
    int year;
    Node *next;
    Node *prev;
};

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

void finding_the_highest_rank_year_of_a_country()
{
    cout << "Enter the country name for which you want the highest rank in 10 years data" << endl;
    string country_name;
    cin >> country_name;
    Node *temp = head;
    queue<Node *> values;

    while (temp != NULL)
    {
        if (temp->countryName == country_name)
        {
            values.push(temp);
        }
        temp = temp->next;
    }

    while (!values.empty())
    {
        Node *front = values.front();
        int min_no = front->rank;
        int year = front->year;

        for (int i = 0; i < 10; i++)
        {
            Node *first_no = values.front();

            if (first_no->rank >= min_no)
            {
                values.pop();
            }
            else if (first_no->rank < min_no)
            {
                min_no = first_no->rank;
                year = first_no->year;
                values.pop();
            }
        }
        cout << country_name << " Highest Happiness rank was : " << min_no << " in year " << year << endl;
    }
}
void finding_average()
{
    queue<Node *> q;
    Node *temp = head;
    while (temp != NULL)
    {
        q.push(temp);
        temp = temp->next;
    }

    while (!q.empty())
    {
        Node *data = q.front();
        double val = 0;
        for (int i = 0; i < 10; i++)
        {
            Node *value = q.front();
            val = value->index + val;
            q.pop();
        }
        double average = val / 10;
        cout << data->countryName << " average happiness index is : " << average << endl;
    }
}
void specific_year_data()
{
    stack<Node *> st;
    int y;
    cout << "Enter the year whose data you want to display: " << endl;
    cin >> y;

    Node *f = head;

    // Push relevant nodes onto the stack
    while (f != NULL)
    {
        if (f->year == y)
        {
            st.push(f);
        }
        f = f->next;
    }

    // Sort the stack in descending order of rank using an additional stack
    stack<Node *> sortedStack;

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();

        while (!sortedStack.empty() && sortedStack.top()->rank < temp->rank)
        {
            st.push(sortedStack.top());
            sortedStack.pop();
        }

        sortedStack.push(temp);
    }

    // Display the sorted data
    while (!sortedStack.empty())
    {
        Node *temp = sortedStack.top();
        sortedStack.pop();

        cout << "Country Name: " << temp->countryName << endl;
        cout << "Happiness Index for the Year: " << temp->index << endl;
        cout << "Rank for the Year: " << temp->rank << endl;
    }
}

void reverse_specific_country_data()
{
    stack<Node *> s;
    string c;
    cout << "Enter the country whose data you want to reverse: ";
    cin >> c;

    // Push nodes with matching country names onto the stack
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->countryName == c)
        {
            s.push(curr);
        }
        curr = curr->next;
    }

    // Display the reversed data
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << "year:" << temp->year << endl;
        cout << "Country Name: " << temp->countryName << endl;
        cout << "Happiness Index for the Year: " << temp->index << endl;
        cout << "Rank for the Year: " << temp->rank << endl;
    }
}

void searchByRank(int targetRank)
{
    Node *ptr = head;
    bool found = false;
    cout << "Country Name ,year , Index , Rank" << endl;
    while (ptr)
    {
        if (ptr->rank == targetRank)
        {
            cout << ptr->countryName << " , " << ptr->year << " , " << ptr->index << " , " << ptr->rank << endl;
            found = true;
        }
        ptr = ptr->next;
    }
    if (!found)
    {
        cout << "No countries found with rank " << targetRank << endl;
    }
}
// Function to compare the index of a specific country between the most recent year and the year before
void compareLastTwoYearsStack(string countryName)
{
    stack<Node *> yearStack;

    Node *ptr = head;
    while (ptr)
    {
        if (ptr->countryName == countryName)
        {
            yearStack.push(ptr);
        }
        ptr = ptr->next;
    }

    if (yearStack.size() >= 2)
    {
        Node *recentYearData = yearStack.top();
        yearStack.pop();
        Node *yearBeforeData = yearStack.top();

        cout << "Comparison of " << countryName << " between the most recent year and the year before:" << endl;
        cout << "Most Recent Year (" << recentYearData->year << ") Index: " << recentYearData->index << endl;
        cout << "Year Before (" << yearBeforeData->year << ") Index: " << yearBeforeData->index << endl;

        if (recentYearData->index > yearBeforeData->index)
        {
            cout << "The index has increased from the year before to the most recent year for " << countryName << "." << endl;
        }
        else if (recentYearData->index < yearBeforeData->index)
        {
            cout << "The index has decreased from the year before to the most recent year for " << countryName << "." << endl;
        }
        else
        {
            cout << "The index remains the same from the year before to the most recent year for " << countryName << "." << endl;
        }
    }
    else
    {
        cout << "Insufficient data to compare the most recent year and the year before for " << countryName << "." << endl;
    }
}

int main()
{
    // reading data from file
    ifstream fin;
    fin.open("World Happiness Index by Reports 2013-2023 with nulls.csv");
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
        double index;
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

    // switch to ask user what to do
    int choice = 0;
    do
    {
        cout << "\n 1.Print information about all countries" << endl;
        cout << "2.Print information about country from an year" << endl;
        cout << "3.Print information about country having index more than specific value " << endl;
        cout << "4.Find the highest rank year of a country" << endl;
        cout << "5.Find the average " << endl;
        cout << "6.display the data of specific year" << endl;
        cout << "7.Reverse the data of specific year" << endl;
        cout << "8.search the data by rank" << endl;
        cout << "9.compare the data of specific country and most recent year & year before" << endl;

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
            string country;
            int year;
            cout << "Enter country name :";
            cin >> country;
            cout << "Enter year:";
            cin >> year;
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
            finding_the_highest_rank_year_of_a_country();
            break;
        }
        case 5:
        {

            finding_average();
            break;
        }
        case 6:
        {

            specific_year_data();
            break;
        }
        case 7:
        {
            reverse_specific_country_data();
            break;
        }
        case 8:
        {
            int rank;
            cout << "Enter rank: ";
            cin >> rank;
            searchByRank(rank);
            break;
        }
        case 9:
        {
            string country;
            cout << "Enter country name: ";
            cin >> country;
            compareLastTwoYearsStack(country);
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