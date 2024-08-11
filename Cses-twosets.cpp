#include<bits/stdc++.h>
using namespace std;

string solve(int n){
    int k=(n)*(n+1)/2;
    if(k%2==0)
    return "YES";
    else
    return "NO";
}
int main(){

  int n,k;
  cin>>n>>k;
  vector<int> nums;
  for(int i=0;i<n;++i){
    int x;
    cin>>x;
    nums.push_back(x);
  }
  vector<int>ans(n+1,INT_MAX);
  ans[0]=0;
  for(int i=0;i<n;++i){
    for(int j=1;j<=k;++j){
        if(i+j<n){
            ans[i+j]=min(ans[i+j],ans[i]+abs(nums[i+j]-nums[i]));
        }
    }
  }
  cout<<ans[n-1];
   return 0;
}