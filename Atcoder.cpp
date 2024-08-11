
#include <bits/stdc++.h>
using namespace std;
set<pair<int, vector<int>>> st;
int n, m;
void dfs(int node, vector<int> adj[], vector<int> path, vector<vector<int>>dis ,int walk)
{  
  if (node == n)
  {
    path.push_back(n);
    st.insert({path.size(), path});
    
    return;
  }
  path.push_back(node);
  int k = 0;
  int nodemax=-1;

  for (auto it : adj[node])
  {  
    if(dis[it][n]!=INT_MAX && k<dis[it][n]){
      nodemax = it;
      k=dis[it][n];
    }
  }
   cout<<k<<" "<<node<<endl;
  if(node!=k){
  dfs(nodemax,adj,path,dis,walk);
  }
}
void distance( vector<vector<int>> &dis)
{
int n=dis.size();


}


int main()
{

  cin >> n >> m;
  vector<vector<int>> dis(n + 1, vector<int>(n+1,INT_MAX));
  vector<int> adj[n + 1];
  for (int i = 0; i < m; ++i)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    dis[u][v]=1;
  }
  vector<int> path;
  
  for(int k=0;k<=n;++k){
  for(int i=0;i<=n;++i){
      for(int j=1;j<=n;++j){
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
      }
  }
}cout<<dis[1][2]<<endl;

  // distance( dis);
  int walk=0;
  dfs(1, adj, path, dis ,walk);
  
  cout << st.size() << endl;
  for (auto it : st)
  {
    cout << it.first << endl;
    for (auto it : it.second)
      cout << it << " ";
    cout << endl;
  }

  return 0;
}