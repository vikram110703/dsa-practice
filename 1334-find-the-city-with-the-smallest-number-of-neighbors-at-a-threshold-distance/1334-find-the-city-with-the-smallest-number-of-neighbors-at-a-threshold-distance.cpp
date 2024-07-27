#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const long long INF = 1e17;

class Solution {
public:
    void floydWarshall(vector<vector<long long>>& dist) {
        int n = dist.size();
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    int calculateMinCity(vector<vector<long long>>& dist, int maxD) {
        int n = dist.size();
        int ans = -1;
        int minCityCount = n;
        
        for (int i = 0; i < n; i++) {
            int currCities = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= maxD) {
                    currCities++;
                }
            }
            if (currCities <= minCityCount) {
                ans = i;
                minCityCount = currCities;
            }
        }
        
        return ans;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int maxD) {
        vector<vector<long long>> dist(n, vector<long long>(n, INF));
        
        // Initialize distance array
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Set distance from each node to itself to 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Run Floyd-Warshall algorithm
        floydWarshall(dist);
        
        // Calculate and return the answer
        return calculateMinCity(dist, maxD);
    }
};
