#include <iostream>
using namespace std;
//Crear primero struct NodoArbol
//Despues crear struct Cola
//En dequeue de Cola devolver de tipo NodoArbol*
//Armar la funcion insertar y mostrarArbol afuera de todo struct
struct Cola{
    NodoArbol* front = nullptr;
    NodoArbol* rear = nullptr;

    void enqueue(NodoArbol*& nodo){
        if(rear == nullptr && front == nullptr){
            front = nodo;
            rear = nodo;
        }else{
            rear -> siguiente = nodo;
            rear = nodo;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout << "No hay elementos en la cola para sacar" << endl;
            return;
        }
        NodoArbol* temporal = front;
        front = front -> siguiente;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temporal;
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

struct NodoArbol {
    int valor;
    NodoArbol* izquierda;
    NodoArbol* derecha;

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
};




int main(){
    NodoArbol raiz {1, nullptr, nullptr};
    NodoArbol* punteroRaiz = &raiz; //puntero a la raíz del árbol, uso & para obtener la dirección de memoria de la raíz y asignarla al puntero.
    NodoArbol* nodo1 = new NodoArbol{2, nullptr, nullptr};
    NodoArbol* nodo2 = new NodoArbol{3, nullptr, nullptr};
    NodoArbol* nodo3 = new NodoArbol{4, nullptr, nullptr};
    NodoArbol* nodo4 = new NodoArbol{5, nullptr, nullptr};

    punteroRaiz -> insertar(punteroRaiz, nodo1); //aca se usa raiz -> porque es un puntero a la estructura NodoArbol, y se necesita acceder a la función insertar() que está definida dentro de la estructura NodoArbol. Al usar el operador ->, se puede llamar a la función insertar() en el objeto apuntado por raiz. también se podría haber llamado a la función insertar() directamente desde el objeto nodo1, pero en este caso se está utilizando la raíz del árbol como punto de partida para insertar los nodos hijos.
    punteroRaiz -> insertar(punteroRaiz, nodo2);
    punteroRaiz -> insertar(punteroRaiz, nodo3);
    punteroRaiz -> insertar(punteroRaiz, nodo4);

    punteroRaiz -> mostrarArbol(punteroRaiz);

    return 0;
}