#include <stdio.h>

#include <string.h>

void eliberat(int p, int cutii[]) {
  int i, j;
  int nr = 0;
  //fiecare frizonier incepe sa isi verifice cutiile
  for (int prizonier = 0; prizonier < p; prizonier++) {
    //retin pozitia prizonierului in j pentru a putea verifica daca si-a gasit numarul in cutie
    j = prizonier;
    //fiecare prizonier are dreptul sa incerce jumatate din cutii
    for (i = 0; i < p / 2; i++) {
      if (cutii[j] - 1 == prizonier) {
        nr = nr + 1; //daca si-a gasit numarul, il numarar si trec la urmatorul prizonier
        break;
      } else {
        j = cutii[j] - 1; //altfel, continua sa caute
      }
    }
  }
  //daca toti prizonierii si-au gasit numarul, castiga
  if (nr == p) {
    printf("Da\n");
  } else {
    printf("Nu\n");
  }
}

void cicluri(int p, int v[]) {
  int viz[501], i, ciclu[501], urm, j;
  //nimic nu e vizitat initial
  for (i = 0; i < p; i++)
    viz[i] = 0;
  int k;//indicele vectorului de cicluri
  k = 0;
  for (i = 0; i < p; i++) {
    if (v[i] != i) {
      if (viz[i] == 0) {
        ciclu[k++] = i + 1;
        viz[i] = 1;
        urm = v[i] - 1;
        while (viz[urm] != 1) {
          ciclu[k++] = urm + 1;
          viz[urm] = 1;
          urm = v[urm] - 1;
        }
        printf("%d", ciclu[0]);
        for (j = 1; j < k; j++)
          printf(" %d", ciclu[j]);
        printf("\n");
        k = 0;//am terminat un ciclu si caut urmatorul daca mai exista, resetez k
      }
    }
  }

}

int main() {
  int p, v[501], i;
  scanf("%d", & p);
  for (i = 0; i < p; i++) {
    scanf("%d", & v[i]);
  }
  eliberat(p, v);
  cicluri(p, v);
}