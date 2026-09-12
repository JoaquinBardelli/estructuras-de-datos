#include <iostream>
#include <cassert>
using namespace std;


int factorialRecursivo(int n) {
    if (n <= 1) {           // cubre n=0 y n=1, ambos casos dan 1
        return 1;
    }
    return n * factorialRecursivo(n - 1);
}

int factorialIterativo(int n){
    int valor = 1;
    for(int i=2; i<=n; i++){
        valor *= i;
    }
    return valor;
}

int fibonacciRecursivo(int n){
    if (n<2){
        return n; //Este es el caso base, quiere decir que cuando n sea menor que 2, osea que llegue al 1 o al 0 (que son los dos primeros valores de la sucesion), que devuelva ese mismo numero
    }
    return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2); //Este es el paso recursivo, devuelve la suma de los dos anteriores, y se va llamando a si misma de esta manera hasta que llegue al caso base
}

int fibonacciIterativo(int n){
    int primero = 0;
    int segundo = 1;
    int suma = n;
    while(n > 1){
        suma = primero + segundo;
        primero = segundo;
        segundo = suma;
        n--;
    }
    return suma;
}

int sumaDigitos(int n){
    if (n < 10) return n;
    int numero = n % 10;
    return numero + sumaDigitos((n-numero)/10);
}

//Tests de las funciones
void testFunciones() {
    // tests de factorial
    assert(factorialRecursivo(0) == 1);
    assert(factorialRecursivo(1) == 1);
    assert(factorialRecursivo(5) == 120);
    assert(factorialRecursivo(6) == 720);

    assert(factorialIterativo(0) == 1);
    assert(factorialIterativo(1) == 1);
    assert(factorialIterativo(5) == 120);
    assert(factorialIterativo(6) == 720);

    // tests de fibonacci
    assert(fibonacciRecursivo(0) == 0);
    assert(fibonacciRecursivo(1) == 1);
    assert(fibonacciRecursivo(6) == 8);
    assert(fibonacciRecursivo(10) == 55);

    assert(fibonacciIterativo(0) == 0);
    assert(fibonacciIterativo(1) == 1);
    assert(fibonacciIterativo(6) == 8);
    assert(fibonacciIterativo(10) == 55);

    // tests de suma de dígitos
    assert(sumaDigitos(5) == 5);
    assert(sumaDigitos(9) == 9);
    assert(sumaDigitos(123) == 6);
    assert(sumaDigitos(999) == 27);
    assert(sumaDigitos(1000) == 1);

    cout << "Todos los tests pasaron correctamente." << endl;
}

int main() {
    testFunciones();
    return 0;
}