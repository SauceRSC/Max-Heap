// Cpp con lo necesario para crear y usar un Max heap, con metodos como pop, push, top, swap, etc.
// Fecha: 23/10/2020
#include <iostream>
#include "MyHeap.h"
using namespace std;

/*
  Descripcion: Constructor que inicia el size en 0, len en 7 y hace un arreglo dinamico
  Input: N/a.
  Output: No regresa nada, pero el objeto termina construido/instanciado.
  Complejidad: O(1)
*/
MyHeap::MyHeap(){
  this->size = 0;
  this->len = 7;
  this->values = new int[len];
}

/*
  Descripcion: Revisa si el arreglo esta vacio o no
  Input: N/a.
  Output: Bool -> true si el size es 0, false si es diferente a 0
  Complejidad: O(1)
*/
bool MyHeap::isEmpty(){
  return this->size == 0;
}

/*
  Descripcion: Regresa el size del arreglo
  Input: N/a.
  Output: int -> Regresa el size del array
  Complejidad: O(1)
*/
int MyHeap::length(){
  return this->size;
}

/*
  Descripcion: Inserta un nuevo valor en el array y hace el heapify para ponerlo en la posicion correcta
               y si es necesario agranda el array
  Input: n -> int con el nuevo valor
  Output: No regresa nada, pero termina habiendo un elemento extra en la lista
  Complejidad: Mejor caso O(1), Promedio O(log(n)), Peor O(n*log(n))
*/
void MyHeap::push(int n){
  if(this->size == this->len - 1){
    this->len = (len * 2) + 1;
    int* tmp = new int[this->len];
    for(int i = 0; i < size; i++){
      tmp[i] = this->values[i];
    }
    delete [] this->values;
    this->values = tmp;
  }
  
  int hijo = 0;
  hijo = this->size;
  if(hijo==0){
    this->values[hijo] = n;
  }else{
    this->values[hijo] = n;
    int padre = 0;
    padre = (hijo - 1) / 2;
    while(this->values[hijo] > this->values[padre]){
      swap(hijo, padre);
      hijo = padre;
      padre = (hijo - 1) / 2;
    }
  }
  this->size++;
}

/*
  Descripcion: Elimina el top/primer elemento del arreglo
  Input: N/a.
  Output: No regresa nada, pero el array termina con un elemento menos y con un nuevo top
  Complejidad: Mejor caso O(1), Promedio y Peor O(log(n))
*/
void MyHeap::pop(){
  if(this->size > 0){
    
    swap(0, size - 1);
    int padre = 0;
    int hijo = padre * 2;
    while(this->values[hijo + 1] > this->values[padre] && (hijo + 1) < this->size - 1 ||
          this->values[hijo + 2] > this->values[padre] && (hijo + 2) < this->size - 1){

      if(this->values[hijo + 1] > this->values[hijo + 2]){
        swap(padre, hijo + 1);
        padre = hijo + 1;
        hijo = padre * 2;
      }else{
        swap(padre, hijo + 2);
        padre = hijo + 2;
        hijo = padre * 2;
      }
    }
    this->size--;
  }
}

/*
  Descripcion: Regresa el top/primer elemento del arreglo
  Input: N/a.
  Output: int -> Regresa el primer elemento del arreglo
  Complejidad: O(1)
*/
int MyHeap::top(){
  return this->values[0];
}

/*
  Descripcion: Cambia el valor de dos posiciones del arreglo
  Input: a -> entero con la posicion 1, b -> entero con la posicion
  Output: No regresa nada, pero 2 posiciones cambiaron de lugar
  Complejidad: O(1)
*/
void MyHeap::swap(int a, int b){
  int aux = this->values[a];
  this->values[a] = this->values[b];
  this->values[b] = aux;
}

