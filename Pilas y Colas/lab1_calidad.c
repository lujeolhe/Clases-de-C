/*
Nombre: Jaime Orlando López Ramos
Matrícula: A01374696
Descripción del programa: Obtener la media y desviación estándar de n números reales utilizando listas
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
  struct nodo* psiguiente;
  double dato;
}NODO;

typedef nodo* Lista;

// Función para agregar elementos a la listas
void insertar(Lista listaOriginal, double dato){
  NODO* nodito = (NODO*)malloc(sizeof(NODO));
  nodito->dato = dato;
  nodito->psiguiente = NULL;

  NODO* auxiliar = listaOriginal;

  if(auxiliar == NULL){
    *(listaOriginal) = *(nodito);
    return;
  }

  while(auxiliar->psiguiente != NULL){
    auxiliar = auxiliar->psiguiente;
  }

  auxiliar->psiguiente = nodito;
}
