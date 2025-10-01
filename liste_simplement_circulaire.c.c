#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int valeur;
    struct cellule* suivant;
} cellule;

typedef cellule* Liste;

void Inserttete(int n, Liste *l);
void Insertqueu(int n, Liste *l);
void afficheListe(Liste l, int n);

int main() {
    int n, m;
    Liste l = NULL;

    printf("\nCombien de valeurs souhaitez-vous enregistrer : ");
    scanf("%d", &n);

    printf("\nVoulez-vous les enregistrer en tête ou en queue ?\n1. Tête \n2. Queue : ");
    scanf("%d", &m);

    if (m == 1) {
        Inserttete(n, &l);
    } else {
        Insertqueu(n, &l);
    }

    afficheListe(l, n);

    return 0;
}

void Inserttete(int n, Liste *l) {
    int i, x;
    for (i = 0; i < n; i++) {
        printf("\nEntrer la valeur %d : ", i + 1);
        scanf("%d", &x);

        cellule* p = (cellule*)malloc(sizeof(cellule));
        p->valeur = x;

        if (*l == NULL) {
            *l = p;
            p->suivant = p;
        } else {
            cellule* t = *l;
            while (t->suivant != *l) {
                t = t->suivant;
            }
            t->suivant = p;
            p->suivant = *l;
            *l = p; 
        }
    }
}

void Insertqueu(int n, Liste *l) {
    int i, x;
    for (i = 0; i < n; i++) {
        printf("\nEntrer la valeur %d : ", i + 1);
        scanf("%d", &x);

        cellule* p = (cellule*)malloc(sizeof(cellule));
        p->valeur = x;

        if (*l == NULL) {
            *l = p;
            p->suivant = p;
        } else {
            cellule* t = *l;
            while (t->suivant != *l) {
                t = t->suivant;
            }
            t->suivant = p;
            p->suivant = *l;
        }
    }
}

void afficheListe(Liste l, int n) {
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

