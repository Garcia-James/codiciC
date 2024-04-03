#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define l 50

void cerca(FILE *comuni, char contenuto[]) {
    comuni = fopen("comuni.txt", "r");
    if (comuni == NULL) {
        printf("errore apertura file\n");
        return;
    }
    while (fgets(contenuto, l, comuni)) {
        printf("%s", contenuto);
    }
    fclose(comuni); // Chiude il file dopo l'uso
}

int main(void) {
    FILE *comuni;
    char contenuto[l];
    int scelta, giorno, mese, anno;
    char nome[l];
    char cognome[l];
    char sesso[2];
    char nascita[l];
    char provincia[l];
    char codice[17];

    do {
        printf("\nMENU:\n 1.GENERA CODICE FISCALE\n 2.ESTRAI INFORMAZIONI\n 3.ESCI\n");
        scanf("%d", &scelta);

        switch(scelta) {
            case 1:
                printf("Inserire nome: \n");
                scanf("%s", nome);
                for (int i = 0; nome[i]; i++) {
                    nome[i] = toupper(nome[i]);
                }
                printf("Inserire cognome: \n");
                scanf("%s", cognome);
                for (int i = 0; cognome[i]; i++) {
                    cognome[i] = toupper(cognome[i]);
                }
                printf("Inserire sesso: \n");
                scanf("%s", sesso);
                for (int i = 0; sesso[i]; i++) {
                    sesso[i] = toupper(sesso[i]);
                }
                printf("Inserire il luogo di nascita: \n");
                scanf("%s", nascita);
                for (int i = 0; nascita[i]; i++) {
                    nascita[i] = toupper(nascita[i]);
                }
                printf("Inserire la provincia: \n");
                scanf("%s", provincia);
                for (int i = 0; provincia[i]; i++) {
                    provincia[i] = toupper(provincia[i]);
                }
                printf("Inserire la data di nascita (gg/mm/aaaa): \n");
                scanf("%d/%d/%d", &giorno, &mese, &anno);
                break;

            case 2:
                printf("Inserisci il tuo codice fiscale: \n");
                scanf("%s", codice);
                for (int i = 0; codice[i]; i++) {
                    codice[i] = toupper(codice[i]);
                }
                cerca(comuni, contenuto); // Invoca la funzione cerca senza indirizzo di comuni
                break;
        }
    } while (scelta != 3);

    return 0;
}
