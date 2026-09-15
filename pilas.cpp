#include <iostream>
#include <array>
using namespace std;


constexpr int capacidad = 100;

struct Pila {
    int tope = -1;
    array <int, capacidad> elementos;

    void push(int valor){
        if(tope < capacidad-1){
            elementos[tope+1] = valor;
            tope++;
        }
    }

    int pop(){
        if(tope != -1){
            tope--;
            return elementos[tope + 1];
        }
        return 0;
    }

    bool estaVacia (){
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

    cout << "Vacia? " << pila.estaVacia() << "\n";       // 0 (false)
    cout << "Tamano: " << pila.tamano() << "\n";          // 4
    cout << "Pop: " << pila.pop() << "\n"; // 1000
    cout << "Pop: " << pila.pop() << "\n"; // 100
    cout << "Pop: " << pila.pop() << "\n"; // 10
    cout << "Vacia? " << pila.estaVacia() << "\n";       // 0 (false), queda el 1
    cout << "Pop: " << pila.pop() << "\n"; // 1
    cout << "Vacia? " << pila.estaVacia() << "\n";       // 1 (true)
}