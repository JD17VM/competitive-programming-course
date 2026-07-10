#include <bits/stdc++.h>
using namespace std;

int distanciaHamming(const string &a, const string &b) {
    int distancia = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != b[i]) distancia++;
    }
    return distancia;
}

int main() {
    vector<vector<string>> casos = {
        {"karolin", "kathrin"},
        {"1011101", "1001001"},
        {"ATCGATCG", "ATGGATGG"},
        {"ROMANE", "ROMANO"}
    };

    for (auto &caso : casos) {
        string a = caso[0], b = caso[1];
        cout << "Cadena A: " << a << "\n";
        cout << "Cadena B: " << b << "\n";
        if (a.size() != b.size()) {
            cout << "No se puede calcular: las cadenas tienen longitudes distintas ("
                 << a.size() << " vs " << b.size() << ")\n";
        } else {
            cout << "Distancia de Hamming: " << distanciaHamming(a, b) << "\n";
        }
        cout << "---------------------------------------\n";
    }

    return 0;
}
