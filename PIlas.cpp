#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};

class Pila{
private:
    Nodo* cima;

public:
    Pila() : cima(nullptr) {}

    void Insertar(int dato){
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = cima;
        cima = nuevoNodo;
    }

    void Borrar(){
        if (cima == nullptr){
            cout<<"La pila está vacía, no se puede eliminar."<<endl;
            return;
        }

        Nodo* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }

    int ObtenerCima() const{
        if (cima == nullptr){
            cout<<"La pila está vacía."<<endl;
            return -1;
        }
        return cima->dato;
    }

    bool EstaVacia() const{
        return cima == nullptr;
    }

    void Imprimir() const{
        if (cima == nullptr){
            cout<<"La pila está vacía."<<endl;
            return;
        }

        Nodo* actual = cima;
        while (actual != nullptr){
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout<<"nullptr"<<endl;
    }
};

int main(){
    Pila pila;

    pila.Insertar(10);
    pila.Insertar(20);
    pila.Insertar(30);
    pila.Insertar(5);

    cout<<"Contenido de la pila: ";
    pila.Imprimir();

    cout<<endl;

    cout<<"Valor superior de la pila: "<<pila.ObtenerCima()<<endl;

    cout<<"Eliminando el valor superior de la pila."<<endl;
    pila.Borrar();

    cout<<endl;

    pila.Imprimir();

    cout<<endl;

    cout<<"Valor superior de la pila después de eliminar: "<<pila.ObtenerCima()<<endl;

    if (pila.EstaVacia()){
        cout<<"La pila está vacía."<<endl;
    }
    else{
        cout<<"La pila no está vacía."<<endl;
    }
    return 0;
}
