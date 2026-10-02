#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
using namespace std::chrono;

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


void medirVector(const vector<int>& v, const vector<int>& clavesABuscar) {
    auto inicio = high_resolution_clock::now();
    volatile bool encontrado = false;
    for (int clave : clavesABuscar) {
        encontrado = false;
        for (int n : v) {
            if (n == clave) { encontrado = true; break; }
        }
    }
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<microseconds>(fin - inicio);
    cout << "El VECTOR tardo (promedio): " << (duracion.count() / (double) clavesABuscar.size())
         << " microsegundos por busqueda" << endl;
}

void medirMapa(const unordered_map<int,int>& mapa, const vector<int>& clavesABuscar){
    auto inicio = high_resolution_clock::now();
    volatile bool encontrado = false;
    for (int clave : clavesABuscar){
        encontrado = (mapa.find(clave) != mapa.end());
    }
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<microseconds>(fin - inicio);
    cout << "El MAPA tardo (promedio): " << (duracion.count() / (double)clavesABuscar.size())
         << " microsegundos por busqueda" << endl;
}

void medirArbol(NodoArbol* raiz, const vector<int>& clavesABuscar){
    auto inicio = high_resolution_clock::now();
    volatile bool encontrado = false;
    for (int clave : clavesABuscar){
        encontrado = buscarBST(raiz, clave);
    }
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<microseconds>(fin - inicio);
    cout << "El ARBOL tardo (promedio): " << (duracion.count() / (double) clavesABuscar.size())
         << " microsegundos por busqueda" << endl;
}

int main(){
    int cantidad = 1000000;
    vector<int> v;
    v.reserve(cantidad);
    unordered_map<int,int> mapa;
    NodoArbol* arbol = nullptr;

    for (int i = 0; i<cantidad; i++){
        v.push_back(i);
        mapa[i] = i;
    }

    vector<int> valores(cantidad);
    for (int i = 0; i < cantidad; i++) valores[i] = i;

    random_device rd;
    mt19937 generador(rd());
    shuffle(valores.begin(), valores.end(), generador);

    for (int num : valores) {
        insertarBST(arbol, num);
    }

    vector<int> clavesParaVector(valores.begin(), valores.begin() + 1000);
    vector<int> clavesParaRapidas(valores.begin(), valores.begin() + 100000);

    cout << "Cantidad de elementos: " << cantidad << endl;
    medirVector(v, clavesParaVector);
    medirMapa(mapa, clavesParaRapidas);
    medirArbol(arbol, clavesParaRapidas);
}