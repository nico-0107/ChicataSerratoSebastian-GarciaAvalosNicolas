#include <iostream>
using namespace std;

int *gpVect = NULL;
int gContador = 0;
int gnMax = 0;

void Redimensionar(){
  const int delta = 5;
  int *pTemp, i;
  pTemp = new int[gnMax + delta];
  for (i = 0; i < gnMax; i++)
    pTemp[i] = gpVect[i];
  delete[] gpVect;
  gpVect = pTemp;
  gnMax += delta;
}

void insertarElementos(int elemento){
  if (gContador == gnMax)
    Redimensionar();
  gpVect[gContador++] = elemento;
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
  int index = -1;

  for (int i = 0; i < gContador; i++) {
    if (gpVect[i] == elemento) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    cout<<"El elemento "<<elemento<<" no se encuentra en el arreglo."<<endl;
    return;
  }

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