#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
};

Nodo* insertarInicio(int valor, Nodo* head){
    Nodo* nuevoNodo = new Nodo{valor, head};
    return nuevoNodo;
}

bool buscar (int valor, Nodo* head){
    Nodo* actual = head;
    while(actual != nullptr){
        if(actual -> valor == valor){
            cout << "Se encontro el valor pedido en la lista enlazada" << endl;
            return true;
        }else{
            actual = actual -> siguiente;
        }
    }
    cout << "NO se encontro el valor pedido en la lista enlazada" << endl;
    return false;
}

void eliminar (Nodo*& aEliminar){
    Nodo* temporal = aEliminar;
    aEliminar = aEliminar -> siguiente;
    delete temporal;
}

void eliminarPorValor(int valor, Nodo*& head){
    if (head == nullptr) return;
    if(head -> valor == valor){
        eliminar(head);
    }else{
        Nodo* actual = head;
        while(actual -> siguiente != nullptr){
            if(actual -> siguiente -> valor == valor){
                eliminar(actual -> siguiente);
                return;
            }else{
                actual = actual -> siguiente;
            }
        }
    }
}




void imprimirLista(Nodo* head){
    Nodo* actual = head;
    cout << "Lista: ";
    while(actual != nullptr){
        cout << actual->valor;
        if(actual->siguiente != nullptr) cout << " -> ";
        actual = actual->siguiente;
    }
    cout << endl;
}

void liberarLista(Nodo*& head){
    while(head != nullptr){
        eliminar(head);
    }
}

int main(){
    Nodo* head = nullptr;  // lista vacia al principio

    // Insertamos algunos valores al inicio
    head = insertarInicio(30, head);
    head = insertarInicio(20, head);
    head = insertarInicio(20, head);
    head = insertarInicio(10, head);

    imprimirLista(head);  // esperado: 10 -> 20 -> 30

    // Probamos buscar
    buscar(20, head);   // deberia encontrarlo
    buscar(99, head);   // no deberia encontrarlo

    eliminarPorValor(20, head);
    imprimirLista(head);

    // Liberamos toda la memoria restante antes de terminar
    liberarLista(head);
    imprimirLista(head);  // esperado: Lista: (vacia)

    eliminarPorValor(20, head);

    return 0;
}