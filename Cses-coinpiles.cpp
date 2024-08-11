#include<bits/stdc++.h>
using namespace std;

string solve(int a,int b){
    if(a==0&&b==0)
    return "YES";
    if(a==0||b==0)
    return "NO";
    if((a+b)%3==0 && abs(a-b)<=min(a,b))
    return "YES";
    else
    return "NO";
}
int main(){

   int t;
   cin>>t;
   while(t--){
    int a,b;
    cin>>a>>b;
    
    cout<<solve(a,b)<<endl;
    
   }
   return 0;
}