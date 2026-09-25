#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct NodoArbol {
    int valor;
    NodoArbol* izquierda;
    NodoArbol* derecha;   
};


void insertarBST(NodoArbol*& raiz, int valor){
    if(raiz == nullptr){
        raiz = new NodoArbol{valor,nullptr,nullptr};
    }else if(valor > raiz -> valor){
        insertarBST(raiz -> derecha, valor);
    }else if(valor < raiz -> valor){
        insertarBST(raiz -> izquierda, valor);
    }
    //en el caso de que valor == raiz -> valor, no lo inserto ya que no queremos tener elementos repetidos 
}

bool buscarBST(NodoArbol* raiz, int valor){
    bool esIgual = false;
    if(raiz == nullptr){
        esIgual = false;
    }else if(valor > raiz -> valor){
        esIgual = buscarBST(raiz -> derecha, valor);
    }else if(valor < raiz -> valor){
        esIgual = buscarBST(raiz -> izquierda, valor);
    }else if(raiz -> valor == valor){
        esIgual = true;
    }
    return esIgual;
}

void testearFunciones(NodoArbol*& raiz){
    assert(buscarBST(raiz, 50));
    assert(buscarBST(raiz,40));
    assert(buscarBST(raiz,45) == false);
    assert(buscarBST(raiz,100) == false);
    cout << "Pasaron todos los tests" << endl;
}


void mostrarArbol(NodoArbol* raiz){
    if(raiz != nullptr){
        cout << raiz -> valor << endl;
        mostrarArbol(raiz -> izquierda);
        mostrarArbol(raiz -> derecha);
    }
}

int main(){
    NodoArbol* arbol = nullptr;

    insertarBST(arbol,50);
    insertarBST(arbol,30);
    insertarBST(arbol,70);
    insertarBST(arbol,20);
    insertarBST(arbol,40);
    insertarBST(arbol,60);
    insertarBST(arbol,80);

    mostrarArbol(arbol);
    testearFunciones(arbol);
}