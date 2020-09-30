/*
Jaime Orlando López Ramos, A01374696
Programación Avanzada
Assignment 1
*/

#include "stdio.h"
#include "stdlib.h"

char* difference(){
  return "What is the difference between\na \' and a \"?  Or between a \" and a \\\"?\n\nOne is what we see when we're typing our program.\nThe other is what appears on the \"console.\"";
}

int main(){
  printf("%s", difference());
}
