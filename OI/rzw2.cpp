#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// Using a slightly larger MAXN for safety
const int MAXN = 500007;
const int LOGN = 20;

vector<int> adj[MAXN];
int dep[MAXN], pre[MAXN], post[MAXN], p_arr[MAXN];
int lca_table[MAXN][LOGN];
int bit[MAXN];
int timer = 0;
int n, q;

// Iterative DFS to avoid stack overflow for N=5*10^5
void dfs_iterative(int root) {
    struct State {
        int u, p, child_idx;
    };
    stack<State> s;
    s.push({root, 0, 0});
    
    while (!s.empty()) {
        State &curr = s.top();
        int u = curr.u;
        int p = curr.p;
        
        if (curr.child_idx == 0) {
            pre[u] = ++timer;
            dep[u] = dep[p] + 1;
            p_arr[u] = p;
            lca_table[u][0] = p;
            for (int i = 1; i < LOGN; i++) {
                lca_table[u][i] = lca_table[lca_table[u][i - 1]][i - 1];
            }
        }
        
        if (curr.child_idx < (int)adj[u].size()) {
            int v = adj[u][curr.child_idx];
            curr.child_idx++;
            if (v != p) {
                s.push({v, u, 0});
            }
        } else {
            post[u] = timer;
            s.pop();
        }
    }
}

int lift(int u, int d) {
    for (int i = 0; i < LOGN; i++) {
        if ((d >> i) & 1) {
            u = lca_table[u][i];
        }
    }
    return u;
}

int get_lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    u = lift(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (lca_table[u][i] != lca_table[v][i]) {
            u = lca_table[u][i];
            v = lca_table[v][i];
        }
    }
    return lca_table[u][0];
}

void bit_add(int idx, int val) {
    if (idx <= 0) return;
    for (; idx <= n; idx += idx & -idx) {
        bit[idx] += val;
    }
}

int bit_query(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) {
        res += bit[idx];
    }
    return res;
}

struct Path {
    int u, v, w;
};

bool comparePaths(const Path& a, const Path& b) {
    return dep[a.w] > dep[b.w];
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> q)) return 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_iterative(1);

    vector<Path> paths(q);
    for (int i = 0; i < q; i++) {
        cin >> paths[i].u >> paths[i].v;
        paths[i].w = get_lca(paths[i].u, paths[i].v);
    }

    // Greedy strategy: deepest LCA first
    sort(paths.begin(), paths.end(), comparePaths);

    vector<int> result;
    for (int i = 0; i < q; i++) {
        int u = paths[i].u;
        int v = paths[i].v;
        int w = paths[i].w;
        int pw = p_arr[w];
        
        // Check if path is already covered by a quarantined node
        if (bit_query(pre[u]) - bit_query(pre[pw]) == 0 && 
            bit_query(pre[v]) - bit_query(pre[pw]) == 0) {
            result.push_back(w);
            bit_add(pre[w], 1);
            bit_add(post[w] + 1, -1);
        }
    }

    cout << result.size() << "
";
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << (i == (int)result.size() - 1 ? "" : " ");
    }
    cout << "
";

    return 0;
}
