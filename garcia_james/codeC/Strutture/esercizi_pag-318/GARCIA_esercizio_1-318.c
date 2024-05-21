#include <stdio.h>
#include <string.h>

typedef struct {
    char anello;
    int zona;
    char settore;
    int orientamento;
} Posto;

int main() {
    Posto p;
    strcpy(p.anello, 'A');
    p.zona = 1;
    p.settore = 'S';
    p.orientamento = 123;

    printf("Prenotazione: %c%d%c%d\n", p.anello, p.zona, p.settore, p.orientamento);
    return 0;
}
