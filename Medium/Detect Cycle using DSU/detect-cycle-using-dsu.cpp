//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isCyclicdfs(vector<int> adj[], unordered_map<int, bool>& visited, int ch, int parent) {
        visited[ch] = true;
        for (int neb : adj[ch]) {
            if (!visited[neb]) {
                int ans1 = isCyclicdfs(adj, visited, neb, ch);
                if (ans1)
                    return true;
            } else if (neb != parent) {
                return true;
            }
        }
        return false;
    }

    
    int detectCycle(int V, vector<int> adj[]) {
        int ans1 = 0;
        unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++) {
            if (visited[i] == false) {
                bool ans = isCyclicdfs(adj, visited, i, -1);
                if(ans==true){
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends