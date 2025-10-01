=================================================================================
                      ## README – Projets de Listes en C
=================================================================================

Ce dossier contient 5 programmes en langage C illustrant différentes structures de données linéaires (listes chaînées). 
Chaque programme met en évidence une variante de liste et des opérations possibles pouvant être éffectuées. 

Ici, on considéra que n est la valeur d'une opération ou d'une unité mémoire

--------------------------------------------------------------------------------------------------
 ### PROGRAMME 1 : Liste Simplement Chainnée – Supression de toutes les occurences d'un Elément
--------------------------------------------------------------------------------------------------
- Structure : Liste simplement chaînée
- Objectif : 
  * Créer une liste à partir des valeurs saisies par l’utilisateur
  * Afficher tous les éléments
  * Supprimer toutes les occurrences d’une valeur donnée

- Complexité temporelle :
  * Insertion en queue : O(n) (parcours nécessaire)
  * Affichage : O(n)
  * Suppression d’occurrences : O(n)

- Complexité mémoire :
  * O(n) (chaque élément est un nœud avec une valeur + pointeur)

-----------------------------------------------------------------------
  ### PROGRAMME 2 : Insertion dans une liste Simplement Chainnée Trié
-----------------------------------------------------------------------
- Structure : Liste simplement chaînée
- Objectif :
  * Insérer directement chaque nouvel élément à la bonne position (liste triée)
  * Afficher et libérer la liste

- Complexité temporelle :
  * Insertion triée : O(n) (parcours jusqu’à la position)
  * Affichage : O(n)

- Complexité mémoire :
  * O(n)

----------------------------------------------------------------------------
 ### PROGRAMME 3 : Insertion dans une Liste Doublement Chainnée Trié
------------------------------------------------------------------------------
- Structure : Liste doublement chaînée non circulaire
- Objectif :
  * Insertion triée dans la liste (en tête, au milieu ou en queue)
  * Affichage avec notation « <-> » pour montrer la double liaison
  * Programme interactif permettant l’insertion répétée

- Complexité temporelle :
  * Insertion triée : O(n)
  * Affichage : O(n)

- Complexité mémoire :
  * O(n)
-------------------------------------------------------------------------------------------
 ### PROGRAMME 4 : Insertion en tête et en queue d'uneListe Simplement Chainnée Circulaire 
-------------------------------------------------------------------------------------------
- Structure : Liste simplement chaînée circulaire
- Objectif :
  * Permet l’insertion multiple en tête (head) ou en queue (tail)
  * Affiche les valeurs en parcourant la liste circulaire

- Complexité temporelle :
  * Insertion en tête : O(1)
  * Insertion en queue : O(1) (grâce au lien circulaire)
  * Affichage : O(n)

- Complexité mémoire :
  * O(n)

---------------------------------------------------------------------------------------------
 ### PROGRAMME 5 :  Insertion en tête et en queue d'une Liste Doublement Chainnée Circulaire
----------------------------------------------------------------------------------------------
- Structure : Liste doublement chaînée circulaire
- Objectif :
  * Insertion de n éléments en tête ou en queue
  * Affichage de la liste circulaire

- Complexité temporelle :
  * Insertion en tête : O(1)
  * Insertion en queue : O(1)
  * Affichage : O(n)

- Complexité mémoire :
  * O(n) (chaque nœud contient valeur + 2 pointeurs)



n) pour n éléments.
