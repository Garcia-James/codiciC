/*Esercizio 1. Definire una struttura di nome data con i campi giorno mese ed anno tutti di tipo int.
Scrivere poi una funzione che riceve un parametro di tipo data e stampa la data passata come parametro 
nella forma estesa in cui il giorno è rappresentato con un numero da 1 a 31, il nome del mese è riportato
per esteso e l’anno è riportato come numero di quattro cifre. Qualora la data passata come parametro contenga un anno di sole due cifre, esso
va considerato un anno del XX secolo se superiore a 24 e un anno del XXI secolo se minore o uguale a 24.*/
#include <stdio.h>
#include <string.h>

struct data {
    int giorno;
    int mese;
    int anno;
}nascita;

void stampaData(struct data nascita) {
    const char* nomiMesi[] = {
        "Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno",
        "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"
    };

    
    int secolo = nascita.anno > 24 ? 1900 : 2000;
    int annoCompleto = secolo + nascita.anno;

    
    if (nascita.mese < 1 || nascita.mese > 12 || nascita.giorno < 1 || nascita.giorno > 31) {
        printf("Data non valida.\n");
        return;
    }

    
    if ((nascita.mese == 4 || nascita.mese == 6 || nascita.mese == 9 || nascita.mese == 11) && nascita.giorno > 30) {
        printf("Data non valida.\n");
        return;
    }

    
    if (nascita.mese == 2) {
        
        int bisestile = (annoCompleto % 4 == 0 && annoCompleto % 100 != 0) || (annoCompleto % 400 == 0);
        if (nascita.giorno > 29 || (nascita.giorno > 28 && !bisestile)) {
            printf("Data non valida.\n");
            return;
        }
    }

   
    printf("%d %s %d\n", nascita.giorno, nomiMesi[nascita.mese - 1], annoCompleto);
}

int main() {
    struct data nascita;

    printf("Inserisci il giorno: ");
    scanf("%d", &nascita.giorno);
    printf("Inserisci il mese: ");
    scanf("%d", &nascita.mese);
    printf("Inserisci l'anno: ");
    scanf("%d", &nascita.anno);

    stampaData(nascita);

    return 0;
}
