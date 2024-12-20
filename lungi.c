#include <stdio.h>

#include <string.h>

void adunare(int n, char a[], char b[], char rezultat[]) {

  int i, a_reala, a_imaginara, b_reala, b_imaginara, im, r;
  int c;
  a_reala = 0;
  a_imaginara = 0;
  b_reala = 0;
  b_imaginara = 0;
  //separ sirul in parte reala si imaginara, folosind pozitiile caracterelor
  //si transform in numere intregi
  for (i = 1; i < (n - 1) / 2; i++) {
    a_reala = a_reala * 10 + (a[i]) - '0';
  }
  for (i = (n - 1) / 2 + 1; i < n - 1; i++) {
    a_imaginara = a_imaginara * 10 + (a[i]) - '0';
  }
  if (a[0] == '1')
    a_reala = a_reala * (-1);
  if (a[(n - 1) / 2] == '1')
    a_imaginara = a_imaginara * (-1);

  for (i = 1; i < (n - 1) / 2; i++) {
    b_reala = b_reala * 10 + (b[i]) - '0';
  }
  for (i = (n - 1) / 2 + 1; i < n - 1; i++) {
    b_imaginara = b_imaginara * 10 + (b[i]) - '0';
  }
  if (b[0] == '1')
    b_reala = b_reala * (-1);
  if (b[(n - 1) / 2] == '1')
    b_imaginara = b_imaginara * (-1);

  //efectuez operatia de adunare
  r = a_reala + b_reala;
  im = a_imaginara + b_imaginara;

  //verific numarul de cifre

  int cr = r;
  int cim = im;
  int nrcif1 = 0, nrcif2 = 0;
  if (cr == 0)
    nrcif1 = 1;
  while (cr) {
    nrcif1++;
    cr = cr / 10;
  }
  if (cim == 0)
    nrcif2 = 1;
  while (cim) {
    nrcif2++;
    cim = cim / 10;
  }
  //daca depaseste bitii pe care trebuie sa ma incadrez,scap de prima cifra
  if (nrcif1 > (n - 2) / 2) {
    int ten = 1;
    for (i = 0; i < (nrcif1 - 1); i++) {
      ten = ten * 10;
    }
    r = r % ten;
  }
  if (nrcif2 > (n - 2) / 2) {
    int ten = 1;
    for (i = 0; i < (nrcif2 - 1); i++) {
      ten = ten * 10;
    }
    im = im % ten;
  }
  //incep sa transform inapoi in sir de caractere
  //apoi afisez
  if (r < 0) {
    rezultat[0] = '1';
  } else {
    rezultat[0] = '0';
  }
  if (im < 0) {
    rezultat[(n - 1) / 2] = '1';
  } else {
    rezultat[(n - 1) / 2] = '0';
  }

  if (r < 0)
    r = r * (-1);
  if (im < 0)
    im = im * (-1);

  for (i = (n - 1) / 2 - 1; i > 0; i--) {
    c = r % 10;
    rezultat[i] = c + '0';
    r = r / 10;
  }

  for (i = (n - 2); i > (n - 1) / 2; i--) {
    c = im % 10;
    rezultat[i] = c + '0';
    im = im / 10;
  }

  for (i = 0; i < n - 1; i++) {
    printf("%c", rezultat[i]);
  }
  printf("\n");
}

//aplic acelasi algoritm si pentru scadere
//doar ca acum efectuez scaderea
void scadere(int n, char a[], char b[], char rezultat[]) {
  int i, a_reala, a_imaginara, b_reala, b_imaginara, im, r;
  int c;
  a_reala = 0;
  a_imaginara = 0;
  b_reala = 0;
  b_imaginara = 0;
  for (i = 1; i < (n - 1) / 2; i++) {
    a_reala = a_reala * 10 + (a[i]) - '0';
  }
  for (i = (n - 1) / 2 + 1; i < n - 1; i++) {
    a_imaginara = a_imaginara * 10 + (a[i]) - '0';
  }
  if (a[0] == '1')
    a_reala = a_reala * (-1);
  if (a[(n - 1) / 2] == '1')
    a_imaginara = a_imaginara * (-1);

  for (i = 1; i < (n - 1) / 2; i++) {
    b_reala = b_reala * 10 + (b[i]) - '0';
  }
  for (i = (n - 1) / 2 + 1; i < n - 1; i++) {
    b_imaginara = b_imaginara * 10 + (b[i]) - '0';
  }
  if (b[0] == '1')
    b_reala = b_reala * (-1);
  if (b[(n - 1) / 2] == '1')
    b_imaginara = b_imaginara * (-1);

  r = a_reala - b_reala;
  im = a_imaginara - b_imaginara;

  int cr = r;
  int cim = im;
  int nrcif1 = 0, nrcif2 = 0;
  if (cr == 0)
    nrcif1 = 1;
  while (cr) {
    nrcif1++;
    cr = cr / 10;
  }
  if (cim == 0)
    nrcif2 = 1;
  while (cim) {
    nrcif2++;
    cim = cim / 10;
  }

  if (nrcif1 > (n - 2) / 2) {
    int ten = 1;
    for (i = 0; i < (nrcif1 - 1); i++) {
      ten = ten * 10;
    }
    r = r % ten;
  }
  if (nrcif2 > (n - 2) / 2) {
    int ten = 1;
    for (i = 0; i < (nrcif2 - 1); i++) {
      ten = ten * 10;
    }
    im = im % ten;
  }

  if (r < 0) {
    rezultat[0] = '1';
  } else {
    rezultat[0] = '0';
  }
  if (im < 0) {
    rezultat[(n - 1) / 2] = '1';
  } else {
    rezultat[(n - 1) / 2] = '0';
  }

  if (r < 0)
    r = r * (-1);
  if (im < 0)
    im = im * (-1);

  for (i = (n - 1) / 2 - 1; i > 0; i--) {
    c = r % 10;
    rezultat[i] = c + '0';
    r = r / 10;
  }

  for (i = (n - 2); i > (n - 1) / 2; i--) {
    c = im % 10;
    rezultat[i] = c + '0';
    im = im / 10;
  }

  for (i = 0; i < n - 1; i++) {
    printf("%c", rezultat[i]);
  }
  printf("\n");
}

int main() {
  int n;
  char rezultat[1001] = "", a[1001], b[1001];
  char operatie;
  //citesc datele astfel incat sa poata intra in loop
  //o sa suprascriu textul dupa fiecare apel al functiilor, pentru a putea retine rezultatul operatiilor in prima variabila
  scanf("%d", & n);
  scanf("%s", a);
  scanf(" %c", & operatie);
  while (operatie != '0') {
    scanf(" %s", b);
    strcpy(rezultat, a);
    if (operatie == '+') {
      adunare(n, a, b, rezultat);
      strcpy(a, rezultat);
    } else {
      scadere(n, a, b, rezultat);
      strcpy(a, rezultat);
    }
    scanf(" %c", & operatie);
  }
}
