#include <stdio.h>

void zeroDigits(char str[100]){
  int counter = 0;
  for(int i = 0; i<100; i++){
    if(str[i]=='\0'){
      break;
    }

    if(str[i] == '0'){
      counter++;
    }

  }

  printf("%d", counter);
}

int main(int argc, char const *argv[]) {
  char str[100];
  gets(str);
  zeroDigits(str);
  return 0;
}
