TP 2: Listes Chainée 
Les algorithmes que j'ai proposé par rapport 
aux problèmes ci-dessous sont les suivants:

1) Lire un élément et supprimer toute ses occurrences
dans une liste chainée: Pour y parvenir, en supposant
qu'on ait une liste donné, on lit la valeur. Après
quoi on parcours la liste du début jusqu'à la fin, et
à l'aide de 2 pointeurs on verifie à chaque fois que
la case ou l'on se trouve ne contient pas la valeur.
Dans une tel éventualité, on désalloue la case du pointeur
avec lequel on parcours la liste et grace au deuxième
pointeur(qui precède celui-ci), on peux continuer le
processus jusqu'à atteindre le dernier élément de la
liste. Au cas ou la liste serai vide, l'algorithme nous
permettrait de passer dans erreur.

2) Insertion en tête et en queue dans une liste simplement
chainée circulaire: Dans le cas de la l'insertion en tête,
on parcours la liste jusqu'à trouver le dernier élément
de la liste, on fait une allocation et on fait pointer la
dernière cellule sur la cellule qu'on vient de créer
et on fait pointer la cellule que l'on vient de créer sur
la tête de liste(ou l) et la l prend l'adresse de la cellule
alloué et devient ainsi la tête de liste. Pour l'insertion
en queue, le processus et le même sauf pour la dernière étape
car dand ce cas, la case qu'on a allouer ne deviendra pas la
première case mais restera la dernière.

3) Insertion en tête et en queue dans une liste doublement
chainée circulaire: Dans le cas de l'insertion en queue ici,
on aura pas besoin de parcourir la liste car le dernier
élément de la liste et le précédent du premier. On fera donc
une allocation et on fera que le suivant de notre nouvelle
cellule soit l'actuelle tête de liste, que le précédent de
la nouvelle cellule soit le précédent de la tête actuelle, que
le suivant de la cellule précédent l'actuelle tête de liste soit
l'adresse de notre nouvelle cellule ainsi que le précédent de
la tête actuelle. Si l'on s'arrête là alors on aura fait
un ajout en queue. On fait donc que la variable contenant la
tête de liste prenne la valeur de l'adresse de la cellule
que nous avons créer ci-dessus faisant d'elle la nouvelle tête
et une Insertion en tête avec du succès.
