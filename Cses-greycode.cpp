#include<bits/stdc++.h>
using namespace std;

void solve(int i,vector<int> num,int &sum ,int &mn){
    if(i<0){
        return;
    }
     
    mn=min(mn,k);

}
int main(){

  int n;
  cin>>n;
  vector<int>v;
  int sum=0;
  for(int i=0;i<n;++i){
    int x;
    cin>>x;
    sum=sum+x;
    v.push_back(x);
  }
  int mn=INT_MAX;
  cout<<solve(n-1,v,sum,mn);
   return 0;
}