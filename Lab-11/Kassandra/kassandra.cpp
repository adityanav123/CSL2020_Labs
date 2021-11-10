    #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <queue>
    using namespace std;
     
    // bfs;
    queue <int> visited;
    vector<int> energyArr (200001);
    void visit (int node, int currEnergy) {
      if (energyArr[node] > 0) return; // already visited.
      energyArr[node] = currEnergy;
      visited.push(node);
    }
     
    int main() {
      int n; cin >> n;
      vector <int> a (n + 1);
      for (int i = 1; i <= n; i++) cin >> a[i];
      /*
        node 1 is the starting node.
      */ 
      // vector<int> minEnergyArr (n + 1); // stores the answer
      visit (1, 1);
     
      while (visited.empty() == false) {
        int currNode = visited.front();
        visited.pop();
        visit (a[currNode], energyArr[currNode] + 1);
        if (currNode > 1) visit (currNode - 1, energyArr[currNode] + 1);
        if (currNode < n) visit (currNode + 1, energyArr[currNode] + 1);
      }
     
      for (int i = 1; i <= n ; i++) {
        cout << energyArr[i] - 1 << " ";
      }
     
      return 0;
    }
