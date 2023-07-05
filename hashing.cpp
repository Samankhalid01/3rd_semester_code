#include <iostream>
using namespace std;

int main()
{
    int array[] = {5, 8, 9, 13};
    int size = sizeof(array) / sizeof(int);
    int hashArray[size];
    for (int i = 0; i < size; i++)
    {
        hashArray[i] = -1;
    }

    for (int i = 0; i < size; i++)
    {
        int index = array[i] % size;
        if (hashArray[index] == -1)
        {
            hashArray[index] = array[i];
        }
        else
        {
            int j = index;
            while (hashArray[j] != -1)
            {
                j = (j + 1) % size;
            }
            hashArray[j] = array[i];
        }
    }

    cout << "Hash Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << hashArray[i] << " ";
    }
    cout << endl;

    return 0;
}
struct Node{
	int data;
	Node *next;
};

struct hash{
	Node node;
	//int data;
	//hash *next;
	hash *first=NULL;
	hash *last=NULL;
};

hash arr[10];
	int array[]={1,12,11,14,2,21,22};
	int size=sizeof(array)/sizeof(int);
	int index;
	for(int i=0; i<size; i++){
		hash *curr=new hash;
		curr->node.data=array[i];
		index=array[i]%size;
		for(int j=0; j<size; j++){
			if(index==j){
				if(arr[j].first==NULL){
					arr[j].first->node=arr[j].last->node=curr->node;
				}
				else{
					arr[j].last->node.next=curr->node;
					arr[j].last->node=curr->node;
				}
			}
		}
	}