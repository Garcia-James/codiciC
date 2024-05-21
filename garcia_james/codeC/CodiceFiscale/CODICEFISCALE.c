#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define DIM 100
#define CODICE_LENGTH 16




char codice[CODICE_LENGTH];


void cercaContenuto() {
   FILE *comuni;
   comuni = fopen("/home/jamesgarcia/Documents/codici_priv/garcia_james/codeC/CodiceFiscale/comuni.txt", "r");
   if (comuni == NULL) {
       printf("Impossibile aprire il file\n");
       return;
   }


   char chiave[5] = {codice[11], codice[12], codice[13], codice[14], '\0'};
   char line[DIM];


   while (fgets(line, DIM, comuni) != NULL) {
       if (strstr(line, chiave) != NULL) {
           int lunghezza = strlen(line);
           int inizio = 4;
           int lunghezza_desiderata = lunghezza - 5;


           if (lunghezza_desiderata < 0) {
               lunghezza_desiderata = 0;
           }


           char porzione[lunghezza_desiderata + 1];
           strncpy(porzione, line + inizio, lunghezza_desiderata);
           porzione[lunghezza_desiderata] = '\0';


           printf("Luogo di nascita e provincia: %s\n", porzione);
           fclose(comuni);
           return;
       }
   }


   printf("Contenuto non trovato nel file\n");
   fclose(comuni);
}


void cerca(const char *luogo_di_nascita, const char *provincia) {
   FILE *comuni;
   char contenuto[DIM];
   comuni = fopen("/home/jamesgarcia/Documents/codici_priv/garcia_james/codeC/CodiceFiscale/comuni.txt", "r");
   if (comuni == NULL) {
       printf("Errore apertura file\n");
       return;
   }
   while (fgets(contenuto, DIM, comuni) != NULL) {
       if (strstr(contenuto, luogo_di_nascita) != NULL && strstr(contenuto, provincia) != NULL) {
           for (int i = 11; i <= 14; i++) {
               codice[i] = contenuto[i - 11];
           }
           fclose(comuni);
           return;
       }
   }
   fclose(comuni);
}


int codice_cognome(void) {
   char cognome[DIM];
   int LEN = 0;
   char voc[5] = "", cons[5] = "";
   int v = 0, c = 0;
  
   printf("Inserire il cognome: \n");
   scanf("%s", cognome);
   LEN = strlen(cognome);


   for (int i = 0; i < LEN; i++) {
       cognome[i] = toupper(cognome[i]);
       switch (cognome[i]) {
       case 'A':
       case 'E':
       case 'I':
       case 'O':
       case 'U':
           voc[v] = cognome[i];
           v++;
           break;
       default:
           cons[c] = cognome[i];
           c++;
           break;
       }
   }
   voc[v] = '\0';
   cons[c] = '\0';


   if (c >= 3) {
       for (int i = 0; i < 3; i++) {
           codice[i] = cons[i];
       }
   }
   else if (c == 2 && v >= 1) {
       codice[0] = cons[0];
       codice[1] = cons[1];
       codice[2] = voc[0];
   }
   else if (c == 1 && v >= 2) {
       codice[0] = cons[0];
       codice[1] = voc[0];
       codice[2] = voc[1];
   }
   else if (c == 0 && v >= 3) {
       codice[0] = voc[0];
       codice[1] = voc[1];
       codice[2] = voc[2];
   }
   else if (c == 1 && v == 1) {
       codice[0] = cons[0];
       codice[1] = voc[0];
       codice[2] = 'X';
   }
   else if (c == 0 && v == 2) {
       codice[0] = voc[0];
       codice[1] = voc[1];
       codice[2] = 'X';
   }
   else {
       printf("Errore nel calcolo del codice fiscale (cognome).\n");
       return 1;
   }


   return 0;
}


