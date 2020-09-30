#include <stdio.h>

unsigned int fourIntOne(unsigned int n1, unsigned int n2, unsigned int n3, unsigned int n4){
  unsigned int mascara= 0x00000003;
  unsigned int result=0;
  result=n1&mascara;
  result=result|(n2&mascara<<8);
  result=result|(n3&mascara<<8*2);
  result=result|(n4&mascara<<8*3);
  return result;

}

int main(int argc, char const *argv[]) {
  unsigned int n1;
  unsigned int n2;
  unsigned int n3;
  unsigned int n4;

  scanf("%u", &n1);
  scanf("%u", &n2);
  scanf("%u", &n3);
  scanf("%u", &n4);

  printf("%u", fourIntOne(n1, n2, n3, n4));
  return 0;
}
