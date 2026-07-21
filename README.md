# Procesamiento de Cadenas — Código

Implementaciones en C++ de los algoritmos de procesamiento de cadenas pedidos en las prácticas: distancia entre cadenas (Práctica 1) y búsqueda de patrones / Suffix Trie (Práctica 2). Cada archivo es independiente y compilable por separado; todos leen un conjunto fijo de casos de prueba definidos.


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

---

# Practica 2: Procesamiento de cadenas

## ej1_kmp.cpp — Knuth-Morris-Pratt (KMP)

Busca todas las ocurrencias de un patrón dentro de un texto evitando retrocesos innecesarios, mediante una función de prefijos que indica cuánto se puede reutilizar del patrón ya comparado tras un desajuste.

- Funciones: `vector<int> calcularPrefijoFuncion(const string &patron)`, `vector<int> kmpBuscar(const string &texto, const string &patron)`
- La función de prefijos `pi[i]` almacena la longitud del prefijo propio más largo del patrón que también es sufijo de `patron[0..i]`. Al recorrer el texto, si hay un desajuste se retrocede usando `pi` en vez de reiniciar la comparación desde cero.
- Complejidad: `O(n + m)`, donde `n` es la longitud del texto y `m` la del patrón.

## ej2_z_algorithm.cpp — Z Algorithm

Calcula el arreglo Z de la cadena `patron + "$" + texto` y localiza las posiciones donde el valor Z iguala la longitud del patrón, lo que indica una ocurrencia completa.

- Funciones: `vector<int> calcularZ(const string &s)`, `vector<int> zBuscar(const string &texto, const string &patron)`
- `z[i]` es la longitud del prefijo común más largo entre la cadena completa y su sufijo que empieza en la posición `i`. Se mantiene una ventana `[izq, der]` con el prefijo coincidente más a la derecha ya conocido para evitar comparaciones redundantes.
- Complejidad: `O(n + m)`.

## ej3_rabin_karp.cpp — Rabin-Karp

Compara un hash polinomial del patrón contra el hash de cada ventana del texto de igual longitud, y solo verifica carácter por carácter cuando los hashes coinciden (para descartar colisiones).

- Función: `vector<int> rabinKarpBuscar(const string &texto, const string &patron)`
- El hash de cada ventana se recalcula en `O(1)` a partir de la anterior (hash rodante), restando el aporte del carácter que sale y sumando el que entra.
- Complejidad: `O(n + m)` en el caso esperado; `O(n*m)` en el peor caso teórico si hay muchas colisiones de hash.

## ej4_suffix_trie.cpp — Suffix Trie

Implementa la clase `SuffixTrie` con los métodos `insert(string text)` y `search(string pattern)` pedidos en el enunciado, además de un programa que construye el Suffix Trie de una cadena y consulta si distintos patrones pertenecen a ella.

- `insert(text)` inserta en el trie todos los sufijos de `text`, uno por uno, compartiendo los nodos de los prefijos comunes entre sufijos.
- `search(pattern)` recorre el trie siguiendo los caracteres de `pattern`; si el recorrido completo es posible, el patrón es una subcadena del texto original (todo patrón que aparece en el texto es, por definición, prefijo de al menos uno de sus sufijos).
- Complejidad: `O(n^2)` en tiempo y espacio para construir el trie de una cadena de longitud `n` (se insertan `n` sufijos de longitud total `O(n^2)`); cada consulta `search` toma `O(m)`, con `m` la longitud del patrón consultado.