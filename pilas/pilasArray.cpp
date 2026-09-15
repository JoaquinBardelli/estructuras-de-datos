#include <iostream>
#include <array>
#include <cassert>
using namespace std;

constexpr int capacidad = 100;

struct Pila {
    int tope = -1;
    array<int, capacidad> elementos;

    void push(int valor){
        if(tope < capacidad-1){
            elementos[tope+1] = valor;
            tope++;
        }
    }

    int top(){
        assert(!estaVacia());
        return elementos[tope];
    }

    void pop(){
        if(tope != -1){
            tope--;
        }
    }

    bool estaVacia(){
        if(tope == -1){
            return true;
        }
        return false;
    }

    int tamano(){
        return tope+1;
    }
};

int main(){
    Pila pila;
    pila.push(1);
    pila.push(10);
    pila.push(100);
    pila.push(1000);

    cout << "Vacia? " << pila.estaVacia() << "\n";  // 0 (false)
    cout << "Tamano: " << pila.tamano() << "\n";      // 4

    cout << "Top: " << pila.top() << "\n"; // 1000
    pila.pop();

    cout << "Top: " << pila.top() << "\n"; // 100
    pila.pop();

    cout << "Top: " << pila.top() << "\n"; // 10
    pila.pop();

    cout << "Vacia? " << pila.estaVacia() << "\n";   // 0 (false), queda el 1

    cout << "Top: " << pila.top() << "\n"; // 1
    pila.pop();

    cout << "Vacia? " << pila.estaVacia() << "\n";   // 1 (true)

    // --- Asserts: top() y pop() trabajando juntos ---
    Pila pila2;
    pila2.push(10);
    pila2.push(20);

    assert(pila2.top() == 20);  // el ultimo que entro es el primero en verse
    pila2.pop();
    assert(pila2.top() == 10);  // al sacar el 20, queda el 10 como tope
    pila2.pop();
    assert(pila2.estaVacia());  // ya no queda nada

    cout << "Todos los asserts pasaron correctamente\n";

    return 0;
}