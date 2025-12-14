#include <stdio.h>
#include <stdlib.h>

// Baðlý liste düðüm yapýsý (Node structure)
struct Node {
    int data;
    struct Node* next;
};

// Yeni düðüm oluþturmak için yardýmcý fonksiyon
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// --- ÖDEVÝN ASIL ÝSTENEN KISMI ---
// Recursive Destroy Fonksiyonu
void destroy(struct Node* root) {
    // Base Case: Eðer düðüm boþsa (listenin sonuysa) dur.
    if (root == NULL) {
        return;
    }

    // Recursive Step: Önce listenin geri kalanýný yok et
    destroy(root->next);

    // Action: Geri kalan silindikten sonra, þu anki düðümü sil
    printf("%d degeri hafizadan siliniyor (Freeing memory)...\n", root->data);
    free(root);
}
// ---------------------------------

int main() {
    // Örnek bir liste oluþturalým: 10 -> 20 -> 30 -> NULL
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Liste olusturuldu.\n");

    // Fonksiyonu çaðýralým
    printf("Recursive destroy islemi basliyor:\n");
    destroy(head);
    
    // Güvenlik için head pointer'ý NULL'a eþitleyelim (Dangling pointer olmasýn)
    head = NULL; 

    printf("Tum liste basariyla silindi.\n");

    return 0;
}
