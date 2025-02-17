# TP4 : Tarik Ouabrk

Ce TP regroupe plusieurs exercices permettant d'explorer différents concepts fondamentaux du langage C++ surtout explorer et manipuler des structures de données. L'objectif est de compiler et exécuter chaque exercice en utilisant des directives du préprocesseur.

## Organisation du TP

- Le fichier principal est main.cpp .
- L'exercice à compiler est sélectionné à l'aide de la macro \`EXO\`.
- Par défaut, l'exercice 1 est compilé.
- Pour compiler un autre exercice, il faut définir la macro \`EXO\` lors de la compilation (ex: -DEXO=2 pour l'exercice 2).
## Description des Exercices

## Exercice 1 : Manipulation d'un Tableau C 1D
Déclare et initialise un tableau d'entiers.
Affiche les éléments du tableau et calcule la somme de ces éléments.

## Exercice 2 : Tableau C 2D (Stockage Matriciel)
Crée un tableau à deux dimensions (matrice).
Affiche les éléments de la matrice et calcule la somme des éléments de la diagonale principale.

## Exercice 3 : Inversion d'un Tableau sans std::reverse
Inverse un tableau manuellement sans utiliser les fonctions standard comme std::reverse.
Affiche le tableau original et inversé.

## Exercice 4 : Utilisation de std::vector
Utilise un std::vector pour stocker une série de nombres saisis par l'utilisateur.
Double chaque élément du vecteur et l'affiche.

## Exercice 5 : Utilisation de std::list
Crée une std::list et insère des éléments au début et à la fin.
Affiche la liste après ces insertions.

## Exercice 6 : Utilisation de std::set
Crée un std::set d'entiers.
Insère un élément déjà existant et observe l'effet sur la structure (les doublons sont ignorés).

## Exercice 7 : Utilisation de std::map
Crée un std::map avec des paires clé-valeur (nom d'étudiant et note).
Affiche chaque paire clé-valeur.

## Exercice 8 : Compteur de mots avec std::unordered_map
Crée un compteur de mots à l'aide de std::unordered_map.
Compte les occurrences de chaque mot dans une phrase donnée.

## Exercice 9 : Trier un std::vector sans std::sort
Trie un std::vector d'entiers sans utiliser la fonction std::sort.
Affiche le vecteur avant et après le tri.

## Exercice 10 : Trouver la Plus Longue Séquence Consécutive dans un std::set
Crée un std::set d'entiers non triés.
Trouve la plus longue séquence d'entiers consécutifs dans cet ensemble.

## Exercice 11 : Implémentation d'un Cache LRU (Least Recently Used)
Implémente un cache LRU (Least Recently Used) en utilisant std::unordered_map et std::list.
Le cache garde une capacité maximale et élimine les éléments les moins récemment utilisés.

## Instructions pour exécuter le programme

### Prérequis
- Un compilateur C++ supportant le standard C++17.
- Exemple : `g++` (GNU Compiler Collection) ou tout autre compilateur C++ compatible.

### Compilation et exécution
1. Naviguez vers le répertoire contenant le fichier `main.cpp`. Ouvrez un terminal et placez-vous dans le dossier où se trouve votre fichier source.

2. Pour compiler un exercice spécifique, définissez la macro correspondante lors de la compilation à l'aide de l'option `-D` :

   - **Exercice 1 (Manipulation d'un Tableau C 1D)** :
     ```sh
     g++ -std=c++17 -DEXO=1 main.cpp -o programme
     ```
   
   - **Exercice 2 (Tableau C 2D (Stockage Matriciel))** :
     ```sh
     g++ -std=c++17 -DEXO=2 main.cpp -o programme
     ```
   
   - **Exercice 3 (Inversion d'un Tableau sans std::reverse)** :
     ```sh
     g++ -std=c++17 -DEXO=3 main.cpp -o programme
     ```
   
   - **Exercice 4 (Utilisation de std::vector)** :
     ```sh
     g++ -std=c++17 -DEXO=4 main.cpp -o programme
     ```
   - **Exercice 5 (Utilisation de std::list)** :
     ```sh
     g++ -std=c++17 -DEXO=5 main.cpp -o programme
     ```
   - **Exercice 6 (Utilisation de std::set)** :
     ```sh
     g++ -std=c++17 -DEXO=6 main.cpp -o programme
     ```
   - **Exercice 7 (Utilisation de std::map)** :
     ```sh
     g++ -std=c++17 -DEXO=7 main.cpp -o programme
     ```
   - **Exercice 8 (Compteur de mots avec std::unordered_map)** :
     ```sh
     g++ -std=c++17 -DEXO=8 main.cpp -o programme
     ```
   - **Exercice 9 (Trier un std::vector sans std::sort)** :
     ```sh
     g++ -std=c++17 -DEXO=9 main.cpp -o programme
     ```
   - **Exercice 10 (Trouver la Plus Longue Séquence Consécutive dans un std::set)** :
     ```sh
     g++ -std=c++17 -DEXO=10 main.cpp -o programme
     ```
   - **Exercice 11 (Implémentation d'un Cache LRU (Least Recently Used))** :
     ```sh
     g++ -std=c++17 -DEXO=11 main.cpp -o programme
     ```
     
3. **Exécution du programme** :
   Une fois la compilation réussie, exécutez le programme généré en tapant :
   ```sh
   ./programme
   ```

### Cas particulier (EXO non défini)
Si aucune macro `EXO` n'est définie lors de la compilation, l'exercice 1 sera compilé par défaut. Cela garantit qu'au moins un exercice fonctionne sans configuration particulière.

Veillez à bien définir `EXO` avec une valeur valide (`1, 2, 3, 4, 5, ..,11`). Si une valeur invalide est fournie, une erreur sera levée lors de la compilation.

Exemple d'erreur en cas de mauvaise valeur :
```sh
Veuillez definir EXO entre 1 et 11. Exemple : -DEXO=1
