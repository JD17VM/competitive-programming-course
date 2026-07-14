# Procesamiento de Cadenas — Código

Implementaciones en C++ de los algoritmos de distancia entre cadenas pedidos en la práctica. Cada archivo es independiente y compilable por separado; todos leen un conjunto fijo de casos de prueba definidos en `main()` e imprimen el resultado por consola.

Compilación (ejemplo con g++):

```
g++ -O2 -std=c++17 -o ej1_hamming.exe ej1_hamming.cpp
```

## ej1_hamming.cpp — Distancia de Hamming

Cuenta el número de posiciones en las que difieren dos cadenas de **igual longitud**. Recorre ambas cadenas en paralelo con un único bucle y compara carácter por carácter.

- Función: `int distanciaHamming(const string &a, const string &b)`
- Complejidad: `O(n)`, siendo `n` la longitud de las cadenas.
- Antes de calcular la distancia, `main()` verifica que ambas cadenas tengan la misma longitud; si no, se informa que la distancia no está definida para ese par.

## ej2_levenshtein.cpp — Distancia de Levenshtein

Calcula la cantidad mínima de operaciones de edición (inserción, eliminación, sustitución) para transformar una cadena en otra, mediante programación dinámica.

- Función: `int distanciaLevenshtein(const string &a, const string &b)`
- Tabla `dp[i][j]`: distancia entre los primeros `i` caracteres de `a` y los primeros `j` caracteres de `b`. Si `a[i-1] == b[j-1]` no hay costo adicional; si no, se toma `1 + min(eliminación, inserción, sustitución)`.
- Complejidad: `O(n*m)` en tiempo y espacio.

## ej3_lcs_subsecuencia.cpp — Longest Common Subsequence

Obtiene la subsecuencia común más larga entre dos cadenas: el orden relativo de los caracteres se conserva, pero no necesitan ser contiguos.

- Función: `string lcsSubsecuencia(const string &a, const string &b)`
- Construye la tabla `dp[i][j]` con la longitud del LCS de los prefijos, y luego reconstruye la subsecuencia recorriendo la tabla desde `dp[n][m]` hacia atrás.
- Complejidad: `O(n*m)` para la tabla, más `O(n+m)` para la reconstrucción.

## ej4_lcs_subcadena.cpp — Longest Common Substring

Obtiene la subcadena común más larga: a diferencia del ejercicio anterior, exige que los caracteres coincidentes sean **contiguos** en ambas cadenas.

- Función: `string lcsSubcadena(const string &a, const string &b)`
- Tabla `dp[i][j]`: longitud de la subcadena común que termina exactamente en `a[i-1]` y `b[j-1]`. Se reinicia a `0` en cada carácter distinto (no se propaga el máximo de los vecinos, como sí ocurre en LCS de subsecuencia). La respuesta es el mayor valor de toda la tabla.
- Complejidad: `O(n*m)`.
