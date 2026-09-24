#include <iostream>
#include <vector>
#include <cassert>
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


struct NodoCola {
    NodoArbol* valor;
    NodoCola* siguiente;
};

struct Cola {
    NodoCola* front = nullptr;
    NodoCola* rear = nullptr;

    void enqueue(NodoArbol* dato){
        NodoCola* nuevo = new NodoCola{dato, nullptr};
        if(rear == nullptr){
            front = rear = nuevo;
        }else{
            rear->siguiente = nuevo;  
            rear = nuevo;
        }
    }

    NodoArbol* dequeue(){
        if(front == nullptr) return nullptr;
        NodoCola* temp = front;
        NodoArbol* dato = front->valor;
        front = front->siguiente;
        if(front == nullptr) rear = nullptr;
        delete temp;
        return dato;
    }

    bool isEmpty(){ return front == nullptr; }
};

void vaciarCola(Cola& cola){
    while(!cola.isEmpty()){
        cola.dequeue();
    }
}

void insertar(NodoArbol*& arbol ,NodoArbol* nodo){
    if(arbol == nullptr){
        arbol = nodo;
    }else{
        Cola cola;
        cola.enqueue(arbol);
        while(!cola.isEmpty()){
            NodoArbol* actual = cola.dequeue();
            if(actual -> izquierda == nullptr){
                actual -> izquierda = nodo;
                vaciarCola(cola);
                return;
            }else if (actual -> derecha == nullptr){
                actual -> derecha = nodo;
                vaciarCola(cola);
                return;
            }else{
                cola.enqueue(actual -> izquierda);
                cola.enqueue(actual -> derecha);
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

void preOrder(NodoArbol* raiz, vector<int>& resultado){
    if(raiz != nullptr){
        resultado.push_back(raiz -> valor);
        preOrder(raiz -> izquierda, resultado);
        preOrder(raiz -> derecha, resultado);
    }
}

void inOrder(NodoArbol* raiz, vector<int>& resultado){
    if(raiz != nullptr){
        inOrder(raiz -> izquierda, resultado);
        resultado.push_back(raiz -> valor);
        inOrder(raiz -> derecha, resultado);
    }
}

void postOrder(NodoArbol* raiz, vector<int>& resultado){
    if(raiz != nullptr){
        postOrder(raiz -> izquierda, resultado);
        postOrder(raiz -> derecha, resultado);
        resultado.push_back(raiz -> valor);
    }
}

void testFunciones(NodoArbol*& arbol){
    vector<int> resultado;
    preOrder(arbol, resultado);
    assert(resultado == vector<int>({1,2,4,5,3,6,7}));
    resultado.clear();

    inOrder(arbol, resultado);
    assert(resultado == vector<int>({4, 2, 5, 1, 6, 3, 7}));
    resultado.clear();

    postOrder(arbol, resultado);
    assert(resultado == vector<int>({4,5,2,6,7,3,1}));
    resultado.clear();

    cout << "Todos los test pasaron correctamente" << endl;

}


int main(){
    NodoArbol* arbol = nullptr;

    insertar(arbol, new NodoArbol{1, nullptr, nullptr});
    insertar(arbol, new NodoArbol{2, nullptr, nullptr});
    insertar(arbol, new NodoArbol{3, nullptr, nullptr});
    insertar(arbol, new NodoArbol{4, nullptr, nullptr});
    insertar(arbol, new NodoArbol{5, nullptr, nullptr});
    insertar(arbol, new NodoArbol{6, nullptr, nullptr});
    insertar(arbol, new NodoArbol{7, nullptr, nullptr});
    mostrarArbol(arbol);

    testFunciones(arbol);
    
    return 0;
}