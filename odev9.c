#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset için

#define MAX_SIZE 15 // Aðaç için maksimum dizi boyutu

// Aðacý temsil eden dizimiz (Karakter dizisi)
// Boþ düðümleri '\0' (NULL karakter) ile temsil edeceðiz.
char astArray[MAX_SIZE];

// Diziyi temizleme yardýmcý fonksiyonu
void clearTree() {
    memset(astArray, '\0', sizeof(astArray));
}

// Düðüm ekleme fonksiyonu (Manuel olarak indekse yerleþtiriyoruz)
void addNode(char data, int index) {
    if (index >= MAX_SIZE) {
        printf("Hata: Dizi kapasitesi asildi!\n");
        return;
    }
    astArray[index] = data;
}

// Aðacýn yapýsýný (Kim kimin çocuðu/atasý) ekrana yazdýrma
void printTreeStructure(int size) {
    printf("Dizi Indeksleri ve Agac Iliskileri (AST):\n");
    printf("-----------------------------------------\n");
    
    int i; // C89 uyumu için dýþarýda tanýmladýk
    for (i = 0; i < size; i++) {
        if (astArray[i] != '\0') { // Eðer düðüm boþ deðilse
            printf("[%d] . Dugum: '%c'", i, astArray[i]);

            // Kök deðilse atasýný bul ve yazdýr
            if (i > 0) {
                int parentIndex = (i - 1) / 2;
                printf(" | Atasi (Parent): [%d] '%c'", parentIndex, astArray[parentIndex]);
            } else {
                printf(" | <-- KOK DUGUM (Root)");
            }
            
            // Sol ve Sað çocuklarýn indekslerini hesapla
            int leftChild = (2 * i) + 1;
            int rightChild = (2 * i) + 2;

            // Varsa çocuklarýný yazdýr
            if (leftChild < size && astArray[leftChild] != '\0')
                 printf(" | Sol Cocuk: [%d] '%c'", leftChild, astArray[leftChild]);
            
            if (rightChild < size && astArray[rightChild] != '\0')
                 printf(" | Sag Cocuk: [%d] '%c'", rightChild, astArray[rightChild]);

            printf("\n");
        }
    }
    printf("\nToplu Dizi Gorunumu: { ");
    for(i=0; i<size; i++) {
        if(astArray[i] == '\0') printf("_ "); // Boþluklarý _ ile gösterelim
        else printf("%c ", astArray[i]);
    }
    printf("}\n\n");
}

int main() {
    // --- ORNEK 1: "A + B * C" Ýfadesi ---
    // Ýþlem Önceliði: Önce çarpma (B*C), sonra toplama (A + Sonuç)
    // Görsel Aðaç:
    //       +  (Index 0)
    //      / \
    //     A   * (Index 1 ve 2)
    //        / \
    //       B   C (Index 5 ve 6 -> 2*2+1 ve 2*2+2)
    
    printf("=== ORNEK 1: A + B * C ===\n");
    clearTree(); // Diziyi temizle

    // Kök (Root)
    addNode('+', 0); 

    // Seviye 1
    addNode('A', 1); // 0'ýn solu
    addNode('*', 2); // 0'ýn saðý

    // Seviye 2
    // Index 1'in (A) çocuklarý yok (Index 3 ve 4 boþ kalacak)
    addNode('B', 5); // Index 2'nin (*) solu -> (2*2)+1 = 5
    addNode('C', 6); // Index 2'nin (*) saðý -> (2*2)+2 = 6

    printTreeStructure(7); // 7 elemanlýk kýsmý yazdýr
    printf("--------------------------------------------------\n\n");


    // --- ORNEK 2: "(A + B) * (C - D)" Ýfadesi ---
    // Bu tam bir ikili aðaç (Complete Binary Tree) olur.
    // Görsel Aðaç:
    //          * (Index 0)
    //         / \
    //        +   - (Index 1 ve 2)
    //       / \ / \
    //      A  B C  D (Index 3, 4, 5, 6)

    printf("=== ORNEK 2: (A + B) * (C - D) ===\n");
    clearTree(); // Diziyi temizle

    // Kök
    addNode('*', 0);

    // Seviye 1
    addNode('+', 1); // 0'ýn solu
    addNode('-', 2); // 0'ýn saðý

    // Seviye 2 (Yapraklar)
    addNode('A', 3); // 1'in solu -> (2*1)+1 = 3
    addNode('B', 4); // 1'in saðý -> (2*1)+2 = 4
    addNode('C', 5); // 2'nin solu -> (2*2)+1 = 5
    addNode('D', 6); // 2'nin saðý -> (2*2)+2 = 6

    printTreeStructure(7); // 7 elemanlýk kýsmý yazdýr

    return 0;
}
