#include <bits/stdc++.h>
using namespace std;

int distanciaLevenshtein(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int eliminacion = dp[i - 1][j];
                int insercion = dp[i][j - 1];
                int sustitucion = dp[i - 1][j - 1];
                dp[i][j] = 1 + min({eliminacion, insercion, sustitucion});
            }
        }
    }

    return dp[n][m];
}

int main() {
    vector<vector<string>> casos = {
        {"kitten", "sitting"},
        {"gato", "pato"},
        {"casa", "calle"},
        {"algoritmo", "logaritmo"}
    };

    for (auto &caso : casos) {
        string a = caso[0], b = caso[1];
        cout << "Cadena A: " << a << "\n";
        cout << "Cadena B: " << b << "\n";
        cout << "Distancia de Levenshtein: " << distanciaLevenshtein(a, b) << "\n";
        cout << "---------------------------------------\n";
    }

    return 0;
}
