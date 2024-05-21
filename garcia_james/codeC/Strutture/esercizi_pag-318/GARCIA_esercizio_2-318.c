#include <stdio.h>
#include <string.h>

typedef struct {
    char codice[14];
    char data[11];
    char colonna[14];
} Giocata;

void copiaGiocateAnno(Giocata giocate[], int n, int annoRichiesto, Giocata risultato[]) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        int annoGiocata;
        sscanf(giocate[i].data, "%d", &annoGiocata);
        if (annoGiocata == annoRichiesto) {
            risultato[j++] = giocate[i];
        }
    }
}

int main() {
    Giocata giocate[100]; // Assumiamo di avere un array di 100 giocate
    Giocata risultato[100];
    int annoRichiesto = 2024;
    copiaGiocateAnno(giocate, 100, annoRichiesto, risultato);
    // Stampa delle giocate filtrate
    for (int i = 0; i < 100 && risultato[i].codice[0] != '\0'; i++) {
        printf("Codice: %s, Data: %s, Colonna: %s\n", risultato[i].codice, risultato[i].data, risultato[i].colonna);
    }
    return 0;
}
