////////Bibliotecas///////
#include <stdio.h>

///////Estructuras////////
struct Fraction{
int numerador;
int denominador;
};

/////Prototipos de Funciones////////
struct Fraction simplifyFraction(const struct Fraction *f);


/////Funcion Principal///////
int main() {

  struct Fraction i;
  scanf("%d",&i.numerador);
  scanf("%d",&i.denominador);

  const struct Fraction *pi=&i;
  struct Fraction r=simplifyFraction(pi);
  printf("%d\n%d",r.numerador,r.denominador );


}

////Definicion de Funciones////////
struct Fraction simplifyFraction(const struct Fraction *f){
  struct Fraction aux={f->numerador,f->denominador};
  struct Fraction ff={f->numerador,f->denominador};

  for(int i=2;aux.denominador>1&&ff.numerador>1;i++){
    while(aux.denominador%i==0){

      aux.denominador/=i;
      //printf("i: %d ff.den: %d\n",i,ff.denominador );
      if(aux.numerador%i==0){
        ff.numerador/=i;
        ff.denominador/=i;
        //printf("i: %d ff.num: %d\n",i,ff.numerador );
      }
      if(ff.numerador==1)
        break;
    }
  }
  return ff;
}
