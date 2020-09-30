/*
Nombre y Matrícula: Jaime Orlando López Ramos, A01374696

Fecha de Creación: 15/09/2020

Descripción: Implemente una función de cantidad de parámetros variable (variadic) que recibe parámetros enteros sin signo de 16 bits y retorna un entero sin signo de 32 bits.
La salida de la función contiene los dos bits menos significativos del primer parámetro variable, luego el par de bits de las posiciones 2 y 3 del siguiente parámetro variable y así sucesivamente.

*/

#include <stdio.h>
#include <stdarg.h>
# define TRUE 1
# define FALSE 0

#include "headerExamen.h"





unsigned long codificandoParesDeBits(unsigned int arr[50], int size){
  if(size == 0){
    return 0;
  }

  int masc = 3;
  unsigned long resultado = 0;

  int limite = size;
  if(limite > 16){
    limite = 16;
  }

  for(int i = 0; i < limite; i++){
    resultado += (masc << 2*i) & arr[i];
  }

  return resultado;
  }

  unsigned long pairBits(unsigned int n, ...){
    if(n == 0){
      return 0;
    }

    va_list args;
    va_start(args, n);
    int limite = n;

    int masc = 3;
    unsigned long resultado = 0;

    if(limite > 16){
      limite = 16;
    }




    for(unsigned int i = 0; i < n && i < 16; i++){
      unsigned int aux = (unsigned int)va_arg(args, int);
      // printf("Representación en bits de %u: ", aux);
      // imprimirBinarioDe16BitsSinSigno(aux);
      resultado += (masc << 2*i) & aux;
    }

    va_end(args);
    // printf("Resultado en representación de 32 bits: ");
    // imprimirBinarioDe32BitsSinSigno(resultado);
    return resultado;

  }

  void imprimirBinarioDe16BitsSinSigno(unsigned int n){
    unsigned int masc = 0x8000;
    for (int i = 0; i < 16; i++) {
      if((masc >> i)& n){
        printf("1");
      }
      else{
        printf("0");
      }
    }
    printf("\n");
  }

  void imprimirBinarioDe32BitsSinSigno(unsigned long n){
    unsigned long masc = 0x80000000;
    for (int i = 0; i < 32; i++) {
      if((masc >> i)& n){
        printf("1");
      }
      else{
        printf("0");
      }
    }
    printf("\n");
  }

  int prueba0(){
    if(pairBits(0) == 0){
      return TRUE;
    }

    return FALSE;

  }

  int prueba3(){
    unsigned long int esperado = 25;
    if(esperado == pairBits(3, 1, 8, 16)){
      return TRUE;
    }

    return FALSE;
  }

  int prueba18(){
    unsigned long int esperado = 65535;
    if(esperado == pairBits(18, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 0, 0)){
      return TRUE;
    }
    return FALSE;
  }

  int main(int argc, char const *argv[]) {
    printf("%d\n", prueba0());
    printf("%d\n", prueba3());
    printf("%d\n", prueba18());
    return 0;
  }
