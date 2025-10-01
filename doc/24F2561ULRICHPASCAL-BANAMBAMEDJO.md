### TRAVAUX PRATIQUES 2 : LISTES DOUBLEMENT CHAINNEES CICULAIRES.

#### 1. Introduction

  Une liste doublement chaînée circulaire est une structure de données dynamique où chaque élément (nœud) contient : une valeur, un pointeur vers l’élément suivant, un pointeur vers l’élément précédent. 
Le caractère circulaire signifie ou permet que: le dernier élément pointe vers le premier (dans le champ suivant), le premier élément pointe vers le dernier (dans le champ precedent). 
Cette structure permet un parcours dans les deux sens, sans jamais rencontrer de NULL.

#### 2. Déclaration de la Structure.
  Chaque noeud est representé par un type cellule qui contient: valeur ; stocke la donnée de l’élément (un entier à l'occurence), suivant : pointeur vers le prochain élément, precedent : pointeur vers l’élément précédent,
et le type Liste est défini comme un pointeur vers cellule.

#### 3. Fonction du Programme.
  ##### a) InsertHead:
  Permet d'insérer un élément en tête ou au début de la liste. Pour celà, il y a deux cas: 
Cas vide : si la liste est vide, le premier élément pointe sur lui-même (suivant = precedent = p).

Cas général :
on relie le nouveau nœud à l’ancien premier et au dernier, on met à jour les pointeurs du dernier et du premier,la tête (*l) devient le nouveau nœud.

  ##### b) InsertTail :
  Cette fonction insère de nouveaux éléments à la fin de la liste. Et donc il y a aussi deux cas:
Cas vide : identique à l’insertion en tête.

Cas général :
on relie le nouveau nœud à l’ancien dernier et au premier, on met à jour les pointeurs du dernier et du premier, le pointeur tête (*l) ne change pas.

  ##### c) PrintList : 
  Le parcours commence à la tête et continue tant que l’on n’est pas revenu au début. Pour celà on utilise une boucle do...while qui permet de travailler sur deux conditions.

  ##### d) main :
  Elle permet l'intéraction avec les différentes fonctions et avec le code dans son ensemble

#### 4. Conclusion. 
Le programme implémente correctement une liste doublement chaînée circulaire en C avec : insertion en tête, insertion en queue, affichage des éléments.
Cette structure est particulièrement utile quand on doit parcourir des données de manière circulaire, comme dans la gestion de files circulaires.
