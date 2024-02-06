class Solution {
public:
    vector<int> result;

    void dfs(int u, int prev, unordered_map<int, vector<int>>& adj) {
        // Add the current node to the result array
        result.push_back(u);
        // Traverse each neighbor of the current node
        for (int& v : adj[u]) {
            // Avoid revisiting the node we came from (prev) to prevent cycles
            if (v != prev)
                dfs(v, u, adj);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // Create an adjacency list to represent the graph
        unordered_map<int, vector<int>> adj;

        for (auto& vec : adjacentPairs) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // STEP 2 : Find Starting Point (Node with only one neighbour)
        // because the original array starts and ends at nodes with only one neighbor.
        int startPoint = -1;
        for (auto& itr : adj) {
            if (itr.second.size() == 1) {
                startPoint = itr.first;
                break;
            }
        }

         // STEP 3: Perform DFS to reconstruct the original array
        dfs(startPoint, INT_MIN, adj);

        return result;
    }
};
