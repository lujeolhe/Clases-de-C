/*
Jaime Orlando López Ramos, A01374696
Programación Avanzada
Assignment 1
*/

#include "stdio.h"
#include "stdlib.h"

char* meta(){
  return "#include \"stdio.h\"\n\n\nint main(void) {\nprintf(\"Hello World\\n\");\nreturn 0;\n}";
}

int main(){
  printf("%s", meta());
}
