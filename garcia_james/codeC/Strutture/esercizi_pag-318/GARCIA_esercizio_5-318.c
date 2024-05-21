#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    char cognome[20];
    int gnome;
    float voti[3]; // scritto, orale, pratica
} Studente;

float calcolaMedia(Studente s) {
    return (s.voti[0] + s.voti[1] + s.voti[2]) / 3;
}

int main() {
    Studente studenti[100]; // Assumiamo di avere un array di 100 studenti
    strcpy(studenti[0].nome, "Mario");
    strcpy(studenti[0].cognome, "Rossi");
    studenti[0].gnome = 123;
    studenti[0].voti[0] = 8.0;
    studenti[0].voti[1] = 9.0;
    studenti[0].voti[2] = 10.0;

    float mediaMassima = -1.0;
    Studente migliore;
    for (int i = 0; i < 100; i++) {
        float media = calcolaMedia(studenti[i]);
        if (media > mediaMassima) {
            mediaMassima = media;
            migliore = studenti[i];
        }
    }
    printf("Migliore studente: %s %s con media %.2f\n", migliore.nome, migliore.cognome, mediaMassima);
    return 0;
}
