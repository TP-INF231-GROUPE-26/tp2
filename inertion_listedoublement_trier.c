#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Création d'un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insertion triée
void insertSorted(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) { // Liste vide
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current != NULL && current->data < data) {
        current = current->next;
    }

    if (current == *head) { // Insertion en tête
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else if (current == NULL) { // Insertion en queue
        Node* tail = *head;
        while (tail->next != NULL) tail = tail->next;
        tail->next = newNode;
        newNode->prev = tail;
    } else { // Insertion au milieu
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
}

// Affichage avec flèches pour montrer la double liaison
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Liste initiale
    int initialElements[] = {3, 7, 10, 15};
    int size = sizeof(initialElements) / sizeof(initialElements[0]);
    for (int i = 0; i < size; i++) {
        insertSorted(&head, initialElements[i]);
    }

    printf("Liste initiale: ");
    printList(head);

    int value;
    char choix;
    do {
        printf("Entrez un element a inserer: ");
        scanf("%d", &value);
        insertSorted(&head, value);
        printf("Liste apres insertion: ");
        printList(head);

        printf("Voulez-vous inserer un autre element ? (o/n) : ");
        scanf(" %c", &choix);
    } while (choix == 'o' || choix == 'O');

    return 0;
}
