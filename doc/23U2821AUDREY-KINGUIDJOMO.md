Rapport sur le programme de liste doublement chaînée triée
1. Objectif

Le programme permet de créer et de gérer une liste doublement chaînée d’entiers.
Les principales fonctionnalités sont :

Créer une liste initiale avec des éléments prédéfinis.

Permettre à l’utilisateur d’ajouter de nouveaux éléments.

Garantir que la liste reste toujours triée en ordre croissant après chaque insertion.

Afficher la liste avec des flèches <-> pour indiquer la double liaison entre les nœuds.

2. Structures de données

Node (nœud de la liste) :

data : valeur entière du nœud.

next : pointeur vers le nœud suivant.

prev : pointeur vers le nœud précédent.

head : pointeur vers le premier nœud de la liste.

Chaque nœud est donc relié à son voisin précédent et suivant, ce qui permet de parcourir la liste dans les deux sens.

3. Algorithmes principaux
3.1 Création d’un nœud

Allocation dynamique mémoire pour un nœud.

Initialisation des pointeurs next et prev à NULL.

3.2 Insertion triée

Si la liste est vide, le nouveau nœud devient la tête.

Sinon, on parcourt la liste pour trouver la position appropriée où insérer le nouvel élément afin que la liste reste triée.

Trois cas possibles :

Insertion en tête : le nouvel élément est plus petit que la tête.

Insertion en queue : le nouvel élément est plus grand que tous les éléments existants.

Insertion au milieu : le nouvel élément est inséré entre deux nœuds existants.

Les pointeurs next et prev sont mis à jour pour maintenir la double liaison.

3.3 Affichage de la liste

Parcours de la liste depuis la tête jusqu’à la fin.

Chaque élément est affiché avec <-> pour montrer la connexion double.

Exemple : 1 <-> 3 <-> 7 <-> 10 <-> 15.

4. Interactions avec l’utilisateur

La liste initiale contient quelques éléments (exemple : 3, 7, 10, 15).

L’utilisateur peut saisir autant d’éléments qu’il souhaite.

Après chaque insertion, la liste est affichée dans l’ordre croissant.

5. Conclusion

Le programme permet de gérer efficacement une liste doublement chaînée triée.

La triabilité de la liste est automatique après chaque insertion.

L’utilisation des flèches <-> dans l’affichage rend la double liaison claire et lisible.
