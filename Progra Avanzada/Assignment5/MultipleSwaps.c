#include <stdio.h>
#include <math.h>

int swapBits(int n1, int n2, int n3){
  unsigned long uln1=(unsigned long)n1;
  unsigned long masc  = 0x00000001;
  unsigned long masc2 = 0x00000001;

  masc = masc<<(n2-1);
  masc2 = masc<<(n3-1);

  //printf("%x: %x %x\n",n1,masc,masc2 );

  int aux = n3 - n2;
  if(aux % 2 == 0){
    aux /= 2;
  }
  else{
    aux = (aux - 1) / 2;
  }

  for(int i = 0; i <= aux; i++){
    unsigned long cn2 = n1&(masc<<i);
    unsigned long cn3 = n1&(masc2>>i);
    //n1=n1&~(masc<<i|masc2>>i);
    //printf("%x: %x %x %x |",n1,masc<<i,masc2>>i, masc<<i|masc2>>i);
    cn2=cn2<<(n3-n2-2*i);
    cn3=cn3>>(n3-n2-2*i);
    //printf(" %x %x | %d\n",cn2, cn3,n3-n2-2*i );
    n1=n1|cn2|cn3;
  }
  return n1;
}


int main(int argc, char const *argv[]) {
  int n1;
  int n2;
  int n3;

  scanf("%d", &n1);
  scanf("%d", &n2);
  scanf("%d", &n3);

  printf("%d", swapBits(n1, n2, n3));
  return 0;
}
