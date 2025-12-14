#include <stdio.h>

#define ROWS 4
#define COLS 4

int main() {
    // 1. ADIM: Dense Matrix Tanýmlama
    // Dikkat et: Elemanlarýn çoðu 0 DEÐÝL, dolu sayýlardan oluþuyor.
    int denseMatrix[ROWS][COLS] = {
        {10, 20, 0,  40},
        {50, 60, 70, 0 },
        {80, 0,  90, 100},
        {110,120,130,140}
    };

    int i, j;
    int totalElements = ROWS * COLS;
    int nonZeroCount = 0;

    printf("--- Dense Matrix (Yogun Matris) Gosterimi ---\n");
    printf("---------------------------------------------\n");

    // 2. ADIM: Matrisi Ekrana Yazdýrma ve Dolu Elemanlarý Sayma
    for (i = 0; i < ROWS; i++) {
        printf("|\t"); // Görsellik için tab
        for (j = 0; j < COLS; j++) {
            printf("%d\t", denseMatrix[i][j]);

            // Eðer eleman 0 deðilse sayacý artýr
            if (denseMatrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
        printf("|\n");
    }

    // 3. ADIM: Yoðunluk (Density) Hesaplama
    // Formül: (Dolu Sayýsý / Toplam Sayý) * 100
    float density = ((float)nonZeroCount / totalElements) * 100;

    printf("---------------------------------------------\n");
    printf("Toplam Eleman Sayisi: %d\n", totalElements);
    printf("Dolu (Non-zero) Eleman Sayisi: %d\n", nonZeroCount);
    printf("Matris Yogunlugu (Density): %%%.2f\n", density);

    // 4. ADIM: Karar Verme
    // Genellikle %50'den fazlasý doluysa Dense kabul edilir.
    if (density >= 50.0) {
        printf("\nSONUC: Bu matris YOGUN (DENSE) bir matristir.\n");
        printf("Standart 2D Array kullanimi uygundur.\n");
    } else {
        printf("\nSONUC: Bu matris SEYREK (SPARSE) bir matristir.\n");
        printf("Hafiza tasarrufu icin Sýkýstýrýlmýs yapý kullanýlmalýdýr.\n");
    }

    return 0;
}
