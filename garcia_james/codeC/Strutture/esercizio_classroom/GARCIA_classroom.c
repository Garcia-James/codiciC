/*Realizzare in C un elenco che contiene per ciascuno studente:
il nome, il cognome, l’età, e la media che ha conseguito a fine anno. 

L’utente, inizialmente deve inserire i dati e poi attraverso un menù deve consentire le seguenti operazioni:
1- Stampa media dei voti con nome e cognome degli alunni;

2- Visualizzazione della media di un alunno specifico
3- Visualizzazione della media di tutti gli alunni
4- Visualizzazione dei dati degli alunni con voto>=6
5- Visualizzazione dei dati degli alunni con voto<6
6- Uscita dal programma

Numero degli studenti da considerare 5
Materie: Italiano, Matematica, Informatica, Storia, Inglese.
Ricorda: utilizzo delle funzioni.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENTI 5
#define VALUTAZIONI 5

typedef struct {
    char nome[50];
    char cognome[50];
    int eta;
    float voti[VALUTAZIONI];
    float media;
} Studente;

void inserisciDati(Studente studenti[]) {
    for(int i = 0; i < STUDENTI; i++) {
        printf("Inserisci i dati per lo studente %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", studenti[i].nome);
        printf("Cognome: ");
        scanf("%s", studenti[i].cognome);
        printf("Età: ");
        scanf("%d", &studenti[i].eta);

        for(int j = 0; j < VALUTAZIONI; j++) {
            printf("Voto %d: ", j + 1);
            scanf("%f", &studenti[i].voti[j]);
        }
    }
}

void calcolaMedie(Studente studenti[]) {
    for(int i = 0; i < STUDENTI; i++) {
        float somma = 0;
        for(int j = 0; j < VALUTAZIONI; j++) {
            somma += studenti[i].voti[j];
        }
        studenti[i].media = somma / VALUTAZIONI;
    }
}

void stampaMedie(Studente studenti[]) {
    printf("\nMedie degli studenti:\n");
    for(int i = 0; i < STUDENTI; i++) {
        printf("%s %s: %.2f\n", studenti[i].nome, studenti[i].cognome, studenti[i].media);
    }
}

void visualizzaMediaStudente(Studente studenti[]) {
    char nome[50], cognome[50];
    int trovato = 0;

    printf("Inserisci il nome dello studente: ");
    scanf("%s", nome);
    printf("Inserisci il cognome dello studente: ");
    scanf("%s", cognome);

    for(int i = 0; i < STUDENTI; i++) {
        if(strcmp(studenti[i].nome, nome) == 0 && strcmp(studenti[i].cognome, cognome) == 0) {
            printf("%s %s: %.2f\n", studenti[i].nome, studenti[i].cognome, studenti[i].media);
            trovato = 1;
            break;
        }
    }

    if(!trovato) {
        printf("Studente non trovato.\n");
    }
}

void visualizzaTutteMedie(Studente studenti[]) {
    printf("\nMedie di tutti gli studenti:\n");
    for(int i = 0; i < STUDENTI; i++) {
        printf("%s %s: %.2f\n", studenti[i].nome, studenti[i].cognome, studenti[i].media);
    }
}

void visualizzaStudentiSopraMedia(Studente studenti[]) {
    printf("\nStudenti con media >= 6:\n");
    for(int i = 0; i < STUDENTI; i++) {
        if(studenti[i].media >= 6) {
            printf("%s %s: %.2f\n", studenti[i].nome, studenti[i].cognome, studenti[i].media);
        }
    }
}

void visualizzaStudentiSottoMedia(Studente studenti[]) {
    printf("\nStudenti con media < 6:\n");
    for(int i = 0; i < STUDENTI; i++) {
        if(studenti[i].media < 6) {
            printf("%s %s: %.2f\n", studenti[i].nome, studenti[i].cognome, studenti[i].media);
        }
    }
}

void menu() {
    printf("\nMenu:\n");
    printf("1- Stampa media dei voti con nome e cognome degli alunni\n");
    printf("2- Visualizzazione della media di un alunno specifico\n");
    printf("3- Visualizzazione della media di tutti gli alunni\n");
    printf("4- Visualizzazione dei dati degli alunni con voto >= 6\n");
    printf("5- Visualizzazione dei dati degli alunni con voto < 6\n");
    printf("6- Uscita dal programma\n");
}

int main() {
    Studente studenti[STUDENTI];
    int scelta;

    inserisciDati(studenti);
    calcolaMedie(studenti);

    do {
        menu();
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        switch(scelta) {
            case 1:
                stampaMedie(studenti);
                break;
            case 2:
                visualizzaMediaStudente(studenti);
                break;
            case 3:
                visualizzaTutteMedie(studenti);
                break;
            case 4:
                visualizzaStudentiSopraMedia(studenti);
                break;
            case 5:
                visualizzaStudentiSottoMedia(studenti);
                break;
            case 6:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Opzione non valida. Riprova.\n");
        }
    } while(scelta != 6);

    return 0;
}