int codice_nome(void) {
   char nome[DIM];
   char voc[DIM] = "", cons[DIM] = "";
   int v = 0, c = 0;


   printf("Inserire il nome: \n");
   scanf("%s", nome);


   for (int i = 0; i < strlen(nome); i++) {
       nome[i] = toupper(nome[i]);
       switch (nome[i]) {
       case 'A':
       case 'E':
       case 'I':
       case 'O':
       case 'U':
           voc[v] = nome[i];
           v++;
           break;
       default:
           cons[c] = nome[i];
           c++;
           break;
       }
   }
   voc[v] = '\0';
   cons[c] = '\0';


   if (c > 3) {
       codice[3] = cons[0];
       codice[4] = cons[2];
       codice[5] = cons[3];
   }
   else if (c == 3) {
       codice[3] = cons[0];
       codice[4] = cons[1];
       codice[5] = cons[2];
   }
   else if (c == 2) {
       codice[3] = cons[0];
       codice[4] = cons[1];
       codice[5] = voc[0];
   }
   else if (c == 1 && v >= 2) {
       codice[3] = cons[0];
       codice[4] = voc[0];
       codice[5] = voc[1];
   }
   else if (c == 1 && v == 1) {
       codice[3] = cons[0];
       codice[4] = voc[0];
       codice[5] = 'X';
   }
   else if (c == 0 && v == 2) {
       codice[3] = voc[0];
       codice[4] = voc[1];
       codice[5] = 'X';
   }
   else {
       return 1;
   }


   return 0;
}


