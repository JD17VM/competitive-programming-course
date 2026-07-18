#include <bits/stdc++.h>
using namespace std;

vector<int> calcularPrefijoFuncion(const string &patron) {
    int m = patron.size();
    vector<int> pi(m, 0);
    int largo = 0;
    for (int i = 1; i < m; i++) {
        while (largo > 0 && patron[i] != patron[largo]) largo = pi[largo - 1];
        if (patron[i] == patron[largo]) largo++;
        pi[i] = largo;
    }
    return pi;
}

vector<int> kmpBuscar(const string &texto, const string &patron) {
    vector<int> ocurrencias;
    int n = texto.size(), m = patron.size();
    if (m == 0 || m > n) return ocurrencias;

    vector<int> pi = calcularPrefijoFuncion(patron);
    int coincidencia = 0;
    for (int i = 0; i < n; i++) {
        while (coincidencia > 0 && texto[i] != patron[coincidencia]) coincidencia = pi[coincidencia - 1];
        if (texto[i] == patron[coincidencia]) coincidencia++;
        if (coincidencia == m) {
            ocurrencias.push_back(i - m + 1);
            coincidencia = pi[coincidencia - 1];
        }
    }
    return ocurrencias;
}

int main() {
    vector<pair<string, string>> casos = {
        {"ababcababcabc", "abc"},
        {"aaaaaaa", "aaa"},
        {"abxabcabcaby", "abcaby"},
        {"programacioncompetitiva", "xyz"}
    };

    for (auto &caso : casos) {
        string texto = caso.first, patron = caso.second;
        cout << "Texto: " << texto << "\n";
        cout << "Patron: " << patron << "\n";

        vector<int> ocurrencias = kmpBuscar(texto, patron);
        if (ocurrencias.empty()) {
            cout << "No se encontraron ocurrencias\n";
        } else {
            cout << "Ocurrencias en posiciones: ";
            for (int i = 0; i < (int)ocurrencias.size(); i++) {
                cout << ocurrencias[i] << (i + 1 < (int)ocurrencias.size() ? ", " : "\n");
            }
        }
    }

    return 0;
}
