#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

void BFS(unordered_map<string, vector<string>> G, string s) {
    unordered_map<string, string> colour;
    unordered_map<string, int> d;
    unordered_map<string, string> p;

    for (auto kv : G) {
        string u = kv.first;
        if (u != s) {
            colour[u] = "W";
            d[u] = INT_MAX;
            p[u] = "NIL";
        }
    }

    colour[s] = "G";
    d[s] = 0;
    p[s] = "NIL";

    queue<string> Q;
    Q.push(s);

    while (!Q.empty()) {
        string u = Q.front();
        Q.pop();
        for (string v : G[u]) {
            if (colour[v] == "W") {
                colour[v] = "G";
                d[v] = d[u] + 1;
                p[v] = u;
                Q.push(v);
            }
        }
        colour[u] = "B";
    }

    cout << "BFS Spanning Tree:\n";
    for (auto kv : G) {
        string parent = kv.first;
        if (parent != s) {
            string child = p[parent];
            cout << child << "->" << parent << endl;
        }
    }
}

int main() {
    unordered_map<string, vector<string>> G = {
        {"1", {"2", "3"}},
        {"2", {"4", "5", "1"}},
        {"3", {"6", "7", "1"}},
        {"4", {"8", "2"}},
        {"5", {"2", "8"}},
        {"6", {"8", "3"}},
        {"7", {"8", "3"}},
        {"8", {"4", "5", "6", "7"}}
    };

    string start_vertex = "1";
    BFS(G, start_vertex);

    return 0;
}
