Rapport de Projet TP2 : Gestion de Liste Chaînée

Objectif: L'objectif de ce projet est de gérer une liste chaînée d'entiers. Le programme permet à l'utilisateur de créer une liste, d'y insérer des valeurs, de l'afficher et de supprimer toutes les occurrences d'un élément spécifique.

Méthode: Le programme utilise une structure de données de type liste chaînée simple (Liste). Chaque élément, ou cellule, contient une valeur entière et un pointeur vers l'élément suivant.

Le programme se déroule en plusieurs étapes :
     Création de la liste : L'utilisateur est invité à saisir la taille de la liste et les valeurs de chaque élément. Les éléments sont ajoutés séquentiellement à la fin de la liste.
    Affichage de la liste : La liste est parcourue et tous ses éléments sont affichés, ce qui permet à l'utilisateur de visualiser la liste avant toute modification.
    Suppression d'éléments : L'utilisateur entre une valeur à supprimer. Le programme parcourt la liste et retire toutes les cellules contenant cette valeur.
    Affichage de la nouvelle liste : La liste est affichée une seconde fois pour montrer le résultat de l'opération de suppression.
    
Fonctionnement détaillé
Structure de la Liste Chaînée
Le code définit une structure Cellule et un alias Liste pour un pointeur de Cellule. La structure Cellule est fondamentale et se compose de deux champs :
    int val : un champ pour stocker la valeur entière de la cellule.
    struct cellule *suiv : un pointeur vers la cellule suivante dans la liste.
.  Création de la liste (creation_liste)
Cette fonction alloue dynamiquement de la mémoire pour chaque nouvelle cellule. Elle parcourt une boucle for n fois, où n est le nombre d'éléments souhaité. À chaque itération, elle :
    Alloue une nouvelle cellule avec malloc.
    Demande à l'utilisateur d'entrer une valeur pour cette cellule.
    Initialise le pointeur suiv de la nouvelle cellule à NULL.
    Gère la connexion de la nouvelle cellule à la liste existante : si c'est la première cellule, elle devient la tête de la liste (*l); sinon, elle est ajoutée à la fin en utilisant un pointeur dernier.
.  Affichage de la liste (afficher_liste)
La fonction parcourt la liste du début à la fin en utilisant un pointeur temporaire (temp) qui se déplace de cellule en cellule grâce à la chaîne de pointeurs suiv. Elle affiche la valeur de chaque cellule, suivie d'une flèche ->, et se termine par NULL pour marquer la fin de la liste.
.  Suppression d'occurrences (supprimer_occurrences)
Cette fonction est conçue pour supprimer toutes les instances d'une valeur donnée. Elle utilise deux pointeurs, courant et precedent, pour parcourir la liste.
    Elle gère d'abord le cas où l'élément à supprimer se trouve au début de la liste (tête de la liste).
    Ensuite, elle parcourt le reste de la liste : si courant pointe vers une cellule à supprimer, elle modifie le pointeur suiv de la cellule precedent pour qu'il "saute" la cellule à supprimer, puis libère la mémoire de cette dernière.
    Si la cellule ne doit pas être supprimée, precedent et courant avancent simplement d'une position.
.  Fonction principale (main)
La fonction main orchestre le programme. Elle demande à l'utilisateur le nombre d'éléments pour la liste, appelle la fonction de création, puis les fonctions d'affichage (avant et après la suppression). Enfin, elle libère toute la mémoire allouée dynamiquement pour éviter les fuites de mémoire, en parcourant la liste et en utilisant free sur chaque cellule.
