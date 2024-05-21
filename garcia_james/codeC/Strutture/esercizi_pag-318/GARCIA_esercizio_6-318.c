#include <stdio.h>

typedef struct {
    int vagone;
    char classe;
    int posti[6];
} Compartimento;

Compartimento prenotazioneTreno(int N, char classe) {
    Compartimento compartimento;
    compartimento.vagone = N / 6 + 1;
    compartimento.classe = classe;
    for (int i = 0; i < 6; i++) {
        compartimento.posti[i] = (classe == 'X') ? 10 : 20;
    }
    return compartimento;
}

int main() {
    Compartimento c = prenotazioneTreno(5, 'X');
    printf("Vagone: %d, Classe: %c, Posti: ", c.vagone, c.classe);
    for (int i = 0; i < 6; i++) {
        printf("%d ", c.posti[i]);
    }
    printf("\n");
    return 0;
}
