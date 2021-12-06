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

void pairSum(struct Node *head, int x)
{
    struct Node *first = head;
    struct Node *second = head;
    while (second->next != NULL)
        second = second->next;
 
    
    bool found = false;
 
    while (first != second && second->next != first)
    {
        if ((first->data + second->data) == x)
        {
            found = true;
            cout << "(" << first->data<< ", " << second->data << ")" << endl;
            first = first->next;
            second = second->prev;
        }
        else
        {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }
    
    if (found == false)
        cout << "No pair found";
}
int main()
{
	head = NULL ;

	push(9); 
	push(8); 
	push(6); 
	push(5); 
	push(4); 
	push(2); 
	push(1); 
	 
	
    // print(head) ;

    pairSum(head, 7);

	return 0;
}
