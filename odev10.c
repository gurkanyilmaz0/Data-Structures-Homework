#include <stdio.h>
#include <stdlib.h>

// Aðaç Düðüm Yapýsý
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Yeni düðüm oluþturma fonksiyonu
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// --- 1. INORDER TRAVERSAL (Sol - Kök - Sað) ---
// Küçükten büyüðe sýralý çýktý verir (BST ise)
void printInorder(struct Node* node) {
    if (node == NULL) return;

    printInorder(node->left);      // 1. Sola git
    printf("%d ", node->data);     // 2. Kökü yaz
    printInorder(node->right);     // 3. Saða git
}

// --- 2. POSTORDER TRAVERSAL (Sol - Sað - Kök) ---
// Genelde aðacý silmek (delete) için kullanýlýr (Kökü en son silmek için)
void printPostorder(struct Node* node) {
    if (node == NULL) return;

    printPostorder(node->left);    // 1. Sola git
    printPostorder(node->right);   // 2. Saða git
    printf("%d ", node->data);     // 3. Kökü yaz
}

// --- 3. PREORDER TRAVERSAL (Kök - Sol - Sað) ---
// (Ekstra bilgi olarak ekledim, hocan sorabilir)
void printPreorder(struct Node* node) {
    if (node == NULL) return;

    printf("%d ", node->data);     // 1. Kökü yaz
    printPreorder(node->left);     // 2. Sola git
    printPreorder(node->right);    // 3. Saða git
}

int main() {
    /*
            Aðaç Yapýsý (Örnek)
                 1
               /   \
              2     3
             / \
            4   5
    */

    // Düðümleri oluþturalým
    struct Node* root = createNode(1);
    root->left        = createNode(2);
    root->right       = createNode(3);
    root->left->left  = createNode(4);
    root->left->right = createNode(5);

    printf("--- Tree Traversal Ornekleri ---\n\n");

    printf("1. Inorder (Sol-Kok-Sag)   : ");
    printInorder(root);
    printf("\n(Beklenen: 4 2 5 1 3)\n\n");

    printf("2. Postorder (Sol-Sag-Kok) : ");
    printPostorder(root);
    printf("\n(Beklenen: 4 5 2 3 1)\n\n");

    printf("3. Preorder (Kok-Sol-Sag)  : ");
    printPreorder(root);
    printf("\n(Beklenen: 1 2 4 5 3)\n");

    return 0;
}
