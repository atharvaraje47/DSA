#include <iostream>
using namespace std;

int main() {
    int graph[5][5] = {
        {0, 10, 20, 0, 0},
        {10, 0, 5, 15, 0},
        {20, 5, 0, 8, 12},
        {0, 15, 8, 0, 6},
        {0, 0, 12, 6, 0}
    };

    int parent[5], key[5];
    bool mst[5] = {false};

    for (int i = 0; i < 5; i++)
        key[i] = 999;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < 4; count++) {
        int min = 999, u = -1;

        for (int v = 0; v < 5; v++) {
            if (!mst[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        mst[u] = true;

        for (int v = 0; v < 5; v++) {
            if (graph[u][v] != 0 && !mst[v]
                && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;

    cout << "Minimum Spanning Tree:\n";

    for (int i = 1; i < 5; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        total += graph[i][parent[i]];
    }

    cout << "Total Minimum Distance = " << total;

    return 0;
}
