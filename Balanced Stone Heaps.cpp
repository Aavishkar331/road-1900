#include <bits/stdc++.h>
using namespace std;

// ===============    SETUP   ======================== //
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define print(x) cout << x;
#define input(x) cin >> x;
#define all(x) x.begin(),(x).end()
#define rall(x) x.rbegin(),x.rend()
#define nextl cout << "\n";
#define space cout<<" ";
#define YES print("YES")nextl
#define NO print("NO")nextl
#define No print("No")nextl
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define vpii vector<pii>
#define pb push_back
#define mp make_pair
#define cint(x) int x; input(x)
#define cstr(s) string s;input(s)
#define f(i,x,n) for(int i = x;i<n;i++)
#define rf(i,x,n) for(int i = x;i>n;i--)
#define cvi(v) f(i,0,n){input(v[i])}
#define printv(a) f(i,0,n){print(a[i])space}
// ==================  ADVICES   ================== //

// for binary search in decimals use 100ish iterations using for loop instead of using while(low<=high)

// ==================  CONSTANTS   ================== //
const int MOD1 = 1e9 + 7;
const int INF = 1e18;
const int MOD2 = 998244353;
const int MAXN = 1000000;
// ==================  HELPER  ===================== //
vi fact(MAXN+1),invfact(MAXN+1),ans(MAXN+1);
int binpow(int a,int b,int mod)
{
    int ans = 1;
    a%=mod;
    while (b>0)
    {
        if(b&1)
        {
            ans=(ans*a)%mod;
        }
        a = (a*a)%mod;
        b/=2;
    }
    return ans;
}
void precompute_factorial(int mod)
{
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
    invfact[MAXN] = binpow(fact[MAXN],mod-2,mod);
    for (int i = MAXN-1; i >= 0; i--)
    {
        invfact[i] = (invfact[i+1]*(i+1))%mod;
    }
}
int nCr(int n,int r,int mod)
{
    if(r<0||r>n)return 0;
    int ans = (((fact[n]*invfact[n-r])%mod)*invfact[r])%mod;
    return ans;
}
bool isPrime(int n)
{
    if(n==0||n==1)
    {
        return false;
    }
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}
int sumofdig(int x)
{
    int ans = 0;
    while(x>0)
    {
        ans += x%10;
        x/=10;
    }
    return ans;
}
int mod_add(int a,int b,int mod)
{
    return ((a%mod)+(b%mod))%mod;
}
int mod_mul(int a,int b,int mod)
{
    return ((a%mod)*(b%mod))%mod;
}
int mod_sub(int a,int b,int mod)
{
    return (((a%mod)-(b%mod))%mod + mod)%mod;
}
int mod_div(int a,int b,int mod)
{
    a%=mod;
    b%=mod;
    int alpha = binpow(b,mod-2,mod);
    return (a*alpha)%mod;
}
int lcm(int a, int b) 
{
    if (a == 0 || b == 0) return 0;
    return (a/gcd(a, b)) * b; 
}
// ==================  CODE  ===================== //
bool check(vi &a,int mid)
{
    vi copy(a.size());
    f(i,0,a.size()){copy[i] = a[i];}
    for(int i = a.size()-1;i>=2;i--)
    {
        if(copy[i]<mid){return false;}
        else
        {
            int val = (min(a[i],copy[i]-mid))/3;
            copy[i-1] += val;copy[i-2]+=2*val;copy[i]-=val*3;
        }
    }
    f(i,0,a.size())
    {
        if(copy[i]<mid){return false;}
    }
    return true;
}
void solve()
{
    cint(n)
    vi a(n);
    f(i,0,n){input(a[i])}
    int minval = *min_element(all(a));
    int maxval = *max_element(all(a));
    // cerr<<minval<<" "<<maxval<<endl;
    int mid = 0;
    while(minval<=maxval)
    {
        mid = (minval+maxval)/2;
        if(check(a,mid))
        {
            minval = mid+1;
        } 
        else
        {
            maxval = mid-1;
        }
        // cerr<<minval<<" "<<maxval<<endl;
    }
    // cerr<<endl;
    print(maxval)
    nextl
    // cout<<setprecision(10)<<fixed;
}
// ==================   MAIN   ===================== //
int32_t main() 
{
    fast;
    // precompute_factorial(MOD1);
    // precompute_factorial(MOD2);
    int t = 1;
    input(t)
    while(t--)
    {
        solve();
    }
    return 0;
}