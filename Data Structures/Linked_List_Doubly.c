#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* buildLinkedListDoubly() {
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;
	head->prev = NULL;

	second->data = 2;
	second->next = third;
	second->prev = head;

	third->data = 3;
	third->next = NULL;
	third->prev = second;

	return head;
}

void printLinkedListDoubly(struct Node* node) {
	struct Node* last = (struct Node*)malloc(sizeof(struct Node));

	while (node != NULL) {
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}

	//printf("\nTraversal in reverse direction \n");
	//while (last != NULL) {
	//	printf(" %d ", last->data);
	//	last = last->prev;
	//}

	printf("\n");
}

struct Node* insertNodeFrontDoubly(struct Node** headRef, int newNodeData) {

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = newNodeData;

	newNode->next = headRef;
	newNode->prev = NULL;

	if ((*headRef) != NULL) {
		(*headRef)->prev = newNode;
	}

	*headRef = newNode;

	return newNode;
}

void insertNodeAfterDoubly(struct Node* prevNode, int newData)
{
	if (prevNode == NULL) {
		printf("the given previous node cannot be NULL");
		return;
	}

	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));

	newNode->data = newData;

	newNode->next = prevNode->next;

	prevNode->next = newNode;

	newNode->prev = prevNode;

	if (newNode->next != NULL)
		newNode->next->prev = newNode;
}

void insertNodeEndDoubly(struct Node** headRef, int newData)
{
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *headRef;

	newNode->data = newData;
	newNode->next = NULL;

	if (*headRef == NULL) {
		newNode->prev = NULL;
		*headRef = newNode;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = newNode;

	newNode->prev = last;

	return;
}

void deleteNodeDoubly(struct Node* node)
{
	struct Node* prev = (struct Node*)malloc(sizeof(struct Node));

	if (node == NULL)
		return;
	else {
		while (node->next != NULL) {
			node->data = node->next->data;
			prev = node;
			node = node->next;
		}

		prev->next = NULL;
	}
}

void main() {
	struct Node* head = buildLinkedListDoubly();

	printLinkedListDoubly(head);

	insertNodeAfterDoubly(head, 8);

	printLinkedListDoubly(head);

	insertNodeEndDoubly(&head, 9);

	printLinkedListDoubly(head);

}