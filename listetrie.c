#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct cellule {
    int valeur;
    struct cellule* suivant;
} cellule;

typedef cellule* Liste;

Liste creer_liste_vide();
Liste inserer_trie(Liste liste, int nouvelle_valeur);
void afficher_liste(Liste liste);
void liberer_liste(Liste liste);

Liste creer_liste_vide() {
    return NULL;
}

Liste inserer_trie(Liste liste, int nouvelle_valeur) {
    cellule* nouveau = (cellule*)malloc(sizeof(cellule));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return liste; 
    }
    nouveau->valeur = nouvelle_valeur;
    nouveau->suivant = NULL;

    cellule* courant = liste;
    cellule* precedent = NULL;

    while (courant != NULL && courant->valeur < nouvelle_valeur) {
        precedent = courant;
        courant = courant->suivant;
    }

    if (precedent == NULL) {
        nouveau->suivant = liste;
        return nouveau;
    } 
    else {
        nouveau->suivant = courant;
        precedent->suivant = nouveau;
        return liste;
    }
}

void afficher_liste(Liste liste) {
    cellule *courant = liste;
    if (courant == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    printf("Liste triée : ");
    while (courant != NULL) {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

void liberer_liste(Liste liste) {
    cellule *courant = liste;
    while (courant != NULL) {
        cellule *tmp = courant;
        courant = courant->suivant;
        free(tmp);
    }
}

int main() {
    Liste ma_liste = creer_liste_vide();
    int val;
    
    printf("--- Gestion de Liste Triée Dynamique ---\n");
    printf("Entrez des nombres entiers, un par un.\n");

     while (printf("Entrez un nombre : ") && scanf("%d", &val) == 1) {
        ma_liste = inserer_trie(ma_liste, val);
        afficher_liste(ma_liste);
    }
    printf("Pour arrêter, entrez un caractère non numérique (ex: 'q').\n");
    printf("------------------------------------------\n");

   
    while (getchar() != '\n'); 

    afficher_liste(ma_liste);

    liberer_liste(ma_liste);

    return 0;
}