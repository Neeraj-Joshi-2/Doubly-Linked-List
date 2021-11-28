#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void printList(struct Node* head) ;

struct Node* sortAKSortedDLL(struct Node* head, int k)
{
	if(head == NULL || head->next == NULL)
		return head;

	for(Node *i = head->next; i != NULL; i = i->next) {
		Node *j = i;

        cout<<"i : "<<i->data<<" "<<"j : "<<j->data<<endl ;

		while(j->prev != NULL && j->data < j->prev->data) {

			Node* temp = j->prev->prev;
			Node* temp2 = j->prev;
			Node *temp3 = j->next;

			j->prev->next = temp3;
			j->prev->prev = j;
			j->prev = temp;
			j->next = temp2;
			if(temp != NULL)
				temp->next = j;
			if(temp3 != NULL)
				temp3->prev = temp2;
		}

		if(j->prev == NULL){
            head = j;
        }
		printList(head);
	}
	return head;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

void printList(struct Node* head)
{
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
    cout<<endl ;
}

int main()
{
	struct Node* head = NULL;

	// push(&head, 8);
	// push(&head, 56);
	// push(&head, 12);
    push(&head, 10);
	push(&head, 2);
	push(&head, 6);
	push(&head, 3);
	

	int k = 12;

	cout << "Original Doubly linked list:\n";
	printList(head);

	// sort the biotonic DLL
	head = sortAKSortedDLL(head, k);

	cout << "\nDoubly linked list after sorting:\n";
	printList(head);

	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void printList(struct Node* head) ;

struct Node* sortAKSortedDLL(struct Node* head, int k)
{
    if (head == NULL)
        return head;

    priority_queue <Node*, vector<Node*>, compare> pq;
    struct Node* newHead = NULL, *last;
 

    for (int i = 0; head != NULL && i <= k; i++) {
        pq.push(head);
        head = head->next;
    }
 
    while (!pq.empty()) {

        if (newHead == NULL) {
            newHead = pq.top();
            newHead->prev = NULL;
            last = newHead;
        }
 
        else {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
 
        pq.pop();
 
        if (head != NULL) {
            pq.push(head);
            head = head->next;
        }
    }
	
    last->next = NULL;

    return newHead;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

void printList(struct Node* head)
{
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
    cout<<endl ;
}

int main()
{
	struct Node* head = NULL;

	push(&head, 8);
	push(&head, 56);
	push(&head, 12);
	push(&head, 2);
	push(&head, 6);
	push(&head, 3);

	int k = 2;

	cout << "Original Doubly linked list:\n";
	printList(head);

	head = sortAKSortedDLL(head, k);

	cout << "\nDoubly linked list after sorting:\n";
	printList(head);

	return 0;
}

*/
