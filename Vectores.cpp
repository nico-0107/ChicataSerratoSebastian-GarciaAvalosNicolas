#include <iostream>
using namespace std;

int gVector[100]; // Arreglo para guardar los elementos
int gContador = 0; // Contador para saber cuántos elementos hay almacenados

//función para añadir un elemento al vector (Insert)
void insertarElemento(int elemento){
  if(gContador < 100){
    gVector[gContador++] = elemento;
  }
}

//Función para mostrar los elementos del vector (Display)
void mostrarElementos(){
  for(int i = 0; i < gContador; i++){
    cout<<"Elemento ["<<i<<"]: "<<gVector[i]<<endl;
  }
  cout<<"Cantidad de elementos: "<<gContador<<endl;
}

//Función para eliminar un elemento del vector (Delete)
void eliminarElemento(int elemento) {
  int i;

  for (i = 0; i < gContador; i++) {
    if (gVector[i] == elemento) {
      break; // Si encontramos el valor, salimos del bucle
    }
  }

  if (i == gContador) {
    // Si no se encontró el valor
    cout<<"Error: el elemento "<<elemento<<" no esta en el arreglo."<<endl;
    return;
  }

  // Desplazar los elementos hacia la izquierda
  for (; i < gContador - 1; i++) {
    gVector[i] = gVector[i + 1];
  }

  gContador--;
  cout<<"El elemento "<<elemento<<" ha sido borrado"<<endl;
}

int main(){

  insertarElemento(10);
  insertarElemento(20);
  insertarElemento(30);
  insertarElemento(40);

  mostrarElementos();

  eliminarElemento(30);
  eliminarElemento(20);
  eliminarElemento(50);
  cout<<endl;
  mostrarElementos();
  return 0;
}