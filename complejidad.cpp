#include <iostream>
#include <vector>

using namespace std;

//Complejidad O(1)
//Porque sin importar la tamano de lo que se ingrese, si o si se hara una unica operacion
int numero (int n){
    n = 1;
    return n;
}

//Complejidad O(n)
//Porque la cantidad de operaciones que se haran depende del tamano de lo que se ingrese
int numeros (int n){
    int contador = 0;
    for (int i = 0; i<n; i++){
        contador += 1;
    }
    return contador;
}

//Complejidad O(log n) "Listas de numeros en orden menor a mayor"
//Porque por cada iteracion, se parte el tamano de lo que se ingresa a la mitad, y en el peor de los casos se hara log n cantidad de operaciones
int buscarIndice(vector<int> lista, int n){
    int primerIndice = 0;
    int ultimoIndice = lista.size()-1;
    while(primerIndice <= ultimoIndice){
        int medioIndice = (primerIndice + ultimoIndice) / 2;
        if(lista[medioIndice] == n){
            return medioIndice;
        } else if(lista[medioIndice] > n){
            ultimoIndice = medioIndice - 1;
        } else{
            primerIndice = medioIndice + 1; 
        }
    }
    return -1;
}

//Complejidad O(n^2)
//En realidad seria O(n*m) pero suponiendo que tienen el mismo tamano, entonces la cantidad de operaciones (en el peor de los casos) sera de n^2
bool chequearDuplicados(vector<int>lista1, vector<int>lista2){
    for(int n : lista1){
        for(int j : lista2){
            if(n==j){
                return true;
            }
        }
    }
    return false;
}

//Complejidad O(2^n)
//Es asi porque por cada vez que se corra la funcion se haran 2 operaciones, y asi recursivamente, la funcion se correra n veces
int fibonacci(int n){
    if (n<2){
        return n; //Este es el caso base, quiere decir que cuando n sea menor que 2, osea que llegue al 1 o al 0 (que son los dos primeros valores de la sucesion), que devuelva ese mismo numero
    }
    return fibonacci(n-1) + fibonacci(n-2); //Este es el paso recursivo, devuelve la suma de los dos anteriores, y se va llamando a si misma de esta manera hasta que llegue al caso base
}

int main(){
    // 1. Prueba O(1)
    cout << "--- O(1) ---" << endl;
    cout << "Resultado numero(50): " << numero(50) << endl << endl;

    // 2. Prueba O(n)
    cout << "--- O(n) ---" << endl;
    cout << "Resultado numeros(5): " << numeros(5) << endl << endl;

    // 3. Prueba O(log n)
    cout << "--- O(log n) ---" << endl;
    vector<int> listaOrdenada = {10, 20, 30, 40, 50, 60, 70};
    int valorBuscado = 40;
    int indice = buscarIndice(listaOrdenada, valorBuscado);
    cout << "El valor " << valorBuscado << " esta en el indice: " << indice << endl << endl;

    // 4. Prueba O(n^2)
    cout << "--- O(n^2) ---" << endl;
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 2}; // El 2 se repite
    bool hayDuplicados = chequearDuplicados(v1, v2);
    cout << "Hay duplicados entre v1 y v2?: " << (hayDuplicados ? "Si" : "No") << endl << endl;

    // 5. Prueba O(2^n)
    cout << "--- O(2^n) ---" << endl;
    int nFibo = 6;
    cout << "Fibonacci(" << nFibo << "): " << fibonacci(nFibo) << endl;

    return 0;
}