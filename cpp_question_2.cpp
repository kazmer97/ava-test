// C++ implementation to delete all
// even nodes from the singly linked list

// #include <bits/stdc++.h>

#include <stdlib.h> // pulls in declaration of malloc, free
#include <string.h> // pulls in declaration for strlen.
#include <stdio.h>
using namespace std;

// Node of the singly linked list
struct Node
{
	int data;
	struct Node* next;
};

// Function to insert a node at
// the beginning of the singly
// Linked List
void push(struct Node** head_ref,
		int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(
			sizeof(
				struct Node));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

// Function to delete a node in a
// singly Linked List.
// head_ref --> Pointer to head
// node pointer.
// key --> Node to be deleted
void deleteNode(struct Node** head_ref,
				int key)
{
	// Store head node
	struct Node *temp = *head_ref,
				*prev;

	// If head node itself holds
	// the key to be deleted
	if (temp != NULL
		&& temp->data == key) {
		// Changed head
		*head_ref = temp->next;
		// Free old head
		free(temp);
		return;
	}

	// Search for the key to be
	// deleted, keep track of the
	// previous node as we need
	// to change 'prev->next'
	while (temp != NULL
		&& temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	// If key was not present
	// in linked list
	if (temp == NULL)
		return;

	// Unlink the node from
	// linked list
	prev->next = temp->next;

	// Free memory
	free(temp);
}

// Function to delete all the
// even nodes from the
// singly linked list
struct Node* even_nodes(Node** head_ref)
{
	Node* head_even = NULL;
	Node* ptr = *head_ref;
	// Node* next;

	while (ptr != NULL) {
		// next = ptr->next;
		// If true, delete node 'ptr'
		if (ptr->data % 2 == 0)
		{
			
			push(&head_even,
				ptr->data);
			deleteNode(head_ref,
					ptr->data);
		}
		ptr = ptr->next;
	}

	return(head_even);
}

// This function prints contents
// of linked list starting from
// the given node
void printList(struct Node* node)
{
	while (node != NULL) {
		printf(" %d -> ", node->data);
		node = node->next;
	}
}

// Driver code
int main()
{
	// Start with the empty list
	Node* head = NULL;
	push(&head, 19);
	push(&head, 18);
	push(&head, 3);
	push(&head, 4);
	push(&head, 1);

	printf("Initial List: ");
	printList(head);

	Node *even_list = even_nodes(&head);

	printf("\nFinal List: ");
	printList(head);
	printf("\nEVEN List: ");
	printList(even_list);

	return 0;
}

