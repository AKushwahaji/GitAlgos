
#include <bits/stdc++.h>
using namespace std;

// counting of the set bits in optimal time
// Brian Kernighan's algorithm  --- isme rightmost bit ko off kr diya jata hai 
//  off right most bit --   n&(n-1)  ==  new (n) 
int counting_Set_bits(int n)
{
    int count=0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;
}
//  check power of two or not 
bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1));
}
// chechk if it is divisible by a number which is power of two
bool isDivisibleByPowerOf2(int n, int k) {
    int powerOf2 = 1 << k;
    return (n & (powerOf2 - 1)) == 0;
}
int main()
{
    int n, m;
    cin >> n >> m;

    cout << counting_Set_bits(n);
    cout<<isPowerOfTwo(n)<<endl;
    return 0;
}