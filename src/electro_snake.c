#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

int dynamic(int ***a, int *n, int *m);
int input(int ***a, int n, int m);
void output(int **a, int n, int m);
int symbolCorrect(char symbol);
int sizeCorrect(int s);

void main() {
  int **matrix, **result;
  int n, m;

  if (dynamic(&matrix, &n, &m)) {
    sort_vertical(matrix, n, m, result);
    output(result, n, m);

    printf("\n");
    sort_horizontal(matrix, n, m, result);
    output(result, n, m);

    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
  } else {
    if (n != 0 && m != 0) {
      for (int i = 0; i < n; i++) free(matrix[i]);
      free(matrix);
    }
    printf("n/a");
  }
}

int symbolCorrect(char symbol) {
  return symbol == ' ' || symbol == '\n' || symbol == EOF ? 1 : 0;
}
int sizeCorrect(int s) { return s > 0 ? 1 : 0; }

int dynamic(int ***a, int *n, int *m) {
  char symbol;
  int check = 1;

  if (scanf("%d %d%c", n, m, &symbol) == 3 && sizeCorrect(*n) &&
      sizeCorrect(*m) && symbolCorrect(symbol)) {
    (*a) = malloc(*n * sizeof(int *));
    for (int i = 0; i < *n; i++) {
      (*a)[i] = malloc(*m * sizeof(int));
    }
    check = input(a, *n, *m);
  } else {
    check = 0;
  }
  return check;
}

int input(int ***a, int n, int m) {
  char symbol;
  int el;
  int check = 1;
  if (scanf("%d %d%c", n, m, &symbol)) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (scanf("%d%c", &el, &symbol) == 2 && symbolCorrect(symbol)) {
          (*a)[i][j] = el;
        } else {
          check = 0;
          break;
        }
      }
    }
  }
  return check;
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
  int count = n * m;
  int k = 0, q = 0;
  while (k * q != count) {
    int min = matrix[k % n][q % m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (min < matrix[i][j]) min = matrix[i][j];
      }
    }
    result_matrix[k % n][q % m] = min;
    q++;
    k++;
  }
}
