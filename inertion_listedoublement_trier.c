#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertSorted(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current != NULL && current->data < data) {
        current = current->next;
    }
    if (current == *head) { // insertion en tête
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else if (current == NULL) { // insertion en queue
        Node* tail = *head;
        while (tail->next != NULL) 
            tail = tail->next;
        tail->next = newNode;
        newNode->prev = tail;
    } else { // insertion au milieu
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
}

void printList(Node* head) {
    Node* tail = NULL;
    printf("Liste avant reverse: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        tail = head;
        head = head->next;
    }
    printf("NULL\n");

    printf("Liste en reverse: ");
    while (tail != NULL) {
        printf("%d <-> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, val;

    printf("Combien d'elements voulez-vous entrer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez l'element %d: ", i + 1);
        scanf("%d", &val);
        insertSorted(&head, val);
    }

    printList(head);
    return 0;
}