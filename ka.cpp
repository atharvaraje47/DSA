#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[5];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    int graph[5][5] = {
        {0, 10, 20, 0, 0},
        {10, 0, 5, 15, 0},
        {20, 5, 0, 8, 12},
        {0, 15, 8, 0, 6},
        {0, 0, 12, 6, 0}
    };

    Edge e[10];
    int k = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (graph[i][j] != 0) {
                e[k++] = {i, j, graph[i][j]};
            }
        }
    }

    sort(e, e + k, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    for (int i = 0; i < 5; i++)
        parent[i] = i;

    int total = 0;

    cout << "Minimum Spanning Tree:\n";

    for (int i = 0; i < k; i++) {
        int u = e[i].u;
        int v = e[i].v;

        if (find(u) != find(v)) {
            unite(u, v);
            cout << u << " - " << v
                 << " : " << e[i].w << endl;
            total += e[i].w;
        }
    }

    cout << "Total Minimum Distance = " << total;

    return 0;
}