void calcola_caratteri_di_controllo(void) {
   int tableC[26] = {1, 0, 5, 7, 9, 13, 15, 17, 19, 21, 2, 4, 18, 20, 11, 3, 6, 8, 12, 14, 16, 10, 22, 25, 24, 23};
   char tableE[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


   int sum = 0;


   for (int i = 0; i < CODICE_LENGTH - 1; i++) {
       char c = codice[i];
       int index;


       if (i % 2 == 0) {
           if (c >= '0' && c <= '9') {
               index = c - '0';
           }
           else if (c >= 'A' && c <= 'Z') {
               index = c - 'A';
           }


           sum += tableC[index];
       }
       else {
           if (c >= '0' && c <= '9') {
               index = c - '0';
           }
           else if (c >= 'A' && c <= 'Z') {
               index = c - 'A';
           }


           sum += index;
       }
   }


   char checkDigit = tableE[sum % 26];


   codice[CODICE_LENGTH - 1] = checkDigit;
}


void stampa_mese(char mese) {
   switch (mese) {
       case 'A':
           printf("Gennaio");
           break;
       case 'B':
           printf("Febbraio");
           break;
       case 'C':
           printf("Marzo");
           break;
       case 'D':
           printf("Aprile");
           break;
       case 'E':
           printf("Maggio");
           break;
       case 'H':
           printf("Giugno");
           break;
       case 'L':
           printf("Luglio");
           break;
       case 'M':
           printf("Agosto");
           break;
       case 'P':
           printf("Settembre");
           break;
       case 'R':
           printf("Ottobre");
           break;
       case 'S':
           printf("Novembre");
           break;
       case 'T':
           printf("Dicembre");
           break;
       default:
           printf("Mese non valido");
           break;
   char provincia[DIM];

   }
}


void stampa_anno() {
   if (codice[6] == '0' || codice[6] == '1') {
       printf("20%c%c\n", codice[6], codice[7]);
   } else {
       printf("19%c%c\n", codice[6], codice[7]);
   }
}


void inverso_sesso(){
   if(codice[9]=='4' || codice[9]=='5' || codice[9]=='6' || codice[9]=='7'){
       printf("Sesso: F\n");
   }
   else {
       printf("Sesso: M\n");
   }
}


void inverso_giorno(){
   if(codice[9]=='4' || codice[9]=='5' || codice[9]=='6' || codice[9]=='7'){
       int giorno_F = atoi(&codice[9]);
       giorno_F -= 40;
       printf("Giorno nascita: %d \n", giorno_F);
   }
   else{
       printf("Giorno nascita: %c%c\n", codice[9], codice[10]);
   }
}


int bisestile(int anno) {
   return (anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0);
}


int main(void) {
   int scelta, giorno, mese, risposta, anno;
   char sesso[3];
   char nascita[DIM];
   char provincia[DIM];


   do {
       printf("\nMENU:\n 1.GENERA CODICE FISCALE\n 2.ESTRAI INFORMAZIONI\n 3.ESCI\n");
       scanf("%d", &scelta);


       switch (scelta) {
           case 1:
               codice_nome();
               codice_cognome();
              
               printf("Inserire il luogo di nascita: \n");
               getchar();
               fgets(nascita, DIM, stdin);
               nascita[strcspn(nascita, "\n")] = '\0';
               for (int i = 0; nascita[i]; i++) {
                   nascita[i] = toupper(nascita[i]);
               }


               printf("Inserire la provincia (INSERIRE 'EE' SE ESTERO): \n");
               fgets(provincia, DIM, stdin);
               provincia[strcspn(provincia, "\n")] = '\0';
               for (int i = 0; provincia[i]; i++) {
                   provincia[i] = toupper(provincia[i]);
               }
              
                               do {
                   printf("Inserire la data di nascita (gg/m/aaaa): \n");
                   scanf("%d/%d/%d", &giorno, &mese, &anno);
                   if (mese == 2) {
                       if (bisestile(anno)) {
                           if (giorno > 29) {
                               printf("Febbraio %d ha al massimo 29 giorni.\n", anno);
                               printf("Vuoi inserire la data nuovamente? (0 per no, 1 per sì): ");
                               scanf("%d", &risposta);
                           }
                       } else {
                           if (giorno > 28) {
                               printf("Febbraio %d ha al massimo 28 giorni.\n", anno);
                               printf("Vuoi inserire la data nuovamente? (0 per no, 1 per sì): ");
                               scanf("%d", &risposta);
                           }
                       }
                   } else if (mese == 4 || mese == 6 || mese == 9 || mese == 11) {
                       if (giorno > 30) {
                           printf("Il mese %d ha al massimo 30 giorni.\n", mese);
                           printf("Vuoi inserire la data nuovamente? (0 per no, 1 per sì): ");
                           scanf("%d", &risposta);
                       }
                   } else {
                       if (giorno > 31) {
                           printf("Il mese %d ha al massimo 31 giorni.\n", mese);
                           printf("Vuoi inserire la data nuovamente? (0 per no, 1 per sì): ");
                           scanf("%d", &risposta);
                       }
                   }
               } while (risposta == 1);
                  
               printf("Inserire sesso (M/F): \n");
               getchar();
               fgets(sesso, sizeof(sesso), stdin);
               sesso[strcspn(sesso, "\n")] = '\0';
               for (int i = 0; sesso[i]; i++) {
                   sesso[i] = toupper(sesso[i]);
               }
               if (strcmp(sesso, "M") != 0 && strcmp(sesso, "F") != 0) {
                   printf("Sesso non valido.\n");
                   break;
               }
               if (sesso[0] == 'F') {
                   giorno += 40;
               }
               sprintf(codice + 9, "%02d", giorno);
               cerca(nascita, provincia);


               sprintf(codice + 6, "%02d", (anno % 100));


               switch (mese) {
                   case 1:
                       codice[8] = 'A';
                       break;
                   case 2:
                       codice[8] = 'B';
                       break;
                   case 3:
                       codice[8] = 'C';
                       break;
                   case 4:
                       codice[8] = 'D';
                       break;
                   case 5:
                       codice[8] = 'E';
                       break;
                   case 6:
                       codice[8] = 'H';
                       break;
                   case 7:
                       codice[8] = 'L';
                       break;
                   case 8:
                       codice[8] = 'M';
                       break;
                   case 9:
                       codice[8] = 'P';
                       break;
                   case 10:
                       codice[8] = 'R';
                       break;
                   case 11:
                       codice[8] = 'S';
                       break;
                   case 12:
                       codice[8] = 'T';
                       break;
                   default:
                       printf("Mese non valido.\n");
                       break;
               }
               calcola_caratteri_di_controllo();
              
               printf("Il tuo codice fiscale è: ");


               for (int i = 0; i < CODICE_LENGTH; i++) {
                   printf("%c", codice[i]);
               }
               printf("\n");
               break;


           case 2:
               printf("Inserire codice fiscale: \n");
               scanf("%s", codice);
               for (int i = 0; codice[i]; i++) {
                   codice[i] = toupper(codice[i]);
               }
               printf("Nome: ");
               for (int i = 3; i < 6; i++) {
                   printf("%c", codice[i]);
               }
               printf("\n");
            
               printf("Cognome: ");
               for (int i = 0; i < 3; i++) {
                   printf("%c", codice[i]);
               }
               printf("\n");
               printf("Mese di nascita: ");
               stampa_mese(codice[8]);
               printf("\n");


               inverso_giorno();


               printf("Anno di nascita: ");
               stampa_anno();
               inverso_sesso();
               cercaContenuto();
               printf("\n");
               break;
       
            case 3:
                    printf("Arrivederci!\n");
                    break;

                default:
                    printf("Scelta non valida\n");
            }


   } while (scelta != 3);


   return 0;
}




