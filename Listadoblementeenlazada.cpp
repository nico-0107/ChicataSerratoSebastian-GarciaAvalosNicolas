#include <iostream>
using namespace std;

template <typename T>
class ListaDobleEnlazada
{
private:
    struct Nodo
    {
        T dato;
        Nodo *siguiente;
        Nodo *anterior;
    };

    Nodo *raiz;
    Nodo *cola;

public:
    ListaDobleEnlazada() : raiz(nullptr), cola(nullptr) {}

    ~ListaDobleEnlazada()
    {
        while (raiz != nullptr)
        {
            Nodo *temporal = raiz;
            raiz = raiz->siguiente;
            delete temporal;
        }
    }

    void InsertarAlFinal(const T &dato)
    {
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = nullptr;
        nuevoNodo->anterior = nullptr;

        if (raiz == nullptr)
        {
            raiz = nuevoNodo;
            cola = nuevoNodo;
        }
        else
        {
            cola->siguiente = nuevoNodo;
            nuevoNodo->anterior = cola;
            cola = nuevoNodo;
        }
    }

    void Borrar(const T &dato)
    {
        if (raiz == nullptr)
            return;

        Nodo *actual = raiz;


        while (actual != nullptr && actual->dato != dato)
        {
            actual = actual->siguiente;
        }

        if (actual == nullptr)
        {
            cout << "El valor " << dato << " no se encuentra en la lista." << endl;
            return;
        }


        if (actual == raiz)
        {
            raiz = actual->siguiente;
            if (raiz != nullptr)
                raiz->anterior = nullptr;
            else
                cola = nullptr;
        }

        else if (actual == cola)
        {
            cola = actual->anterior;
            cola->siguiente = nullptr;
        }

        else
        {
            actual->anterior->siguiente = actual->siguiente;
            actual->siguiente->anterior = actual->anterior;
        }

        delete actual;
    }

    void Imprimir() const
    {
        Nodo *actual = raiz;
        while (actual != nullptr)
        {
            cout << actual->dato << " <-> ";
            actual = actual->siguiente;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    ListaDobleEnlazada<int> lista;

    lista.InsertarAlFinal(10);
    lista.InsertarAlFinal(20);
    lista.InsertarAlFinal(30);
    lista.InsertarAlFinal(5);

    lista.Imprimir();

    cout << "Eliminando 20 de la lista." << endl;
    lista.Borrar(20);
    lista.Imprimir();

    cout << "Eliminando 10 (raíz) de la lista." << endl;
    lista.Borrar(10);
    lista.Imprimir();

    cout << "Eliminando 5 (cola) de la lista." << endl;
    lista.Borrar(5);
    lista.Imprimir();

    return 0;
}
