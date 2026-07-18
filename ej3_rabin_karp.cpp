#include <bits/stdc++.h>
using namespace std;

const long long BASE = 131;
const long long MOD = 1000000007;

vector<int> rabinKarpBuscar(const string &texto, const string &patron) {
    vector<int> ocurrencias;
    int n = texto.size(), m = patron.size();
    if (m == 0 || m > n) return ocurrencias;

    long long hashPatron = 0, hashVentana = 0, potencia = 1;
    for (int i = 0; i < m - 1; i++) potencia = (potencia * BASE) % MOD;

    for (int i = 0; i < m; i++) {
        hashPatron = (hashPatron * BASE + patron[i]) % MOD;
        hashVentana = (hashVentana * BASE + texto[i]) % MOD;
    }

    for (int i = 0; i + m <= n; i++) {
        if (hashPatron == hashVentana) {
            if (texto.compare(i, m, patron) == 0) ocurrencias.push_back(i);
        }
        if (i + m < n) {
            hashVentana = (hashVentana - (long long)texto[i] * potencia % MOD + MOD) % MOD;
            hashVentana = (hashVentana * BASE + texto[i + m]) % MOD;
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

        vector<int> ocurrencias = rabinKarpBuscar(texto, patron);
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
