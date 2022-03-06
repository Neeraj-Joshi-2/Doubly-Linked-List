//DELETION

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

void deleteNode(int key)
{
    Node* temp = head ;
    Node* prevNode ;
    if(temp->data == key)
    {
        head = temp->next ;
        temp->next->prev = NULL ;
        delete temp ;
        return ;
    }
    else
    {
        while(temp != NULL and temp->data != key)
        {
            prevNode = temp ;
            temp = temp->next ;
        }
        if (temp == NULL)
            return;
        prevNode->next = temp->next ;
        if(temp->next == NULL)
        {
            delete temp ;
            return ;
        }
        temp->next->prev = temp->prev ;
        delete temp;
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

    deleteNode(4) ;

    print(head) ;
	
	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
	Node* prev;
};

void deleteNode(Node** head_ref, Node* del)
{
	if (*head_ref == NULL || del == NULL)
		return;

	if (*head_ref == del)
		*head_ref = del->next;

	if (del->next != NULL)
		del->next->prev = del->prev;

	if (del->prev != NULL)
		del->prev->next = del->next;

	free(del);
	return;
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}

void printList(Node* node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

int main()
{

	Node* head = NULL;

	push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

	cout << "Original Linked list ";
    printList(head);
 
    deleteNode(&head, head); //delete first node
    deleteNode(&head, head->next); //delete middle node
    deleteNode(&head, head->next); //delete last node
 
    cout << "\nModified Linked list ";
    printList(head);

	return 0;
}


*/
