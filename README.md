# Estructuras de Datos — Proyecto 1

Implementación desde cero de las estructuras de datos fundamentales en C++, con tests propios (`assert`) y un benchmark de tiempos reales que compara su rendimiento. Es el primer proyecto de un plan de estudio autogestionado de 30 semanas para reforzar fundamentos de programación.

Cada estructura está programada a mano —sin usar las versiones de la librería estándar para la implementación interna— justamente para entender qué pasa "por debajo" de herramientas como `std::vector`, `std::stack`, `std::queue` o `std::unordered_map`.

## Estructura del repositorio

```
estructuras-de-datos/
├── complejidad.cpp          # Ejemplos comentados de O(1), O(log n), O(n), O(n²) y O(2ⁿ)
├── recursion.cpp            # Factorial, Fibonacci y suma de dígitos
├── listasEnlazadas.cpp      # Lista simplemente enlazada + LeetCode #876
├── medirComplejidad.cpp     # Benchmark: vector vs BST vs unordered_map
├── pilas/
│   ├── pilasArray.cpp
│   └── pilasListasEnlazadas.cpp
├── colas/
│   ├── colasArray.cpp
│   ├── colasListasEnlazadas.cpp
│   ├── arbolBinario.cpp
│   └── binarySearchTree.cpp
└── hash/
    ├── twoSum.cpp
    ├── containsDuplicate.cpp
    └── validAnagram.cpp
```

## Contenido

### Fundamentos

| Archivo | Qué implementa |
|---|---|
| `complejidad.cpp` | Una función de ejemplo por cada orden de complejidad (constante, búsqueda binaria, recorrido lineal, doble bucle anidado y Fibonacci recursivo), con un comentario que justifica su Big-O. |
| `recursion.cpp` | Factorial y Fibonacci en versión recursiva e iterativa, más suma de dígitos recursiva. Permite comparar el Fibonacci recursivo O(2ⁿ) contra el iterativo O(n). |

### Estructuras lineales

