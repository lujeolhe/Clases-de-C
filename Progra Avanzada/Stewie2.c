/*
Jaime Orlando López Ramos, A01374696
Programación Avanzada
Assignment 1
*/

#include "stdio.h"
#include "stdlib.h"

char* stewie(){
  return "//////////////////////\n|| Victory is mine! ||\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
}

char* stewie2(){
  return "|| Victory is mine! ||\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
}

int main(){
  printf("%s", stewie());
  for(int i = 0; i<3; i++)
    printf("%s\n", stewie2());
  printf("%s", stewie2());
}
