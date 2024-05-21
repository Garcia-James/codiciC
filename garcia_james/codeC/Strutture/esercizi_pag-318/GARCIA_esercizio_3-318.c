#include <stdio.h>

typedef struct {
    char nome[20];
    double diametroEquatoriale;
    int numeroLune;
    double durataOrbita;
    double durataRotazione;
    double distanzaSole;
} Pianeta;

int main() {
    Pianeta terra = {"Terra", 12742, 1, 365.25, 24, 149.6};
    printf("Nome: %s, Diametro: %.2f km, Lune: %d, Orbita: %.2f giorni, Rotazione: %.2f ore, Distanza: %.1f milioni km\n", 
           terra.nome, terra.diametroEquatoriale, terra.numeroLune, terra.durataOrbita, terra.durataRotazione, terra.distanzaSole);
    return 0;
}
