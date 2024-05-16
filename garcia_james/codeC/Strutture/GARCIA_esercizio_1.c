#include <stdio.h>
#include <string.h>
#define MAX_NAME 30
#define MAX_t 20


struct animale {
    char nome[MAX_NAME];
    char tipo[MAX_t];
    int peso;
    struct data
    {
        int giorno;
        char mese[12];
        int anno;
    }data_nascita;
    
}animale1, animale2;
int main(void){

   
        strcpy(animale1.nome,"asia");
        strcpy(animale1.tipo,"labrador");
        animale1.peso = 45;
        animale1.data_nascita.giorno = 14;
        strcpy(animale1.data_nascita.mese,"novembre");
        animale1.data_nascita.anno = 2014;

        strcpy(animale2.nome,"spank");
        strcpy(animale2.tipo,"maltese");
        animale2.peso = 12;
        animale2.data_nascita.giorno = 19;
        strcpy(animale2.data_nascita.mese,"settembre");
        animale2.data_nascita.anno = 2018;

    
        printf("Il primo animale:\n");
        printf("Nome: %s\n", animale1.nome);
        printf("Tipo: %s\n", animale1.tipo);
        printf("Peso: %d\n", animale1.peso);
        printf("Data di nascita: %d %s %d\n", animale1.data_nascita.giorno, animale1.data_nascita.mese, animale1.data_nascita.anno);

        printf("\n");

        printf("Il secondo animale:\n");
        printf("Nome: %s\n", animale2.nome);
        printf("Tipo: %s\n", animale2.tipo);
        printf("Peso: %d\n", animale2.peso);
        printf("Data di nascita: %d %s %d\n", animale2.data_nascita.giorno, animale2.data_nascita.mese, animale2.data_nascita.anno);
return 0;
}