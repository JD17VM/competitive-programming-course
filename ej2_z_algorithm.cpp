#include <bits/stdc++.h>
using namespace std;

vector<int> calcularZ(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    int izq = 0, der = 0;
    for (int i = 1; i < n; i++) {
        if (i < der) z[i] = min(der - i, z[i - izq]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > der) { izq = i; der = i + z[i]; }
    }
    return z;
}

vector<int> zBuscar(const string &texto, const string &patron) {
    vector<int> ocurrencias;
    int m = patron.size();
    string combinada = patron + "$" + texto;
    vector<int> z = calcularZ(combinada);

    for (int i = m + 1; i < (int)combinada.size(); i++) {
        if (z[i] == m) ocurrencias.push_back(i - m - 1);
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

        string combinada = patron + "$" + texto;
        vector<int> z = calcularZ(combinada);
        cout << "Arreglo Z (patron$texto): ";
        for (int i = 0; i < (int)z.size(); i++) cout << z[i] << (i + 1 < (int)z.size() ? " " : "\n");

        vector<int> ocurrencias = zBuscar(texto, patron);
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
