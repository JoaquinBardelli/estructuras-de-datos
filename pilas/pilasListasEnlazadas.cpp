#include <iostream>
#include <cassert>
using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
};

void push(int valor, Nodo*& head){
    Nodo* nuevoElemento = new Nodo{valor, head};
    head = nuevoElemento;
}

bool estaVacia(Nodo* head){
    if(head == nullptr){
        return true;
    }
    return false;
}

void pop(Nodo*& head){
    if(estaVacia(head)){
        return;
    }
    Nodo* sacar = head;
    head = head -> siguiente;
    delete sacar;
}

int tamanoPila(Nodo* head){
    int tamano = 1;
    if(estaVacia(head)){
        return 0;
    }
    while(head -> siguiente != nullptr){
        tamano++;
        head = head -> siguiente;
    }
    return tamano;
}

bool parentesisBalanceados(string cadena){
    Nodo* head = nullptr;
    bool valido = true;
    for(int i = 0; i<cadena.size(); i++){
        char c = cadena[i];
        if(c == '(' || c == '[' || c == '{'){
            head = new Nodo{c, head};
        }else if (c == ')' || c == ']' || c == '}'){
            if(head == nullptr){
                valido = false;
            }
            char abre = head -> valor;
            bool coincide = (c == ')' && abre == '(') || (c == ']' && abre == '[') || (c == '}' && abre == '{');
            if(!coincide){
                valido = false;
            }else{
                pop(head);
            }
        }
    }
    if(head != nullptr){
        valido = false;
    }
    while(head != nullptr){
        pop(head);
    }
    return valido;
}



void testearFunciones(){
    assert(parentesisBalanceados("()") == true);
    assert(parentesisBalanceados("([)]") == false);
    assert(parentesisBalanceados("{[]}") == true);
    assert(parentesisBalanceados("(") == false);
    assert(parentesisBalanceados("") == true); //Es true porque no hay ningun desbalance ya que no hay nada que balancear

    cout << "Todos los tests pasaron correctamente." << endl;
}




int main(){
    testearFunciones();
    Nodo* head = nullptr; // la pila arranca vacia, sin nodos

    cout << "Vacia? " << estaVacia(head) << "\n"; // 1

    push(10, head);
    push(20, head);
    push(30, head);

    cout << "Tamano: " << tamanoPila(head) << "\n"; // 3

    pop(head);
    cout << "Tamano: " << tamanoPila(head) << "\n"; // 2
    cout << "Vacia? " << estaVacia(head) << "\n"; // 0
    cout << "({[]})" << parentesisBalanceados("({[]})") << "\n"; // 1
    cout << "({[}])" << parentesisBalanceados("({[}])") << "\n"; // 0
    return 0;

}