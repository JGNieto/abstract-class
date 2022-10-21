#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000
#define ARRAY_SIZE 1000000

int main() {
  int primes[ARRAY_SIZE];
  primes[0] = 2;
  primes[1] = 3;

  int index = 1;

  for (int i = 3; i < MAX; i += 2) {
    int found_factor = 0;
    int j = 1;
    int n = primes[j];
    while (n * n <= i) {
      if (i % n == 0) {
        found_factor = 1;
        break;
      }
      n = primes[++j];
    }

    if (index >= ARRAY_SIZE) {
      printf("Not enough array size.");
      exit(1);
    }

    if (found_factor == 0) {
      primes[index++] = i;
    }
  }
  printf("There are %d prime numbers.", index);

  FILE *fptr;
  fptr = fopen("./primes_efficient_weaver_array.txt","w");

  if (fptr == NULL) {
    printf("Error!");
    exit(1);
  }

  for (int i = 0; i < index; i++) {
    fprintf(fptr,"%d\n", primes[i]);
  }

  fclose(fptr);

  printf("Done!");
}