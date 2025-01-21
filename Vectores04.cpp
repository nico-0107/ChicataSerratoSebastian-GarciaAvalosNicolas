#include <iostream>
using namespace std;
class CVector {

private:
    int *m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void redimensionar();

public:
    // Constructor
    CVector(int delta = 10);

    // Destructor
    ~CVector();

    // Métodos públicos
    void insertarElemento(int elem);
    void eliminarElemento(int elem);
    void mostrarElementos();
};

// Implementación del constructor
CVector::CVector(int delta) {
    m_nDelta = delta;
    m_nCount = 0;
    m_nMax = 0;
    m_pVect = nullptr;
}

// Implementación del destructor
CVector::~CVector() {
    delete[] m_pVect;
}

void CVector::redimensionar() {
    int *pTemp = new int[m_nMax + m_nDelta];

    for (int i = 0; i < m_nCount; i++) {
        pTemp[i] = m_pVect[i];
    }

    delete[] m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}

void CVector::insertarElemento(int elemento) {
    if (m_nCount == m_nMax) {
        redimensionar();
    }

    m_pVect[m_nCount++] = elemento;
}

void CVector::eliminarElemento(int elemento) {
    int index = -1;

    for (int i = 0; i < m_nCount; i++) {
        if (m_pVect[i] == elemento) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout<<"El elemento "<<elemento<<" no se encuentra en el vector."<<endl;
        return;
    }

    for (int i = index; i < m_nCount - 1; i++) {
        m_pVect[i] = m_pVect[i + 1];
    }

    m_nCount--;

    cout<<"El elemento "<<elemento<<" ha sido eliminado."<<endl;
}

void CVector::mostrarElementos() {
    cout<<"Elementos en el vector: "<<endl;
    for (int i = 0; i < m_nCount; i++) {
        cout<<"Elemento ["<<i<<"]: "<<m_pVect[i]<<endl;
    }
    cout<<endl;
    cout<<"Cantidad de elementos almacenados: "<< m_nCount<<endl;
}

int main() {
    CVector miVector(5);

    miVector.insertarElemento(10);
    miVector.insertarElemento(20);
    miVector.insertarElemento(30);
    miVector.insertarElemento(40);
    miVector.insertarElemento(50);

    miVector.mostrarElementos();

    miVector.eliminarElemento(30);
    cout<<endl;
    miVector.mostrarElementos();

    miVector.eliminarElemento(100);
    cout<<endl;
    miVector.mostrarElementos();

    return 0;
}