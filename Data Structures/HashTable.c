#include <stdio.h>
#include <stdlib.h>

struct Employee {
	unsigned short code;
	char* name;
	char* dept;
	double salary;
};

struct Node {
	struct Employee* info;
	struct Node* next;
};

#define HASH_TABLE_SIZE 100

unsigned char hashFunction(unsigned char hashTableSize, unsigned short int key) {
	return (key % hashTableSize);
}

struct Employee* buildHashTableEmp(unsigned short code, char* name, char* dept, double salary) {

	struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));

	newEmployee->code = code;
	newEmployee->name = (char*)malloc(strlen(name) + 1);
	strcpy(newEmployee->name, name);
	newEmployee->dept = (char*)malloc(strlen(dept) + 1);
	strcpy(newEmployee->dept, dept);
	newEmployee->salary = salary;

	return newEmployee;
}

struct Node* insertNode(struct Node* node, struct Employee* emp) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->info = emp;
	newNode->next = node;

	return newNode;
}

void insertNodeInHashTable(struct Node** hashTable, unsigned char hashTableSize, struct Employee* emp) {
	unsigned char nodePosition = hashFunction(hashTableSize, emp->code);

	hashTable[nodePosition] = insertNode(hashTable[nodePosition], emp);
}

void deleteNodeFromHashTable(struct Node** hashTable, int key) {
	int hashCode = hashFunction(HASH_TABLE_SIZE, key);

	while (hashTable[hashCode] != NULL) {
		if (hashTable[hashCode]->info->code == key) {
			hashTable[hashCode - 1]->next = hashTable[hashCode + 1];
			hashTable[hashCode]->next = NULL;
			free(hashTable[hashCode]);

			break;
		}

		++hashCode;

		hashCode %= HASH_TABLE_SIZE;
	}
}

struct Node* searchNode(struct Node** hashTable, int key) {
	int hashCode = hashFunction(HASH_TABLE_SIZE, key);

	while (hashTable[hashCode] != NULL) {
		if (hashTable[hashCode]->info->code = key) {
			return hashTable[hashCode];
		}

		++hashCode;
		hashCode %= HASH_TABLE_SIZE;
	}

	return NULL;
}

void printHashTable(struct Node** hashTable) {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			printf("%s", hashTable[i]->info->name);
			printf("\n");
		}
	}
}

void main() {

	struct Node** hashTable = NULL;

	hashTable = (struct Node**)malloc(HASH_TABLE_SIZE * sizeof(struct Node));

	for (unsigned char i = 0; i < 100; i++) {
		hashTable[i] = NULL;
	}

	struct Employee* emp = (struct Employee*)malloc(sizeof(struct Employee));
	struct Employee* emp1 = (struct Employee*)malloc(sizeof(struct Employee));
	struct Employee* emp2 = (struct Employee*)malloc(sizeof(struct Employee));

	emp = buildHashTableEmp(3213, "Angajat 1", "Departament 1", 3231);
	emp1 = buildHashTableEmp(123, "Angajat 2", "Departament 2", 5000);
	emp2 = buildHashTableEmp(204, "Angajat 3", "Departament 3", 4500);

	insertNodeInHashTable(hashTable, HASH_TABLE_SIZE, emp);
	insertNodeInHashTable(hashTable, HASH_TABLE_SIZE, emp1);
	insertNodeInHashTable(hashTable, HASH_TABLE_SIZE, emp2);

	struct Node* searchedNode = (struct Node*)malloc(sizeof(struct Node));
	struct Employee* searchedEmployee = (struct Employee*)malloc(sizeof(struct Employee));

	searchedNode = searchNode(hashTable, 13);

	searchedEmployee = searchedNode->info;

	printf("Angajatul %s din departamentul %s are codul %d si salariul %f.", searchedEmployee->name, searchedEmployee->dept, searchedEmployee->code, searchedEmployee->salary);
	printf("\n");

	//printHashTable(hashTable);

	deleteNodeFromHashTable(hashTable, 13);

	printHashTable(hashTable);
}