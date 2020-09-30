/*
Jaime Orlando López Ramos, A01374696
Programación Avanzada
Assignment 1
*/

#include "stdio.h"
#include "stdlib.h"

char* muchBetter(){
  return "A \"quoted\" String is\n'much' better if you learn\nthe rules of \"escape sequences.\"\nAlso, \"\" represents an empty String.\nDon't forget: use \\\" instead of \" !\n'' is not the same as \"";
}

int main(){
  printf("%s", muchBetter());
}
