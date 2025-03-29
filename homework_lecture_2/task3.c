#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  int *matrix = (int *)malloc(N * M * sizeof(int));
  int *transposed = (int *)malloc(M * N * sizeof(int));

  for (int i = 0; i < N * M; i++) {
    scanf("%d", &matrix[i]);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      transposed[j * N + i] = matrix[i * M + j];
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", transposed[i * N + j]);
    }
    printf("\n");
  }

  free(matrix);
  free(transposed);
  return 0;
}