| Archivo | Qué implementa |
|---|---|
| `listasEnlazadas.cpp` | Lista simplemente enlazada: inserción al inicio, búsqueda, eliminación por valor y liberación de memoria. Incluye la solución a [LeetCode #876 — Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/). |
| `pilas/pilasArray.cpp` | Pila (stack) sobre un array fijo. La interfaz separa `top()` de `pop()` para no confundir "pila vacía" con un valor 0 real. |
| `pilas/pilasListasEnlazadas.cpp` | Pila sobre lista enlazada (`push`/`pop` operan sobre el head en O(1)). Incluye la validación de paréntesis balanceados `()[]{}` usando la pila. |
| `colas/colasArray.cpp` | Cola (queue) sobre un array fijo con índices `front` y `rear`. |
| `colas/colasListasEnlazadas.cpp` | Cola sobre lista enlazada, con punteros a `front` y `rear` para encolar y desencolar en O(1). |

### Árboles

| Archivo | Qué implementa |
|---|---|
| `colas/arbolBinario.cpp` | Árbol binario con inserción por niveles (usa una cola propia para encontrar el próximo lugar libre) y los tres recorridos clásicos: preorder, inorder y postorder. |
| `colas/binarySearchTree.cpp` | Binary Search Tree: inserción y búsqueda respetando la propiedad de orden (izquierda < nodo < derecha). Búsqueda en O(log n) promedio. |

> Los árboles viven en `colas/` porque `arbolBinario.cpp` reutiliza una cola enlazada para la inserción por niveles.

### Tablas hash

| Archivo | Qué implementa |
|---|---|
| `hash/twoSum.cpp` | [LeetCode #1 — Two Sum](https://leetcode.com/problems/two-sum/) con `unordered_map`. |
| `hash/containsDuplicate.cpp` | [LeetCode #217 — Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) con `unordered_set`. |
| `hash/validAnagram.cpp` | [LeetCode #242 — Valid Anagram](https://leetcode.com/problems/valid-anagram/) contando apariciones con `unordered_map`. |

Los tres bajan la solución de fuerza bruta O(n²) a O(n). Están escritos en formato LeetCode (`class Solution`), así que no tienen `main()` propio.

## Cómo compilar y ejecutar

Se necesita un compilador con soporte para C++17 (por ejemplo `g++` de MinGW/MSYS2 en Windows, o `g++`/`clang++` en Linux/macOS). Cada archivo con `main()` es un programa independiente:

```bash
g++ -std=c++17 -Wall listasEnlazadas.cpp -o programa
./programa
```

Los archivos de `hash/` solo se pueden chequear sintácticamente, porque no tienen `main()`:

```bash
g++ -std=c++17 -Wall -fsyntax-only hash/twoSum.cpp
```

Para el benchmark conviene compilar con optimizaciones:

```bash
g++ -std=c++17 -O2 medirComplejidad.cpp -o benchmark
```

## Tests

Los archivos que tienen tests usan `assert`: si algún resultado no es el esperado, el programa corta la ejecución y muestra la línea que falló. Si todo pasa, imprime un mensaje de confirmación.

| Archivo | Qué se testea |
|---|---|
| `recursion.cpp` | Casos base (0 y 1) y valores conocidos de cada función. |
| `listasEnlazadas.cpp` | Listas de largo par, impar y de un solo nodo para #876. Además: eliminar el head, el del medio y el último nodo, eliminar un valor inexistente y operar sobre una lista vacía. |
| `pilas/pilasArray.cpp` | Orden LIFO entre `top()` y `pop()`, y pila vacía al final. |
| `pilas/pilasListasEnlazadas.cpp` | Paréntesis balanceados, cruzados (`([)]`), sin cerrar y cadena vacía. |
| `colas/arbolBinario.cpp` | Resultado exacto de preorder, inorder y postorder sobre un árbol de 7 nodos. |
| `colas/binarySearchTree.cpp` | Búsqueda de la raíz, de un nodo interno y de valores ausentes. |

`complejidad.cpp`, `colas/colasArray.cpp` y `colas/colasListasEnlazadas.cpp` muestran su funcionamiento por consola, sin `assert`.

## Benchmark: tiempos reales de búsqueda

Se midió el tiempo promedio de búsqueda en tres estructuras cargadas con la misma cantidad de elementos, buscando 100.000 claves distintas elegidas al azar (no la misma clave repetida, para evitar que el compilador u optimizaciones de cache distorsionen la medición).

| Elementos | Vector (O(n)) | BST propio (O(log n)) | `unordered_map` (O(1) promedio) |
|---|---|---|---|
| 100.000 | 121.45 µs | 0.42 µs | 0.20 µs |
| 1.000.000 | 3144.18 µs | 1.10 µs | 0.72 µs |

**Lectura de los resultados:**

- El vector escala linealmente con la cantidad de datos, como predice O(n): al crecer 10 veces la cantidad de elementos, el tiempo de búsqueda crece en proporción similar.
- El BST y el `unordered_map` se mantienen órdenes de magnitud más rápidos que el vector en ambos tamaños, y la diferencia entre ellos dos apenas crece al aumentar los datos — consistente con O(log n): log₂(100.000) ≈ 17, log₂(1.000.000) ≈ 20, una diferencia mínima de pasos para 10 veces más datos.
- `unordered_map` fue la estructura más rápida en ambos casos, como corresponde a su complejidad O(1) promedio.

(Los tiempos exactos varían según la máquina, el compilador y sus optimizaciones — lo relevante no es el valor absoluto sino la proporción entre las tres estructuras y cómo escala cada una.)

## Lo que buscaba reforzar este proyecto

- **Big-O:** analizar la complejidad temporal de código propio, no solo de ejercicios de ejemplo.
- **Memoria manual:** manejar `new`/`delete` en C++ y sus bugs típicos (memory leaks, dangling pointers, use-after-free).
- **Testing con `assert`:** cubrir casos límite como listas vacías, un solo elemento, valores repetidos y valores ausentes.
- **Calidad:** la diferencia entre una estructura que "funciona" y una que funciona, está bien testeada y además es eficiente.

## Posibles mejoras

- **Cola circular:** convertir `colasArray.cpp` en una cola circular, para reutilizar los lugares que libera `dequeue`.
- **Liberar los árboles:** agregar una función que libere la memoria de los árboles con un recorrido postorder.
- **Más tests:** sumar `assert` a las colas y un `main()` con tests a los ejercicios de `hash/`.
- **Carpeta propia:** mover los árboles a `arboles/`.
