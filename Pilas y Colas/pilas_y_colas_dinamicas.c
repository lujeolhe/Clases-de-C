/*
Autor: Jaime Orlando López Ramos
Descripción: Implementación de pilas y colas dinámicas
Fecha: 30/'7/2020'
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
  struct nodo* psiguiente;
  int dato;
}NODO;

typedef NODO* PILA;
typedef NODO* COLA;

void pila_push(PILA* pila, int dato);
int pila_pop(PILA* pila);
void print(PILA pila);
void cola_push(COLA* cola, int dato);
int cola_pull(COLA* cola);

int main(){
  PILA miPilaFeliz = NULL;
  for(int i = 0; i<10; i++){
    pila_push(&miPilaFeliz, (i*10-2));
  }

  print(miPilaFeliz);

  for(int i = 0; i<9; i++){
    printf("%d\n", pila_pop(&miPilaFeliz));
  }

  print(miPilaFeliz);

  printf("-.-.-.-.-..-.-.-..-.-.-.-.-.-.-..--.-..-.-.-.-.-.-.-.-.-..--.-..-.--..--.-.-\n");

  COLA cola = NULL;
  for(int i = 50; i<1000; i = i*2){
    cola_push(&cola, i);
  }

  print(cola);

  for(int i = 0; i<5; i++){
    printf("%i\n Cola Actualizada: ", cola_pull(&cola));
    print(cola);
  }






}

void pila_push(PILA* pila, int dato){
  NODO* nuevo_nodo = (NODO*)malloc(sizeof(NODO));
  nuevo_nodo->dato = dato;
  nuevo_nodo->psiguiente = NULL;
  if(*(pila) != NULL){
    NODO* nodo_aux = *(pila);

    while(nodo_aux->psiguiente != NULL){
      nodo_aux = nodo_aux->psiguiente;
    }

    nodo_aux->psiguiente = nuevo_nodo;
    return;
  }

  *(pila) = nuevo_nodo;
}

int pila_pop(PILA* pila){
  if(*(pila) == NULL){
    printf("Pila Vacía \n");
    return 0;
  }

  NODO* nodo_aux = *(pila);

  while(nodo_aux->psiguiente != NULL){
    nodo_aux = nodo_aux->psiguiente;
  }

  int valorRetorno = nodo_aux->dato;

  NODO* nuevoNodoFinal = *(pila);
  while(nuevoNodoFinal->psiguiente != nodo_aux){
    nuevoNodoFinal = nuevoNodoFinal->psiguiente;
  }

  nuevoNodoFinal->psiguiente = NULL;
  free(nodo_aux);
  return valorRetorno;
}

void cola_push(COLA* cola, int dato){
  NODO* nuevoNodo = (NODO*)malloc(sizeof(NODO));
  nuevoNodo->dato = dato;
  nuevoNodo->psiguiente = NULL;
  if(*(cola) == NULL){
    *(cola) = nuevoNodo;
    return;
  }

  else{
    NODO* nodoAux = *(cola);
    while(nodoAux->psiguiente != NULL){
      nodoAux = nodoAux->psiguiente;
    }
    nodoAux->psiguiente = nuevoNodo;
  }

}

int cola_pull(COLA* cola){
  if(*(cola) == NULL){
    printf("No elements to remove, LOL \n");
    return 0;
  }

  else{
    NODO* nodoARemover = *(cola);

    int valorRetorno = nodoARemover->dato;
    if(nodoARemover->psiguiente == NULL){
        *(cola) = NULL;
        return valorRetorno;
    }

    else{
    *cola = (*cola)->psiguiente;
    free(nodoARemover);
    return valorRetorno;
    }



  }
}

void print(PILA pila){
  if(pila == NULL){
    printf("Pila Vacía \n");
    return;
  }

    NODO* nodoAux = pila;
    while(nodoAux->psiguiente != NULL){
      printf("%d, ", nodoAux->dato);
      nodoAux = nodoAux->psiguiente;
    }
    printf("%d\n", nodoAux->dato);
}
