// C++ Implementation
#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
	// Topological sort using bfs is called
	// Kahn's Algorithm
	void topo_sort(vector<int> adj[], int n)
	{
		// Here concept of indegree used
		// as it represents number of incoming
		// edges on a node
		vector<int> indegree(n, 0);
		// Code for make indegree
		for (int i = 0; i < n; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		vector<int> ans;
		queue<int> qrr;
		// Initially insert elements who has
		// indegree 0
		for (int i = 0; i < n; i++) {

			if (indegree[i] == 0) {
				qrr.push(i);
			}
		}

		while (!qrr.empty()) {
			// push those elements in queue which
			// poses 0 indegree
			int node = qrr.front();

			qrr.pop();
			ans.push_back(node);
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) {
					qrr.push(it);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
	}
};

// Function to add edge
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

// Driver code
int main()
{
	int n = 6;
	vector<int> adj[n];
	addEdge(adj, 5, 0);
	addEdge(adj, 5, 2);
	addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 0);
	addEdge(adj, 3, 1);
	addEdge(adj, 1, 0);
	addEdge(adj, 4, 0);
	addEdge(adj, 4, 1);
	Solution s1;

	// Function call
	s1.topo_sort(adj, n);
	return 0;
}
