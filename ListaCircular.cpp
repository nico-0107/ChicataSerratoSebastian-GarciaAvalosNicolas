#include <iostream>
using namespace std;

template <typename T>
class ListaCircular
{
private:
    struct Nodo
    {
        T dato;
        Nodo *siguiente;
    };

    Nodo *raiz;

public:
    ListaCircular() : raiz(nullptr) {}

    ~ListaCircular()
    {
        if (raiz == nullptr)
            return;

        Nodo *actual = raiz;
        while (actual->siguiente != raiz)
        {
            Nodo *temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
        delete actual;
    }

    void Insertar(const T &dato)
    {
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->dato = dato;

        if (raiz == nullptr)
        {
            raiz = nuevoNodo;
            nuevoNodo->siguiente = raiz;
        }
        else
        {
            Nodo *actual = raiz;
            while (actual->siguiente != raiz)
            {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
            nuevoNodo->siguiente = raiz;
        }
    }

    void Imprimir() const
    {
        if (raiz == nullptr)
        {
            cout << "Lista vacía" << endl;
            return;
        }

        Nodo *actual = raiz;
        do
        {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        } while (actual != raiz);

        cout << "(Inicio)" << endl;
    }

    void Borrar(const T &dato)
    {
        if (raiz == nullptr)
            return;

        Nodo *actual = raiz;
        Nodo *previo = nullptr;

        do
        {
            if (actual->dato == dato)
            {
                if (actual == raiz && actual->siguiente == raiz)
                {
                    delete raiz;
                    raiz = nullptr;
                    return;
                }
                else if (actual == raiz)
                {
                    Nodo *temp = raiz;
                    while (actual->siguiente != raiz)
                    {
                        actual = actual->siguiente;
                    }
                    actual->siguiente = raiz->siguiente;
                    raiz = raiz->siguiente;
                    delete temp;
                    return;
                }
                else
                {
                    previo->siguiente = actual->siguiente;
                    delete actual;
                    return;
                }
            }
            previo = actual;
            actual = actual->siguiente;
        } while (actual != raiz);
    }
};

int main()
{
    ListaCircular<int> lista;

    lista.Insertar(10);
    lista.Insertar(20);
    lista.Insertar(30);
    lista.Insertar(5);

    lista.Imprimir();

    cout << "Borrando 20 de la lista." << endl;
    lista.Borrar(20);
    lista.Imprimir();

    return 0;
}

