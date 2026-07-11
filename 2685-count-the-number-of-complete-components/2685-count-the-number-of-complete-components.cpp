class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        if(n == 1) return 1;

        vector<int> cnt_edge(n, 0);
        vector<int> sz(n, 1);
        vector<int> par(n);
        std::iota(par.begin(), par.end(), 0); 
        
        auto find = [&](auto&& self, int node) -> int {
            if(par[node] == node) return node;
            return par[node] = self(self, par[node]);
        };
        
        auto merge = [&](int u, int v) {
            int rootU = find(find, u);
            int rootV = find(find, v);

            if(rootU == rootV) {
                cnt_edge[rootU]++; 
                return; 
            }
            
            if(sz[rootU] > sz[rootV]) {
                swap(rootU, rootV); 
            }
            
            par[rootU] = rootV;
            sz[rootV] += sz[rootU];
            cnt_edge[rootV] += cnt_edge[rootU] + 1;
        };

        for(auto& x: edges) {
            merge(x[0], x[1]); 
        }

        int ans = 0;
        int64_t vis = 0; 
        
        for(int i = 0; i < n; ++i) {
            int p = find(find, i);
            if(vis&(1LL<<p)) continue;
            vis |= (1LL<<p);
            
            if (cnt_edge[p] == (sz[p]*(sz[p] - 1))/2) {
                ans++;
            }
        }
        return ans;
    }
};