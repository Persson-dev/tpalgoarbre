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

// Définition du type noeud de l'arbre ...
typedef struct node
{
    struct node *left;
    std::uint64_t data;
    int height;
    struct node *right;

    node(std::uint64_t a_Data)
    {
        left = nullptr;
        data = a_Data;
        height = 1;
        right = nullptr;
    }
} node;

int height(node *n)
{
    return n ? n->height : 0;
}

/**
 * Balance factor
 */
int bf(node *n)
{
    return n ? height(n->left) - height(n->right) : 0;
}

node *rrrotation(node *n){ // Rotation RR
    node *tp;
    tp = n->left;

    n->left = tp->right;
    tp->right = n;

    n->height = std::max(height(n->left), height(n->right)) + 1;
    tp->height = std::max(height(tp->right), tp->height) + 1;
    return tp;
}


node* llrotation(node *n){ // Rotation LL
    node *tp;
    tp = n->right;

    n->right = tp->left;
    tp->left = n;

    n->height = std::max(height(n->left), height(n->right)) + 1;
    tp->height = std::max(height(tp->right), tp->height) + 1;
    return tp; 
}


node * rlrotation(node *n){ // Rotation RL
    node *tp;

    n->left = llrotation(n->left);
    tp = rrrotation(n);

    return tp; 
}

node* lrrotation(node *n){ // Rotation LR
    node *tp;

    n->right = rrrotation(n->right);
    tp = llrotation(n);

    return tp;
}

// insère la valeur data au bon endroit dans l'arbre enraciné en root ...
node *insert(node *root, uint64_t data)
{
    if (!root)
        return new node{data};

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root;
    }

    root->height = 1 + std::max(root->left ? root->left->height : 0, root->right ? root->right->height : 0);

    int balance = bf(root);

    // gauche gauche
    if (balance > 1 && data < root->left->data)
        return rrrotation(root);

    // droite droite
    if (balance < -1 && data > root->right->data)
        return llrotation(root);

    // gauche droite
    if (balance > 1 && data > root->left->data)
    {
        return rlrotation(root);
    }

    // droite gauche
    if (balance < -1 && data < root->right->data)
    {
        return lrrotation(root);
    }

    return root;
}

node *minNode(node *root)
{
    node *current = root;

    // loop down to find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;

    return current;
}

node *deleteNode(node *root, uint64_t data)
{
    if (!root)
        return root;

    if (data < root->left->data)
    {
        root->left = deleteNode(root->left, data);
        return root;
    }
    else if (data > root->right->data)
    {
        root->right = deleteNode(root->right, data);
        return root;
    }
    if ((root->left == nullptr) ||
        (root->right == nullptr))
    {
        node *temp = root->left ? root->left : root->right;

        if (temp == nullptr)
        {
            temp = root;
            root = nullptr;
        }
        else
            *root = *temp;

        delete temp;
    }
    else
    {
        node *temp = minNode(root->right);
        // Copy the inorder successor's
        // data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    root->height = 1 + std::max(root->left ? root->left->data : 0,
                                root->right ? root->right->data : 0);

    int balance = bf(root);

    // gauche gauche
    if (balance > 1 && 
        bf(root->left) >= 0)
        return rrrotation(root);

    // gauche droite
    if (balance > 1 && 
        bf(root->left) < 0) {
        return rlrotation(root);
    }

    // droite droite
    if (balance < -1 && 
        bf(root->right) <= 0)
        return llrotation(root);

    // droite gauche
    if (balance < -1 && 
        bf(root->right) > 0) {
        return lrrotation(root);
    }
    
    return root;
}

int main()
{

    node *root = nullptr;
    // remplir l'arbre
    // faire des tests
    return 0;
}