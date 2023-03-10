#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STARTING_POINTS 0
#define TURNS 8
#define DESIRED_END_STATE 5

#define ITERATIONS 10000000

int good_results = 0;
int total_results = 0;

void run_game() {
  int points = STARTING_POINTS;

  for (int i = 0; i < TURNS; i++) {
    int random_number = rand() % 4;

    switch (random_number) {
      case 0:
        points += 1;
        break;
      case 1:
        points += 2;
        break;
      case 2:
        points -= 1;
        break;
      case 3:
        points = 0;
        break;
      default:
        break;
    }
    if (points < 0) {
      points = 0;
    } else if (points >= 5) {
      points = 5;
      break;
    }
  }

  if (points == DESIRED_END_STATE) ++good_results;
  ++total_results;
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < ITERATIONS; ++i) {
    run_game();
  }

  printf("Total results: %d / %d", good_results, total_results);
}
