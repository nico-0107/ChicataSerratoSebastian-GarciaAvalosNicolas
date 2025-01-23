#include <iostream>
using namespace std;

template <typename T>
class ListaEnlazada
{
private:
    struct Nodo
    {
        T dato;
        struct Nodo *siguiente;
    };

    Nodo *raiz;

public:

    ListaEnlazada() : raiz(nullptr) {}

    ~ListaEnlazada()
    {
        while (raiz != nullptr)
        {
            Nodo *temporal = raiz;
            raiz = raiz->siguiente;
            delete temporal;
        }
    }

    void InsertarAlInicio(const T &dato)
    {
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = raiz;
        raiz = nuevoNodo;
    }

    void InsertarAlFinal(const T &dato)
    {
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = nullptr;

        if (raiz == nullptr)
        {
            raiz = nuevoNodo;
        }
        else
        {
            Nodo *actual = raiz;
            while (actual->siguiente != nullptr)
            {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    void Imprimir() const
    {
        Nodo *actual = raiz;
        while (actual != nullptr)
        {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    ListaEnlazada<int> lista;

    lista.InsertarAlInicio(30);
    lista.InsertarAlInicio(20);
    lista.InsertarAlInicio(10);

    lista.InsertarAlFinal(40);
    lista.InsertarAlFinal(50);

    lista.Imprimir();

    return 0;
}