#include <stdio.h>


void printStrings(char* string, int n);


int main(int argc, char const *argv[]) {
  int n;
  char string[100];
  scanf("%d", &n);
  while (getchar() != '\n');
  gets(string);
  printStrings(string, n);
}



void printStrings(char* string, int n){
  for (int i = 0; i < n; i++) {
    printf("%s", string);
  }
}
