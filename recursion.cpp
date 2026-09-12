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