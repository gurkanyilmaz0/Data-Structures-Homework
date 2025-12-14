#include <stdio.h>
#include <stdlib.h>

// Çift Yönlü Baðlý Liste Düðümü (Doubly Linked List Node)
struct Node {
    int data;
    struct Node* next; // Sonraki düðümü gösterir
    struct Node* prev; // Önceki düðümü gösterir
};

// --- YÖNTEM 1: Non-Recursive (Ýteratif / Döngü ile) Yazdýrma ---
void printIterative(struct Node* node) {
    printf("Iterative (Dongu ile): ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next; // Bir sonrakine geç
    }
    printf("NULL\n");
}

// --- YÖNTEM 2: Recursive (Özyinelemeli) Yazdýrma ---
void printRecursive(struct Node* node) {
    // Base Case: Eðer düðüm boþsa dur
    if (node == NULL) {
        printf("NULL\n"); // Satýr sonuna NULL yazýp bitiriyoruz
        return;
    }

    // Önce veriyi yazdýr
    printf("%d -> ", node->data);

    // Sonra kendisini bir sonraki düðüm için tekrar çaðýr
    printRecursive(node->next);
}

// Düðüm oluþturmak için yardýmcý fonksiyon
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    // Örnek bir Çift Yönlü Liste oluþturalým: 10 <-> 20 <-> 30
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    // Baðlantýlarý kuralým (Double Linked List olduðu için hem ileri hem geri)
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    printf("--- Doubly Linked List Yazdirma Odevi ---\n\n");

    // 1. Yöntemi Çaðýr
    printIterative(head);

    // 2. Yöntemi Çaðýr
    printf("Recursive (Ozyinelemeli): ");
    printRecursive(head);

    return 0;
}
