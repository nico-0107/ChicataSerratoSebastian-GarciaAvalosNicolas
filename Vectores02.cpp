#include <iostream>
using namespace std;

int *gpVect = NULL; // Puntero que apunta al arreglo dinámico donde se almacenan los elementos.
int gContador = 0;
int gnMax = 0;

void Redimensionar(){
  const int delta = 5;
  int *pTemp, i;
  pTemp = new int[gnMax + delta];
  for (i = 0; i < gnMax; i++) // Transferir los elementos al nuevo arreglo
    pTemp[i] = gpVect[i];
  delete[] gpVect; // Liberar la memoria del arreglo antiguo
  gpVect = pTemp; // Actualizar el puntero al nuevo arreglo
  gnMax += delta; // Incrementar la capacidad máxima
}

void insertarElementos(int elemento){
  if (gContador == gnMax) // Si no hay espacio para el nuevo elemento
    Redimensionar(); // Aumentar el tamaño del arreglo
  gpVect[gContador++] = elemento; // Insertar el elemento al final del arreglo
}

void mostrarElementos(){
  cout<<"Elementos en el arreglo: "<<endl;
  for(int i = 0; i < gContador; i++){
    cout<<"Elemento ["<<i<<"]: "<<gpVect[i]<<endl;
  }
  cout<<endl;
  cout<<"Cantidad de elementos almacenados: "<<gContador<<endl;
}

void eliminarElemento(int elemento){
  int index = -1; // Variable para almacenar la posición del elemento

  // Buscar la posición del elemento
  for (int i = 0; i < gContador; i++) {
    if (gpVect[i] == elemento) {
      index = i; // Encontrado, almacenar la posición
      break;
    }
  }

  // Si el elemento no se encuentra
  if (index == -1) {
    cout<<"El elemento "<<elemento<<" no se encuentra en el arreglo."<<endl;
    return;
  }

  // Desplazar los elementos hacia la izquierda para llenar el hueco
  for (int i = index; i < gContador - 1; i++) {
    gpVect[i] = gpVect[i + 1];
  }

  gContador--;
  cout<<"El elemento "<<elemento<<" ha sido eliminado."<<endl;
}

int main(){

  insertarElementos(10);
  insertarElementos(20);
  insertarElementos(30);

  mostrarElementos();

  eliminarElemento(20);
  cout<<endl;
  mostrarElementos();
  return 0;
}