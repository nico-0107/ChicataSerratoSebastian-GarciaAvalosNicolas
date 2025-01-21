#include <iostream>
using namespace std;

struct Vector{
  int *m_pVect;
  int m_nCount;
  int m_nMax;
  int m_nDelta;
};

void redimensionar(Vector *pThis){
  const int delta = 5;
  int *pTemp, i;

  pTemp = new int[pThis->m_nMax + pThis->m_nDelta];

  for(i = 0; i < pThis->m_nMax; i++)
    pTemp[i] = pThis->m_pVect[i];

  delete [] pThis->m_pVect;

  pThis->m_pVect = pTemp;
  pThis->m_nMax += pThis->m_nDelta;
}

void insertarElemento(Vector *pThis, int elemento){
  if (pThis->m_nCount == pThis->m_nMax)
    redimensionar(pThis);

  pThis->m_pVect[pThis->m_nCount++] = elemento;
}

void mostrarElementos(Vector *pThis){
  cout<<"Elementos en el arreglo: "<<endl;
  for (int i = 0; i < pThis->m_nCount; i++) {
    cout<<"Elemento ["<<i<<"]: "<<pThis->m_pVect[i]<<endl;
  }
  cout<<endl;
  cout<<"Cantidad de elementos almacenados: "<<pThis->m_nCount<<endl;
}

void eliminarElemento(Vector *pThis, int elemento){
  int index = -1;

  for (int i = 0; i < pThis->m_nCount; i++) {
    if (pThis->m_pVect[i] == elemento) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    cout << "El elemento " << elemento<< " no se encuentra en el arreglo." << endl;
    return;
  }

  for (int i = index; i < pThis->m_nCount - 1; i++) {
    pThis->m_pVect[i] = pThis->m_pVect[i + 1];
  }

  pThis->m_nCount--;
  cout<<"El elemento "<<elemento<<" ha sido eliminado."<<endl;
}

int main(){

  Vector myVect; // Crear un vector dinámico.
  myVect.m_nCount = 0;
  myVect.m_nMax = 0;
  myVect.m_nDelta = 5;

  insertarElemento(&myVect, 10);
  insertarElemento(&myVect, 20);
  insertarElemento(&myVect, 30);

  mostrarElementos(&myVect);

  eliminarElemento(&myVect, 20);
  cout<<endl;
  mostrarElementos(&myVect);
  return 0;
}