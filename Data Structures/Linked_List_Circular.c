#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

void insertNodeFrontCircular(struct Node** headRef, int newData) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = *headRef;
	newNode->data = newData;
	newNode->next = *headRef;

	if (*headRef != NULL) {
		while (temp->next != *headRef) {
			temp = temp->next;
		}

		temp->next = newNode;
	}
	else {
		newNode->next = newNode;
	}

	*headRef = newNode;
}

void updateNodeCircular(struct Node* headRef, int nodePosition, int newNodeData) {
	struct Node* tempNode = headRef;

	for (int i = 0; i < nodePosition - 1; i++) {
		tempNode = tempNode->next;
	}

	tempNode->data = newNodeData;
}

void printList(struct Node* head) {
	struct Node* temp = head;

	if (temp != NULL) {
		do {
			printf("%d ", temp->data);
			temp = temp->next;
		} while (temp != head);
	}
	else {
		printf("%s", "The list is empty");
	}

	printf("\r\n");
}

void mainLinkedListCircular() {
	struct Node* head = NULL;

	insertNodeFrontCircular(&head, 1);
	insertNodeFrontCircular(&head, 3);
	insertNodeFrontCircular(&head, 4);

	printList(head);

	updateNodeCircular(head, 2, 323);

	printList(head);
}