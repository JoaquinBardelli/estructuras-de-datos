#include <iostream>
#include <cassert>
using namespace std;

//Ejercicio de leetcode #876 resuelto
struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cantNodos = cantidadNodos(head);
        for (int i = 0; i < cantNodos/2; i++){
            head = head -> next;
        }
        return head;
    }

    int cantidadNodos(ListNode* head){
        int cantidad = 0;
        while(head -> next != nullptr){
            cantidad ++;
            head = head -> next;
        }
        return cantidad + 1;
    }
};


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





void testFunciones() {
    // ---------- Tests de Solution::middleNode y cantidadNodos ----------
    Solution sol;

    // Lista impar: 1 -> 2 -> 3  (esperado: nodo con valor 2)
    ListNode n3{3, nullptr};
    ListNode n2{2, &n3};
    ListNode n1{1, &n2};
    assert(sol.cantidadNodos(&n1) == 3);
    assert(sol.middleNode(&n1)->val == 2);

    // Lista par: 1 -> 2 -> 3 -> 4  (esperado: nodo con valor 3, "segundo" del medio)
    ListNode m4{4, nullptr};
    ListNode m3{3, &m4};
    ListNode m2{2, &m3};
    ListNode m1{1, &m2};
    assert(sol.cantidadNodos(&m1) == 4);
    assert(sol.middleNode(&m1)->val == 3);

    // Lista de un solo nodo
    ListNode u1{99, nullptr};
    assert(sol.cantidadNodos(&u1) == 1);
    assert(sol.middleNode(&u1)->val == 99);

    // ---------- Tests de la lista enlazada con Nodo ----------
    Nodo* lista = nullptr;

    // insertarInicio: insertamos 30, 20, 10 -> queda 10 -> 20 -> 30
    lista = insertarInicio(30, lista);
    lista = insertarInicio(20, lista);
    lista = insertarInicio(10, lista);

    assert(lista->valor == 10);
    assert(lista->siguiente->valor == 20);
    assert(lista->siguiente->siguiente->valor == 30);
    assert(lista->siguiente->siguiente->siguiente == nullptr);

    // buscar: valores presentes y ausentes
    assert(buscar(10, lista) == true);
    assert(buscar(20, lista) == true);
    assert(buscar(30, lista) == true);
    assert(buscar(99, lista) == false);

    // eliminarPorValor: eliminar el del medio (20)
    eliminarPorValor(20, lista);
    assert(lista->valor == 10);
    assert(lista->siguiente->valor == 30);
    assert(lista->siguiente->siguiente == nullptr);

    // eliminarPorValor: eliminar el head (10)
    eliminarPorValor(10, lista);
    assert(lista->valor == 30);
    assert(lista->siguiente == nullptr);

    // eliminarPorValor: valor que no existe, no debe romper nada
    eliminarPorValor(999, lista);
    assert(lista->valor == 30);

    // eliminarPorValor: eliminar el último nodo restante (queda vacía)
    eliminarPorValor(30, lista);
    assert(lista == nullptr);

    // eliminarPorValor sobre lista vacía no debe explotar
    eliminarPorValor(5, lista);
    assert(lista == nullptr);

    // liberarLista sobre lista con elementos
    lista = insertarInicio(2, lista);
    lista = insertarInicio(1, lista);
    liberarLista(lista);
    assert(lista == nullptr);

    cout << "Todos los tests pasaron correctamente." << endl;
}
int main(){
    testFunciones();

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