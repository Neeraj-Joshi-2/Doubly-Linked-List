/*
INSERTION 
    AT FIRST
    AFTER A GIVEN NODE
    AT LAST
    BEFORE A GIVEN NODE
*/

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

void insertAfter(Node* prevNode , int new_data)
{
    if(prevNode == NULL)
    {
        cout<<"previous node cannot be NULL" ;
        return ;
    } 
    Node* temp = new Node() ;
    temp->data = new_data ;
    temp->next = prevNode->next ;
    prevNode->next = temp ;
    temp->prev = prevNode ;
    if(temp->next!=NULL) 
    {
        temp->next->prev = temp ;
    }
}

void append(int new_data)
{
    Node* temp = new Node() ;
    Node* last = head ;
    temp->data = new_data;
    temp->next = NULL ;
    if(head==NULL)
    {
        temp->prev = NULL ;
        head = temp ;
        return ;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = temp; 
    temp->prev = last;

    return;
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

void insertBefore(Node* nextNode , int new_data)
{
    if (nextNode == NULL) {
        cout<<"the given next node cannot be NULL" ;
        return;
    }
    Node* before = head ;
    while (before->next != nextNode)
        before = before->next;
    Node* temp = new Node() ;
    temp->data = new_data ;
    temp->next = nextNode ;
    nextNode->prev = temp ;
    before->next = temp ;
    temp->prev = before ;

}

int main()
{
	head = NULL ;

	push(7); 
	push(1); 
	push(3); 
	push(4); 
	push(5); 
    insertBefore(head->next->next->next , 10) ;
    insertAfter(head->next->next->next , 100) ;
    append(200) ;
    append(300) ;
    push(1); 
    insertBefore(head->next->next->next , 10) ;
    push(1); 
    append(300) ;
	
    print(head) ;
	
	return 0;
}
