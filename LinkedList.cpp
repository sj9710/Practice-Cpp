//Intersection of 2 Linked List in O(n).
#include<iostream>
#include<iterator>
#include<map>
using namespace std;

struct Node {
	struct Node* prev; //pointer to previous node
	struct Node* next; //pointer to next node
	int value;
};

class LinkedList {
	struct Node* head;
	struct Node* curr;

	public:	
	LinkedList() {
		head = NULL;
	}

	LinkedList(int arr[], int len) {
		head = NULL;
		if(len) {
			this->_populateList(arr, len);
		}
	}

	struct Node* getHead() {
		return head;
	}
	
	void insert(int element) {
		struct Node* node = new struct Node;
		node->value = element;
		node->next = NULL;
		if(head == NULL) {
			head = node;
			curr = head;
			node->prev = head;
		} else {
			curr->next = node;
			node->prev = curr;
			curr = node;
		}
	}


	void print() {
		struct Node* printer = head;
		while(1) {
			printf("%d\n",printer->value);
			if(printer->next != NULL) {
				printer = printer->next;
			} else { break; }
		}
	}
	private:
	void _populateList(int arr[], int len) {
		for(int i=0; i<len; i++) {
			this->insert(arr[i]);
		}
	}	
};

/*void intersectList(LinkedList l1, LinkedList l2) {
	LinkedList l3;
	struct Node* l1Head = l1.getHead();
	struct Node* l2Head = l2.getHead();
	while(l1Head != NULL) {
		while(l2Head != NULL) {
			if(l1Head->value == l2Head->value)
			{
				l3.insert(l1Head->value);
			}
			l2Head = l2Head->next;
		}
		l2Head = l2.getHead();
		l1Head = l1Head->next;
	}		
	l3.print();
}*/
void intersectList(LinkedList l1, LinkedList l2) {
	LinkedList l3;
    int i=0;
	struct Node* l1Head = l1.getHead();
	struct Node* l2Head = l2.getHead();
    map<int , int> ob;
    while(l1Head != NULL)
    {
        ob.insert(pair<int , int>(l1Head->value , i));
        i++;
        l1Head = l1Head->next;
    }
    while(l2Head != NULL)
    {
        int no = l2Head->value;
        if (ob.find(no) == ob.end()) 
            break;
        else
        {
            l3.insert(no);
        }
        l2Head = l2Head->next;
    }
    l3.print();
}


int main() {
    LinkedList ll;
	int arr1[] = {1,2,3,4,5,7,9,12};
	int arr2[] = {1,2};

	LinkedList l1(arr1, 8);
	LinkedList l2(arr2, 2);
    l1.print();
    cout<<"\n";
	l2.print();
    cout<<"\n";

	intersectList(l1, l2);



	return 0;
}
