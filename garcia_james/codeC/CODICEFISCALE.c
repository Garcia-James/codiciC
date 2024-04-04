#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DIM 100

void cerca(FILE *comuni, char contenuto[]) {
    comuni = fopen("comuni.txt", "r");
    if (comuni == NULL) {
        printf("Errore apertura file\n");
        return;
    }
    while (fgets(contenuto, DIM, comuni) != NULL) {
        printf("%s", contenuto);
    }
    fclose(comuni);
}

int main(void) {
    FILE *comuni;
    char contenuto[DIM];
    int scelta, giorno, mese, anno;
    char nome[DIM];
    char cognome[DIM];
    char sesso[3];
    char nascita[DIM];
    char provincia[DIM];
    char codice[17];

    do {
        printf("\nMENU:\n 1.GENERA CODICE FISCALE\n 2.ESTRAI INFORMAZIONI\n 3.ESCI\n");
        scanf("%d", &scelta);

        switch(scelta) {
            case 1:
                printf("Inserire nome: \n");
                getchar(); // Consuma il carattere di nuova riga residuo dal precedente scanf
                fgets(nome, DIM, stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Rimuove il carattere di nuova riga
                for (int i = 0; nome[i]; i++) {
                    nome[i] = toupper(nome[i]);
                }

                printf("Inserire cognome: \n");
                fgets(cognome, DIM, stdin);
                cognome[strcspn(cognome, "\n")] = '\0';
                for (int i = 0; cognome[i]; i++) {
                    cognome[i] = toupper(cognome[i]);
                }

                printf("Inserire sesso: \n");
                fgets(sesso, sizeof(sesso), stdin);
                sesso[strcspn(sesso, "\n")] = '\0';
                for (int i = 0; sesso[i]; i++) {
                    sesso[i] = toupper(sesso[i]);
                }

                printf("Inserire il luogo di nascita: \n");
                fgets(nascita, DIM, stdin);
                nascita[strcspn(nascita, "\n")] = '\0';
                for (int i = 0; nascita[i]; i++) {
                    nascita[i] = toupper(nascita[i]);
                }

                printf("Inserire la provincia: \n");
                fgets(provincia, DIM, stdin);
                provincia[strcspn(provincia, "\n")] = '\0';
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
                cerca(comuni, contenuto); 
                break;
        }
    } while (scelta != 3);

    return 0;
}
