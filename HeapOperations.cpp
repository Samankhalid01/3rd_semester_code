#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
    	size = size + 1;
        int index=size;
        arr[index] = val;
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                cout << "You have successfully inserted the element at index " << index << endl;
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << "The array element at index " << i << " is: " << arr[i] << endl;
        }
    }
    void deleteFromHeap(){
    	if(size==0){
    		cout<<"heap is empty,nothing to delete"<<endl;
    		return;
		}
		//step1:put last element into first index
		arr[1]=arr[size];
		//step 2:remove the last element
		size--;
		//step 3: taking root node to it's correct position
		int i=1;
		while(i<size){
			int LeftIndex=2*i;
			int RightIndex=2*i+1;
		if(LeftIndex<size&&arr[i]<arr[LeftIndex]){
				swap(arr[i],arr[LeftIndex]);
				i =LeftIndex;
			}
			else if(RightIndex<size&&arr[i]<arr[RightIndex]){
				swap(arr[i],arr[RightIndex]);
				i=RightIndex;
			}
			else {
				cout<<"you have successfully deleted the last element"<<endl;
					return;
			}

		
			}
			
		}
	
};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();
     return 0;
}

