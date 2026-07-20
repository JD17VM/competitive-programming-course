#include <bits/stdc++.h>
using namespace std;

class SuffixTrie {
private:
    struct Nodo {
        unordered_map<char, Nodo *> hijos;
    };

    Nodo *raiz;

    void insertarSufijo(const string &sufijo) {
        Nodo *actual = raiz;
        for (char c : sufijo) {
            if (actual->hijos.find(c) == actual->hijos.end()) {
                actual->hijos[c] = new Nodo();
            }
            actual = actual->hijos[c];
        }
    }

public:
    SuffixTrie() { raiz = new Nodo(); }

    void insert(string text) {
        for (int i = 0; i < (int)text.size(); i++) {
            insertarSufijo(text.substr(i));
        }
    }

    bool search(string pattern) {
        Nodo *actual = raiz;
        for (char c : pattern) {
            if (actual->hijos.find(c) == actual->hijos.end()) return false;
            actual = actual->hijos[c];
        }
        return true;
    }
};

int main() {
    string texto = "bananas";
    SuffixTrie trie;
    trie.insert(texto);

    cout << "Texto: " << texto << "\n";
    cout << "Suffix Trie construido con todos los sufijos de \"" << texto << "\"\n";

    vector<string> patrones = {"ana", "nas", "ban", "xyz", "s", ""};
    for (auto &patron : patrones) {
        cout << "Patron: \"" << patron << "\" -> ";
        cout << (trie.search(patron) ? "SI pertenece al texto" : "NO pertenece al texto") << "\n";
    }

    return 0;
}
