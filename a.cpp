#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
const int MOD = 998244353;
int add(int x, int y)
{
  return ((x + y) % MOD + MOD) % MOD;
}
int mul(int x, int y)
{
  return x * y % MOD;
}
int binpow(int x, int y)
{
  int z = 1;
  while (y)
  {
    if (y % 2 == 1)
    z = mul(z, x);
    x = mul(x, x);
    y /= 2;
  }
  return z;
}
int inv(int x)
{
  return binpow(x, MOD - 2);
}
int divide(int x, int y)
{
  return mul(x, inv(y));
}
 
int countSetBits(int n)
{
  int count=0;
  while(n)
  {
    if(n&1LL)
    count++;
    n = n>>1;
  }
  return count;
}
 
void solve()
{
 cout<<"Hello\n";
}
 
signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;cin>>t;
  while(t--)
  solve();
}