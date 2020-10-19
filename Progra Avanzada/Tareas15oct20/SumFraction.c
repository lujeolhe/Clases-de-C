////////Bibliotecas///////
#include <stdio.h>

///////Estructuras////////
struct Fraction{
int numerador;
int denominador;
};

/////Prototipos de Funciones////////
struct Fraction simplifyFraction(const struct Fraction *f);
struct Fraction sumFraction(const struct Fraction *a, const struct Fraction *b);

/////Funcion Principal///////
int main() {

  struct Fraction i;
  struct Fraction j;
  scanf("%d",&i.numerador);
  scanf("%d",&i.denominador);

  scanf("%d",&j.numerador);
  scanf("%d",&j.denominador);


  struct Fraction r=sumFraction((const struct Fraction*)&i,(const struct Fraction*)&j);
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
      if(ff.numerador%i==0&&ff.denominador%i==0){
        ff.numerador/=i;
        ff.denominador/=i;
        //printf("i: %d ff.num: %d\n",i,ff.numerador );
      }

    }
  }
  return ff;
}
struct Fraction sumFraction(const struct Fraction *a, const struct Fraction *b){
  const struct Fraction sum={a->denominador*b->numerador+b->denominador*a->numerador,b->denominador*a->denominador};
  return simplifyFraction(&sum);
}
