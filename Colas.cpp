#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};

class Cola{
private:
    Nodo* frente;
    Nodo* fondo;

public:
    Cola() : frente(nullptr), fondo(nullptr) {}

    void Insertar(int dato){
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = nullptr;

        if (fondo == nullptr){
            frente = nuevoNodo;
            fondo = nuevoNodo;
        }
        else{
            fondo->siguiente = nuevoNodo;
            fondo = nuevoNodo;
        }
    }

    void Borrar(){
        if (frente == nullptr){
            cout<<"La cola está vacía, no se puede eliminar."<<endl;
            return;
        }

        Nodo* temp = frente;
        frente = frente->siguiente;
        delete temp;

        if (frente == nullptr){
            fondo = nullptr;
        }
    }

    int ObtenerFrente() const{
        if (frente == nullptr){
            cout<<"La cola está vacía."<<endl;
            return -1;
        }
        return frente->dato;
    }

    bool EstaVacia() const{
        return frente == nullptr;
    }

    void Imprimir() const{
        if (frente == nullptr){
            cout<<"La cola está vacía."<<endl;
            return;
        }

        Nodo* actual = frente;
        while (actual != nullptr){
            cout<<actual->dato<<" -> ";
            actual = actual->siguiente;
        }
        cout<<"nullptr"<<endl;
    }
};

int main(){
    Cola cola;

    cola.Insertar(10);
    cola.Insertar(20);
    cola.Insertar(30);
    cola.Insertar(5);

    cout<<"Contenido de la cola: ";
    cola.Imprimir();

    cout<<endl;

    cout<<"Valor del frente de la cola: "<<cola.ObtenerFrente()<<endl;

    cout<<"Eliminando el frente de la cola."<<endl;
    cola.Borrar();

    cout<<endl;

    cola.Imprimir();

    cout<<endl;

    cout<<"Valor del frente de la cola después de eliminar: "<<cola.ObtenerFrente()<<endl;

    if (cola.EstaVacia()){
        cout<<"La cola está vacía."<<endl;
    }
    else{
        cout<<"La cola no está vacía."<<endl;
    }

    return 0;
}
