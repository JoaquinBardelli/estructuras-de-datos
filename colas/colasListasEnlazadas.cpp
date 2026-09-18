#include <iostream>
using namespace std;

struct Nodo{
    int valor;
    Nodo* siguiente;
};

struct Cola{
    Nodo* front = nullptr;
    Nodo* rear = nullptr;

    void enqueue(Nodo*& nodo){
        if(rear == nullptr && front == nullptr){
            front = nodo;
            rear = nodo;
        }else{
            rear -> siguiente = nodo;
            rear = nodo;
        }
    }

    void dequeue(){
        Nodo* temporal = front;
        front = front -> siguiente;
        delete temporal;
    }

    void peek(){
        cout << "El elemento en el frente de la cola es: " << front -> valor << endl;
    }

    void peekRear(){
        cout << "El elemento en el final de la cola es: " << rear -> valor << endl;    
    }

    int size(){
        Nodo* actual = front;
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

int main(){
    Cola cola;
    Nodo* primero = new Nodo{10, nullptr};
    Nodo* segundo = new Nodo{15, nullptr};
    Nodo* tercero = new Nodo{20, nullptr};
    Nodo* cuarto = new Nodo{25, nullptr};
    cout << cola.isEmpty() << endl;
    cola.enqueue(primero);
    cola.peek();
    cola.enqueue(segundo);
    cola.enqueue(tercero);
    cola.peekRear();
    cola.dequeue();
    cola.peek();
    cout << cola.isEmpty() << endl;
    cola.enqueue(cuarto);
    return 0;
}