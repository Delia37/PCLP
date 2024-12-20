#include <stdio.h>

#include <string.h>

#include <stdlib.h>

void codificareA(char text[], char cuvant[], char rezultat[]) {
  int c, l, i, j;
  c = strlen(cuvant);
  l = strlen(text) / strlen(cuvant) + 1;
  i = 0;
  int k = -1;
  char copie[100];
  //fac o copie a textului pentru a nu pierde valori cand prelucrez matricea
  strcpy(copie, text);
  //formez matricea
  char matrice[l][c];
  //adaug spatiile
  for (i = strlen(text) - 1; i < l * c; i++) {
    copie[i] = ' ';
  }
  //prima linie
  i = 0;
  for (j = 0; j < c; j++) {
    matrice[i][j] = cuvant[j];
  }
  //restul matricei
  for (i = 1; i < l; i++) {
    for (j = 0; j < c; j++) {
      matrice[i][j] = copie[++k];
    }
  }

  //creez un vector care va retine pozitiile caracterelor din cuvantul cheie
  i = 0;
  char aux;
  int v[100];
  for (i = 0; i < c; i++) {
    v[i] = i;
  }
  //sortez indicii din vector in functie de valorile din matrice si sortez si prima linie din matrice totodata
  for (k = 0; k < c - 1; k++) {
    for (j = k + 1; j < c; j++) {
      if (matrice[0][k] > matrice[0][j]) {
        aux = v[k];
        v[k] = v[j];
        v[j] = aux;
        aux = matrice[0][k];
        matrice[0][k] = matrice[0][j];
        matrice[0][j] = aux;
      }
    }
  }

  //afisare
  k = 0;
  for (j = 0; j < c; j++) {
    for (i = 1; i < l; i++) {
      printf("%c", matrice[i][v[j]]);
      rezultat[k++] = matrice[i][v[j]];
    }

  }
  printf("\n");
}
//analog si pentru decodificare
void decodificareA(char text[], char cuvant[], char rezultat[]) {
  int c, l, i, j;
  c = strlen(cuvant);
  l = strlen(text) / strlen(cuvant) + 1;
  i = 0;
  int k = -1;
  //formez matricea
  char matrice[l][c];
  char copie[100];
  strcpy(copie, text);
  //prima linie
  i = 0;
  for (j = 0; j < c; j++) {
    matrice[i][j] = cuvant[j];
  }
  //restul matricei
  for (j = 0; j < c; j++) {
    for (i = 1; i < l; i++) {
      //matrice[i][j]=text[++k];
      matrice[i][j] = copie[++k];
    }
  }
  //vectorul de poizitii+sortare
  i = 0;
  char aux;
  int v[100], w[100];
  for (i = 0; i < c; i++) {
    v[i] = i;
  }
  for (k = 0; k < c - 1; k++) {
    for (j = k + 1; j < c; j++) {
      if (matrice[0][k] > matrice[0][j]) {
        aux = v[k];
        v[k] = v[j];
        v[j] = aux;
        aux = matrice[0][k];
        matrice[0][k] = matrice[0][j];
        matrice[0][j] = aux;
      }
    }
  }
  //retin pozitiile care-mi trebuie intr-un alt vector, w
  for (i = 0; i < c; i++) {
    for (j = 0; j < c; j++) {
      if (v[j] == i)
        w[i] = j;
    }
  }
  //afisare
  k = 0;
  for (i = 1; i < l; i++) {
    for (j = 0; j < c; j++) {
      printf("%c", matrice[i][w[j]]);
      rezultat[k++] = matrice[i][w[j]];
    }
  }
  printf("\n");

}

void codificareB(int n, char text[], char rezultat[]) {
  int d;
  char s2[51];
  d = strlen(text);
  int i, j;
  j = 0;
  for (i = d - n; i < d; i++) {
    rezultat[j] = text[i]; //pun in fata sirulde modificat
    s2[j++] = text[i]; //il pastrez in s2
  }
  for (i = 0; i < (d - n); i++) {
    rezultat[j++] = text[i]; //in continuare pun ce ramane la fel
  }
  //modific sirul adaugand cod ASCII
  for (i = 0; i < n; i++) {
    if (s2[i] != ' ') {
      if (s2[i] >= 'a' && s2[i] <= 'z' - n) {
        s2[i] += n;
      } else if (s2[i] > 'z' - n) {
        s2[i] = s2[i] + n - 57;
      } else if (s2[i] >= 'A' && s2[i] <= 'Z' - n) {
        s2[i] += n;
      } else if (s2[i] > 'Z' - n) {
        s2[i] = s2[i] + n + 7;
      }
    }
    rezultat[i] = s2[i];
  }
  //afisez
  for (i = 0; i < d; i++) {
    printf("%c", rezultat[i]);
  }
  printf("\n");
}

//la fel si pentru decodificare
void decodificareB(int n, char text[], char rezultat[]) {
  int d;
  char s1[51];
  d = strlen(text) - 1;
  int i, j;
  j = 0;
  for (i = 0; i < n; i++) {
    s1[i] = text[i]; //in s1 pastrez ce trebuie modificat
  }
  for (i = n; i < d; i++) {
    rezultat[j++] = text[i]; //in s2 pastrez ce ramane la fel
  }

  //modific sirul, dar acum scad ASCII
  for (i = 0; i < n; i++) {
    if (s1[i] != ' ') {
      if (s1[i] >= 'a' + n && s1[i] <= 'z') {
        s1[i] -= n;
      } else if (s1[i] < 'a' + n) {
        s1[i] = s1[i] - n + 57;
      } else if (s1[i] >= 'A' + n && s1[i] <= 'Z') {
        s1[i] -= n;
      } else if (s1[i] > 'A' + n) {
        s1[i] = s1[i] - n - 7;
      }
    }
    rezultat[j++] = s1[i];
  }

  for (i = 0; i < d; i++) {
    printf("%c", rezultat[i]);
  }
  printf("\n");

}

void main() {
  char text[501], rezultat[501];
  char codificare[50] = "";
  int n;
  char key[51];
  fgets(text, 100, stdin);
  scanf(" %s", codificare);
  while (strcmp(codificare, "STOP") != 0) {
    if (strcmp(codificare, "CodificareA") == 0) {
      scanf(" %s", key);
      codificareA(text, key, rezultat);
      strcpy(text, rezultat); //copiez rezutatul codificat peste textul orginal pt folosire mai departe
    }
    if (strcmp(codificare, "DecodificareA") == 0) {
      scanf(" %s", key);
      decodificareA(text, key, rezultat);
      strcpy(text, rezultat);
    }
    if (strcmp(codificare, "CodificareB") == 0) {
      scanf(" %d", & n);
      codificareB(n, text, rezultat);
      strcpy(text, rezultat);
    }
    if (strcmp(codificare, "DecodificareB") == 0) {
      scanf(" %d", & n);
      decodificareB(n, text, rezultat);
      strcpy(text, rezultat);
    }
    scanf(" %s", codificare);
  }
}