#include <iostream>
using namespace std;

//Crear primero struct NodoArbol HECHO
//Despues crear struct Cola HECHO
//En dequeue de Cola devolver de tipo NodoArbol* HECHO
//Armar la funcion insertar y mostrarArbol afuera de todo struct
//


struct NodoArbol {
    int valor;
    NodoArbol* izquierda;
    NodoArbol* derecha;   
};


struct Cola{
    NodoArbol* front = nullptr;
    NodoArbol* rear = nullptr;

    void enqueue(NodoArbol*& nodo){
        if(rear == nullptr && front == nullptr){
            front = nodo;
            rear = nodo;
        }else{
            rear = nodo;
        }
    }

    NodoArbol* dequeue(){
        if(isEmpty()){
            cout << "No hay elementos en la cola para sacar" << endl;
            return;
        }
        NodoArbol* temporal = front;
        front = front -> siguiente;
        if(front == nullptr){
            rear = nullptr;
        }
        return temporal;
    }

    void peek(){
        cout << "El elemento en el frente de la cola es: " << front -> valor << endl;
    }

    void peekRear(){
        cout << "El elemento en el final de la cola es: " << rear -> valor << endl;    
    }

    int size(){
        NodoArbol* actual = front;
        int cantidad = 0;
        if (front == nullptr){
            return 0;
        }else{
            while (actual != nullptr){
                cantidad ++;
                actual = actual -> siguiente;
            }
        }
        return cantidad;
    }

    bool isEmpty(){
        return front == nullptr;
    }
};

void insertar(NodoArbol*& arbol ,NodoArbol* nodo){
        if(arbol == nullptr){
            arbol = nodo;
        }else{
            Cola cola = new Cola{nullptr,nullptr};
            cola.enqueue(arbol);
            while(!cola.isEmpty){
                actual = cola -> front
                if(actual -> izquierda == nullptr){
                    actual -> izquierda = nodo;
                    return;
                }else {
                    cola.enqueue(cola -> izquierda);
                }
                if(actual -> derecha == nullptr){
                    actual -> derecha = nodo;
                    return;
                }else {
                    cola.enqueue(cola -> derecha);
                }
            }
        }
    }

    void mostrarArbol(NodoArbol* raiz){
        if(raiz != nullptr){
            cout << raiz -> valor << endl;
            mostrarArbol(raiz -> izquierda);
            mostrarArbol(raiz -> derecha);
        }
    }




//hace el main completo para probar todo
int main(){
    
    NodoArbol* arbol = nullptr;

    NodoArbol* nodo1 = new NodoArbol{1, nullptr, nullptr};
    NodoArbol* nodo2 = new NodoArbol{2, nullptr, nullptr};
    NodoArbol* nodo3 = new NodoArbol{3, nullptr, nullptr};
    NodoArbol* nodo4 = new NodoArbol{4, nullptr, nullptr};
    NodoArbol* nodo5 = new NodoArbol{5, nullptr, nullptr};

    insertar(arbol, nodo1);
    insertar(arbol, nodo2);
    insertar(arbol, nodo3);
    insertar(arbol, nodo4);
    insertar(arbol, nodo5);

    cout << "Mostrando el arbol:" << endl;
    mostrarArbol(arbol);

    return 0;
}