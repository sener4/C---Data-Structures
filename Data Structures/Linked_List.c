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

int getNumberOfNodes(struct Node* headRef)
{
	int count = 0;
	struct Node* nodeCurrent = headRef;

	while (nodeCurrent != NULL)
	{
		count++;
		nodeCurrent = nodeCurrent->next;
	}

	return count;
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

void insertNodeFront(struct Node** headRef, int newNodeData) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = newNodeData;
	newNode->next = (*headRef);

	(*headRef) = newNode;
}

void insertNodeAfter(struct Node* prevNode, int newNodeData) {
	checkIfNodeExists(prevNode);

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = newNodeData;
	newNode->next = prevNode->next;

	prevNode->next = newNode;
}

void insertNodeEnd(struct Node** headRef, int newNodeData) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *headRef;

	newNode->data = newNodeData;
	newNode->next = NULL;

	if (*headRef == NULL) {
		*headRef = newNode;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newNode;
}

void deleteNode(struct Node** headRef, int prevNodeData) {
	struct Node* temp = *headRef;
	struct Node* prev = *headRef;

	if (temp != NULL && temp->data == prevNodeData) {
		*headRef = temp->next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->data != prevNodeData) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		return;
	}

	prev->next = temp->next;

	free(temp);
}

void deleteNodeFromPosition(struct Node* head, int nodePosition) {
	struct Node* temp = head;

	if (nodePosition == 0) {
		head = head->next;
		temp->next = NULL;
		free(temp);
	}
	else {
		for (int i = 0; i < nodePosition - 1; i++) {
			temp = temp->next;
		}
		struct Node* nodeToBeDeleted = temp->next;
		temp->next = temp->next->next;
		nodeToBeDeleted->next = NULL;
		free(nodeToBeDeleted);
	}
}

void deleteLinkedList(struct Node** headRef) {
	struct Node* nodeCurrent = *headRef;
	struct Node* next;

	while (nodeCurrent != NULL) {
		next = nodeCurrent->next;
		free(nodeCurrent);
		nodeCurrent = next;
	}

	headRef = NULL;
}

void updateNodeFromPosition(struct Node* head, int nodePosition, int newNodeData) {
	struct Node* tempNode = head;

	for (int i = 0; i < nodePosition - 1; i++) {
		tempNode = tempNode->next;
	}

	tempNode->data = newNodeData;
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

	updateNodeFromPosition(head, 3, 2313);

	printLinkedList(head);

	//deleteNode(&head, 2);

	//printLinkedList(head);

	//deleteNodeFromPosition(head, 2);

	//printLinkedList(head);

	//deleteLinkedList(head);

	//printLinkedList(head);
}