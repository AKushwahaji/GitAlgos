
#include <bits/stdc++.h>
using namespace std;

// toposort
void go(int start, vector<bool> &vis, vector<int> adj[], stack<int> &s)
{

    vis[start] = true;
    for (auto it : adj[start])
    {
        if (vis[it] == false)
            go(it, vis, adj, s);
    }
    s.push(start);
}
vector<int> topoSort(int v, vector<int> adj[])
{
    vector<bool> vis(v, false);
    stack<int> s;
    for (int i = 0; i < v; ++i)
    {
        if (vis[i] == false)
        {
            go(i, vis, adj, s);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// kahn's algorithm // toposort(using BFS)

vector<int> topoSort(int v, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; ++i)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < v; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return ans;
}

// dijkshtra algorithm
vector<int> dijkstra(int v, vector<vector<int>> adj[], int src)
{
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int u = it[0];
            int v = it[1];
            if (dist[u] > dis + v)
            {
                dist[u] = dis + v;
                pq.push({dist[u], u});
            }
        }
    }
    return dist;
}

// Bellman ford algorithm -- distance to all nodes , negative cycle detection
vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; ++i)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dist[u] != 1e8 && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    vector<int> ans = dist;

    // detection of negative cycle
    for (auto it : edges)
    {
        if (dist[it[0]] != 1e8 && dist[it[1]] > dist[it[0]] + it[2])
        {
            dist[it[1]] = dist[it[0]] + it[2];
        }
    }
    if (ans == dist)
    {
        return dist;
    }
    else
        return {-1};
}

// floyd warshell algorithm -- distance of every node to every nodes, negative cycle detection
void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;
        }
    }
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (matrix[i][i] < 0)
        {
        }
        // return -1;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
}

// prims algorithm -- minimum spanning tree
int spanningTree(int V, vector<vector<int>> adj[])
{
    // vector<pair<int,int>> ADJ[V];
    // for(int i=0;i<V;++i){
    //  for(auto it:adj[i]){
    //       ADJ[it[0]].push_back({it[1],it[2]});
    //       ADJ[it[1]].push_back({it[0],it[2]});
    //  }
    // }
    // vector<pair<int,int>>mst;
    vector<int> vis(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    int sum = 0;
    while (!q.empty())
    {
        int weight = q.top().first;
        int u = q.top().second;
        //  int parent=q.top().second.second;
        q.pop();

        if (vis[u] == 1)
            continue;
        vis[u] = 1;
        sum = sum + weight;
        for (auto it : adj[u])
        {
            if (vis[it[0]] == 0)
            {
                q.push({it[1], it[0]});
            }
        }
    }
    return sum;
}

// DSU dis-joint set union
// #include <bits/stdc++.h>
// using namespace std;
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}

// kruskal algorithm -- for minimum spanning tree
// how it work
//    sort the edges with weight  then make the use of dsu

// Strongly connected component -- Kosaraju's algorithm
class
{
    void transpose(int V, vector<vector<int>> &adj, vector<int> transpose_adj[])
    {
        for (int u = 0; u < V; u++)
            for (auto v : adj[u])
                transpose_adj[v].push_back(u);
    }

    stack<int> s;
    void dfs(vector<int> adj[], bool *visited, int u)
    {
        visited[u] = true;
        for (auto v : adj[u])
        {
            if (visited[v] == 0)
                dfs(adj, visited, v);
        }
    }
    void fillorder(vector<vector<int>> &adj, bool *visited, int u)
    {
        visited[u] = true;
        for (auto v : adj[u])
            if (visited[v] == 0)
                fillorder(adj, visited, v);
        s.push(u);
    }

    int kosaraju(int V, vector<vector<int>> &adj)
    {
        bool visited[V];
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                fillorder(adj, visited, i);
        vector<int> transpose_adj[V];
        transpose(V, adj, transpose_adj);

        for (int i = 0; i < V; i++)
            visited[i] = false;

        int ans = 0;
        while (!s.empty())
        {
            int temp = s.top();
            s.pop();
            if (!visited[temp])
            {
                dfs(transpose_adj, visited, temp);
                ans++;
            }
        }
        return ans;
    }
};

// Segment tree making
class SegemntTree
{

    class Node
    {
    public:
        int data;
        int leftindex;
        int rightindex;
        Node *left;
        Node *right;
        Node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->leftindex = -1;
            this->rightindex = -1;
        }
        Node(int leftindex, int rightindex)
        {
            this->leftindex = leftindex;
            this->rightindex = rightindex;
            this->left = NULL;
            this->right = NULL;
        }
    };

    // createing a tree using
    Node *root;
    Node *ConstructTree(vector<int> &num, int left, int right) // left right are indexs
    {
        if (left == right)
        {
            Node *leaf = new Node(left, right);
            leaf->data = num[left];
            return leaf;
        }
        Node *node = new Node(left, right);
        int mid = (left + right) / 2;
        node->left = ConstructTree(num, left, mid);
        node->right = ConstructTree(num, mid + 1, right);
        node->data = node->left->data + node->right->data;
        return node;
    }
    void printtree(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        printtree(root->left);
        printtree(root->right);
    }
    void solve(vector<int> num)
    {
        int n = num.size();
        root = ConstructTree(num, 0, n - 1);
    }
};


// Prefix tree ( Trie )

class Node
{
public:
    Node *links[26];
    bool terminal = false;
    bool containskey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    bool setend()
    {
        terminal = true;
    }
    bool isend()
    {
        return terminal;
    }
};

// Targens algorithm -- To know that any edge is a bridge or not
class Solution
{
public:
    int time = 0;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis,
             vector<int> &tin, vector<int> &low, vector<vector<int>> &ans)
    {
        vis[node] = 1;
        tin[node] = low[node] = time;
        time++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, adj, vis, tin, low, ans);
                low[node] = min(low[node], low[it]);
                // node -- it (is a bridge)
                if (tin[node] < low[it])
                {
                    ans.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>> &connections)
    {
        vector<int> adj[n + 1];
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n + 1, 0);
        vector<int> insertTime(n + 1, 0);
        vector<int> lowtime(n + 1, 0);

        vector<vector<int>> ans;

        dfs(0, -1, adj, vis, insertTime, lowtime, ans);
        return ans;
    }
};

// Articulation point in graph -- same as Bridge finding ( point due to which graph will break in two or more networks)

class Solution
{
public:
    int time = 0;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &ans)
    {
        vis[node] = 1;
        tin[node] = low[node] = time;
        time++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, adj, vis, tin, low, ans);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                {
                    ans[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
        {
            ans[node] = 1;
        }
    }
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        vector<int> ans(n + 1, 0);
        vector<int> tin(n + 1, 0);
        vector<int> low(n + 1, 0);
        vector<int> vis(n + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {

                dfs(i, -1, adj, vis, tin, low, ans);
            }
        }
        vector<int> artpoint;
        for (int i = 0; i < n; ++i)
        {
            if (ans[i] == 1)
            {
                artpoint.push_back(i);
            }
        }

        if (artpoint.size() == 0)
            return {-1};
        return artpoint;
    }
};
