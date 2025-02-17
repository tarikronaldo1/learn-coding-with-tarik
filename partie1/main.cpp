#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>

// Si la macro EXO n'est pas definie lors de la compilation, on la definit par defaut aï¿½ 1.
#ifndef EXO
#define EXO 1
#endif

#if EXO == 1
// Exercice 1 : Manipulation d'un tableau C 1D
int main() {
    int tableau[5] = {10, 20, 30, 40, 50};  // Initialisation du tableau
    int somme = 0;  // Variable pour la somme des elements
    std::cout << "Elements : ";
    // Affichage des Ã©lÃ©ments du tableau et calcul de la somme
    for (auto val : tableau) {
        std::cout << val << " ";
        somme += val;
    }
    std::cout << "\nSomme : " << somme << std::endl;  // Affichage de la somme
    return 0;
}
#elif EXO == 2
// Exercice 2 : Tableau C 2D (Stockage Matriciel)
int main() {
    int matrice[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Matrice 3x3
    int somme_diag = 0; // Variable pour la somme de la diagonale
    std::cout << "Matrice :\n";
    // Affichage de la matrice et calcul de la somme de la diagonale
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrice[i][j] << " ";// Somme des elements diagonaux
            if (i == j) somme_diag += matrice[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "Somme diagonale : " << somme_diag << std::endl;
    return 0;
}
#elif EXO == 3
// Exercice 3 : Inversion d'un tableau sans algorithm
int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};// Tableau de 5 elements
    std::cout << "Original : ";
    // Affichage du tableau original
    for (int i = 0; i < 5; i++) std::cout << arr[i] << " ";
    std::cout << "\nInverse : ";
    // Inversion du tableau sans utiliser std::reverse 
    for (int i = 4; i >= 0; i--) std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}
