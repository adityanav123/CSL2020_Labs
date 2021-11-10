#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define vpp vector<pair<int, pair<int, int>>>
#define mkp make_pair
#define pii pair<int, int>

unordered_map<int, int> parent;
unordered_map<int, int> sizeSet;

void showParents () {
    for (auto x : parent) {
        cout << x.first << " : " << x.second << "\n";
    }
}

void showSizes() {
    for (auto x : sizeSet) {
        cout << "element's set : " << x.first << " : " << x.second << "\n"; 
    }
}

void initSet(int vertices) {
    for (int i = 0; i <= vertices; i++) {
        parent[i] = i;
        sizeSet[i] = 0;
    }
}

void insert (vpp &graph, int weight, int src, int dst) {
    graph.push_back(mkp(weight, mkp(src, dst)));
}


int findParent (int node) {
    if (node == parent[node]) return node;
    else 
    return parent[node] = findParent(parent[node]);
}

void unionNodes(int node1, int node2) {
    int p1 = findParent(node1), p2 = findParent(node2);
    if (sizeSet[p1] < sizeSet[p2]) {
        parent[p1] = p2;
    }
    if (sizeSet[p1] > sizeSet[p2]) {
        parent[p2] = p1;
    }
    if (sizeSet[p1] == sizeSet[p2]) {
        ++sizeSet[p2];
        parent[p1] = p2;
    }

}

void kruskalMST (vpp &graph) {
    int minCost = 0; // MST min cost.
    for (auto edge : graph) {
        int currentCost = edge.first;
        int src = edge.second.first;
        int dst = edge.second.second;
        
        if (findParent(src)  != findParent(dst)) {
            minCost += currentCost;
            unionNodes(src, dst);
        }
    }
    /*showParents();
    showSizes();*/
    cout << minCost << "\n";
    //cout << "min cost for the spanning tree : " << minCost << "\n";
}


int main() {
    int v, e;
    cin >> v >> e;
    vpp graph;
    for(int i = 0; i < e; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        insert(graph, weight, from, to);
    }

    initSet(v);
    sort (graph.begin(), graph.end());
    kruskalMST(graph); 
    return 0;
}

