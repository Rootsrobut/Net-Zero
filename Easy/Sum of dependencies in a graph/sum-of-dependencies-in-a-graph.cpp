//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int bfs(vector<int> adj[], unordered_map<int, bool>& visited, int v, int i) {
        queue<int> p;
        p.push(i);
        int count = 0;
        visited[i] = true;
        while (!p.empty()) {
            int ci = p.front();
            p.pop();
            for (auto neb : adj[ci]) {
                count++;
                if (!visited[neb]) {
                    p.push(neb);
                    visited[neb] = true;
                }
            }
        }
        return count;
    }

    int sumOfDependencies(vector<int> adj[], int V) {
        int ans = 0;
        unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                ans += bfs(adj, visited, V, i);
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<int> v[N];
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            v[x].push_back(y);
        }
        Solution ob;
        cout << ob.sumOfDependencies(v, N) << "\n";
    }
}
// } Driver Code Ends