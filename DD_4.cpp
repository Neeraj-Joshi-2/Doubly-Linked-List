//CLONING THE DOUBLY LINKED LIST

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next,*random;
	Node(int x)
	{
		data = x;
		next = random = NULL;
	}
};

void print(Node *start)
{
	Node *ptr = start;
	while (ptr)
	{
		cout << "Data = " << ptr->data << ", Random = " << ptr->random->data << endl;
		ptr = ptr->next;
	}
}

Node* clone(Node *start)
{
	Node* curr = start, *temp;
	
	while (curr)
	{
		temp = curr->next;

		curr->next = new Node(curr->data);
		curr->next->next = temp;
		curr = temp;
	}

	curr = start;

	while (curr)
	{
		if(curr->next)
			curr->next->random = curr->random->next ;
		curr = curr->next->next ;
	}

	Node* original = start, *copy = start->next;

	temp = copy;

	while (original && copy)
	{
		original->next = original->next->next ;
		copy->next = copy->next ? copy->next->next : copy->next;
		original = original->next;
		copy = copy->next;
	}

	return temp;
}

int main()
{
	Node* start = new Node(1);
	start->next = new Node(2);
	start->next->next = new Node(3);
	start->next->next->next = new Node(4);
	start->next->next->next->next = new Node(5);

	start->random = start->next->next;
	start->next->random = start;
	start->next->next->random = start->next->next->next->next;
	start->next->next->next->random = start->next->next->next->next;
	start->next->next->next->next->random = start->next;

	cout << "Original list : \n";
	print(start);

	cout << "\nCloned list : \n";
	Node *cloned_list = clone(start);
	print(cloned_list);

	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next,*random;
	Node(int x)
	{
		data = x;
		next = random = NULL;
	}
};

void print(Node *start)
{
	Node *ptr = start;
	while (ptr)
	{
		cout << "Data = " << ptr->data << ", Random = " << ptr->random->data << endl;
		ptr = ptr->next;
	}
}

Node* clone(Node *start)
{
	Node* curr = start, *temp;

	// insert additional node after every node of original list
	while (curr)
	{
		temp = curr->next;

		// Inserting node
		curr->next = new Node(curr->data);
		curr->next->next = temp;
		curr = temp;
	}

	curr = start;

	// adjust the random pointers of the
	// newly added nodes
	while (curr)
	{
		if(curr->next)
			curr->next->random = curr->random ? curr->random->next : curr->random;

		// move to the next newly added node by
		// skipping an original node
		curr = curr->next ? curr->next->next : curr->next;
	}

	Node* original = start, *copy = start->next;

	// save the start of copied linked list
	temp = copy;

	// now separate the original list and copied list
	while (original && copy)
	{
		original->next = original->next ? original->next->next : original->next;

		copy->next = copy->next?copy->next->next:copy->next;
		original = original->next;
		copy = copy->next;
	}

	return temp;
}

int main()
{
	Node* start = new Node(1);
	start->next = new Node(2);
	start->next->next = new Node(3);
	start->next->next->next = new Node(4);
	start->next->next->next->next = new Node(5);

	start->random = start->next->next;
	start->next->random = start;
	start->next->next->random = start->next->next->next->next;
	start->next->next->next->random = start->next->next->next->next;
	start->next->next->next->next->random = start->next;

	cout << "Original list : \n";
	print(start);

	cout << "\nCloned list : \n";
	Node *cloned_list = clone(start);
	print(cloned_list);

	return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next, *random;
	Node(int data)
	{
		this->data = data;
		this->next = this->random = NULL;
	}
};


class LinkedList
{
public:
	Node *head;

	LinkedList(Node *head)
	{
		this->head = head;
	}

	void push(int data)
	{
		Node *node = new Node(data);
		node->next = head;
		head = node;
	}

	void print()
	{
		Node *temp = head;
		while (temp != NULL)
		{
			Node *random = temp->random;
			int randomData = (random != NULL) ? random->data : -1;
			cout << "Data = " << temp->data<< ", ";
			cout << "Random Data = " <<randomData << endl;
			temp = temp->next;
		}
		cout << endl;
	}

	LinkedList* clone()
	{
		Node *origCurr = head;
		Node *cloneCurr = NULL;

		unordered_map<Node*, Node*> mymap;


		while (origCurr != NULL)
		{
			cloneCurr = new Node(origCurr->data);
			mymap[origCurr] = cloneCurr;
			origCurr = origCurr->next;
		}	
		origCurr = head;

		while (origCurr != NULL)
		{
			cloneCurr = mymap[origCurr];
			cloneCurr->next = mymap[origCurr->next]; 
			cloneCurr->random = mymap[origCurr->random];
			origCurr = origCurr->next;
		}

		return new LinkedList(mymap[head]);
	}
};

int main()
{
	LinkedList *mylist = new LinkedList(new Node(5));
	mylist->push(4);
	mylist->push(3);
	mylist->push(2);
	mylist->push(1);

	mylist->head->random = mylist->head->next->next;

	mylist->head->next->random = mylist->head->next->next->next;

	mylist->head->next->next->random = mylist->head->next->next->next->next;

	mylist->head->next->next->next->random = mylist->head->next->next->next->next->next;

	mylist->head->next->next->next->next->random = mylist->head->next;

	LinkedList *clone = mylist->clone();

	cout << "Original linked list\n";
	mylist->print();
	cout << "\nCloned linked list\n";
	clone->print();
	cout << "Original linked list\n";
	mylist->print();
}

*/