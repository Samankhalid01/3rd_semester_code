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
};

struct Node *head = NULL;
struct Node *tail = NULL;

//adding nodes
void addNode(string countryName ,int year ,double index, int rank )
{
    //adding data to new node
    Node *new_node = new Node;
    new_node->countryName = countryName;
    new_node->year=year;
    new_node->index = index;
    new_node->rank = rank;
    new_node->next = NULL;
    //empty list
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
        new_node->next = NULL;
        return;
    }
    //non empty
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
}//adding node function ends here

//printing info about all movies
void print()
{
    Node *ptr = head;
    cout << "Country Name ,year , Index , Rank " << endl;
    if (head!=NULL)
    {
       while (ptr)
       {
           cout<<ptr->countryName<<" , "<<ptr->year<<" , "<<ptr->index<<" , "<<ptr->rank<< endl;
           ptr=ptr->next;
       }
    }
   else
    {
       cout << "List is empty"<<endl;
    }
}//printing function ends here

//printing movies info only from a specific country
void print(string countryName,int year)
{
    Node *ptr = head;
    cout << "Country Name ,year , Index , Rank" << endl;
    if (head!=NULL)
    {
        while (ptr)
        {
            if(ptr->countryName==countryName && ptr->year==year)
            {
                cout<<ptr->countryName<<" , "<<ptr->year<<" , "<<ptr->index<<" , "<<ptr->rank<< endl;
            }
            ptr=ptr->next;
        }
    }
    else
    {
       cout << "List is empty"<<endl;
    }
}//printing movie of a country function ends here

//printing movies info with duration greater than d minutes
void printIndexGreater(int d)
{
    Node *ptr = head;
    cout << "Country Name ,year , Index , Rank" << endl;
    if (head!=NULL)
    {
        while (ptr)
        {
            if(ptr->index>d)
            {
                cout<<ptr->countryName<<" , "<<ptr->year<<" , "<<ptr->index<<" , "<<ptr->rank<< endl;
            }
            ptr=ptr->next;
        }
    }
    else
    {
       cout << "List is empty"<<endl;
    }
}//printing movie greater than duration function ends here

//delete nodes having movie less than duration d
void deleteLess(int d)
{
    Node *ptr = head;
    while (ptr)
    {
        if(ptr->index<d)
        {
            //deleting
            //one node and head or tail
            if((ptr==head||ptr==tail) && head==tail)
            {
                head=NULL;
                tail=NULL;
            }
            //multiple nodes and head
            else if(ptr==head)
            {
                head=head->next;
                head->prev=NULL;
            }
            //multiple nodes and tail
            else if(ptr==tail)
            {
                tail=tail->prev;
                tail->next=NULL;
            }
            //neither head nor tail
            else
            {
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
            }
        }
        ptr=ptr->next;
		}
}
    
    

int main()
{
    //reading data from file
    ifstream fin;
    fin.open("World Happiness Index by Reports 2013-2023.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;
    while(!fin.eof()){
        //reading data and adding to vector
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,',')){
            lineData.push_back(word);
        }
        //type casting year from string to int
        stringstream s2(lineData[1]);
        int year;
        s2>>year;
        
        stringstream s3(lineData[2]);
        int index;
        s3>>index;
        
        stringstream s4(lineData[3]);
        int rank;
        s4>>rank;
        //adding data to linked list
        if(lines!=0)
        {
            addNode(lineData[0],year,index,rank);
        }
        //clearing vector
        lineData.clear();
        lines++;
    }
    
    
    //switch to ask user what to do
    int choice = 0;
    do
    {
        cout<<"\n 1.Print information about all countries"<<endl;
        cout<<"2.Print information about country from an year"<<endl;
        cout<<"3.Print information about country having index more than specific value "<<endl;
        cout<<"4.Delete countries having index less than a specific value"<<endl;
        cout<< "Select an option and 0 to exit:";
        cin>>choice;
        switch(choice)
        {
            case 1 :
            {
                print();
                break;
            }
            case 2 :
            {
                string country;
                int year;
                cout<<"Enter country name :";
                cin>>country;
                cout<<"Enter year:";
                cin>>year;
                print(country,year);
                break;
            }
            case 3 :
            {
                int index;
                cout<<"Enter index:";
                cin>>index;
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
            default :
            {
                cout<<"Invalid choice!"<<endl;
            }
        }
    }
    while(choice!=0);
    return 0;
}
