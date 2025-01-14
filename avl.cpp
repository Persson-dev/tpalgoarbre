/*
Instructions :

1 - Compléter le code ci-dessous pour avoir une implémentation
d'un arbre de type AVL. 

2 - Faire des tests d'insertion, de suppression et de recherche (penser à faire une fonction d’affichage). 
Faire en sorte d’avoir toutes les possibilités dans vos tests.

3 – Considérer le fichier "avl_bench.cpp". Il génère des ensembles de benchmarking avec des tailles d’arbre différentes : 
de 2^5 éléments dans l’arbre à 2^25 éléments. Pour chaque taille, il donne 3 fichiers :
Values, Search et Delete, contenant respectivement les valeurs à insérer dans l’arbre, 
les valeurs à rechercher, et celles à supprimer. Ajouter dans ce fichier (avl.cpp) les codes nécessaire pour lire 
les fichiers de benchmark et effectuer les opérations correspondantes.

4 – Ajouter du code pour chronométrer les opérations. Réaliser des courbes comparatives 
des temps d’exécutions des différentes opération en fonction de la taille de l’arbre. 
Retrouvons-nous bien les complexité logarithmiques promises ?

*/

#include <iostream>

using namespace std;

// Définition du type noeud de l'arbre ...
typedef struct node {
    struct node *left;
    uint64_t data;
    int height;
    struct node *right;

} node;


int bf(node *n){ // Balance Factor BF
    int bf = 0;
    // Calcul le BF au niveau du noeud n dans l'arbre
    return bf;   
}

node* llrotation(node *n){ // Rotation LL
    node *p;
    node *tp;
    p = n;
    tp = p->left;

    p->left = tp->right;
    tp->right = p;

    return tp; 
}


node* rrrotation(node *n){ // Rotation RR
    node *p;
    node *tp;
    p = n;
    tp = p->right;

    p->right = tp->left;
    tp->left = p;

    return tp; 
}


node * rlrotation(node *n){
    node *tp;
    // effectue la rotation RL
    // TODO
    return tp; 
}

node* lrrotation(node *n){
    node *tp;
    // effectue la rotation LR
    // TODO
    return tp; 
}

node* insert(node *root, uint64_t data){
    
    // insère la valeur data au bon endroit dans l'arbre enraciné en root ...
    // TODO
    return root;
}


node* deleteNode(node *root, uint64_t data){

    // cherche la valeur data dans l'arbre enraciné en root puis la supprime ...    
    // TODO
    return root;
}

    

int main(){

    node * root = NULL;
    // remplir l'arbre
    // faire des tests
    return 0;
  
}