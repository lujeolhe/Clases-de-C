/*
Autor: Jaime Orlando López Ramos
Descripción: Implementación de pilas y colas estáticas
Fecha: 28/'7/2020'
*/

#include <stdio.h>
#define TAM_MAX 50

typedef struct p{
  int pila[TAM_MAX];
  int indice;
}PILA;

typedef PILA COLA;

// Funciones Para Pilas
void pila_push(PILA *pPILA, int dato);
int pila_pop(PILA *pPILA);

// Funciones Compartidas Pilas y Colas
void pila_init(PILA *pPILA);
void pila_print(PILA *pPILA);

// Funciones colas
void cola_push(COLA *pCOLA, int dato);
int cola_pull(COLA *pCOLA);

int main(){
  PILA miPilaFeliz;
  pila_init(&miPilaFeliz);
  for(int i=0; i<TAM_MAX; i++){
    pila_push(&miPilaFeliz, i);
  }

  pila_print(&miPilaFeliz);

  pila_push(&miPilaFeliz, 50);

  pila_print(&miPilaFeliz);

  for(int i=0; i<TAM_MAX/2; i++){
    printf("El valor retirado fue: %d\n", pila_pop(&miPilaFeliz));
  }

  pila_print(&miPilaFeliz);

  for(int i=0; i<TAM_MAX/2; i++){
    printf("El valor retirado fue: %d\n", pila_pop(&miPilaFeliz));
  }

  pila_print(&miPilaFeliz);

  pila_pop(&miPilaFeliz);

printf("\n=================================================================\n");

  COLA cola;
  pila_init(&cola);
  for(int i = 0; i < TAM_MAX; i++){
    cola_push(&cola, i*i);
  }

  pila_print(&cola);
  cola_push(&cola, 50);
  pila_print(&cola);

  for(int i=0; i<TAM_MAX; i++){
    printf("El elemento removido fue: %d\n", cola_pull(&cola));
  }

  pila_print(&cola);

  cola_pull(&cola);

}

void pila_init(PILA *pPILA){
  pPILA->indice=0;
  for(int i=0; i<TAM_MAX; i++){
    pPILA->pila[i]=0;
  }
}

void pila_push(PILA *pPILA, int dato){

  if(pPILA->indice >= 50){
    printf("Error insertando, la pila llegó a su límite de elementos\n");
    return;
  }

  pPILA->pila[pPILA->indice]=dato;
  pPILA->indice++;
}

int pila_pop(PILA *pPILA){
  if(pPILA->indice <= 0){
    printf("No puedes eliminar algo si la pila está vacía \n");
    return 0;
  }
  int elementoBorrado;
  pPILA->indice--;
  elementoBorrado = pPILA->pila[pPILA->indice];
  return elementoBorrado;
}

void pila_print(PILA *pPILA){
  for(int i=0; i<pPILA->indice; i++){
    printf("%d ", pPILA->pila[i]);
  }
  printf("\n");

}

void cola_push(COLA *pPILA, int dato){
  if(pPILA->indice >= 50){
    printf("Error insertando, la pila llegó a su límite de elementos\n");
    return;
  }

  pPILA->pila[pPILA->indice]=dato;
  pPILA->indice++;
}

int cola_pull(COLA *pCOLA){

if(pCOLA->indice<=0){
  printf("La cola ya está vacía, no hay elementos a borrar\n");
  return 0;
}

  int elementoBorrado = pCOLA->pila[0];
  for(int i=0; i<pCOLA->indice; i++){
    pCOLA->pila[i]=pCOLA->pila[i+1];
  }

  pCOLA->indice--;
  return elementoBorrado;
}
