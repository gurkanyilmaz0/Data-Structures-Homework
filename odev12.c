#include <stdio.h>

#define V 4 // Düðüm sayýsý (Vertex Count) - Örnek olarak 4 düðüm (0, 1, 2, 3)

// Matrisi baþlatan fonksiyon (Hepsini 0 yapar)
void initMatrix(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

// Kenar (Edge) ekleme fonksiyonu
// src: Kaynak (Source), dest: Hedef (Destination)
void addEdge(int arr[][V], int src, int dest) {
    // Yönsüz Graf (Undirected Graph) olduðu için karþýlýklý 1 yapýyoruz
    arr[src][dest] = 1;
    arr[dest][src] = 1;
}

// Matrisi ekrana yazdýrma fonksiyonu
void printMatrix(int arr[][V]) {
    int i, j;
    printf("\n--- Adjacency Matrix (Komsuluk Matrisi) ---\n");
    printf("   ");
    for(i = 0; i < V; i++) printf("%d ", i); // Üstteki baþlýklar
    printf("\n");
    printf("   --------\n");

    for (i = 0; i < V; i++) {
        printf("%d| ", i); // Soldaki baþlýklar
        for (j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Adjacency matrisimizi tanýmlayalým (4x4)
    int adjMatrix[V][V];

    // 1. Matrisi sýfýrla
    initMatrix(adjMatrix);

    // 2. Baðlantýlarý (Kenarlarý) Ekle
    // Graf Örneði:
    // 0 --- 1
    // |     |
    // 2 --- 3
    
    addEdge(adjMatrix, 0, 1); // 0 ile 1 baðlý
    addEdge(adjMatrix, 0, 2); // 0 ile 2 baðlý
    addEdge(adjMatrix, 1, 3); // 1 ile 3 baðlý
    addEdge(adjMatrix, 2, 3); // 2 ile 3 baðlý

    // 3. Sonucu Yazdýr
    printMatrix(adjMatrix);

    return 0;
}
