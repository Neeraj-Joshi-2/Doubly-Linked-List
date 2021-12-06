//REVERSING 

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data ;
    Node* next ;
    Node* prev ;
};

Node* head ;

void push(int new_data) 
{
    Node* temp = new Node() ;
    temp->data = new_data ;
    temp->next = head ;
    temp->prev = NULL ;
    if(head != NULL)
    {
        head->prev = temp ;
    }
    head = temp ;
}

void reverse()
{
    Node* current = head , *temp = NULL ;

    while(current!=NULL)
    {
        temp = current->prev ;
        current->prev = current->next ;
        current->next = temp ;
        current = current->prev ;
    }

    if(temp != NULL)
    {
        head = temp->prev ;
    }
}

void print(Node* temp)
{
    Node* last;
    cout<<"\nTraversal in forward direction \n";
    while (temp != NULL)
    {
        cout<<" "<<temp->data<<" ";
        last = temp;
        temp = temp->next;
    }
    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout<<" "<<last->data<<" ";
        last = last->prev;
    }
}


int main()
{
	head = NULL ;

	push(7); 
	push(1); 
	push(3); 
	push(4); 
	push(5); 
	
    print(head) ;

	
	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
struct LinkedList
{
	struct Node
	{
		int data;
		Node *next, *prev;
		Node(int d)
		{
			data = d;
			next = prev = NULL;
		}
	};
	Node *head = NULL;


	void reverse()
	{
		stack<int> st;
		Node *temp = head;
		while (temp != NULL)
		{
			st.push(temp->data);
			temp = temp->next;
		}

		temp = head;
		while (temp != NULL)
		{
			temp->data = st.top();
			st.pop();
			temp = temp->next;
		}
	}

	void Push(int new_data)
	{
		Node *new_node = new Node(new_data);
		new_node->prev = NULL;
		new_node->next = head;
		if (head != NULL)
		{
			head->prev = new_node;
		}
		head = new_node;
	}

	void printList(Node *node)
	{
		while (node)
		{
			cout << node->data << " ";
			node = node->next;
		}
	}
};

int main()
{
	LinkedList list;

	list.Push(2);
	list.Push(4);
	list.Push(8);
	list.Push(10);
	cout << "Original linked list " << endl;
	list.printList(list.head);
	list.reverse();
	cout << endl;
	cout << "The reversed Linked List is " << endl;
	list.printList(list.head);
}


*/
