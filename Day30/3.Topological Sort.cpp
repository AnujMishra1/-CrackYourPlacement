#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    
    vector<int> indegree(V, 0);

    // Calculate in-degrees of all nodes
    for (int i = 0; i < V; ++i) {
        for (auto neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;

    // Initialize the queue with all nodes having in-degree 0
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    // Process nodes
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // Decrease the in-degree of all neighbors
        for (auto neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check if topological sort is possible (i.e., no cycle exists)
    if (ans.size() != V) {
        // If the sorted order does not contain all nodes, it means there's a cycle.
        return {};
    }

    return ans;
}
};