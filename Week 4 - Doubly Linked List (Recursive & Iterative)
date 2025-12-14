#include <stdio.h>
#include <stdlib.h>

// Çift Yönlü Bağlı Liste Düğümü (Doubly Linked List Node)
struct Node {
    int data;
    struct Node* next; // Sonraki düğümü gösterir
    struct Node* prev; // Önceki düğümü gösterir
};

// --- YÖNTEM 1: Non-Recursive (İteratif / Döngü ile) Yazdırma ---
void printIterative(struct Node* node) {
    printf("Iterative (Dongu ile): ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next; // Bir sonrakine geç
    }
    printf("NULL\n");
}

// --- YÖNTEM 2: Recursive (Özyinelemeli) Yazdırma ---
void printRecursive(struct Node* node) {
    // Base Case: Eğer düğüm boşsa dur
    if (node == NULL) {
        printf("NULL\n"); // Satır sonuna NULL yazıp bitiriyoruz
        return;
    }

    // Önce veriyi yazdır
    printf("%d -> ", node->data);

    // Sonra kendisini bir sonraki düğüm için tekrar çağır
    printRecursive(node->next);
}

// Düğüm oluşturmak için yardımcı fonksiyon
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    // Örnek bir Çift Yönlü Liste oluşturalım: 10 <-> 20 <-> 30
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    // Bağlantıları kuralım (Double Linked List olduğu için hem ileri hem geri)
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    printf("--- Doubly Linked List Yazdirma Odevi ---\n\n");

    // 1. Yöntemi Çağır
    printIterative(head);

    // 2. Yöntemi Çağır
    printf("Recursive (Ozyinelemeli): ");
    printRecursive(head);

    return 0;
}
