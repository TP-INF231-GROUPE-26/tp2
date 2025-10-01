#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int val;
    struct cellule *suiv;
} Cellule;
typedef Cellule *Liste;
void creation_liste(Liste *l, int n) {
    if (n <= 0) {
        *l = NULL; 
        return;
    }

    Liste nouveau, dernier = NULL;
    for (int i = 0; i < n; i++) {
        nouveau = (Liste)malloc(sizeof(Cellule));
        if (nouveau == NULL) {
            printf("Erreur d'allocation de mémoire.\n");
            return;
        }

        printf("Entrer l'element numero:%d\n",i+1);
        scanf("%d", &(nouveau->val));
        nouveau->suiv = NULL;

        if (*l == NULL) { 
            *l = nouveau;
        } else {
            dernier->suiv = nouveau;
        }
        dernier = nouveau;
    }
}

void afficher_liste(Liste l) {
    if (l == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Liste temp = l;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->suiv;
    }
    printf("NULL\n");
}

void supprimer_occurrences(Liste *l, int element_a_supprimer) {
    Liste courant = *l, precedent = NULL;

    while (courant != NULL && courant->val == element_a_supprimer) {
        *l = courant->suiv; 
        free(courant);
        courant = *l;
    }

    while (courant != NULL) {
        if (courant->val == element_a_supprimer) {
            precedent->suiv = courant->suiv;
            free(courant);
            courant = precedent->suiv; 
        } else {
            precedent = courant;
            courant = courant->suiv;
        }
    }
}

int main() {
    Liste ma_liste = NULL; 
    
    int nombre_elements, element_a_supprimer;

    printf("Combien d'elements voulez-vous dans la liste ? ");
    scanf("%d", &nombre_elements);

    creation_liste(&ma_liste, nombre_elements);

    printf("\nListe avant suppression :\n");
    afficher_liste(ma_liste);

    printf("\nQuel element voulez-vous supprimer ? ");
    scanf("%d", &element_a_supprimer);

    supprimer_occurrences(&ma_liste, element_a_supprimer);

    printf("\nnouvelle liste suppression :\n");
    afficher_liste(ma_liste);

    while (ma_liste != NULL) {
        Liste temp = ma_liste;
        ma_liste = ma_liste->suiv;
        free(temp);
    }
    
    return 0;
}
