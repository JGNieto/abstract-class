#include <stdio.h>
#include <stdlib.h>

int main() {
  int primes[100000];
  primes[0] = 2;

  int index = 1;

  for (int i = 3; i < 1000000; i += 2) {
    int found_factor = 0;
    for (int j = 3; j * j <= i; j += 2) {
      if (i % j == 0) {
        found_factor = 1;
        break;
      }
    }
    if (found_factor == 0) {
      primes[index++] = i;
    }
  }
  printf("There are %d prime numbers.", index);

  FILE *fptr;
  fptr = fopen("./primes_efficient_weaver.txt","w");

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