#elif EXO == 4
// Exercice 4 : Utilisation de std::vector
int main() {
    std::vector<int> vec;// Declaration d'un vecteur vide

    int num; 
    // Lecture des entrées utilisateur et ajout dans le vecteur
    while (std::cin >> num) {  
        vec.push_back(num); // Ajouter le nombre au vecteur
        if (std::cin.peek() == '\n') break;  // Arreter dÃ¨s que l'utilisateur appuie sur EntrÃ©e
    }
    
    std::cout << "Double : ";
    // Affichage des Ã©lÃ©ments doublÃ©s
    for (auto val : vec) std::cout << val * 2 << " ";
    std::cout << std::endl;
    return 0;
}
#elif EXO == 5
// Exercice 5 : Utilisation de std::list
int main() {
    std::list<int> liste = {10, 20, 30, 40, 50};// Declaration d'une liste initialisee
    liste.push_front(0); // Ajouter un element au debut
    liste.push_back(60);  // Ajouter un element a la fin
    std::cout << "Apres insertion : ";
    // Affichage de la liste apres insertion
    for (auto val : liste) std::cout << val << " ";
    std::cout << std::endl;
    return 0;
}
#elif EXO == 6
// Exercice 6 : Utilisation de std::set
int main() {
    std::set<int> s = {5, 10, 15, 20};// Declaration d'un set

    std::cout << "Original : ";
    // Affichage des élements du set
    for (int val : s) std::cout << val << " ";
    std::cout << std::endl;

    s.insert(10);// Tentative d'insertion d'un doublon

    std::cout << "Apres insertion : ";
    // Affichage du set apres insertion (pas de doublons)
    for (auto val : s) std::cout << val << " ";
    std::cout <<" (pas de doublons)" <<std::endl;

    return 0;
}
#elif EXO == 7
// Exercice 7 : Utilisation de std::map
int main() {
    std::map<std::string, int> etudiants = {{"John", 85}, {"Alice", 90}, {"Bob", 78}};// Déclaration d'un map
    // Affichage des élements du map
    for (auto& [nom, note] : etudiants) {
        std::cout << nom << " : " << note << std::endl;
    }
    return 0;
}
#elif EXO == 8
// Exercice 8 : Compteur de mots avec std::unordered_map
int main() {
    std::unordered_map<std::string, int> compteur;
    std::string phrase, mot;

    std::cout << "Entrez une phrase : ";
    std::getline(std::cin, phrase);  // Lire une ligne complète

    std::stringstream ss(phrase);  // Convertir la phrase en flux de mots
    while (ss >> mot) compteur[mot]++;  // Compter chaque mot
    // Affichage des resultats
    for (const auto& [mot, occurence] : compteur) {
        std::cout << mot << " : " << occurence << std::endl;
    }

    return 0;
}
#elif EXO == 9
// Exercice 9 : Trier un std::vector avec std::sort() en utilisant <algorithm>
int main() {
    std::vector<int> vec = {30, 10, 50, 20, 40}; // DÃ©claration d'un vecteur
    std::cout << "Original : ";
    // Affichage du vecteur original
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    // Tri du vecteur
    std::sort(vec.begin(), vec.end());

    std::cout << "\nTrie : ";
    // Affichage du vecteur triÃ©
    for (int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
#elif EXO == 10
// Exercice 10 : Trouver la plus longue sequence consecutive dans un std::set

int main() {
    std::set<int> numbers = {100, 4, 200, 1, 3, 2}; // Declaration d'un set

    if (numbers.empty()) {
        std::cout << "La sÃ©quence est vide." << std::endl;
        return 0;
    }

    int longestStreak = 1;
    int currentStreak = 1;
    auto prev = numbers.begin(); // Initialisation du premier élement

    std::vector<int> longestSequence, currentSequence = {*prev};
    // Parcours du set pour trouver la séquence la plus longue
    for (auto it = std::next(numbers.begin()); it != numbers.end(); ++it) {
        if (*it == *prev + 1) {
            ++currentStreak;
            currentSequence.push_back(*it);
        } else {
            if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
                longestSequence = currentSequence;
            }
            currentStreak = 1;
            currentSequence = {*it};
        }
        prev = it;
    }

    // Vérification finale pour mettre Ã  jour la plus longue sÃ©quence
    if (currentStreak > longestStreak) {
        longestSequence = currentSequence;
        longestStreak = currentStreak;
    }

    // Affichage du resultat
    std::cout << "Plus longue sequence : " << longestStreak << " (";
    for (size_t i = 0; i < longestSequence.size(); ++i) {
        std::cout << longestSequence[i];
        if (i != longestSequence.size() - 1) std::cout << ", ";
    }
    std::cout << ")" << std::endl;

    return 0;
}

#elif EXO == 11
// Exercice 11 : Implementation d'un Cache LRU (Least Recently Used)
void display(const std::list<std::pair<int, int>>& lru) {
    std::cout << "Etat du cache : ";
    for (const std::pair<int, int>& item : lru) {
        std::cout << "(" << item.first << ", " << item.second << ") ";
    }
    std::cout << std::endl;
}

int get(std::unordered_map<int, std::list<std::pair<int, int>>::iterator>& cache, 
        std::list<std::pair<int, int>>& lru, int key) {
    if (cache.find(key) == cache.end()) return -1; // Clé non trouvée

    // Déplacer l'élement en tete (récemment utilisé)
    lru.splice(lru.begin(), lru, cache[key]);
    
    return cache[key]->second; // Retourne la valeur
}

void put(std::unordered_map<int, std::list<std::pair<int, int>>::iterator>& cache, 
         std::list<std::pair<int, int>>& lru, int capacity, int key, int value) {
    if (cache.find(key) != cache.end()) {
        // Mise A jour de la valeur et déplacement en tete
        cache[key]->second = value;
        lru.splice(lru.begin(), lru, cache[key]);
    } else {
        if (lru.size() == capacity) {
            // Supprimer l'élement le moins récemment utilisé
            int old_key = lru.back().first;
            std::cout << "Ajout de (" << key << ", " << value << "), suppression de (" << old_key << ", " << lru.back().second << ")\n";
            cache.erase(old_key);
            lru.pop_back();
        }
        // Ajouter un nouvel élement en tÃªte
        lru.emplace_front(key, value);
        cache[key] = lru.begin();
    }
}

int main() {
    std::list<std::pair<int, int>> lru;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
    int capacity = 2;

    put(cache, lru, capacity, 1, 10);
    put(cache, lru, capacity, 2, 20);
    display(lru);  // Etat du cache : (2, 20) (1, 10)

    std::cout << "Acces a la cle 1 : " << get(cache, lru, 1) << std::endl;
    display(lru);  // Etat du cache : (1, 10) (2, 20)

    put(cache, lru, capacity, 3, 30);
    display(lru);  // Etat du cache : (3, 30) (1, 10) (2, 20 supprimé)
    
    return 0;
}

#else
#error "Veuillez definir EXO entre 1 et 11 (-DEXO=1, -DEXO=2, etc.)"
#endif
