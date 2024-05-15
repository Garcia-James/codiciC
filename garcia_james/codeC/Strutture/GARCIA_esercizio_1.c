#include <stdio.h>
#include <string.h>
#define MAX 3

typedef struct {
    char cognome[20];
    char nome[20];
    int voto;
} alunno;

int main() {
    alunno a[MAX];
    int n;
    int trovato = 0;
    char cerca[20];

    do {
        printf("Inserire numero alunni: \n");
        scanf("%d", &n);
    } while (n > MAX || n < 1);

    for (int i = 0; i < n; i++) { 
        printf("Inserisci il cognome dell'alunno %d: \n", i + 1);
        scanf("%s", a[i].cognome);
        printf("Inserisci il nome dell'alunno %d: \n", i + 1);
        scanf("%s", a[i].nome);
        printf("Inserisci il voto: \n");
        scanf("%d", &a[i].voto);
    }

    printf("Inserire cognome alunno da cercare: \n");
    scanf("%s", cerca); 

    for (int j = 0; j < n; j++) { 
        if (strcmp(a[j].cognome, cerca) == 0) {
            printf("Alunno trovato: \n%s\t%s\t%d\n", a[j].nome, a[j].cognome, a[j].voto);
            trovato = 1;
            break; 
        }
    }

    if (!trovato) {
        printf("Alunno non trovato.\n");
    }

    return 0;
}
