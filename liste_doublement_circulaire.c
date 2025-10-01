#include <stdio.h>
#include <stdlib.h>

// ===== Définition =====
typedef struct cellule {
    int valeur;
    struct cellule* suivant;
    struct cellule* precedent;
} cellule;

typedef cellule* Liste;

// ===== Prototypes =====
void InsertHead(int n, Liste *l);
void InsertTail(int n, Liste *l);
void PrintList(Liste l, int n);

// ===== MAIN =====
int main() {
    int n, m;
    Liste l = NULL;

    printf("\nCombien de valeurs souhaitez-vous enregistrer : ");
    scanf("%d", &n);

    printf("\nVoulez-vous les enregistrer en tête ou en queue ?\n1. Tête \n2. Queue : ");
    scanf("%d", &m);

    if (m == 1) {
        InsertHead(n, &l);
    } else {
        InsertTail(n, &l);
    }

    PrintList(l, n);

    return 0;
}

// ===== Insertion en tête =====
void InsertHead(int n, Liste *l) {
    int i, x;
    for (i = 0; i < n; i++) {
        printf("\nEntrer la valeur %d : ", i + 1);
        scanf("%d", &x);

        cellule* p = (cellule*)malloc(sizeof(cellule));
        p->valeur = x;

        if (*l == NULL) {
            // Premier élément
            *l = p;
            p->suivant = p;
            p->precedent = p;
        } else {
            cellule* d = (*l)->precedent;  // dernier élément
            p->suivant = *l;
            p->precedent = d;
            d->suivant = p;
            (*l)->precedent = p;
            *l = p; // nouveau head
        }
    }
}

// ===== Insertion en queue =====
void InsertTail(int n, Liste *l) {
    int i, x;
    for (i = 0; i < n; i++) {
        printf("\nEntrer la valeur %d : ", i + 1);
        scanf("%d", &x);

        cellule* p = (cellule*)malloc(sizeof(cellule));
        p->valeur = x;

        if (*l == NULL) {
            // Premier élément
            *l = p;
            p->suivant = p;
            p->precedent = p;
        } else {
            cellule* d = (*l)->precedent;  // dernier élément
            p->suivant = *l;
            p->precedent = d;
            d->suivant = p;
            (*l)->precedent = p;
            // pas de déplacement du head ici
        }
    }
}

// ===== Affichage =====
void PrintList(Liste l, int n) {
    if (l == NULL) return;

    printf("\nVoici les valeurs que vous avez saisies :\n");
    cellule* t = l;
    int i = 0;
    do {
        printf("Valeur %d : %d\n", i + 1, t->valeur);
        t = t->suivant;
        i++;
    } while (t != l && i < n);
}
