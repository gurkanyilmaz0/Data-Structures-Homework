#include <stdio.h>
#include <stdlib.h>

// Liste yapýsý
struct Node {
    int data;
    struct Node* next;
};

// Düðüm oluþturma fonksiyonu
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// --- SONDAN BAÞA YAZDIRMA (SAYAÇLI) ---
// Not: Sayacýn deðerini tutabilmek için pointer (*counter) kullanýyoruz.
void printReverse(struct Node* root, int* counter) {
    
    // Base Case: Listenin sonuna geldiysek dur (Geri dönmeye baþla)
    if (root == NULL) {
        return;
    }

    // Önce bir sonrakine git (En sona kadar dal)
    printReverse(root->next, counter);

    // --- BURASI DÖNÜÞ YOLU ---
    // Geri dönerken iþlem yapýyoruz
    *counter = *counter + 1; // Sayacý artýr
    printf("Sondan %d. Eleman: %d\n", *counter, root->data);
}

int main() {
    // Deðiþken tanýmlarý en üstte (Hata almamak için)
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    int sayac = 0; // Baþlangýç sayacý

    // 1. Listeyi Oluþturalým: 10 -> 20 -> 30 -> 40 -> NULL
    head = createNode(10);
    second = createNode(20);
    third = createNode(30);
    fourth = createNode(40);

    // Baðlantýlarý yapalým
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    printf("--- Listenin Sondan Basa Yazdirilmasi ---\n");
    printf("Normal sira: 10 -> 20 -> 30 -> 40\n\n");

    // Fonksiyonu çaðýralým (sayacýn adresini & ile gönderiyoruz)
    printReverse(head, &sayac);

    return 0;
}
