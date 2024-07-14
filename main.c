#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

FILE *f;

int opcija, opcijaRada, pomak, i, j, datotekaPostoji;
char tekst[10000], znak, smece, kljuc[16], imeDatoteke[30];
char naslov[] = "\n------- ---    -- --  ------  ---    ---  -----\n"
                "--      ----   -- -- --       ----  ---- --   --\n"
                "-----   -- --  -- -- --   --- -- ---- -- -------\n"
                "--      --  -- -- -- --    -- --  --  -- --   --\n"
                "------- --   ---- --  ------  --      -- --   --\n\n"
                "                  Mara & Jipp";

int main(void) {
  while (1) {
    system("cls");
    printf("%s", naslov);
    printf("\n\n Izbornik:");
    printf("\n\t1. Enkripcija");
    printf("\n\t2. Dekripcija");
    printf("\n\t3. Ispis");
    printf("\n\t0. Kraj\n");
    printf("\n >> ");
    scanf("%d", &opcija);
    scanf("%c", &smece);

    switch (opcija) {
    case 1:
      // ENKRIPCIJA
      system("cls");
      printf("%s", naslov);
      printf("\n\n Izbornik:");
      printf("\n\t1. Cezarova sifra");
      printf("\n\t2. Vigenereova sifra");
      printf("\n\t3. ROT13");
      printf("\n\t4. Atbash sifra");
      printf("\n\t0. Kraj\n");
      printf("\n >> ");
      scanf("%d", &opcijaRada);
      scanf("%c", &smece);

      switch (opcijaRada) {

      // Cezarova sifra
      case 1:
        system("cls");
        printf("%s", naslov);

        printf("\nIme datoteke");
        printf("\n >> ");
        scanf("%[^\n]", imeDatoteke);
        strcat(imeDatoteke, ".txt");

        scanf("%c", &smece);

        printf("\nTekst");
        printf("\n >> ");
        scanf("%[^\n]", tekst);

        printf("\nPomak");
        printf("\n >> ");
        scanf("%d", &pomak);

        i = 0;
        for (i = 0; tekst[i] != '\0'; ++i) {
          znak = tekst[i];
          if (isalnum(znak)) {
            if (islower(znak)) {
              znak = (znak - 'a' + pomak) % 26 + 'a';
            }
            if (isupper(znak)) {
              znak = (znak - 'A' + pomak) % 26 + 'A';
            }
            if (isdigit(znak)) {
              znak = (znak - '0' + pomak) % 10 + '0';
            }
          }
          tekst[i] = znak;
        }
        tekst[i] = '\0';

        f = fopen(imeDatoteke, "w+");
        fprintf(f, "%s\n", tekst);
        fclose(f);

        printf("\nGotovo, za dvije sekunde Vas vracamo do pocetnog izbornika.");
        sleep(2);

        continue;
      // Vigenereova sifra
      case 2:
        system("cls");
        printf("%s", naslov);

        printf("\nIme datoteke");
        printf("\n >> ");
        scanf("%[^\n]", imeDatoteke);
        strcat(imeDatoteke, ".txt");

        scanf("%c", &smece);

        printf("\nTekst");
        printf("\n >> ");
        scanf("%[^\n]", &tekst);

        printf("\nKljuc");
        printf("\n >> ");
        scanf("%s", &kljuc);

        i = 0;
        j = 0;
        for (i = 0; tekst[i] != '\0'; i++) {
          char znak = tekst[i];
          if (isalpha(znak)) {
            if (j >= strlen(kljuc)) {
              j = 0;
            }
            pomak = toupper(kljuc[j]) - 'A';
            if (isupper(znak)) {
              tekst[i] = ((znak - 'A' + pomak) % 26) + 'A';
            } else {
              tekst[i] = ((znak - 'a' + pomak) % 26) + 'a';
            }
            j++;
          }
        }
        tekst[i] = '\0';

        f = fopen(imeDatoteke, "w+");
        fprintf(f, "%s\n", tekst);
        fclose(f);

        printf("\nGotovo, za dvije sekunde Vas vracamo do pocetnog izbornika.");
        sleep(2);

        continue;
      // ROT13
      case 3:
        system("cls");
        printf("%s", naslov);

        printf("\nIme datoteke");
        printf("\n >> ");
        scanf("%[^\n]", imeDatoteke);
        strcat(imeDatoteke, ".txt");

        scanf("%c", &smece);

        printf("\nTekst");
        printf("\n >> ");
        scanf("%[^\n]", &tekst);

        i = 0;
        for (i = 0; tekst[i] != '\0'; i++) {
          char znak = tekst[i];
          if (isalpha(znak)) {
            if (isupper(znak)) {
              tekst[i] = ((znak - 'A' + 13) % 26) + 'A';
            } else {
              tekst[i] = ((znak - 'a' + 13) % 26) + 'a';
            }
          }
        }
        tekst[i] = '\0';

        f = fopen(imeDatoteke, "w+");
        fprintf(f, "%s\n", tekst);
        fclose(f);

        printf("\nGotovo, za dvije sekunde Vas vracamo do pocetnog izbornika.");
        sleep(2);

        continue;
      // Atbash
      case 4:
        system("cls");
        printf("%s", naslov);

        printf("\nIme datoteke");
        printf("\n >> ");
        scanf("%[^\n]", imeDatoteke);
        strcat(imeDatoteke, ".txt");

        scanf("%c", &smece);

        printf("\nTekst");
        printf("\n >> ");
        scanf("%[^\n]", &tekst);

        i = 0;
        for (i = 0; tekst[i] != '\0'; i++) {
          if (isalpha(tekst[i])) {
            if (isupper(tekst[i])) {
              tekst[i] = 'Z' - (tekst[i] - 'A');
            } else {
              tekst[i] = 'z' - (tekst[i] - 'a');
            }
          }
        }
        tekst[i] = '\0';

        f = fopen(imeDatoteke, "w+");
        fprintf(f, "%s\n", tekst);
        fclose(f);

        printf("\nGotovo, za dvije sekunde Vas vracamo do pocetnog izbornika.");
        sleep(2);

        continue;
      case 0:
        printf("\n Hvala Vam sto ste koristili Projekt Enigma!");
        sleep(1);
        exit(1);

      default:
        printf("\n Opcija nije moguca!");
        sleep(1);
        continue;
      }
      opcija = 0;
      opcijaRada = 0;

    case 2:
      // DEKRIPCIJA
      system("cls");
      printf("%s", naslov);
      printf("\n\n Izbornik:");
      printf("\n\t1. Cezarova sifra");
      printf("\n\t2. Vigenereova sifra");
      printf("\n\t3. ROT13");
      printf("\n\t4. Atbash sifra");
      printf("\n\t0. Kraj\n");
      printf("\n >> ");
      scanf("%d", &opcijaRada);
      scanf("%c", &smece);

      switch (opcijaRada) {
      // Cezarova sifra
      case 1:
        system("cls");
        printf("%s", naslov);

        printf("\nIme datoteke");
        printf("\n >> ");
        scanf("%[^\n]", imeDatoteke);
        strcat(imeDatoteke, ".txt");

        scanf("%c", &smece);

        f = fopen(imeDatoteke, "r+");
        if (f != NULL) {
          datotekaPostoji = 1;
        } else {
          datotekaPostoji = 0;
        }
        fclose(f);

        if (datotekaPostoji == 0) {

          printf("\nTekst");
          printf("\n >> ");
          scanf("%[^\n]", tekst);

          printf("\nPomak");
          printf("\n >> ");
          scanf("%d", &pomak);

          i = 0;
          for (i = 0; tekst[i] != '\0'; ++i) {
            znak = tekst[i];
            if (isalnum(znak)) {
              if (islower(znak)) {
                znak = (znak - 'a' - pomak + 26) % 26 + 'a';
              }
              if (isupper(znak)) {
                znak = (znak - 'A' - pomak + 26) % 26 + 'A';
              }
              if (isdigit(znak)) {
                znak = (znak - '0' - pomak + 10) % 10 + '0';
              }
            }
            tekst[i] = znak;
          }
          tekst[i] = '\0';
        } else {
          f = fopen(imeDatoteke, "r+");
          i = 0;
          while ((znak = fgetc(f)) != EOF) {
            if (znak != '\n') {
              tekst[i++] = znak;
            }
          }
          tekst[i] = '\0';
          fclose(f);

          printf("\nPomak");
          printf("\n >> ");
          scanf("%d", &pomak);

          i = 0;
          for (i = 0; tekst[i] != '\0'; ++i) {
            znak = tekst[i];
            if (isalnum(znak)) {
              if (islower(znak)) {
                znak = (znak - 'a' - pomak + 26) % 26 + 'a';
              }
              if (isupper(znak)) {
                znak = (znak - 'A' - pomak + 26) % 26 + 'A';
              }
              if (isdigit(znak)) {
                znak = (znak - '0' - pomak + 10) % 10 + '0';
              }
            }
            tekst[i] = znak;
          }
          tekst[i] = '\0';
        }

        f = fopen(imeDatoteke, "w+");
        fprintf(f, "%s\n", tekst);
        fclose(f);

        printf("\nGotovo, za dvije sekunde Vas vracamo do pocetnog izbornika.");
        sleep(2);

        continue;
      // Vigenereova sifra
      case 2:
        system("cls");
        printf("%s", naslov);

        printf("\nIme datoteke");
        printf("\n >> ");
        scanf("%[^\n]", imeDatoteke);
        strcat(imeDatoteke, ".txt");

        scanf("%c", &smece);

        f = fopen(imeDatoteke, "r+");
        if (f != NULL) {
          datotekaPostoji = 1;
        } else {
          datotekaPostoji = 0;
        }
        fclose(f);

        if (datotekaPostoji == 0) {
          printf("\nTekst");
          printf("\n >> ");
          scanf("%[^\n]", &tekst);

          scanf("%c", &smece);

          printf("\nKljuc");
          printf("\n >> ");
          scanf("%[^\n]", &kljuc);

          scanf("%c", &smece);

          i = 0;
          j = 0;
          for (i = 0; tekst[i] != '\0'; i++) {
            char znak = tekst[i];
            if (isalpha(znak)) {
              if (j >= strlen(kljuc)) {
                j = 0;
              }
              pomak = toupper(kljuc[j]) - 'A';
              if (isupper(znak)) {
                tekst[i] = ((znak - 'A' - pomak + 26) % 26) + 'A';
              } else {
                tekst[i] = ((znak - 'a' - pomak + 26) % 26) + 'a';
              }
              j++;
            }
          }
          tekst[i] = '\0';
        } else {
          f = fopen(imeDatoteke, "r+");
          i = 0;
          while ((znak = fgetc(f)) != EOF) {
            if (znak != '\n') {
              tekst[i++] = znak;
            }
          }
          tekst[i] = '\0';
          fclose(f);

          printf("\nKljuc");
          printf("\n >> ");
          scanf("%[^\n]", kljuc);

          i = 0;
          j = 0;
          for (i = 0; tekst[i] != '\0'; i++) {
            znak = tekst[i];
            if (isalpha(znak)) {
              if (j >= strlen(kljuc)) {
                j = 0;
              }
              pomak = toupper(kljuc[j]) - 'A';
              if (isupper(znak)) {
                tekst[i] = ((znak - 'A' - pomak + 26) % 26) + 'A';
              } else {
                tekst[i] = ((znak - 'a' - pomak + 26) % 26) + 'a';
              }
              j++;
            }
          }
          tekst[i] = '\0';
        }

        f = fopen(imeDatoteke, "w+");
        fprintf(f, "%s\n", tekst);
        fclose(f);

        printf("\nGotovo, za dvije sekunde Vas vracamo do pocetnog izbornika.");
        sleep(2);

        continue;
      // ROT13
      case 3:
        system("cls");
        printf("%s", naslov);

        printf("\nIme datoteke");
        printf("\n >> ");
        scanf("%[^\n]", imeDatoteke);
        strcat(imeDatoteke, ".txt");

        scanf("%c", &smece);

        f = fopen(imeDatoteke, "r+");
        if (f != NULL) {
          datotekaPostoji = 1;
        } else {
          datotekaPostoji = 0;
        }
        fclose(f);

        if (datotekaPostoji == 0) {
          printf("\nTekst");
          printf("\n >> ");
          scanf("%[^\n]", &tekst);

          scanf("%c", &smece);

          i = 0;
          for (i = 0; tekst[i] != '\0'; i++) {
            char znak = tekst[i];
            if (isalpha(znak)) {
              if (isupper(znak)) {
                tekst[i] = ((znak - 'A' + 13) % 26) + 'A';
              } else {
                tekst[i] = ((znak - 'a' + 13) % 26) + 'a';
              }
            }
          }
          tekst[i] = '\0';
        }

        else {
          f = fopen(imeDatoteke, "r+");
          i = 0;
          while ((znak = fgetc(f)) != EOF) {
            if (znak != '\n') {
              tekst[i++] = znak;
            }
          }
          tekst[i] = '\0';
          fclose(f);

          i = 0;
          for (i = 0; tekst[i] != '\0'; i++) {
            char znak = tekst[i];
            if (isalpha(znak)) {
              if (isupper(znak)) {
                tekst[i] = ((znak - 'A' + 13) % 26) + 'A';
              } else {
                tekst[i] = ((znak - 'a' + 13) % 26) + 'a';
              }
            }
          }
          tekst[i] = '\0';
        }

        f = fopen(imeDatoteke, "w+");
        fprintf(f, "%s\n", tekst);
        fclose(f);

        printf("\nGotovo, za dvije sekunde Vas vracamo do pocetnog izbornika.");
        sleep(2);

        continue;
      // Atbash
      case 4:
        system("cls");
        printf("%s", naslov);

        printf("\nIme datoteke");
        printf("\n >> ");
        scanf("%[^\n]", imeDatoteke);
        strcat(imeDatoteke, ".txt");

        scanf("%c", &smece);

        f = fopen(imeDatoteke, "r+");
        if (f != NULL) {
          datotekaPostoji = 1;
        } else {
          datotekaPostoji = 0;
        }
        fclose(f);

        if (datotekaPostoji == 0) {
          printf("\nTekst");
          printf("\n >> ");
          scanf("%[^\n]", &tekst);

          scanf("%c", &smece);

          i = 0;
          for (i = 0; tekst[i] != '\0'; i++) {
            if (isalpha(tekst[i])) {
              if (isupper(tekst[i])) {
                tekst[i] = 'Z' - (tekst[i] - 'A');
              } else {
                tekst[i] = 'z' - (tekst[i] - 'a');
              }
            }
          }
          tekst[i] = '\0';
        } else {
          f = fopen(imeDatoteke, "r+");
          i = 0;
          while ((znak = fgetc(f)) != EOF) {
            if (znak != '\n') {
              tekst[i++] = znak;
            }
          }
          tekst[i] = '\0';
          fclose(f);

          i = 0;
          for (i = 0; tekst[i] != '\0'; i++) {
            if (isalpha(tekst[i])) {
              if (isupper(tekst[i])) {
                tekst[i] = 'Z' - (tekst[i] - 'A');
              } else {
                tekst[i] = 'z' - (tekst[i] - 'a');
              }
            }
          }
          tekst[i] = '\0';
        }

        f = fopen(imeDatoteke, "w+");
        fprintf(f, "%s\n", tekst);
        fclose(f);

        printf("\nGotovo, za dvije sekunde Vas vracamo do pocetnog izbornika.");
        sleep(2);

        continue;
      case 0:
        printf("\n Hvala Vam sto ste koristili Projekt Enigma!");
        sleep(1);
        exit(1);

      default:
        printf("\n Opcija nije moguca!");
        sleep(1);
        continue;
      }
      opcija = 0;
      opcijaRada = 0;

    case 3:
      system("cls");
      printf("%s", naslov);

      printf("\nIme datoteke");
      printf("\n >> ");
      scanf("%[^\n]", imeDatoteke);
      strcat(imeDatoteke, ".txt");

      scanf("%c", &smece);

      f = fopen(imeDatoteke, "r+");
      if (f != NULL) {
        datotekaPostoji = 1;
      } else {
        datotekaPostoji = 0;
      }
      fclose(f);

      if (datotekaPostoji == 0) {
        printf("\n Datoteka ne postoji.");
        sleep(1);
        continue;
      } else {
        f = fopen(imeDatoteke, "r+");
        i = 0;
        while ((znak = fgetc(f)) != EOF) {
          if (znak != '\n') {
            tekst[i++] = znak;
          }
        }
        tekst[i] = '\0';
        fclose(f);

        printf("\n%s", tekst);
        sleep(2);
        continue;
      }

    case 0:
      printf("\n Hvala Vam sto ste koristili Projekt Enigma!");
      sleep(1);
      exit(1);

    default:
      printf("\n Opcija nije moguca!");
      sleep(1);
      continue;
    }
  }
}