#include <bits/stdc++.h>
using namespace std;

string lcsSubcadena(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int longitudMaxima = 0, finA = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > longitudMaxima) {
                    longitudMaxima = dp[i][j];
                    finA = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return a.substr(finA - longitudMaxima, longitudMaxima);
}

int main() {
    vector<vector<string>> casos = {
        {"ABCBDAB", "BDCABA"},
        {"programacion", "gramaticalmente"},
    };

    for (auto &caso : casos) {
        string a = caso[0], b = caso[1];
        string subcadena = lcsSubcadena(a, b);
        cout << "Cadena A: " << a << "\n";
        cout << "Cadena B: " << b << "\n";
        cout << "LCS (subcadena): " << subcadena << "\n";
        cout << "Longitud: " << subcadena.size() << "\n";
        cout << "---------------------------------------\n";
    }

    return 0;
}
