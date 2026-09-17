#include <iostream>
#include <array>
using namespace std;

constexpr int capacidad = 15;

struct Cola{
    array<int,capacidad> elementos {};
    int front = 0;
    int rear = 0;

    void enqueue (int valor){
        if(rear < capacidad){
            elementos[rear] = valor;
            rear ++;
        }else{
            cout << "No se pueda agregar mas valores, la pila esta llena" << endl;
        }
    }

    void dequeue (){
        if(front == rear){
            cout << "No hay elementos en la cola para sacar" << endl;
        }else{
            front ++;
        }
    }

    void peek(){
        cout << "El elemento en el frente de la cola es: " << elementos[front] << endl;
    }
};

int main(){
    Cola cola;
    cola.enqueue(5);
    cola.peek();
    cola.enqueue(6);
    cola.enqueue(7);
    cola.enqueue(8);
    cola.dequeue();
    cola.peek();
    return 0;
}