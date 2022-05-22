#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

int checkIfNodeExists(struct Node* node) {
	if (node == NULL) {
		printf("The node is NULL");
		return;
	}
}

struct Node* buildLinkedList() {
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	return head;
}

void printLinkedList(struct Node* node) {
	while (node != NULL) {
		printf(" %d ", node->data);
		node = node->next;
	}

	printf("\n");
}

void insertNodeFront(struct Node** headPointer, int newNodeData) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = newNodeData;
	newNode->next = (*headPointer);

	(*headPointer) = newNode;
}

void insertNodeAfter(struct Node* prevNode, int newNodeData) {
	checkIfNodeExists(prevNode);

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = newNodeData;
	newNode->next = prevNode->next;

	prevNode->next = newNode;
}

void insertNodeEnd(struct Node** headPointer, int newNodeData) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *headPointer;

	newNode->data = newNodeData;
	newNode->next = NULL;

	if (*headPointer == NULL) {
		*headPointer = newNode;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newNode;
}

void main() {
	struct Node* head = buildLinkedList();

	printLinkedList(head);

	insertNodeFront(&head, 0);

	printLinkedList(head);

	insertNodeAfter(head, 5);

	printLinkedList(head);

	insertNodeEnd(&head, 7);

	printLinkedList(head);
}