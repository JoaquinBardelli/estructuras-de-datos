# Estructuras de Datos — Proyecto 1

Implementación desde cero de las estructuras de datos fundamentales, con tests propios (`assert`) y un benchmark de tiempos reales comparando su rendimiento. Es el primer proyecto de un plan de estudio autogestionado de 30 semanas para reforzar fundamentos de programación.

Cada estructura está programada a mano — sin usar las versiones de la librería estándar de C++ para la implementación interna — justamente para entender qué pasa "por debajo" de herramientas como `std::vector`, `std::unordered_map` o `std::queue`.

## Contenido

| Archivo | Qué implementa |
|---|---|
| `recursion.cpp` | Factorial y Fibonacci, versión recursiva e iterativa de cada uno, más suma de dígitos recursiva. Compara complejidad O(2^n) vs O(n) entre el Fibonacci recursivo y el iterativo. |
| `listasEnlazadas.cpp` | Lista simplemente enlazada: inserción al inicio, búsqueda, eliminación por valor. Incluye además la solución a [LeetCode #876 — Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/). |
| `pilasArray.cpp` | Pila (stack) implementada con array fijo, con la interfaz `push` / `top` / `pop` separada para evitar ambigüedad entre "pila vacía" y "valor 0 real". |
| `pilasListasEnlazadas.cpp` | Pila implementada con lista enlazada, con `push`/`pop` equivalentes a insertar/eliminar por el head. Incluye la resolución de paréntesis balanceados usando la pila. |
| `colasArray.cpp` | Cola (queue) implementada con array fijo, usando los índices `front` y `rear`. |
| `colasListasEnlazadas.cpp` | Cola implementada con lista enlazada, manteniendo punteros a `front` y `rear`. |
| `arbolBinario.cpp` | Árbol binario con inserción por niveles (usando una cola interna para encontrar el próximo lugar libre) y los tres recorridos clásicos: preorder, inorder y postorder. |
| `binarySearchTree.cpp` | Binary Search Tree: inserción y búsqueda respetando la propiedad de orden (izquierda &lt; nodo &lt; derecha), con búsqueda en O(log n) promedio. |
| `twoSum.cpp`, `containsDuplicate.cpp`, `validAnagram.cpp` | Tres problemas clásicos de LeetCode resueltos con `unordered_map`, bajando su complejidad de O(n²) (fuerza bruta) a O(n). |
| `medirComplejidad.cpp` | Benchmark que mide tiempos reales de búsqueda en `vector`, BST propio y `unordered_map`, comparando contra el comportamiento teórico de Big-O. |

Todos los archivos incluyen una función `main()` con pruebas usando `assert`, que cortan la ejecución si algún resultado no es el esperado.

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

- Análisis de complejidad temporal (Big-O) de código propio, no solo de ejercicios de ejemplo
- Manejo manual de memoria en C++ (`new`/`delete`), y los bugs típicos que trae: memory leaks, dangling pointers, use-after-free
- Testing con `assert`, cubriendo casos límite (listas vacías, un solo elemento, valores repetidos, valores ausentes)
- La diferencia entre una estructura "funciona" y una estructura "funciona, está bien testeada y además es eficiente"
