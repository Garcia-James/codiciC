#include <stdio.h>

// Definizione della struttura 'data'
struct data {
    int giorno;
    int mese;
    int anno;
};

// Funzione per stampare la data in forma estesa
void stampaData(struct data d) {
    // Array di stringhe per i nomi dei mesi
    char *nomi_mesi[] = {
        "Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno",
        "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"
    };

    // Determina il secolo dell'anno
    
    if (d.anno >= 25) {
       d.anno+=1900;
    } else {
       d.anno+=2000;
    }

    // Stampa la data nella forma estesa
    printf("%d %s %d\n", d.giorno, nomi_mesi[d.mese - 1],d.anno);
}

int main() {
    // Dichiarazione di una variabile di tipo 'data'
    struct data mia_data;

    // Richiesta all'utente di inserire giorno, mese e anno
    do {
        printf("Inserire giorno, mese e anno: ");
        scanf("%d %d %d", &mia_data.giorno, &mia_data.mese, &mia_data.anno);

        // Chiamata alla funzione per stampare la data se l'input è corretto
        if (mia_data.giorno > 0 && mia_data.giorno <= 31 && mia_data.mese > 0 && mia_data.mese <= 12) {
            stampaData(mia_data);
        } else {
            printf("ERRORE: Inserimento non valido!\n");
        }
    } while (mia_data.giorno <= 0 || mia_data.giorno > 31 || mia_data.mese <= 0 || mia_data.mese > 12);

    return 0;
}
