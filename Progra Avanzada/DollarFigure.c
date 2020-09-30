// Jaime Orlando López Ramos
// Assignment 2

#include <stdio.h>

int main(int argc, char const *argv[]) {
  int dollarN = 7;
  int asterisks = 0;

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < asterisks; j++) {
      printf("*");
    }

    for (int k = 0; k < dollarN; k++) {
      printf("$");
    }

    for (int l = 0; l < 28 - ((asterisks*2)+(dollarN * 2)); l++) {
      printf("*");
    }

    for (int k = 0; k < dollarN; k++) {
      printf("$");
    }

    for (int j = 0; j < asterisks; j++) {
      printf("*");
    }

    dollarN --;
    asterisks += 2;
    printf("\n");

  }

  return 0;
}
