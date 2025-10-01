#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int valeur;
    struct cellule* suivant;
} cellule;

typedef cellule* Liste;

Liste creer_liste_vide();
Liste inserer_trie(Liste liste, int nouvelle_valeur);
void afficher_liste(Liste liste);
void liberer_liste(Liste liste);
void saisir_elements(Liste *liste_ptr, int nombre);

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

void saisir_elements(Liste *liste_ptr, int nombre) {
    int i, val;

    if (nombre <= 0) {
        printf("Aucun élément à insérer.\n");
        return;
    }

    printf("\n--- Saisie de %d élément(s) ---\n", nombre);
    for (i = 0; i < nombre; i++) {
        printf("Entrez le nombre %d/%d : ", i + 1, nombre);
        if (scanf("%d", &val) != 1) {
            printf("Saisie invalide. Opération annulée pour cette série.\n");
            // Nettoyage du buffer en cas d'erreur de saisie
            while(getchar() != '\n');
            return;
        }
        *liste_ptr = inserer_trie(*liste_ptr, val);
    }
    printf("Saisie terminée.\n");
}

int main() {
    Liste ma_liste = creer_liste_vide();
    int nb_elements;
    int choix;
    
    printf("--- Gestion de Liste Triée Dynamique ---\n");
    printf("Combien d'éléments voulez-vous insérer initialement ? : ");
    if (scanf("%d", &nb_elements) == 1) {
        while(getchar() != '\n'); 
        saisir_elements(&ma_liste, nb_elements);
    } else {
        printf("Saisie du nombre d'éléments invalide. Démarrage avec une liste vide.\n");
        while(getchar() != '\n'); 
    }
    
    do {
        printf("\n------------------------------------------\n");
        printf("Liste actuelle :\n");
        afficher_liste(ma_liste);
        printf("\nChoisissez une option :\n");
        printf("1. Afficher la liste (Liste triée)\n");
        printf("2. Ajouter de nouveaux éléments (Remplir à nouveau)\n");
        printf("3. Quitter le programme\n");
        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("Choix invalide. Veuillez entrer 1, 2 ou 3.\n");

            while(getchar() != '\n'); 
            choix = 0; 
            continue;
        }
        while(getchar() != '\n'); 

        switch (choix) {
            case 1:
                printf("\n--- Affichage de la Liste ---\n");
                afficher_liste(ma_liste);
                break;
            case 2:
                printf("\nCombien de nouveaux éléments voulez-vous ajouter ? : ");
                if (scanf("%d", &nb_elements) == 1) {
                    while(getchar() != '\n'); 
                    saisir_elements(&ma_liste, nb_elements);
                } else {
                    printf("Saisie du nombre d'éléments invalide.\n");
                    while(getchar() != '\n'); 
                }
                break;
            case 3:
                printf("\nFermeture du programme.\n");
                break;
            default:
                printf("\nOption non reconnue. Veuillez choisir 1, 2 ou 3.\n");
                break;
        }

    } while (choix != 3);

    liberer_liste(ma_liste);

    return 0;
}
