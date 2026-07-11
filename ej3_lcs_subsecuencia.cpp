#include <bits/stdc++.h>
using namespace std;

string lcsSubsecuencia(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string subsecuencia;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            subsecuencia += a[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(subsecuencia.begin(), subsecuencia.end());

    return subsecuencia;
}

int main() {
    vector<vector<string>> casos = {
        {"ABCBDAB", "BDCABA"},
        {"programacion", "dinamica"},
        {"AGGTAB", "GXTXAYB"}
    };

    for (auto &caso : casos) {
        string a = caso[0], b = caso[1];
        string subsecuencia = lcsSubsecuencia(a, b);
        cout << "Cadena A: " << a << "\n";
        cout << "Cadena B: " << b << "\n";
        cout << "LCS (subsecuencia): " << subsecuencia << "\n";
        cout << "Longitud: " << subsecuencia.size() << "\n";
        cout << "---------------------------------------\n";
    }

    return 0;
}
